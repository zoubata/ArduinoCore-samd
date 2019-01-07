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

#ifndef _BOARD_DRIVER_LED_
#define _BOARD_DRIVER_LED_

#include "sam.h"
#include "board_definitions/board_definitions.h"
#include "util.h"
#define LED_STATUS_SUCCESS                      1000
#define LED_STATUS_FILE_ALREADY_MATCHES         500
#define LED_STATUS_FILE_NOT_FOUND               250
#define LED_STATUS_NO_SAM_BA_INTERFACE          125
#define LED_STATUS_FILE_TOO_LARGE               63
#define LED_STATUS_VERIFICATION_FAILURE         31

void LED_pulse(void);
void LED_status(uint32_t periodMS);
#ifdef __ICCARM__
#define __inline__           inline
#endif
#if defined(BOARD_LED_PORT)
  #if ((defined BOARD_LED_POLARITY) && BOARD_LED_POLARITY == LED_POLARITY_LOW_ON)
   static inline void LED_on(void) { PORT->Group[BOARD_LED_PORT].OUTCLR.reg = (1<<BOARD_LED_PIN); }
   static inline void LED_off(void) { PORT->Group[BOARD_LED_PORT].OUTSET.reg = (1<<BOARD_LED_PIN); }
  #else
  
static __inline__  void LED_on(void) { PORT->Group[BOARD_LED_PORT].OUTSET.reg = (1<<BOARD_LED_PIN); }
static __inline__  void LED_off(void) { PORT->Group[BOARD_LED_PORT].OUTCLR.reg = (1<<BOARD_LED_PIN); }
  #endif

  static __inline__  void LED_init(void) { PORT->Group[BOARD_LED_PORT].DIRSET.reg = (1<<BOARD_LED_PIN); LED_off(); }
static __inline__  void LED_toggle(void) { PORT->Group[BOARD_LED_PORT].OUTTGL.reg = (1<<BOARD_LED_PIN); }
#else
static __inline__  void LED_init(void) { }
static __inline__  void LED_on(void) { }

static __inline__  void LED_off(void) { }
static __inline__  void LED_toggle(void) { }
#endif
void LED_pulse();
void LED_setSpeed(uint8_t s);
#if defined(BOARD_LEDRX_PORT)
  #if ((defined BOARD_LEDRX_POLARITY) && BOARD_LEDRX_POLARITY == LED_POLARITY_LOW_ON)
static __inline__  void LEDRX_on(void) { PORT->Group[BOARD_LEDRX_PORT].OUTCLR.reg = (1<<BOARD_LEDRX_PIN); }
static __inline__  void LEDRX_off(void) { PORT->Group[BOARD_LEDRX_PORT].OUTSET.reg = (1<<BOARD_LEDRX_PIN); }
  #else
    static inline void LEDRX_on(void) { PORT->Group[BOARD_LEDRX_PORT].OUTSET.reg = (1<<BOARD_LEDRX_PIN); }
    static inline void LEDRX_off(void) { PORT->Group[BOARD_LEDRX_PORT].OUTCLR.reg = (1<<BOARD_LEDRX_PIN); }
  #endif
static __inline__  void LEDRX_init(void) { PORT->Group[BOARD_LEDRX_PORT].DIRSET.reg = (1<<BOARD_LEDRX_PIN); LEDRX_off();  }
static __inline__  void LEDRX_toggle(void) { PORT->Group[BOARD_LEDRX_PORT].OUTTGL.reg = (1<<BOARD_LEDRX_PIN); }
#else
static __inline__  void LEDRX_init(void) { }
static __inline__  void LEDRX_on(void) { }
static __inline__  void LEDRX_off(void) { }
static __inline__  void LEDRX_toggle(void) { }
#endif

#if defined(BOARD_LEDTX_PORT)
  #if ((defined BOARD_LEDTX_POLARITY) && BOARD_LEDTX_POLARITY == LED_POLARITY_LOW_ON)
static __inline__  void LEDTX_on(void) { PORT->Group[BOARD_LEDTX_PORT].OUTCLR.reg = (1<<BOARD_LEDTX_PIN); }
static __inline__  void LEDTX_off(void) { PORT->Group[BOARD_LEDTX_PORT].OUTSET.reg = (1<<BOARD_LEDTX_PIN); }
  #else
    static __inline__  void LEDTX_on(void) { PORT->Group[BOARD_LEDTX_PORT].OUTSET.reg = (1<<BOARD_LEDTX_PIN); }
    static __inline__  void LEDTX_off(void) { PORT->Group[BOARD_LEDTX_PORT].OUTCLR.reg = (1<<BOARD_LEDTX_PIN); }
  #endif
static __inline__  void LEDTX_init(void) { PORT->Group[BOARD_LEDTX_PORT].DIRSET.reg = (1<<BOARD_LEDTX_PIN); LEDTX_off(); }
static __inline__  void LEDTX_toggle(void) { PORT->Group[BOARD_LEDTX_PORT].OUTTGL.reg = (1<<BOARD_LEDTX_PIN); }
#else
static __inline__  void LEDTX_init(void) { }
static __inline__  void LEDTX_on(void) { }
static __inline__  void LEDTX_off(void) { }
static __inline__  void LEDTX_toggle(void) { }
#endif

#endif // _BOARD_DRIVER_LED_
