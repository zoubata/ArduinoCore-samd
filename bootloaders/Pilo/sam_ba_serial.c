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

#include <sam.h>
#include "board_definitions/board_definitions.h"
#include "sam_ba_serial.h"
#include "board_driver_serial.h"
#include "cores\arduino\WVariant.h"
#include "Variant.h"

Sercom * boot_usart_module=BOOT_USART_MODULE;

/* Local reference to current Usart instance in use with this driver */
//struct usart_module usart_sam_ba;

/* Variable to let the main task select the appropriate communication interface */
volatile uint8_t b_sharp_received;

/* RX and TX Buffers + rw pointers for each buffer */
volatile uint8_t buffer_rx_usart[USART_BUFFER_SIZE];

volatile uint8_t idx_rx_read;
volatile uint8_t idx_rx_write;

volatile uint8_t buffer_tx_usart[USART_BUFFER_SIZE];

volatile uint8_t idx_tx_read;
volatile uint8_t idx_tx_write;

/* Test for timeout in AT91F_GetChar */
uint8_t error_timeout;
uint16_t size_of_data;
uint8_t mode_of_transfer;

#define BOOT_USART_PAD(n) BOOT_USART_PAD##n
#define READ_PIN(pin) (((PORT->Group[pin >>5].IN.reg)>>(pin & 0x1F)) & 0x1)
#define MAX(a,b) ((a<b)?b:a)
#define MIN(a,b) ((a<b)?a:b)
long long  get_time_ns();
unsigned  long  ticks0 ;
unsigned  long  ticks1;
unsigned  long  ticks2;
unsigned  long  ticks3;
unsigned  long  ticks4;
unsigned  long  ticks5;
char s0;
char s1;
char s2;
char s3;
char s4;
char s5;
signed int pin;
/**
 * \brief Open the given USART
 */
