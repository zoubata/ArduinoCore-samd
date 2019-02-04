/*
  Copyright (c) 2015 Arduino LLC.  All right reserved.

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

#define ARDUINO_MAIN
#include "Arduino.h"
#include "sam.h"

/* RTOS Hooks */
extern void svcHook(void);
extern void pendSVHook(void);
extern "C" 
{
	int sysTickHook(void);
}// extern "C" {
// Weak empty variant initialization function.
// May be redefined by variant files.

/*

#define TRACE_BUFFER_SIZE 1024
#define STOP_MTB() {REG_MTB_MASTER = 0x00000000 + 6;   }
#ifdef __ICCARM__
#else
__attribute__((__aligned__(TRACE_BUFFER_SIZE * sizeof(uint32_t))))
#endif
uint32_t mtb[TRACE_BUFFER_SIZE];

void enableMTB()
{
REG_MTB_POSITION = ((uint32_t) (mtb - REG_MTB_BASE)) & 0xFFFFFFF8;
REG_MTB_FLOW = ((uint32_t) mtb + TRACE_BUFFER_SIZE * sizeof(uint32_t)) & 0xFFFFFFF8;
REG_MTB_MASTER = 0x80000000 + 6;
}
*/
void enableMTB2()
{
REG_MTB_POSITION = ((uint32_t) (0x20006000 )) & 0xFFFFFFF8;
REG_MTB_FLOW = ((uint32_t) 0x20007FFF) & 0xFFFFFFF8;
REG_MTB_MASTER = 0x80000000 + 6;
}


void initVariant() __attribute__((weak));
void initVariant() { }

// Initialize C library
extern "C"  void __libc_init_array(void)



#if ( defined(__ICCARM__) || defined(__AARM__) )
 __attribute__((weak));
void __libc_init_array() { };
#else
;
#endif
void init_debug() ;		
/*
 * \brief Main entry point of Arduino application
 */
  
int main( void )
{
  init_debug() ;
enableMTB2();		
  SystemInit();// init of system clock
  init(); // wire init for sercom/timer/analog
  __libc_init_array();// to setup symbols :
  
   
 // __libc_init_array();//done in reset handler to setup symbols :
/*
These symbols are related to the C / C++ constructor and destructor startup and tear down code that is called before / after main(). Sections named .init, .ctors, .preinit_array, and .init_array are to do with initialization of C/C++ objects, and sections .fini, .fini_array, and .dtors are for tear down. The start and end symbols define the beginning and end of code sections related to such operations and might be referenced from other parts of the runtime support code.
The .preinit_array and .init_array sections contain arrays of pointers to functions that will be called on initialization. The .fini_array is an array of functions that will be called on destruction. Presumably the start and end labels are used to walk these lists.
A good example of code that uses these symbols is to be found here libc source for initfini.c. You can see that on startup, __libc_init_array() is called and this first calls all the function pointers in section .preinit_array by referring to the start and end labels. Then it calls the _init() function in the .init section. Lastly it calls all the function pointers in section .init_array. After main() is complete the teardown call to __libc_fini_array() causes all the functions in .fini_array to be called, before finally calling _fini(). Note that there seems to be a cut-and-paste bug in this code when it calculates the count of functions to call at teardown. Presumably they were dealing with a real time micro controller OS and never encountered this section.
*/

  initVariant();


	
  delay(1);
#if defined(USBCON) && !defined(USB_DISABLED)
  USBDevice.init();
  USBDevice.attach();
#endif
//STOP_MTB();

  setup();

  for (;;)
  {
    loop();
    if (serialEventRun) serialEventRun();
  }
  return 0;
}
