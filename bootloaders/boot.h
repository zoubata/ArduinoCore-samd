

#ifndef __BOOT_H__
#define __BOOT_H__ 1
//#include "util.h"
/** 
This file can be included to the main application to allow to jump in the boot from the application, 
Note that BOOT_DOUBLE_TAP_ENABLED must be define on the bootloader used


*/  
#define DOUBLE_TAP_MAGIC 0x07738135
  #if (SAMD21 || SAMD11)
  #define BOOT_DOUBLE_TAP_ADDRESS           (HMCRAMC0_ADDR + HMCRAMC0_SIZE - 4)
#elif (SAML21 || SAMC21 || SAMC20 || SAMD20)
	
#ifdef HSRAM_SIZE
  #define BOOT_DOUBLE_TAP_ADDRESS           (HSRAM_ADDR + HSRAM_SIZE - 4)
  #else
	#define BOOT_DOUBLE_TAP_ADDRESS           (HRAMC0_ADDR + HRAMC0_SIZE - 4)
    
  #endif
#else
  #error "board_definitions.h: Missing dependency or unsupported chip. Please install CMSIS-Atmel from zoubworld (see Prerequisites for Building in README.md)."
#endif

#define BOOT_DOUBLE_TAP_DATA              (*((volatile uint32_t *) BOOT_DOUBLE_TAP_ADDRESS))

#if ( defined (__GNUC__))
static __inline__ 
#elif defined( __ICCARM__)
static inline
//! @}
#endif

 void jumpInBoot()
 {
	 BOOT_DOUBLE_TAP_DATA = DOUBLE_TAP_MAGIC;
	 uint32_t * __sketch_vectors_ptr_reboot=0; // Exported value from linker script
	 uint32_t* pulSketch_Start_Address_reboot;
  pulSketch_Start_Address_reboot = __sketch_vectors_ptr_reboot ;
  pulSketch_Start_Address_reboot++ ;
  /* Rebase the Stack Pointer */
  __set_MSP( (uint32_t)(*__sketch_vectors_ptr_reboot) );

  /* Rebase the vector table base address */
  SCB->VTOR = ((uint32_t)(__sketch_vectors_ptr_reboot) & SCB_VTOR_TBLOFF_Msk);

  /* Jump to application Reset Handler in the application */
  asm("bx %0"::"r"(*pulSketch_Start_Address_reboot));
  }
#endif