void serial_open(unsigned int fBaudSpeed)
{
	
  #if defined (SERIAL_AUTOBAUD) && (SERIAL_AUTOBAUD==1)
  if (fBaudSpeed!=0)
  {
	//signed int
	pin =-1;
	switch(BOOT_USART_PAD_SETTINGS) 
	{
		case 	UART_RX_PAD0_TX_PAD2 : pin=BOOT_USART_PAD0;break;
		case 	UART_RX_PAD1_TX_PAD2 : pin=BOOT_USART_PAD1;break;
		case 	UART_RX_PAD2_TX_PAD0 : pin=BOOT_USART_PAD2;break;
		case 	UART_RX_PAD3_TX_PAD0 : pin=BOOT_USART_PAD3;break;
		case 	UART_RX_PAD1_TX_PAD0 : pin=BOOT_USART_PAD1;break;
		case 	UART_RX_PAD3_TX_PAD2 : pin=BOOT_USART_PAD3;break;
        default : pin=PINMUX_UNUSED;break;
		 
	}
        unsigned int b[5]={1,1000,1,100000,10};
	
	if (pin!=PINMUX_UNUSED)
	{
		pin=(pin>>16)&0xff;
		//configure as input pull up
		PORT->Group[pin >>5].PINCFG[pin & 0x1F].bit.INEN=1;
			PORT->Group[pin >>5].PINCFG[pin & 0x1F].bit.PULLEN=1;
			PORT->Group[pin >>5].OUTSET.reg=(1L<<(pin & 0x1F));
			PORT->Group[pin >>5].DIRCLR.reg=(1L<<(pin & 0x1F));
		//wait 1st frame to read baud rate.

                 //wait a frame
		 //char 
		 s0=READ_PIN(pin);
		 while(s0==READ_PIN(pin));
                  int load=SysTick->LOAD;// use to measure time (get_time_ns take time, create latency, so limit the baud max to 115200.
                   SysTick->LOAD=SysTick_VAL_CURRENT_Msk;
                   SysTick->VAL=0;
                  s0=READ_PIN(pin);//start to measure
                  while(s0==READ_PIN(pin));
                  
		 //unsigned  long  
		 ticks0  =   SysTick->VAL;//get_time_ns();
		 //char
		 s1=READ_PIN(pin);
		 while(s1==READ_PIN(pin));
		// unsigned  long  
		ticks1  =  SysTick->VAL;//get_time_ns();
		 //char
		 s2=READ_PIN(pin);
		 while(s2==READ_PIN(pin));
		 //unsigned  long  
		 ticks2  =  SysTick->VAL;//get_time_ns();
		 //char 
		 s3=READ_PIN(pin);
		 while(s3==READ_PIN(pin));
		 //unsigned  long 
		 ticks3  =  SysTick->VAL;//get_time_ns();
		// char 
		s4=READ_PIN(pin);
		 while(s4==READ_PIN(pin));
		 //unsigned  long  
		 ticks4  =  SysTick->VAL;//get_time_ns();
		 //char 
		 s5=READ_PIN(pin);
		 while(s5==READ_PIN(pin));
		// unsigned  long
		ticks5  =  SysTick->VAL;//get_time_ns();
                 
                 SysTick->LOAD=load;// restaure
                 SysTick->VAL=0;
                 
		 b[0]=ticks0-ticks1;
		 b[1]=ticks1-ticks2;
		 b[2]=ticks2-ticks3;
		 b[3]=ticks3-ticks4;
		 b[4]=ticks4-ticks5;
                 for(int i=0;i<5;i++)
                  b[i]=(b[i]*1000)/(VARIANT_MCK/1000000);
               
	}
	// frame : 80 80 #
	// ------_00000001-...._00000001-...._11000100-
	//s      0       1     2       3     45 6  78 9
	//          b0     b1      b2    b3  b4b5    
	//count      8     >2      8      >2  1 2
	//_=start ; -=stop
	
	 unsigned int bm=b[0];
	 unsigned int bM=b[0];
	 for(int i=1;i<5;i++)
         {
           bm=MIN(bm,b[i]);
           bM=MAX(bM,b[i]);
         }
         
           
	//
	 if (bM>(1000000000LL/1100)) {}//error too slow to be correct
	else
		if (bm<(1000000000LL/1500000)) {}//error too fast 1.5Mbps we can't measure upper
	else
        {
          
         unsigned int bavg=0;
           
           if (((bm*17)/10)<bM) // not a 'U'
              for(int i=0;i<5;i++)
                 b[i]=b[i]/((b[i]+bm/2)/bm);// normalize pulse length to 1 bit
             for(int i=0;i<5;i++)
           { bavg+=b[i];}
           bavg/=5;
           
	 fBaudSpeed=(long long)(1000000000LL/(long long)bavg);
        }
  }
  #endif
	/* Configure the port pins for SERCOM_USART */
	

        pinMux(BOOT_USART_PAD0);
        pinMux(BOOT_USART_PAD1);
        pinMux(BOOT_USART_PAD2);
        pinMux(BOOT_USART_PAD3);

	/* Enable clock for boot_usart_module */
#if (SAMD21 || SAMD20 || SAMD11)
  PM->APBCMASK.reg |= BOOT_USART_BUS_CLOCK_INDEX;
#elif (SAML21)
  MCLK->APBCMASK.reg |= MCLK_APBCMASK_SERCOM0 | MCLK_APBCMASK_SERCOM1 | MCLK_APBCMASK_SERCOM2 | MCLK_APBCMASK_SERCOM3 | MCLK_APBCMASK_SERCOM4 ;
  MCLK->APBDMASK.reg |= MCLK_APBDMASK_SERCOM5;	// On the SAML, SERCOM5 is on the low power bridge
#elif (SAMC21 || SAMC20)
  #if (SAMC21E)
  MCLK->APBCMASK.reg |= MCLK_APBCMASK_SERCOM0 | MCLK_APBCMASK_SERCOM1 | MCLK_APBCMASK_SERCOM2 | MCLK_APBCMASK_SERCOM3 ;
  #elif (SAMC21G) || (SAMC21J)
  MCLK->APBCMASK.reg |= MCLK_APBCMASK_SERCOM0 | MCLK_APBCMASK_SERCOM1 | MCLK_APBCMASK_SERCOM2 | MCLK_APBCMASK_SERCOM3 | MCLK_APBCMASK_SERCOM4 | MCLK_APBCMASK_SERCOM5 ;
 #elif (SAMC21N) 
  MCLK->APBCMASK.reg |= MCLK_APBCMASK_SERCOM0 | MCLK_APBCMASK_SERCOM1 | MCLK_APBCMASK_SERCOM2 | MCLK_APBCMASK_SERCOM3 | MCLK_APBCMASK_SERCOM4 | MCLK_APBCMASK_SERCOM5  ;
  MCLK->APBDMASK.reg |=  MCLK_APBDMASK_SERCOM6 | MCLK_APBDMASK_SERCOM7 ;

#else
  #error "sam_ba_serial.c: Missing dependency or unsupported chip. Please install CMSIS-Atmel from zoubworld (see Prerequisites for Building in README.md)."
  #endif
#else
  #error "sam_ba_serial.c: Missing dependency or unsupported chip. Please install CMSIS-Atmel from zoubworld (see Prerequisites for Building in README.md)."
#endif

	/* Set GCLK_GEN0 as source for GCLK_ID_SERCOMx_CORE */
#if (SAMD21 || SAMD20 || SAMD11)
  GCLK->CLKCTRL.reg = ( GCLK_CLKCTRL_ID( BOOT_USART_PER_CLOCK_INDEX ) | GCLK_CLKCTRL_GEN_GCLK0 | GCLK_CLKCTRL_CLKEN );
  waitForSync();
#elif (SAML21 || SAMC21)
  GCLK->PCHCTRL[BOOT_USART_PER_CLOCK_INDEX].reg = ( GCLK_PCHCTRL_CHEN | GCLK_PCHCTRL_GEN_GCLK0 );
  waitForSync();
#else
  #error "sam_ba_serial.c: Missing dependency or unsupported chip. Please install CMSIS-Atmel from zoubworld (see Prerequisites for Building in README.md)."
#endif

#define fref ((signed long long )VARIANT_MCK)
#define SamplesPerBit 16LL
signed long long BAUD=((signed long long )65536LL*(signed long long )SamplesPerBit*(signed long long )fBaudSpeed);
BAUD=BAUD/(signed long long )fref;
BAUD=65536-BAUD;

	/* Baud rate 115200 - clock 48MHz -> BAUD value-63018 */
	uart_basic_init(boot_usart_module,BAUD , BOOT_USART_PAD_SETTINGS);
// SAMPR=0 =>16 & Arithmetic Baud
//SMPA=0  => 7/8/9



	//Initialize flag
	b_sharp_received = false;
	idx_rx_read = 0;
	idx_rx_write = 0;
	idx_tx_read = 0;
	idx_tx_write = 0;

	serial_putc('B');
	serial_putc('O');
	serial_putc('O');
	serial_putc('T');
	error_timeout = 0;
	/*	while(1)
	serial_putc('U');*/
}

