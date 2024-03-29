#include "hal.h"
#include "mc_drive.h"
#include "utils.h"

#define STEP_NUMBER 6

#define COMMSTATE_BLANKING 0
#define COMMSTATE_WAITZC 1
#define COMMSTATE_WAITCOMM 2
#define COMMSTATE_ALIGN 3

#define BLANKING_PWM_PERIODS 30
#define BEMF_FILTER_COEFF 4
#define ADVANCE_ANGLE 0
#define ALIGN_INCREMENT_TIME 50UL
#define ALIGN_DUTY_TARGET  120   
#define ALIGN_DUTY_INCREMENT 1
#define MIN_DUTY 50
#define MAX_DUTY 255
#define MIN_IN_DUTY 0
#define MAX_IN_DUTY 255
#define OPENLOOP_RAMPUP_DUTY (ALIGN_DUTY_TARGET)
#define OPENLOOP_STEP_DECREMENT 1

#define CLOSEDLOOP_ZC_TIMEOUT_MULTIPLIER 16

#define TARGET_SPEED 200

struct flags
{
    uint8_t comm_pending;
    uint8_t direction;
    uint8_t zc_valid;
    uint8_t mcstate;
    uint8_t commstep;
 
};
uint8_t mc_step = 0;
uint16_t pwm_periods = 0;
volatile uint16_t PWM_comm = 230, cnt = 0;
volatile uint8_t blanking = 0;
volatile uint16_t pwm_counts = 0, zc_pwm_counts = TARGET_SPEED, adv_zc_pwm_counts;
volatile uint8_t align_duty;

struct flags sysflags;

static void mcdrive_PWM_cb();
static void mcdrive_ZC_INT_cb();
static void mcdrive_trigStep();
static void mcdrive_setNextStep();
static void mcdrive_enableBEMF_INT();
static void mcdrive_faultHandler();

void MCDRIVE_init()
{
    sysflags.mcstate = MCSTATE_STOP;
    sysflags.direction =  MCDIR_CW;
}

void mcdrive_initStartup()
{
    HAL_set_ZC_INT_cb(&mcdrive_ZC_INT_cb);
    HAL_set_PWM_PER_INT_cb(&mcdrive_PWM_cb);
    sysflags.comm_pending = 0;
    sysflags.zc_valid = 1;
    sysflags.mcstate = MCSTATE_OPENLOOP;
    sysflags.commstep = COMMSTATE_ALIGN;
    mc_step = 0;
    pwm_periods = 0;
    PWM_comm = 370;
    cnt = 0;
    blanking = 0;
    pwm_counts = 0;
    align_duty = 0;
    zc_pwm_counts = TARGET_SPEED;
    HAL_setDuty(OPENLOOP_RAMPUP_DUTY);
    mcdrive_trigStep();
    mcdrive_enableBEMF_INT();
}

void MCDRIVE_startMotor()
{
    //Initialize the motor drive subsystem
    mcdrive_initStartup();
}

void MCDRIVE_stopMotor()
{
    sysflags.mcstate = MCSTATE_STOP;
    HAL_drive_OFF();
    HAL_disableBEMF_INT();
}

uint8_t MCDRIVE_getState()
{
    return sysflags.mcstate;
}

uint16_t MCDRIVE_getSpeed()
{

}

uint8_t MCDRIVE_getDirection()
{
   return sysflags.direction ;
}

void MCDRIVE_setDirection(uint8_t direction)
{
    if(sysflags.mcstate == MCSTATE_STOP)
    {
        sysflags.direction = direction;
    }
}

void MCDRIVE_setSpeed(uint8_t duty)
{
    uint8_t mapped_duty = map(duty, MIN_IN_DUTY, MAX_IN_DUTY, MIN_DUTY, MAX_DUTY);
    
    if(sysflags.mcstate == MCSTATE_CLOSEDLOOP)
    {
        HAL_setDuty(mapped_duty);
    }
}

static void mcdrive_openLoopHandler()
{    
    cnt++;
    
    if(COMMSTATE_ALIGN == sysflags.commstep)
    {
        mcdrive_trigStep();
        if (cnt > ALIGN_INCREMENT_TIME)
        {
            cnt = 0;
            align_duty += ALIGN_DUTY_INCREMENT;
            HAL_setDuty(align_duty);
            
            if(align_duty >= ALIGN_DUTY_TARGET)
            {
                sysflags.commstep = COMMSTATE_WAITZC;
            }
        }
    }
    
    else if(cnt >= PWM_comm)
    {
        if(blanking)
        {
            sysflags.mcstate = MCSTATE_CLOSEDLOOP;
            sysflags.commstep = COMMSTATE_WAITZC;
            mcdrive_enableBEMF_INT();
        }
        else
        {
            if(PWM_comm <= TARGET_SPEED)
            {
                HAL_drive_OFF();
                for(uint8_t i = 0; i<1; i++)
                {
                    mcdrive_setNextStep();
                }
                blanking = 1;
            }
            else 
            {
                mcdrive_setNextStep();
                mcdrive_trigStep();
                PWM_comm -= OPENLOOP_STEP_DECREMENT;
            }
        }
        cnt = 0;
    }  
}

