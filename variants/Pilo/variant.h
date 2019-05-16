/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.

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

#ifndef _VARIANT_ARDUINO_PILO_
#define _VARIANT_ARDUINO_PILO_


#include "variant_pins.h"

// The definitions here needs a SAMD core >=1.6.10
#define ARDUINO_SAMD_VARIANT_COMPLIANCE 10610

/*----------------------------------------------------------------------------
 *        Definitions
 *----------------------------------------------------------------------------*/

/** Frequency of the board main oscillator */
#define VARIANT_MAINOSC		(32768ul)

/** Master clock frequency */
#define VARIANT_MCK			  (48000000ul)
/* If CLOCKCONFIG_HS_CRYSTAL is defined, then HS_CRYSTAL_FREQUENCY_HERTZ
 * must also be defined with the external crystal frequency in Hertz.
 */
#define HS_CRYSTAL_FREQUENCY_HERTZ	16000000UL

/* If the PLL is used (CLOCKCONFIG_32768HZ_CRYSTAL, or CLOCKCONFIG_HS_CRYSTAL
 * defined), then PLL_FRACTIONAL_ENABLED can be defined, which will result in
 * a more accurate 48MHz output frequency at the expense of increased jitter.
 */
//#define PLL_FRACTIONAL_ENABLED

/* If both PLL_FAST_STARTUP and CLOCKCONFIG_HS_CRYSTAL are defined, the crystal
 * will be divided down to 1MHz - 2MHz, rather than 32KHz - 64KHz, before being
 * multiplied by the PLL. This will result in a faster lock time for the PLL,
 * however, it will also result in a less accurate PLL output frequency if the
 * crystal is not divisible (without remainder) by 1MHz. In this case, define
 * PLL_FRACTIONAL_ENABLED as well.
 */
//#define PLL_FAST_STARTUP

/* The fine calibration value for DFLL open-loop mode is defined here.
 * The coarse calibration value is loaded from NVM OTP (factory calibration values).
 */
#define NVM_SW_CALIB_DFLL48M_FINE_VAL     (512)

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "WVariant.h"
#include "sam.h"

#ifdef __cplusplus
#include "SERCOM.h"
#include "Uart.h"

#endif // __cplusplus

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/

// Number of pins defined in PinDescription array
#define NUM_PIN_DESCRIPTION_ENTRIES     (52u)

#define PINS_COUNT           NUM_PIN_DESCRIPTION_ENTRIES
#define NUM_DIGITAL_PINS     PINS_COUNT
#define NUM_ANALOG_INPUTS    (10u)
#define NUM_ANALOG_OUTPUTS   (1u)
#define analogInputToDigitalPin(p)  (p)

#define digitalPinToPort(P)        ( &(PORT->Group[g_APinDescription[P].ulPort]) )
#define digitalPinToBitMask(P)     ( 1 << g_APinDescription[P].ulPin )
//#define analogInPinToBit(P)        ( )
#define portOutputRegister(port)   ( &(port->OUT.reg) )
#define portInputRegister(port)    ( &(port->IN.reg) )
#define portModeRegister(port)     ( &(port->DIR.reg) )
#define digitalPinHasPWM(P)        ( g_APinDescription[P].ulPWMChannel != NOT_ON_PWM || g_APinDescription[P].ulTCChannel != NOT_ON_TIMER )

/*
 * digitalPinToTimer(..) is AVR-specific and is not defined for SAMD
 * architecture. If you need to check if a pin supports PWM you must
 * use digitalPinHasPWM(..).
 *
 * https://github.com/arduino/Arduino/issues/1833
 */
// #define digitalPinToTimer(P)

/* LEDs
 * None of these defines are currently used by the core.
 * The RX and TX LEDs are not present.
 * You may optionally add them to any free pins.
 */
  //V1 : #define PIN_LED_13           (28u)
// V1 : #define LED_BUILTIN          PIN_LED_13

#define LED_TOP          LED_GREEN
#define LED_BOTTOM          LED_RED
#define LED_GREEN          14
#define LED_RED          15


#define LED_BUILTIN          LED_TOP
  

/**/
/*
 * Analog pins
 */
#define PIN_A0               (42ul)
#define PIN_A1               (43ul)
#define PIN_A2               (10ul)
#define PIN_A3               (11ul)
#define PIN_A4               ( 6ul)
#define PIN_A5               ( 7ul)
#define PIN_A6               ( 8ul)
#define PIN_A7               ( 9ul)
#define PIN_A8               (16ul)
#define PIN_A9               (17ul)
#define PIN_A10              (44ul)
#define PIN_A11              (45ul)
#define PIN_A12              (46ul)
#define PIN_A13              (47ul)
#define PIN_A14              (48ul)
#define PIN_A15              (49ul)
#define PIN_DAC0            PIN_A12

static const uint8_t A0  = PIN_A0;
static const uint8_t A1  = PIN_A1;
static const uint8_t A2  = PIN_A2;
static const uint8_t A3  = PIN_A3;
static const uint8_t A4  = PIN_A4;
static const uint8_t A5  = PIN_A5;
static const uint8_t DAC0 = PIN_DAC0;

#define VARIANT_AR_DEFAULT	AR_DEFAULT

