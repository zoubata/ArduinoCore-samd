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

#if defined(BOARD_ID_arduino_zero)
  #include "board_definitions_arduino_zero.h"
#elif defined(BOARD_ID_genuino_zero)
  #include "board_definitions_genuino_zero.h"
#elif defined(BOARD_ID_arduino_mkr1000)
  #include "board_definitions_arduino_mkr1000.h"
#elif defined(BOARD_ID_genuino_mkr1000)
  #include "board_definitions_genuino_mkr1000.h"
#elif defined(BOARD_ID_arduino_mkrzero)
  #include "board_definitions_arduino_mkrzero.h"
#elif defined(BOARD_ID_arduino_mkrfox1200)
  #include "board_definitions_arduino_mkrfox1200.h"
#elif defined(BOARD_ID_Pilo)
  #include "board_definitions_arduino_pilo.h"
#elif defined(BOARD_ID_engi)
  #include "board_definitions_arduino_engi.h"
 

#else
  #error You must define a BOARD_ID and add the corresponding definitions in board_definitions.h
#endif


// Common definitions
// ------------------

// These are undefined in CMSIS for L21 and C21
#if (SAML21)
#ifndef GCLK_CLKCTRL_ID_SERCOM0_CORE_Val
  #define GCLK_CLKCTRL_ID_SERCOM0_CORE_Val	18
  #define GCLK_CLKCTRL_ID_SERCOM1_CORE_Val	19
  #define GCLK_CLKCTRL_ID_SERCOM2_CORE_Val	20
  #define GCLK_CLKCTRL_ID_SERCOM3_CORE_Val	21
  #define GCLK_CLKCTRL_ID_SERCOM4_CORE_Val	22
  #define GCLK_CLKCTRL_ID_SERCOM5_CORE_Val	24
#endif
#elif (SAMC21)
#ifndef GCLK_CLKCTRL_ID_SERCOM0_CORE_Val
  #define GCLK_CLKCTRL_ID_SERCOM0_CORE_Val	19
  #define GCLK_CLKCTRL_ID_SERCOM1_CORE_Val	20
  #define GCLK_CLKCTRL_ID_SERCOM2_CORE_Val	21
  #define GCLK_CLKCTRL_ID_SERCOM3_CORE_Val	22
  #define GCLK_CLKCTRL_ID_SERCOM4_CORE_Val	23
  #define GCLK_CLKCTRL_ID_SERCOM5_CORE_Val	25
#endif
#endif

#define LED_POLARITY_LOW_ON             0
#define LED_POLARITY_HIGH_ON            1
#define PIN_POLARITY_ACTIVE_LOW         0
#define PIN_POLARITY_ACTIVE_HIGH        1
#define PIN_POLARITY_USBCDC_LOW         0
#define PIN_POLARITY_USBCDC_HIGH        1

#define INPUT                   (0x0)
#define OUTPUT                  (0x1)
#define INPUT_PULLUP            (0x2)
#define INPUT_PULLDOWN          (0x3)
#define OUTPUT_HIGH             (0x4)
#define OUTPUT_LOW              (0x5)

#define PINMUX_UNUSED          0xFFFFFFFF

/*
 * If BOOT_DOUBLE_TAP_ENABLED is defined the bootloader is started by
 * quickly tapping two times on the reset button.
 * BOOT_DOUBLE_TAP_ADDRESS must point to a free SRAM cell that must not
 * be touched from the loaded application. By default, the SRAM
 * location is the last 4 bytes.
 */
#if (SAMD21 || SAMD11)
  #define BOOT_DOUBLE_TAP_ADDRESS           (HMCRAMC0_ADDR + HMCRAMC0_SIZE - 4)
#elif (SAML21 || SAMC21 || SAMD20)
  #define BOOT_DOUBLE_TAP_ADDRESS           (HSRAM_ADDR + HSRAM_SIZE - 4)
#else
  #error "board_definitions.h: Missing dependency or unsupported chip. Please install CMSIS-Atmel from MattairTech (see Prerequisites for Building in README.md)."
