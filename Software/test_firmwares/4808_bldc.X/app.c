#include "app.h"
#include "hal.h"
#include "mc_drive.h"
#include "util/delay.h"

static void app_adcResCb();

void APP_init()
{
HAL_set_Pot_INT_cb(&app_adcResCb);
HAL_ADC_init();
}

void APP_run()
{
    uint8_t motor_state;
    
    motor_state = MCDRIVE_getState();

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

static void app_adcResCb()
{
MCDRIVE_setSpeed(HAL_getPotValue());
}