/*
 * Copyright (c) 2015 Arduino LLC.  All right reserved.
 * Copyright (c) 2015 Atmel Corporation/Thibaut VIARD.  All right reserved.
 * Copyright (c) 2017 MattairTech LLC. All right reserved.
 * Copyright (C) 2014, ChaN, all right reserved.
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef _UTIL_H_
#define _UTIL_H_

#include "sam.h"
#include <stdbool.h>
#include "board_definitions/board_definitions.h"

extern unsigned int s_fcpu_hz;
#define SYSTICK_NUMBER_CYCLE 1
#ifdef __ICCARM__
/*! \name Compiler Keywords
 *
 * Port of some keywords from GCC to IAR Embedded Workbench.
 */
//! @{
#define __asm__              asm
#define __inline__           inline
#define __volatile__
//! @}
#endif

#define TRUE (1==1)
#define FALSE (1==0)

// TODO: Variable bootloader sizes
#if (SAMD11)
  #define APP_START 0x00001000
#else
  #define APP_START 0x00002000
#endif

#define SCB_AIRCR_VECTKEY_Val   0x05FA

void flashErase (uint32_t startAddress);
void flashWrite (uint32_t startAddress, uint32_t * buffer, uint32_t * ptr_data);
void pinMux (uint32_t pinmux);
void systemReset (void);
void pinConfig (uint8_t port, uint8_t pin, uint8_t config);
bool isPinActive (uint8_t port, uint8_t pin, uint8_t config);
void delayUs (unsigned int delay);
void waitForSync (void);


