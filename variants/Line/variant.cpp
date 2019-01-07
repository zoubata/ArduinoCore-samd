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
QFN32_1	,
QFN32_2	,
QFN32_3	,
QFN32_4	,
QFN32_5	,
QFN32_6	,
QFN32_7	,
QFN32_8	,
QFN32_9	,
QFN32_10	,
QFN32_11	,
QFN32_12	,
QFN32_13	,
QFN32_14	,
QFN32_15	,
QFN32_16	,
QFN32_17	,
QFN32_18	,
QFN32_19	,
QFN32_20	,
QFN32_21	,
QFN32_22	,
QFN32_23	,
QFN32_24	,
QFN32_25	,
QFN32_26	,
QFN32_27	,
QFN32_28	,
QFN32_29	,
QFN32_30	,
QFN32_31	,
QFN32_32	
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
#if  !SAMD20_SERIES 
 #if  !SAMD21_SERIES 
TC2,
#endif
  #endif
  TC3, TC4, 
   #if !( SAMC_SERIES)
TC5,//TC6,TC7,
  #endif

} ;



// Multi-serial objects instantiation

SERCOM sercom0( SERCOM0 ) ;
SERCOM sercom1( SERCOM1 ) ;
SERCOM sercom2( SERCOM2 ) ;
SERCOM sercom3( SERCOM3 ) ;



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
  if (Serial0.enabled()) 
      Serial0.IrqHandler();
  else
	   if (Serial0B.enabled()) 
      Serial0B.IrqHandler();
  else
	  if (Wire0.enabled()) 
      WIRE0_IT_HANDLER();
  if (Serial0_BIS.enabled()) 
      Serial0_BIS.IrqHandler();
  else
	  if (Wire0_BIS.enabled()) 
      WIRE0_BIS_IT_HANDLER();
}
}// extern "C" {

#if defined(TWO_UART) || defined(THREE_UART) || defined(FOUR_UART) || defined(FIVE_UART) || defined(SIX_UART)

Uart Serial1( SERCOM_INSTANCE_SERIAL1, (uint8_t)PIN_SERIAL1_RX, (uint8_t)PIN_SERIAL1_TX, PAD_SERIAL1_RX, PAD_SERIAL1_TX ) ;	
Uart Serial1B( SERCOM_INSTANCE_SERIAL_B1,(uint8_t) PIN_SERIAL_B1_RX, (uint8_t)PIN_SERIAL_B1_TX, PAD_SERIAL_B1_RX, PAD_SERIAL_B1_TX ) ;
extern "C"
{
void SERCOM1_Handler()
{
  if (Serial1.enabled()) 
      Serial1.IrqHandler();
   else  if (Serial1B.enabled()) 
      Serial1B.IrqHandler();
  else
      WIRE1_IT_HANDLER();
}}// extern "C" {
#endif
/*
#if defined(THREE_UART) || defined(FOUR_UART) || defined(FIVE_UART) || defined(SIX_UART)
Uart Serial2( SERCOM_INSTANCE_SERIAL2, (uint8_t)PIN_SERIAL2_RX, (uint8_t)PIN_SERIAL2_TX, PAD_SERIAL2_RX, PAD_SERIAL2_TX ) ;
Uart Serial2B( SERCOM_INSTANCE_SERIAL_B2,(uint8_t) PIN_SERIAL_B2_RX, (uint8_t)PIN_SERIAL_B2_TX, PAD_SERIAL_B2_RX, PAD_SERIAL_B2_TX ) ;

void SERCOM2_Handler()
{
  if (Serial2.enabled()) 
      Serial2.IrqHandler();
   else  if (Serial2B.enabled()) 
      Serial2B.IrqHandler();
  else
      WIRE2_IT_HANDLER();
}
#endif

#if defined(FOUR_UART) || defined(FIVE_UART) || defined(SIX_UART)
Uart Serial3( SERCOM_INSTANCE_SERIAL3, (uint8_t)PIN_SERIAL3_RX, (uint8_t)PIN_SERIAL3_TX, PAD_SERIAL3_RX, PAD_SERIAL3_TX ) ;
Uart Serial3B( SERCOM_INSTANCE_SERIAL_B3,(uint8_t) PIN_SERIAL_B3_RX, (uint8_t)PIN_SERIAL_B3_TX, PAD_SERIAL_B3_RX, PAD_SERIAL_B3_TX ) ;

void SERCOM3_Handler()
{
  if (Serial3.enabled()) 
      Serial3.IrqHandler();
  else  if (Serial3B.enabled()) 
      Serial3B.IrqHandler();
  else
      WIRE3_IT_HANDLER();
}
#endif
#if defined(FIVE_UART) || defined(SIX_UART)
Uart Serial4( SERCOM_INSTANCE_SERIAL4, (uint8_t)PIN_SERIAL4_RX, (uint8_t)PIN_SERIAL4_TX, PAD_SERIAL4_RX, PAD_SERIAL4_TX ) ;
Uart Serial4B( SERCOM_INSTANCE_SERIAL_B4,(uint8_t) PIN_SERIAL_B4_RX, (uint8_t)PIN_SERIAL_B4_TX, PAD_SERIAL_B4_RX, PAD_SERIAL_B4_TX ) ;

void SERCOM4_Handler()
{
  if (Serial4.enabled()) 
      Serial4.IrqHandler();
    else if (Serial4B.enabled()) 
      Serial4B.IrqHandler();
  else
      WIRE4_IT_HANDLER();
}
#endif

#if defined(SIX_UART)
Uart Serial5( SERCOM_INSTANCE_SERIAL5,(uint8_t) PIN_SERIAL5_RX, (uint8_t)PIN_SERIAL5_TX, PAD_SERIAL5_RX, PAD_SERIAL5_TX ) ;
Uart Serial5B( SERCOM_INSTANCE_SERIAL_B5,(uint8_t) PIN_SERIAL_B5_RX, (uint8_t)PIN_SERIAL_B5_TX, PAD_SERIAL_B5_RX, PAD_SERIAL_B5_TX ) ;

void SERCOM5_Handler()
{
  if (Serial5.enabled()) 
      Serial5.IrqHandler();
  else if (Serial5B.enabled()) 
      Serial5B.IrqHandler();
  

  else
      WIRE5_IT_HANDLER();
}
#endif
*/