// arduino pin number based on Pcom pin number of connector
//==================================
#define P_COM0_PIN6     0
#define P_COM0_PIN5     1
#define P_COM0_PIN8     2
#define P_COM0_PIN7     3
#define P_COM0_PIN10     4
#define P_COM0_PIN9     5

#define P_COM0_BIS_PIN6     6
#define P_COM0_BIS_PIN5     7
#define P_COM0_BIS_PIN8     8
#define P_COM0_BIS_PIN7     9
#define P_COM0_BIS_PIN10     10
#define P_COM0_BIS_PIN9     11

#define P_COM1_PIN6     12
#define P_COM1_PIN5     13
#define P_COM1_PIN8     14
#define P_COM1_PIN7     15
#define P_COM1_PIN10     16
#define P_COM1_PIN9     17

#define P_COM2_PIN6     18
#define P_COM2_PIN5     19
#define P_COM2_PIN8     20
#define P_COM2_PIN7     21
#define P_COM2_PIN10     23
#define P_COM2_PIN9     22

#define P_COM3_PIN6     24
#define P_COM3_PIN5     25
#define P_COM3_PIN8     26
#define P_COM3_PIN7     27
#define P_COM3_PIN10     28
#define P_COM3_PIN9     29

#define P_COM4_PIN6     30
#define P_COM4_PIN5     31
#define P_COM4_PIN8     32
#define P_COM4_PIN7     33
#define P_COM4_PIN10     34
#define P_COM4_PIN9     35

#define P_COM5_PIN6     36
#define P_COM5_PIN5     37
#define P_COM5_PIN8     38
#define P_COM5_PIN7     39
#define P_COM5_PIN10     40
#define P_COM5_PIN9     41

















#define CAN_PIN2     42
#define CAN_PIN3     43



#define PANA1_PIN4     42
#define PANA1_PIN6     43
#define PANA1_PIN8     10
#define PANA1_PIN10     11
#define PANA1_PIN12     6
#define PANA1_PIN14     7
#define PANA1_PIN16     8
#define PANA1_PIN18     9



#define PANA2_PIN4     16
#define PANA2_PIN6     17
#define PANA2_PIN8     44
#define PANA2_PIN10     45
#define PANA2_PIN12     46
#define PANA2_PIN14     47
#define PANA2_PIN16     48
#define PANA2_PIN18     49







#define FTDI_PIN8     14
#define FTDI_PIN7     15


#define DEBUG_SWD_PIN8     14
#define DEBUG_SWD_PIN7     15


#define LIN_PIN8     14
#define LIN_PIN7     15
#define LIN_PIN9     17

// arduino pin number based on Pcom pin name
//==================================
#define P_COM0_P0     0
#define P_COM0_P1     1
#define P_COM0_P2     2
#define P_COM0_P3     3
#define P_COM0_P4     4
#define P_COM0_P5     5

#define P_COM0_BIS_P0     6
#define P_COM0_BIS_P1     7
#define P_COM0_BIS_P2     8
#define P_COM0_BIS_P3     9
#define P_COM0_BIS_P4     10
#define P_COM0_BIS_P5     11

#define P_COM1_P0     12
#define P_COM1_P1     13
#define P_COM1_P2     14
#define P_COM1_P3     15
#define P_COM1_P4     16
#define P_COM1_P5     17

#define P_COM2_P0     18
#define P_COM2_P1     19
#define P_COM2_P2     20
#define P_COM2_P3     21
#define P_COM2_P4     23
#define P_COM2_P5     22

#define P_COM3_P0     24
#define P_COM3_P1     25
#define P_COM3_P2     26
#define P_COM3_P3     27
#define P_COM3_P4     28
#define P_COM3_P5     29

#define P_COM4_P0     30
#define P_COM4_P1     31
#define P_COM4_P2     32
#define P_COM4_P3     33
#define P_COM4_P4     34
#define P_COM4_P5     35

#define P_COM5_P0     36
#define P_COM5_P1     37
#define P_COM5_P2     38
#define P_COM5_P3     39
#define P_COM5_P4     40
#define P_COM5_P5     41

// arduino INT number based on Pcom pin name
//==================================
#define P_COM0_P0_INT     EXTERNAL_INT_NMI
#define P_COM0_P1_INT     EXTERNAL_INT_9
#define P_COM0_P2_INT     EXTERNAL_INT_10
#define P_COM0_P3_INT     EXTERNAL_INT_11
#define P_COM0_P4_INT     EXTERNAL_INT_5
#define P_COM0_P5_INT     EXTERNAL_INT_2

#define P_COM0_BIS_P0_INT     EXTERNAL_INT_4
#define P_COM0_BIS_P1_INT     EXTERNAL_INT_5
#define P_COM0_BIS_P2_INT     EXTERNAL_INT_6
#define P_COM0_BIS_P3_INT     EXTERNAL_INT_7
#define P_COM0_BIS_P4_INT     EXTERNAL_INT_9
#define P_COM0_BIS_P5_INT     EXTERNAL_INT_8

#define P_COM1_P0_INT     EXTERNAL_INT_0
#define P_COM1_P1_INT     EXTERNAL_INT_1
#define P_COM1_P2_INT     EXTERNAL_INT_10
#define P_COM1_P3_INT     EXTERNAL_INT_11
#define P_COM1_P4_INT     EXTERNAL_INT_0
#define P_COM1_P5_INT     EXTERNAL_INT_1

