/*
  Copyright (c) 2015 Arduino LLC.  All right reserved.
  Copyright (c) 2015 Atmel Corporation/Thibaut VIARD.  All right reserved.

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

#include "sam.h"
#include "board_definitions/board_definitions.h"
#include "util.h"

extern uint32_t SystemCoreClock;

/**
 * \brief system_init() configures the needed clocks and according Flash Read Wait States.
 * At reset:
 * - OSC8M clock source is enabled with a divider by 8 (1MHz).
 * - Generic Clock Generator 0 (GCLKMAIN) is using OSC8M as source.
 * We need to:
 * 1) Enable XOSC32K clock (External on-board 32.768Hz oscillator), will be used as DFLL48M reference.
 * 2) Put XOSC32K as source of Generic Clock Generator 1
 * 3) Put Generic Clock Generator 1 as source for Generic Clock Multiplexer 0 (DFLL48M reference)
 * 4) Enable DFLL48M clock
 * 5) Switch Generic Clock Generator 0 to DFLL48M. CPU will run at 48MHz.
 * 6) Modify PRESCaler value of OSCM to have 8MHz
 * 7) Put OSC8M as source for Generic Clock Generator 3
 */
// Constants for Clock generators
#define GENERIC_CLOCK_GENERATOR_MAIN      (0u)
#define GENERIC_CLOCK_GENERATOR_XOSC32K   (1u)
#define GENERIC_CLOCK_GENERATOR_XOSC      (1u)
#define GENERIC_CLOCK_GENERATOR_OSCULP32K (2u) /* Initialized at reset for WDT */
#define GENERIC_CLOCK_GENERATOR_OSC8M     (3u)
#define GENERIC_CLOCK_GENERATOR_OSC_HS    (3u)

// Constants for Clock multiplexers
#if (SAMD_SERIES || SAML21_SERIES)
  #define GENERIC_CLOCK_MULTIPLEXER_DFLL    (0u)
  #define GENERIC_CLOCK_MULTIPLEXER_FDPLL   (1u)
  #define GENERIC_CLOCK_MULTIPLEXER_FDPLL96M_32K (2u)
#elif (SAMC21_SERIES) || (SAMC20_SERIES)
  #define GENERIC_CLOCK_MULTIPLEXER_FDPLL   (0u)
  #define GENERIC_CLOCK_MULTIPLEXER_FDPLL96M_32K (1u)
#else
  #error "startup.c: Missing dependency or unsupported chip. Please install CMSIS-Atmel from MattairTech (see Prerequisites for Building in README.md)."
#endif

#if (SAMD_SERIES || SAML21_SERIES)
void waitForDFLL( void )
{
#if (SAMD_SERIES)
  while ( (SYSCTRL->PCLKSR.reg & SYSCTRL_PCLKSR_DFLLRDY) == 0 );
#elif (SAML21_SERIES)
  while ( (OSCCTRL->STATUS.reg & OSCCTRL_STATUS_DFLLRDY) == 0 );
#endif
}
#endif

#if (SAML21 || SAMC21 || SAMC20)
void waitForPLL( void )
{
  while ( OSCCTRL->DPLLSYNCBUSY.reg & OSCCTRL_DPLLSYNCBUSY_MASK );
}
#endif

