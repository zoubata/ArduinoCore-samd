/*
 * TWI/I2C library for Arduino Zero
 * Copyright (c) 2015 Arduino LLC. All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "Wire.h"

extern "C" {
#include <string.h>
}// extern "C" {

#include <Arduino.h>

#include <wiring_private.h>

//#include "variant.h"
TwoWire::TwoWire(SERCOM * s, uint8_t pinSDA, uint8_t pinSCL)
{
  this->sercom = s;
  this->_uc_pinSDA=pinSDA;
  this->_uc_pinSCL=pinSCL;
  transmissionBegun = false;
  initialized= false;
}

int TwoWire::enabled()
{
	if (!initialized)
		return initialized;
    return (((sercom->mode()>>1)&0x3)==0x2);
}

   bool TwoWire::testLine(void) {
     bool r=true;
     
  if (!initialized)
  {
     pinMode(_uc_pinSDA, INPUT_PULLDOWN);
     pinMode(_uc_pinSCL, INPUT_PULLDOWN); 
     delay(10);
     r&= (digitalRead(_uc_pinSDA)==HIGH) &&
(digitalRead(_uc_pinSCL)==HIGH);

     pinMode(_uc_pinSDA, INPUT_PULLUP);
     pinMode(_uc_pinSCL, INPUT_PULLUP); 
   
   }
       delay(10);// wait to be sure that line is up from previous operation(pull up config or previous write on line)
  r&= (digitalRead(_uc_pinSDA)==HIGH) &&
(digitalRead(_uc_pinSCL)==HIGH);

   return r;
}
void TwoWire::begin(void) {
  //Master Mode
  sercom->initMasterWIRE(TWI_CLOCK);
  sercom->enableWIRE();

  initialized= true;

  pinPeripheral(_uc_pinSDA,PIO_SERCOM);

  pinPeripheral(_uc_pinSCL, PIO_SERCOM);

  pinPeripheral(_uc_pinSDA, g_APinDescription[_uc_pinSDA].ulPinType);
  pinPeripheral(_uc_pinSCL, g_APinDescription[_uc_pinSCL].ulPinType);
}

void TwoWire::begin(uint8_t address, bool enableGeneralCall) {
  //Slave mode
  sercom->initSlaveWIRE(address, enableGeneralCall);
  sercom->enableWIRE();

  pinPeripheral(_uc_pinSDA, g_APinDescription[_uc_pinSDA].ulPinType);
  pinPeripheral(_uc_pinSCL, g_APinDescription[_uc_pinSCL].ulPinType);
}

void TwoWire::setClock(uint32_t baudrate) {
  sercom->disableWIRE();
  sercom->initMasterWIRE(baudrate);
  // Synchronous arithmetic baudrate
  sercom->enableWIRE();
}

void TwoWire::end() {
  sercom->disableWIRE();
//  initialized= false;
}

uint8_t TwoWire::requestFrom(uint8_t address, size_t quantity, bool stopBit)
{
  if(quantity == 0)
  {
    return 0;
  }

  size_t byteRead = 0;

  rxBuffer.clear();

  if(sercom->startTransmissionWIRE(address, WIRE_READ_FLAG))
  {
    // Read first data
    rxBuffer.store_char(sercom->readDataWIRE());

    // Connected to slave
    for (byteRead = 1; byteRead < quantity; ++byteRead)
    {
      sercom->prepareAckBitWIRE();                          // Prepare Acknowledge
      sercom->prepareCommandBitsWire(WIRE_MASTER_ACT_READ); // Prepare the ACK command for the slave
      rxBuffer.store_char(sercom->readDataWIRE());          // Read data and send the ACK
    }
    sercom->prepareNackBitWIRE();                           // Prepare NACK to stop slave transmission
    //sercom->readDataWIRE();                               // Clear data register to send NACK

    if (stopBit)
    {
      sercom->prepareCommandBitsWire(WIRE_MASTER_ACT_STOP);   // Send Stop
    }
  }

  return byteRead;
}

uint8_t TwoWire::requestFrom(uint8_t address, size_t quantity)
{
  return requestFrom(address, quantity, true);
}

void TwoWire::beginTransmission(uint8_t address) {
  // save address of target and clear buffer
  txAddress = address;
  txBuffer.clear();

  transmissionBegun = true;
}

// Errors:
//  0 : Success
//  1 : Data too long
//  2 : NACK on transmit of address
//  3 : NACK on transmit of data
//  4 : Other error
uint8_t TwoWire::endTransmission(bool stopBit)
{
  transmissionBegun = false ;
//  sercom->multiMastertoMaster();
  // Start I2C transmission
  if ( !sercom->startTransmissionWIRE( txAddress, WIRE_WRITE_FLAG ) )
  {
    sercom->prepareCommandBitsWire(WIRE_MASTER_ACT_STOP);
    return 2 ;  // Address error
  }

  // Send all buffer
  while( txBuffer.available() )
  {
    // Trying to send data
    if ( !sercom->sendDataMasterWIRE( txBuffer.read_char() ) )
    {
      sercom->prepareCommandBitsWire(WIRE_MASTER_ACT_STOP);
      return 3 ;  // Nack or error
    }
  }
  
  if (stopBit)
  {
    sercom->prepareCommandBitsWire(WIRE_MASTER_ACT_STOP);
  }
//  sercom->multiMastertoSlave();

  return 0;
}

uint8_t TwoWire::endTransmission()
{
  return endTransmission(true);
}

size_t TwoWire::write(uint8_t ucData)
{
  // No writing, without begun transmission or a full buffer
  if ( (!transmissionBegun) || txBuffer.isFull() )
  {
    return 0 ;
  }
  noInterrupts();// txBuffer isn't atomic, and it could be modify by interrupt handler at same time by this function, creating a corruption
  txBuffer.store_char( ucData ) ;
  interrupts();
  

  return 1 ;
}

size_t TwoWire::write(const uint8_t *data, size_t quantity)
{
  //Try to store all data
  for(size_t i = 0; i < quantity; ++i)
  {
    //Return the number of data stored, when the buffer is full (if write return 0)
    if(!write(data[i]))
      return i;
  }

  //All data stored
  return quantity;
}

int TwoWire::available(void)
{
  return rxBuffer.available();
}

int TwoWire::read(void)
{
   noInterrupts();// rxBuffer isn't atomic, and it could be modify by interrupt handler at same time by this function, creating a corruption
 signed  int c = rxBuffer.read_char();
interrupts();

  return c;
}

int TwoWire::peek(void)
{
  return rxBuffer.peek();
}

void TwoWire::flush(void)
{
  // Do nothing, use endTransmission(..) to force
  // data transfer.
}

void TwoWire::onReceive(void(*function)(int))
{
  onReceiveCallback = function;
}

void TwoWire::onRequest(void(*function)(void))
{
  onRequestCallback = function;
}

bool TwoWire::isIrq()
{
  if(enabled())
    return sercom->isIrq();
  return false;
}

void TwoWire::onService(void)
{
  if ( sercom->isSlaveWIRE() )
  {
    if(sercom->isStopDetectedWIRE() || 
        (sercom->isAddressMatch() && sercom->isRestartDetectedWIRE() && !sercom->isMasterReadOperationWIRE())) //Stop or Restart detected
    {
      sercom->prepareAckBitWIRE();
      sercom->prepareCommandBitsWire(0x03);

      //Calling onReceiveCallback, if exists
      if(onReceiveCallback)
      {
        onReceiveCallback(available());
      }
      
      rxBuffer.clear();
    }
    else if(sercom->isAddressMatch())  //Address Match
    {
      sercom->prepareAckBitWIRE();
      sercom->prepareCommandBitsWire(0x03);

      if(sercom->isMasterReadOperationWIRE()) //Is a request ?
      {
        txBuffer.clear();

        transmissionBegun = true;

        //Calling onRequestCallback, if exists
        if(onRequestCallback)
        {
          onRequestCallback();
        }
      }
    }
    else if(sercom->isDataReadyWIRE())
    {
      if (sercom->isMasterReadOperationWIRE())
      {
        uint8_t c = 0xff;

        if( txBuffer.available() ) {
          c = txBuffer.read_char();
        }

        transmissionBegun = sercom->sendDataSlaveWIRE(c);
      } else { //Received data
        if (rxBuffer.isFull()) {
          sercom->prepareNackBitWIRE(); 
        } else {
          //Store data
          rxBuffer.store_char(sercom->readDataWIRE());

          sercom->prepareAckBitWIRE(); 
        }

        sercom->prepareCommandBitsWire(0x03);
      }
    }
  }
}

#if defined(PERIPH_WIRE)
  /* In case new variant doesn't define these macros,
   * we put here the ones for Arduino Zero.
   *
   * These values should be different on some variants!
   */
  #ifndef PERIPH_WIRE
    #define PERIPH_WIRE          sercom3
    #define WIRE_IT_HANDLER      SERCOM3_Handler
  #endif // PERIPH_WIRE
  TwoWire Wire0(&PERIPH_WIRE, PIN_WIRE_SDA, PIN_WIRE_SCL);

  void WIRE_IT_HANDLER(void) {
    Wire0.onService();
  }