#define P_COM2_P0_INT     EXTERNAL_INT_12
#define P_COM2_P1_INT     EXTERNAL_INT_13
#define P_COM2_P2_INT     EXTERNAL_INT_14
#define P_COM2_P3_INT     EXTERNAL_INT_15
#define P_COM2_P4_INT     EXTERNAL_INT_1
#define P_COM2_P5_INT     EXTERNAL_INT_0

#define P_COM3_P0_INT     EXTERNAL_INT_6
#define P_COM3_P1_INT     EXTERNAL_INT_7
#define P_COM3_P2_INT     EXTERNAL_INT_12
#define P_COM3_P3_INT     EXTERNAL_INT_13
#define P_COM3_P4_INT     EXTERNAL_INT_4
#define P_COM3_P5_INT     EXTERNAL_INT_3

#define P_COM4_P0_INT     EXTERNAL_INT_12
#define P_COM4_P1_INT     EXTERNAL_INT_13
#define P_COM4_P2_INT     EXTERNAL_INT_14
#define P_COM4_P3_INT     EXTERNAL_INT_15
#define P_COM4_P4_INT     EXTERNAL_INT_0
#define P_COM4_P5_INT     EXTERNAL_INT_1

#define P_COM5_P0_INT     EXTERNAL_INT_14
#define P_COM5_P1_INT     EXTERNAL_INT_15
#define P_COM5_P2_INT     EXTERNAL_INT_6
#define P_COM5_P3_INT     EXTERNAL_INT_7
#define P_COM5_P4_INT     EXTERNAL_INT_15
#define P_COM5_P5_INT     EXTERNAL_INT_8




// arduino INT number based on Pcom pin name
//==================================
#define P_COM0_P0_TMR     TCC1_CH2
#define P_COM0_P1_TMR     TCC1_CH3
#define P_COM0_P2_TMR     TCC0_CH2
#define P_COM0_P3_TMR     TCC0_CH3
#define P_COM0_P4_TMR     TC3_CH1
#define P_COM0_P5_TMR     TC4_CH0

#define P_COM0_BIS_P0_TMR     TCC0_CH0
#define P_COM0_BIS_P1_TMR     TCC0_CH1
#define P_COM0_BIS_P2_TMR     TCC1_CH0
#define P_COM0_BIS_P3_TMR     TCC1_CH1
#define P_COM0_BIS_P4_TMR     TC0_CH1
#define P_COM0_BIS_P5_TMR     TC0_CH0

#define P_COM1_P0_TMR     TCC2_CH0
#define P_COM1_P1_TMR     TCC2_CH1
#define P_COM1_P2_TMR     TCC1_CH0
#define P_COM1_P3_TMR     TCC1_CH1
#define P_COM1_P4_TMR     TC3_CH0
#define P_COM1_P5_TMR     TC3_CH1

#define P_COM2_P0_TMR     TCC0_CH6
#define P_COM2_P1_TMR     TCC0_CH7
#define P_COM2_P2_TMR     TCC0_CH4
#define P_COM2_P3_TMR     TCC0_CH5
#define P_COM2_P4_TMR     TCC2_CH1
#define P_COM2_P5_TMR     TCC2_CH0

#define P_COM3_P0_TMR     TC0_CH0
#define P_COM3_P1_TMR     TC0_CH1
#define P_COM3_P2_TMR     TC1_CH0
#define P_COM3_P3_TMR     TC1_CH1
#define P_COM3_P4_TMR     TC3_CH0
#define P_COM3_P5_TMR     TC4_CH1

#define P_COM4_P0_TMR     TC0_CH0
#define P_COM4_P1_TMR     TC0_CH1
#define P_COM4_P2_TMR     TC1_CH0
#define P_COM4_P3_TMR     TC1_CH1
#define P_COM4_P4_TMR     TC2_CH0
#define P_COM4_P5_TMR     TC2_CH1

#define P_COM5_P0_TMR     TCC0_CH0
#define P_COM5_P1_TMR     TCC0_CH1
#define P_COM5_P2_TMR     TC3_CH0
#define P_COM5_P3_TMR     TC3_CH1



// arduino ATTRIBUTE based on Pcom pin name (not yet manage : PIN_ATTR_ADC , PIN_ATTR_DAC , PIN_ATTR_REF , PIN_ATTR_AC)
//==================================
#define P_COM0_P0_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_DIGITAL)
#define P_COM0_P1_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_DIGITAL)
#define P_COM0_P2_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_AC_GCLK | PIN_ATTR_DIGITAL)
#define P_COM0_P3_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_AC_GCLK | PIN_ATTR_DIGITAL)
#define P_COM0_P4_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_AC_GCLK | PIN_ATTR_DIGITAL)
#define P_COM0_P5_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_DIGITAL)

#define P_COM0_BIS_P0_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_DIGITAL)
#define P_COM0_BIS_P1_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_DIGITAL)
#define P_COM0_BIS_P2_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_DIGITAL)
#define P_COM0_BIS_P3_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_DIGITAL)
#define P_COM0_BIS_P4_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_DIGITAL)
#define P_COM0_BIS_P5_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_DIGITAL)

#define P_COM1_P0_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_DIGITAL)
#define P_COM1_P1_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_DIGITAL)
#define P_COM1_P2_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_AC_GCLK | PIN_ATTR_DIGITAL)
#define P_COM1_P3_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_DIGITAL)
#define P_COM1_P4_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_DIGITAL)
#define P_COM1_P5_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_DIGITAL)

