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
#include "variant_net_list.h"
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
#define NUM_PIN_DESCRIPTION_ENTRIES     (100u)

#define PINS_COUNT           NUM_PIN_DESCRIPTION_ENTRIES
#define NUM_DIGITAL_PINS     PINS_COUNT
#define NUM_ANALOG_INPUTS    (20u)
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


/**/
/*
 * Analog pins
 */
 /*
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
*/


#define VARIANT_AR_DEFAULT	AR_DEFAULT

				
										
//SPI definition				
//------------------------------				
#define SPI_INTERFACES_COUNT 1

#define       PIN_SPI0_MISO          (80u)
#define       PIN_SPI0_SCK           (81u)
#define       PIN_SPI0_SS            (78u)
#define       PIN_SPI0_MOSI          (79u)
#define       PERIPH_SPI0           sercom0
#define       PAD_SPI0_TX           SPI_PAD_2_SCK_3
#define       PAD_SPI0_RX           SERCOM_RX_PAD_0

#define       PIN_SPI_MISO          PIN_SPI0_MISO
#define       PIN_SPI_SCK           PIN_SPI0_SCK
#define       PIN_SPI_SS            PIN_SPI0_SS
#define       PIN_SPI_MOSI          PIN_SPI0_MOSI
#define       PERIPH_SPI            PERIPH_SPI0
#define       PAD_SPI_TX            PAD_SPI0_TX
#define       PAD_SPI_RX            PAD_SPI0_RX
//   SERCOM						
						
//   SERCOM						
//	Serial0 PCOM0
#define	PAD_SERIAL0_TX	(UART_TX_PAD_0)				
#define	PAD_SERIAL0_RX	(SERCOM_RX_PAD_1)				
#define	PIN_SERIAL0_TX	(TQFP100_80_ARDUINO)				
#define	PIN_SERIAL0_RX	(TQFP100_81_ARDUINO)				
#define	SERCOM_INSTANCE_SERIAL0	&sercom0				

#define	PAD_SERIAL_B0_TX	(UART_TX_PAD_2)				
#define	PAD_SERIAL_B0_RX	(SERCOM_RX_PAD_3)				
#define	PIN_SERIAL_B0_TX	(TQFP100_78_ARDUINO)				
#define	PIN_SERIAL_B0_RX	(TQFP100_79_ARDUINO)				
#define	SERCOM_INSTANCE_SERIAL_B0	&sercom0				
	
	
//	Serial3					
#define	PAD_SERIAL1_TX	(UART_TX_PAD_0)				
#define	PAD_SERIAL1_RX	(SERCOM_RX_PAD_1)				
#define	PIN_SERIAL1_TX	(TQFP100_53_ARDUINO)				
#define	PIN_SERIAL1_RX	(TQFP100_52_ARDUINO)				
#define	SERCOM_INSTANCE_SERIAL1	&sercom3			
						
//	Serial1_2				
#define	PAD_SERIAL2_TX	(UART_TX_PAD_0)				
#define	PAD_SERIAL2_RX	(SERCOM_RX_PAD_1)				
#define	PIN_SERIAL2_TX	(TQFP100_86_ARDUINO)				
#define	PIN_SERIAL2_RX	(TQFP100_85_ARDUINO)				
#define	SERCOM_INSTANCE_SERIAL2	&sercom1			
						
	
//FTDI Serial3B_3
#define	PAD_SERIAL_B3_TX	(UART_TX_PAD_2)				
#define	PAD_SERIAL_B3_RX	(SERCOM_RX_PAD_3)				
#define	PIN_SERIAL_B3_TX	(TQFP100_93_ARDUINO)				
#define	PIN_SERIAL_B3_RX	(TQFP100_94_ARDUINO)				
#define	SERCOM_INSTANCE_SERIAL_B3	&sercom1				




/*
 * Wire Interfaces
 */
 //WIRE definition						
//------------------------------		

    #define PERIPH_WIRE          PERIPH_WIRE0
    #define WIRE_IT_HANDLER      WIRE0_IT_HANDLER


	
#define	WIRE_INTERFACES_COUNT		3			
#define       PIN_WIRE0_SDA          (TQFP100_81_ARDUINO)						
#define       PIN_WIRE0_SCL          (TQFP100_80_ARDUINO)						
#define       WIRE0_IT_HANDLER          SERCOM0_Handler_softwire						
#define       PERIPH_WIRE0          sercom0		
#define PIN_WIRE_SDA PIN_WIRE0_SDA
#define PIN_WIRE_SCL PIN_WIRE0_SCL
	
