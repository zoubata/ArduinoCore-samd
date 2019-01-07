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

#pragma once
#ifndef __WVARIANT__
#define __WVARIANT__
#include <stdint.h>
#include "sam.h"
#include "variant.h"

#ifdef __cplusplus
extern "C" {
#endif

struct PComPinMux
{
	union {	
		struct {
			uint32_t	P1;// µC number PA00=0 PB00=32; PA31=31
			uint32_t	P0;
			uint32_t	P3;
			uint32_t	P2;
			uint32_t	P5;
			uint32_t	P4;
		};
		struct {
			uint32_t	INT0;// µC number PA00=0 PB00=32; PA31=31
			uint32_t	INT1;
			uint32_t	INT2;
			uint32_t	INT3;
			uint32_t	INT4;
			uint32_t	INT5;
		};
			struct {
			uint32_t	PIN05;// µC number PA00=0 PB00=32; PA31=31
			uint32_t	PIN06;
			uint32_t	PIN07;
			uint32_t	PIN08;
			uint32_t	PIN09;
			uint32_t	PIN10;
		};
		struct {   //IO
			uint32_t	IO0;// µC number PA00=0 PB00=32; PA31=31
			uint32_t	IO1;
			uint32_t	IO2;
			uint32_t	IO3;
			uint32_t	IO4;
			uint32_t	IO5;
		};
		struct {   //PWM
			uint32_t	Tx0;// µC number PA00=0 PB00=32; PA31=31
			uint32_t	Tx1;
			uint32_t	Ty0;
			uint32_t	Ty1;
			uint32_t	rsvd3;
			uint32_t	rsvd4;
		};
		struct { //I2C and USART2
			uint32_t	SCL;// µC number PA00=0 PB00=32; PA31=31
			uint32_t	SDA;
			uint32_t	RXD2;
			uint32_t	TXD2;
			uint32_t	 rsvd2;
			uint32_t	GCLKIO;
		};
		struct { //USART
			uint32_t	RXD;// µC number PA00=0 PB00=32; PA31=31
			uint32_t	TXD;
			uint32_t	CTS;
			uint32_t	RTS;
			uint32_t	 rsvd0;
			uint32_t	 rsvd1;
		};
		struct {//SPI SLAVE
			uint32_t	SCKs;// µC number PA00=0 PB00=32; PA31=31
			uint32_t	MOSIs;
			uint32_t	MISOs;
			uint32_t	SS;
			uint32_t	 rsvd5;
			uint32_t	rsvd6;
		};
		struct {  //SPI MASTER
			uint32_t	SCKm;// µC number PA00=0 PB00=32; PA31=31
			uint32_t	MISOm;
			uint32_t	MOSIm;
			uint32_t	CS0;
			uint32_t	CS1 ;
			uint32_t	CS2;
		};
		struct {
			uint32_t         ulAPin[6] ;// µC number PA00=0 PB00=32; PA31=31
		};
	};
};
//typedef _PComPin PComPin;

struct PComUcDescription
{	
	struct PComPinMux PinMux;
	Sercom* sercom;
/*
	
	union {
		struct {
			Tc* x;// TC instance
			Tc* y;
		} TC;
		struct {
			Tcc* x;
			Tcc* y;
		} TCC;
	} PWM;
	
	struct {
			uint32_t	Tcx0:4;// channel number
			uint32_t	Tcx1:4;// channel number
			uint32_t	Tcy0:4;// channel number
			uint32_t	Tcy1:4;// channel number
			uint32_t	TypeX0:1;//0 TC; 1: TCC
			uint32_t	TypeX1:1;//0 TC; 1: TCC
			uint32_t	TypeY0:1;//0 TC; 1: TCC
			uint32_t	TypeY1:1;//0 TC; 1: TCC
			uint32_t	Adc1:1;//ADC 0 or 1
			uint32_t	Adc2:1;//ADC 0 or 1
			uint32_t	Adc3:1;//ADC 0 or 1
			uint32_t	Adc4:1;//ADC 0 or 1
			uint32_t	Adc5:1;//ADC 0 or 1
			uint32_t	Adc6:1;//ADC 0 or 1
			uint32_t	:6;			
		} ;
	uint8_t EICn[6];//EIC channel number
	uint8_t ADCn[6];//ADC Channel number 0xFF not available
*/
}  ;

typedef struct _PcomStatus
{
 // PComUcDescription         instance ;	                // Must be 32 bits
  struct PComUcDescription instance ;
  char mode;
  int BaudRate;//0 for slave SPI/I2C
  char * fifoRx;
  char Rxe;//index end
  char Rxb;//index begin
  char * fifoTx;
  char Txe;
  char Txb;
  
} PcomStatus ;
#define PCOMSTATUS_EMPTY {0,0,0,0,0,0,0,0}


/* Definitions and types for pins */
typedef enum _EAnalogChannel
{
  No_ADC_Channel=0xff,
  ADC_Channel0=0,
  ADC_Channel1=1,
  ADC_Channel2=2,
  ADC_Channel3=3,
  ADC_Channel4=4,
  ADC_Channel5=5,
  ADC_Channel6=6,
  ADC_Channel7=7,
  ADC_Channel8=8,
  ADC_Channel9=9,
  ADC_Channel10=10,
  ADC_Channel11=11,
  ADC_Channel12=12,
  ADC_Channel13=13,
  ADC_Channel14=14,
  ADC_Channel15=15,
  ADC_Channel16=16,
  ADC_Channel17=17,
  ADC_Channel18=18,
  ADC_Channel19=19,
  DAC_Channel0,
  DAC_Channel1
} EAnalogChannel ;

// Definitions for TC channels
// RESERVED (1 bit, used for negative) | Timer Number (3 bits: 0-7) | Timer Type (1 bit: 0=TCC, 1=TC) | Timer Channel (3 bits: 0-7)
typedef enum _ETCChannel
{
  NOT_ON_TIMER=0xff,
  TCC0_CH0 = (0<<4)|(0<<3)|(0),
  TCC0_CH1 = (0<<4)|(0<<3)|(1),
  TCC0_CH2 = (0<<4)|(0<<3)|(2),
  TCC0_CH3 = (0<<4)|(0<<3)|(3),
  TCC0_CH4 = (0<<4)|(0<<3)|(4), 
  TCC0_CH5 = (0<<4)|(0<<3)|(5), 
  TCC0_CH6 = (0<<4)|(0<<3)|(6), 
  TCC0_CH7 = (0<<4)|(0<<3)|(7), 
  TCC1_CH0 = (1<<4)|(0<<3)|(0),
  TCC1_CH1 = (1<<4)|(0<<3)|(1),
  TCC1_CH2 = (1<<4)|(0<<3)|(2), 
  TCC1_CH3 = (1<<4)|(0<<3)|(3), 
  TCC2_CH0 = (2<<4)|(0<<3)|(0),
  TCC2_CH1 = (2<<4)|(0<<3)|(1),
  TCC2_CH2 = (2<<4)|(0<<3)|(2), 
  TCC2_CH3 = (2<<4)|(0<<3)|(3), 
  TC0_CH0  = (0<<4)|(1<<3)|(0),
  TC0_CH1  = (0<<4)|(1<<3)|(1),
  TC1_CH0  = (1<<4)|(1<<3)|(0),
  TC1_CH1  = (1<<4)|(1<<3)|(1),
  TC2_CH0  = (2<<4)|(1<<3)|(0),
  TC2_CH1  = (2<<4)|(1<<3)|(1),
  TC3_CH0  = (3<<4)|(1<<3)|(0),
  TC3_CH1  = (3<<4)|(1<<3)|(1),
  TC4_CH0  = (4<<4)|(1<<3)|(0),
  TC4_CH1  = (4<<4)|(1<<3)|(1),
  TC5_CH0  = (5<<4)|(1<<3)|(0),
  TC5_CH1  = (5<<4)|(1<<3)|(1),
  TC6_CH0  = (6<<4)|(1<<3)|(0),
  TC6_CH1  = (6<<4)|(1<<3)|(1),
  TC7_CH0  = (7<<4)|(1<<3)|(0),
  TC7_CH1  = (7<<4)|(1<<3)|(1)
} ETCChannel ;
#ifndef TCC_INST_NUM
#define TCC_INST_NUM 0
#endif

extern const void* g_apTCInstances[TCC_INST_NUM+TC_INST_NUM] ;

#define GetTCNumber( x ) ( ((x) >> 4) & 0x07 )
#define GetTCType( x ) ( ((x) >> 3) & 0x01 )
#define GetTCChannelNumber( x ) ( (x) & 0x07 )
#if (SAMD)
	#define GetTC( x ) ( g_apTCInstances[((x) >> 4) & 0x07] )
#elif (SAML ) // have TCC
	#define GetTC( x ) ( (((x) >> 3) & 0x01 ) == 0 ? g_apTCInstances[((x) >> 4) & 0x07] : (((((x) >> 4) & 0x07) == 4) ? TC4 : g_apTCInstances[(((x) >> 4) & 0x07) + TCC_INST_NUM]) )
#elif ( SAMC ) // have TCC
	#define GetTC( x ) ( (((x) >> 3) & 0x01 ) == 0 ? g_apTCInstances[((x) >> 4) & 0x07] : ( g_apTCInstances[(((x) >> 4) & 0x07) + TCC_INST_NUM]) )
#else
	#error "WVariant.h: Unsupported chip"
#endif

// Definitions for GCLK_CCL column TODO, AC?
// RESERVED (1 bit, used for negative) | GCLK (3 bits: 0-7) | CCL (4 bits: 2 for CCL number, 2 for pin)
typedef enum _EGCLK_CCL
{
  GCLK_CCL_NONE=0xff
} EGCLK_CCL ;

typedef enum _EPortType
{
  NOT_A_PORT=0xff,
  PORTA=0,
  PORTB=1,
  PORTC=2
} EPortType ;

typedef enum
{
  EXTERNAL_INT_0 = 0,
  EXTERNAL_INT_1,
  EXTERNAL_INT_2,
  EXTERNAL_INT_3,
  EXTERNAL_INT_4,
  EXTERNAL_INT_5,
  EXTERNAL_INT_6,
  EXTERNAL_INT_7,
  EXTERNAL_INT_8,
  EXTERNAL_INT_9,
  EXTERNAL_INT_10,
  EXTERNAL_INT_11,
  EXTERNAL_INT_12,
  EXTERNAL_INT_13,
  EXTERNAL_INT_14,
  EXTERNAL_INT_15,
  EXTERNAL_INT_NMI,
  EXTERNAL_NUM_INTERRUPTS,
  NOT_AN_INTERRUPT = 0xff,
  EXTERNAL_INT_NONE = NOT_AN_INTERRUPT
} EExt_Interrupts ;


/* Copied from wiring_constants.h */
#define INPUT           (0x0)
#define OUTPUT          (0x1)
#define INPUT_PULLUP    (0x2)
#define INPUT_PULLDOWN  (0x3)
#define OUTPUT_LOW          (0x4)
typedef enum _EPioType
{
  PIO_NOT_A_PIN=0xff,                   /* Not under control of a peripheral. */

  PIO_INPUT=INPUT,                    /* The pin is controlled by PORT and is an input. */
  PIO_OUTPUT=OUTPUT,                  /* The pin is controlled by PORT and is an output. */
  PIO_INPUT_PULLUP=INPUT_PULLUP,      /* The pin is controlled by PORT and is an input with internal pull-up resistor enabled. */
  PIO_INPUT_PULLDOWN=INPUT_PULLDOWN,  /* The pin is controlled by PORT and is an input with internal pull-down resistor enabled. */

  PIO_EXTINT=4,                       /* The pin is controlled by the EXTINT peripheral and is an input with interrupt. */

  PIO_ANALOG_ADC=5,                   /* The pin is controlled by the ANALOG peripheral and is an ADC input. */
  PIO_ANALOG_DAC=6,                   /* The pin is controlled by the ANALOG peripheral and is a DAC output. */
  PIO_ANALOG_REF=7,                   /* The pin is controlled by the ANALOG peripheral and is a voltage reference input (3.3V MAX). */
  PIO_ANALOG_AC=8,                    /* The pin is controlled by the ANALOG peripheral and is used by the AC (analog comparator). */
  PIO_ANALOG_PTC=9,                   /* The pin is controlled by the ANALOG peripheral and is used by the PTC (peripheral touch controller). */
  PIO_ANALOG_SDADC=10,                /* The pin is controlled by the ANALOG peripheral and is used by the PTC (peripheral touch controller). */

  PIO_TIMER_PWM=11,                   /* The pin is controlled by a TIMER peripheral and is a PWM output. */
  PIO_TIMER_CAPTURE=12,               /* The pin is controlled by a TIMER peripheral and is a capture input. */

  PIO_SERCOM=13,                      /* The pin is controlled by a SERCOM peripheral (UART, SPI, or I2C). */
  PIO_COM=14,                         /* The pin is controlled by the COM peripheral (USB or I2S). */
  PIO_AC_GCLK=15,                     /* The pin is controlled by the AC_GCLK peripheral (I/O). */
  PIO_CCL=16,                         /* The pin is controlled by the CCL (configurable custom logic) peripheral (I/O). */

  PIO_MULTI,                          /* The pin can be configured to any type based on the attributes. */

  PIO_STARTUP                        /* Used as parameter to pinPeripheral() only to set startup state (enable INEN only) */
} EPioType ;

/**
 * Pin Attributes to be OR-ed
 */
#define PIN_ATTR_NONE              (0UL << 0)

#define PIN_ATTR_INPUT           (1UL << PIO_INPUT)
#define PIN_ATTR_OUTPUT          (1UL << PIO_OUTPUT)
#define PIN_ATTR_INPUT_PULLUP    (1UL << PIO_INPUT_PULLUP)
#define PIN_ATTR_INPUT_PULLDOWN  (1UL << PIO_INPUT_PULLDOWN)
#define PIN_ATTR_DIGITAL           (PIN_ATTR_INPUT|PIN_ATTR_INPUT_PULLUP|PIN_ATTR_INPUT_PULLDOWN|PIN_ATTR_OUTPUT)

#define PIN_ATTR_EXTINT            (1UL << PIO_EXTINT)

#define PIN_ATTR_ADC               (1UL << PIO_ANALOG_ADC)
#define PIN_ATTR_DAC               (1UL << PIO_ANALOG_DAC)
#define PIN_ATTR_REF               (1UL << PIO_ANALOG_REF)
#define PIN_ATTR_AC                (1UL << PIO_ANALOG_AC)
#define PIN_ATTR_PTC               (1UL << PIO_ANALOG_PTC)
#define PIN_ATTR_SDADC             (1UL << PIO_ANALOG_SDADC)
#define PIN_ATTR_ANALOG          PIN_ATTR_ADC

#define PIN_ATTR_TIMER_PWM       (1UL << PIO_TIMER_PWM)
#define PIN_ATTR_TIMER_CAPTURE   (1UL << PIO_TIMER_CAPTURE)
#define PIN_ATTR_TIMER_BOTH        (PIN_ATTR_TIMER_PWM|PIN_ATTR_TIMER_CAPTURE)
#define PIN_ATTR_TIMER             PIN_ATTR_TIMER_BOTH

#define PIN_ATTR_SERCOM            (1UL << PIO_SERCOM)
#define PIN_ATTR_COM               (1UL << PIO_COM)
#define PIN_ATTR_AC_GCLK           (1UL << PIO_AC_GCLK)
#define PIN_ATTR_CCL               (1UL << PIO_CCL)


// A   B                 C       D          E      F   G     H     I
//EIC REF ADC AC PTC DAC SERCOM SERCOM_ALT TC/TCC TCC COM AC/GCLK CCL
typedef enum _EPioPeripheral
{
	PER_PORT=0xff,          /* The pin is controlled by PORT. */
	PER_EXTINT=0,         /* The pin is controlled by the associated signal of peripheral A. */
	PER_ANALOG=1,         /* The pin is controlled by the associated signal of peripheral B. */
	PER_SERCOM=2,         /* The pin is controlled by the associated signal of peripheral C. */
	PER_SERCOM_ALT=3,     /* The pin is controlled by the associated signal of peripheral D. */
	PER_TIMER=4,          /* The pin is controlled by the associated signal of peripheral E. */
	PER_TIMER_ALT=5,      /* The pin is controlled by the associated signal of peripheral F. */
	PER_COM=6,            /* The pin is controlled by the associated signal of peripheral G. */
	PER_AC_CLK=7,         /* The pin is controlled by the associated signal of peripheral H. */
	PER_CCL=8            /* The pin is controlled by the associated signal of peripheral I. */
} EPioPeripheral ;

/**
 * Peripheral Attributes to be OR-ed
 */
#define PER_ATTR_NONE            (0UL<<0)

#define PER_ATTR_SERCOM_STD      (0UL<<0)
#define PER_ATTR_SERCOM_ALT      (1UL<<0)
#define PER_ATTR_SERCOM_MASK     (1UL<<0)

#define PER_ATTR_TIMER_STD       (0UL<<1)
#define PER_ATTR_TIMER_ALT       (1UL<<1)
#define PER_ATTR_TIMER_MASK      (1UL<<1)

#define PER_ATTR_DRIVE_STD       (0UL<<2)
#define PER_ATTR_DRIVE_STRONG    (1UL<<2)
#define PER_ATTR_DRIVE_MASK      (1UL<<2)

#define PER_ATTR_OUTPUT_TYPE_STD            (0UL<<3)
#define PER_ATTR_OUTPUT_TYPE_OPEN_DRAIN     (1UL<<3)
#define PER_ATTR_OUTPUT_TYPE_OPEN_SOURCE    (2UL<<3)
#define PER_ATTR_OUTPUT_TYPE_BUSKEEPER      (3UL<<3)
#define PER_ATTR_OUTPUT_TYPE_MASK           (3UL<<3)

#define PER_ATTR_INPUT_SYNCHRONIZER_ON_DEMAND     (0UL<<5)
#define PER_ATTR_INPUT_SYNCHRONIZER_ALWAYS_ON     (1UL<<5)
#define PER_ATTR_INPUT_SYNCHRONIZER_MASK          (1UL<<5)

#define PER_ATTR_ADC_STD             (0UL<<6)
#define PER_ATTR_ADC_ALT             (1UL<<6)
#define PER_ATTR_ADC_MASK            (1UL<<6)


/* Types used for the table below
 * This struct MUST be 12 bytes long (elements are ordered to prevent unaligned access).
 */
typedef struct _PinDescription
{
  EPortType         ulPort ;	                // Must be 8 bits
  uint8_t         ulPin ;	                // Must be 8 bits
  EPioType         ulPinType ;	                // Must be 8 bits
  uint8_t         ulPeripheralAttribute ;	// Must be 8 bit bitfield
  uint32_t        ulPinAttribute ;	        // Must be 32 bit bitfield
  uint8_t         ulTCChannel ;	                // Must be 8 bits
  uint8_t         ulADCChannelNumber ;	        // Must be 8 bits
  uint8_t         ulExtInt ;	                // Must be 8 bits
  uint8_t         ulGCLKCCL ;	                // Must be 8 bits
} PinDescription ;


typedef enum
{
  NONE = 0,
  GPIO = 1,
  INT=2,
  PWM=3,
  SPI_MASTER=0x11,
  USART=0x12,
  I2C=0x14,
  USART2=0x13,
  SPI_SLAVE=0x10,
  I2C_USART2=0x17
} Pcom_Mode ;


/* Pins table to be instantiated into variant.cpp */
extern const PinDescription g_APinDescription[] ;

/* Generic Clock Multiplexer IDs */
#if (SAMD20)
	#define   GCM_DFLL48M    		0x0ul  /**< \brief (GCLK_CLKCTRL) DFLL48M Reference */
	#define   GCM_WDT        		0x1ul  /**< \brief (GCLK_CLKCTRL) WDT */
	#define   GCM_RTC        		0x2ul  /**< \brief (GCLK_CLKCTRL) RTC */
	#define   GCM_EIC        		0x3ul  /**< \brief (GCLK_CLKCTRL) EIC */
	#define   GCM_EVSYS_CHANNEL_0 	0x4ul  /**< \brief (GCLK_CLKCTRL) EVSYS_CHANNEL_0 */
	#define   GCM_EVSYS_CHANNEL_1 	0x5ul  /**< \brief (GCLK_CLKCTRL) EVSYS_CHANNEL_1 */
	#define   GCM_EVSYS_CHANNEL_2 	0x6ul  /**< \brief (GCLK_CLKCTRL) EVSYS_CHANNEL_2 */
	#define   GCM_EVSYS_CHANNEL_3 	0x7ul  /**< \brief (GCLK_CLKCTRL) EVSYS_CHANNEL_3 */
	#define   GCM_EVSYS_CHANNEL_4 	0x8ul  /**< \brief (GCLK_CLKCTRL) EVSYS_CHANNEL_4 */
	#define   GCM_EVSYS_CHANNEL_5 	0x9ul  /**< \brief (GCLK_CLKCTRL) EVSYS_CHANNEL_5 */
	#define   GCM_EVSYS_CHANNEL_6 	0xAul  /**< \brief (GCLK_CLKCTRL) EVSYS_CHANNEL_6 */
	#define   GCM_EVSYS_CHANNEL_7 	0xBul  /**< \brief (GCLK_CLKCTRL) EVSYS_CHANNEL_7 */
	#define   GCM_SERCOMX_SLOW 		0xCul  /**< \brief (GCLK_CLKCTRL) SERCOMx_SLOW */
	#define   GCM_SERCOM0_CORE 		0xDul  /**< \brief (GCLK_CLKCTRL) SERCOM0_CORE */
	#define   GCM_SERCOM1_CORE 		0xEul  /**< \brief (GCLK_CLKCTRL) SERCOM1_CORE */
	#define   GCM_SERCOM2_CORE 		0xFul  /**< \brief (GCLK_CLKCTRL) SERCOM2_CORE */
	#define   GCM_SERCOM3_CORE 		0x10ul  /**< \brief (GCLK_CLKCTRL) SERCOM3_CORE */
	#define   GCM_SERCOM4_CORE 		0x11ul  /**< \brief (GCLK_CLKCTRL) SERCOM4_CORE */
	#define   GCM_SERCOM5_CORE 		0x12ul  /**< \brief (GCLK_CLKCTRL) SERCOM5_CORE */
	#define   GCM_TC0_TC1    		0x13ul  /**< \brief (GCLK_CLKCTRL) TC0,TC1 */
	#define   GCM_TC2_TC3    		0x14ul  /**< \brief (GCLK_CLKCTRL) TC2,TC3 */
	#define   GCM_TC4_TC5    		0x15ul  /**< \brief (GCLK_CLKCTRL) TC4,TC5 */
	#define   GCM_TC6_TC7    		0x16ul  /**< \brief (GCLK_CLKCTRL) TC6,TC7 */
	#define   GCM_ADC        		ADC_GCLK_ID  /**< \brief (GCLK_CLKCTRL) ADC */
	#define   GCM_AC_DIG     		0x18ul  /**< \brief (GCLK_CLKCTRL) AC_DIG */
	#define   GCM_AC_ANA     		0x19ul  /**< \brief (GCLK_CLKCTRL) AC_ANA */
	#define   GCM_DAC        		0x1Aul  /**< \brief (GCLK_CLKCTRL) DAC */
	#define   GCM_PTC        		0x1Bul  /**< \brief (GCLK_CLKCTRL) PTC */
#elif (SAMD21 || SAMD11)

	#define GCM_DFLL48M_REF           (0x00U)
	#define GCM_FDPLL96M_INPUT        (0x01U)
	#define GCM_FDPLL96M_32K          (0x02U)
	#define GCM_WDT                   (0x03U)
	#define GCM_RTC                   (0x04U)
	#define GCM_EIC                   (0x05U)
	#define GCM_USB                   (0x06U)
	#define GCM_EVSYS_CHANNEL_0       (0x07U)
	#define GCM_EVSYS_CHANNEL_1       (0x08U)
	#define GCM_EVSYS_CHANNEL_2       (0x09U)
	#define GCM_EVSYS_CHANNEL_3       (0x0AU)
	#define GCM_EVSYS_CHANNEL_4       (0x0BU)
	#define GCM_EVSYS_CHANNEL_5       (0x0CU)
	#if (SAMD11)
		#define GCM_SERCOMx_SLOW          (0x0DU)
		#define GCM_SERCOM0_CORE          (0x0EU)
		#define GCM_SERCOM1_CORE          (0x0FU)
		#define GCM_SERCOM2_CORE          (0x10U)
		#define GCM_TCC0                  (0x11U)
		#define GCM_TC1_TC2               (0x12U)
		#define GCM_ADC                   (ADC_GCLK_ID)
		#define GCM_AC_DIG                (0x14U)
		#define GCM_AC_ANA                (0x15U)
		#define GCM_DAC                   (0x16U)
		#define GCM_PTC                   (0x17U)
	#else
		#define GCM_EVSYS_CHANNEL_6       (0x0DU)
		#define GCM_EVSYS_CHANNEL_7       (0x0EU)
		#define GCM_EVSYS_CHANNEL_8       (0x0FU)
		#define GCM_EVSYS_CHANNEL_9       (0x10U)
		#define GCM_EVSYS_CHANNEL_10      (0x11U)
		#define GCM_EVSYS_CHANNEL_11      (0x12U)
		#define GCM_SERCOMx_SLOW          (0x13U)
		#define GCM_SERCOM0_CORE          (0x14U)
		#define GCM_SERCOM1_CORE          (0x15U)
		#define GCM_SERCOM2_CORE          (0x16U)
		#define GCM_SERCOM3_CORE          (0x17U)
		#define GCM_SERCOM4_CORE          (0x18U)
		#define GCM_SERCOM5_CORE          (0x19U)
		#define GCM_TCC0_TCC1             (0x1AU)
		#define GCM_TCC2_TC3              (0x1BU)
		#define GCM_TC4_TC5               (0x1CU)
		#define GCM_TC6_TC7               (0x1DU)
		#define GCM_ADC                   (ADC_GCLK_ID)
		#define GCM_AC_DIG                (0x1FU)
		#define GCM_AC_ANA                (0x20U)
		#define GCM_DAC                   (0x21U)
		#define GCM_PTC                   (0x22U)
		#define GCM_I2S_0                 (0x23U)
		#define GCM_I2S_1                 (0x24U)
	#endif

#elif (SAML21)
	#define GCM_DFLL48M_REF           (0x00U)
	#define GCM_FDPLL96M_INPUT        (0x01U)
	#define GCM_FDPLL96M_32K          (0x02U)
	#define GCM_EIC                   (0x03U)
	#define GCM_USB                   (0x04U)
	#define GCM_EVSYS_CHANNEL_0       (0x05U)
	#define GCM_EVSYS_CHANNEL_1       (0x06U)
	#define GCM_EVSYS_CHANNEL_2       (0x07U)
	#define GCM_EVSYS_CHANNEL_3       (0x08U)
	#define GCM_EVSYS_CHANNEL_4       (0x09U)
	#define GCM_EVSYS_CHANNEL_5       (0x0AU)
	#define GCM_EVSYS_CHANNEL_6       (0x0BU)
	#define GCM_EVSYS_CHANNEL_7       (0x0CU)
	#define GCM_EVSYS_CHANNEL_8       (0x0DU)
	#define GCM_EVSYS_CHANNEL_9       (0x0EU)
	#define GCM_EVSYS_CHANNEL_10      (0x0FU)
	#define GCM_EVSYS_CHANNEL_11      (0x10U)
	#define GCM_SERCOMx_SLOW          (0x11U)
	#define GCM_SERCOM0_CORE          (0x12U)
	#define GCM_SERCOM1_CORE          (0x13U)
	#define GCM_SERCOM2_CORE          (0x14U)
	#define GCM_SERCOM3_CORE          (0x15U)
	#define GCM_SERCOM4_CORE          (0x16U)
	#define GCM_SERCOM5_SLOW          (0x17U)
	#define GCM_SERCOM5_CORE          (0x18U)
	#define GCM_TCC0_TCC1             (0x19U)
	#define GCM_TCC2                  (0x1AU)
	#define GCM_TC0_TC1               (0x1BU)
	#define GCM_TC2_TC3               (0x1CU)
	#define GCM_TC4                   (0x1DU)
	#define GCM_ADC                   (ADC_GCLK_ID)
	#define GCM_AC                    (0x1FU)
	#define GCM_DAC                   (0x20U)
	#define GCM_PTC                   (0x21U)
	#define GCM_CCL                   (0x22U)

#elif (SAMC21)
	#define GCM_FDPLL96M_INPUT        (0x00U)
	#define GCM_FDPLL96M_32K          (0x01U)
	#define GCM_EIC                   (0x02U)
	#define GCM_FREQM_MEASURE         (0x03U)
	#define GCM_FREQM_REF             (0x04U)
	#define GCM_TSENS                 (0x05U)
	#define GCM_EVSYS_CHANNEL_0       (0x06U)
	#define GCM_EVSYS_CHANNEL_1       (0x07U)
	#define GCM_EVSYS_CHANNEL_2       (0x08U)
	#define GCM_EVSYS_CHANNEL_3       (0x09U)
	#define GCM_EVSYS_CHANNEL_4       (0x0AU)
	#define GCM_EVSYS_CHANNEL_5       (0x0BU)
	#define GCM_EVSYS_CHANNEL_6       (0x0CU)
	#define GCM_EVSYS_CHANNEL_7       (0x0DU)
	#define GCM_EVSYS_CHANNEL_8       (0x0EU)
	#define GCM_EVSYS_CHANNEL_9       (0x0FU)
	#define GCM_EVSYS_CHANNEL_10      (0x10U)
	#define GCM_EVSYS_CHANNEL_11      (0x11U)
	#define GCM_SERCOMx_SLOW          (SERCOM0_GCLK_ID_SLOW)
	#define GCM_SERCOM0_CORE          (SERCOM0_GCLK_ID_CORE)
	#define GCM_SERCOM1_CORE          (SERCOM1_GCLK_ID_CORE)
	#define GCM_SERCOM2_CORE          (SERCOM2_GCLK_ID_CORE)
	#define GCM_SERCOM3_CORE          (SERCOM3_GCLK_ID_CORE)
	#define GCM_SERCOM4_CORE          (SERCOM4_GCLK_ID_CORE)
	#define GCM_SERCOM5_SLOW          (SERCOM5_GCLK_ID_SLOW)
	#define GCM_SERCOM5_CORE          (SERCOM3_GCLK_ID_CORE)
	#define GCM_CAN0                  (0x1AU)
	#define GCM_CAN1                  (0x1BU)
	#define GCM_TCC0_TCC1             (TCC0_GCLK_ID)
	#define GCM_TCC2                  (TCC2_GCLK_ID)
	#define GCM_TC0_TC1               (0x1EU)
	#define GCM_TC2_TC3               (0x1FU)
	#define GCM_TC4                   (0x20U)
	#define GCM_ADC0                  (ADC0_GCLK_ID)
	#define GCM_ADC1                  (ADC1_GCLK_ID)
	#define GCM_SDADC                 (0x23U)
	#define GCM_AC                    (0x22U)
	#define GCM_DAC                   (0x24U)
	#define GCM_PTC                   (0x25U)
	#define GCM_CCL                   (0x26U)
	#define GCM_NVMCTRL               (0x27U)
#endif
#ifdef __cplusplus
} // extern "C"
#endif