#define SHIFT 32
#define USART_SAMPLE_NUM 16
/*
* \internal Calculate asynchronous baudrate value (UART)
*/
uint16_t calculate_baud_value(
const uint32_t baudrate,
const uint32_t peripheral_clock,
uint8_t sample_num)
{
  /* Temporary variables */
  uint64_t ratio = 0;
  uint64_t scale = 0;
  uint64_t baud_calculated = 0;
  uint64_t temp1;
  /* Calculate the BAUD value */
  temp1 = ((sample_num * (uint64_t)baudrate) << SHIFT);
  ratio = long_division(temp1, peripheral_clock);
  scale = ((uint64_t)1 << SHIFT) - ratio;
  baud_calculated = (65536 * scale) >> SHIFT;
  return baud_calculated;
}
/**
 * \brief Open the given USART
 */
void Pcom_open_usart(PcomStatus Pcom)
{

if (Pcom.mode==USART2)
{
	/* Configure the port pins for SERCOM_USART */
	pinMux(Pcom.instance.PinMux.RXD2);
    pinMux(Pcom.instance.PinMux.TXD2);       
}
else if (Pcom.mode==USART)
{
	/* Configure the port pins for SERCOM_USART */
	pinMux(Pcom.instance.PinMux.RXD);
    pinMux(Pcom.instance.PinMux.TXD);       
}

	/* Enable clock for boot_usart_module */
#if (SAMD20 || SAMD21 || SAMD11)
  PM->APBCMASK.reg |= BOOT_USART_BUS_CLOCK_INDEX;
#elif (SAML21)
  MCLK->APBCMASK.reg |= MCLK_APBCMASK_SERCOM0 | MCLK_APBCMASK_SERCOM1 | MCLK_APBCMASK_SERCOM2 | MCLK_APBCMASK_SERCOM3 | MCLK_APBCMASK_SERCOM4 ;
  MCLK->APBDMASK.reg |= MCLK_APBDMASK_SERCOM5;	// On the SAML, SERCOM5 is on the low power bridge
#elif (SAMC21 || SAMC20)
  #if (SAMC21E)
  MCLK->APBCMASK.reg |= MCLK_APBCMASK_SERCOM0 | MCLK_APBCMASK_SERCOM1 | MCLK_APBCMASK_SERCOM2 | MCLK_APBCMASK_SERCOM3 ;
  #elif (SAMC21G) || (SAMC21J)
  MCLK->APBCMASK.reg |= MCLK_APBCMASK_SERCOM0 | MCLK_APBCMASK_SERCOM1 | MCLK_APBCMASK_SERCOM2 | MCLK_APBCMASK_SERCOM3 | MCLK_APBCMASK_SERCOM4 | MCLK_APBCMASK_SERCOM5 ;
#elif (SAMC21N) 
  MCLK->APBCMASK.reg |= MCLK_APBCMASK_SERCOM0 | MCLK_APBCMASK_SERCOM1 | MCLK_APBCMASK_SERCOM2 | MCLK_APBCMASK_SERCOM3 | MCLK_APBCMASK_SERCOM4 | MCLK_APBCMASK_SERCOM5  ;
  MCLK->APBDMASK.reg |=  MCLK_APBDMASK_SERCOM6 | MCLK_APBDMASK_SERCOM7 ;
  #else
  #error "sam_ba_serial.c: Missing dependency or unsupported chip. Please install CMSIS-Atmel from zoubworld (see Prerequisites for Building in README.md)."
  #endif
#else
  #error "sam_ba_serial.c: Missing dependency or unsupported chip. Please install CMSIS-Atmel from zoubworld (see Prerequisites for Building in README.md)."
#endif

	/* Set GCLK_GEN0 as source for GCLK_ID_SERCOMx_CORE */
#if (SAMD20 || SAMD21 || SAMD11)
  GCLK->CLKCTRL.reg = ( GCLK_CLKCTRL_ID( BOOT_USART_PER_CLOCK_INDEX ) | GCLK_CLKCTRL_GEN_GCLK0 | GCLK_CLKCTRL_CLKEN );
  waitForSync();
#elif (SAML21 || SAMC21)
  GCLK->PCHCTRL[BOOT_USART_PER_CLOCK_INDEX].reg = ( GCLK_PCHCTRL_CHEN | GCLK_PCHCTRL_GEN_GCLK0 );
  waitForSync();
#else
  #error "sam_ba_serial.c: Missing dependency or unsupported chip. Please install CMSIS-Atmel from zoubworld (see Prerequisites for Building in README.md)."
#endif


	/* Baud rate 115200 - clock 48MHz -> BAUD value-63018 */
	int baud_value=63018;
	baud_value = calculate_baud_value(Pcom.BaudRate,VARIANT_MCK/*system_gclk_chan_get_hz(BOOT_USART_PER_CLOCK_INDEX/*SERCOM2_GCLK_ID_CORE*//*)*/,USART_SAMPLE_NUM);
	if (Pcom.mode==USART)
{
	uart_basic_init(Pcom.instance.sercom, baud_value, UART_RX_PAD1_TX_PAD0);
	}
else if (Pcom.mode==USART2)
{
	uart_basic_init(Pcom.instance.sercom, baud_value, UART_RX_PAD3_TX_PAD2);
}
	//Initialize flag
	b_sharp_received = false;
	idx_rx_read = 0;
	idx_rx_write = 0;
	idx_tx_read = 0;
	idx_tx_write = 0;

	error_timeout = 0;

}
/**
 * \brief Close communication line
 */
