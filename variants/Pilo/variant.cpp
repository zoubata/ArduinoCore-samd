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
/*
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * + Pin number +  ZERO Board pin  |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            | Digital Low      |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */


#include "variant.h"

/*
 * Pins descriptions
 */
const PinDescription g_APinDescription[]=
{
// ulPort ;ulPin ; ulPinType ; ulPeripheralAttribute ;      ulPinAttribute ;	     ulTCChannel ;	       ulADCChannelNumber ;	     ulExtInt ;	     ulGCLKCCL 
//{ PORTA,  0, PIO_MULTI, PER_ATTR_DRIVE_STRONG,  , NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_NONE, GCLK_CCL_NONE },
  // P_com0 0..5 - Digital pins
  // ----------------------
  // 0/1 - SERCOM/UART (Serial1)        

  { PORTA,  8, PIO_MULTI,	P_COM0_P0_PER_ATTRIB,	P_COM0_P0_PIN_ATTRIB,	P_COM0_P0_TMR, 	ADC_Channel8, 	P_COM0_P0_INT	,GCLK_CCL_NONE }, //  
  { PORTA,  9, PIO_MULTI,	P_COM0_P1_PER_ATTRIB,	P_COM0_P0_PIN_ATTRIB,	P_COM0_P1_TMR, 	ADC_Channel9,  	P_COM0_P1_INT	,GCLK_CCL_NONE  }, //  
  { PORTA, 10, PIO_MULTI,	P_COM0_P2_PER_ATTRIB,	P_COM0_P0_PIN_ATTRIB,	P_COM0_P2_TMR, 	ADC_Channel10, 	P_COM0_P2_INT	,GCLK_CCL_NONE }, //  
  { PORTA, 11, PIO_MULTI,	P_COM0_P3_PER_ATTRIB,	P_COM0_P0_PIN_ATTRIB,	P_COM0_P3_TMR, 	ADC_Channel11, 	P_COM0_P3_INT	,GCLK_CCL_NONE }, // 
  { PORTA, 21, PIO_MULTI,	P_COM0_P4_PER_ATTRIB,	P_COM0_P0_PIN_ATTRIB,	P_COM0_P4_TMR, 	No_ADC_Channel,  P_COM0_P4_INT	,GCLK_CCL_NONE }, //  
  { PORTA, 18, PIO_MULTI,	P_COM0_P5_PER_ATTRIB,	P_COM0_P0_PIN_ATTRIB,	P_COM0_P5_TMR, 	No_ADC_Channel,  P_COM0_P5_INT	,GCLK_CCL_NONE }, //  

  // P_com0_bis 0..5 - Digital pins
  //6..11

  { PORTA,  4, PIO_MULTI,P_COM0_BIS_P0_PER_ATTRIB,P_COM0_BIS_P0_PIN_ATTRIB,P_COM0_BIS_P0_TMR,	ADC_Channel4 ,  P_COM0_BIS_P0_INT	,GCLK_CCL_NONE  }, //  
  { PORTA,  5, PIO_MULTI,P_COM0_BIS_P1_PER_ATTRIB,P_COM0_BIS_P1_PIN_ATTRIB,P_COM0_BIS_P1_TMR,	ADC_Channel5 ,  P_COM0_BIS_P1_INT	,GCLK_CCL_NONE   }, //  
  { PORTA,  6, PIO_MULTI,P_COM0_BIS_P2_PER_ATTRIB,P_COM0_BIS_P2_PIN_ATTRIB,P_COM0_BIS_P2_TMR,	ADC_Channel6 ,  P_COM0_BIS_P2_INT	,GCLK_CCL_NONE   }, //  
  { PORTA,  7, PIO_MULTI,P_COM0_BIS_P3_PER_ATTRIB,P_COM0_BIS_P3_PIN_ATTRIB,P_COM0_BIS_P3_TMR,	ADC_Channel7 ,  P_COM0_BIS_P3_INT	,GCLK_CCL_NONE   }, // 
  { PORTB,  9, PIO_MULTI,P_COM0_BIS_P4_PER_ATTRIB,P_COM0_BIS_P4_PIN_ATTRIB,P_COM0_BIS_P4_TMR,	ADC_Channel4 ,  P_COM0_BIS_P4_INT	,GCLK_CCL_NONE  }, //  PER_ATTR_ADC_ALT
  { PORTB,  8, PIO_MULTI,P_COM0_BIS_P5_PER_ATTRIB,P_COM0_BIS_P5_PIN_ATTRIB,P_COM0_BIS_P5_TMR,	ADC_Channel5 ,  P_COM0_BIS_P5_INT	,GCLK_CCL_NONE  }, //  PER_ATTR_ADC_ALT

  // P_com1 0..5 - Digital pins
  //12..17
  { PORTA,  0, PIO_MULTI,	P_COM1_P0_PER_ATTRIB,	P_COM1_P0_PIN_ATTRIB,	P_COM1_P0_TMR, 	 No_ADC_Channel,  P_COM1_P0_INT	,GCLK_CCL_NONE  }, //  
  { PORTA,  1, PIO_MULTI,	P_COM1_P1_PER_ATTRIB,	P_COM1_P1_PIN_ATTRIB,	P_COM1_P1_TMR, 	 No_ADC_Channel,  P_COM1_P1_INT	,GCLK_CCL_NONE   }, //  
  { PORTA, 30, PIO_MULTI,	P_COM1_P2_PER_ATTRIB,	P_COM1_P2_PIN_ATTRIB,	P_COM1_P2_TMR, 	 No_ADC_Channel,  P_COM1_P2_INT	,GCLK_CCL_NONE  }, //  
  { PORTA, 31, PIO_MULTI,	P_COM1_P3_PER_ATTRIB,	P_COM1_P3_PIN_ATTRIB,	P_COM1_P3_TMR, 	 No_ADC_Channel,  P_COM1_P3_INT	,GCLK_CCL_NONE  }, // 
  { PORTB,  0, PIO_MULTI,	P_COM1_P4_PER_ATTRIB,	P_COM1_P4_PIN_ATTRIB,	P_COM1_P4_TMR, 	 ADC_Channel0,  P_COM1_P4_INT	,GCLK_CCL_NONE  }, //  PER_ATTR_ADC_ALT
  { PORTB,  1, PIO_MULTI,	P_COM1_P5_PER_ATTRIB,	P_COM1_P5_PIN_ATTRIB,	P_COM1_P5_TMR, 	 ADC_Channel1,  P_COM1_P5_INT	,GCLK_CCL_NONE  }, //  PER_ATTR_ADC_ALT
  
  // P_com2 0..5 - Digital pins
  //18..23
  { PORTA, 12, PIO_MULTI,	P_COM2_P0_PER_ATTRIB,	P_COM2_P0_PIN_ATTRIB,	P_COM2_P0_TMR, 	 No_ADC_Channel,  P_COM2_P0_INT	,GCLK_CCL_NONE }, //  
  { PORTA, 13, PIO_MULTI,	P_COM2_P1_PER_ATTRIB,	P_COM2_P1_PIN_ATTRIB,	P_COM2_P1_TMR, 	 No_ADC_Channel,  P_COM2_P1_INT	,GCLK_CCL_NONE  }, //  
  { PORTA, 14, PIO_MULTI,	P_COM2_P2_PER_ATTRIB,	P_COM2_P2_PIN_ATTRIB,	P_COM2_P2_TMR, 	 No_ADC_Channel,  P_COM2_P2_INT	,GCLK_CCL_NONE  }, //  
  { PORTA, 15, PIO_MULTI,	P_COM2_P3_PER_ATTRIB,	P_COM2_P3_PIN_ATTRIB,	P_COM2_P3_TMR, 	 No_ADC_Channel,  P_COM2_P3_INT	,GCLK_CCL_NONE  }, // 
  { PORTA, 17, PIO_MULTI,	P_COM2_P4_PER_ATTRIB,	P_COM2_P4_PIN_ATTRIB,	P_COM2_P4_TMR, 	 No_ADC_Channel,  P_COM2_P4_INT	,GCLK_CCL_NONE  }, //  
  { PORTA, 16, PIO_MULTI,	P_COM2_P5_PER_ATTRIB,	P_COM2_P5_PIN_ATTRIB,	P_COM2_P5_TMR, 	 No_ADC_Channel,  P_COM2_P5_INT	,GCLK_CCL_NONE  }, //  
  // P_com3 0..5 - Digital pins  
  //24..29
  { PORTA, 22, PIO_MULTI,	P_COM3_P0_PER_ATTRIB,	P_COM3_P0_PIN_ATTRIB,	P_COM3_P0_TMR, 	 No_ADC_Channel,  P_COM3_P0_INT	,GCLK_CCL_NONE  }, //  
  { PORTA, 23, PIO_MULTI,	P_COM3_P1_PER_ATTRIB,	P_COM3_P1_PIN_ATTRIB,	P_COM3_P1_TMR, 	 No_ADC_Channel,  P_COM3_P1_INT	,GCLK_CCL_NONE   }, //  
  { PORTA, 24, PIO_MULTI,	P_COM3_P2_PER_ATTRIB,	P_COM3_P2_PIN_ATTRIB,	P_COM3_P2_TMR, 	 No_ADC_Channel,  P_COM3_P2_INT	,GCLK_CCL_NONE  }, //  
  { PORTA, 25, PIO_MULTI,	P_COM3_P3_PER_ATTRIB,	P_COM3_P3_PIN_ATTRIB,	P_COM3_P3_TMR, 	 No_ADC_Channel,  P_COM3_P3_INT	,GCLK_CCL_NONE  }, // 
  { PORTA, 20, PIO_MULTI,	P_COM3_P4_PER_ATTRIB,	P_COM3_P4_PIN_ATTRIB,	P_COM3_P4_TMR, 	 No_ADC_Channel,  P_COM3_P4_INT	,GCLK_CCL_NONE  }, //  
  { PORTA, 19, PIO_MULTI,	P_COM3_P5_PER_ATTRIB,	P_COM3_P5_PIN_ATTRIB,	P_COM3_P5_TMR, 	 No_ADC_Channel,  P_COM3_P5_INT	,GCLK_CCL_NONE  }, //  
  // P_com4 0..6 - Digital pins
  //30..35
  { PORTB, 12, PIO_MULTI,	P_COM4_P0_PER_ATTRIB,	P_COM4_P0_PIN_ATTRIB,	P_COM4_P0_TMR, 	 No_ADC_Channel,  P_COM4_P0_INT	,GCLK_CCL_NONE  }, //  
  { PORTB, 13, PIO_MULTI,	P_COM4_P1_PER_ATTRIB,	P_COM4_P1_PIN_ATTRIB,	P_COM4_P1_TMR, 	 No_ADC_Channel,  P_COM4_P1_INT	,GCLK_CCL_NONE   }, //  
  { PORTB, 14, PIO_MULTI,	P_COM4_P2_PER_ATTRIB,	P_COM4_P2_PIN_ATTRIB,	P_COM4_P2_TMR, 	 No_ADC_Channel,  P_COM4_P2_INT	,GCLK_CCL_NONE  }, //  
  { PORTB, 15, PIO_MULTI,	P_COM4_P3_PER_ATTRIB,	P_COM4_P3_PIN_ATTRIB,	P_COM4_P3_TMR, 	 No_ADC_Channel,  P_COM4_P3_INT	,GCLK_CCL_NONE  }, // 
  { PORTB, 16, PIO_MULTI,	P_COM4_P4_PER_ATTRIB,	P_COM4_P4_PIN_ATTRIB,	P_COM4_P4_TMR, 	 No_ADC_Channel,  P_COM4_P4_INT	,GCLK_CCL_NONE  }, //  
  { PORTB, 17, PIO_MULTI,	P_COM4_P5_PER_ATTRIB,	P_COM4_P5_PIN_ATTRIB,	P_COM4_P5_TMR, 	 No_ADC_Channel,  P_COM4_P5_INT	,GCLK_CCL_NONE  }, //  
  // P_com5 0..6 - Digital pins
  //36..41
  { PORTB, 30, PIO_MULTI,	P_COM5_P0_PER_ATTRIB,	P_COM5_P0_PIN_ATTRIB,	P_COM5_P0_TMR, 	No_ADC_Channel,  P_COM5_P0_INT	,GCLK_CCL_NONE  }, //  
  { PORTB, 31, PIO_MULTI,	P_COM5_P1_PER_ATTRIB,	P_COM5_P1_PIN_ATTRIB,	P_COM5_P1_TMR, 	 No_ADC_Channel,  P_COM5_P1_INT	,GCLK_CCL_NONE   }, //  
  { PORTB, 22, PIO_MULTI,	P_COM5_P2_PER_ATTRIB,	P_COM5_P2_PIN_ATTRIB,	P_COM5_P2_TMR, 	 No_ADC_Channel,  P_COM5_P2_INT	,GCLK_CCL_NONE  }, //  
  { PORTB, 23, PIO_MULTI,	P_COM5_P3_PER_ATTRIB,	P_COM5_P3_PIN_ATTRIB,	P_COM5_P3_TMR, 	 No_ADC_Channel,  P_COM5_P3_INT	,GCLK_CCL_NONE  }, // 
  { PORTA, 27, PIO_MULTI,	P_COM5_P4_PER_ATTRIB,	P_COM5_P4_PIN_ATTRIB,	NOT_ON_TIMER, 	 No_ADC_Channel,  P_COM5_P4_INT	,GCLK_CCL_NONE  }, //  
  { PORTA, 28, PIO_MULTI,	P_COM5_P5_PER_ATTRIB,	P_COM5_P5_PIN_ATTRIB,	NOT_ON_TIMER, 	 No_ADC_Channel,  P_COM5_P5_INT	,GCLK_CCL_NONE  }, //  

  // CAN 42 43 
  { PORTB, 10, PIO_MULTI,PER_ATTR_DRIVE_STRONG, (PIN_ATTR_DIGITAL|PIN_ATTR_TIMER|PIN_ATTR_TIMER), TCC2_CH1,No_ADC_Channel,   EXTERNAL_INT_1	,GCLK_CCL_NONE  }, // TCC2/WO[1]
  { PORTB, 11, PIO_MULTI,PER_ATTR_DRIVE_STRONG, (PIN_ATTR_DIGITAL|PIN_ATTR_TIMER|PIN_ATTR_TIMER), TCC2_CH1,No_ADC_Channel,   EXTERNAL_INT_1	,GCLK_CCL_NONE  }, // TCC2/WO[1]

  // PANA1 42 43 - Analog pins
  // --------------------
  { PORTB,  6, PIO_ANALOG_ADC,PER_ATTR_DRIVE_STRONG, PIN_ATTR_ANALOG                               , NOT_ON_TIMER,ADC_Channel8,   EXTERNAL_INT_6	,GCLK_CCL_NONE  }, // PER_ATTR_ADC_ALTADC/AIN[0]
  { PORTB,  7, PIO_ANALOG_ADC,PER_ATTR_DRIVE_STRONG, PIN_ATTR_ANALOG| (PIN_ATTR_TIMER|PIN_ATTR_TIMER), NOT_ON_TIMER,ADC_Channel9,   EXTERNAL_INT_7	,GCLK_CCL_NONE  }, //PER_ATTR_ADC_ALT ADC/AIN[2]
 
  // PANA2 44 49 - Analog pins
  // ----------------------
  { PORTB,  2, PIO_ANALOG_ADC,PER_ATTR_DRIVE_STRONG, PIN_ATTR_ANALOG|PIN_ATTR_DIGITAL, NOT_ON_TIMER,ADC_Channel2,   EXTERNAL_INT_2	,GCLK_CCL_NONE  }, // PER_ATTR_ADC_ALT SDA: SERCOM3/PAD[0]
  { PORTB,  3, PIO_ANALOG_ADC,PER_ATTR_DRIVE_STRONG, PIN_ATTR_ANALOG|PIN_ATTR_DIGITAL, NOT_ON_TIMER,ADC_Channel3,   EXTERNAL_INT_3	,GCLK_CCL_NONE  }, //  PER_ATTR_ADC_ALT SCL: SERCOM3/PAD[1]
  { PORTA,  2, PIO_ANALOG_ADC,PER_ATTR_DRIVE_STRONG, PIN_ATTR_ANALOG|PIN_ATTR_DIGITAL, NOT_ON_TIMER,ADC_Channel10,   EXTERNAL_INT_2	,GCLK_CCL_NONE  }, // SDA: SERCOM3/PAD[0]
  { PORTA,  3, PIO_ANALOG_ADC,PER_ATTR_DRIVE_STRONG, PIN_ATTR_ANALOG|PIN_ATTR_DIGITAL, NOT_ON_TIMER, ADC_Channel11,   EXTERNAL_INT_3	,GCLK_CCL_NONE  }, // SCL: SERCOM3/PAD[1]
  { PORTB,  4, PIO_ANALOG_ADC,PER_ATTR_DRIVE_STRONG, PIN_ATTR_ANALOG|PIN_ATTR_DIGITAL, NOT_ON_TIMER,ADC_Channel6,   EXTERNAL_INT_4	,GCLK_CCL_NONE  }, // PER_ATTR_ADC_ALT  SDA: SERCOM3/PAD[0]
  { PORTB,  5, PIO_ANALOG_ADC,PER_ATTR_DRIVE_STRONG, PIN_ATTR_ANALOG|PIN_ATTR_DIGITAL, NOT_ON_TIMER,ADC_Channel7,   EXTERNAL_INT_5	,GCLK_CCL_NONE  }, // PER_ATTR_ADC_ALT  SCL: SERCOM3/PAD[1]

  
  // 42 (AREF)
  { PORTA, 3, PIO_ANALOG_ADC,PER_ATTR_DRIVE_STRONG, PIN_ATTR_ANALOG, NOT_ON_TIMER, No_ADC_Channel,   EXTERNAL_INT_NONE	,GCLK_CCL_NONE  }, // DAC/VREFP

  // ----------------------
  // 43 - Alternate use of A0 (DAC output)
  { PORTA,  2, PIO_ANALOG_ADC,PER_ATTR_DRIVE_STRONG, PIN_ATTR_ANALOG,  NOT_ON_TIMER,DAC_Channel0,  EXTERNAL_INT_2	,GCLK_CCL_NONE  }, // DAC/VOUT
} ;

