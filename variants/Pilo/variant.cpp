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
 
const PinDescription g_APinDescription[NUM_PIN_DESCRIPTION_ENTRIES]=
{
//   ulPort        ;ulPin         ; ulPinType         ; ulPeripheralAttribute           ;      ulPinAttribute ;	     ulTCChannel ;	       ulADCChannelNumber ;	     ulExtInt ;	     ulGCLKCCL 
//{ PORTA,  0, PIO_MULTI, PER_ATTR_DRIVE_STRONG,  , NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_NONE, GCLK_CCL_NONE },
  // P_com0 0..5 - Digital pins
  // ----------------------
  // 0/1 - SERCOM/UART (Serial1)        
PA08_ARDUINO,
PA09_ARDUINO,
PA10_ARDUINO,
PA11_ARDUINO,
PA21_ARDUINO,
PA18_ARDUINO,
/*
  { (uint8_t) PORTA,(uint8_t)   8,(uint8_t)  PIO_MULTI,(uint8_t) 	P_COM0_P0_PER_ATTRIB,(uint32_t) 	P_COM0_P0_PIN_ATTRIB|PIN_ATTR_ADC,(uint8_t)	P_COM0_P0_TMR,(uint8_t) 	ADC_Channel8,(uint8_t) 	P_COM0_P0_INT	,(uint8_t)GCLK_CCL_NONE }, //  
  { (uint8_t) PORTA,(uint8_t)   9,(uint8_t)  PIO_MULTI,(uint8_t) 	P_COM0_P1_PER_ATTRIB,(uint32_t) 	P_COM0_P1_PIN_ATTRIB|PIN_ATTR_ADC,(uint8_t)	P_COM0_P1_TMR,(uint8_t) 	ADC_Channel9,(uint8_t)  	P_COM0_P1_INT	,(uint8_t)GCLK_CCL_NONE  }, //  
  { (uint8_t) PORTA,(uint8_t)  10,(uint8_t)  PIO_MULTI,(uint8_t) 	P_COM0_P2_PER_ATTRIB,(uint32_t) 	P_COM0_P2_PIN_ATTRIB|PIN_ATTR_ADC,(uint8_t)	P_COM0_P2_TMR,(uint8_t) 	ADC_Channel10,(uint8_t) 	P_COM0_P2_INT	,(uint8_t)GCLK_CCL_NONE }, //  
  { (uint8_t) PORTA,(uint8_t)  11,(uint8_t)  PIO_MULTI,(uint8_t) 	P_COM0_P3_PER_ATTRIB,(uint32_t) 	P_COM0_P3_PIN_ATTRIB|PIN_ATTR_ADC,(uint8_t)	P_COM0_P3_TMR,(uint8_t) 	ADC_Channel11,(uint8_t) 	P_COM0_P3_INT	,(uint8_t)GCLK_CCL_NONE }, // 
  { (uint8_t) PORTA,(uint8_t)  21,(uint8_t)  PIO_MULTI,(uint8_t) 	P_COM0_P4_PER_ATTRIB,(uint32_t) 	P_COM0_P4_PIN_ATTRIB,(uint8_t)	P_COM0_P4_TMR,(uint8_t) 	No_ADC_Channel,(uint8_t)  P_COM0_P4_INT	,(uint8_t)GCLK_CCL_NONE }, //  
  { (uint8_t) PORTA,(uint8_t)  18,(uint8_t)  PIO_MULTI,(uint8_t) 	P_COM0_P5_PER_ATTRIB,(uint32_t) 	P_COM0_P5_PIN_ATTRIB,(uint8_t)	P_COM0_P5_TMR,(uint8_t) 	No_ADC_Channel,(uint8_t)  P_COM0_P5_INT	,(uint8_t)GCLK_CCL_NONE }, //  
*/
  // P_com0_bis 0..5 - Digital pins
  //6..11
PA04_ARDUINO,
PA05_ARDUINO,
PA06_ARDUINO,
PA07_ARDUINO,
PB09_ARDUINO,
PB08_ARDUINO,
/*
  { (uint8_t) PORTA,(uint8_t)   4,(uint8_t)  PIO_MULTI,(uint8_t) P_COM0_BIS_P0_PER_ATTRIB|PER_ATTR_ADC_STD,(uint32_t) P_COM0_BIS_P0_PIN_ATTRIB|PIN_ATTR_ADC,(uint8_t)P_COM0_BIS_P0_TMR,(uint8_t)	ADC_Channel4 ,(uint8_t)  P_COM0_BIS_P0_INT	,(uint8_t)GCLK_CCL_NONE  }, //  
  { (uint8_t) PORTA,(uint8_t)   5,(uint8_t)  PIO_MULTI,(uint8_t) P_COM0_BIS_P1_PER_ATTRIB|PER_ATTR_ADC_STD,(uint32_t) P_COM0_BIS_P1_PIN_ATTRIB|PIN_ATTR_ADC,(uint8_t)P_COM0_BIS_P1_TMR,(uint8_t)	ADC_Channel5 ,(uint8_t)  P_COM0_BIS_P1_INT	,(uint8_t)GCLK_CCL_NONE   }, //  
  { (uint8_t) PORTA,(uint8_t)   6,(uint8_t)  PIO_MULTI,(uint8_t) P_COM0_BIS_P2_PER_ATTRIB|PER_ATTR_ADC_STD,(uint32_t) P_COM0_BIS_P2_PIN_ATTRIB|PIN_ATTR_ADC,(uint8_t)P_COM0_BIS_P2_TMR,(uint8_t)	ADC_Channel6 ,(uint8_t)  P_COM0_BIS_P2_INT	,(uint8_t)GCLK_CCL_NONE   }, //  
  { (uint8_t) PORTA,(uint8_t)   7,(uint8_t)  PIO_MULTI,(uint8_t) P_COM0_BIS_P3_PER_ATTRIB|PER_ATTR_ADC_STD,(uint32_t) P_COM0_BIS_P3_PIN_ATTRIB|PIN_ATTR_ADC,(uint8_t)P_COM0_BIS_P3_TMR,(uint8_t)	ADC_Channel7 ,(uint8_t)  P_COM0_BIS_P3_INT	,(uint8_t)GCLK_CCL_NONE   }, // 
  { (uint8_t) PORTB,(uint8_t)   9,(uint8_t)  PIO_MULTI,(uint8_t) P_COM0_BIS_P4_PER_ATTRIB|PER_ATTR_ADC_ALT,(uint32_t) P_COM0_BIS_P4_PIN_ATTRIB|PIN_ATTR_ADC,(uint8_t)P_COM0_BIS_P4_TMR,(uint8_t)	ADC_Channel5 ,(uint8_t)  P_COM0_BIS_P4_INT	,(uint8_t)GCLK_CCL_NONE  }, //  PER_ATTR_ADC_ALT
  { (uint8_t) PORTB,(uint8_t)   8,(uint8_t)  PIO_MULTI,(uint8_t) P_COM0_BIS_P5_PER_ATTRIB|PER_ATTR_ADC_ALT,(uint32_t) P_COM0_BIS_P5_PIN_ATTRIB|PIN_ATTR_ADC,(uint8_t)P_COM0_BIS_P5_TMR,(uint8_t)	ADC_Channel4 ,(uint8_t)  P_COM0_BIS_P5_INT	,(uint8_t)GCLK_CCL_NONE  }, //  PER_ATTR_ADC_ALT
*/
  // P_com1 0..5 - Digital pins
  //12..17
PA00_ARDUINO,
PA01_ARDUINO,
PA30_ARDUINO,
PA31_ARDUINO,
PB00_ARDUINO,
PB01_ARDUINO,
  /*
  { (uint8_t) PORTA,(uint8_t)   0,(uint8_t)  PIO_MULTI,(uint8_t) 	P_COM1_P0_PER_ATTRIB,(uint32_t) 	P_COM1_P0_PIN_ATTRIB,(uint8_t)	P_COM1_P0_TMR, (uint8_t)	 No_ADC_Channel,(uint8_t)  P_COM1_P0_INT	,(uint8_t)GCLK_CCL_NONE  }, //  
  { (uint8_t) PORTA,(uint8_t)   1,(uint8_t)  PIO_MULTI,(uint8_t) 	P_COM1_P1_PER_ATTRIB,(uint32_t) 	P_COM1_P1_PIN_ATTRIB,(uint8_t)	P_COM1_P1_TMR, (uint8_t)	 No_ADC_Channel,(uint8_t)  P_COM1_P1_INT	,(uint8_t)GCLK_CCL_NONE   }, //  
  { (uint8_t) PORTA,(uint8_t)  30,(uint8_t)  PIO_MULTI,(uint8_t) 	P_COM1_P2_PER_ATTRIB,(uint32_t) 	P_COM1_P2_PIN_ATTRIB,(uint8_t)	P_COM1_P2_TMR,(uint8_t) 	 No_ADC_Channel, (uint8_t) P_COM1_P2_INT	,(uint8_t)GCLK_CCL_NONE  }, //  
  { (uint8_t) PORTA,(uint8_t)  31,(uint8_t)  PIO_MULTI,(uint8_t) 	P_COM1_P3_PER_ATTRIB,(uint32_t) 	P_COM1_P3_PIN_ATTRIB,(uint8_t)	P_COM1_P3_TMR,(uint8_t) 	 No_ADC_Channel, (uint8_t) P_COM1_P3_INT	,(uint8_t)GCLK_CCL_NONE  }, // 
  { (uint8_t) PORTB,(uint8_t)   0,(uint8_t)  PIO_MULTI,(uint8_t) 	P_COM1_P4_PER_ATTRIB|PER_ATTR_ADC_ALT,(uint32_t) 	P_COM1_P4_PIN_ATTRIB|PIN_ATTR_ADC,(uint8_t)	P_COM1_P4_TMR,(uint8_t) 	 ADC_Channel0, (uint8_t) P_COM1_P4_INT	,(uint8_t)GCLK_CCL_NONE  }, //  PER_ATTR_ADC_ALT
  { (uint8_t) PORTB,(uint8_t)   1,(uint8_t)  PIO_MULTI,(uint8_t) 	P_COM1_P5_PER_ATTRIB|PER_ATTR_ADC_ALT,(uint32_t) 	P_COM1_P5_PIN_ATTRIB|PIN_ATTR_ADC,(uint8_t)	P_COM1_P5_TMR,(uint8_t) 	 ADC_Channel1, (uint8_t) P_COM1_P5_INT	,(uint8_t)GCLK_CCL_NONE  }, //  PER_ATTR_ADC_ALT
*/
  // P_com2 0..5 - Digital pins
  //18..23
  PA12_ARDUINO,
PA13_ARDUINO,
PA14_ARDUINO,
PA15_ARDUINO,
PA17_ARDUINO,
PA16_ARDUINO,
/*
  { (uint8_t) PORTA,(uint8_t)  12,(uint8_t)  PIO_MULTI,(uint8_t) 	P_COM2_P0_PER_ATTRIB,(uint32_t) 	P_COM2_P0_PIN_ATTRIB,(uint8_t)	P_COM2_P0_TMR,(uint8_t) 	 No_ADC_Channel,(uint8_t)  P_COM2_P0_INT	,(uint8_t)GCLK_CCL_NONE }, //  
  { (uint8_t) PORTA,(uint8_t)  13,(uint8_t)  PIO_MULTI,(uint8_t) 	P_COM2_P1_PER_ATTRIB,(uint32_t) 	P_COM2_P1_PIN_ATTRIB,(uint8_t)	P_COM2_P1_TMR,(uint8_t) 	 No_ADC_Channel,(uint8_t)  P_COM2_P1_INT	,(uint8_t)GCLK_CCL_NONE  }, //  
  { (uint8_t) PORTA,(uint8_t)  14,(uint8_t)  PIO_MULTI,(uint8_t) 	P_COM2_P2_PER_ATTRIB,(uint32_t) 	P_COM2_P2_PIN_ATTRIB,(uint8_t)	P_COM2_P2_TMR,(uint8_t) 	 No_ADC_Channel,(uint8_t)  P_COM2_P2_INT	,(uint8_t)GCLK_CCL_NONE  }, //  
  { (uint8_t) PORTA,(uint8_t)  15,(uint8_t)  PIO_MULTI,(uint8_t) 	P_COM2_P3_PER_ATTRIB,(uint32_t) 	P_COM2_P3_PIN_ATTRIB,(uint8_t)	P_COM2_P3_TMR,(uint8_t) 	 No_ADC_Channel,(uint8_t)  P_COM2_P3_INT	,(uint8_t)GCLK_CCL_NONE  }, // 
  { (uint8_t) PORTA,(uint8_t)  17,(uint8_t)  PIO_MULTI,(uint8_t) 	P_COM2_P4_PER_ATTRIB,(uint32_t) 	P_COM2_P4_PIN_ATTRIB,(uint8_t)	P_COM2_P4_TMR,(uint8_t) 	 No_ADC_Channel,(uint8_t)  P_COM2_P4_INT	,(uint8_t)GCLK_CCL_NONE  }, //  
  { (uint8_t) PORTA,(uint8_t)  16,(uint8_t)  PIO_MULTI,(uint8_t) 	P_COM2_P5_PER_ATTRIB,(uint32_t) 	P_COM2_P5_PIN_ATTRIB,(uint8_t)	P_COM2_P5_TMR,(uint8_t) 	 No_ADC_Channel,(uint8_t)  P_COM2_P5_INT	,(uint8_t)GCLK_CCL_NONE  }, //  
  */
  // P_com3 0..5 - Digital pins  
  //24..29
  PA22_ARDUINO,
PA23_ARDUINO,
PA24_ARDUINO,
PA25_ARDUINO,
PA20_ARDUINO,
PA19_ARDUINO,
/*
  { (uint8_t) PORTA,(uint8_t)  22,(uint8_t)  PIO_MULTI,(uint8_t) 	P_COM3_P0_PER_ATTRIB,(uint32_t) 	P_COM3_P0_PIN_ATTRIB,(uint8_t)	P_COM3_P0_TMR,(uint8_t) 	 No_ADC_Channel,(uint8_t)  P_COM3_P0_INT	,(uint8_t)GCLK_CCL_NONE  }, //  
  { (uint8_t) PORTA,(uint8_t)  23,(uint8_t)  PIO_MULTI,(uint8_t) 	P_COM3_P1_PER_ATTRIB,(uint32_t) 	P_COM3_P1_PIN_ATTRIB,(uint8_t)	P_COM3_P1_TMR,(uint8_t) 	 No_ADC_Channel,(uint8_t)  P_COM3_P1_INT	,(uint8_t)GCLK_CCL_NONE   }, //  
  { (uint8_t) PORTA,(uint8_t)  24,(uint8_t)  PIO_MULTI,(uint8_t) 	P_COM3_P2_PER_ATTRIB,(uint32_t) 	P_COM3_P2_PIN_ATTRIB,(uint8_t)	P_COM3_P2_TMR,(uint8_t) 	 No_ADC_Channel,(uint8_t)  P_COM3_P2_INT	,(uint8_t)GCLK_CCL_NONE  }, //  
  { (uint8_t) PORTA,(uint8_t)  25,(uint8_t)  PIO_MULTI,(uint8_t) 	P_COM3_P3_PER_ATTRIB,(uint32_t) 	P_COM3_P3_PIN_ATTRIB,(uint8_t)	P_COM3_P3_TMR,(uint8_t) 	 No_ADC_Channel,(uint8_t)  P_COM3_P3_INT	,(uint8_t)GCLK_CCL_NONE  }, // 
  { (uint8_t) PORTA,(uint8_t)  20,(uint8_t)  PIO_MULTI,(uint8_t) 	P_COM3_P4_PER_ATTRIB,(uint32_t) 	P_COM3_P4_PIN_ATTRIB,(uint8_t)	P_COM3_P4_TMR,(uint8_t) 	 No_ADC_Channel,(uint8_t)  P_COM3_P4_INT	,(uint8_t)GCLK_CCL_NONE  }, //  
  { (uint8_t) PORTA,(uint8_t)  19,(uint8_t)  PIO_MULTI,(uint8_t) 	P_COM3_P5_PER_ATTRIB,(uint32_t) 	P_COM3_P5_PIN_ATTRIB,(uint8_t)	P_COM3_P5_TMR,(uint8_t) 	 No_ADC_Channel,(uint8_t)  P_COM3_P5_INT	,(uint8_t)GCLK_CCL_NONE  }, //  
 */
 // P_com4 0..6 - Digital pins
  //30..35
  PB12_ARDUINO,
PB13_ARDUINO,
PB14_ARDUINO,
PB15_ARDUINO,
PB16_ARDUINO,
PB17_ARDUINO,
/*
  { (uint8_t) PORTB,(uint8_t)  12,(uint8_t)  PIO_MULTI,(uint8_t) 	P_COM4_P0_PER_ATTRIB,(uint32_t) 	P_COM4_P0_PIN_ATTRIB,(uint8_t)	P_COM4_P0_TMR,(uint8_t) 	 No_ADC_Channel,(uint8_t)  P_COM4_P0_INT	,(uint8_t)GCLK_CCL_NONE  }, //  
  { (uint8_t) PORTB,(uint8_t)  13,(uint8_t)  PIO_MULTI,(uint8_t) 	P_COM4_P1_PER_ATTRIB,(uint32_t) 	P_COM4_P1_PIN_ATTRIB,(uint8_t)	P_COM4_P1_TMR,(uint8_t) 	 No_ADC_Channel,(uint8_t)  P_COM4_P1_INT	,(uint8_t)GCLK_CCL_NONE   }, //  
  { (uint8_t) PORTB,(uint8_t)  14,(uint8_t)  PIO_MULTI,(uint8_t) 	P_COM4_P2_PER_ATTRIB,(uint32_t) 	P_COM4_P2_PIN_ATTRIB,(uint8_t)	P_COM4_P2_TMR,(uint8_t) 	 No_ADC_Channel,(uint8_t)  P_COM4_P2_INT	,(uint8_t)GCLK_CCL_NONE  }, //  
  { (uint8_t) PORTB,(uint8_t)  15,(uint8_t)  PIO_MULTI,(uint8_t) 	P_COM4_P3_PER_ATTRIB,(uint32_t) 	P_COM4_P3_PIN_ATTRIB,(uint8_t)	P_COM4_P3_TMR,(uint8_t) 	 No_ADC_Channel,(uint8_t)  P_COM4_P3_INT	,(uint8_t)GCLK_CCL_NONE  }, // 
  { (uint8_t) PORTB,(uint8_t)  16,(uint8_t)  PIO_MULTI,(uint8_t) 	P_COM4_P4_PER_ATTRIB,(uint32_t) 	P_COM4_P4_PIN_ATTRIB,(uint8_t)	P_COM4_P4_TMR,(uint8_t) 	 No_ADC_Channel,(uint8_t)  P_COM4_P4_INT	,(uint8_t)GCLK_CCL_NONE  }, //  
  { (uint8_t) PORTB,(uint8_t)  17,(uint8_t)  PIO_MULTI,(uint8_t) 	P_COM4_P5_PER_ATTRIB,(uint32_t) 	P_COM4_P5_PIN_ATTRIB,(uint8_t)	P_COM4_P5_TMR,(uint8_t) 	 No_ADC_Channel,(uint8_t)  P_COM4_P5_INT	,(uint8_t)GCLK_CCL_NONE  }, //  
  */
//  P_com5 0..6 - Digital pins
  //36..41
  PB30_ARDUINO,
PB31_ARDUINO,
PB22_ARDUINO,
PB23_ARDUINO,
PA27_ARDUINO,
PA28_ARDUINO,
/*
  { (uint8_t) PORTB,(uint8_t)  30,(uint8_t)  PIO_MULTI,(uint8_t) 	P_COM5_P0_PER_ATTRIB,(uint32_t) 	P_COM5_P0_PIN_ATTRIB,(uint8_t)	P_COM5_P0_TMR,(uint8_t) 	No_ADC_Channel,(uint8_t)  P_COM5_P0_INT	,(uint8_t)GCLK_CCL_NONE  }, //  
  { (uint8_t) PORTB,(uint8_t)  31,(uint8_t)  PIO_MULTI,(uint8_t) 	P_COM5_P1_PER_ATTRIB,(uint32_t) 	P_COM5_P1_PIN_ATTRIB,(uint8_t)	P_COM5_P1_TMR,(uint8_t) 	 No_ADC_Channel,(uint8_t)  P_COM5_P1_INT	,(uint8_t)GCLK_CCL_NONE   }, //  
  { (uint8_t) PORTB,(uint8_t)  22,(uint8_t)  PIO_MULTI,(uint8_t) 	P_COM5_P2_PER_ATTRIB,(uint32_t) 	P_COM5_P2_PIN_ATTRIB,(uint8_t)	P_COM5_P2_TMR,(uint8_t) 	 No_ADC_Channel,(uint8_t)  P_COM5_P2_INT	,(uint8_t)GCLK_CCL_NONE  }, //  
  { (uint8_t) PORTB,(uint8_t)  23,(uint8_t)  PIO_MULTI,(uint8_t) 	P_COM5_P3_PER_ATTRIB,(uint32_t) 	P_COM5_P3_PIN_ATTRIB,(uint8_t)	P_COM5_P3_TMR,(uint8_t) 	 No_ADC_Channel,(uint8_t)  P_COM5_P3_INT	,(uint8_t)GCLK_CCL_NONE  }, // 
  { (uint8_t) PORTA,(uint8_t)  27,(uint8_t)  PIO_MULTI,(uint8_t) 	P_COM5_P4_PER_ATTRIB,(uint32_t) 	P_COM5_P4_PIN_ATTRIB,(uint8_t)	NOT_ON_TIMER,(uint8_t) 	 No_ADC_Channel,(uint8_t)  P_COM5_P4_INT	,(uint8_t)GCLK_CCL_NONE  }, //  
  { (uint8_t) PORTA,(uint8_t)  28,(uint8_t)  PIO_MULTI,(uint8_t) 	P_COM5_P5_PER_ATTRIB,(uint32_t) 	P_COM5_P5_PIN_ATTRIB,(uint8_t)	NOT_ON_TIMER,(uint8_t) 	 No_ADC_Channel,(uint8_t)  P_COM5_P5_INT	,(uint8_t)GCLK_CCL_NONE  }, //  
*/
  // CAN 42 43 
  PB10_ARDUINO,
  PB11_ARDUINO,
 /* { (uint8_t) PORTB,(uint8_t)  10,(uint8_t)  PIO_MULTI,(uint8_t) PER_ATTR_DRIVE_STRONG,(uint32_t)  (PIN_ATTR_DIGITAL|PIN_ATTR_TIMER|PIN_ATTR_TIMER),(uint8_t) TCC2_CH1,(uint8_t)No_ADC_Channel,(uint8_t)   EXTERNAL_INT_1	,(uint8_t)GCLK_CCL_NONE  }, // TCC2/WO[1]
  { (uint8_t) PORTB,(uint8_t)  11,(uint8_t)  PIO_MULTI,(uint8_t) PER_ATTR_DRIVE_STRONG,(uint32_t)  (PIN_ATTR_DIGITAL|PIN_ATTR_TIMER|PIN_ATTR_TIMER),(uint8_t) TCC2_CH1,(uint8_t)No_ADC_Channel,(uint8_t)   EXTERNAL_INT_1	,(uint8_t)GCLK_CCL_NONE  }, // TCC2/WO[1]
*/
  // PANA1 44 45 - Analog pins
  // --------------------
/*  { (uint8_t) PORTB,(uint8_t)   6,(uint8_t)  PIO_MULTI,(uint8_t) PER_ATTR_DRIVE_STRONG|PER_ATTR_ADC_ALT,(uint32_t)  PIN_ATTR_EXTINT |PIN_ATTR_ANALOG |PIN_ATTR_DIGITAL|PIN_ATTR_ADC,(uint8_t) NOT_ON_TIMER,(uint8_t)ADC_Channel8,(uint8_t)   EXTERNAL_INT_6	,(uint8_t)GCLK_CCL_NONE  }, // PER_ATTR_ADC_ALTADC/AIN[0]
  { (uint8_t) PORTB,(uint8_t)   7,(uint8_t)  PIO_MULTI,(uint8_t) PER_ATTR_DRIVE_STRONG|PER_ATTR_ADC_ALT,(uint32_t)  PIN_ATTR_EXTINT |PIN_ATTR_ANALOG|PIN_ATTR_DIGITAL|PIN_ATTR_ADC,(uint8_t) NOT_ON_TIMER,(uint8_t)ADC_Channel9,(uint8_t)   EXTERNAL_INT_7	,(uint8_t)GCLK_CCL_NONE  }, //PER_ATTR_ADC_ALT ADC/AIN[2]
  */
  PB06_ARDUINO,
  PB07_ARDUINO,
 //  { (uint8_t) PORTB,(uint8_t)   9,(uint8_t)  PIO_MULTI,(uint8_t) P_COM0_BIS_P4_PER_ATTRIB,(uint32_t) P_COM0_BIS_P4_PIN_ATTRIB,(uint8_t)P_COM0_BIS_P4_TMR,(uint8_t)	ADC_Channel4 ,(uint8_t)  P_COM0_BIS_P4_INT	,(uint8_t)GCLK_CCL_NONE  }, //  PER_ATTR_ADC_ALT
 // { (uint8_t) PORTB,(uint8_t)   8,(uint8_t)  PIO_MULTI,(uint8_t) P_COM0_BIS_P5_PER_ATTRIB,(uint32_t) P_COM0_BIS_P5_PIN_ATTRIB,(uint8_t)P_COM0_BIS_P5_TMR,(uint8_t)	ADC_Channel5 ,(uint8_t)  P_COM0_BIS_P5_INT	,(uint8_t)GCLK_CCL_NONE  }, //  PER_ATTR_ADC_ALT
//  { (uint8_t) PORTA,(uint8_t)   4,(uint8_t)  PIO_MULTI,(uint8_t) P_COM0_BIS_P0_PER_ATTRIB,(uint32_t) P_COM0_BIS_P0_PIN_ATTRIB,(uint8_t)P_COM0_BIS_P0_TMR,(uint8_t)	ADC_Channel4 ,(uint8_t)  P_COM0_BIS_P0_INT	,(uint8_t)GCLK_CCL_NONE  }, //  
//  { (uint8_t) PORTA,(uint8_t)   5,(uint8_t)  PIO_MULTI,(uint8_t) P_COM0_BIS_P1_PER_ATTRIB,(uint32_t) P_COM0_BIS_P1_PIN_ATTRIB,(uint8_t)P_COM0_BIS_P1_TMR,(uint8_t)	ADC_Channel5 ,(uint8_t)  P_COM0_BIS_P1_INT	,(uint8_t)GCLK_CCL_NONE   }, //  
//  { (uint8_t) PORTA,(uint8_t)   6,(uint8_t)  PIO_MULTI,(uint8_t) P_COM0_BIS_P2_PER_ATTRIB,(uint32_t) P_COM0_BIS_P2_PIN_ATTRIB,(uint8_t)P_COM0_BIS_P2_TMR,(uint8_t)	ADC_Channel6 ,(uint8_t)  P_COM0_BIS_P2_INT	,(uint8_t)GCLK_CCL_NONE   }, //  
//  { (uint8_t) PORTA,(uint8_t)   7,(uint8_t)  PIO_MULTI,(uint8_t) P_COM0_BIS_P3_PER_ATTRIB,(uint32_t) P_COM0_BIS_P3_PIN_ATTRIB,(uint8_t)P_COM0_BIS_P3_TMR,(uint8_t)	ADC_Channel7 ,(uint8_t)  P_COM0_BIS_P3_INT	,(uint8_t)GCLK_CCL_NONE   }, // 

  // PANA2 46 51 - Analog pins
  // ----------------------
 // { (uint8_t) PORTB,(uint8_t)   0,(uint8_t)  PIO_ANALOG_ADC,(uint8_t) PER_ATTR_DRIVE_STRONG,(uint32_t)  PIN_ATTR_ANALOG|PIN_ATTR_DIGITAL,(uint8_t) NOT_ON_TIMER,(uint8_t)ADC_Channel2,(uint8_t)   EXTERNAL_INT_2	,(uint8_t)GCLK_CCL_NONE  }, // PER_ATTR_ADC_ALT SDA: SERCOM3/PAD[0]
  //{ (uint8_t) PORTB,(uint8_t)   1,(uint8_t)  PIO_ANALOG_ADC,(uint8_t) PER_ATTR_DRIVE_STRONG,(uint32_t)  PIN_ATTR_ANALOG|PIN_ATTR_DIGITAL,(uint8_t) NOT_ON_TIMER,(uint8_t)ADC_Channel2,(uint8_t)   EXTERNAL_INT_2	,(uint8_t)GCLK_CCL_NONE  }, // PER_ATTR_ADC_ALT SDA: SERCOM3/PAD[0]
  PB02_ARDUINO,
  PB03_ARDUINO,
  PA02_ARDUINO,
  PA03_ARDUINO,
  PB04_ARDUINO,
  PB05_ARDUINO,
/*  { (uint8_t) PORTB,(uint8_t)   2,(uint8_t)  PIO_MULTI,(uint8_t) PER_ATTR_DRIVE_STRONG|PER_ATTR_ADC_ALT,(uint32_t)  PIN_ATTR_EXTINT |PIN_ATTR_ANALOG|PIN_ATTR_DIGITAL|PIN_ATTR_ADC,(uint8_t) NOT_ON_TIMER,(uint8_t)ADC_Channel2,(uint8_t)   EXTERNAL_INT_2	,(uint8_t)GCLK_CCL_NONE  }, // PER_ATTR_ADC_ALT SDA: SERCOM3/PAD[0]
  { (uint8_t) PORTB,(uint8_t)   3,(uint8_t)  PIO_MULTI,(uint8_t) PER_ATTR_DRIVE_STRONG|PER_ATTR_ADC_ALT,(uint32_t)  PIN_ATTR_EXTINT |PIN_ATTR_ANALOG|PIN_ATTR_DIGITAL|PIN_ATTR_ADC,(uint8_t) NOT_ON_TIMER,(uint8_t)ADC_Channel3,(uint8_t)   EXTERNAL_INT_3	,(uint8_t)GCLK_CCL_NONE  }, //  PER_ATTR_ADC_ALT SCL: SERCOM3/PAD[1]
  { (uint8_t) PORTA,(uint8_t)   2,(uint8_t)  PIO_MULTI,(uint8_t) PER_ATTR_DRIVE_STRONG|PER_ATTR_ADC_STD,(uint32_t)  PIN_ATTR_EXTINT |PIN_ATTR_ANALOG|PIN_ATTR_DIGITAL|PIN_ATTR_ADC,(uint8_t) NOT_ON_TIMER,(uint8_t)ADC_Channel0,(uint8_t)  EXTERNAL_INT_2	,(uint8_t)GCLK_CCL_NONE  }, // SDA: SERCOM3/PAD[0]
  { (uint8_t) PORTA,(uint8_t)   3,(uint8_t)  PIO_MULTI,(uint8_t) PER_ATTR_DRIVE_STRONG|PER_ATTR_ADC_STD,(uint32_t)  PIN_ATTR_EXTINT |PIN_ATTR_ANALOG|PIN_ATTR_DIGITAL|PIN_ATTR_ADC,(uint8_t) NOT_ON_TIMER,(uint8_t)ADC_Channel1,(uint8_t)  EXTERNAL_INT_3	,(uint8_t)GCLK_CCL_NONE  }, // SCL: SERCOM3/PAD[1]
  { (uint8_t) PORTB,(uint8_t)   4,(uint8_t)  PIO_MULTI,(uint8_t) PER_ATTR_DRIVE_STRONG|PER_ATTR_ADC_ALT,(uint32_t)  PIN_ATTR_EXTINT |PIN_ATTR_ANALOG|PIN_ATTR_DIGITAL|PIN_ATTR_ADC,(uint8_t) NOT_ON_TIMER,(uint8_t)ADC_Channel6,(uint8_t)   EXTERNAL_INT_4	,(uint8_t)GCLK_CCL_NONE  }, // PER_ATTR_ADC_ALT  SDA: SERCOM3/PAD[0]
  { (uint8_t) PORTB,(uint8_t)   5,(uint8_t)  PIO_MULTI,(uint8_t) PER_ATTR_DRIVE_STRONG|PER_ATTR_ADC_ALT,(uint32_t)  PIN_ATTR_EXTINT |PIN_ATTR_ANALOG|PIN_ATTR_DIGITAL|PIN_ATTR_ADC,(uint8_t) NOT_ON_TIMER,(uint8_t)ADC_Channel7,(uint8_t)   EXTERNAL_INT_5	,(uint8_t)GCLK_CCL_NONE  }, // PER_ATTR_ADC_ALT  SCL: SERCOM3/PAD[1]
*/
  
  //  (AREF)
 // { (uint8_t) PORTA,(uint8_t)   3,(uint8_t)  PIO_ANALOG_ADC,(uint8_t) PER_ATTR_DRIVE_STRONG,(uint32_t)  PIN_ATTR_ANALOG,(uint8_t) NOT_ON_TIMER,(uint8_t) No_ADC_Channel,(uint8_t)   EXTERNAL_INT_NONE	,(uint8_t)GCLK_CCL_NONE  }, // DAC/VREFP

  // ----------------------
  // 43 - Alternate use of A0 (DAC output)
//  { (uint8_t) PORTA,(uint8_t)   2,(uint8_t)  PIO_ANALOG_ADC,(uint8_t) PER_ATTR_DRIVE_STRONG,(uint32_t)  PIN_ATTR_ANALOG,(uint8_t)  NOT_ON_TIMER,(uint8_t)DAC_Channel0,(uint8_t)  EXTERNAL_INT_2	,(uint8_t)GCLK_CCL_NONE  }, // DAC/VOUT
} ;
/*
#if (NUM_PIN_DESCRIPTION_ENTRIES!=(sizeof(g_APinDescription)/sizeof(PinDescription)))
	#error bad size
#endif*/