void board_init(void)
{
  /*
   * Disable automatic NVM write operations (errata reference 13134, applies to D21/D11/L21, but not C21)
   */
  NVMCTRL->CTRLB.bit.MANW = 1;

  /* Set 1 Flash Wait State for 48MHz (2 for the L21 and C21), cf tables 20.9 and 35.27 in SAMD21 Datasheet */
#if (SAMD)
  NVMCTRL->CTRLB.bit.RWS = NVMCTRL_CTRLB_RWS_HALF_Val ;	// one wait state
#elif (SAML21 || SAMC21 || SAMC20)
  NVMCTRL->CTRLB.reg |= NVMCTRL_CTRLB_RWS_DUAL ; // two wait states
#endif

  /* Turn on the digital interface clock */
#if (SAMD)
  PM->APBAMASK.reg |= PM_APBAMASK_GCLK;
#elif (SAML21 || SAMC21 || SAMC20)
  MCLK->APBAMASK.reg |= MCLK_APBAMASK_GCLK ;

  MCLK->AHBMASK.reg |=MCLK_AHBMASK_MASK;// enable all
  MCLK->APBAMASK.reg |=MCLK_APBAMASK_MASK;// enable all
  MCLK->APBBMASK.reg |=MCLK_APBBMASK_MASK;// enable all
  MCLK->APBCMASK.reg |=MCLK_APBCMASK_MASK;// enable all
  #if ( SAMC20N)
		MCLK->APBDMASK.reg |=MCLK_APBCDMASK_MASK;// enable all
  #endif
#endif

#if (SAML21)
  PM->INTFLAG.reg = PM_INTFLAG_PLRDY; //clear flag
  PM->PLCFG.reg |= PM_PLCFG_PLSEL_PL2 ;	// must set to highest performance level
  while ( (PM->INTFLAG.reg & PM_INTFLAG_PLRDY) != PM_INTFLAG_PLRDY );
  PM->INTFLAG.reg = PM_INTFLAG_PLRDY; //clear flag
#endif

  /* ----------------------------------------------------------------------------------------------
   * Software reset the GCLK module to ensure it is re-initialized correctly
   */
#if (SAMD)
  GCLK->CTRL.reg = GCLK_CTRL_SWRST;

  while ( (GCLK->CTRL.reg & GCLK_CTRL_SWRST) && (GCLK->STATUS.reg & GCLK_STATUS_SYNCBUSY) );	/* Wait for reset to complete */
#elif (SAML21 || SAMC21 || SAMC20)
  GCLK->CTRLA.reg = GCLK_CTRLA_SWRST ;

  while ( (GCLK->CTRLA.reg & GCLK_CTRLA_SWRST) && (GCLK->SYNCBUSY.reg & GCLK_SYNCBUSY_MASK) );	/* Wait for reset to complete */
#endif

#if defined(CLOCKCONFIG_CLOCK_SOURCE) && (CLOCKCONFIG_CLOCK_SOURCE == CLOCKCONFIG_32768HZ_CRYSTAL)

  /* ----------------------------------------------------------------------------------------------
   * Enable XOSC32K clock (External on-board 32.768Hz crystal oscillator)
   */
#if defined(PLL_FRACTIONAL_ENABLE)
  #define DPLLRATIO_LDR		2928u
  #define DPLLRATIO_LDRFRAC	11u
#else
  #define DPLLRATIO_LDR		2929u
  #define DPLLRATIO_LDRFRAC	0u
#endif

#if (SAMD)
  SYSCTRL->XOSC32K.reg = (SYSCTRL_XOSC32K_STARTUP( 0x6u ) | SYSCTRL_XOSC32K_XTALEN | SYSCTRL_XOSC32K_EN32K) ;
  SYSCTRL->XOSC32K.bit.ENABLE = 1 ; /* separate call, as described in chapter 15.6.3 */

  while ( (SYSCTRL->PCLKSR.reg & SYSCTRL_PCLKSR_XOSC32KRDY) == 0 );	/* Wait for oscillator stabilization */
  
  SYSCTRL->DPLLRATIO.reg = ( SYSCTRL_DPLLRATIO_LDR(DPLLRATIO_LDR) | SYSCTRL_DPLLRATIO_LDRFRAC(DPLLRATIO_LDRFRAC) ) ;  /* set PLL multiplier */
  
  SYSCTRL->DPLLCTRLB.reg = SYSCTRL_DPLLCTRLB_REFCLK(0) ;  /* select 32KHz crystal input */
  
  SYSCTRL->DPLLCTRLA.reg = SYSCTRL_DPLLCTRLA_ENABLE ;
  
  while ( (SYSCTRL->DPLLSTATUS.reg & SYSCTRL_DPLLSTATUS_CLKRDY) != SYSCTRL_DPLLSTATUS_CLKRDY );
  
  /* Switch Generic Clock Generator 0 to PLL. Divide by two and the CPU will run at 48MHz */
  GCLK->GENDIV.reg = ( GCLK_GENDIV_ID( GENERIC_CLOCK_GENERATOR_MAIN ) | GCLK_GENDIV_DIV(2) ) ;
  waitForSync();

  GCLK->GENCTRL.reg = ( GCLK_GENCTRL_ID( GENERIC_CLOCK_GENERATOR_MAIN ) | GCLK_GENCTRL_SRC_DPLL96M | GCLK_GENCTRL_IDC | GCLK_GENCTRL_GENEN );
  waitForSync();
  
#elif (SAML21 || SAMC21 || SAMC20)
  OSC32KCTRL->XOSC32K.reg = (OSC32KCTRL_XOSC32K_STARTUP( 0x4u ) | OSC32KCTRL_XOSC32K_XTALEN | OSC32KCTRL_XOSC32K_EN32K | OSC32KCTRL_XOSC32K_EN1K) ;
  OSC32KCTRL->XOSC32K.bit.ENABLE = 1 ;
  
  while ( (OSC32KCTRL->STATUS.reg & OSC32KCTRL_STATUS_XOSC32KRDY) == 0 );	/* Wait for oscillator stabilization */
  
  OSCCTRL->DPLLRATIO.reg = ( OSCCTRL_DPLLRATIO_LDR(DPLLRATIO_LDR) | OSCCTRL_DPLLRATIO_LDRFRAC(DPLLRATIO_LDRFRAC) ) ;  /* set PLL multiplier */
  waitForPLL();
  
  OSCCTRL->DPLLCTRLB.reg = OSCCTRL_DPLLCTRLB_REFCLK(0) ;  /* select 32KHz crystal input */
  
  OSCCTRL->DPLLPRESC.reg = 0;
  waitForPLL();
  
  OSCCTRL->DPLLCTRLA.reg = OSCCTRL_DPLLCTRLA_ENABLE ;
  waitForPLL();
  
  while ( (OSCCTRL->DPLLSTATUS.reg & OSCCTRL_DPLLSTATUS_CLKRDY) != OSCCTRL_DPLLSTATUS_CLKRDY );
  
  /* Switch Generic Clock Generator 0 to PLL. Divide by two and the CPU will run at 48MHz */
  GCLK->GENCTRL[GENERIC_CLOCK_GENERATOR_MAIN].reg = ( GCLK_GENCTRL_DIV(2) | GCLK_GENCTRL_SRC_DPLL96M | GCLK_GENCTRL_IDC | GCLK_GENCTRL_GENEN );
  waitForSync();
#endif

#elif defined(CLOCKCONFIG_CLOCK_SOURCE) && (CLOCKCONFIG_CLOCK_SOURCE == CLOCKCONFIG_HS_CRYSTAL)

  /* ----------------------------------------------------------------------------------------------
   * Enable XOSC clock (External on-board high speed crystal oscillator)
   */
#if ((HS_CRYSTAL_FREQUENCY_HERTZ < 400000UL) || (HS_CRYSTAL_FREQUENCY_HERTZ > 32000000UL))
  #error "board.init.c: HS_CRYSTAL_FREQUENCY_HERTZ must be between 4000000UL and 32000000UL"
#endif

#if defined(PLL_FAST_STARTUP)
  #if (HS_CRYSTAL_FREQUENCY_HERTZ < 1000000UL)
    #error "board.init.c: HS_CRYSTAL_FREQUENCY_HERTZ must be at least 1000000UL when PLL_FAST_STARTUP is defined"
  #else
    #define HS_CRYSTAL_DIVISOR	1000000UL
  #endif
#else
  #define HS_CRYSTAL_DIVISOR	32000UL
#endif

#define HS_CRYSTAL_DIVIDER	(HS_CRYSTAL_FREQUENCY_HERTZ / HS_CRYSTAL_DIVISOR)
#define DPLLRATIO_FLOAT		(96000000.0 / ((float)HS_CRYSTAL_FREQUENCY_HERTZ / HS_CRYSTAL_DIVIDER))

#if defined(PLL_FRACTIONAL_ENABLED)
  #define DPLLRATIO_LDR		(uint16_t)DPLLRATIO_FLOAT
  #define DPLLRATIO_LDRFRAC	(uint8_t)((DPLLRATIO_FLOAT - (uint16_t)DPLLRATIO_FLOAT) * 16.0)
#else
  #define DPLLRATIO_LDR		(uint16_t)DPLLRATIO_FLOAT
  #define DPLLRATIO_LDRFRAC	0
#endif

#if (SAMD)
  SYSCTRL->XOSC.reg = (SYSCTRL_XOSC_STARTUP( 0x8u ) | SYSCTRL_XOSC_GAIN( 0x4u ) | SYSCTRL_XOSC_XTALEN | SYSCTRL_XOSC_ENABLE) ;	// startup time is 8ms
  while ( (SYSCTRL->PCLKSR.reg & SYSCTRL_PCLKSR_XOSCRDY) == 0 );	/* Wait for oscillator stabilization */

  SYSCTRL->XOSC.reg |= SYSCTRL_XOSC_AMPGC ;	// set only after startup time
  
  /* Connect GCLK1 to XOSC and set prescaler */
  GCLK->GENDIV.reg = ( GCLK_GENDIV_ID( GENERIC_CLOCK_GENERATOR_XOSC ) | GCLK_GENDIV_DIV(HS_CRYSTAL_DIVIDER) ) ; // Set divider for generic clock generator 1
  waitForSync();

  GCLK->GENCTRL.reg = ( GCLK_GENCTRL_ID( GENERIC_CLOCK_GENERATOR_XOSC ) | GCLK_GENCTRL_SRC_XOSC | GCLK_GENCTRL_GENEN );
  waitForSync();
  
  /* Put Generic Clock Generator 1 as source for Generic Clock Multiplexer 1 (FDPLL reference) */
  GCLK->CLKCTRL.reg = ( GCLK_CLKCTRL_ID( GENERIC_CLOCK_MULTIPLEXER_FDPLL ) | GCLK_CLKCTRL_GEN_GCLK1 | GCLK_CLKCTRL_CLKEN );
  waitForSync();
  
  /* Configure PLL */
  SYSCTRL->DPLLRATIO.reg = ( SYSCTRL_DPLLRATIO_LDR(DPLLRATIO_LDR) | SYSCTRL_DPLLRATIO_LDRFRAC(DPLLRATIO_LDRFRAC) ) ;  /* set PLL multiplier */
  
  SYSCTRL->DPLLCTRLB.reg = SYSCTRL_DPLLCTRLB_REFCLK(2) ;  /* select GCLK input */
  
  SYSCTRL->DPLLCTRLA.reg = SYSCTRL_DPLLCTRLA_ENABLE ;
  
  while ( (SYSCTRL->DPLLSTATUS.reg & SYSCTRL_DPLLSTATUS_CLKRDY) != SYSCTRL_DPLLSTATUS_CLKRDY );
  
  /* Switch Generic Clock Generator 0 to PLL. Divide by two and the CPU will run at 48MHz */
  GCLK->GENDIV.reg = ( GCLK_GENDIV_ID( GENERIC_CLOCK_GENERATOR_MAIN ) | GCLK_GENDIV_DIV(2) ) ;
  waitForSync();

  GCLK->GENCTRL.reg = ( GCLK_GENCTRL_ID( GENERIC_CLOCK_GENERATOR_MAIN ) | GCLK_GENCTRL_SRC_DPLL96M | GCLK_GENCTRL_IDC | GCLK_GENCTRL_GENEN );
  waitForSync();
  
#elif (SAML21 || SAMC21 || SAMC20)
  OSCCTRL->XOSCCTRL.reg = (OSCCTRL_XOSCCTRL_STARTUP( 0x8u ) | OSCCTRL_XOSCCTRL_GAIN( 0x4u ) | OSCCTRL_XOSCCTRL_XTALEN | OSCCTRL_XOSCCTRL_ENABLE) ;	// startup time is 8ms
  while ( (OSCCTRL->STATUS.reg & OSCCTRL_STATUS_XOSCRDY) == 0 );	/* Wait for oscillator stabilization */

  OSCCTRL->XOSCCTRL.reg |= OSCCTRL_XOSCCTRL_AMPGC ;	// set only after startup time
  
  /* Connect GCLK1 to XOSC and set prescaler */
  GCLK->GENCTRL[GENERIC_CLOCK_GENERATOR_XOSC].reg = ( GCLK_GENCTRL_DIV(HS_CRYSTAL_DIVIDER) | GCLK_GENCTRL_SRC_XOSC | GCLK_GENCTRL_GENEN );
  waitForSync();
  
  /* Put Generic Clock Generator 1 as source for Generic Clock Multiplexer 1 (FDPLL reference) */
  GCLK->PCHCTRL[GENERIC_CLOCK_MULTIPLEXER_FDPLL].reg = ( GCLK_PCHCTRL_CHEN | GCLK_PCHCTRL_GEN_GCLK1 );
  while ( (GCLK->PCHCTRL[GENERIC_CLOCK_MULTIPLEXER_FDPLL].reg & GCLK_PCHCTRL_CHEN) != GCLK_PCHCTRL_CHEN );	// wait for sync
  
  /* Configure PLL */
  OSCCTRL->DPLLRATIO.reg = ( OSCCTRL_DPLLRATIO_LDR(DPLLRATIO_LDR) | OSCCTRL_DPLLRATIO_LDRFRAC(DPLLRATIO_LDRFRAC) ) ;  /* set PLL multiplier */
  waitForPLL();
  
  OSCCTRL->DPLLCTRLB.reg = OSCCTRL_DPLLCTRLB_REFCLK(2) ;  /* select GCLK input */
  
  OSCCTRL->DPLLPRESC.reg = 0;
  waitForPLL();
  
  OSCCTRL->DPLLCTRLA.reg = OSCCTRL_DPLLCTRLA_ENABLE ;
  waitForPLL();
  
  while ( (OSCCTRL->DPLLSTATUS.reg & OSCCTRL_DPLLSTATUS_CLKRDY) != OSCCTRL_DPLLSTATUS_CLKRDY );
  
  /* Switch Generic Clock Generator 0 to PLL. Divide by two and the CPU will run at 48MHz */
  GCLK->GENCTRL[GENERIC_CLOCK_GENERATOR_MAIN].reg = ( GCLK_GENCTRL_DIV(2) | GCLK_GENCTRL_SRC_DPLL96M | GCLK_GENCTRL_IDC | GCLK_GENCTRL_GENEN );
  waitForSync();
#endif

#elif defined(CLOCKCONFIG_CLOCK_SOURCE) && ((CLOCKCONFIG_CLOCK_SOURCE == CLOCKCONFIG_INTERNAL) || (CLOCKCONFIG_CLOCK_SOURCE == CLOCKCONFIG_INTERNAL_USB))

  /* ----------------------------------------------------------------------------------------------
   * Enable DFLL48M clock (D21/L21) or RC oscillator (C21)
   */

#if (SAMD)

  /* Remove the OnDemand mode, Bug http://avr32.icgroup.norway.atmel.com/bugzilla/show_bug.cgi?id=9905 */
  SYSCTRL->DFLLCTRL.bit.ONDEMAND = 0;

  waitForDFLL();
  
  /* Load NVM Coarse calibration value */
  uint32_t calib = (*((uint32_t *) FUSES_DFLL48M_COARSE_CAL_ADDR) & FUSES_DFLL48M_COARSE_CAL_Msk) >> FUSES_DFLL48M_COARSE_CAL_Pos;
  SYSCTRL->DFLLVAL.reg = SYSCTRL_DFLLVAL_COARSE(calib) | SYSCTRL_DFLLVAL_FINE(512);

  /* Write full configuration to DFLL control register */
  #if defined(CLOCKCONFIG_CLOCK_SOURCE) && (CLOCKCONFIG_CLOCK_SOURCE == CLOCKCONFIG_INTERNAL_USB)
    SYSCTRL->DFLLMUL.reg = SYSCTRL_DFLLMUL_CSTEP( 31 ) | // Coarse step is 31, half of the max value
                           SYSCTRL_DFLLMUL_FSTEP( 0xA ) | // value from datasheet USB Characteristics
                           SYSCTRL_DFLLMUL_MUL( 0xBB80 ) ; // 1KHz USB SOF signal (48MHz Fcpu / 1KHz SOF)
    #if  SAMD20                     
    SYSCTRL->DFLLCTRL.reg =  SYSCTRL_DFLLCTRL_MODE | /* Closed loop mode */
                             SYSCTRL_DFLLCTRL_CCDIS ;
							 #else
								     SYSCTRL->DFLLCTRL.reg =  SYSCTRL_DFLLCTRL_USBCRM | /* USB correction */
                             SYSCTRL_DFLLCTRL_MODE | /* Closed loop mode */
                             SYSCTRL_DFLLCTRL_CCDIS ;
								 #endif
    waitForDFLL();
  #endif

  /* Enable the DFLL */
  SYSCTRL->DFLLCTRL.reg |= SYSCTRL_DFLLCTRL_ENABLE;

  waitForDFLL();
  
  /* Switch Generic Clock Generator 0 to DFLL48M. CPU will run at 48MHz */
  GCLK->GENDIV.reg = GCLK_GENDIV_ID( GENERIC_CLOCK_GENERATOR_MAIN ); // Generic Clock Generator 0

  waitForSync();

  GCLK->GENCTRL.reg = ( GCLK_GENCTRL_ID( GENERIC_CLOCK_GENERATOR_MAIN ) | GCLK_GENCTRL_SRC_DFLL48M | GCLK_GENCTRL_IDC | GCLK_GENCTRL_GENEN );
  waitForSync();
  
#elif (SAML21)
  /* Defines missing from CMSIS */
  #ifndef FUSES_DFLL48M_COARSE_CAL_ADDR
    #define FUSES_DFLL48M_COARSE_CAL_ADDR (NVMCTRL_OTP5)
  #endif
  #ifndef FUSES_DFLL48M_COARSE_CAL_Pos
    #define FUSES_DFLL48M_COARSE_CAL_Pos 26
  #endif
  #ifndef FUSES_DFLL48M_COARSE_CAL_Msk
    #define FUSES_DFLL48M_COARSE_CAL_Msk (0x3Ful << FUSES_DFLL48M_COARSE_CAL_Pos)
  #endif
  
  OSCCTRL->DFLLCTRL.bit.ONDEMAND = 0 ;
  waitForDFLL();
  
  /* Load NVM Coarse calibration value */
  uint32_t calib = (*((uint32_t *) FUSES_DFLL48M_COARSE_CAL_ADDR) & FUSES_DFLL48M_COARSE_CAL_Msk) >> FUSES_DFLL48M_COARSE_CAL_Pos;
  OSCCTRL->DFLLVAL.reg = OSCCTRL_DFLLVAL_COARSE(calib) | OSCCTRL_DFLLVAL_FINE(512);
  
  /* Write full configuration to DFLL control register */
  #if defined(CLOCKCONFIG_CLOCK_SOURCE) && (CLOCKCONFIG_CLOCK_SOURCE == CLOCKCONFIG_INTERNAL_USB)
    OSCCTRL->DFLLMUL.reg = OSCCTRL_DFLLMUL_CSTEP( 31 ) | // Coarse step is 31, half of the max value
                           OSCCTRL_DFLLMUL_FSTEP( 0xA ) | // value from datasheet USB Characteristics
                           OSCCTRL_DFLLMUL_MUL( 0xBB80 ) ; // 1KHz USB SOF signal (48MHz Fcpu / 1KHz SOF)
                         
    OSCCTRL->DFLLCTRL.reg =  OSCCTRL_DFLLCTRL_USBCRM | /* USB correction */
                             OSCCTRL_DFLLCTRL_MODE | /* Closed loop mode */
                             OSCCTRL_DFLLCTRL_CCDIS ;
    waitForDFLL();
  #endif
  
  /* Enable the DFLL */
  OSCCTRL->DFLLCTRL.reg |= OSCCTRL_DFLLCTRL_ENABLE ;
  waitForDFLL();
  
  /* Switch Generic Clock Generator 0 to DFLL48M. CPU will run at 48MHz */
  GCLK->GENCTRL[GENERIC_CLOCK_GENERATOR_MAIN].reg = ( GCLK_GENCTRL_DIV(1) | GCLK_GENCTRL_SRC_DFLL48M | GCLK_GENCTRL_IDC | GCLK_GENCTRL_GENEN );
  waitForSync();
  
#elif (SAMC21 || SAMC20)
  #if defined(CLOCKCONFIG_CLOCK_SOURCE) && (CLOCKCONFIG_CLOCK_SOURCE == CLOCKCONFIG_INTERNAL_USB)
    #error "startup.c: CLOCKCONFIG_INTERNAL_USB setting invalid for C21 chips as they lack USB."
  #endif
  
  /* Change OSC48M divider to /1. CPU will run at 48MHz */
  OSCCTRL->OSC48MDIV.reg = OSCCTRL_OSC48MDIV_DIV(0);
  while ( OSCCTRL->OSC48MSYNCBUSY.reg & OSCCTRL_OSC48MSYNCBUSY_OSC48MDIV );
#endif
#else
  #error "board_init.c: CLOCKCONFIG_CLOCK_SOURCE must be defined in the board_definitions file"
#endif

#if (SAMD21)
  /* Modify PRESCaler value of OSC8M to have 8MHz */
  SYSCTRL->OSC8M.bit.PRESC = SYSCTRL_OSC8M_PRESC_0_Val ;  // recent versions of CMSIS from Atmel changed the prescaler defines
  //SYSCTRL->OSC8M.bit.ONDEMAND = 0 ;

  /* Put OSC8M as source for Generic Clock Generator 3 */
  GCLK->GENDIV.reg = GCLK_GENDIV_ID( GENERIC_CLOCK_GENERATOR_OSC_HS ) ; // Generic Clock Generator 3
  waitForSync();

  GCLK->GENCTRL.reg = ( GCLK_GENCTRL_ID( GENERIC_CLOCK_GENERATOR_OSC_HS ) | GCLK_GENCTRL_SRC_OSC8M | GCLK_GENCTRL_GENEN );
  waitForSync();
  
#elif (SAML21)
  /* Note that after reset, the L21 starts with the OSC16M set to 4MHz, NOT the DFLL@48MHz as stated in some documentation. */
  /* Modify FSEL value of OSC16M to have 8MHz */
  OSCCTRL->OSC16MCTRL.bit.FSEL = OSCCTRL_OSC16MCTRL_FSEL_8_Val;

  /* Put OSC16M as source for Generic Clock Generator 3 */
  GCLK->GENCTRL[GENERIC_CLOCK_GENERATOR_OSC_HS].reg = ( GCLK_GENCTRL_DIV(1) | GCLK_GENCTRL_SRC_OSC16M | GCLK_GENCTRL_GENEN );
  waitForSync();
#endif

  SystemCoreClock=VARIANT_MCK;
  /* Set CPU and APB dividers before switching the CPU/APB clocks to the new clock source */
#if (SAMD)
  PM->CPUSEL.reg  = PM_CPUSEL_CPUDIV_DIV1 ;
  PM->APBASEL.reg = PM_APBASEL_APBADIV_DIV1_Val ;
  PM->APBBSEL.reg = PM_APBBSEL_APBBDIV_DIV1_Val ;
  PM->APBCSEL.reg = PM_APBCSEL_APBCDIV_DIV1_Val ;
#elif (SAML21 || SAMC21 || SAMC20)
  MCLK->CPUDIV.reg  = MCLK_CPUDIV_CPUDIV_DIV1 ;
#endif
}