void Pcom_close(PcomStatus Pcom)
{
	uart_disable(Pcom.instance.sercom);
}
/**
 * \brief Close communication line
 */
void serial_close(void)
{
	uart_disable(boot_usart_module);
}

/**
 * \brief Puts a byte on usart line
 * The type int is used to support printf redirection from compiler LIB.
 *
 * \param value      Value to put
 *
 * \return \c 1 if function was successfully done, otherwise \c 0.
 */
int serial_putc(int value)
{	
	uart_write_byte(boot_usart_module, (uint8_t)value);
	return 1;
}
int Pcom_putc(PcomStatus Pcom,int value)
{
	if ((Pcom.mode==USART)||(Pcom.mode==USART2))
	uart_write_byte(Pcom.instance.sercom, (uint8_t)value);
else{
/**to do SPI I2C*/
}
	return 1;
}

int Pcom_getc(PcomStatus Pcom)
{
	uint16_t retval;
	if ((Pcom.mode==USART)||(Pcom.mode==USART2))
	{
	//Wait until input buffer is filled
	while(!(Pcom_is_rx_ready(Pcom)));
	retval = (uint16_t)uart_read_byte(Pcom.instance.sercom);
	}
	else{
/**to do SPI I2C*/
}
	//usart_read_wait(&usart_sam_ba, &retval);
	return (int)retval;

}

