/*
  Copyright (c) 2015 Arduino LLC.  All right reserved.

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

#include <sam.h>
#include <variant.h>
#include <stdio.h>

/* RTOS Hooks */
extern void svcHook(void);
extern void pendSVHook(void);
extern int sysTickHook(void);
extern void SystemInit( void );



#if !( defined(__ICCARM__) || defined(__AARM__) )


/* ggc reset code not compatible with link script*/
/*
#if SAMC21N
#include "samc21n\source\gcc\startup_samc21.c"
#elif SAMC21_SERIES
#include "samc21\source\gcc\startup_samc21.c"
#elif SAMC20N
#include "samc20n\source\gcc\startup_samc20.c"
#elif SAMC20_SERIES
#include "samc20\source\gcc\startup_samc20.c"
#elif SAMD20_SERIES
#include "samd20\source\gcc\startup_samd20.c"
#elif SAMD21_SERIES
#include "samd21\source\gcc\startup_samd21.c"
#elif SAMD10_SERIES
#include "samd10\source\gcc\startup_samd10.c"
#elif SAMD9_SERIES
#include "samd9\source\gcc\startup_samd9.c"
#elif SAMD11_SERIES
#include "samd11\source\gcc\startup_samd11.c"
#elif SAML10_SERIES
#include "saml20\source\gcc\startup_saml10.c"
#elif SAML11_SERIES
#include "saml11\source\gcc\startup_saml11.c"
#elif SAML21_SERIES
#include "saml21\source\gcc\startup_saml21.c"
#elif SAML22_SERIES
#include "saml22\source\gcc\startup_saml22.c"
#endif // SAML_SERIES 
*/




// Default empty handler 
void Dummy_Handler(void)
{
#if defined DEBUG
  __BKPT(3);
#endif
  for (;;) { }
}
// Cortex-M0+ core handlers 
void HardFault_Handler(void);
void Reset_Handler    (void);
void NMI_Handler      (void) __attribute__ ((weak, alias("Dummy_Handler")));
void SVC_Handler      (void) __attribute__ ((weak, alias("Dummy_Handler")));
void PendSV_Handler   (void) __attribute__ ((weak, alias("Dummy_Handler")));
void SysTick_Handler  (void);

// Peripherals handlers 
void SYSTEM_Handler   (void) __attribute__ ((weak, alias("Dummy_Handler")));
void PM_Handler       (void) __attribute__ ((weak, alias("Dummy_Handler")));
void SYSCTRL_Handler  (void) __attribute__ ((weak, alias("Dummy_Handler")));
void WDT_Handler      (void) __attribute__ ((weak, alias("Dummy_Handler")));
void RTC_Handler      (void) __attribute__ ((weak, alias("Dummy_Handler")));
void EIC_Handler      (void) __attribute__ ((weak, alias("Dummy_Handler")));
void FREQM_Handler    (void) __attribute__ ((weak, alias("Dummy_Handler")));
void TSENS_Handler    (void) __attribute__ ((weak, alias("Dummy_Handler")));
void NVMCTRL_Handler  (void) __attribute__ ((weak, alias("Dummy_Handler")));
void DMAC_Handler     (void) __attribute__ ((weak, alias("Dummy_Handler")));
void USB_Handler      (void) __attribute__ ((weak));
void EVSYS_Handler    (void) __attribute__ ((weak, alias("Dummy_Handler")));
void SERCOM0_Handler  (void) __attribute__ ((weak, alias("Dummy_Handler")));
void SERCOM1_Handler  (void) __attribute__ ((weak, alias("Dummy_Handler")));
void SERCOM2_Handler  (void) __attribute__ ((weak, alias("Dummy_Handler")));
void SERCOM3_Handler  (void) __attribute__ ((weak, alias("Dummy_Handler")));
void SERCOM4_Handler  (void) __attribute__ ((weak, alias("Dummy_Handler")));
void SERCOM5_Handler  (void) __attribute__ ((weak, alias("Dummy_Handler")));
void SERCOM6_Handler  (void) __attribute__ ((weak, alias("Dummy_Handler")));
void SERCOM7_Handler  (void) __attribute__ ((weak, alias("Dummy_Handler")));
void CAN0_Handler     (void) __attribute__ ((weak, alias("Dummy_Handler")));
void CAN1_Handler     (void) __attribute__ ((weak, alias("Dummy_Handler")));
void TCC0_Handler     (void) __attribute__ ((weak, alias("Dummy_Handler")));
void TCC1_Handler     (void) __attribute__ ((weak, alias("Dummy_Handler")));
void TCC2_Handler     (void) __attribute__ ((weak, alias("Dummy_Handler")));
void TC0_Handler      (void) __attribute__ ((weak, alias("Dummy_Handler")));
void TC1_Handler      (void) __attribute__ ((weak, alias("Dummy_Handler")));
void TC2_Handler      (void) __attribute__ ((weak, alias("Dummy_Handler")));
void TC3_Handler      (void) __attribute__ ((weak, alias("Dummy_Handler")));
void TC4_Handler      (void) __attribute__ ((weak, alias("Dummy_Handler")));
void TC5_Handler      (void) __attribute__ ((weak, alias("Dummy_Handler")));
void TC6_Handler      (void) __attribute__ ((weak, alias("Dummy_Handler")));
void TC7_Handler      (void) __attribute__ ((weak, alias("Dummy_Handler")));
void ADC_Handler      (void) __attribute__ ((weak, alias("Dummy_Handler")));
void ADC0_Handler     (void) __attribute__ ((weak, alias("Dummy_Handler")));
void ADC1_Handler     (void) __attribute__ ((weak, alias("Dummy_Handler")));
void AC_Handler       (void) __attribute__ ((weak, alias("Dummy_Handler")));
void DAC_Handler      (void) __attribute__ ((weak, alias("Dummy_Handler")));
void SDADC_Handler    (void) __attribute__ ((weak, alias("Dummy_Handler")));
void PTC_Handler      (void) __attribute__ ((weak, alias("Dummy_Handler")));
void I2S_Handler      (void) __attribute__ ((weak, alias("Dummy_Handler")));
void AES_Handler      (void) __attribute__ ((weak, alias("Dummy_Handler")));
void TRNG_Handler     (void) __attribute__ ((weak, alias("Dummy_Handler")));


