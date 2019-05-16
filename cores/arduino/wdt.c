#include "Arduino.h"
#include <wdt.h>
void wdt_poll_syncbusy( int index) {
  switch ( index ) {
    case WDT_SYNCBUSY_ENABLE_Pos   :
      while (WDT->SYNCBUSY.bit.ENABLE == 1);
      break;
    case WDT_SYNCBUSY_WEN_Pos    :
      while (WDT->SYNCBUSY.bit.WEN == 1);
      break;
    case WDT_SYNCBUSY_ALWAYSON_Pos    :
      while (WDT->SYNCBUSY.bit.ALWAYSON == 1);
      break;
    case WDT_SYNCBUSY_CLEAR_Pos :
      while (WDT->SYNCBUSY.bit.CLEAR == 1);
      break;
  }
}
void wdt_clr()
{

    WDT->CLEAR.reg = WDT_CLEAR_CLEAR_KEY_Val;
  wdt_poll_syncbusy( WDT_SYNCBUSY_CLEAR_Pos);
}


// code With  clock cycles count then no optimisation here,
void WDT_off(void)
{

wdt_clr();
 if ( WDT->CTRLA.bit.ALWAYSON == 0 ) {
    WDT->CTRLA.bit.ENABLE = 0;
    wdt_poll_syncbusy( WDT_SYNCBUSY_ENABLE_Pos);
  }
}


void wdt_config(Wdt *wdt, int wen, int per, int window, int ewoffset) {
  WDT_CONFIG_Type wdtconfig;
  WDT_EWCTRL_Type wdtewctrl;
  wdtconfig.bit.PER = per;
  wdtconfig.bit.WINDOW = window;
  wdtewctrl.bit.EWOFFSET = ewoffset;
  if ( wdt->CTRLA.bit.ALWAYSON == 1 || wdt->CTRLA.bit.ENABLE == 0 ) {
    wdt->CTRLA.bit.WEN = wen;
    wdt_poll_syncbusy( WDT_SYNCBUSY_WEN_Pos);
  }
  if ( wdt->CTRLA.bit.ALWAYSON == 0 && wdt->CTRLA.bit.ENABLE == 0 ) {
    wdt->CONFIG.reg = wdtconfig.reg;
    wdt->EWCTRL.reg = wdtewctrl.reg;
  }
}

void WDT_set(uint32_t timeout)
{
  if(timeout > WDT_TIMEOUT_MAX)
    timeout = WDT_TIMEOUT_MAX;

  WDT_off();
	wdt_config(WDT, 0, timeout, 0, 0);

}
void WDT_on(  )
{
   WDT_set( WDT_TIMEOUT_4S );
   if ( WDT->CTRLA.bit.ALWAYSON == 0 ) {
     WDT->CTRLA.bit.ENABLE = 1;
    wdt_poll_syncbusy( WDT_SYNCBUSY_ENABLE_Pos);
  }
  wdt_clr();
}

