#include "app.h"
#include "hal.h"
#include "mc_drive.h"

static void app_adcResCb();

void APP_init()
{
HAL_set_Pot_INT_cb(&app_adcResCb);
HAL_ADC_init();
}

void APP_run()
{

}

static void app_adcResCb()
{
MCDRIVE_setSpeed(HAL_getPotValue());
}