const void* g_apTCInstances[TCC_INST_NUM+TC_INST_NUM]={ 
#if  !SAMD20_SERIES
TCC0,TCC1,TCC2, 
  #endif
#if  !SAMD21_SERIES
TC0, TC1,
#endif
#if  ((!SAMD20_SERIES) && (!SAMD21_SERIES ))
TC2,
  #endif
  TC3, TC4, 
   #if defined(TC5)
TC5,
  #endif
     #if defined(TC6)
TC6,
  #endif
     #if defined(TC7)
TC7,
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
Uart Serial0( SERCOM_INSTANCE_SERIAL0, (uint8_t)PIN_SERIAL0_RX, (uint8_t)PIN_SERIAL0_TX, PAD_SERIAL0_RX, PAD_SERIAL0_TX ) ;
Uart Serial0B( SERCOM_INSTANCE_SERIAL_B0,(uint8_t) PIN_SERIAL_B0_RX, (uint8_t)PIN_SERIAL_B0_TX, PAD_SERIAL_B0_RX, PAD_SERIAL_B0_TX ) ;

void WIRE0_IT_HANDLER();
void WIRE0_BIS_IT_HANDLER();
void WIRE1_IT_HANDLER();
void WIRE2_IT_HANDLER();
void WIRE3_IT_HANDLER();
void WIRE4_IT_HANDLER();
void WIRE5_IT_HANDLER();

  extern TwoWire Wire0;
  extern TwoWire Wire1;
  extern TwoWire Wire2;
  extern TwoWire Wire3;
  extern TwoWire Wire4;
  extern TwoWire Wire5;
extern "C"
{
void SERCOM0_Handler()
{
  if (Serial0.isIrq()) 
      Serial0.IrqHandler();
  else
	   if (Serial0B.isIrq()) 
      Serial0B.IrqHandler();
  else
	  if (Wire0.isIrq()) 
      WIRE0_IT_HANDLER();
  if (Serial0_BIS.isIrq()) 
      Serial0_BIS.IrqHandler();
  else if (Serial0_BIS_B.isIrq()) 
      Serial0_BIS_B.IrqHandler();
  else
	  if (Wire0_BIS.isIrq()) 
      WIRE0_BIS_IT_HANDLER();
}
}// extern "C" {
#endif
#if defined(TWO_UART) || defined(THREE_UART) || defined(FOUR_UART) || defined(FIVE_UART) || defined(SIX_UART)
/*
#if defined(BOARD_ID_engi)
#define	PIN_SERIAL1_TX	(18ul)		
#define	PIN_SERIAL1_RX	(19ul)	
#else
#define	PIN_SERIAL1_TX	(00ul)		
#define	PIN_SERIAL1_RX	(01ul)	
Uart Serial1( SERCOM_INSTANCE_SERIAL1, (uint8_t)PIN_SERIAL1_RX, (uint8_t)PIN_SERIAL1_TX, PAD_SERIAL1_RX, PAD_SERIAL1_TX ) ;	
#endif
*/
#if defined(BOARD_ID_engi)
Uart SerialFTDI( SERCOM_INSTANCE_SERIAL1, (uint8_t)5, (uint8_t)29, SERCOM_RX_PAD_3, UART_TX_PAD_2 ) ;
#endif
Uart Serial1( SERCOM_INSTANCE_SERIAL1, (uint8_t)PIN_SERIAL1_RX, (uint8_t)PIN_SERIAL1_TX, PAD_SERIAL1_RX, PAD_SERIAL1_TX ) ;	

Uart Serial1B( SERCOM_INSTANCE_SERIAL_B1,(uint8_t) PIN_SERIAL_B1_RX, (uint8_t)PIN_SERIAL_B1_TX, PAD_SERIAL_B1_RX, PAD_SERIAL_B1_TX ) ;
extern "C"
{
void SERCOM1_Handler()
{
  if (Serial1.isIrq()) 
      Serial1.IrqHandler();
   else  if (Serial1B.isIrq()) 
      Serial1B.IrqHandler();
     #if defined(BOARD_ID_engi)
    else if (SerialFTDI.isIrq()) 
      SerialFTDI.IrqHandler();
#endif
  else
      WIRE1_IT_HANDLER();

}}// extern "C" {
#endif

#if defined(THREE_UART) || defined(FOUR_UART) || defined(FIVE_UART) || defined(SIX_UART)
Uart Serial2( SERCOM_INSTANCE_SERIAL2, (uint8_t)PIN_SERIAL2_RX, (uint8_t)PIN_SERIAL2_TX, PAD_SERIAL2_RX, PAD_SERIAL2_TX ) ;
Uart Serial2B( SERCOM_INSTANCE_SERIAL_B2,(uint8_t) PIN_SERIAL_B2_RX, (uint8_t)PIN_SERIAL_B2_TX, PAD_SERIAL_B2_RX, PAD_SERIAL_B2_TX ) ;
extern "C"
{
void SERCOM2_Handler()
{
  if (Serial2.isIrq()) 
      Serial2.IrqHandler();
   else  if (Serial2B.isIrq()) 
      Serial2B.IrqHandler();
  else
      WIRE2_IT_HANDLER();
}}// extern "C" {
#endif

#if defined(FOUR_UART) || defined(FIVE_UART) || defined(SIX_UART)
Uart Serial3( SERCOM_INSTANCE_SERIAL3, (uint8_t)PIN_SERIAL3_RX, (uint8_t)PIN_SERIAL3_TX, PAD_SERIAL3_RX, PAD_SERIAL3_TX ) ;
Uart Serial3B( SERCOM_INSTANCE_SERIAL_B3,(uint8_t) PIN_SERIAL_B3_RX, (uint8_t)PIN_SERIAL_B3_TX, PAD_SERIAL_B3_RX, PAD_SERIAL_B3_TX ) ;
extern "C"
{
void SERCOM3_Handler()
{
  if (Serial3.isIrq()) 
      Serial3.IrqHandler();
  else  if (Serial3B.isIrq()) 
      Serial3B.IrqHandler();
  else
      WIRE3_IT_HANDLER();
}}// extern "C" {
#endif
#if defined(FIVE_UART) || defined(SIX_UART)
Uart Serial4( SERCOM_INSTANCE_SERIAL4, (uint8_t)PIN_SERIAL4_RX, (uint8_t)PIN_SERIAL4_TX, PAD_SERIAL4_RX, PAD_SERIAL4_TX ) ;
Uart Serial4B( SERCOM_INSTANCE_SERIAL_B4,(uint8_t) PIN_SERIAL_B4_RX, (uint8_t)PIN_SERIAL_B4_TX, PAD_SERIAL_B4_RX, PAD_SERIAL_B4_TX ) ;
extern "C"
{
void SERCOM4_Handler()
{
  if (Serial4.isIrq()) 
      Serial4.IrqHandler();
    else if (Serial4B.isIrq()) 
      Serial4B.IrqHandler();
  else
      WIRE4_IT_HANDLER();
}}// extern "C" {
#endif

#if defined(SIX_UART)
Uart Serial5( SERCOM_INSTANCE_SERIAL5,(uint8_t) PIN_SERIAL5_RX, (uint8_t)PIN_SERIAL5_TX, PAD_SERIAL5_RX, PAD_SERIAL5_TX ) ;
Uart Serial5B( SERCOM_INSTANCE_SERIAL_B5,(uint8_t) PIN_SERIAL_B5_RX, (uint8_t)PIN_SERIAL_B5_TX, PAD_SERIAL_B5_RX, PAD_SERIAL_B5_TX ) ;
extern "C"
{
void SERCOM5_Handler()
{
  if (Serial5.isIrq()) 
      Serial5.IrqHandler();
  else if (Serial5B.isIrq()) 
      Serial5B.IrqHandler();
  

  else
      WIRE5_IT_HANDLER();
}
}// extern "C" {
#endif



#include "uart.h"
#include "libraries/SPI/SPI.h"

SPIClass SPI0_BIS(&PERIPH_SPI0_BIS,  PIN_SPI0_BIS_MISO,  PIN_SPI0_BIS_SCK,  PIN_SPI0_BIS_MOSI,  PAD_SPI0_BIS_TX,  PAD_SPI0_BIS_RX);
Uart Serial0_BIS(SERCOM_INSTANCE_SERIAL0_BIS, PIN_SERIAL0_BIS_RX, PIN_SERIAL0_BIS_TX,  PAD_SERIAL0_BIS_RX, PAD_SERIAL0_BIS_TX);
Uart Serial0_BIS_B(SERCOM_INSTANCE_SERIAL_B0_BIS, PIN_SERIAL_B0_BIS_RX, PIN_SERIAL_B0_BIS_TX,  (SERCOM_RX_PAD_3)	, (UART_TX_PAD_2)	);
TwoWire Wire0_BIS(&PERIPH_WIRE0_BIS, PIN_WIRE0_BIS_SDA, PIN_WIRE0_BIS_SCL);


  void WIRE0_BIS_IT_HANDLER(void) {
    Wire0_BIS.onService();
  }


const struct PComDescription g_PComDescription[]=
{
  {{  0, 1, 2, 3, 4, 5 },Serial0,Serial0B,Wire0,SPI0/*,SPI0*/}, //  
  {{ 12,13,14,15,16,17 },Serial1,Serial1B,Wire1,SPI1/*,SPI1*/}, //  
  {{ 18,19,20,21,22,23 },Serial2,Serial2B,Wire2,SPI2/*,SPI2*/}, //  
  {{ 24,25,26,27,28,29 },Serial3,Serial3B,Wire3,SPI3/*,SPI3*/}, //  
  {{ 30,31,32,33,34,35 },Serial4,Serial4B,Wire4,SPI4/*,SPI4*/}, //  
  {{ 36,37,38,39,40,41 },Serial5,Serial5B,Wire5,SPI5/*,SPI5*/}, //  
  {{  6, 7, 8, 9,10,11 },Serial0_BIS,Serial0_BIS_B,Wire0_BIS,SPI0_BIS/*,SPI0_BIS*/}, //  

};

 
const struct PAnaDescription g_PAnaDescription[]=
{
  {  44, 45, 11, 10, 6, 7, 8, 9 }, // PANA0 
  {  16, 17, 46, 47, 48, 49, 50, 51 }, // PANA1 
};

#include "../debug.c"
