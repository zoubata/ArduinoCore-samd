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

#include <stdio.h>
#include <stdbool.h>
#include <sam.h>
#include "sam_ba_monitor.h"
#include "sam_ba_serial.h"
#include "board_definitions/board_definitions.h"
#include "board_driver_led.h"
#if defined(SDCARD_ENABLED)
#include "SDCard/sdBootloader.h"
#endif
#include "util.h"
#if (SAMD21 || SAMD11 || SAML21)
#include "sam_ba_usb.h"
#include "sam_ba_cdc.h"
#endif
#include "cores\arduino\WVariant.h"
#include "Variant.h"


const struct PComUcDescription g_PComDescription[]=
{
  {{  PINMUX_PA08C_SERCOM0_PAD0, PINMUX_PA09C_SERCOM0_PAD1, PINMUX_PA10C_SERCOM0_PAD2, PINMUX_PA11C_SERCOM0_PAD3, PINMUX_UNUSED, PINMUX_UNUSED },SERCOM0/*,SPI0*/}, //  
  {{  PINMUX_PA04D_SERCOM0_PAD0, PINMUX_PA05D_SERCOM0_PAD1, PINMUX_PA06D_SERCOM0_PAD2, PINMUX_PA07D_SERCOM0_PAD3,PINMUX_UNUSED,PINMUX_UNUSED },SERCOM0/*,SPI0_BIS*/}, //  
  {{ PINMUX_PA00D_SERCOM1_PAD0,PINMUX_PA01D_SERCOM1_PAD1,PINMUX_PA30D_SERCOM1_PAD2,PINMUX_PA31D_SERCOM1_PAD3,PINMUX_UNUSED,PINMUX_UNUSED },SERCOM1/*,SPI1*/}, //  
  {{ PINMUX_PA12C_SERCOM2_PAD0,PINMUX_PA13C_SERCOM2_PAD1,PINMUX_PA14C_SERCOM2_PAD2,PINMUX_PA15C_SERCOM2_PAD3,PINMUX_UNUSED,PINMUX_UNUSED },SERCOM2/*,SPI2*/}, //  
  {{ PINMUX_PA22C_SERCOM3_PAD0,PINMUX_PA23C_SERCOM3_PAD1,PINMUX_PA24C_SERCOM3_PAD2,PINMUX_PA25C_SERCOM3_PAD3,PINMUX_UNUSED,PINMUX_UNUSED },SERCOM3/*,SPI3*/}, //  
  {{ PINMUX_PB12C_SERCOM4_PAD0,PINMUX_PB13C_SERCOM4_PAD1,PINMUX_PB14C_SERCOM4_PAD2,PINMUX_PB15C_SERCOM4_PAD3,PINMUX_UNUSED,PINMUX_UNUSED },SERCOM4/*,SPI4*/}, //  
  {{ PINMUX_PB30D_SERCOM5_PAD0,PINMUX_PB31D_SERCOM5_PAD1,PINMUX_PB22D_SERCOM5_PAD2,PINMUX_PB23D_SERCOM5_PAD3,PINMUX_UNUSED,PINMUX_UNUSED },SERCOM5/*,SPI5*/}, //  
};


extern uint32_t __sketch_vectors_ptr; // Exported value from linker script
extern volatile int8_t ledDirection;
extern void board_init(void);

#if (defined DEBUG) && (DEBUG == 1)
volatile uint32_t* pulSketch_Start_Address;
#endif

static volatile bool main_b_cdc_enable = false;

/**
 * \brief Check the application startup condition
 *
 */
