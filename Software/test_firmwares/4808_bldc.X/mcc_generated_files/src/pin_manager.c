/**
  @Company
    Microchip Technology Inc.

  @Description
    This Source file provides APIs.
    Generation Information :
    Driver Version    :   1.0.0
*/
/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/


#include "../include/pin_manager.h"
static void (*PORTA_PA2_InterruptHandler)(void);
static void (*PORTC_PC3_InterruptHandler)(void);
static void (*PORTA_PA1_InterruptHandler)(void);
static void (*PORTA_BL_InterruptHandler)(void);
static void (*PORTD_PD7_InterruptHandler)(void);
static void (*PORTA_AL_InterruptHandler)(void);
static void (*PORTA_USER1_InterruptHandler)(void);
static void (*PORTA_CL_InterruptHandler)(void);
static void (*PORTA_USER2_InterruptHandler)(void);
static void (*PORTF_BUTTON_InterruptHandler)(void);
static void (*PORTC_LED_RED_InterruptHandler)(void);
static void (*PORTD_PD1_InterruptHandler)(void);
static void (*PORTF_PF3_InterruptHandler)(void);
static void (*PORTC_LED_BLUE_InterruptHandler)(void);
static void (*PORTD_PD3_InterruptHandler)(void);
static void (*PORTA_PA0_InterruptHandler)(void);
static void (*PORTF_PF5_InterruptHandler)(void);
static void (*PORTC_LED_GREEN_InterruptHandler)(void);
static void (*PORTF_PF4_InterruptHandler)(void);

void PORT_Initialize(void);

void PIN_MANAGER_Initialize()
{
    PORT_Initialize();

    /* DIR Registers Initialization */
    PORTA.DIR = 0x3F;
    PORTB.DIR = 0x00;
    PORTC.DIR = 0x0F;
    PORTD.DIR = 0x88;
    PORTE.DIR = 0x00;
    PORTF.DIR = 0x08;

    /* OUT Registers Initialization */
    PORTA.OUT = 0x00;
    PORTB.OUT = 0x00;
    PORTC.OUT = 0x00;
    PORTD.OUT = 0x00;
    PORTE.OUT = 0x00;
    PORTF.OUT = 0x00;

    /* PINxCTRL registers Initialization */
    PORTA.PIN0CTRL = 0x00;
    PORTA.PIN1CTRL = 0x00;
    PORTA.PIN2CTRL = 0x00;
    PORTA.PIN3CTRL = 0x00;
    PORTA.PIN4CTRL = 0x00;
    PORTA.PIN5CTRL = 0x00;
    PORTA.PIN6CTRL = 0x00;
    PORTA.PIN7CTRL = 0x00;
    PORTB.PIN0CTRL = 0x00;
    PORTB.PIN1CTRL = 0x00;
    PORTB.PIN2CTRL = 0x00;
    PORTB.PIN3CTRL = 0x00;
    PORTB.PIN4CTRL = 0x00;
    PORTB.PIN5CTRL = 0x00;
    PORTB.PIN6CTRL = 0x00;
    PORTB.PIN7CTRL = 0x00;
    PORTC.PIN0CTRL = 0x00;
    PORTC.PIN1CTRL = 0x00;
    PORTC.PIN2CTRL = 0x00;
    PORTC.PIN3CTRL = 0x00;
    PORTC.PIN4CTRL = 0x00;
    PORTC.PIN5CTRL = 0x00;
    PORTC.PIN6CTRL = 0x00;
    PORTC.PIN7CTRL = 0x00;
    PORTD.PIN0CTRL = 0x04;
    PORTD.PIN1CTRL = 0x04;
    PORTD.PIN2CTRL = 0x04;
    PORTD.PIN3CTRL = 0x04;
    PORTD.PIN4CTRL = 0x04;
    PORTD.PIN5CTRL = 0x00;
    PORTD.PIN6CTRL = 0x00;
    PORTD.PIN7CTRL = 0x00;
    PORTE.PIN0CTRL = 0x00;
    PORTE.PIN1CTRL = 0x00;
    PORTE.PIN2CTRL = 0x00;
    PORTE.PIN3CTRL = 0x00;
    PORTE.PIN4CTRL = 0x00;
    PORTE.PIN5CTRL = 0x00;
    PORTE.PIN6CTRL = 0x00;
    PORTE.PIN7CTRL = 0x00;
    PORTF.PIN0CTRL = 0x00;
    PORTF.PIN1CTRL = 0x00;
    PORTF.PIN2CTRL = 0x00;
    PORTF.PIN3CTRL = 0x00;
    PORTF.PIN4CTRL = 0x04;
    PORTF.PIN5CTRL = 0x04;
    PORTF.PIN6CTRL = 0x00;
    PORTF.PIN7CTRL = 0x00;

    /* PORTMUX Initialization */
    PORTMUX.CCLROUTEA = 0x01;
    PORTMUX.EVSYSROUTEA = 0x00;
    PORTMUX.TCAROUTEA = 0x00;
    PORTMUX.TCBROUTEA = 0x00;
    PORTMUX.TWISPIROUTEA = 0x00;
    PORTMUX.USARTROUTEA = 0x00;

    // register default ISC callback functions at runtime; use these methods to register a custom function
    PORTA_PA2_SetInterruptHandler(PORTA_PA2_DefaultInterruptHandler);
    PORTC_PC3_SetInterruptHandler(PORTC_PC3_DefaultInterruptHandler);
    PORTA_PA1_SetInterruptHandler(PORTA_PA1_DefaultInterruptHandler);
    PORTA_BL_SetInterruptHandler(PORTA_BL_DefaultInterruptHandler);
    PORTD_PD7_SetInterruptHandler(PORTD_PD7_DefaultInterruptHandler);
    PORTA_AL_SetInterruptHandler(PORTA_AL_DefaultInterruptHandler);
    PORTA_USER1_SetInterruptHandler(PORTA_USER1_DefaultInterruptHandler);
    PORTA_CL_SetInterruptHandler(PORTA_CL_DefaultInterruptHandler);
    PORTA_USER2_SetInterruptHandler(PORTA_USER2_DefaultInterruptHandler);
    PORTF_BUTTON_SetInterruptHandler(PORTF_BUTTON_DefaultInterruptHandler);
    PORTC_LED_RED_SetInterruptHandler(PORTC_LED_RED_DefaultInterruptHandler);
    PORTD_PD1_SetInterruptHandler(PORTD_PD1_DefaultInterruptHandler);
    PORTF_PF3_SetInterruptHandler(PORTF_PF3_DefaultInterruptHandler);
    PORTC_LED_BLUE_SetInterruptHandler(PORTC_LED_BLUE_DefaultInterruptHandler);
    PORTD_PD3_SetInterruptHandler(PORTD_PD3_DefaultInterruptHandler);
    PORTA_PA0_SetInterruptHandler(PORTA_PA0_DefaultInterruptHandler);
    PORTF_PF5_SetInterruptHandler(PORTF_PF5_DefaultInterruptHandler);
    PORTC_LED_GREEN_SetInterruptHandler(PORTC_LED_GREEN_DefaultInterruptHandler);
    PORTF_PF4_SetInterruptHandler(PORTF_PF4_DefaultInterruptHandler);
}