#define P_COM2_P0_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_DIGITAL)
#define P_COM2_P1_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_DIGITAL)
#define P_COM2_P2_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_AC_GCLK | PIN_ATTR_DIGITAL)
#define P_COM2_P3_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_AC_GCLK | PIN_ATTR_DIGITAL)
#define P_COM2_P4_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_AC_GCLK | PIN_ATTR_DIGITAL)
#define P_COM2_P5_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_AC_GCLK | PIN_ATTR_DIGITAL)

#define P_COM3_P0_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_AC_GCLK | PIN_ATTR_DIGITAL)
#define P_COM3_P1_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_AC_GCLK | PIN_ATTR_DIGITAL)
#define P_COM3_P2_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_DIGITAL)
#define P_COM3_P3_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_DIGITAL)
#define P_COM3_P4_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_AC_GCLK | PIN_ATTR_DIGITAL)
#define P_COM3_P5_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_DIGITAL)

#define P_COM4_P0_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_AC_GCLK | PIN_ATTR_DIGITAL)
#define P_COM4_P1_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_AC_GCLK | PIN_ATTR_DIGITAL)
#define P_COM4_P2_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_AC_GCLK | PIN_ATTR_DIGITAL)
#define P_COM4_P3_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_AC_GCLK | PIN_ATTR_DIGITAL)
#define P_COM4_P4_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_AC_GCLK | PIN_ATTR_DIGITAL)
#define P_COM4_P5_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_AC_GCLK | PIN_ATTR_DIGITAL)

#define P_COM5_P0_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_AC_GCLK | PIN_ATTR_DIGITAL)
#define P_COM5_P1_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_AC_GCLK | PIN_ATTR_DIGITAL)
#define P_COM5_P2_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_AC_GCLK | PIN_ATTR_DIGITAL)
#define P_COM5_P3_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_AC_GCLK | PIN_ATTR_DIGITAL)
#define P_COM5_P4_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_AC_GCLK | PIN_ATTR_DIGITAL)
#define P_COM5_P5_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_AC_GCLK | PIN_ATTR_DIGITAL)

















#define CAN_5V_PIN_ATTRIB     (PIN_ATTR_SERCOM | PIN_ATTR_DIGITAL)
#define CAN_3V_PIN_ATTRIB     (PIN_ATTR_SERCOM | PIN_ATTR_DIGITAL)



#define PANA1_G_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_DIGITAL)
#define PANA1_P0_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_DIGITAL)
#define PANA1_P2_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_AC_GCLK | PIN_ATTR_DIGITAL)
#define PANA1_P4_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_TIMER | PIN_ATTR_AC_GCLK | PIN_ATTR_DIGITAL)




#define PANA2_G_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_DIGITAL)
#define PANA2_P0_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_DIGITAL)
#define PANA2_P2_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_DIGITAL)
#define PANA2_P4_PIN_ATTRIB     (PIN_ATTR_EXTINT | PIN_ATTR_SERCOM | PIN_ATTR_DIGITAL)



// arduino ATTRIBUTE based on Pcom pin name (not yet manage : PIN_ATTR_ADC , PIN_ATTR_DAC , PIN_ATTR_REF , PIN_ATTR_AC)
//==================================
#define P_COM0_P0_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)
#define P_COM0_P1_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)
#define P_COM0_P2_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)
#define P_COM0_P3_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)
#define P_COM0_P4_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)
#define P_COM0_P5_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)

#define P_COM0_BIS_P0_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)
#define P_COM0_BIS_P1_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)
#define P_COM0_BIS_P2_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)
#define P_COM0_BIS_P3_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)
#define P_COM0_BIS_P4_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)
#define P_COM0_BIS_P5_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)

#define P_COM1_P0_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)
#define P_COM1_P1_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)
#define P_COM1_P2_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)
#define P_COM1_P3_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)
#define P_COM1_P4_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)
#define P_COM1_P5_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)

#define P_COM2_P0_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)
#define P_COM2_P1_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)
#define P_COM2_P2_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)
#define P_COM2_P3_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)
#define P_COM2_P4_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)
#define P_COM2_P5_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)

#define P_COM3_P0_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)
#define P_COM3_P1_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)
#define P_COM3_P2_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)
#define P_COM3_P3_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)
#define P_COM3_P4_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)
#define P_COM3_P5_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)

#define P_COM4_P0_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)
#define P_COM4_P1_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)
#define P_COM4_P2_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)
#define P_COM4_P3_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)
#define P_COM4_P4_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)
#define P_COM4_P5_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)

#define P_COM5_P0_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)
#define P_COM5_P1_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)
#define P_COM5_P2_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)
#define P_COM5_P3_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)
#define P_COM5_P4_PER_ATTRIB     (PER_ATTR_DRIVE_STRONG)
#define P_COM5_P5_PER_ATTRIB     (PER_ATTR_DRIVE_STRONG)

















#define CAN_5V_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_DRIVE_STRONG)
#define CAN_3V_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_DRIVE_STRONG)



#define PANA1_G_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)
#define PANA1_P0_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)
#define PANA1_P2_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)
#define PANA1_P4_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_TIMER_STD | PER_ATTR_DRIVE_STRONG)



