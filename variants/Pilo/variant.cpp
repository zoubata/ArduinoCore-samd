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
  // P_com0 0..5 - Digital pins
  // ----------------------
  // 0/1 - SERCOM/UART (Serial1)
  { PORTA,  8, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), ADC_Channel8, PCOM_PWM0_CH0, TCC0_CH0, EXTERNAL_INT_NMI }, //  
  { PORTA,  9, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), ADC_Channel9, PCOM_PWM0_CH1, TCC0_CH1, EXTERNAL_INT_9  }, //  
  { PORTA, 10, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), ADC_Channel10, PCOM_PWM0_CH2, TCC1_CH0, EXTERNAL_INT_10 }, //  
  { PORTA, 11, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), ADC_Channel11, PCOM_PWM0_CH3, TCC1_CH1, EXTERNAL_INT_11 }, // 
  { PORTA, 21, PIO_AC_CLK, (PIN_ATTR_DIGITAL             |PIN_ATTR_TIMER), No_ADC_Channel, PCOM_NOT_ON_PWM, TCC0_CH7, EXTERNAL_INT_5 }, //  
  { PORTA, 18, PIO_EXTINT, (PIN_ATTR_DIGITAL             |PIN_ATTR_TIMER), No_ADC_Channel, PCOM_NOT_ON_PWM, TCC0_CH2, EXTERNAL_INT_2 }, //  

  // P_com0_bis 0..6 - Digital pins
  //6..11

  { PORTA,  4, PIO_SERCOM, (PIN_ATTR_ANALOG|PIN_ATTR_DIGITAL|PIN_ATTR_PWM               ), ADC_Channel4 , PCOM_PWM0BIS_CH0  , NOT_ON_TIMER, EXTERNAL_INT_4 }, //  
  { PORTA,  5, PIO_SERCOM, (PIN_ATTR_ANALOG|PIN_ATTR_DIGITAL|PIN_ATTR_PWM               ), ADC_Channel5 , PCOM_PWM0BIS_CH1  , NOT_ON_TIMER, EXTERNAL_INT_5  }, //  
  { PORTA,  6, PIO_SERCOM, (PIN_ATTR_ANALOG|PIN_ATTR_DIGITAL|PIN_ATTR_PWM               ), ADC_Channel6 , PCOM_PWM0BIS_CH2  , NOT_ON_TIMER, EXTERNAL_INT_6  }, //  
  { PORTA,  7, PIO_SERCOM, (PIN_ATTR_ANALOG|PIN_ATTR_DIGITAL|PIN_ATTR_PWM               ), ADC_Channel7 , PCOM_PWM0BIS_CH3  , NOT_ON_TIMER, EXTERNAL_INT_7  }, // 
  { PORTB,  9, PIO_AC_CLK, (PIN_ATTR_ANALOG|PIN_ATTR_DIGITAL                            ), ADC1_Channel4 , PCOM_NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_9 }, //  
  { PORTB,  8, PIO_EXTINT, (PIN_ATTR_ANALOG|PIN_ATTR_DIGITAL                            ), ADC1_Channel5 , PCOM_NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_8 }, //  

  // P_com1 0..6 - Digital pins
  //12..17
  { PORTA,  0, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM               ), No_ADC_Channel, PCOM_PWM1_CH0, NOT_ON_TIMER, EXTERNAL_INT_0 }, //  
  { PORTA,  1, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM               ), No_ADC_Channel, PCOM_PWM1_CH1, NOT_ON_TIMER, EXTERNAL_INT_1  }, //  
  { PORTA, 30, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM               ), No_ADC_Channel, PCOM_PWM1_CH2, NOT_ON_TIMER, EXTERNAL_INT_10 }, //  
  { PORTA, 31, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM               ), No_ADC_Channel, PCOM_PWM1_CH3, NOT_ON_TIMER, EXTERNAL_INT_11 }, // 
  { PORTB,  0, PIO_EXTINT, (PIN_ATTR_ANALOG|PIN_ATTR_DIGITAL            ), ADC1_Channel0, PCOM_NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_0 }, //  
  { PORTB,  1, PIO_EXTINT, (PIN_ATTR_ANALOG|PIN_ATTR_DIGITAL            ), ADC1_Channel1, PCOM_NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_1 }, //  
  
  // P_com2 0..6 - Digital pins
  //18..23
  { PORTA, 12, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM               ), No_ADC_Channel, PCOM_PWM2_CH0, NOT_ON_TIMER, EXTERNAL_INT_12}, //  
  { PORTA, 13, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM               ), No_ADC_Channel, PCOM_PWM2_CH1, NOT_ON_TIMER, EXTERNAL_INT_13 }, //  
  { PORTA, 14, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM               ), No_ADC_Channel, PCOM_PWM2_CH2, NOT_ON_TIMER, EXTERNAL_INT_14 }, //  
  { PORTA, 15, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM               ), No_ADC_Channel, PCOM_PWM2_CH3, NOT_ON_TIMER, EXTERNAL_INT_15 }, // 
  { PORTA, 17, PIO_AC_CLK, (PIN_ATTR_DIGITAL                            ), No_ADC_Channel, PCOM_NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_1 }, //  
  { PORTA, 16, PIO_EXTINT, (PIN_ATTR_DIGITAL                            ), No_ADC_Channel, PCOM_NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_0 }, //  
  // P_com3 0..6 - Digital pins
  //24..29
  { PORTA, 22, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM               ), No_ADC_Channel, PCOM_PWM3_CH0, NOT_ON_TIMER, EXTERNAL_INT_6 }, //  
  { PORTA, 23, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM               ), No_ADC_Channel, PCOM_PWM3_CH1, NOT_ON_TIMER, EXTERNAL_INT_7  }, //  
  { PORTA, 24, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM               ), No_ADC_Channel, PCOM_PWM3_CH2, NOT_ON_TIMER, EXTERNAL_INT_12 }, //  
  { PORTA, 25, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM               ), No_ADC_Channel, PCOM_PWM3_CH3, NOT_ON_TIMER, EXTERNAL_INT_13 }, // 
  { PORTA, 20, PIO_AC_CLK, (PIN_ATTR_DIGITAL                            ), No_ADC_Channel, PCOM_NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_4 }, //  
  { PORTA, 19, PIO_EXTINT, (PIN_ATTR_DIGITAL                            ), No_ADC_Channel, PCOM_NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3 }, //  
  // P_com4 0..6 - Digital pins
  //30..35
  { PORTB, 12, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM               ), No_ADC_Channel, PCOM_PWM4_CH0, NOT_ON_TIMER, EXTERNAL_INT_12 }, //  
  { PORTB, 13, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM               ), No_ADC_Channel, PCOM_PWM4_CH1, NOT_ON_TIMER, EXTERNAL_INT_13  }, //  
  { PORTB, 14, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM               ), No_ADC_Channel, PCOM_PWM4_CH2, NOT_ON_TIMER, EXTERNAL_INT_14 }, //  
  { PORTB, 15, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM               ), No_ADC_Channel, PCOM_PWM4_CH3, NOT_ON_TIMER, EXTERNAL_INT_15 }, // 
  { PORTB, 16, PIO_AC_CLK, (PIN_ATTR_DIGITAL                            ), No_ADC_Channel, PCOM_NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_0 }, //  
  { PORTB, 17, PIO_EXTINT, (PIN_ATTR_DIGITAL                            ), No_ADC_Channel, PCOM_NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_1 }, //  
  // P_com5 0..6 - Digital pins
  //36..41
  { PORTB, 30, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM               ), No_ADC_Channel, PCOM_PWM5_CH0, NOT_ON_TIMER, EXTERNAL_INT_14 }, //  
  { PORTB, 31, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM               ), No_ADC_Channel, PCOM_PWM5_CH1, NOT_ON_TIMER, EXTERNAL_INT_15  }, //  
  { PORTB, 22, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM               ), No_ADC_Channel, PCOM_PWM5_CH2, NOT_ON_TIMER, EXTERNAL_INT_6 }, //  
  { PORTB, 23, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM               ), No_ADC_Channel, PCOM_PWM5_CH3, NOT_ON_TIMER, EXTERNAL_INT_7 }, // 
  { PORTA, 27, PIO_AC_CLK, (PIN_ATTR_DIGITAL                            ), No_ADC_Channel, PCOM_NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_15 }, //  
  { PORTA, 28, PIO_EXTINT, (PIN_ATTR_DIGITAL                            ), No_ADC_Channel, PCOM_NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_8 }, //  

  // CAN 42 43 
  { PORTB, 10, PIO_PWM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PCOM_NOT_ON_PWM, TCC2_CH1, EXTERNAL_INT_1 }, // TCC2/WO[1]
  { PORTB, 11, PIO_PWM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PCOM_NOT_ON_PWM, TCC2_CH1, EXTERNAL_INT_1 }, // TCC2/WO[1]

  // PANA1 42 43 - Analog pins
  // --------------------
  { PORTB,  6, PIO_ANALOG, PIN_ATTR_ANALOG                               , ADC1_Channel8, PCOM_NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_6 }, // ADC/AIN[0]
  { PORTB,  7, PIO_ANALOG, PIN_ATTR_ANALOG| (PIN_ATTR_PWM|PIN_ATTR_TIMER), ADC1_Channel9, PCOM_NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_7 }, // ADC/AIN[2]
 
  // PANA2 44 49 - Analog pins
  // ----------------------
  { PORTB,  2, PIO_ANALOG, PIN_ATTR_ANALOG|PIN_ATTR_DIGITAL, ADC1_Channel2, PCOM_NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2 }, // SDA: SERCOM3/PAD[0]
  { PORTB,  3, PIO_ANALOG, PIN_ATTR_ANALOG|PIN_ATTR_DIGITAL, ADC1_Channel3, PCOM_NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3 }, // SCL: SERCOM3/PAD[1]
  { PORTA,  2, PIO_ANALOG, PIN_ATTR_ANALOG|PIN_ATTR_DIGITAL, ADC_Channel10, PCOM_NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2 }, // SDA: SERCOM3/PAD[0]
  { PORTA,  3, PIO_ANALOG, PIN_ATTR_ANALOG|PIN_ATTR_DIGITAL, ADC_Channel11, PCOM_NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3 }, // SCL: SERCOM3/PAD[1]
  { PORTB,  4, PIO_ANALOG, PIN_ATTR_ANALOG|PIN_ATTR_DIGITAL, ADC1_Channel6, PCOM_NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_4 }, // SDA: SERCOM3/PAD[0]
  { PORTB,  5, PIO_ANALOG, PIN_ATTR_ANALOG|PIN_ATTR_DIGITAL, ADC1_Channel7, PCOM_NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_5 }, // SCL: SERCOM3/PAD[1]

  
  // 42 (AREF)
  { PORTA, 3, PIO_ANALOG, PIN_ATTR_ANALOG, No_ADC_Channel, PCOM_NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // DAC/VREFP

  // ----------------------
  // 43 - Alternate use of A0 (DAC output)
  { PORTA,  2, PIO_ANALOG, PIN_ATTR_ANALOG, DAC_Channel0, PCOM_NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2 }, // DAC/VOUT
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