int Pcom_sharp_received(PcomStatus Pcom)
{
	if (Pcom_is_rx_ready(Pcom))
  {
		if (serial_getc() == SHARP_CHARACTER)
			return (true);
	}

	return (false);
}

bool Pcom_is_rx_ready(PcomStatus Pcom)
{
	if ((Pcom.mode==USART)||(Pcom.mode==USART2))
	return (Pcom.instance.sercom->USART.INTFLAG.reg & SERCOM_USART_INTFLAG_RXC);
	else{
/**to do SPI I2C*/
return 0;
}
}










int serial_getc(void)
{
	uint16_t retval;
	//Wait until input buffer is filled
	while(!(serial_is_rx_ready()));
	retval = (uint16_t)uart_read_byte(boot_usart_module);
	//usart_read_wait(&usart_sam_ba, &retval);
	return (int)retval;

}

int serial_sharp_received(void)
{
	if (serial_is_rx_ready())
  {
		if (serial_getc() == SHARP_CHARACTER)
			return (true);
	}
	return (false);
}

bool serial_is_rx_ready(void)
{
	return (boot_usart_module->USART.INTFLAG.reg & SERCOM_USART_INTFLAG_RXC);
}



int serial_readc(void)
{
	int retval;
	retval = buffer_rx_usart[idx_rx_read];
	idx_rx_read = (idx_rx_read + 1) & (USART_BUFFER_SIZE - 1);
	return (retval);
}