static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;					
						
		
  //------------------------------						
	
#define       PIN_WIRE1_SDA          (TQFP100_52_ARDUINO)						
#define       PIN_WIRE1_SCL          (TQFP100_53_ARDUINO)						
#define       WIRE1_IT_HANDLER          SERCOM3_Handler_softwire						
#define       PERIPH_WIRE1          sercom3						
static const uint8_t SDAA = PIN_WIRE1_SDA;
static const uint8_t SCLA = PIN_WIRE1_SCL;		
				
#define       PIN_WIRE2_SDA          (TQFP100_85_ARDUINO)						
#define       PIN_WIRE2_SCL          (TQFP100_86_ARDUINO)						
#define       WIRE2_IT_HANDLER          SERCOM1_Handler_softwire						
#define       PERIPH_WIRE2          sercom1						
static const uint8_t SDAB = PIN_WIRE2_SDA;
static const uint8_t SCLB = PIN_WIRE2_SCL;						
						
		
  
 /*
#define WIRE_INTERFACES_COUNT 1

#define PIN_WIRE_SDA         (20u)
#define PIN_WIRE_SCL         (21u)
#define PERIPH_WIRE          sercom3
#define WIRE_IT_HANDLER      SERCOM3_Handler

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;
*/
#ifdef __cplusplus
}
#endif


//   SERCOM						
				/*		
//   SERCOM						
//	Serial3					
#define	PAD_SERIAL0_TX	(UART_TX_PAD_0)				
#define	PAD_SERIAL0_RX	(SERCOM_RX_PAD_1)				
#define	PIN_SERIAL0_TX	(0ul)				
#define	PIN_SERIAL0_RX	(1ul)				
#define	SERCOM_INSTANCE_SERIAL0	&sercom0				
		*/



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

extern Uart Serial0;
extern Uart Serial3;
extern Uart Serial1_2;
extern Uart Serial3B_3;


//#define SIX_UART 6

#if defined(BOARD_ID_engi)
extern Uart SerialFTDI;
#endif
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
#define SERIAL_PORT_HARDWARE        Serial3
#define SERIAL_PORT_HARDWARE_OPEN   Serial3

// The board does not have the EDBG support chip, which provides a USB-UART bridge
// accessible using Serial (the Arduino serial monitor is normally connected to this).
// So, the USB virtual serial port (SerialUSB) must be used to communicate with the host.
// Because most sketches use Serial to print to the monitor, it is aliased to SerialUSB.
// Remember to use while(!Serial); to wait for a connection before Serial printing.


#define Serial                      Serial0



#define  PCOM_NB 4

#if defined( _SPI_H_INCLUDED) && defined( TwoWire_h)  && defined( cores_usart_h) 

  extern SPIClass SPI0;
  extern SPIClass SPI1;
  extern SPIClass SPI2;
  extern SPIClass SPI3;

  extern TwoWire Wire0;
  extern TwoWire Wire1;
  extern TwoWire Wire2;
  extern TwoWire Wire3;


#endif
#define WireB Wire1
#define WireA Wire2
#define P_COMB P_COM1
#define P_COMA P_COM2
#define P_COM g_PComDescription
#define P_COM0  (g_PComDescription[0])
#define P_COM1  (g_PComDescription[1])
#define P_COM2  (g_PComDescription[2])
#define P_COM3  (g_PComDescription[3])




#define LEDGREEN 		TQFP100_64_ARDUINO
#define LEDRED 			TQFP100_65_ARDUINO
#define LED0 			LEDGREEN
#define LED1 			LEDRED
#define LED_TOP 		LEDGREEN
#define LED_BOTTOM		LEDRED
/* LEDs
 * None of these defines are currently used by the core.
 * The RX and TX LEDs are not present.
 * You may optionally add them to any free pins.
 */

#define LED_BUILTIN          LED_TOP
#define P_IR_NB 8
#define P_GP2Y_NB 8
#define P_Encoder_NB 8
#define P_US_NB 6

#if defined(BOARD_ID_engi)
#define FTDI_Serial 	SerialFTDI

#else
#define SerialFTDI      Serial3B_3
#define FTDI_Serial 	SerialFTDI
#endif

#endif /* _VARIANT_ARDUINO_PILO_ */
