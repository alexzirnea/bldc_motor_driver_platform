#include "app.h"
#include "hal.h"
#include "mc_drive.h"
#include "util/delay.h"

static void app_adcResCb();
static void app_testRGB(void);

void APP_init()
{
HAL_set_Pot_INT_cb(&app_adcResCb);
HAL_ADC_init();
HAL_lightRGB(HAL_RGB_OFF);
}

void APP_run()
{
    uint8_t motor_state;
    static uint8_t motor_state_old=0xFF;
    motor_state = MCDRIVE_getState();
    if(motor_state != motor_state_old)
    {
        motor_state_old = motor_state;
        switch(motor_state)
        {
            case MCSTATE_OPENLOOP:
                HAL_lightRGB(HAL_RGB_YELLOW);
            break;
            
            case MCSTATE_CLOSEDLOOP:
                HAL_lightRGB(HAL_RGB_GREEN);
            break;
            
            case MCSTATE_STOP:
                HAL_lightRGB(HAL_RGB_BLUE);
            break;
            
            case MCSTATE_FAULT:
                HAL_lightRGB(HAL_RGB_RED);
            break;
            
            default:
                HAL_lightRGB(HAL_RGB_OFF);
            break;
        }
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