#endif

#if defined(PERIPH_WIRE1)
  TwoWire Wire1(&PERIPH_WIRE1, PIN_WIRE1_SDA, PIN_WIRE1_SCL);

  void WIRE1_IT_HANDLER(void) {
    Wire1.onService();
  }
#endif

#if defined(PERIPH_WIRE2)
  TwoWire Wire2(&PERIPH_WIRE2, PIN_WIRE2_SDA, PIN_WIRE2_SCL);

  void WIRE2_IT_HANDLER(void) {
    Wire2.onService();
  }
#endif

#if defined(PERIPH_WIRE3)
  TwoWire Wire3(&PERIPH_WIRE3, PIN_WIRE3_SDA, PIN_WIRE3_SCL);

  void WIRE3_IT_HANDLER(void) {
    Wire3.onService();
  }
#endif

#if defined(PERIPH_WIRE4)
  TwoWire Wire4(&PERIPH_WIRE4, PIN_WIRE4_SDA, PIN_WIRE4_SCL);

  void WIRE4_IT_HANDLER(void) {
    Wire4.onService();
  }
#endif

#if defined(PERIPH_WIRE5)
  TwoWire Wire5(&PERIPH_WIRE5, PIN_WIRE5_SDA, PIN_WIRE5_SCL);

  void WIRE5_IT_HANDLER(void) {
    Wire5.onService();
  } 
#endif

#if defined(PERIPH_WIRE6)
  TwoWire Wire6(&PERIPH_WIRE6, PIN_WIRE6_SDA, PIN_WIRE6_SCL);

  void WIRE6_IT_HANDLER(void) {
    Wire6.onService();
  }
#endif