/*

#if defined(NVMCTRL_CAL)
	volatile   FUSEMAP_CAL_type               *               MyNVMCTRL_CAL               =0;
#endif
#if defined(NVMCTRL_LOCKBIT)
	volatile   FUSEMAP_LOCKBIT_type               *               MyNVMCTRL_LOCKBIT               =0;
   
#endif
#if defined(NVMCTRL_OTP1)
	volatile   FUSEMAP_OTP1_type               *               MyNVMCTRL_OTP1               =0;
   
#endif
#if defined(NVMCTRL_OTP2)
	volatile   FUSEMAP_OTP2_type               *               MyNVMCTRL_OTP2               =0;
   
#endif
#if defined(NVMCTRL_OTP3)
	volatile   FUSEMAP_OTP3_type               *               MyNVMCTRL_OTP3               =0;
   
#endif
#if defined(NVMCTRL_OTP4)
	volatile   FUSEMAP_OTP4_type               *               MyNVMCTRL_OTP4               =0;
   
#endif
#if defined(NVMCTRL_OTP5)
	volatile   FUSEMAP_OTP5_type               *               MyNVMCTRL_OTP5               =0;
   
#endif
#if defined(NVMCTRL_USER)
	volatile   FUSEMAP_USER_type               *               MyNVMCTRL_USER               =0;
   
#endif
*/