//Send given data (polling)
uint32_t serial_putdata(void const* data, uint32_t length)
{
	uint32_t i;
	uint8_t* ptrdata;
	ptrdata = (uint8_t*) data;
	for (i = 0; i < length; i++)
  {
		serial_putc(*ptrdata);
		ptrdata++;
	}
	return (i);
}

//Get data from comm. device
uint32_t serial_getdata(void* data, uint32_t length)
{
	uint8_t* ptrdata;
	ptrdata = (uint8_t*) data;
	*ptrdata = serial_getc();
	return (1);
}

static const uint16_t crc16Table[256]=
{
	0x0000,0x1021,0x2042,0x3063,0x4084,0x50a5,0x60c6,0x70e7,
	0x8108,0x9129,0xa14a,0xb16b,0xc18c,0xd1ad,0xe1ce,0xf1ef,
	0x1231,0x0210,0x3273,0x2252,0x52b5,0x4294,0x72f7,0x62d6,
	0x9339,0x8318,0xb37b,0xa35a,0xd3bd,0xc39c,0xf3ff,0xe3de,
	0x2462,0x3443,0x0420,0x1401,0x64e6,0x74c7,0x44a4,0x5485,
	0xa56a,0xb54b,0x8528,0x9509,0xe5ee,0xf5cf,0xc5ac,0xd58d,
	0x3653,0x2672,0x1611,0x0630,0x76d7,0x66f6,0x5695,0x46b4,
	0xb75b,0xa77a,0x9719,0x8738,0xf7df,0xe7fe,0xd79d,0xc7bc,
	0x48c4,0x58e5,0x6886,0x78a7,0x0840,0x1861,0x2802,0x3823,
	0xc9cc,0xd9ed,0xe98e,0xf9af,0x8948,0x9969,0xa90a,0xb92b,
	0x5af5,0x4ad4,0x7ab7,0x6a96,0x1a71,0x0a50,0x3a33,0x2a12,
	0xdbfd,0xcbdc,0xfbbf,0xeb9e,0x9b79,0x8b58,0xbb3b,0xab1a,
	0x6ca6,0x7c87,0x4ce4,0x5cc5,0x2c22,0x3c03,0x0c60,0x1c41,
	0xedae,0xfd8f,0xcdec,0xddcd,0xad2a,0xbd0b,0x8d68,0x9d49,
	0x7e97,0x6eb6,0x5ed5,0x4ef4,0x3e13,0x2e32,0x1e51,0x0e70,
	0xff9f,0xefbe,0xdfdd,0xcffc,0xbf1b,0xaf3a,0x9f59,0x8f78,
	0x9188,0x81a9,0xb1ca,0xa1eb,0xd10c,0xc12d,0xf14e,0xe16f,
	0x1080,0x00a1,0x30c2,0x20e3,0x5004,0x4025,0x7046,0x6067,
	0x83b9,0x9398,0xa3fb,0xb3da,0xc33d,0xd31c,0xe37f,0xf35e,
	0x02b1,0x1290,0x22f3,0x32d2,0x4235,0x5214,0x6277,0x7256,
	0xb5ea,0xa5cb,0x95a8,0x8589,0xf56e,0xe54f,0xd52c,0xc50d,
	0x34e2,0x24c3,0x14a0,0x0481,0x7466,0x6447,0x5424,0x4405,
	0xa7db,0xb7fa,0x8799,0x97b8,0xe75f,0xf77e,0xc71d,0xd73c,
	0x26d3,0x36f2,0x0691,0x16b0,0x6657,0x7676,0x4615,0x5634,
	0xd94c,0xc96d,0xf90e,0xe92f,0x99c8,0x89e9,0xb98a,0xa9ab,
	0x5844,0x4865,0x7806,0x6827,0x18c0,0x08e1,0x3882,0x28a3,
	0xcb7d,0xdb5c,0xeb3f,0xfb1e,0x8bf9,0x9bd8,0xabbb,0xbb9a,
	0x4a75,0x5a54,0x6a37,0x7a16,0x0af1,0x1ad0,0x2ab3,0x3a92,
	0xfd2e,0xed0f,0xdd6c,0xcd4d,0xbdaa,0xad8b,0x9de8,0x8dc9,
	0x7c26,0x6c07,0x5c64,0x4c45,0x3ca2,0x2c83,0x1ce0,0x0cc1,
	0xef1f,0xff3e,0xcf5d,0xdf7c,0xaf9b,0xbfba,0x8fd9,0x9ff8,
	0x6e17,0x7e36,0x4e55,0x5e74,0x2e93,0x3eb2,0x0ed1,0x1ef0
};

