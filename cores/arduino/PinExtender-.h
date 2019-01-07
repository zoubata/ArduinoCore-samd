#ifndef _PinExtender_H
#define _PinExtender_H

#ifdef __AVR
  #include <avr/pgmspace.h>
#elif defined(ESP8266)
  #include <pgmspace.h>
#endif
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "PinExtender.h"

/** daisy chain to manage pin
*/
class PinExtender
{

	
  public:
  PinExtender * _next;
    virtual bool accept(uint32_t p);
	
  
    virtual void begin(TwoWire *MyWire,uint8_t addr);
    virtual void begin(uint8_t addr);
    virtual void begin(void);
	/** convert local pin number(uint8_t) of the board to arduino pin number(uint32_t) */
	virtual uint32_t getPin(uint8_t channel_local);
    virtual void pinMode(uint32_t pin_arduino, uint8_t d);
    virtual void digitalWrite(uint32_t pin_arduino, uint8_t d);
    virtual uint8_t digitalRead(uint32_t pin_arduino);
	
	virtual void analogWrite( uint32_t pin_arduino, uint32_t ulValue ) ;
    virtual void analogWriteResolution(int res);  
	
	virtual bool acceptlocal(uint32_t p);
};
#endif
