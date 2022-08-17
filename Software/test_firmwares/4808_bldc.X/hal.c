#include "hal.h"

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
    //Hardcoded 0x7 value for faster access; eliminates the need of RMW
    //TCA0.SINGLE.CTRLB = TCA_SINGLE_CMP0EN_bm | 0x7;
    PORTA.OUTCLR = 0x3F;//clear all three outputs for sanity
   // PA0_SetHigh();
    BL_SetHigh();
}

void HAL_drive_AH_CL()
{
    //Hardcoded 0x7 value for faster access; eliminates the need of RMW
    //TCA0.SINGLE.CTRLB = TCA_SINGLE_CMP0EN_bm | 0x7;
    PORTA.OUTCLR = 0x3F;//clear all three outputs for sanity
  //  PA0_SetHigh();
    CL_SetHigh();
}

void HAL_drive_BH_CL()
{
    //Hardcoded 0x7 value for faster access; eliminates the need of RMW
    //TCA0.SINGLE.CTRLB = TCA_SINGLE_CMP1EN_bm | 0x7;
    PORTA.OUTCLR = 0x3F;//clear all three outputs for sanity
  //  PA1_SetHigh();
    CL_SetHigh();
}

void HAL_drive_BH_AL()
{
    //Hardcoded 0x7 value for faster access; eliminates the need of RMW
    //TCA0.SINGLE.CTRLB = TCA_SINGLE_CMP1EN_bm | 0x7;
    PORTA.OUTCLR = 0x3F;//clear all three outputs for sanity
 //   PA1_SetHigh();
    AL_SetHigh();
}

void HAL_drive_CH_AL()
{
    //Hardcoded 0x7 value for faster access; eliminates the need of RMW
    //TCA0.SINGLE.CTRLB = TCA_SINGLE_CMP2EN_bm | 0x7;
    PORTA.OUTCLR = 0x3F;//clear all three outputs for sanity
 //   PA2_SetHigh();
    AL_SetHigh(); 
}

void HAL_drive_CH_BL()
{
    //Hardcoded 0x7 value for faster access; eliminates the need of RMW
    //TCA0.SINGLE.CTRLB = TCA_SINGLE_CMP2EN_bm | 0x7;
    PORTA.OUTCLR = 0x3F;//clear all three outputs for sanity
 //   PA2_SetHigh();
    BL_SetHigh();
}

void HAL_drive_OFF()
{
    //TCA0.SINGLE.CTRLB = 0x7;
    PORTA.OUTCLR = 0x3F;
}

void HAL_brake_NonRegen()
{
    PORTA.OUTCLR = 0x3F;
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