//*----------------------------------------------------------------------------
//* \brief Compute the CRC
//*----------------------------------------------------------------------------
unsigned short serial_add_crc(char ptr, unsigned short crc)
{
	return (crc << 8) ^ crc16Table[((crc >> 8) ^ ptr) & 0xff];
}

//*----------------------------------------------------------------------------
//* \brief
//*----------------------------------------------------------------------------
static uint16_t getbytes(uint8_t *ptr_data, uint16_t length)
{
	uint16_t crc = 0;
	uint16_t cpt;
	uint8_t c;

	for (cpt = 0; cpt < length; ++cpt)
  {
		c = serial_getc();
		if (error_timeout)
			return 1;
		crc = serial_add_crc(c, crc);
		//crc = (crc << 8) ^ xcrc16tab[(crc>>8) ^ c];
		if (size_of_data || mode_of_transfer)
    {
			*ptr_data++ = c;
			if (length == PKTLEN_128)
				size_of_data--;
		}
	}

	return crc;
}

//*----------------------------------------------------------------------------
//* \brief Used by Xup to send packets.
//*----------------------------------------------------------------------------
static int putPacket(uint8_t *tmppkt, uint8_t sno)
{
	uint32_t i;
	uint16_t chksm;
	uint8_t data;

	chksm = 0;

	serial_putc(SOH);

	serial_putc(sno);
	serial_putc((uint8_t) ~(sno));

	for (i = 0; i < PKTLEN_128; i++)
  {
		if (size_of_data || mode_of_transfer)
    {
			data = *tmppkt++;
			size_of_data--;
		}
    else
			data = 0x00;

		serial_putc(data);

		//chksm = (chksm<<8) ^ xcrc16tab[(chksm>>8)^data];
		chksm = serial_add_crc(data, chksm);
	}

	/* An "endian independent way to extract the CRC bytes. */
	serial_putc((uint8_t) (chksm >> 8));
	serial_putc((uint8_t) chksm);

	return (serial_getc()); /* Wait for ack */
}

//*----------------------------------------------------------------------------
//* \brief Called when a transfer from target to host is being made (considered
//*        an upload).
//*----------------------------------------------------------------------------
//Send given data (polling) using xmodem (if necessary)
uint32_t serial_putdata_xmd(void const* data, uint32_t length)
{
	uint8_t c, sno = 1;
	uint8_t done;
	uint8_t * ptr_data = (uint8_t *) data;
	error_timeout = 0;
	if (!length)
		mode_of_transfer = 1;
	else
  {
		size_of_data = length;
		mode_of_transfer = 0;
	}

	if (length & (PKTLEN_128 - 1))
  {
		length += PKTLEN_128;
		length &= ~(PKTLEN_128 - 1);
	}

	/* Startup synchronization... */
	/* Wait to receive a NAK or 'C' from receiver. */
	done = 0;
	while (!done) {
		c = (uint8_t) serial_getc();
		if (error_timeout)
    { // Test for timeout in serial_getc
			error_timeout = 0;
			c = (uint8_t) serial_getc();
			if (error_timeout)
      {
				error_timeout = 0;
				return (0);
			}
		}
		switch (c)
    {
      case NAK:
        done = 1;
        // ("CSM");
			break;
      case 'C':
        done = 1;
        // ("CRC");
			break;
      case 'q': /* ELS addition, not part of XMODEM spec. */
        return (0);
      default:
			break;
		}
	}

	done = 0;
	sno = 1;
	while (!done)
  {
		c = (uint8_t) putPacket((uint8_t *) ptr_data, sno);
		if (error_timeout)
    { // Test for timeout in serial_getc
			error_timeout = 0;
			return (0);
		}
		switch (c)
    {
      case ACK:
        ++sno;
        length -= PKTLEN_128;
        ptr_data += PKTLEN_128;
        // ("A");
			break;

      case NAK:
        // ("N");
			break;

      case CAN:
      case EOT:
      default:
        done = 0;
			break;
		}

		if (!length)
    {
			serial_putc(EOT);
			serial_getc(); /* Flush the ACK */
			break;
		}
		// ("!");
	}

	mode_of_transfer = 0;
	// ("Xup_done.");
	return (1);
	//    return(0);
}