#endif

#define BOOT_DOUBLE_TAP_DATA              (*((volatile uint32_t *) BOOT_DOUBLE_TAP_ADDRESS))

#if (BOOT_USART_SERCOM_INSTANCE == 0)
  #define BOOT_USART_MODULE                   SERCOM0
  #define BOOT_USART_PER_CLOCK_INDEX          GCLK_CLKCTRL_ID_SERCOM0_CORE_Val
  #if (SAMD21 || SAMD11)
    #define BOOT_USART_BUS_CLOCK_INDEX        PM_APBCMASK_SERCOM0
  #elif (SAML21 || SAMC21)
    #define BOOT_USART_BUS_CLOCK_INDEX        MCLK_APBCMASK_SERCOM0
  #endif
#elif (BOOT_USART_SERCOM_INSTANCE == 1)
  #define BOOT_USART_MODULE                   SERCOM1
  #define BOOT_USART_PER_CLOCK_INDEX          GCLK_CLKCTRL_ID_SERCOM1_CORE_Val
  #if (SAMD21 || SAMD11)
    #define BOOT_USART_BUS_CLOCK_INDEX        PM_APBCMASK_SERCOM1
  #elif (SAML21 || SAMC21)
    #define BOOT_USART_BUS_CLOCK_INDEX        MCLK_APBCMASK_SERCOM1
  #endif
#elif (BOOT_USART_SERCOM_INSTANCE == 2)
  #define BOOT_USART_MODULE                   SERCOM2
  #define BOOT_USART_PER_CLOCK_INDEX          GCLK_CLKCTRL_ID_SERCOM2_CORE_Val
  #if (SAMD21 || SAMD11)
    #define BOOT_USART_BUS_CLOCK_INDEX        PM_APBCMASK_SERCOM2
  #elif (SAML21 || SAMC21)
    #define BOOT_USART_BUS_CLOCK_INDEX        MCLK_APBCMASK_SERCOM2
  #endif
#elif (BOOT_USART_SERCOM_INSTANCE == 3)
  #define BOOT_USART_MODULE                   SERCOM3
  #define BOOT_USART_PER_CLOCK_INDEX          GCLK_CLKCTRL_ID_SERCOM3_CORE_Val
  #if (SAMD21 || SAMD11)
    #define BOOT_USART_BUS_CLOCK_INDEX        PM_APBCMASK_SERCOM3
  #elif (SAML21 || SAMC21)
    #define BOOT_USART_BUS_CLOCK_INDEX        MCLK_APBCMASK_SERCOM3
  #endif
#elif (BOOT_USART_SERCOM_INSTANCE == 4)
  #define BOOT_USART_MODULE                   SERCOM4
  #define BOOT_USART_PER_CLOCK_INDEX          GCLK_CLKCTRL_ID_SERCOM4_CORE_Val
  #if (SAMD21 || SAMD11)
    #define BOOT_USART_BUS_CLOCK_INDEX        PM_APBCMASK_SERCOM4
  #elif (SAML21 || SAMC21)
    #define BOOT_USART_BUS_CLOCK_INDEX        MCLK_APBCMASK_SERCOM4
  #endif
#elif (BOOT_USART_SERCOM_INSTANCE == 5)
  #define BOOT_USART_MODULE                   SERCOM5
  #define BOOT_USART_PER_CLOCK_INDEX          GCLK_CLKCTRL_ID_SERCOM5_CORE_Val
  #if (SAMD21 || SAMD11)
    #define BOOT_USART_BUS_CLOCK_INDEX        PM_APBCMASK_SERCOM5
  #elif (SAML21 || SAMC21)
    #define BOOT_USART_BUS_CLOCK_INDEX        MCLK_APBCMASK_SERCOM5
  #endif
#endif