static void check_start_application(void)
{

#if (!defined DEBUG) || ((defined DEBUG) && (DEBUG == 0))
uint32_t* pulSketch_Start_Address;
#endif

  /*
   * Test sketch stack pointer @ &__sketch_vectors_ptr
   * Stay in SAM-BA if value @ (&__sketch_vectors_ptr) == 0xFFFFFFFF (Erased flash cell value)
   */
  if (__sketch_vectors_ptr == 0xFFFFFFFF)
  {
    /* Stay in bootloader */
    return;
  }

  /*
   * Load the sketch Reset Handler address
   * __sketch_vectors_ptr is exported from linker script and point on first 32b word of sketch vector table
   * Remember, variables exported from a linker script are different than normal variables (only address, no value)
   * First 32b word is sketch stack
   * Second 32b word is sketch entry point: Reset_Handler()
   */
  pulSketch_Start_Address = &__sketch_vectors_ptr ;
  pulSketch_Start_Address++ ;

  /*
   * Test vector table address of sketch @ &__sketch_vectors_ptr
   * Stay in SAM-BA if this function is not aligned enough, ie not valid
   */
  if ( ((uint32_t)(&__sketch_vectors_ptr) & ~SCB_VTOR_TBLOFF_Msk) != 0x00)
  {
    /* Stay in bootloader */
    return;
  }
#if defined(BOOT_LOAD_PIN_ENABLED)
  pinConfig(BOOT_LOAD_PIN_PORT, BOOT_LOAD_PIN, BOOT_LOAD_PIN_CONFIG);

  /* Allow time for debouncing capacitor (if using a button) to charge (10ms) */
  delayUs(10000UL);

  // Read the BOOT_LOAD_PIN status
  if (isPinActive(BOOT_LOAD_PIN_PORT, BOOT_LOAD_PIN, BOOT_LOAD_PIN_POLARITY))
  {
    // Stay in bootloader
    return;
  }
#endif

#if defined(BOOT_DOUBLE_TAP_ENABLED)
  #define DOUBLE_TAP_MAGIC 0x07738135
#if (SAMD21 || SAMD11)
  if (PM->RCAUSE.bit.POR)
#elif (SAML21 || SAMC21)
  if (RSTC->RCAUSE.bit.POR)
#else
  #error "main.c: Missing dependency or unsupported chip. Please install CMSIS-Atmel from MattairTech (see Prerequisites for Building in README.md)."
#endif
  {
    /* On power-on initialize double-tap */
    BOOT_DOUBLE_TAP_DATA = 0;
  }
  else
  {
    if (BOOT_DOUBLE_TAP_DATA == DOUBLE_TAP_MAGIC)
    {
      /* Second tap, stay in bootloader */
      BOOT_DOUBLE_TAP_DATA = 0;
      return;
    }

    /* First tap */
    BOOT_DOUBLE_TAP_DATA = DOUBLE_TAP_MAGIC;

    /* Wait 0.5sec to see if the user tap reset again */
    delayUs(500000UL);

    /* Timeout happened, continue boot... */
    BOOT_DOUBLE_TAP_DATA = 0;
  }
#endif



  /* Rebase the Stack Pointer */
  __set_MSP( (uint32_t)(__sketch_vectors_ptr) );

  /* Rebase the vector table base address */
  SCB->VTOR = ((uint32_t)(&__sketch_vectors_ptr) & SCB_VTOR_TBLOFF_Msk);

  /* Jump to application Reset Handler in the application */
  asm("bx %0"::"r"(*pulSketch_Start_Address));
}

#if DEBUG_ENABLE
#	define DEBUG_PIN_HIGH 	port_pin_set_output_level(BOOT_LED, 1)
#	define DEBUG_PIN_LOW 	port_pin_set_output_level(BOOT_LED, 0)
#else
#	define DEBUG_PIN_HIGH 	do{}while(0)
#	define DEBUG_PIN_LOW 	do{}while(0)
#endif
	volatile int ina1=0;
	volatile int inb1=0;
	volatile int ticks1  = 0;
	volatile int ina2=0;
	volatile int inb2=0;
	volatile int ticks2  = 0;
	volatile int ina3=0;
	volatile int inb3=0;
	volatile int baud1=0;
	volatile int ticks3=0;
	int in1[2];// 1st edge
	int in2[2];// 2nd edge
	
	#define getPin(x) (x>>16)
	#define MASKPIN (0x3FFFFFFF &(~(1<<BOARD_LED_PIN)))
