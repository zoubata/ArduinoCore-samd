/*
  Copyright (c) 2015 Arduino LLC.  All right reserved.
  Copyright (c) 2017 MattairTech LLC. All right reserved.
  Copyright (c) 2018 Zoubworld LLC. All right reserved.
  
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "Arduino.h"
#include "wiring_private.h"
#include "sam.h"

#include <string.h>


static voidFuncPtr ISRcallback[EXTERNAL_NUM_INTERRUPTS];
static uint32_t    ISRlist[EXTERNAL_NUM_INTERRUPTS];
static uint32_t    nints; // Stores total number of attached interrupts

/* Configure I/O interrupt sources */
static void __initialize()
{
  memset(ISRlist,     0, sizeof(ISRlist));
  memset(ISRcallback, 0, sizeof(ISRcallback));
  nints = 0;

  NVIC_DisableIRQ(EIC_IRQn);
  NVIC_ClearPendingIRQ(EIC_IRQn);
  NVIC_SetPriority(EIC_IRQn, ((1<<__NVIC_PRIO_BITS) -1)/2);/* set Priority medium : just to be sure that we are called on time but not kill other critical peripheral.*/
  NVIC_EnableIRQ(EIC_IRQn);

  // Enable GCLK for IEC (External Interrupt Controller)
#if (SAMD20 ||SAMD21 || SAMD11)
  GCLK->CLKCTRL.reg = ( GCLK_CLKCTRL_ID( GCM_EIC ) | GCLK_CLKCTRL_GEN_GCLK0 | GCLK_CLKCTRL_CLKEN );
  while ( GCLK->STATUS.reg & GCLK_STATUS_SYNCBUSY );
#elif (SAML21 || SAMC21)
  MCLK->APBAMASK.reg |= MCLK_APBAMASK_EIC;
  GCLK->PCHCTRL[GCM_EIC].reg = ( GCLK_PCHCTRL_CHEN | GCLK_PCHCTRL_GEN_GCLK0 );
  while ( (GCLK->PCHCTRL[GCM_EIC].reg & GCLK_PCHCTRL_CHEN) != GCLK_PCHCTRL_CHEN );	// wait for sync
#else
  #error "WInterrupts.c: Unsupported chip"
#endif

// SAML and SAMC EIC.CONFIG registers are enable-protected, thus must be disabled/enabled for each config change
#if (SAMD20 ||SAMD21   || SAMD11)
/* Shall we do that?
  // Do a software reset on EIC
  EIC->CTRL.SWRST.bit = 1 ;
  while ((EIC->CTRL.SWRST.bit == 1) && (EIC->STATUS.SYNCBUSY.bit == 1)) { }
*/

  // Enable EIC
  EIC->CTRL.bit.ENABLE = 1;
  while (EIC->STATUS.bit.SYNCBUSY == 1) { }
#endif
}
// Interrupts
EExt_Interrupts digitalPinToInterrupt(uint32_t pin)
{
#if ARDUINO_SAMD_VARIANT_COMPLIANCE >= 10606
  EExt_Interrupts in = g_APinDescription[pin].ulExtInt;
#else
  EExt_Interrupts in = digitalPinToInterrupt(pin);
#endif 
}

/*
uint32_t digitalPinToInterrupt(uint32_t pin)
{
EExt_Interrupts in = g_APinDescription[pin].ulExtInt;
if (callbacksInt[in]!=0) return EXTERNAL_INT_NONE;// if already assigned fail
return pin;
}*/
/*
 * \brief Specifies a named Interrupt Service Routine (ISR) to call when an interrupt occurs.
 *        Replaces any previous function that was attached to the interrupt.
 */
