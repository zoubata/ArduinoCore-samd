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

TQFP100_1	,
TQFP100_2	,
TQFP100_3	,
TQFP100_4	,
TQFP100_5	,
TQFP100_6	,
TQFP100_7	,
TQFP100_8	,
TQFP100_9	,
TQFP100_10	,
TQFP100_11	,
TQFP100_12	,
TQFP100_13	,
TQFP100_14	,
TQFP100_15	,
TQFP100_16	,
TQFP100_17	,
TQFP100_18	,
TQFP100_19	,
TQFP100_20	,
TQFP100_21	,
TQFP100_22	,
TQFP100_23	,
TQFP100_24	,
TQFP100_25	,
TQFP100_26	,
TQFP100_27	,
TQFP100_28	,
TQFP100_29	,
TQFP100_30	,
TQFP100_31	,
TQFP100_32	,
TQFP100_33	,
TQFP100_34	,
TQFP100_35	,
TQFP100_36	,
TQFP100_37	,
TQFP100_38	,
TQFP100_39	,
TQFP100_40	,
TQFP100_41	,
TQFP100_42	,
TQFP100_43	,
TQFP100_44	,
TQFP100_45	,
TQFP100_46	,
TQFP100_47	,
TQFP100_48	,
TQFP100_49	,
TQFP100_50	,
TQFP100_51	,
TQFP100_52	,
TQFP100_53	,
TQFP100_54	,
TQFP100_55	,
TQFP100_56	,
TQFP100_57	,
TQFP100_58	,
TQFP100_59	,
TQFP100_60	,
TQFP100_61	,
TQFP100_62	,
TQFP100_63	,
TQFP100_64	,
TQFP100_65	,
TQFP100_66	,
TQFP100_67	,
TQFP100_68	,
TQFP100_69	,
TQFP100_70	,
TQFP100_71	,
TQFP100_72	,
TQFP100_73	,
TQFP100_74	,
TQFP100_75	,
TQFP100_76	,
TQFP100_77	,
TQFP100_78	,
TQFP100_79	,
TQFP100_80	,
TQFP100_81	,
TQFP100_82	,
TQFP100_83	,
TQFP100_84	,
TQFP100_85	,
TQFP100_86	,
TQFP100_87	,
TQFP100_88	,
TQFP100_89	,
TQFP100_90	,
TQFP100_91	,
TQFP100_92	,
TQFP100_93	,
TQFP100_94	,
TQFP100_95	,
TQFP100_96	,
TQFP100_97	,
TQFP100_98	,
TQFP100_99	,
TQFP100_100	


} ;
/*
#if (NUM_PIN_DESCRIPTION_ENTRIES!=(sizeof(g_APinDescription)/sizeof(PinDescription)))
	#error bad size
#endif*/