// Initialize segments 
extern uint32_t __etext;
extern uint32_t __data_start__;
extern uint32_t __data_end__;
extern uint32_t __bss_start__;
extern uint32_t __bss_end__;
extern uint32_t __StackTop;



// Exception Table 
__attribute__ ((section(".isr_vector"))) const DeviceVectors exception_table =
#if SAMC21N
{
        // Configure Initial Stack Pointer, using linker-generated symbols 
        .pvStack                = (void*) (&__StackTop),

        .pfnReset_Handler       = (void*) Reset_Handler,
        .pfnNMI_Handler         = (void*) NMI_Handler,
        .pfnHardFault_Handler   = (void*) HardFault_Handler,
        .pvReservedM12          = (void*) (0UL), // Reserved 
        .pvReservedM11          = (void*) (0UL), // Reserved 
        .pvReservedM10          = (void*) (0UL), // Reserved 
        .pvReservedM9           = (void*) (0UL), // Reserved 
        .pvReservedM8           = (void*) (0UL), // Reserved 
        .pvReservedM7           = (void*) (0UL), // Reserved 
        .pvReservedM6           = (void*) (0UL), // Reserved 
        .pfnSVC_Handler         = (void*) SVC_Handler,
        .pvReservedM4           = (void*) (0UL), // Reserved 
        .pvReservedM3           = (void*) (0UL), // Reserved 
        .pfnPendSV_Handler      = (void*) PendSV_Handler,
        .pfnSysTick_Handler     = (void*) SysTick_Handler,

        // Configurable interrupts 
        .pfnSYSTEM_Handler      = (void*) SYSTEM_Handler,         //  0 Main Clock, 32k Oscillators Control, Oscillators Control, Peripheral Access Controller, Power Manager, Supply Controller, Trigger Allocator 
        .pfnWDT_Handler         = (void*) WDT_Handler,            //  1 Watchdog Timer 
        .pfnRTC_Handler         = (void*) RTC_Handler,            //  2 Real-Time Counter 
        .pfnEIC_Handler         = (void*) EIC_Handler,            //  3 External Interrupt Controller 
        .pfnFREQM_Handler       = (void*) FREQM_Handler,          //  4 Frequency Meter 
#ifdef ID_TSENS
        .pfnTSENS_Handler       = (void*) TSENS_Handler,          //  5 Temperature Sensor 
#else
        .pvReserved5            = (void*) (0UL),                  //  5 Reserved 
#endif
        .pfnNVMCTRL_Handler     = (void*) NVMCTRL_Handler,        //  6 Non-Volatile Memory Controller 
        .pfnDMAC_Handler        = (void*) DMAC_Handler,           //  7 Direct Memory Access Controller 
        .pfnEVSYS_Handler       = (void*) EVSYS_Handler,          //  8 Event System Interface 
        .pfnINT9_Handler        = (void*) INT9_Handler,           //  9 Serial Communication Interface 0, Serial Communication Interface 6 
        .pfnINT10_Handler       = (void*) INT10_Handler,          // 10 Serial Communication Interface 1, Serial Communication Interface 7 
        .pfnSERCOM2_Handler     = (void*) SERCOM2_Handler,        // 11 Serial Communication Interface 2 
        .pfnSERCOM3_Handler     = (void*) SERCOM3_Handler,        // 12 Serial Communication Interface 3 
#ifdef ID_SERCOM4
        .pfnSERCOM4_Handler     = (void*) SERCOM4_Handler,        // 13 Serial Communication Interface 4 
#else
        .pvReserved13           = (void*) (0UL),                  // 13 Reserved 
#endif
#ifdef ID_SERCOM5
        .pfnSERCOM5_Handler     = (void*) SERCOM5_Handler,        // 14 Serial Communication Interface 5 
#else
        .pvReserved14           = (void*) (0UL),                  // 14 Reserved 
#endif
#ifdef ID_CAN0
        .pfnCAN0_Handler        = (void*) CAN0_Handler,           // 15 Control Area Network 0 
#else
        .pvReserved15           = (void*) (0UL),                  // 15 Reserved 
#endif
#ifdef ID_CAN1
        .pfnCAN1_Handler        = (void*) CAN1_Handler,           // 16 Control Area Network 1 
#else
        .pvReserved16           = (void*) (0UL),                  // 16 Reserved 
#endif
        .pfnTCC0_Handler        = (void*) TCC0_Handler,           // 17 Timer Counter Control 0 
        .pfnTCC1_Handler        = (void*) TCC1_Handler,           // 18 Timer Counter Control 1 
#ifdef ID_TCC2
        .pfnTCC2_Handler        = (void*) TCC2_Handler,           // 19 Timer Counter Control 2 
#else
        .pvReserved19           = (void*) (0UL),                  // 19 Reserved 
#endif
        .pfnINT20_Handler       = (void*) INT20_Handler,          // 20 Basic Timer Counter 0, Basic Timer Counter 5 
        .pfnINT21_Handler       = (void*) INT21_Handler,          // 21 Basic Timer Counter 1, Basic Timer Counter 6 
        .pfnINT22_Handler       = (void*) INT22_Handler,          // 22 Basic Timer Counter 2, Basic Timer Counter 7 
        .pfnTC3_Handler         = (void*) TC3_Handler,            // 23 Basic Timer Counter 3 
        .pfnTC4_Handler         = (void*) TC4_Handler,            // 24 Basic Timer Counter 4 
#ifdef ID_ADC0
        .pfnADC0_Handler        = (void*) ADC0_Handler,           // 25 Analog Digital Converter 0 
#else
        .pvReserved25           = (void*) (0UL),                  // 25 Reserved 
#endif
#ifdef ID_ADC1
        .pfnADC1_Handler        = (void*) ADC1_Handler,           // 26 Analog Digital Converter 1 
#else
        .pvReserved26           = (void*) (0UL),                  // 26 Reserved 
#endif
#ifdef ID_AC
        .pfnAC_Handler          = (void*) AC_Handler,             // 27 Analog Comparators 
#else
        .pvReserved27           = (void*) (0UL),                  // 27 Reserved 
#endif
#ifdef ID_DAC
        .pfnDAC_Handler         = (void*) DAC_Handler,            // 28 Digital Analog Converter 
#else
        .pvReserved28           = (void*) (0UL),                  // 28 Reserved 
#endif
#ifdef ID_SDADC
        .pfnSDADC_Handler       = (void*) SDADC_Handler,          // 29 Sigma-Delta Analog Digital Converter 
#else
        .pvReserved29           = (void*) (0UL),                  // 29 Reserved 
#endif
#ifdef ID_PTC
        .pfnPTC_Handler         = (void*) PTC_Handler             // 30 Peripheral Touch Controller 
#else
        .pvReserved30           = (void*) (0UL)                   // 30 Reserved 
#endif
};
#else
{
  // Configure Initial Stack Pointer, using linker-generated symbols 
  (void*) (&__StackTop),

  (void*) Reset_Handler,
  (void*) NMI_Handler,
  (void*) HardFault_Handler,
  (void*) (0UL), // Reserved 
  (void*) (0UL), // Reserved 
  (void*) (0UL), // Reserved 
  (void*) (0UL), // Reserved 
  (void*) (0UL), // Reserved 
  (void*) (0UL), // Reserved 
  (void*) (0UL), // Reserved 
  (void*) SVC_Handler,
  (void*) (0UL), // Reserved 
  (void*) (0UL), // Reserved 
  (void*) PendSV_Handler,
  (void*) SysTick_Handler,

  // Configurable interrupts 
#if (SAMD21 || SAMD11)
  (void*) PM_Handler,             //  0 Power Manager 
  (void*) SYSCTRL_Handler,        //  1 System Control 
  (void*) WDT_Handler,            //  2 Watchdog Timer 
  (void*) RTC_Handler,            //  3 Real-Time Counter 
  (void*) EIC_Handler,            //  4 External Interrupt Controller 
  (void*) NVMCTRL_Handler,        //  5 Non-Volatile Memory Controller 
  (void*) DMAC_Handler,           //  6 Direct Memory Access Controller 
  (void*) USB_Handler,            //  7 Universal Serial Bus 
  (void*) EVSYS_Handler,          //  8 Event System Interface 
  (void*) SERCOM0_Handler,        //  9 Serial Communication Interface 0 
  (void*) SERCOM1_Handler,        // 10 Serial Communication Interface 1 
  (void*) SERCOM2_Handler,        // 11 Serial Communication Interface 2 
#if (SAMD21)
  (void*) SERCOM3_Handler,        // 12 Serial Communication Interface 3 
  (void*) SERCOM4_Handler,        // 13 Serial Communication Interface 4 
  (void*) SERCOM5_Handler,        // 14 Serial Communication Interface 5 
#endif
  (void*) TCC0_Handler,           // 15 / 12 Timer Counter Control 0 
#if (SAMD21)
  (void*) TCC1_Handler,           // 16 Timer Counter Control 1 
  (void*) TCC2_Handler,           // 17 Timer Counter Control 2 
  (void*) TC3_Handler,            // 18 Basic Timer Counter 3 
  (void*) TC4_Handler,            // 19 Basic Timer Counter 4 
  (void*) TC5_Handler,            // 20 Basic Timer Counter 5 
  (void*) TC6_Handler,            // 21 Basic Timer Counter 6 
  (void*) TC7_Handler,            // 22 Basic Timer Counter 7 
#else
  (void*) TC1_Handler,            // 13 Basic Timer Counter 1 
  (void*) TC2_Handler,            // 14 Basic Timer Counter 2 
#endif
  (void*) ADC_Handler,            // 23 / 15 Analog Digital Converter 
  (void*) AC_Handler,             // 24 / 16 Analog Comparators 
  (void*) DAC_Handler,            // 25 / 17 Digital Analog Converter 
  (void*) PTC_Handler,            // 26 / 18 Peripheral Touch Controller 
#if (SAMD21)
  (void*) I2S_Handler,             // 27 Inter-IC Sound Interface 
  (void*) (0UL),                  // Reserved 
#endif

#elif (SAML21 || SAMC21)
  (void*) SYSTEM_Handler,         //  0 SYSTEM handler (includes SYSTEM, MCLK, OSCCTRL, OSC32KCTRL, PAC, PM, SUPC, and TAL) 
  (void*) WDT_Handler,            //  1 Watchdog Timer 
  (void*) RTC_Handler,            //  2 Real-Time Counter 
  (void*) EIC_Handler,            //  3 External Interrupt Controller 
#if (SAMC21)
  (void*) FREQM_Handler,          //  4 FREQM 
  (void*) TSENS_Handler,          //  5 TSENS 
#endif
  (void*) NVMCTRL_Handler,        //  4 / 6 Non-Volatile Memory Controller 
  (void*) DMAC_Handler,           //  5 / 7 Direct Memory Access Controller 
#if (SAML21)
  (void*) USB_Handler,            //  6 Universal Serial Bus 
#endif
  (void*) EVSYS_Handler,          //  7 / 8 Event System Interface 
  (void*) SERCOM0_Handler,        //  8 / 9 Serial Communication Interface 0 
  (void*) SERCOM1_Handler,        //  9 / 10 Serial Communication Interface 1 
  (void*) SERCOM2_Handler,        // 10 / 11 Serial Communication Interface 2 
  (void*) SERCOM3_Handler,        // 11 / 12 Serial Communication Interface 3 
  (void*) SERCOM4_Handler,        // 12 / 13 Serial Communication Interface 4 
  (void*) SERCOM5_Handler,        // 13 / 14 Serial Communication Interface 5 
#if (SAMC21)
  (void*) CAN0_Handler,           // 15 CAN0 
  (void*) CAN1_Handler,           // 16 CAN1 
#endif
  (void*) TCC0_Handler,           // 14 / 17 Timer Counter Control 0 
  (void*) TCC1_Handler,           // 15 / 18 Timer Counter Control 1 
  (void*) TCC2_Handler,           // 16 / 19 Timer Counter Control 2 
  (void*) TC0_Handler,            // 17 / 20 Basic Timer Counter 0 
  (void*) TC1_Handler,            // 18 / 21 Basic Timer Counter 1 
  (void*) TC2_Handler,            // 19 / 22 Basic Timer Counter 2 
  (void*) TC3_Handler,            // 20 / 23 Basic Timer Counter 3 
  (void*) TC4_Handler,            // 21 / 24 Basic Timer Counter 4 
#if (SAMC21)
  (void*) ADC0_Handler,           // 25 ADC0 
  (void*) ADC1_Handler,           // 26 ADC1 
#else
  (void*) ADC_Handler,            // 22 Analog Digital Converter 
#endif
  (void*) AC_Handler,             // 23 / 27 Analog Comparators 
  (void*) DAC_Handler,            // 24 / 28 Digital Analog Converter 
#if (SAMC21)
  (void*) SDADC_Handler,          // 29 SDADC 
#endif
  (void*) PTC_Handler,            // 25 / 30 Peripheral Touch Controller 
#if (SAML21)
  (void*) AES_Handler,            // 26 AES 
  (void*) TRNG_Handler,           // 27 TRNG 
#endif

#else
#error "cortex_handlers.c: Unsupported chip"
#endif
};