#define PANA2_G_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_DRIVE_STRONG)
#define PANA2_P0_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_DRIVE_STRONG)
#define PANA2_P2_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_DRIVE_STRONG)
#define PANA2_P4_PER_ATTRIB     (PER_ATTR_SERCOM_STD | PER_ATTR_DRIVE_STRONG)



#define ADC_RESOLUTION		12
/* Reference voltage pins (define even if not enabled with PIN_ATTR_REF in the PinDescription table) */
#define REFA_PIN    (3ul)
#define REFB_PIN    (4ul)

// The ATN pin may be used in the future as the first SPI chip select.
// On boards that do not have the Arduino physical form factor, it can to set to any free pin.

#define PIN_ATN              (38ul)
static const uint8_t ATN = PIN_ATN;




/*
 * SPI Interfaces
 */

//SPI definition				
//------------------------------				
#define SPI_INTERFACES_COUNT 6

#define       PIN_SPI0_MISO          (0u)
#define       PIN_SPI0_SCK          (1u)
#define       PIN_SPI0_SS          (2u)
#define       PIN_SPI0_MOSI          (3u)
#define       PERIPH_SPI0          sercom0


#define       PIN_SPI0_BIS_MISO          (6u)
#define       PIN_SPI0_BIS_SCK          (7u)
#define       PIN_SPI0_BIS_SS          (8u)
#define       PIN_SPI0_BIS_MOSI          (9u)
#define       PERIPH_SPI0_BIS          sercom0


#define       PIN_SPI1_MISO          (12u)
#define       PIN_SPI1_SCK          (13u)
#define       PIN_SPI1_SS          (14u)
#define       PIN_SPI1_MOSI          (15u)
#define       PERIPH_SPI1          sercom1


#define       PIN_SPI2_MISO          (18u)
#define       PIN_SPI2_SCK          (19u)
#define       PIN_SPI2_SS          (20u)
#define       PIN_SPI2_MOSI          (21u)
#define       PERIPH_SPI2          sercom2


#define       PIN_SPI3_MISO          (24u)
#define       PIN_SPI3_SCK          (25u)
#define       PIN_SPI3_SS          (26u)
#define       PIN_SPI3_MOSI          (27u)
#define       PERIPH_SPI3          sercom3


#define       PIN_SPI4_MISO          (30u)
#define       PIN_SPI4_SCK          (31u)
#define       PIN_SPI4_SS          (32u)
#define       PIN_SPI4_MOSI          (33u)
#define       PERIPH_SPI4          sercom4


#define       PIN_SPI5_MISO          (36u)
#define       PIN_SPI5_SCK          (37u)
#define       PIN_SPI5_SS          (38u)
#define       PIN_SPI5_MOSI          (39u)
#define       PERIPH_SPI5          sercom5
			
				
				
				
				
				
				
				
				
				
				

						
						
#define	PAD_SPI0_TX	SPI_PAD_3_SCK_1				
#define	PAD_SPI0_RX	SERCOM_RX_PAD_0				
#define	PAD_SPI1_TX	SPI_PAD_3_SCK_1				
#define	PAD_SPI1_RX	SERCOM_RX_PAD_0				
#define	PAD_SPI2_TX	SPI_PAD_3_SCK_1				
#define	PAD_SPI2_RX	SERCOM_RX_PAD_0				
#define	PAD_SPI3_TX	SPI_PAD_3_SCK_1				
#define	PAD_SPI3_RX	SERCOM_RX_PAD_0				
#define	PAD_SPI4_TX	SPI_PAD_3_SCK_1				
#define	PAD_SPI4_RX	SERCOM_RX_PAD_0				
#define	PAD_SPI5_TX	SPI_PAD_3_SCK_1				
#define	PAD_SPI5_RX	SERCOM_RX_PAD_0				
#define	PAD_SPI0_BIS_TX	SPI_PAD_3_SCK_1				
#define	PAD_SPI0_BIS_RX	SERCOM_RX_PAD_0				
static	const	uint8_t	SS0	=	PIN_SPI0_SS	;
static	const	uint8_t	MOSI0	=	PIN_SPI0_MOSI	;
static	const	uint8_t	MISO0	=	PIN_SPI0_MISO	;
static	const	uint8_t	SCK0	=	PIN_SPI0_SCK	;
static	const	uint8_t	SS1	=	PIN_SPI1_SS	;
static	const	uint8_t	MOSI1	=	PIN_SPI1_MOSI	;
static	const	uint8_t	MISO1	=	PIN_SPI1_MISO	;
static	const	uint8_t	SCK1	=	PIN_SPI1_SCK	;
static	const	uint8_t	SS2	=	PIN_SPI2_SS	;
static	const	uint8_t	MOSI2	=	PIN_SPI2_MOSI	;
static	const	uint8_t	MISO2	=	PIN_SPI2_MISO	;
static	const	uint8_t	SCK2	=	PIN_SPI2_SCK	;
static	const	uint8_t	SS3	=	PIN_SPI3_SS	;
static	const	uint8_t	MOSI3	=	PIN_SPI3_MOSI	;
static	const	uint8_t	MISO3	=	PIN_SPI3_MISO	;
static	const	uint8_t	SCK3	=	PIN_SPI3_SCK	;
static	const	uint8_t	SS4	=	PIN_SPI4_SS	;
static	const	uint8_t	MOSI4	=	PIN_SPI4_MOSI	;
static	const	uint8_t	MISO4	=	PIN_SPI4_MISO	;
static	const	uint8_t	SCK4	=	PIN_SPI4_SCK	;
static	const	uint8_t	SS5	=	PIN_SPI5_SS	;
static	const	uint8_t	MOSI5	=	PIN_SPI5_MOSI	;
static	const	uint8_t	MISO5	=	PIN_SPI5_MISO	;
static	const	uint8_t	SCK5	=	PIN_SPI5_SCK	;
static	const	uint8_t	SS0_BIS	=	PIN_SPI0_BIS_SS	;
static	const	uint8_t	MOSI0_BIS	=	PIN_SPI0_BIS_MOSI	;
static	const	uint8_t	MISO0_BIS	=	PIN_SPI0_BIS_MISO	;
static	const	uint8_t	SCK0_BIS	=	PIN_SPI0_BIS_SCK	;
 //alias to 0						
