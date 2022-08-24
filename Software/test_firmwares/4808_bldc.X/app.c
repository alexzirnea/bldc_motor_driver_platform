#include "app.h"
#include "hal.h"
#include "mc_drive.h"
#include "util/delay.h"

#define START_STOP_BUTTON_LEVEL() (HAL_getUSER1Level())
#define CHANGE_DIR_BUTTON_LEVEL() (HAL_getUSER2Level())

static void app_adcResCb();
static void app_testRGB(void);
void app_handle_startStopButton();
void app_handle_directionButton();
void app_updateRGBstatus();

uint8_t prev_START_STOP_level;
uint8_t prev_CHANGE_DIR_level;
uint8_t motor_state, motor_direction;

void APP_init()
{
    HAL_set_Pot_INT_cb(&app_adcResCb);
    HAL_ADC_init();
    HAL_lightRGB(HAL_RGB_OFF);
    prev_START_STOP_level = START_STOP_BUTTON_LEVEL();
    prev_CHANGE_DIR_level = CHANGE_DIR_BUTTON_LEVEL(); 
}

void app_handle_startStopButton()
{
    uint8_t current_START_STOP_level;
    
    current_START_STOP_level = START_STOP_BUTTON_LEVEL();
    
    if(current_START_STOP_level != prev_START_STOP_level)
    {
        prev_START_STOP_level = current_START_STOP_level;
        if(!current_START_STOP_level)
        {
            switch(motor_state)
            {
                case MCSTATE_OPENLOOP:
                    MCDRIVE_stopMotor();
                break;
            
                case MCSTATE_CLOSEDLOOP:
                    MCDRIVE_stopMotor();
                break;
            
                case MCSTATE_STOP:
                    MCDRIVE_startMotor();
                break;
            
                case MCSTATE_FAULT:
                    MCDRIVE_stopMotor();
                break;
            
                default:
                    MCDRIVE_stopMotor();
                break;
            }    
        }    
    }
}

void app_handle_directionButton()
{
    uint8_t current_CHANGE_DIR_level;
    
    current_CHANGE_DIR_level = CHANGE_DIR_BUTTON_LEVEL();
    
    if(current_CHANGE_DIR_level != prev_CHANGE_DIR_level)
    {
        prev_CHANGE_DIR_level = current_CHANGE_DIR_level;
        if(!current_CHANGE_DIR_level)
        {
            switch(motor_state)
            {
                case MCSTATE_OPENLOOP:
                break;
            
                case MCSTATE_CLOSEDLOOP:
                break;
            
                case MCSTATE_STOP:
                    if(MCDRIVE_getDirection() == MCDIR_CW)
                    {
                        MCDRIVE_setDirection(MCDIR_CCW);
                        app_updateRGBstatus();
                    }
                    else
                    {
                        MCDRIVE_setDirection(MCDIR_CW);
                        app_updateRGBstatus();
                    }
                break;
            
                case MCSTATE_FAULT:
                break;
            
                default:
                break;
            }    
        }    
    }
}

void app_updateRGBstatus()
{
    switch(motor_state)
    {
        case MCSTATE_OPENLOOP:
            HAL_lightRGB(HAL_RGB_YELLOW);
        break;
            
        case MCSTATE_CLOSEDLOOP:
            HAL_lightRGB(HAL_RGB_GREEN);
        break;
            
        case MCSTATE_STOP:
            if(MCDRIVE_getDirection() == MCDIR_CW)
            {
                HAL_lightRGB(HAL_RGB_BLUE);
            }
            else
            {
                HAL_lightRGB(HAL_RGB_CYAN);
            }
        break;
            
        case MCSTATE_FAULT:
            HAL_lightRGB(HAL_RGB_RED);
        break;
            
        default:
            HAL_lightRGB(HAL_RGB_OFF);
        break;
    }
}

void APP_run()
{
    static uint8_t motor_state_old=0xFF;
       
    motor_state = MCDRIVE_getState();

    app_handle_startStopButton();
    app_handle_directionButton();
    
    if(motor_state != motor_state_old)
    {
        motor_state_old = motor_state;
        app_updateRGBstatus();
    } 
}

static void app_adcResCb()
{
    MCDRIVE_setSpeed(HAL_getPotValue());
}

static void app_testRGB(void)
{
    HAL_lightRGB(HAL_RGB_OFF);
    _delay_ms(500);
    HAL_lightRGB(HAL_RGB_RED); 
    _delay_ms(500);
    HAL_lightRGB(HAL_RGB_BLUE);
    _delay_ms(500);
    HAL_lightRGB(HAL_RGB_GREEN);
    _delay_ms(500);
    HAL_lightRGB(HAL_RGB_WHITE);
    _delay_ms(500);
    HAL_lightRGB(HAL_RGB_YELLOW);
    _delay_ms(500);
    HAL_lightRGB(HAL_RGB_CYAN);
    _delay_ms(500);
    HAL_lightRGB(HAL_RGB_MAGENTA);
    _delay_ms(500);
}