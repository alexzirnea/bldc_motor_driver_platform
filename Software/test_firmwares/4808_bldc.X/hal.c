#include "hal.h"

#define DELAY_CYCLES 4

void HAL_setDuty(uint8_t duty)
{ 
    TCA0.SINGLE.CTRLFCLR = 0xE;//clear buffer valid
    TCA0.SINGLE.CMP0BUF = duty;
	TCA0.SINGLE.CMP1BUF = duty;
	TCA0.SINGLE.CMP2BUF = duty;
    TCA0.SINGLE.CTRLFSET = 0xE;
}

void HAL_drive_AH_BL()
{
    PORTA.OUTCLR = 0x38;//clear all three outputs for sanity
    TCA0.SINGLE.CTRLB = 0x7;
    for(uint8_t i=0; i<=DELAY_CYCLES;i++);
    //Hardcoded 0x7 value for faster access; eliminates the need of RMW
    TCA0.SINGLE.CTRLB = TCA_SINGLE_CMP0EN_bm | 0x7;
    BL_SetHigh();
}

void HAL_drive_AH_CL()
{
    PORTA.OUTCLR = 0x38;//clear all three outputs for sanity
    TCA0.SINGLE.CTRLB = 0x7;
    for(uint8_t i=0; i<=DELAY_CYCLES;i++);
    //Hardcoded 0x7 value for faster access; eliminates the need of RMW
    TCA0.SINGLE.CTRLB = TCA_SINGLE_CMP0EN_bm | 0x7;
    CL_SetHigh();
}

void HAL_drive_BH_CL()
{
    PORTA.OUTCLR = 0x38;//clear all three outputs for sanity
    TCA0.SINGLE.CTRLB = 0x7;
    for(uint8_t i=0; i<=DELAY_CYCLES;i++);
    //Hardcoded 0x7 value for faster access; eliminates the need of RMW
    TCA0.SINGLE.CTRLB = TCA_SINGLE_CMP1EN_bm | 0x7;
    CL_SetHigh();
}

void HAL_drive_BH_AL()
{
    PORTA.OUTCLR = 0x38;//clear all three outputs for sanity
    TCA0.SINGLE.CTRLB = 0x7;
    for(uint8_t i=0; i<=DELAY_CYCLES;i++);
    //Hardcoded 0x7 value for faster access; eliminates the need of RMW
    TCA0.SINGLE.CTRLB = TCA_SINGLE_CMP1EN_bm | 0x7;
    AL_SetHigh();
}

void HAL_drive_CH_AL()
{
    PORTA.OUTCLR = 0x38;//clear all three outputs for sanity
    TCA0.SINGLE.CTRLB = 0x7;
    for(uint8_t i=0; i<=DELAY_CYCLES;i++);
    //Hardcoded 0x7 value for faster access; eliminates the need of RMW
    TCA0.SINGLE.CTRLB = TCA_SINGLE_CMP2EN_bm | 0x7;
    AL_SetHigh(); 
}

void HAL_drive_CH_BL()
{
    PORTA.OUTCLR = 0x38;//clear all three outputs for sanity
    TCA0.SINGLE.CTRLB = 0x7;
    for(uint8_t i=0; i<=DELAY_CYCLES;i++);
    //Hardcoded 0x7 value for faster access; eliminates the need of RMW
    TCA0.SINGLE.CTRLB = TCA_SINGLE_CMP2EN_bm | 0x7;
    BL_SetHigh();
}

void HAL_drive_OFF()
{
    TCA0.SINGLE.CTRLB = 0x7;
    PORTA.OUTCLR = 0x38;
}

void HAL_brake_NonRegen()
{
    PORTA.OUTCLR = 0x38;
    //Hardcoded 0x7 value for faster access; eliminates the need of RMW
    TCA0.SINGLE.CTRLB = TCA_SINGLE_CMP0EN_bm 
                      | TCA_SINGLE_CMP1EN_bm 
                      | TCA_SINGLE_CMP2EN_bm 
                      | 0x7;
}

void HAL_AC_selectPhase(uint8_t phase)
{
    AC0.MUXCTRLA = phase;
}

void HAL_init()
{
    HAL_drive_OFF();
}

void HAL_lightRGB(uint8_t color)
{
    HAL_RGB_PORT.OUTSET = HAL_RGB_MASK;
    HAL_RGB_PORT.OUTCLR = color;
}

uint8_t HAL_getUSER1Level(void)
{
    return USER1_GetValue();
}

uint8_t HAL_getUSER2Level(void)
{
    return USER2_GetValue();
}