#define	PIN_SPI_MISO	PIN_SPI0_MISO				
#define	PIN_SPI_MOSI	PIN_SPI0_MOSI				
#define	PIN_SPI_SCK	PIN_SPI0_SCK				
#define	PIN_SPI_SS	PIN_SPI0_SS				
#define	PERIPH_SPI	PERIPH_SPI0				
#define	PAD_SPI_TX	PAD_SPI0_TX				
#define	PAD_SPI_RX	PAD_SPI0_RX				
						
static	const	uint8_t	SS	=	PIN_SPI_SS	;
static	const	uint8_t	MOSI	=	PIN_SPI_MOSI	;
static	const	uint8_t	MISO	=	PIN_SPI_MISO	;
static	const	uint8_t	SCK	=	PIN_SPI_SCK	;
						
						


/*
 * Wire Interfaces
 */
 //WIRE definition						
//------------------------------						
#define	WIRE_INTERFACES_COUNT		6			
#define       PIN_WIRE0_SDA          (0u)						
#define       PIN_WIRE0_SCL          (1u)	
					
#define PERIPH_WIRE          PERIPH_WIRE0
#define WIRE_IT_HANDLER      WIRE0_IT_HANDLER
#define       WIRE0_IT_HANDLER          SERCOM0_Handler_softwire						
#define       PERIPH_WIRE0          sercom0						
						
						
						
#define       PIN_WIRE0_BIS_SDA          (6u)						
#define       PIN_WIRE0_BIS_SCL          (7u)						
#define       WIRE0_BIS_IT_HANDLER          SERCOM0Bis_Handler_softwire
#define       PERIPH_WIRE0_BIS          sercom0						
						
						
						
#define       PIN_WIRE1_SDA          (12u)						
#define       PIN_WIRE1_SCL          (13u)						
#define       WIRE1_IT_HANDLER          SERCOM1_Handler_softwire
#define       PERIPH_WIRE1          sercom1						
						
						
						
#define       PIN_WIRE2_SDA          (18u)						
#define       PIN_WIRE2_SCL          (19u)						
#define       WIRE2_IT_HANDLER          SERCOM2_Handler_softwire						
#define       PERIPH_WIRE2          sercom2						
						
						
						
#define       PIN_WIRE3_SDA          (24u)						
#define       PIN_WIRE3_SCL          (25u)						
#define       WIRE3_IT_HANDLER          SERCOM3_Handler_softwire
#define       PERIPH_WIRE3          sercom3						
						
						
						
#define       PIN_WIRE4_SDA          (30u)						
#define       PIN_WIRE4_SCL          (31u)						
#define       WIRE4_IT_HANDLER          SERCOM4_Handler_softwire
#define       PERIPH_WIRE4          sercom4						
						
						
						
#define       PIN_WIRE5_SDA          (36u)						
#define       PIN_WIRE5_SCL          (37u)						
#define       WIRE5_IT_HANDLER          SERCOM5_Handler_softwire
#define       PERIPH_WIRE5          sercom5						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
#define	PIN_WIRE_SDA	PIN_WIRE0_SDA				
#define	PIN_WIRE_SCL	PIN_WIRE0_SCL				
#define	PERIPH_WIRE	PERIPH_WIRE0				
#define	WIRE_IT_HANDLER	WIRE0_IT_HANDLER				
static	const	uint8_t	SDA0	=	PIN_WIRE0_SDA;	
static	const	uint8_t	SCL0	=	PIN_WIRE0_SCL;	
static	const	uint8_t	SDA0_BIS	=	PIN_WIRE0_BIS_SDA;	
static	const	uint8_t	SCL0_BIS	=	PIN_WIRE0_BIS_SCL;	
static	const	uint8_t	SDA1	=	PIN_WIRE1_SDA;	
static	const	uint8_t	SCL1	=	PIN_WIRE1_SCL;	
static	const	uint8_t	SDA2	=	PIN_WIRE2_SDA;	
static	const	uint8_t	SCL2	=	PIN_WIRE2_SCL;	
static	const	uint8_t	SDA3	=	PIN_WIRE3_SDA;	
static	const	uint8_t	SCL3	=	PIN_WIRE3_SCL;	
static	const	uint8_t	SDA4	=	PIN_WIRE4_SDA;	
static	const	uint8_t	SCL4	=	PIN_WIRE4_SCL;	
static	const	uint8_t	SDA5	=	PIN_WIRE5_SDA;	
static	const	uint8_t	SCL5	=	PIN_WIRE5_SCL;	
static	const	uint8_t	SDA	=	PIN_WIRE_SDA;	
static	const	uint8_t	SCL	=	PIN_WIRE_SCL;	


  
  
 /*
#define WIRE_INTERFACES_COUNT 1

#define PIN_WIRE_SDA         (20u)
#define PIN_WIRE_SCL         (21u)
#define PERIPH_WIRE          sercom3
#define WIRE_IT_HANDLER      SERCOM3_Handler

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;
*/
/*
 * USB
 */