#ifdef __cplusplus
	//#include "../../libraries/SPI/SPI.h"
	#include "../../libraries/SPI/SPI.h"
	#include "../../libraries/Wire/Wire.h"
	struct PComPin
	{
		union {	
			struct {
				unsigned char	P1;
				unsigned char	P0;
				unsigned char	P3;
				unsigned char	P2;
				unsigned char	P5;
				unsigned char	P4;
			};
			struct {
				unsigned char	INT0;
				unsigned char	INT1;
				unsigned char	INT2;
				unsigned char	INT3;
				unsigned char	INT4;
				unsigned char	INT5;
			};
			
				struct {
				unsigned char	PIN06;
				unsigned char	PIN05;
				unsigned char	PIN08;
				unsigned char	PIN07;
				unsigned char	PIN10;
				unsigned char	PIN09;
			};
			struct {   //IO
				unsigned char	IO0;
				unsigned char	IO1;
				unsigned char	IO2;
				unsigned char	IO3;
				unsigned char	IO4;
				unsigned char	IO5;
			};
			struct {   //PWM
				unsigned char	Tx0;
				unsigned char	Tx1;
				unsigned char	Ty0;
				unsigned char	Ty1;
				unsigned char	rsvd3;
				unsigned char	rsvd4;
			};
			struct { //I2C and USART2
				unsigned char	SCL;
				unsigned char	SDA;
				unsigned char	RXD2;
				unsigned char	TXD2;
				unsigned char	 rsvd2;
				unsigned char	GCLKIO;
			};
			struct { //USART
				unsigned char	RXD;
				unsigned char	TXD;
				unsigned char	CTS;
				unsigned char	RTS;
				unsigned char	 rsvd0;
				unsigned char	 rsvd1;
			};
			struct {//SPI SLAVE
				unsigned char	SCKs;
				unsigned char	MOSIs;
				unsigned char	MISOs;
				unsigned char	SS;
				unsigned char	 rsvd5;
				unsigned char	rsvd6;
			};
			struct {  //SPI MASTER
				unsigned char	SCKm;
				unsigned char	MISOm;
				unsigned char	MOSIm;
				unsigned char	CS0;
				unsigned char	CS1 ;
				unsigned char	CS2;
			};
			struct {
				unsigned char         ulAPin[6] ;// µC number PA00=0 PB00=32; PA31=31
			};
		};
	};
	//typedef _PComPin PComPin;