/*----------------------------------------------------------------------------
 * \brief Used by serial_getdata_xmd to retrieve packets.
 */
static uint8_t getPacket(uint8_t *ptr_data, uint8_t sno)
{
	uint8_t seq[2];
	uint16_t crc, xcrc;

	getbytes(seq, 2);
	xcrc = getbytes(ptr_data, PKTLEN_128);
	if (error_timeout)
		return (false);

	/* An "endian independent way to combine the CRC bytes. */
	crc = (uint16_t) serial_getc() << 8;
	crc += (uint16_t) serial_getc();

	if (error_timeout == 1)
		return (false);

	if ((crc != xcrc) || (seq[0] != sno) || (seq[1] != (uint8_t) (~sno)))
  {
		serial_putc(CAN);
		return (false);
	}

	serial_putc(ACK);
	return (true);
}

//*----------------------------------------------------------------------------
//* \brief Called when a transfer from host to target is being made (considered
//*        an download).
//*----------------------------------------------------------------------------
//Get data from comm. device using xmodem (if necessary)
uint32_t serial_getdata_xmd(void* data, uint32_t length)
{
	uint32_t timeout;
	char c;
	uint8_t * ptr_data = (uint8_t *) data;
	uint32_t b_run, nbr_of_timeout = 100;
	uint8_t sno = 0x01;
	uint32_t data_transfered = 0;

	//Copied from legacy source code ... might need some tweaking
	uint32_t loops_per_second = VARIANT_MCK/60;

	error_timeout = 0;

	if (length == 0)
		mode_of_transfer = 1;
	else
  {
		size_of_data = length;
		mode_of_transfer = 0;
	}

	/* Startup synchronization... */
	/* Continuously send NAK or 'C' until sender responds. */
	// ("Xdown");
	while (1)
  {
		serial_putc('C');
		timeout = loops_per_second;
		while (!(serial_is_rx_ready()) && timeout)
			timeout--;
		if (timeout)
			break;

		if (!(--nbr_of_timeout))
			return (0);
//            return -1;
	}

	b_run = true;
	// ("Got response");
	while (b_run != false)
  {
		c = (char) serial_getc();
		if (error_timeout)
    { // Test for timeout in serial_getc
			error_timeout = 0;
			return (0);
//            return (-1);
		}
		switch (c)
    {
      case SOH: /* 128-byte incoming packet */
        // ("O");
        b_run = getPacket(ptr_data, sno);
        if (error_timeout)
        { // Test for timeout in serial_getc
          error_timeout = 0;
          return (0);
  //                return (-1);
        }
        if (b_run == true)
        {
          ++sno;
          ptr_data += PKTLEN_128;
          data_transfered += PKTLEN_128;
        }
			break;
      case EOT: // ("E");
        serial_putc(ACK);
        b_run = false;
			break;
      case CAN: // ("C");
      case ESC: /* "X" User-invoked abort */
      default:
        b_run = false;
			break;
		}
		// ("!");
	}
	mode_of_transfer = 0;
	return (true);
//    return(b_run);
}