#if defined(ADC)
	volatile   Adc               *               MyADC               =0;    
 #endif
   

#if defined(RAMECC)
	volatile   Ramecc               *               MyRAMECC               =0;    
 #endif
   

#if defined(DIVAS)
	volatile   Divas               *               MyDIVAS               =0;    
 #endif
   

#if defined(ATW)
	volatile   Atw               *               MyATW               =0;    
 #endif
   

#if defined(LINCTRL)
	volatile   Linctrl               *               MyLINCTRL               =0;    
 #endif
   

#if defined(DSUSTANDBY)
	volatile   Dsustandby               *               MyDSUSTANDBY               =0;    
 #endif
   

#if defined(TRNG)
	volatile   Trng               *               MyTRNG               =0;    
 #endif
   

#if defined(SDHC1)
	volatile   Sdhc               *               MySDHC1               =0;    
 #endif
   
#if defined(GCLK)
	volatile   Gclk               *               MyGCLK               =0;    
 #endif
   

        
#if defined(SDHC0)
	volatile   Sdhc               *               MySDHC0               =0;    
 #endif
   

#if defined(EIC)
	volatile   Eic               *               MyEIC               =0;    
 #endif
   

#if defined(CAN1)
	volatile   Can               *               MyCAN1               =0;    
 #endif
   

