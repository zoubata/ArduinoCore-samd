/*
  Copyright (c) 2015 Arduino LLC.  All right reserved.
  Copyright (c) 2017 MattairTech LLC. All right reserved.
  Copyright (c) 2018 Zoubworld LLC. All right reserved.
  

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

#include "Arduino.h"

#ifdef __cplusplus
 extern "C" {
#endif

void pinMode( uint32_t ulPin, uint32_t ulMode )
{
    if (( ulPin>=NUM_PIN_DESCRIPTION_ENTRIES)|| ( g_APinDescription[ulPin].ulPinType == PIO_NOT_A_PIN ))
  {
    PinExtention_pinMode(  ulPin,  ulMode );
    return;
  }
  if (ulMode==OUTPUT_LOW)
  {
  pinPeripheral(ulPin, OUTPUT);
  digitalWrite(  ulPin, LOW );
  }
  else
  pinPeripheral(ulPin, ulMode);
  
  // Set pin mode according to chapter '22.6.3 I/O Pin Configuration'
 
}

void digitalWrite( uint32_t ulPin, uint32_t ulVal )
{
  // Handle the case the pin isn't usable as PIO
  
  if (( ulPin>=NUM_PIN_DESCRIPTION_ENTRIES)|| ( g_APinDescription[ulPin].ulPinType == PIO_NOT_A_PIN ))
  {
    PinExtention_digitalWrite(  ulPin,  ulVal );
    return;
  }

  uint32_t pinAttribute = g_APinDescription[ulPin].ulPinAttribute;
  uint8_t pinPort = g_APinDescription[ulPin].ulPort;
  uint8_t pinNum = g_APinDescription[ulPin].ulPin;
  uint8_t pinConfig = PORT->Group[pinPort].PINCFG[pinNum].reg;
  uint8_t pinDir = (PORT->Group[pinPort].DIR.reg && (1ul << pinNum));
  uint8_t pinOut = (PORT->Group[pinPort].OUT.reg && (1ul << pinNum));

  // Enable pull resistor if pin attributes allow and only if pin is not configured as output
  // Note that most pins should use PIN_ATTR_DIGITAL, which includes both PIN_ATTR_INPUT_PULLUP and PIN_ATTR_INPUT_PULLDOWN.
  if ( pinDir == 0 ) { // pin DIR is input
     if ( ulVal == HIGH )
     {
       if ( (pinOut == 1 && (pinAttribute & PIN_ATTR_INPUT_PULLUP)) || (pinOut == 0 && (pinAttribute & PIN_ATTR_INPUT_PULLDOWN)) )
       {
         pinConfig |= (uint8_t)(PORT_PINCFG_PULLEN) ;
       }
     }
     else
     {
       pinConfig &= ~(uint8_t)(PORT_PINCFG_PULLEN) ;
     }
     
     PORT->Group[pinPort].PINCFG[pinNum].reg = pinConfig ;
  }
  // Set or clear OUT register only when pin DIR is set to output.
  // Pull direction (pullup or pulldown) is now set with pinMode only (defaults to pullup if pinMode never called).
  else
  {
    if ( ulVal == HIGH ) {
      PORT->Group[pinPort].OUTSET.reg = (1ul << pinNum) ;
    }
    else
    {
      PORT->Group[pinPort].OUTCLR.reg = (1ul << pinNum) ;
    }
  }

  return ;
}

int digitalRead( uint32_t ulPin )
{
  
    if (( ulPin>=NUM_PIN_DESCRIPTION_ENTRIES))
  {
    return PinExtention_digitalRead(  ulPin );
  }
  // Handle the case the pin isn't usable as PIO
  if ( g_APinDescription[ulPin].ulPinType == PIO_NOT_A_PIN )
  {    
    return LOW ;
  }
  
  if ( (PORT->Group[g_APinDescription[ulPin].ulPort].IN.reg & (1ul << g_APinDescription[ulPin].ulPin)) != 0 )
  {
    return HIGH ;
  }

  return LOW ;
}

#ifdef __cplusplus
}// extern "C" {
#endif