#endif //__cplusplus
// typedef _PComUcDescription PComUcDescription
#ifdef __cplusplus

	#include "../../libraries/SPI/SPI.h"
	#include "../../libraries/Wire/Wire.h"

	struct  PComDescription
	{
	 struct PComPin Pin;

	  Uart & serial;
	  Uart & serial2;
	  TwoWire & wire;
	  SPIClass & spi;


	} ;
	struct  PAnaDescription
	{
		union {	
			struct {
				unsigned char	IO0;
				unsigned char	IO1;
				unsigned char	IO2;
				unsigned char	IO3;
				unsigned char	IO4;
				unsigned char	IO5;
				unsigned char	IO6;
				unsigned char	IO7;
			};
			
				struct {
				unsigned char	PIN04;
				unsigned char	PIN06;
				unsigned char	PIN08;
				unsigned char	PIN10;
				unsigned char	PIN12;
				unsigned char	PIN14;
				unsigned char	PIN16;
				unsigned char	PIN18;
			};
			struct {
				unsigned char	A0;
				unsigned char	A1;
				unsigned char	A2;
				unsigned char	A3;
				unsigned char	A4;
				unsigned char	A5;
				unsigned char	A6;
				unsigned char	A7;
			 };
			 struct {
				unsigned char	INT0;
				unsigned char	INT1;
				unsigned char	INT2;
				unsigned char	INT3;
				unsigned char	INT4;
				unsigned char	INT5;
				unsigned char	INT6;
				unsigned char	INT7;
				};
		} Pin;		
	} ;
	//typedef _PComDescription PComDescription ;

	extern const struct PComDescription g_PComDescription[];
	extern const struct PAnaDescription g_PAnaDescription[];