#if defined(CAN0)
	volatile   Can               *               MyCAN0               =0;    
 #endif
   

#if defined(TC0)
	volatile   Tc               *               MyTC0               =0;    
 #endif
   

#if defined(AC)
	volatile   Ac               *               MyAC               =0;    
 #endif
   

#if defined(TC2)
	volatile   Tc               *               MyTC2               =0;    
 #endif
   

#if defined(TC1)
	volatile   Tc               *               MyTC1               =0;    
 #endif
   

#if defined(TC4)
	volatile   Tc               *               MyTC4               =0;    
 #endif
   

#if defined(PORT)
	volatile   Port               *               MyPORT               =0;    
 #endif
   

#if defined(TC3)
	volatile   Tc               *               MyTC3               =0;    
 #endif
   

#if defined(PAC2)
	volatile   Pac               *               MyPAC2               =0;    
 #endif
   

#if defined(HMATRIXLP)
	volatile   Hmatrixb               *               MyHMATRIXLP               =0;    
 #endif
   

#if defined(TC6)
	volatile   Tc               *               MyTC6               =0;    
 #endif
   

#if defined(WDT)
	volatile   Wdt               *               MyWDT               =0;    
 #endif
   

#if defined(DSU)
	volatile   Dsu               *               MyDSU               =0;    
 #endif
   

#if defined(TCC4)
	volatile   Tcc               *               MyTCC4               =0;    
 #endif
   

#if defined(TC5)
	volatile   Tc               *               MyTC5               =0;    
 #endif
   

#if defined(EVSYS)
	volatile   Evsys               *               MyEVSYS               =0;    
 #endif
   

#if defined(TC7)
	volatile   Tc               *               MyTC7               =0;    
 #endif
   

#if defined(SERCOM0)
	volatile   Sercom               *               MySERCOM0               =0;    
 #endif
   

#if defined(GMAC)
	volatile   Gmac               *               MyGMAC               =0;    
 #endif
   

#if defined(SYSCTRL)
	volatile   Sysctrl               *               MySYSCTRL               =0;    
 #endif
   

#if defined(TSENS)
	volatile   Tsens               *               MyTSENS               =0;    
 #endif
   

#if defined(ADC0)
	volatile   Adc               *               MyADC0               =0;    
 #endif
   

#if defined(ADC1)
	volatile   Adc               *               MyADC1               =0;    
 #endif
   

#if defined(AES)
	volatile   Aes               *               MyAES               =0;    
 #endif
   