#if (SAMD21 || SAML21)
#define PIN_USB_HOST_ENABLE (27ul)
#define PIN_USB_DM          (28ul)
#define PIN_USB_DP          (29ul)
#define PIN_USB_HOST_ENABLE_VALUE	HIGH
#endif

/*
 * I2S Interfaces
 */
#define I2S_INTERFACES_COUNT 1

#define I2S_DEVICE          0
#define I2S_CLOCK_GENERATOR 3
#define PIN_I2S_SD          (7u)
#define PIN_I2S_SCK         (10u)
#define PIN_I2S_FS          (11u)

#ifdef __cplusplus
}
#endif //// extern "C" {


//   SERCOM						
						
//   SERCOM						
//	Serial1					
#define	PAD_SERIAL0_TX	(UART_TX_PAD_0)				
#define	PAD_SERIAL0_RX	(SERCOM_RX_PAD_1)				
#define	PIN_SERIAL0_TX	(0ul)				
#define	PIN_SERIAL0_RX	(1ul)				
#define	SERCOM_INSTANCE_SERIAL0	&sercom0				
						
//	Serial1					
#define	PAD_SERIAL0_BIS_TX	(UART_TX_PAD_0)				
#define	PAD_SERIAL0_BIS_RX	(SERCOM_RX_PAD_1)				
#define	PIN_SERIAL0_BIS_TX	(6ul)				
#define	PIN_SERIAL0_BIS_RX	(7ul)				
#define	SERCOM_INSTANCE_SERIAL0_BIS	&sercom0				
						
//	Serial1					
#define	PAD_SERIAL1_TX	(UART_TX_PAD_0)				
#define	PAD_SERIAL1_RX	(SERCOM_RX_PAD_1)				
#define	PIN_SERIAL1_TX	(12ul)				
#define	PIN_SERIAL1_RX	(13ul)				
#define	SERCOM_INSTANCE_SERIAL1	&sercom1				
						
//	Serial1					
#define	PAD_SERIAL2_TX	(UART_TX_PAD_0)				
#define	PAD_SERIAL2_RX	(SERCOM_RX_PAD_1)				
#define	PIN_SERIAL2_TX	(18ul)				
#define	PIN_SERIAL2_RX	(19ul)				
#define	SERCOM_INSTANCE_SERIAL2	&sercom2				
						
//	Serial1					
#define	PAD_SERIAL3_TX	(UART_TX_PAD_0)				
#define	PAD_SERIAL3_RX	(SERCOM_RX_PAD_1)				
#define	PIN_SERIAL3_TX	(24ul)				
#define	PIN_SERIAL3_RX	(25ul)				
#define	SERCOM_INSTANCE_SERIAL3	&sercom3				
						
//	Serial1					
#define	PAD_SERIAL4_TX	(UART_TX_PAD_0)				
#define	PAD_SERIAL4_RX	(SERCOM_RX_PAD_1)				
#define	PIN_SERIAL4_TX	(30ul)				
#define	PIN_SERIAL4_RX	(31ul)				
#define	SERCOM_INSTANCE_SERIAL4	&sercom4				
						
//	Serial1					
#define	PAD_SERIAL5_TX	(UART_TX_PAD_0)				
#define	PAD_SERIAL5_RX	(SERCOM_RX_PAD_1)				
#define	PIN_SERIAL5_TX	(36ul)				
#define	PIN_SERIAL5_RX	(37ul)				
#define	SERCOM_INSTANCE_SERIAL5	&sercom5				
						
						
//	Serial	(EDBG)				
#define	PIN_SERIAL_RX	PAD_SERIAL0_TX				
#define	PIN_SERIAL_TX	PAD_SERIAL0_RX				
#define	PAD_SERIAL_TX	PIN_SERIAL0_TX				
#define	PAD_SERIAL_RX	PIN_SERIAL0_RX				
#define	SERCOM_INSTANCE_SERIAL	SERCOM_INSTANCE_SERIAL0				
//	Serial1					
#define	PAD_SERIAL_B0_TX	(UART_TX_PAD_2)				
#define	PAD_SERIAL_B0_RX	(SERCOM_RX_PAD_3)				
#define	PIN_SERIAL_B0_TX	(2ul)				
#define	PIN_SERIAL_B0_RX	(3ul)				
#define	SERCOM_INSTANCE_SERIAL_B0	&sercom0				
						
//	Serial1					
#define	PAD_SERIAL_B0_BIS_TX	(UART_TX_PAD_2)				
#define	PAD_SERIAL_B0_BIS_RX	(SERCOM_RX_PAD_3)				
#define	PIN_SERIAL_B0_BIS_TX	(8ul)				
#define	PIN_SERIAL_B0_BIS_RX	(9ul)				
#define	SERCOM_INSTANCE_SERIAL_B0_BIS	&sercom0				
						
