
#include "PinExtender.h"
/** PinExtender
This functions and class are here to extends the API of Arduino.
when it is fully integrated, the API of arduino manage the pin and extended components pins.
The pin number of extended component is object.getPin(x), where x is the channel of the componnent represented by object. 
so a simple digitalWrite(pinExtended, LOW) define the state of the pin extended.
So not rewrite of code is needed to use extended pin, this include library of 3rd party, you have just to identify the pin on uint32_t.
pinExtended is equal to myMCP23017.getPin(MCP23017_GPIOA1) for example where myMCP23017 is an instance of ZMCP23017 that extend PinExtender class. and MCP23017_GPIOA1 the channel 1 of MCP23017 component.

so the schematic is like this :
   PIN                       PINEXT
    |                         |
|---+------|   I2C line  |----+-----------|
| ARDUINO  +-------------@ EXT.COMPONENT  |
|__________|             |________________|


so the extended component is identify by a wire object and an address, we can manage several component if the adresses are differents.
A pin number from a component encode the channel number inside the component and the address of the component but not the wire interface used.
to get it use getPin() function from object that instanciate the classe of the component and that has been initialise with the good address and wire object. 
This object that reflect the component must be daisy chain with setPinExtender((PinExtender) object1st ) if it is the 1st, else with the last object of the daisy chain objectLast.SetPinExtender(newObject)
These object must heritate fromclass PinExtender.
Today this folowing class instiate this :
- ZPCA9685 : a PCA9685 driver for PWM and led and servo application, it handle the board called module Pca9685  16 PWM 12bits.....
- ZMCP23017 : a MCP23017 driver for I/O extension application, it handle the board called MCP23017 module
- Zmotor2 : a board driver for motor control <0.8A up to 16 DC motor that used one MCP23017 and one PCA9685 and L9110 for power
- Zmotor3 : a board driver for motor control <3A up to 8 DC motor with Current sense that used one MCP23017 and one PCA9685 and L298 for power

The IPA supported are :
- pinMode(uint32_t pin_arduino, uint8_t d)
- digitalWrite(uint32_t pin_arduino, uint8_t d)
- digitalRead(uint32_t pin_arduino)
- analogWrite( uint32_t pin_arduino, uint32_t ulValue ) 
- analogWriteResolution(int res)
- analogRead( uint32_t pin )
N.B. the core API must be patched to support that, today the following core support that :
- zoubworld_samd support that 
.
to patch it by your self :
- add PinExtended.h & .cpp on C:\Users\*\AppData\Local\Arduino15\packages\*\hardware\*\*\cores\arduino
- update the previous API from uint8_t to uint32_t,
- add at begining of each API funtion add :

void APIfuntion( uint32_t ulPin, uint32_t ulVal )
{  // Handle the case the pin isn't a native arduino pin
 if (( ulPin>=NUM_PIN_DESCRIPTION_ENTRIES))
  { PinExtention_APIfuntion(  ulPin,  ulVal );
    return;
  }
...

This only draw back of this library once setup(see example), it that it is slower to access an extended pin compare to a native one, because each access is manage by a wire transaction.

*/

 PinExtender * pinExtention;
#ifdef __cplusplus
 extern "C" {
#endif
  
void PinExtention_analogWriteResolution(int res)
{
  if( pinExtention) 
    pinExtention->analogWriteResolution(res);
}


void setPinExtender(PinExtender * next)
{
  pinExtention=next;
}
void    PinExtention_digitalWrite( uint32_t ulPin, uint32_t ulVal )
{
  if( pinExtention) 
    pinExtention->digitalWrite( ulPin,  ulVal );
}

void    PinExtention_analogWrite( uint32_t ulPin, uint32_t ulVal )
{
  if( pinExtention) 
    pinExtention->analogWrite( ulPin,  ulVal );
}
int PinExtention_digitalRead( uint32_t ulPin )
 {
  if( pinExtention) 
    return pinExtention->digitalRead(  ulPin );
  return LOW;
}     
void PinExtention_pinMode( uint32_t ulPin, uint32_t ulMode )
{
  if( pinExtention) 
    pinExtention->pinMode(  ulPin,  ulMode );
}
uint32_t PinExtention_analogRead( uint32_t pin )
{
  if( pinExtention)
    return pinExtention->analogRead(  pin );
  return 0;
}
#ifdef __cplusplus
 }// extern "C" {

#endif
/** test if pin is supported.
 
 return true when the pin is supported by the object or its daisy chain.
*/
bool PinExtender::accept(uint32_t p)
{
	if(acceptlocal( p))
		return true;
	if (_next)
		return _next->accept( p);
	return false;
}
void PinExtender::setPinExtender(PinExtender * next)
{
  _next=next;
}
PinExtender::PinExtender() :  _i2caddr(0),
  _i2c(0),   
  _next(0)
{
 
}















     void PinExtender::begin(TwoWire *MyWire,uint8_t addr) {};
     void PinExtender::begin(uint8_t addr) {};
     void PinExtender::begin(void) {};
	/** convert local pin number(uint8_t) of the board to arduino pin number(uint32_t) */
     uint32_t PinExtender::getPin(uint8_t channel_local) {return (_i2caddr<<16) | channel_local&0xffff;};
     void PinExtender::pinMode(uint32_t pin_arduino, uint8_t d) {};
     void PinExtender::digitalWrite(uint32_t pin_arduino, uint8_t d) {};
     uint8_t PinExtender::digitalRead(uint32_t pin_arduino) {return 0;};
     void PinExtender::analogWrite( uint32_t pin_arduino, uint32_t ulValue )  {};
     void PinExtender::analogWriteResolution(int res) {};  
     uint32_t PinExtender::analogRead( uint32_t pin ) {return 0;};
     bool PinExtender::acceptlocal(uint32_t p){return 0;};
     uint8_t PinExtender::pin2channel(uint32_t pin){return 0;};
     void PinExtender::analogReadResolution(int res){};
	 
	 
	 
	 