#if defined(SERCOM7)
	volatile   Sercom               *               MySERCOM7               =0;    
 #endif
   

#if defined(MCLK)
	volatile   Mclk               *               MyMCLK               =0;    
 #endif
   

#if defined(PCC)
	volatile   Pcc               *               MyPCC               =0;    
 #endif
   

#if defined(SERCOM5)
	volatile   Sercom               *               MySERCOM5               =0;    
 #endif
   

#if defined(NVMCTRL)
	volatile   Nvmctrl               *               MyNVMCTRL               =0;    
 #endif
   

#if defined(SERCOM6)
	volatile   Sercom               *               MySERCOM6               =0;    
 #endif
   

#if defined(OZCTRL)
	volatile   Ozctrl               *               MyOZCTRL               =0;    
 #endif
   

#if defined(SERCOM3)
	volatile   Sercom               *               MySERCOM3               =0;    
 #endif
   

#if defined(OSCCTRL)
	volatile   Oscctrl               *               MyOSCCTRL               =0;    
 #endif
   
#if defined(OSC32KCTRL)
	volatile   Osc32kctrl               *               MyOSC32KCTRL               =0;    
 #endif

        
#if defined(SERCOM4)
	volatile   Sercom               *               MySERCOM4               =0;    
 #endif
   

#if defined(SERCOM1)
	volatile   Sercom               *               MySERCOM1               =0;    
 #endif
   

#if defined(PDEC)
	volatile   Pdec               *               MyPDEC               =0;    
 #endif
   

#if defined(SERCOM2)
	volatile   Sercom               *               MySERCOM2               =0;    
 #endif
   

#if defined(QSPI)
	volatile   Qspi               *               MyQSPI               =0;    
 #endif
   
/*
#if defined(PTC)
	volatile   Ptc               *               MyPTC               =0;    
 #endif
   */

#if defined(SDADC)
	volatile   Sdadc               *               MySDADC               =0;    
 #endif
   

#if defined(HMATRIXHS)
	volatile   Hmatrixb               *               MyHMATRIXHS               =0;    
 #endif
   

#if defined(RTC)
	volatile   Rtc               *               MyRTC               =0;    
 #endif
   

#if defined(PICOP)
	volatile   Picop               *               MyPICOP               =0;    
 #endif
   

#if defined(PUKCC)
	volatile   Pukcc               *               MyPUKCC               =0;    
 #endif
   

#if defined(DMAC)
	volatile   Dmac               *               MyDMAC               =0;    
 #endif
   

#if defined(AC1)
	volatile   Ac               *               MyAC1               =0;    
 #endif
   

#if defined(CMCC)
	volatile   Cmcc               *               MyCMCC               =0;    
 #endif
   

#if defined(FREQM)
	volatile   Freqm               *               MyFREQM               =0;    
 #endif
   

#if defined(RSTC)
	volatile   Rstc               *               MyRSTC               =0;    
 #endif
   

#if defined(TCC3)
	volatile   Tcc               *               MyTCC3               =0;    
 #endif
   

#if defined(TCC2)
	volatile   Tcc               *               MyTCC2               =0;    
 #endif
   

#if defined(TCC1)
	volatile   Tcc               *               MyTCC1               =0;    
 #endif
   

#if defined(PAC1)
	volatile   Pac               *               MyPAC1               =0;    
 #endif
   

#if defined(TCC0)
	volatile   Tcc               *               MyTCC0               =0;    
 #endif
   

#if defined(PAC0)
	volatile   Pac               *               MyPAC0               =0;    
 #endif
   

#if defined(SLCD)
	volatile   Slcd               *               MySLCD               =0;    
 #endif
   

#if defined(OPAMP)
	volatile   Opamp               *               MyOPAMP               =0;    
 #endif
   

#if defined(USB)
	volatile   Usb               *               MyUSB               =0;    
 #endif
   

#if defined(DAC)
	volatile   Dac               *               MyDAC               =0;    
 #endif
   

#if defined(HMATRIX)
	volatile   Hmatrixb               *               MyHMATRIX               =0;    
 #endif
   

#if defined(CCL)
	volatile   Ccl               *               MyCCL               =0;    
 #endif
   

#if defined(SUPC)
	volatile   Supc               *               MySUPC               =0;    
 #endif
   

#if defined(ICM)
	volatile   Icm               *               MyICM               =0;    
 #endif
   

#if defined(PAC)
	volatile   Pac               *               MyPAC               =0;    
 #endif
   

#if defined(RFCTRL)
	volatile   Rfctrl               *               MyRFCTRL               =0;    
 #endif
   

#if defined(MTB)
	volatile   Mtb               *               MyMTB               =0;    
 #endif
   



#if defined(PM)
	volatile   Pm               *               MyPM               =0;    
 #endif
   

#if defined(TAL)
	volatile   Tal               *               MyTAL               =0;    
 #endif
   

