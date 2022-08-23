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


#include "../include/ac0.h"

void (*AC0_isr_cb)(void) = NULL;

void AC0_SetCmpIsrCallback(AC_cb_t cb)
{
	AC0_isr_cb = cb;
}

ISR(AC0_AC_vect)
{
	/* Insert your TCB interrupt handling code */

	/**
	 * The interrupt flag is cleared by writing 1 to it, or when the Capture register
	 * is read in Capture mode
	 */
	 if(AC0.STATUS & AC_CMP_bm)
        {
            if (AC0_isr_cb != NULL)
            {
                (*AC0_isr_cb)();
            }

            AC0.STATUS = AC_CMP_bm;
        }
	 
}

/**
 * \brief Initialize ac interface
 */
int8_t AC0_Initialize()
{
    //CMP enabled; 
    AC0.INTCTRL = 0x00;

    //INVERT disabled; MUXPOS PIN3; MUXNEG PIN0; 
    AC0.MUXCTRLA = 0x18;

    //RUNSTDBY disabled; OUTEN disabled; INTMODE BOTHEDGE; LPMODE DIS; HYSMODE OFF; ENABLE enabled; 
    AC0.CTRLA = 0x01;

    //DATA 255; 
    AC0.DACREF = 0xFF;

    return 0;
}