/*
#define Get_sys_count()     ( (SysTick->VAL)  & SysTick_VAL_CURRENT_Msk       )
#define Set_sys_count( val )     SysTick->VAL=(val  & SysTick_VAL_CURRENT_Msk )


//! Structure holding private information, automatically initialized by the
//! cpu_set_timeout() function.
typedef struct
{
  //! The cycle count at the begining of the timeout.
  unsigned long delay_start_cycle;

  //! The cycle count at the end of the timeout.
  unsigned long delay_end_cycle;

  //! Enable/disable the timout detection
  unsigned char timer_state;
  #define CPU_TIMER_STATE_STARTED 0
  #define CPU_TIMER_STATE_REACHED 1
  #define CPU_TIMER_STATE_STOPPED 2
} t_cpu_time;

// precomputed factor to reduce compute time on the fly about 100µs

extern uint32_t us2CyFactor;


#define  cpu_us_2_cy_fast( Nus )    (((unsigned long)Nus * us2CyFactor)>>10)     

#define  cpu_ms_2_cy_fast( Nus )    (((unsigned long)Nus * us2CyFactor))     

//!
// \brief Set a timer variable.
//
// Ex:  t_cpu_time timer;
//      cpu_set_timeout( cpu_ms_2_cy(10, FOSC0), &timer ); // timeout in 10 ms
//      if( cpu_is_timeout(&timer) )
//         cpu_stop_timeout(&timer);
//         ../..
// \param  delay:   (input) delay in CPU cycles before timeout.
// \param  cpu_time: (output) internal information used by the timer API.
///
#if (defined __GNUC__)
__attribute__((__always_inline__))
static  __inline__
#else
static inline
#endif
 void cpu_set_timeout(unsigned long delay, t_cpu_time *cpu_time)
{
  cpu_time->delay_start_cycle = Get_sys_count();
  cpu_time->delay_end_cycle   = (cpu_time->delay_start_cycle - delay) & SysTick_VAL_CURRENT_Msk;
  if      ( delay==0)
     cpu_time->timer_state       = CPU_TIMER_STATE_REACHED; // as wait time is 0 it is already reach
  else
  cpu_time->timer_state       = CPU_TIMER_STATE_STARTED;
}

extern signed int TimeStamp1,TimeStamp2;

#define SetTimeStamp1()  TimeStamp1=Get_sys_count();
#define SetTimeStamp2()  TimeStamp2=Get_sys_count();
//!
// \brief Set a timer variable.
//
// Ex:  t_cpu_time timer;
//      cpu_set_timeout( cpu_ms_2_cy(10, FOSC0), &timer ); // timeout in 10 ms
//      if( cpu_is_timeout(&timer) )
//         cpu_stop_timeout(&timer);
//         ../..
//
// \param  delay:   (input) delay in CPU cycles before timeout.
// \param  cpu_time: (output) internal information used by the timer API.
///

#define  cpu_set_timeout_fast( delay, cpu_time )                               \
{                                                                              \
  if      ( delay==0)                                                          \
  {                                                                            \
  cpu_time.timer_state       = CPU_TIMER_STATE_REACHED;                        \
 cpu_time.delay_end_cycle   = 0;                                              \
                                                                               \
  }                                                                            \
  else                                                                         \
  {                                                                            \
  cpu_time.timer_state       = CPU_TIMER_STATE_STARTED;                        \
  cpu_time.delay_start_cycle = SysTick_LOAD_RELOAD_Msk;                        \
  cpu_time.delay_end_cycle   = ((unsigned long )SysTick_LOAD_RELOAD_Msk - (unsigned long )delay) ;\
  }                                                                            \
}

//!
// \brief Test if a timer variable reached its timeout.
//
// Once the timeout is reached, the function will always return TRUE,
// until the cpu_stop_timeout() function is called.
//
// Ex:  t_cpu_time timer;
//      cpu_set_timeout( 10, FOSC0, &timer ); // timeout in 10 ms
//      if( cpu_is_timeout(&timer) )
//         cpu_stop_timeout(&timer);
//         ../..
//
// \param  cpu_time:   (input) internal information used by the timer API.
//
// \return TRUE if timeout occured, otherwise FALSE.
//
#if (defined __GNUC__)
__attribute__((__always_inline__))
static  __inline__
#else
static inline
#endif
unsigned long cpu_is_timeout(t_cpu_time *cpu_time)
{
  unsigned long current_cycle_count = Get_sys_count();


  // Test if the timeout as already occured.
   if (cpu_time->timer_state == CPU_TIMER_STATE_REACHED)
    return TRUE;
   else    if( cpu_time->timer_state==CPU_TIMER_STATE_STOPPED )
    return FALSE;

  // If the ending cycle count of this timeout is wrapped, ...
  else if (cpu_time->delay_start_cycle > cpu_time->delay_end_cycle)
  {
    if (current_cycle_count < cpu_time->delay_start_cycle && current_cycle_count < cpu_time->delay_end_cycle)
    {
      cpu_time->timer_state = CPU_TIMER_STATE_REACHED;
      return TRUE;
    }
    return FALSE;
  }
  else
  {
    if (current_cycle_count > cpu_time->delay_start_cycle && current_cycle_count < cpu_time->delay_end_cycle)
    {
      cpu_time->timer_state = CPU_TIMER_STATE_REACHED;
      return TRUE;
    }
    return FALSE;
  }
}

//!
// \brief Waits during at least the specified delay (in microsecond) before returning.
//
// \param  delay:   Number of microsecond to wait.
// \param  fcpu_hz: CPU frequency in Hz.
//
#if (defined __GNUC__)
__attribute__((__always_inline__))
static  __inline__
#else
static inline
#endif
 void cpu_delay_us(unsigned long delay, unsigned long fcpu_hz)
{
  Set_sys_count( 0 ) ;   // start from a known point
  t_cpu_time timer;
  cpu_set_timeout_fast( cpu_us_2_cy_fast(delay), timer);
  while( !cpu_is_timeout(&timer) );
}

//!
// \brief Waits during at least the specified delay (in CPU cycles) before returning.
//
// \param  delay:   Number of CPU cycles to wait.
//
#if (defined __GNUC__)
__attribute__((__always_inline__))
static  __inline__

#else
static inline
#endif
void cpu_delay_cy(unsigned long delay)
{
  t_cpu_time timer;
  Set_sys_count( 0 ) ;   // start from a known point
  cpu_set_timeout( delay, &timer);
  while( !cpu_is_timeout(&timer) );
}
*/
#endif