#if (SDCARD_SPI_SERCOM_INSTANCE == 0)
  #define SDCARD_SPI_MODULE                   SERCOM0
  #define SDCARD_SPI_PER_CLOCK_INDEX          GCLK_CLKCTRL_ID_SERCOM0_CORE_Val
  #if (SAMD21 || SAMD11)
    #define SDCARD_SPI_BUS_CLOCK_INDEX        PM_APBCMASK_SERCOM0
  #elif (SAML21 || SAMC21)
    #define SDCARD_SPI_BUS_CLOCK_INDEX        MCLK_APBCMASK_SERCOM0
  #endif
#elif (SDCARD_SPI_SERCOM_INSTANCE == 1)
  #define SDCARD_SPI_MODULE                   SERCOM1
  #define SDCARD_SPI_PER_CLOCK_INDEX          GCLK_CLKCTRL_ID_SERCOM1_CORE_Val
  #if (SAMD21 || SAMD11)
    #define SDCARD_SPI_BUS_CLOCK_INDEX        PM_APBCMASK_SERCOM1
  #elif (SAML21 || SAMC21)
    #define SDCARD_SPI_BUS_CLOCK_INDEX        MCLK_APBCMASK_SERCOM1
  #endif
#elif (SDCARD_SPI_SERCOM_INSTANCE == 2)
  #define SDCARD_SPI_MODULE                   SERCOM2
  #define SDCARD_SPI_PER_CLOCK_INDEX          GCLK_CLKCTRL_ID_SERCOM2_CORE_Val
  #if (SAMD21 || SAMD11)
    #define SDCARD_SPI_BUS_CLOCK_INDEX        PM_APBCMASK_SERCOM2
  #elif (SAML21 || SAMC21)
    #define SDCARD_SPI_BUS_CLOCK_INDEX        MCLK_APBCMASK_SERCOM2
  #endif
#elif (SDCARD_SPI_SERCOM_INSTANCE == 3)
  #define SDCARD_SPI_MODULE                   SERCOM3
  #define SDCARD_SPI_PER_CLOCK_INDEX          GCLK_CLKCTRL_ID_SERCOM3_CORE_Val
  #if (SAMD21 || SAMD11)
    #define SDCARD_SPI_BUS_CLOCK_INDEX        PM_APBCMASK_SERCOM3
  #elif (SAML21 || SAMC21)
    #define SDCARD_SPI_BUS_CLOCK_INDEX        MCLK_APBCMASK_SERCOM3
  #endif
#elif (SDCARD_SPI_SERCOM_INSTANCE == 4)
  #define SDCARD_SPI_MODULE                   SERCOM4
  #define SDCARD_SPI_PER_CLOCK_INDEX          GCLK_CLKCTRL_ID_SERCOM4_CORE_Val
  #if (SAMD21 || SAMD11)
    #define SDCARD_SPI_BUS_CLOCK_INDEX        PM_APBCMASK_SERCOM4
  #elif (SAML21 || SAMC21)
    #define SDCARD_SPI_BUS_CLOCK_INDEX        MCLK_APBCMASK_SERCOM4
  #endif
#elif (SDCARD_SPI_SERCOM_INSTANCE == 5)
  #define SDCARD_SPI_MODULE                   SERCOM5
  #define SDCARD_SPI_PER_CLOCK_INDEX          GCLK_CLKCTRL_ID_SERCOM5_CORE_Val
  #if (SAMD21 || SAMD11)
    #define SDCARD_SPI_BUS_CLOCK_INDEX        PM_APBCMASK_SERCOM5
  #elif (SAML21 || SAMC21)
    #define SDCARD_SPI_BUS_CLOCK_INDEX        MCLK_APBCMASK_SERCOM5
  #endif
#endif

#ifndef SAM_BA_INTERFACE
  #define SAM_BA_INTERFACE    SAM_BA_BOTH_INTERFACES
#endif

#ifndef ARDUINO_EXTENDED_CAPABILITIES
  #define ARDUINO_EXTENDED_CAPABILITIES		1
#endif

#define CLOCKCONFIG_32768HZ_CRYSTAL	0
#define CLOCKCONFIG_HS_CRYSTAL		1
#define CLOCKCONFIG_INTERNAL		2
#define CLOCKCONFIG_INTERNAL_USB	3

