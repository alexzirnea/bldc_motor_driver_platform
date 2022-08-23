/* 
 * File:   hal.h
 * Author: Alexandru Zirnea
 *
 * Created on March 17, 2021, 10:07 PM
 */

#ifndef HAL_H
#define	HAL_H

#include "mcc_generated_files/mcc.h" 

#ifdef	__cplusplus
extern "C" {
#endif

#define PHASE_A ((0x0<<3) | AC_MUXNEG0_bm)
#define PHASE_B ((0x1<<3) | AC_MUXNEG0_bm)
#define PHASE_C ((0x3<<3) | AC_MUXNEG0_bm)

#define HAL_RGB_PORT        (PORTC)
#define HAL_RGB_RED_PIN     (1 << 2)
#define HAL_RGB_BLUE_PIN    (1 << 0)
#define HAL_RGB_GREEN_PIN   (1 << 1)
#define HAL_RGB_MASK        (HAL_RGB_RED_PIN | HAL_RGB_BLUE_PIN | HAL_RGB_GREEN_PIN)   
    
#define HAL_RGB_OFF     0x0
#define HAL_RGB_RED     (HAL_RGB_RED_PIN)  
#define HAL_RGB_BLUE    (HAL_RGB_BLUE_PIN)
#define HAL_RGB_GREEN   (HAL_RGB_GREEN_PIN)
#define HAL_RGB_WHITE   (HAL_RGB_GREEN_PIN | HAL_RGB_RED_PIN | HAL_RGB_BLUE_PIN)
#define HAL_RGB_YELLOW  (HAL_RGB_GREEN_PIN | HAL_RGB_RED_PIN)
#define HAL_RGB_CYAN    (HAL_RGB_GREEN_PIN | HAL_RGB_BLUE_PIN)
#define HAL_RGB_MAGENTA (HAL_RGB_RED_PIN | HAL_RGB_BLUE_PIN)   
    
void HAL_setDuty(uint8_t duty);
void HAL_drive_AH_BL();
void HAL_drive_AH_CL();
void HAL_drive_BH_CL();
void HAL_drive_BH_AL();
void HAL_drive_CH_AL();
void HAL_drive_CH_BL();
void HAL_drive_OFF();
void HAL_brake_NonRegen();
void HAL_AC_selectPhase(uint8_t phase);
void HAL_init();
void HAL_lightRGB(uint8_t color);

#define HAL_set_ZC_INT_cb(X)        (CCL0_SetCaptIsrCallback(X))
//#define HAL_set_ZC_INT_cb(X)        (AC0_SetCmpIsrCallback(X))
#define HAL_set_Pot_INT_cb(X)       (ADC0_RegisterWindowCallback(X))
#define HAL_set_PWM_PER_INT_cb(X)   (TCB0_SetCaptIsrCallback(X))
#define HAL_setBEMF_RisingEdgeINT() do{ CCL.INTFLAGS = 0x1; \
                                        CCL.INTCTRL0 = 0x1;}while(0)
#define HAL_setBEMF_FallingEdgeINT() do{CCL.INTFLAGS = 0x1; \
                                        CCL.INTCTRL0 = 0x2;}while(0)
#define HAL_disableBEMF_INT() do{CCL.INTCTRL0 = 0;}while(0)
#define HAL_getPotValue() (ADC0_GetConversionResult() >> 4)
#define HAL_ADC_init() (ADC0_StartConversion(15))
#ifdef	__cplusplus
}
#endif

#endif	/* HAL_H */