void autodetect(PcomStatus * Pcom)
{// detect :
for(int pin=0;pin<PORT_BITS;pin++)
{
	PORT->Group[pin >>5].PINCFG[pin & 0x1F].bit.INEN=1;
	PORT->Group[pin >>5].PINCFG[pin & 0x1F].bit.PULLEN=1;
	PORT->Group[pin >>5].OUT.reg=(PORT->Group[pin >>5].OUT.reg)&~(1L<<(pin & 0x1F));
	PORT->Group[pin >>5].DIR.reg=(PORT->Group[pin >>5].OUT.reg)&~(1L<<(pin & 0x1F));
}
	 ina1=((PORT->Group[0].IN.reg))& MASKPIN;// hide SWD for debug
	 inb1=(PORT->Group[1].IN.reg);
	ina2=ina1;
	inb2=inb1;
	while ((ina2==ina1) && (inb1==(inb2)))
	{ 
		ina2=(PORT->Group[0].IN.reg)& MASKPIN;// hide SWD for debug
		inb2=(PORT->Group[1].IN.reg);
		
	};//detect by soft a toggle
	 ticks1  = SysTick->VAL;
	ina3=ina2;
	inb3=inb2;
	while (((inb3)==ina2) && (inb2==(ina3)))
		{
		ina3=PORT->Group[0].IN.reg&MASKPIN;// hide SWD for debug
		inb3=PORT->Group[1].IN.reg;
		
	};
	  ticks2  = SysTick->VAL;
	  
	  
    while ((PORT->Group[0].IN.reg==ina3) && (inb3==PORT->Group[1].IN.reg));
	  ticks3  = SysTick->VAL;
	
	if (ticks1<ticks2) ticks1+=MASKPIN;
	volatile int baud1=VARIANT_MCK/(ticks1-ticks2);
	if (ticks2<ticks3) ticks2+=MASKPIN;
	volatile int baud2=VARIANT_MCK/(ticks2-ticks3);
	volatile int N=baud1/baud2;
	volatile int baud=0;
	if (N>1)// check if several bit.
	{
		baud=baud2;		
	}
	else
		baud=baud1;	
	in1[0]=(ina1^ina2);
	in1[1]=(inb1^inb2);

	in2[0]=(ina3^ina2);
	in2[1]=(inb3^inb2);
	for(int i=0;i<7;i++)
	{
		if ((in1[i/32]>>(i%32))==1)
		{
			for(int p=0;p<6;p++)
				if (getPin(P_COM[p].PinMux.SS)==i)// 1st edge should be SS in SPI
				{
					Pcom->mode=SPI_SLAVE;
					Pcom->instance=P_COM[p];
					Pcom->BaudRate=0;
					return ;
				}
				else
					if (getPin(P_COM[p].PinMux.RXD2)==i)// 1st edge should be DXS in usart
				{
					Pcom->mode=USART2;
					Pcom->instance=P_COM[p];
					Pcom->BaudRate=baud;
					return ;
				}
				else
					if (getPin(P_COM[p].PinMux.RXD)==i)// 1st edge should be DXS in usart
					{
						Pcom->mode=USART;
						Pcom->instance=P_COM[p];
						Pcom->BaudRate=baud;
						return ;
				}
				else
					if (getPin(P_COM[p].PinMux.SDA)==i)// 1st edge should be SDA in I2C
					{
						Pcom->mode=I2C;
					Pcom->instance=P_COM[p];
					Pcom->BaudRate=0;
					return ;
					}
		}
	}		
}
/**
 *  \brief SAMD21 SAM-BA Main loop.
 *  \return Unused (ANSI-C compatibility).
 */