typedef	struct  
	{
		union {	
			struct {
				unsigned char	PIN01;
				unsigned char	PIN02;
				unsigned char	PIN03;
				unsigned char	PIN04;
			};		 
		} Pin;		
	} P4Description;
typedef	struct  
	{
		union {	
			struct {
				unsigned char	PIN01;
				unsigned char	PIN02;
				unsigned char	PIN03;
			};		 
		} Pin;		
	} P3Description; 


typedef	struct  
	{
		union {	
			struct {
				unsigned char	PIN01;
				unsigned char	PIN02;
				unsigned char	PIN03;
				unsigned char	PIN04;
			};	
			struct {
				unsigned char	VDD5V;
				unsigned char	IRE;
				unsigned char	IRR;
				unsigned char	GND;
			};	
		} Pin;		
	} PInfraRedDescription;	
typedef	struct  
	{
		union {	
			struct {
				unsigned char	PIN01;
				unsigned char	PIN02;
				unsigned char	PIN03;
			};		
	struct {
				unsigned char	VDD5V;
				unsigned char	GP2Y;
				unsigned char	GND;
			};		
	struct {
				unsigned char	VDD5V_;
				unsigned char	VO;
				unsigned char	GND_;
			};		
		} Pin;		
	} P3GP2YDescription;
typedef struct  
	{
		union {	
			struct {
				unsigned char	PIN01;
				unsigned char	PIN02;
				unsigned char	PIN03;
				unsigned char	PIN04;
			};	
			struct {
				unsigned char	VDD5V;
				unsigned char	IA;
				unsigned char	IB;
				unsigned char	GND;
			};	
			struct {
				unsigned char	VDD3V3;
				unsigned char	IA_;
				unsigned char	IB_;
				unsigned char	GND_;
			};	
		} Pin;		
	} PEncoderDescription ;	
typedef	struct  
	{
		union {	
			struct {
				unsigned char	PIN01;
				unsigned char	PIN02;
				unsigned char	PIN03;
				unsigned char	PIN04;
			};	
			struct {
				unsigned char	VDD5V;
				unsigned char	TRIG;
				unsigned char	ECHO;
				unsigned char	GND;
			};		
		} Pin;		
	} PUSDescription;
extern const  P3GP2YDescription P_GP2Y[];
extern const  PUSDescription P_US[];
extern const  PInfraRedDescription P_IR[];
extern const  PEncoderDescription P_Encoder[];


#endif//__cplusplus
#endif //__WVARIANT__