const void* g_apTCInstances[TCC_INST_NUM+TC_INST_NUM]={ 
#if  !SAMD20_SERIES
TCC0,TCC1,TCC2, 
  #endif
TC0, TC1, TCC2, TC3, TC4, 
   #if !( SAMC_SERIES)
TC5,TC6,TC7,
  #endif

} ;



// Multi-serial objects instantiation
SERCOM sercom0( SERCOM0 ) ;
SERCOM sercom1( SERCOM1 ) ;
SERCOM sercom2( SERCOM2 ) ;
SERCOM sercom3( SERCOM3 ) ;
SERCOM sercom4( SERCOM4 ) ;
SERCOM sercom5( SERCOM5 ) ;


#if defined(ONE_UART) || defined(TWO_UART) || defined(THREE_UART) || defined(FOUR_UART) || defined(FIVE_UART) || defined(SIX_UART)
Uart Serial1( SERCOM_INSTANCE_SERIAL1, PIN_SERIAL1_RX, PIN_SERIAL1_TX, PAD_SERIAL1_RX, PAD_SERIAL1_TX ) ;

void SERCOM0_Handler()
{
  Serial1.IrqHandler();
}
#endif
#if defined(TWO_UART) || defined(THREE_UART) || defined(FOUR_UART) || defined(FIVE_UART) || defined(SIX_UART)
Uart Serial2( SERCOM_INSTANCE_SERIAL2, PIN_SERIAL2_RX, PIN_SERIAL2_TX, PAD_SERIAL2_RX, PAD_SERIAL2_TX ) ;