int main(void)
{
   init_debug() ;
#if SAM_BA_INTERFACE == SAM_BA_USBCDC_ONLY  ||  SAM_BA_INTERFACE == SAM_BA_BOTH_INTERFACES
  P_USB_CDC pCdc;
#endif
  DEBUG_PIN_HIGH;
  

  /* Jump in application if condition is satisfied */
  check_start_application();

  /* We have determined we should stay in the monitor. */
  /* System initialization */
  board_init();
  __enable_irq();
  /* Initialize LEDs */
  LED_init();
  #if !defined(BOARD_LED_FADE_ENABLED)
  LED_on();
  #endif
  LEDRX_init();
  LEDRX_off();
  LEDTX_init();
  LEDTX_off();

  /* Start the sys tick (20 us) */
  SysTick_Config(VARIANT_MCK / 50000);


/* If SDCARD_ENABLED defined, read optional external pins and run SD Card bootloader (if enabled).
 */
  #if defined(SDCARD_ENABLED)
    uint8_t bootloaderMode = SD_BOOTLOADER_MODE_NO_UPDATE;
    #if defined(SAM_BA_INTERFACE_USE_PIN)
      uint8_t sdcardStatus = SD_BOOTLOADER_NOT_CALLED;
    #endif

    #if defined(SDCARD_USE_PIN1)
      pinConfig(SDCARD_PIN1_PORT, SDCARD_PIN1_PIN, SDCARD_PIN1_CONFIG);
    #endif
    #if defined(SDCARD_USE_PIN2)
      #if !defined(SDCARD_USE_PIN1)
        #error "main.c: When SDCARD_USE_PIN2 is defined, SDCARD_USE_PIN1 must also be defined"
      #endif
      pinConfig(SDCARD_PIN2_PORT, SDCARD_PIN2_PIN, SDCARD_PIN2_CONFIG);
    #endif

    #if (defined(SDCARD_USE_PIN1) && defined(SDCARD_USE_PIN2))
      bool pin1 = isPinActive(SDCARD_PIN1_PORT, SDCARD_PIN1_PIN, SDCARD_PIN1_POLARITY);
      bool pin2 = isPinActive(SDCARD_PIN2_PORT, SDCARD_PIN2_PIN, SDCARD_PIN2_POLARITY);
      if (pin1) {
        bootloaderMode = SD_BOOTLOADER_MODE_UPDATE;
      } else if (pin2) {
        bootloaderMode = SD_BOOTLOADER_MODE_UPDATE2;
      }
    #elif defined(SDCARD_USE_PIN1)
      if (isPinActive(SDCARD_PIN1_PORT, SDCARD_PIN1_PIN, SDCARD_PIN1_POLARITY)) {
        bootloaderMode = SD_BOOTLOADER_MODE_UPDATE;
      }
    #else
      bootloaderMode = SD_BOOTLOADER_MODE_UPDATE;
    #endif

    if (bootloaderMode != SD_BOOTLOADER_MODE_NO_UPDATE) {
    #if defined(SAM_BA_INTERFACE_USE_PIN)
      sdcardStatus = sdBootloader(bootloaderMode);
    #else
      sdBootloader(bootloaderMode);
    #endif
    }
  #endif

/* When using SAM_BA_INTERFACE_USE_PIN, check the pin to determine which SAM-BA interface to use.
 */
#if defined(SAM_BA_INTERFACE_USE_PIN)
  uint8_t sambaInterface = SAM_BA_NONE;
  pinConfig(SAM_BA_INTERFACE_PIN_PORT, SAM_BA_INTERFACE_PIN_PIN, SAM_BA_INTERFACE_PIN_CONFIG);

  if (isPinActive(SAM_BA_INTERFACE_PIN_PORT, SAM_BA_INTERFACE_PIN_PIN, PIN_POLARITY_ACTIVE_LOW)) {      // pin is low
  #if ((SAM_BA_INTERFACE == SAM_BA_BOTH_INTERFACES) && (SAM_BA_INTERFACE_PIN_POLARITY == PIN_POLARITY_USBCDC_LOW))
    sambaInterface = SAM_BA_USBCDC_ONLY;
  #elif ((SAM_BA_INTERFACE == SAM_BA_USBCDC_ONLY) && (SAM_BA_INTERFACE_PIN_POLARITY == PIN_POLARITY_ACTIVE_LOW))
    sambaInterface = SAM_BA_USBCDC_ONLY;
  #elif ((SAM_BA_INTERFACE == SAM_BA_UART_ONLY) && (SAM_BA_INTERFACE_PIN_POLARITY == PIN_POLARITY_ACTIVE_LOW))
    sambaInterface = SAM_BA_UART_ONLY;
  #endif
  } else {      // pin is high
  #if ((SAM_BA_INTERFACE == SAM_BA_BOTH_INTERFACES) && (SAM_BA_INTERFACE_PIN_POLARITY == PIN_POLARITY_USBCDC_HIGH))
    sambaInterface = SAM_BA_USBCDC_ONLY;
  #elif ((SAM_BA_INTERFACE == SAM_BA_USBCDC_ONLY) && (SAM_BA_INTERFACE_PIN_POLARITY == PIN_POLARITY_ACTIVE_HIGH))
    sambaInterface = SAM_BA_USBCDC_ONLY;
  #elif ((SAM_BA_INTERFACE == SAM_BA_UART_ONLY) && (SAM_BA_INTERFACE_PIN_POLARITY == PIN_POLARITY_ACTIVE_HIGH))
    sambaInterface = SAM_BA_UART_ONLY;
  #endif
  }
#endif

/* Check if we should continue with a SAM-BA interface (if compiled and enabled).
 * Only show LED_STATUS_FILE_NOT_FOUND if a SAM-BA interface is not available.
 * LED_STATUS_FILE_NOT_FOUND occurs if there is no SD Card, no FAT16/FAT32
 * filesystem, or no file (UPDATE.BIN or UPDATE2.BIN) in the root directory.
 */
#if defined(SAM_BA_INTERFACE_USE_PIN)
  #if defined(SDCARD_ENABLED)
  if (sambaInterface == SAM_BA_NONE) {
    if (sdcardStatus == SD_BOOTLOADER_FILE_NOT_FOUND) {
      LED_status(LED_STATUS_FILE_NOT_FOUND);
    } else if (sdcardStatus == SD_BOOTLOADER_NOT_CALLED) {
      LED_status(LED_STATUS_NO_SAM_BA_INTERFACE);
    }
  }
  #else
    #if (SAM_BA_INTERFACE == SAM_BA_NONE)
      LED_status(LED_STATUS_NO_SAM_BA_INTERFACE);
    #else
    if (sambaInterface == SAM_BA_NONE) {
      LED_status(LED_STATUS_NO_SAM_BA_INTERFACE);
    }
    #endif
  #endif
#else
  #if (SAM_BA_INTERFACE == SAM_BA_NONE)
    LED_status(LED_STATUS_NO_SAM_BA_INTERFACE);
  #endif
#endif

/* Enable the appropriate SAM-BA interfaces. When using SAM_BA_INTERFACE_USE_PIN,
 * the peripheral and pins are only setup for the selected/enabled interface.
 */
#if defined(SAM_BA_INTERFACE_USE_PIN)
  if (sambaInterface == SAM_BA_UART_ONLY) {
#endif

#if SAM_BA_INTERFACE == SAM_BA_UART_ONLY  ||  SAM_BA_INTERFACE == SAM_BA_BOTH_INTERFACES

#if defined(AUTO_DETECT_ENABLED)
PcomStatus Pcom=PCOMSTATUS_EMPTY;
autodetect(&Pcom);

#else  /* UART is enabled in all cases */
  serial_open(115200);
#endif
#endif
#if defined(SAM_BA_INTERFACE_USE_PIN)
  } else if (sambaInterface == SAM_BA_USBCDC_ONLY) {
#endif

#if SAM_BA_INTERFACE == SAM_BA_USBCDC_ONLY  ||  SAM_BA_INTERFACE == SAM_BA_BOTH_INTERFACES
  pCdc = usb_init();
#endif
#if defined(SAM_BA_INTERFACE_USE_PIN)
  }
#endif


  ledDirection = 4;

  DEBUG_PIN_LOW;


  /* Wait for a complete enum on usb or a '#' char on serial line */
  while (1)
  {
#if defined(SAM_BA_INTERFACE_USE_PIN)
    if (sambaInterface == SAM_BA_USBCDC_ONLY) {
#endif
#if SAM_BA_INTERFACE == SAM_BA_USBCDC_ONLY  ||  SAM_BA_INTERFACE == SAM_BA_BOTH_INTERFACES
    if (pCdc->IsConfigured(pCdc) != 0)
    {
      main_b_cdc_enable = true;
    }

    /* Check if a USB enumeration has succeeded and if comm port has been opened */
    if (main_b_cdc_enable)
    {
      sam_ba_monitor_init(SAM_BA_INTERFACE_USBCDC);
      /* SAM-BA on USB loop */
      while( 1 )
      {
        sam_ba_monitor_run();
      }
    }
#endif
#if defined(SAM_BA_INTERFACE_USE_PIN)
    } else if (sambaInterface == SAM_BA_UART_ONLY) {
#endif

#if SAM_BA_INTERFACE == SAM_BA_UART_ONLY  ||  SAM_BA_INTERFACE == SAM_BA_BOTH_INTERFACES
    /* Check if a '#' has been received */
    if (!main_b_cdc_enable && serial_sharp_received())
    {
      sam_ba_monitor_init(SAM_BA_INTERFACE_USART);
      /* SAM-BA on Serial loop */
      while(1)
      {
        sam_ba_monitor_run();
      }
    }
#endif
#if defined(SAM_BA_INTERFACE_USE_PIN)
    }
#endif
  }
}

void SysTick_Handler(void)
{
#if (defined(BOARD_LED_FADE_ENABLED) && defined(BOARD_LED_PORT))
  LED_pulse();
#endif

  sam_ba_monitor_sys_tick();
}