void PORT_Initialize(void)
{
    /* On AVR devices all peripherals are enable from power on reset, this
     * disables all peripherals to save power. Driver shall enable
     * peripheral if used */

    /* Set all pins to low power mode */
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTE + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTF + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTA + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTB + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTC + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTD + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
}

/**
  Allows selecting an interrupt handler for PORTA_PA2 at application runtime
*/
void PORTA_PA2_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTA_PA2_InterruptHandler = interruptHandler;
}

void PORTA_PA2_DefaultInterruptHandler(void)
{
    // add your PORTA_PA2 interrupt custom code
    // or set custom function using PORTA_PA2_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTC_PC3 at application runtime
*/
void PORTC_PC3_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTC_PC3_InterruptHandler = interruptHandler;
}

void PORTC_PC3_DefaultInterruptHandler(void)
{
    // add your PORTC_PC3 interrupt custom code
    // or set custom function using PORTC_PC3_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTA_PA1 at application runtime
*/
void PORTA_PA1_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTA_PA1_InterruptHandler = interruptHandler;
}

void PORTA_PA1_DefaultInterruptHandler(void)
{
    // add your PORTA_PA1 interrupt custom code
    // or set custom function using PORTA_PA1_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTA_BL at application runtime
*/
void PORTA_BL_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTA_BL_InterruptHandler = interruptHandler;
}

void PORTA_BL_DefaultInterruptHandler(void)
{
    // add your PORTA_BL interrupt custom code
    // or set custom function using PORTA_BL_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTD_PD7 at application runtime
*/
void PORTD_PD7_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTD_PD7_InterruptHandler = interruptHandler;
}