int attachInterrupt(uint32_t pin, voidFuncPtr callback, uint32_t mode)
{
  static int enabled = 0;
  uint32_t config;
  uint32_t pos;


#if ARDUINO_SAMD_VARIANT_COMPLIANCE >= 10606
  EExt_Interrupts in = g_APinDescription[pin].ulExtInt;
#else
  EExt_Interrupts in = digitalPinToInterrupt(pin);
#endif
  if (in == NOT_AN_INTERRUPT )
    return -1;
  if (in == EXTERNAL_INT_NMI )
    return -2;//todo



  if (!enabled) {
    __initialize();
    enabled = 1;
  }

uint32_t inMask = 1 << in;

  // Enable wakeup capability on pin in case being used during sleep (WAKEUP always enabled on SAML and SAMC)
#if (SAMD20 || SAMD21 || SAMD11)

  EIC->WAKEUP.reg |= inMask;
#endif

#if (SAML21)
  // The CHANGE and RISING interrupt modes on pin A31 on the SAML21 do not seem to work properly
  if ((g_APinDescription[pin].ulPort == 0) && (g_APinDescription[pin].ulPin == 31) && ((mode == CHANGE) || (mode == RISING)))
    return -2;
#endif

signed int r=0;
  // Assign pin to EIC
  if ((r=pinPeripheral(pin, PIO_EXTINT)) != RET_STATUS_OK)
    return r<<8;

 if (in != EXTERNAL_INT_NMI)
{
  // Assign callback to interrupt
 if (callback)
  {
    // Store interrupts to service in order of when they were attached
    // to allow for first come first serve handler
    uint32_t current = 0;

    // Check if we already have this interrupt
    for (current=0; current<nints; current++) {
      if (ISRlist[current] == inMask) {
        break;
      }
    }
    if (current ==  nints) {
      // Need to make a new entry
      nints++;
    }
    ISRlist[current] = inMask;       // List of interrupt in order of when they were attached
    ISRcallback[current] = callback; // List of callback adresses

  // Look for right CONFIG register to be addressed
  if (in > EXTERNAL_INT_7) {
    config = 1;
	pos = (in - 8) << 2;
  } else {
    config = 0;
	pos = in << 2;
  }

  // Configure the interrupt mode
  
#if (SAML21 || SAMC21)
  EIC->CTRLA.reg = 0;	// disable EIC before changing CONFIG
  while (EIC->SYNCBUSY.reg & EIC_SYNCBUSY_MASK) { }
#endif

    EIC->CONFIG[config].reg &=~ (EIC_CONFIG_SENSE0_Msk << pos); // Reset sense mode, important when changing trigger mode during runtime

    switch (mode)
    {
      case LOW:
        EIC->CONFIG[config].reg |= EIC_CONFIG_SENSE0_LOW_Val << pos;
        break;

      case HIGH:
        EIC->CONFIG[config].reg |= EIC_CONFIG_SENSE0_HIGH_Val << pos;
        break;

      case CHANGE:
        EIC->CONFIG[config].reg |= EIC_CONFIG_SENSE0_BOTH_Val << pos;
        break;

      case FALLING:
        EIC->CONFIG[config].reg |= EIC_CONFIG_SENSE0_FALL_Val << pos;
        break;

      case RISING:
        EIC->CONFIG[config].reg |= EIC_CONFIG_SENSE0_RISE_Val << pos;
        break;
    }
#if (SAML21 || SAMC21)
  EIC->CTRLA.reg = EIC_CTRLA_ENABLE;	// enable EIC
  while (EIC->SYNCBUSY.reg & EIC_SYNCBUSY_MASK) { }
#endif

  // Clear the interrupt flag
  EIC->INTFLAG.reg = (1 << in);

  // Enable the interrupt
  EIC->INTENSET.reg = EIC_INTENSET_EXTINT(inMask);
  }
}
 else
{
ISRcallback[EXTERNAL_INT_NMI]=callback;
 
#if (SAML21 || SAMC21)
  EIC->CTRLA.reg = 0;	// disable EIC before changing CONFIG
  while (EIC->SYNCBUSY.reg & EIC_SYNCBUSY_MASK) { }
#endif

  uint32_t regConfig = (~(EIC_NMICTRL_NMISENSE_Msk << 0) & EIC->NMICTRL.reg);		// copy register to variable, clearing mode bits
  // insert new mode and write to register (the hardware numbering for the 5 interrupt modes is in reverse order to the arduino numbering, so using '5-mode').
  EIC->NMICTRL.reg = (regConfig | ((5-mode) ));

#if (SAML21 || SAMC21)
  EIC->CTRLA.reg = EIC_CTRLA_ENABLE;	// enable EIC
  while (EIC->SYNCBUSY.reg & EIC_SYNCBUSY_MASK) { }
#endif

  // Clear the interrupt flag
  EIC->NMIFLAG.reg = (1 << in);

  // Enable the interrupt
  //NMI always enabled
}
  
return 01;
}


/*
 * \brief Turns off the given interrupt.
 */
void detachInterrupt(uint32_t pin)
{
#if (ARDUINO_SAMD_VARIANT_COMPLIANCE >= 10606)
  EExt_Interrupts in = g_APinDescription[pin].ulExtInt;
#else
  EExt_Interrupts in = digitalPinToInterrupt(pin);
#endif 
  if (in == NOT_AN_INTERRUPT )
    return;

  uint32_t inMask = 1 << in;
  EIC->INTENCLR.reg = EIC_INTENCLR_EXTINT(inMask);
  
  // Disable wakeup capability on pin during sleep (WAKEUP always enabled on SAML and SAMC)
#if (SAMD21 || SAMD11)
  EIC->WAKEUP.reg &= ~(1 << in);
#endif

  // Remove callback from the ISR list
  uint32_t current;
  for (current=0; current<nints; current++) {
    if (ISRlist[current] == inMask) {
      break;
    }
  }
  if (current == nints) return; // We didn't have it

  // Shift the reminder down
  for (; current<nints-1; current++) {
    ISRlist[current]     = ISRlist[current+1];
    ISRcallback[current] = ISRcallback[current+1];
  }
  nints--;
}

/*
 * External Interrupt Controller NVIC Interrupt Handler
 */
void EIC_Handler(void)
{
  // Calling the routine directly from -here- takes about 1us
  // Depending on where you are in the list it will take longer

  // Loop over all enabled interrupts in the list
  for (uint32_t i=0; i<nints; i++)
  {
    if ((EIC->INTFLAG.reg & ISRlist[i]) != 0)
    {
      // Call the callback function
      ISRcallback[i]();
      // Clear the interrupt
      EIC->INTFLAG.reg = ISRlist[i];
      
    }
  }
}
/*
 * External Interrupt Controller NVIC Interrupt Handler
 */
void NMI_Handler(void)
{
      // Call the callback function if assigned
      if (ISRcallback[EXTERNAL_INT_NMI]) {
        ISRcallback[EXTERNAL_INT_NMI]();
      }

      // Clear the interrupt
      EIC->NMIFLAG.reg = 1 ;
    
  
}

	  