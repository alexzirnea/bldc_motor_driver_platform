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


#include "../include/ccl.h"

/**
 * \brief Initialize CCL peripheral
 * \return Return value 0 if success
 */
void (*CCL0_isr_cb)(void) = NULL;

void CCL0_SetCaptIsrCallback(CCL_cb_t cb)
{
	CCL0_isr_cb = cb;
}

ISR(CCL_CCL_vect)
{
	/* Insert your TCB interrupt handling code */

	/**
	 * The interrupt flag is cleared by writing 1 to it, or when the Capture register
	 * is read in Capture mode
	 */
	 if(CCL.INTFLAGS & CCL_INT0_bm)
        {
            if (CCL0_isr_cb != NULL)
            {
                (*CCL0_isr_cb)();
            }

            CCL.INTFLAGS = CCL_INT0_bm;
        }
	 
}


int8_t CCL_Initialize()
{

    //INTMODE3 INTDISABLE; INTMODE2 INTDISABLE; INTMODE1 INTDISABLE; INTMODE0 BOTH; 
	CCL.INTCTRL0 = 0x03;

    //INT 0; 
	CCL.INTFLAGS = 0x00;

    //INSEL1 MASK; INSEL0 AC0; 
	CCL.LUT0CTRLB = 0x06;

    //INSEL2 EVENTA; 
	CCL.LUT0CTRLC = 0x03;

    //INSEL1 MASK; INSEL0 MASK; 
	CCL.LUT1CTRLB = 0x00;
	
    //INSEL2 MASK; 
	CCL.LUT1CTRLC = 0x00;

    //INSEL1 MASK; INSEL0 MASK; 
	CCL.LUT2CTRLB = 0x00;
	
    //INSEL2 MASK; 
	CCL.LUT2CTRLC = 0x00;

    //INSEL1 MASK; INSEL0 MASK; 
	CCL.LUT3CTRLB = 0x00;
	
    //INSEL2 MASK; 
	CCL.LUT3CTRLC = 0x00;

    //SEQSEL0 DISABLE; 
	CCL.SEQCTRL0 = 0x00;

    //SEQSEL1 DISABLE; 
	CCL.SEQCTRL1 = 0x00;

    //Truth 0
	CCL.TRUTH0 = 0xA2;

    //Truth 1
	CCL.TRUTH1 = 0x00;

    //Truth 2
	CCL.TRUTH2 = 0x00;

    //Truth 3
	CCL.TRUTH3 = 0x00;

    //EDGEDET DIS; OUTEN disabled; FILTSEL SYNCH; CLKSRC IN2; ENABLE enabled; 
	CCL.LUT0CTRLA = 0x13;

    //EDGEDET DIS; OUTEN disabled; FILTSEL DISABLE; CLKSRC CLKPER; ENABLE disabled; 
	CCL.LUT1CTRLA = 0x00;

    //EDGEDET DIS; OUTEN disabled; FILTSEL DISABLE; CLKSRC CLKPER; ENABLE disabled; 
	CCL.LUT2CTRLA = 0x00;

    //EDGEDET DIS; OUTEN disabled; FILTSEL DISABLE; CLKSRC CLKPER; ENABLE disabled; 
	CCL.LUT3CTRLA = 0x00;

    //RUNSTDBY disabled; ENABLE enabled; 
	CCL.CTRLA = 0x01;

	return 0;
}