#endif //C21N


extern int main(void);
// Initialize segments 
extern uint32_t __etext;
extern uint32_t __data_start__;
extern uint32_t __data_end__;
extern uint32_t __bss_start__;
extern uint32_t __bss_end__;
extern uint32_t __StackTop;
/* This is called on processor reset to initialize the device and call main() */
void Reset_Handler(void)
{
  uint32_t *pSrc, *pDest;

  /* Initialize the initialized data section */
  pSrc = &__etext;
  pDest = &__data_start__;

  if ((&__data_start__ != &__data_end__) && (pSrc != pDest)) {
    for (; pDest < &__data_end__; pDest++, pSrc++)
      *pDest = *pSrc;
  }

  /* Clear the zero section */
  if ((&__data_start__ != &__data_end__) && (pSrc != pDest)) {
    for (pDest = &__bss_start__; pDest < &__bss_end__; pDest++)
      *pDest = 0;
  }


  main();

  while (1)
    ;
}

#else

#if SAMC21N
#include "samc21n\iar\iar\startup_samc21.c"
#elif SAMC21_SERIES
#include "samc21\iar\iar\startup_samc21.c"
#elif SAMC20N
#include "samc20n\iar\iar\startup_samc20.c"
#elif SAMC20_SERIES
#include "samc20\iar\iar\startup_samc20.c"
#elif SAMD20_SERIES
#include "samd20\iar\iar\startup_samd20.c"
#elif SAMD21_SERIES
#include "samd21\iar\iar\startup_samd21.c"
#elif SAMD10_SERIES
#include "samd10\iar\iar\startup_samd10.c"
#elif SAMD9_SERIES
#include "samd9\iar\iar\startup_samd9.c"
#elif SAMD11_SERIES
#include "samd11\iar\iar\startup_samd11.c"
#elif SAML10_SERIES
#include "saml20\iar\iar\startup_saml10.c"
#elif SAML11_SERIES
#include "saml11\iar\iar\startup_saml11.c"
#elif SAML21_SERIES
#include "saml21\iar\iar\startup_saml21.c"
#elif SAML22_SERIES
#include "saml22\iar\iar\startup_saml22.c"
#endif //SAML_SERIES 

#endif



/* Default Arduino systick handler */
extern void SysTick_DefaultHandler(void);
/* RTOS Hooks */
extern void svcHook(void);
extern void pendSVHook(void);
extern int sysTickHook(void);
extern void SystemInit( void );

#if !defined(USB_DISABLED)
static void (*usb_isr)(void) = NULL;

void USB_Handler(void)
{
  if (usb_isr)
    usb_isr();
}

void USB_SetHandler(void (*new_usb_isr)(void))
{
  usb_isr = new_usb_isr;
}
#endif