void init_debug() 
{	
#if defined(ADC)
	MyADC=ADC;
#endif

#if defined(RAMECC)
	MyRAMECC=RAMECC;
#endif

#if defined(DIVAS)
	MyDIVAS=DIVAS;
#endif

#if defined(ATW)
	MyATW=ATW;
#endif

#if defined(LINCTRL)
	MyLINCTRL=LINCTRL;
#endif

#if defined(DSUSTANDBY)
	MyDSUSTANDBY=DSUSTANDBY;
#endif

#if defined(TRNG)
	MyTRNG=TRNG;
#endif

#if defined(SDHC1)
	MySDHC1=SDHC1;
#endif

#if defined(SDHC0)
	MySDHC0=SDHC0;
#endif

#if defined(EIC)
	MyEIC=EIC;
#endif

#if defined(CAN1)
	MyCAN1=CAN1;
#endif

#if defined(CAN0)
	MyCAN0=CAN0;
#endif

#if defined(TC0)
	MyTC0=TC0;
#endif

#if defined(AC)
	MyAC=AC;
#endif

#if defined(TC2)
	MyTC2=TC2;
#endif

#if defined(TC1)
	MyTC1=TC1;
#endif

#if defined(TC4)
	MyTC4=TC4;
#endif

#if defined(PORT)
	MyPORT=PORT;
#endif

#if defined(TC3)
	MyTC3=TC3;
#endif

#if defined(PAC2)
	MyPAC2=PAC2;
#endif

#if defined(HMATRIXLP)
	MyHMATRIXLP=HMATRIXLP;
#endif

#if defined(TC6)
	MyTC6=TC6;
#endif

#if defined(WDT)
	MyWDT=WDT;
#endif

#if defined(DSU)
	MyDSU=DSU;
#endif

#if defined(TCC4)
	MyTCC4=TCC4;
#endif

#if defined(TC5)
	MyTC5=TC5;
#endif

#if defined(EVSYS)
	MyEVSYS=EVSYS;
#endif

#if defined(TC7)
	MyTC7=TC7;
#endif

#if defined(SERCOM0)
	MySERCOM0=SERCOM0;
#endif

#if defined(GMAC)
	MyGMAC=GMAC;
#endif

#if defined(SYSCTRL)
	MySYSCTRL=SYSCTRL;
#endif

#if defined(TSENS)
	MyTSENS=TSENS;
#endif

#if defined(ADC0)
	MyADC0=ADC0;
#endif

#if defined(ADC1)
	MyADC1=ADC1;
#endif

#if defined(AES)
	MyAES=AES;
#endif

#if defined(SERCOM7)
	MySERCOM7=SERCOM7;
#endif

#if defined(MCLK)
	MyMCLK=MCLK;
#endif

#if defined(PCC)
	MyPCC=PCC;
#endif

#if defined(SERCOM5)
	MySERCOM5=SERCOM5;
#endif

#if defined(NVMCTRL)
	MyNVMCTRL=NVMCTRL;
#endif

#if defined(SERCOM6)
	MySERCOM6=SERCOM6;
#endif

#if defined(OZCTRL)
	MyOZCTRL=OZCTRL;
#endif

#if defined(SERCOM3)
	MySERCOM3=SERCOM3;
#endif

#if defined(OSCCTRL)
	MyOSCCTRL=OSCCTRL;
#endif

#if defined(OSC32KCTRL)
	MyOSC32KCTRL=OSC32KCTRL;
#endif
        
#if defined(SERCOM4)
	MySERCOM4=SERCOM4;
#endif

#if defined(SERCOM1)
	MySERCOM1=SERCOM1;
#endif

#if defined(PDEC)
	MyPDEC=PDEC;
#endif

#if defined(SERCOM2)
	MySERCOM2=SERCOM2;
#endif

#if defined(QSPI)
	MyQSPI=QSPI;
#endif
/*
#if defined(PTC)
	MyPTC=PTC;
#endif
*/
#if defined(SDADC)
	MySDADC=SDADC;
#endif

#if defined(HMATRIXHS)
	MyHMATRIXHS=HMATRIXHS;
#endif

#if defined(RTC)
	MyRTC=RTC;
#endif

#if defined(PICOP)
	MyPICOP=PICOP;
#endif

#if defined(PUKCC)
	MyPUKCC=PUKCC;
#endif

#if defined(DMAC)
	MyDMAC=DMAC;
#endif

#if defined(AC1)
	MyAC1=AC1;
#endif

#if defined(CMCC)
	MyCMCC=CMCC;
#endif

#if defined(FREQM)
	MyFREQM=FREQM;
#endif

#if defined(RSTC)
	MyRSTC=RSTC;
#endif

#if defined(TCC3)
	MyTCC3=TCC3;
#endif

#if defined(TCC2)
	MyTCC2=TCC2;
#endif

#if defined(TCC1)
	MyTCC1=TCC1;
#endif

#if defined(PAC1)
	MyPAC1=PAC1;
#endif

#if defined(TCC0)
	MyTCC0=TCC0;
#endif

#if defined(PAC0)
	MyPAC0=PAC0;
#endif

#if defined(SLCD)
	MySLCD=SLCD;
#endif

#if defined(OPAMP)
	MyOPAMP=OPAMP;
#endif

#if defined(USB)
	MyUSB=USB;
#endif

#if defined(DAC)
	MyDAC=DAC;
#endif

#if defined(HMATRIX)
	MyHMATRIX=HMATRIX;
#endif

#if defined(CCL)
	MyCCL=CCL;
#endif

#if defined(SUPC)
	MySUPC=SUPC;
#endif

#if defined(ICM)
	MyICM=ICM;
#endif

#if defined(PAC)
	MyPAC=PAC;
#endif

#if defined(RFCTRL)
	MyRFCTRL=RFCTRL;
#endif

#if defined(MTB)
	MyMTB=MTB;
#endif

#if defined(GCLK)
	MyGCLK=GCLK;
#endif

#if defined(PM)
	MyPM=PM;
#endif

#if defined(TAL)
	MyTAL=TAL;
#endif

volatile int tmp= (int)   0                ;

#if defined(ADC)
	tmp= (int)         MyADC;
#endif

#if defined(RAMECC)
	tmp= (int)         MyRAMECC;
#endif

#if defined(DIVAS)
	tmp= (int)         MyDIVAS;
#endif

#if defined(ATW)
	tmp= (int)         MyATW;
#endif

#if defined(LINCTRL)
	tmp= (int)         MyLINCTRL;
#endif

#if defined(DSUSTANDBY)
	tmp= (int)         MyDSUSTANDBY;
#endif

#if defined(TRNG)
	tmp= (int)         MyTRNG;
#endif

#if defined(SDHC1)
	tmp= (int)         MySDHC1;
#endif

#if defined(SDHC0)
	tmp= (int)         MySDHC0;
#endif
#if defined(GCLK)
	tmp= (int)         MyGCLK;
#endif

#if defined(EIC)
	tmp= (int)         MyEIC;
#endif

#if defined(CAN1)
	tmp= (int)         MyCAN1;
#endif

#if defined(CAN0)
	tmp= (int)         MyCAN0;
#endif

#if defined(TC0)
	tmp= (int)         MyTC0;
#endif

#if defined(AC)
	tmp= (int)         MyAC;
#endif

#if defined(TC2)
	tmp= (int)         MyTC2;
#endif

#if defined(TC1)
	tmp= (int)         MyTC1;
#endif

#if defined(TC4)
	tmp= (int)         MyTC4;
#endif

#if defined(PORT)
	tmp= (int)         MyPORT;
#endif

#if defined(TC3)
	tmp= (int)         MyTC3;
#endif

#if defined(PAC2)
	tmp= (int)         MyPAC2;
#endif

#if defined(HMATRIXLP)
	tmp= (int)         MyHMATRIXLP;
#endif

#if defined(TC6)
	tmp= (int)         MyTC6;
#endif

#if defined(WDT)
	tmp= (int)         MyWDT;
#endif

#if defined(DSU)
	tmp= (int)         MyDSU;
#endif

#if defined(TCC4)
	tmp= (int)         MyTCC4;
#endif

#if defined(TC5)
	tmp= (int)         MyTC5;
#endif

#if defined(EVSYS)
	tmp= (int)         MyEVSYS;
#endif

#if defined(TC7)
	tmp= (int)         MyTC7;
#endif

#if defined(SERCOM0)
	tmp= (int)         MySERCOM0;
#endif

#if defined(GMAC)
	tmp= (int)         MyGMAC;
#endif

#if defined(SYSCTRL)
	tmp= (int)         MySYSCTRL;
#endif

#if defined(TSENS)
	tmp= (int)         MyTSENS;
#endif

#if defined(ADC0)
	tmp= (int)         MyADC0;
#endif

#if defined(ADC1)
	tmp= (int)         MyADC1;
#endif

#if defined(AES)
	tmp= (int)         MyAES;
#endif

#if defined(SERCOM7)
	tmp= (int)         MySERCOM7;
#endif

#if defined(MCLK)
	tmp= (int)         MyMCLK;
#endif

#if defined(PCC)
	tmp= (int)         MyPCC;
#endif

#if defined(SERCOM5)
	tmp= (int)         MySERCOM5;
#endif

#if defined(NVMCTRL)
	tmp= (int)         MyNVMCTRL;
#endif

#if defined(SERCOM6)
	tmp= (int)         MySERCOM6;
#endif

#if defined(OZCTRL)
	tmp= (int)         MyOZCTRL;
#endif

#if defined(SERCOM3)
	tmp= (int)         MySERCOM3;
#endif

#if defined(OSCCTRL)
	tmp= (int)         MyOSCCTRL;
#endif

#if defined(OSC32KCTRL)
	tmp= (int)         MyOSC32KCTRL;
#endif

#if defined(SERCOM4)
	tmp= (int)         MySERCOM4;
#endif

#if defined(SERCOM1)
	tmp= (int)         MySERCOM1;
#endif

#if defined(PDEC)
	tmp= (int)         MyPDEC;
#endif

#if defined(SERCOM2)
	tmp= (int)         MySERCOM2;
#endif

#if defined(QSPI)
	tmp= (int)         MyQSPI;
#endif
/*
#if defined(PTC)
	tmp= (int)         MyPTC;
#endif
*/
#if defined(SDADC)
	tmp= (int)         MySDADC;
#endif

#if defined(HMATRIXHS)
	tmp= (int)         MyHMATRIXHS;
#endif

#if defined(RTC)
	tmp= (int)         MyRTC;
#endif

#if defined(PICOP)
	tmp= (int)         MyPICOP;
#endif

#if defined(PUKCC)
	tmp= (int)         MyPUKCC;
#endif

#if defined(DMAC)
	tmp= (int)         MyDMAC;
#endif

#if defined(AC1)
	tmp= (int)         MyAC1;
#endif

#if defined(CMCC)
	tmp= (int)         MyCMCC;
#endif

#if defined(FREQM)
	tmp= (int)         MyFREQM;
#endif

#if defined(RSTC)
	tmp= (int)         MyRSTC;
#endif

#if defined(TCC3)
	tmp= (int)         MyTCC3;
#endif

#if defined(TCC2)
	tmp= (int)         MyTCC2;
#endif

#if defined(TCC1)
	tmp= (int)         MyTCC1;
#endif

#if defined(PAC1)
	tmp= (int)         MyPAC1;
#endif

#if defined(TCC0)
	tmp= (int)         MyTCC0;
#endif

#if defined(PAC0)
	tmp= (int)         MyPAC0;
#endif

#if defined(SLCD)
	tmp= (int)         MySLCD;
#endif

#if defined(OPAMP)
	tmp= (int)         MyOPAMP;
#endif

#if defined(USB)
	tmp= (int)         MyUSB;
#endif

#if defined(DAC)
	tmp= (int)         MyDAC;
#endif

#if defined(HMATRIX)
	tmp= (int)         MyHMATRIX;
#endif

#if defined(CCL)
	tmp= (int)         MyCCL;
#endif

#if defined(SUPC)
	tmp= (int)         MySUPC;
#endif

#if defined(ICM)
	tmp= (int)         MyICM;
#endif

#if defined(PAC)
	tmp= (int)         MyPAC;
#endif

#if defined(RFCTRL)
	tmp= (int)         MyRFCTRL;
#endif

#if defined(MTB)
	tmp= (int)         MyMTB;
#endif

#if defined(GCLK)
	tmp= (int)         MyGCLK;
#endif

#if defined(PM)
	tmp= (int)         MyPM;
#endif

#if defined(TAL)
	tmp= (int)         MyTAL;
#endif
/*
MySCB = SCB;
	MySysTick = SysTick;
	MyNVIC = NVIC;
		tmp =(int)MyNVIC+(int)MySysTick+(int)MySCB;
tmp=tmp*(int)&version;
	#if defined(NVMCTRL_CAL)
	MyNVMCTRL_CAL        =(FUSEMAP_CAL_type*)    NVMCTRL_CAL       ;       
        
	tmp =(int)MyNVMCTRL_CAL;
	#endif
	#if defined(NVMCTRL_LOCKBIT)
	MyNVMCTRL_LOCKBIT    =(FUSEMAP_LOCKBIT_type*)    NVMCTRL_LOCKBIT   ;        
	tmp =(int)MyNVMCTRL_LOCKBIT;
		#endif
	#if defined(NVMCTRL_OTP1)
	MyNVMCTRL_OTP1       =(FUSEMAP_OTP1_type *)    NVMCTRL_OTP1      ;         
	tmp =(int)MyNVMCTRL_OTP1;
		#endif
	#if defined(NVMCTRL_OTP2)
	MyNVMCTRL_OTP2       =(FUSEMAP_OTP2_type *)    NVMCTRL_OTP2      ;         
	tmp =(int)MyNVMCTRL_OTP2;
		#endif
	#if defined(NVMCTRL_OTP3)
	MyNVMCTRL_OTP3       =(FUSEMAP_OTP3_type *)    NVMCTRL_OTP3      ;        
	tmp =(int)MyNVMCTRL_OTP3;
		#endif
	#if defined(NVMCTRL_OTP4)
	MyNVMCTRL_OTP4       =(FUSEMAP_OTP4_type*)    NVMCTRL_OTP4      ;        
	tmp =(int)MyNVMCTRL_OTP4;
		#endif
	#if defined(NVMCTRL_OTP5)
	MyNVMCTRL_OTP5       =(FUSEMAP_OTP5_type *)    NVMCTRL_OTP5      ;         
	tmp =(int)MyNVMCTRL_OTP5;
		#endif
	#if defined(NVMCTRL_USER)
	MyNVMCTRL_USER       =(FUSEMAP_USER_type *)    NVMCTRL_USER      ;        
	tmp =(int)MyNVMCTRL_USER;
	#endif*/
	//	debug_stack(0);	
}