const void* g_apTCInstances[TCC_INST_NUM+TC_INST_NUM]={ 
#if  !(SAMD20_SERIES)
  TCC0,TCC1,TCC2, 
#endif
  TC0, TC1,
#if  !(SAMD20_SERIES )
  TC2,
#endif
  TC3, TC4, 
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

#if defined(BOARD_ID_engi) 
Uart SerialFTDI( &sercom0, (uint8_t)TQFP100_29_ARDUINO, (uint8_t)TQFP100_28_ARDUINO, SERCOM_RX_PAD_3, UART_TX_PAD_2 ) ;
#endif

Uart Serial0( SERCOM_INSTANCE_SERIAL0, (uint8_t)PIN_SERIAL0_RX, (uint8_t)PIN_SERIAL0_TX, PAD_SERIAL0_RX, PAD_SERIAL0_TX ) ;
Uart Serial0B( SERCOM_INSTANCE_SERIAL_B0,(uint8_t) PIN_SERIAL_B0_RX, (uint8_t)PIN_SERIAL_B0_TX, PAD_SERIAL_B0_RX, PAD_SERIAL_B0_TX ) ;

void WIRE0_IT_HANDLER();
void WIRE1_IT_HANDLER();
void WIRE2_IT_HANDLER();
  extern TwoWire Wire0;
  extern TwoWire Wire1;
  extern TwoWire Wire2;
  

Uart Serial3( SERCOM_INSTANCE_SERIAL1, (uint8_t)PIN_SERIAL1_RX, (uint8_t)PIN_SERIAL1_TX, PAD_SERIAL1_RX, PAD_SERIAL1_TX ) ;	
//Uart Serial3B( SERCOM_INSTANCE_SERIAL_B1,(uint8_t) PIN_SERIAL_B1_RX, (uint8_t)PIN_SERIAL_B1_TX, PAD_SERIAL_B1_RX, PAD_SERIAL_B1_TX ) ;

Uart Serial1_2( SERCOM_INSTANCE_SERIAL2, (uint8_t)PIN_SERIAL2_RX, (uint8_t)PIN_SERIAL2_TX, PAD_SERIAL2_RX, PAD_SERIAL2_TX ) ;
//Uart Serial1_2B( SERCOM_INSTANCE_SERIAL_B2,(uint8_t) PIN_SERIAL_B2_RX, (uint8_t)PIN_SERIAL_B2_TX, PAD_SERIAL_B2_RX, PAD_SERIAL_B2_TX ) ;


Uart Serial3B_3( SERCOM_INSTANCE_SERIAL_B3,(uint8_t) PIN_SERIAL_B3_RX, (uint8_t)PIN_SERIAL_B3_TX, PAD_SERIAL_B3_RX, PAD_SERIAL_B3_TX ) ;



#ifdef __cplusplus
extern "C"
{
#endif 
//sercom 3 ->serial1  so wire1
void SERCOM3_Handler()
{
  if (Serial3.enabled()) 
      Serial3.IrqHandler();
 /*  else  if (Serial3B.enabled()) 
      Serial3B.IrqHandler();*/
  else
      WIRE1_IT_HANDLER();
}
//secom 0 ->serial0 so pcom0
void SERCOM0_Handler()
{
#if defined(BOARD_ID_engi) 
  if (SerialFTDI.enabled()) 
      SerialFTDI.IrqHandler();
  else
#endif

  if (Serial0.enabled()) 
      Serial0.IrqHandler();
  else
	   if (Serial0B.enabled()) 
      Serial0B.IrqHandler();
  else
	  if (Wire0.enabled()) 
      WIRE0_IT_HANDLER(); 
}
//secom 1 ->serial2 +serial3B so wire2 and ftdi

void SERCOM1_Handler()
{
  if (Serial1_2.enabled()) 
      Serial1_2.IrqHandler();
 /*  else  if (Serial1_2B.enabled()) 
      Serial1_2B.IrqHandler();*/
   else  if (Serial3B_3.enabled()) 
      Serial3B_3.IrqHandler();
  else
      WIRE2_IT_HANDLER();
 
}
#ifdef __cplusplus
}// extern "C" {
#endif 
//#include "../../cores/arduino/usart.h"

/*
SPIClass SPI0_BIS(&PERIPH_SPI0_BIS,  PIN_SPI0_BIS_MISO,  PIN_SPI0_BIS_SCK,  PIN_SPI0_BIS_MOSI,  PAD_SPI0_BIS_TX,  PAD_SPI0_BIS_RX);
Uart Serial0_BIS(SERCOM_INSTANCE_SERIAL0_BIS, PIN_SERIAL0_BIS_RX, PIN_SERIAL0_BIS_TX,  PAD_SERIAL0_BIS_RX, PAD_SERIAL0_BIS_TX);
Uart Serial0_BIS_B(SERCOM_INSTANCE_SERIAL_B0_BIS, PIN_SERIAL_B0_BIS_RX, PIN_SERIAL_B0_BIS_TX,  (SERCOM_RX_PAD_3)	, (UART_TX_PAD_2)	);
TwoWire Wire0_BIS(&PERIPH_WIRE, PIN_WIRE_SDA, PIN_WIRE_SCL);

*/
Uart SerialDummy( SERCOM_INSTANCE_SERIAL2, (uint8_t)PIN_SERIAL2_RX, (uint8_t)PIN_SERIAL2_TX, PAD_SERIAL2_RX, PAD_SERIAL2_TX ) ;
#define   TwoWireDummy Wire2
SPIClass SPIDummy (&PERIPH_SPI,  PIN_SPI_MISO,  PIN_SPI_SCK,  PIN_SPI_MOSI,  PAD_SPI_TX,  PAD_SPI_RX);

const struct PComDescription g_PComDescription[4]=
{
	//PAD0,PAD1,PAD2,PAD3,PAD4,PAD5
	//SCL,SDA,,,,,,
  {{  TQFP100_80_ARDUINO, TQFP100_81_ARDUINO, TQFP100_78_ARDUINO, TQFP100_79_ARDUINO, TQFP100_82_ARDUINO, TQFP100_83_ARDUINO }	,Serial0,Serial0B	,Wire0	,SPI0}, //  PCOM0
  {{ TQFP100_53_ARDUINO,TQFP100_52_ARDUINO,PIO_NOT_A_PIN,PIO_NOT_A_PIN,TQFP100_49_ARDUINO,PIO_NOT_A_PIN }		,Serial3,(Uart&)SerialDummy	,Wire1	,(SPIClass&)SPIDummy}, //  I2C1 WIREA
  {{ TQFP100_86_ARDUINO,TQFP100_85_ARDUINO,TQFP100_20_ARDUINO,PIO_NOT_A_PIN,TQFP100_89_ARDUINO,PIO_NOT_A_PIN }		,Serial1_2,(Uart&)SerialDummy	,Wire2	,(SPIClass&)SPIDummy},//  I2C2    WIREB
  {{ PIO_NOT_A_PIN,PIO_NOT_A_PIN,TQFP100_93_ARDUINO,TQFP100_94_ARDUINO,PIO_NOT_A_PIN,PIO_NOT_A_PIN }		,(Uart&)SerialDummy,Serial3B_3	,(TwoWire&)TwoWireDummy		,(SPIClass&)SPIDummy}, //  FTDI can't be used at same time of I2C2
  /*{{ 30,31,32,33,34,35 },Serial4,Serial4B,Wire4,SPI4}, //  
  {{ 36,37,38,39,40,41 },Serial5,Serial5B,Wire5,SPI5}, //  
  {{  6, 7, 8, 9,10,11 },Serial0_BIS,Serial0_BIS_B,Wire0_BIS,SPI0_BIS}, */ 
};

const  P3GP2YDescription P_GP2Y[P_GP2Y_NB]={
	 G__1,
	 G__2,
	 G__3,
	 G__4,
	 G__5,
	 G__6,
          G__7,
	 G__8	
};
const  PUSDescription P_US[P_US_NB]={
	 U__1,
	 U__2,
	 U__3,
	 U__4,
	 U__5,
	 U__6	
};


const  PInfraRedDescription P_IR[P_IR_NB]={
	 I__1,
	 I__2,
	 I__3,
	 I__4,
	 I__5,
	 I__6,
	 I__7,
	 I__8,
};

const  PEncoderDescription P_Encoder[P_Encoder_NB]={
         P__1,
	 P__2,
	 P__3,
	 P__4,
	 P__5,
	 P__6,
	 P__7,
	 P__8 //coder	
};


/*
const  PAnaDescription g_PAnaDescription[]=
{

};
*/
/////////////////////////////////////////////////////////////////////////////////


//gen begin
#include "../debug.c"
