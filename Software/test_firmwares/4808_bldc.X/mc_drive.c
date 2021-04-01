#include "hal.h"
#include "mc_drive.h"

#define STEP_NUMBER 6

#define MCSTATE_OPENLOOP 3
#define MCSTATE_CLOSEDLOOP 2
#define MCSTATE_STOP 0
#define MCSTATE_FAULT 1

#define COMMSTATE_BLANKING 0
#define COMMSTATE_WAITZC 1
#define COMMSTATE_WAITCOMM 2

#define BLANKING_PWM_PERIODS 30
#define BEMF_FILTER_COEFF 16
#define ADVANCE_ANGLE 5

#define TARGET_SPEED 60

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

struct flags sysflags;

static void mcdrive_PWM_cb();
static void mcdrive_ZC_INT_cb();
static void mcdrive_trigStep();
static void mcdrive_setNextStep();
static void mcdrive_enableBEMF_INT();

void MCDRIVE_init()
{
 HAL_set_ZC_INT_cb(&mcdrive_ZC_INT_cb);
 HAL_set_PWM_PER_INT_cb(&mcdrive_PWM_cb);
 sysflags.comm_pending = 0;
 sysflags.direction = 1;
 sysflags.zc_valid = 1;
 sysflags.mcstate = MCSTATE_OPENLOOP;
 sysflags.commstep = COMMSTATE_WAITZC;
 HAL_setDuty(30);
 mcdrive_trigStep();
 mcdrive_enableBEMF_INT();
}

void MCDRIVE_startMotor()
{
}

void MCDRIVE_stopMotor()
{
}

uint8_t MCDRIVE_getState()
{

}

uint16_t MCDRIVE_getSpeed()
{

}

MCDRIVE_setSpeed(uint8_t duty)
{
    HAL_setDuty(duty);
}


static void mcdrive_openLoopHandler()
{
    static volatile uint16_t PWM_comm = 500, cnt = 0;
    static volatile uint8_t blanking = 0;
    
    cnt++;
    if(cnt >= PWM_comm)
    {
        if(blanking)
        {
            sysflags.mcstate = MCSTATE_CLOSEDLOOP;
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
        else {
        mcdrive_setNextStep();
        mcdrive_trigStep();
        PWM_comm -= 2;
        }
        }
        cnt = 0;
    }
    
}

static void mcdrive_closedLoopHandler()
{
    static volatile uint16_t pwm_counts = 0, zc_pwm_counts = TARGET_SPEED, adv_zc_pwm_counts;
        pwm_counts ++;
    switch(sysflags.commstep)
    {
        case COMMSTATE_BLANKING:
            if(pwm_counts > zc_pwm_counts >> 1 - zc_pwm_counts>>2)
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
            //HAL_drive_AH_BL();
            break;           
        case 1:
            HAL_AC_selectPhase(PHASE_B);
            HAL_setBEMF_RisingEdgeINT();
            //HAL_drive_AH_CL();
            break;            
        case 2:
            HAL_AC_selectPhase(PHASE_A);
            HAL_setBEMF_FallingEdgeINT();
            //HAL_drive_BH_CL();
            break;           
        case 3:
            HAL_AC_selectPhase(PHASE_C);
            HAL_setBEMF_RisingEdgeINT();
            //HAL_drive_BH_AL();
            break;           
        case 4:
            HAL_AC_selectPhase(PHASE_B);
            HAL_setBEMF_FallingEdgeINT();
            //HAL_drive_CH_AL();
            break;          
        case 5:
            HAL_AC_selectPhase(PHASE_A);
            HAL_setBEMF_RisingEdgeINT();
            //HAL_drive_CH_BL();
            break;           
        default:
            //something awfully wrong happened here
            //mc_step = 0;
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
            //HAL_drive_AH_BL();
            break;            
        case 1:
            HAL_AC_selectPhase(PHASE_B);
            HAL_setBEMF_FallingEdgeINT();
            //HAL_drive_AH_CL();
            break;           
        case 2:
            HAL_AC_selectPhase(PHASE_A);
            HAL_setBEMF_RisingEdgeINT();
            ///HAL_drive_BH_CL();
            break;           
        case 3:
            HAL_AC_selectPhase(PHASE_C);
            HAL_setBEMF_FallingEdgeINT();
            //HAL_drive_BH_AL();
            break;           
        case 4:
            HAL_AC_selectPhase(PHASE_B);
            HAL_setBEMF_RisingEdgeINT();
            //HAL_drive_CH_AL();
            break;
        case 5:
            HAL_AC_selectPhase(PHASE_A);
            HAL_setBEMF_FallingEdgeINT();
            //HAL_drive_CH_BL();
            break;         
        default:
            //something awfully wrong happened here
            //mc_step = 0;
            break;
    }
    }
}

static void mcdrive_PWM_cb()
{   
    PA6_Toggle();
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
    //mcdrive_enableBEMF_INT();
    //mcdrive_trigStep();
    HAL_disableBEMF_INT();
}