//#include "../../cores/arduino/usart.h"


SPIClass SPI0_BIS(&PERIPH_SPI0_BIS,  PIN_SPI0_BIS_MISO,  PIN_SPI0_BIS_SCK,  PIN_SPI0_BIS_MOSI,  PAD_SPI0_BIS_TX,  PAD_SPI0_BIS_RX);
Uart Serial0_BIS(SERCOM_INSTANCE_SERIAL0_BIS, PIN_SERIAL0_BIS_RX, PIN_SERIAL0_BIS_TX,  PAD_SERIAL0_BIS_RX, PAD_SERIAL0_BIS_TX);
Uart Serial0_BIS_B(SERCOM_INSTANCE_SERIAL_B0_BIS, PIN_SERIAL_B0_BIS_RX, PIN_SERIAL_B0_BIS_TX,  (SERCOM_RX_PAD_3)	, (UART_TX_PAD_2)	);
TwoWire Wire0_BIS(&PERIPH_WIRE, PIN_WIRE_SDA, PIN_WIRE_SCL);





const struct PComDescription g_PComDescription[]=
{
  {{  0, 1, 2, 3, 4, 5 },Serial0,Serial0B,Wire0,SPI0/*,SPI0*/}, //  
//  {{ 12,13,14,15,16,17 },Serial1,Serial1B,Wire1,SPI1/*,SPI1*/}, //  
//  {{ 18,19,20,21,22,23 },Serial2,Serial2B,Wire2,SPI2/*,SPI2*/}, //  
//  {{ 24,25,26,27,28,29 },Serial3,Serial3B,Wire3,SPI3/*,SPI3*/}, //  
//  {{ 30,31,32,33,34,35 },Serial4,Serial4B,Wire4,SPI4/*,SPI4*/}, //  
//  {{ 36,37,38,39,40,41 },Serial5,Serial5B,Wire5,SPI5/*,SPI5*/}, //  
//  {{  6, 7, 8, 9,10,11 },Serial0_BIS,Serial0_BIS_B,Wire0_BIS,SPI0_BIS/*,SPI0_BIS*/}, //  

};


const struct PAnaDescription g_PAnaDescription[]=
{
  {  44, 45, 11, 10, 6, 7, 8, 9 }, // PANA0 
  {  16, 17, 46, 47, 48, 49, 50, 51 }, // PANA1 
};