void SERCOM1_Handler()
{
  Serial2.IrqHandler();
}
#endif

#if defined(THREE_UART) || defined(FOUR_UART) || defined(FIVE_UART) || defined(SIX_UART)
Uart Serial3( SERCOM_INSTANCE_SERIAL3, PIN_SERIAL3_RX, PIN_SERIAL3_TX, PAD_SERIAL3_RX, PAD_SERIAL3_TX ) ;

void SERCOM2_Handler()
{
  Serial3.IrqHandler();
}
#endif

#if defined(FOUR_UART) || defined(FIVE_UART) || defined(SIX_UART)
Uart Serial4( SERCOM_INSTANCE_SERIAL4, PIN_SERIAL4_RX, PIN_SERIAL4_TX, PAD_SERIAL4_RX, PAD_SERIAL4_TX ) ;

void SERCOM3_Handler()
{
  Serial4.IrqHandler();
}
#endif
#if defined(FIVE_UART) || defined(SIX_UART)
Uart Serial5( SERCOM_INSTANCE_SERIAL5, PIN_SERIAL5_RX, PIN_SERIAL5_TX, PAD_SERIAL5_RX, PAD_SERIAL5_TX ) ;

void SERCOM4_Handler()
{
  Serial5.IrqHandler();
}
#endif

#if defined(SIX_UART)
Uart Serial6( SERCOM_INSTANCE_SERIAL6, PIN_SERIAL6_RX, PIN_SERIAL6_TX, PAD_SERIAL6_RX, PAD_SERIAL6_TX ) ;

void SERCOM5_Handler()
{
  Serial6.IrqHandler();
}
#endif