static void mcdrive_closedLoopHandler()
{    
    pwm_counts ++;
    
    if(pwm_counts > (CLOSEDLOOP_ZC_TIMEOUT_MULTIPLIER * zc_pwm_counts))
    {
        mcdrive_faultHandler();
        return;
    }
    switch(sysflags.commstep)
    {
        case COMMSTATE_BLANKING:
            if(pwm_counts > ((zc_pwm_counts >> 1) - (zc_pwm_counts>>2)))
            {
                mcdrive_enableBEMF_INT();
                sysflags.commstep = COMMSTATE_WAITZC;
            }
            break;
        
        case COMMSTATE_WAITZC:
            if(sysflags.zc_valid)
            {
                sysflags.zc_valid = 0;
                zc_pwm_counts = (pwm_counts + zc_pwm_counts * (BEMF_FILTER_COEFF - 1)) / BEMF_FILTER_COEFF;
                adv_zc_pwm_counts = (30*zc_pwm_counts - ADVANCE_ANGLE * zc_pwm_counts) / 30;
                pwm_counts = 0;
                sysflags.commstep = COMMSTATE_WAITCOMM;
            }
            break;
        
        case COMMSTATE_WAITCOMM:
            if(pwm_counts >= adv_zc_pwm_counts)
            {
                mcdrive_trigStep();
                sysflags.commstep = COMMSTATE_BLANKING;
                pwm_counts = 0;   
            }
            break;
        
        default:
            sysflags.commstep = COMMSTATE_BLANKING;
            break; 
    }
}

static void mcdrive_faultHandler()
{
    sysflags.mcstate = MCSTATE_FAULT;
    HAL_drive_OFF();
    HAL_disableBEMF_INT();
}

static void mcdrive_stopHandler()
{
}

static void mcdrive_trigStep()
{
    switch(mc_step)
    {
        case 0:
            HAL_drive_AH_BL();
            break;
            
        case 1:
            HAL_drive_AH_CL();
            break;
            
        case 2:
            HAL_drive_BH_CL();
            break;
            
        case 3:
            HAL_drive_BH_AL();
            break;
            
        case 4:
            HAL_drive_CH_AL();
            break;
            
        case 5:
            HAL_drive_CH_BL();
            break;
            
        default:
            //something awfully wrong happened here
            mc_step = 0;
            break;
    }
}

static void mcdrive_setNextStep()
{
    if(sysflags.direction)
    {
        if(++mc_step >= STEP_NUMBER)
        {
            mc_step = 0;
        }  
    }
    else 
    {   
        if(mc_step == 0)
        {
            mc_step = STEP_NUMBER - 1;
        }
        else
        {
            mc_step--;
        }
    }

}

static void mcdrive_enableBEMF_INT()
{
    if(sysflags.direction)
    {
        switch(mc_step)
        {
            case 0:
                HAL_AC_selectPhase(PHASE_C);
                HAL_setBEMF_FallingEdgeINT();
            break;           
            
            case 1:
                HAL_AC_selectPhase(PHASE_B);
                HAL_setBEMF_RisingEdgeINT();
            break;            
            
            case 2:
                HAL_AC_selectPhase(PHASE_A);
                HAL_setBEMF_FallingEdgeINT();
            break;           
            
            case 3:
                HAL_AC_selectPhase(PHASE_C);
                HAL_setBEMF_RisingEdgeINT();
            break;           
            
            case 4:
                HAL_AC_selectPhase(PHASE_B);
                HAL_setBEMF_FallingEdgeINT();
            break;          
            
            case 5:
                HAL_AC_selectPhase(PHASE_A);
                HAL_setBEMF_RisingEdgeINT();
            break;           
            
            default:
                //something awfully wrong happened here
                mc_step = 0;
            break;
        }
    }
    else
    {
        switch(mc_step)
        {
            case 0:
                HAL_AC_selectPhase(PHASE_C);
                HAL_setBEMF_RisingEdgeINT();
            break;            
        
                case 1:
                HAL_AC_selectPhase(PHASE_B);
                HAL_setBEMF_FallingEdgeINT();
            break;           
            
            case 2:
                HAL_AC_selectPhase(PHASE_A);
                HAL_setBEMF_RisingEdgeINT();
            break;           
        
            case 3:
                HAL_AC_selectPhase(PHASE_C);
                HAL_setBEMF_FallingEdgeINT();
            break;           
            
            case 4:
                HAL_AC_selectPhase(PHASE_B);
                HAL_setBEMF_RisingEdgeINT();
            break;
            
            case 5:
                HAL_AC_selectPhase(PHASE_A);
                HAL_setBEMF_FallingEdgeINT();
            break;         
        
            default:
                //something awfully wrong happened here
                mc_step = 0;
            break;
        }
    }
}

static void mcdrive_PWM_cb()
{   
    switch(sysflags.mcstate)
    {
        case MCSTATE_OPENLOOP:
            mcdrive_openLoopHandler();
            break;          
        case MCSTATE_CLOSEDLOOP:
            mcdrive_closedLoopHandler();
            break;
        case MCSTATE_FAULT:
            mcdrive_faultHandler();
            break;
        case MCSTATE_STOP:
            mcdrive_stopHandler();
            break;
        default:
            sysflags.mcstate = MCSTATE_STOP;
            break; 
    }
}

static void mcdrive_ZC_INT_cb()
{    
    sysflags.zc_valid = 1;
    mcdrive_setNextStep();
    HAL_disableBEMF_INT();
}