//	Serial1					
#define	PAD_SERIAL_B1_TX	(UART_TX_PAD_2)				
#define	PAD_SERIAL_B1_RX	(SERCOM_RX_PAD_3)				
#define	PIN_SERIAL_B1_TX	(14ul)				
#define	PIN_SERIAL_B1_RX	(15ul)				
#define	SERCOM_INSTANCE_SERIAL_B1	&sercom1				
						
//	Serial1					
#define	PAD_SERIAL_B2_TX	(UART_TX_PAD_2)				
#define	PAD_SERIAL_B2_RX	(SERCOM_RX_PAD_3)				
#define	PIN_SERIAL_B2_TX	(20ul)				
#define	PIN_SERIAL_B2_RX	(21ul)				
#define	SERCOM_INSTANCE_SERIAL_B2	&sercom2				
						
//	Serial1					
#define	PAD_SERIAL_B3_TX	(UART_TX_PAD_2)				
#define	PAD_SERIAL_B3_RX	(SERCOM_RX_PAD_3)				
#define	PIN_SERIAL_B3_TX	(26ul)				
#define	PIN_SERIAL_B3_RX	(27ul)				
#define	SERCOM_INSTANCE_SERIAL_B3	&sercom3				
						
//	Serial1					
#define	PAD_SERIAL_B4_TX	(UART_TX_PAD_2)				
#define	PAD_SERIAL_B4_RX	(SERCOM_RX_PAD_3)				
#define	PIN_SERIAL_B4_TX	(32ul)				
#define	PIN_SERIAL_B4_RX	(33ul)				
#define	SERCOM_INSTANCE_SERIAL_B4	&sercom4				
						
//	Serial1					
#define	PAD_SERIAL_B5_TX	(UART_TX_PAD_2)				
#define	PAD_SERIAL_B5_RX	(SERCOM_RX_PAD_3)				
#define	PIN_SERIAL_B5_TX	(38ul)				
#define	PIN_SERIAL_B5_RX	(39ul)				
#define	SERCOM_INSTANCE_SERIAL_B5	&sercom5				






/*--------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/


#ifdef __cplusplus

/*	=========================
 *	===== SERCOM DEFINITION
 *	=========================
*/

extern SERCOM sercom0;
extern SERCOM sercom1;
extern SERCOM sercom2;
extern SERCOM sercom3;
extern SERCOM sercom4;
extern SERCOM sercom5;

extern Uart Serial0;
extern Uart Serial0_BIS;
extern Uart Serial1;
extern Uart Serial2;
extern Uart Serial3;
extern Uart Serial4;
extern Uart Serial5;


extern Uart Serial0B;
extern Uart Serial0_BIS_B;
extern Uart Serial1B;
extern Uart Serial2B;
extern Uart Serial3B;
extern Uart Serial4B;
extern Uart Serial5B;
#if defined(BOARD_ID_engi)
extern Uart SerialFTDI;
#endif
//#define SIX_UART 6

#endif

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_USBVIRTUAL      SerialUSB
#define SERIAL_PORT_MONITOR         Serial
// Serial has no physical pins broken out, so it's not listed as HARDWARE port
#define SERIAL_PORT_HARDWARE        Serial1
#define SERIAL_PORT_HARDWARE_OPEN   Serial1

// The board does not have the EDBG support chip, which provides a USB-UART bridge
// accessible using Serial (the Arduino serial monitor is normally connected to this).
// So, the USB virtual serial port (SerialUSB) must be used to communicate with the host.
// Because most sketches use Serial to print to the monitor, it is aliased to SerialUSB.
// Remember to use while(!Serial); to wait for a connection before Serial printing.

// When USB CDC is enabled, Serial refers to SerialUSB, otherwise it refers to Serial1.
#if defined(CDC_ONLY) || defined(CDC_HID) || defined(WITH_CDC)
#define Serial                      SerialUSB
#else
#define Serial                      Serial0
#endif



#define  PCOM_NB 7

#if defined( _SPI_H_INCLUDED) && defined( TwoWire_h)  && defined( cores_usart_h) 

  extern SPIClass SPI0;
  extern SPIClass SPI0_BIS;
  extern SPIClass SPI1;
  extern SPIClass SPI2;
  extern SPIClass SPI3;
  extern SPIClass SPI4;
  extern SPIClass SPI5;

  extern TwoWire Wire0;
  extern TwoWire Wire1;
  extern TwoWire Wire2;
  extern TwoWire Wire3;
  extern TwoWire Wire4;
  extern TwoWire Wire5;
#endif

#define P_COM g_PComDescription
#define P_COM0 g_PComDescription[0]
#define P_COM1 g_PComDescription[1]
#define P_COM2 g_PComDescription[2]
#define P_COM3 g_PComDescription[3]
#define P_COM4 g_PComDescription[4]
#define P_COM5 g_PComDescription[5]
#define P_COM0_BIS g_PComDescription[6]

#define P_ANA0 g_PAnaDescription[0]
#define P_ANA1 g_PAnaDescription[1]


#if defined(BOARD_ID_engi)
// new one #define SerialFTDI      Serial1B

#define FTDI_Serial 	SerialFTDI
#else
#define SerialFTDI      Serial1B
#define FTDI_Serial 	SerialFTDI
#endif


#endif /* _VARIANT_ARDUINO_PILO_ */