void PORTD_PD7_DefaultInterruptHandler(void)
{
    // add your PORTD_PD7 interrupt custom code
    // or set custom function using PORTD_PD7_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTA_AL at application runtime
*/
void PORTA_AL_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTA_AL_InterruptHandler = interruptHandler;
}

void PORTA_AL_DefaultInterruptHandler(void)
{
    // add your PORTA_AL interrupt custom code
    // or set custom function using PORTA_AL_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTA_USER1 at application runtime
*/
void PORTA_USER1_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTA_USER1_InterruptHandler = interruptHandler;
}

void PORTA_USER1_DefaultInterruptHandler(void)
{
    // add your PORTA_USER1 interrupt custom code
    // or set custom function using PORTA_USER1_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTA_CL at application runtime
*/
void PORTA_CL_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTA_CL_InterruptHandler = interruptHandler;
}

void PORTA_CL_DefaultInterruptHandler(void)
{
    // add your PORTA_CL interrupt custom code
    // or set custom function using PORTA_CL_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTA_USER2 at application runtime
*/
void PORTA_USER2_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTA_USER2_InterruptHandler = interruptHandler;
}

void PORTA_USER2_DefaultInterruptHandler(void)
{
    // add your PORTA_USER2 interrupt custom code
    // or set custom function using PORTA_USER2_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTF_BUTTON at application runtime
*/
void PORTF_BUTTON_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTF_BUTTON_InterruptHandler = interruptHandler;
}

void PORTF_BUTTON_DefaultInterruptHandler(void)
{
    // add your PORTF_BUTTON interrupt custom code
    // or set custom function using PORTF_BUTTON_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTC_LED_RED at application runtime
*/
void PORTC_LED_RED_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTC_LED_RED_InterruptHandler = interruptHandler;
}

void PORTC_LED_RED_DefaultInterruptHandler(void)
{
    // add your PORTC_LED_RED interrupt custom code
    // or set custom function using PORTC_LED_RED_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTD_PD1 at application runtime
*/
void PORTD_PD1_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTD_PD1_InterruptHandler = interruptHandler;
}

void PORTD_PD1_DefaultInterruptHandler(void)
{
    // add your PORTD_PD1 interrupt custom code
    // or set custom function using PORTD_PD1_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTF_PF3 at application runtime
*/
void PORTF_PF3_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTF_PF3_InterruptHandler = interruptHandler;
}

void PORTF_PF3_DefaultInterruptHandler(void)
{
    // add your PORTF_PF3 interrupt custom code
    // or set custom function using PORTF_PF3_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTC_LED_BLUE at application runtime
*/
void PORTC_LED_BLUE_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTC_LED_BLUE_InterruptHandler = interruptHandler;
}

void PORTC_LED_BLUE_DefaultInterruptHandler(void)
{
    // add your PORTC_LED_BLUE interrupt custom code
    // or set custom function using PORTC_LED_BLUE_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTD_PD3 at application runtime
*/
void PORTD_PD3_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTD_PD3_InterruptHandler = interruptHandler;
}

void PORTD_PD3_DefaultInterruptHandler(void)
{
    // add your PORTD_PD3 interrupt custom code
    // or set custom function using PORTD_PD3_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTA_PA0 at application runtime
*/
void PORTA_PA0_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTA_PA0_InterruptHandler = interruptHandler;
}

void PORTA_PA0_DefaultInterruptHandler(void)
{
    // add your PORTA_PA0 interrupt custom code
    // or set custom function using PORTA_PA0_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTF_PF5 at application runtime
*/
void PORTF_PF5_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTF_PF5_InterruptHandler = interruptHandler;
}

void PORTF_PF5_DefaultInterruptHandler(void)
{
    // add your PORTF_PF5 interrupt custom code
    // or set custom function using PORTF_PF5_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTC_LED_GREEN at application runtime
*/
void PORTC_LED_GREEN_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTC_LED_GREEN_InterruptHandler = interruptHandler;
}

void PORTC_LED_GREEN_DefaultInterruptHandler(void)
{
    // add your PORTC_LED_GREEN interrupt custom code
    // or set custom function using PORTC_LED_GREEN_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTF_PF4 at application runtime
*/
void PORTF_PF4_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTF_PF4_InterruptHandler = interruptHandler;
}

void PORTF_PF4_DefaultInterruptHandler(void)
{
    // add your PORTF_PF4 interrupt custom code
    // or set custom function using PORTF_PF4_SetInterruptHandler()
}
