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

#include "Uart.h"
#include <assert.h>
#include "Arduino.h"
#include "wiring_private.h"
#define NO_RTS_PIN -1
#define NO_CTS_PIN -1
#define RTS_RX_THRESHOLD 10

Uart::Uart(SERCOM *_s, uint8_t _pinRX, uint8_t _pinTX, SercomRXPad _padRX, SercomUartTXPad _padTX) 
 
{
   sercom = _s;
  uc_pinRX = _pinRX;
  uc_pinTX = _pinTX;
  uc_padRX=_padRX ;
  uc_padTX=_padTX;
 uc_pinRTS = NO_RTS_PIN;
  uc_pinCTS = NO_CTS_PIN;
  initialized=false;
}

Uart::Uart(SERCOM *_s, uint8_t _pinRX, uint8_t _pinTX, SercomRXPad _padRX, SercomUartTXPad _padTX, uint8_t _pinRTS, uint8_t _pinCTS)
{
  sercom = _s;
  uc_pinRX = _pinRX;
  uc_pinTX = _pinTX;
  uc_padRX=_padRX ;
  uc_padTX=_padTX;
 uc_pinRTS = _pinRTS;
  uc_pinCTS = _pinCTS;
  initialized=false;
}

void Uart::begin(unsigned long baudrate)
{
  begin(baudrate, SERIAL_8N1);
  initialized=true;
}

void Uart::begin(unsigned long baudrate, uint16_t config)
{
  initialized=true;
  pinPeripheral(uc_pinRX, PIO_SERCOM);
  pinPeripheral(uc_pinTX, PIO_SERCOM);

  sercom->initUART(UART_INT_CLOCK, SAMPLE_RATE_x16, baudrate);
  sercom->initFrame(extractCharSize(config), LSB_FIRST, extractParity(config), extractNbStopBit(config));
  sercom->initPads(uc_padTX, uc_padRX);

  sercom->enableUART();
}

void Uart::end()
{
  sercom->resetUART();
  rxBuffer.clear();
  txBuffer.clear();
  initialized=false;
}

void Uart::flush()
{
  while(txBuffer.available()); // wait until TX buffer is empty

  sercom->flushUART();
}

bool Uart::isIrq()
{
  if(enabled())
    return sercom->isIrq();
  return false;
}

///IRQ HANDLER
void Uart::IrqHandler()
{
/*while*/
  if (sercom->availableDataUART()) {
    
    rxBuffer.store_char(sercom->readDataUART());
    if (uc_pinRTS != (uint8_t)NO_RTS_PIN) {
      // RX buffer space is below the threshold, de-assert RTS
      if (rxBuffer.availableForStore() < RTS_RX_THRESHOLD) {
        *pul_outsetRTS = ul_pinMaskRTS;
      }
    }
  }

  if (sercom->isDataRegisterEmptyUART()) {
    if (txBuffer.available()) {
      uint8_t data = txBuffer.read_char();

      sercom->writeDataUART(data);
    } else {
      sercom->disableDataRegisterEmptyInterruptUART();
    }
  }

  if (sercom->isUARTError()) {
    sercom->acknowledgeUARTError();
    if (sercom->isBufferOverflowErrorUART()) 
    {
#ifdef DEBUG
  //PV    assert(false);
#endif
      
    }
    // TODO: 
    if (sercom->isFrameErrorUART())
    {
      //....      
#ifdef DEBUG
     assert(false);
#endif
    }
    // TODO: 
    if (sercom->isParityErrorUART()) 
    {
      //....
      
#ifdef DEBUG
//      assert(false);
#endif
    }
    sercom->clearStatusUART();
  }
/*  // in case of new data comming during irq because interupt handler was called later after the 1st data.
  while (sercom->availableDataUART()) {
    rxBuffer.store_char(sercom->readDataUART());
    if (uc_pinRTS != NO_RTS_PIN) {
      // RX buffer space is below the threshold, de-assert RTS
      if (rxBuffer.availableForStore() < RTS_RX_THRESHOLD) {
        *pul_outsetRTS = ul_pinMaskRTS;
      }
    }
  }
*/
  //if an other receive data happen process it now instead of pop context and push it again.
  // usefull for 1Mbps and upper.(I squizz error processing it will happen on next call)
    if (sercom->availableDataUART()) {
    
    rxBuffer.store_char(sercom->readDataUART());
    if (uc_pinRTS != (uint8_t)NO_RTS_PIN) {
      // RX buffer space is below the threshold, de-assert RTS
      if (rxBuffer.availableForStore() < RTS_RX_THRESHOLD) {
        *pul_outsetRTS = ul_pinMaskRTS;
      }
    }
  }
}

int Uart::enabled()
{
	if (!initialized)
		return initialized;
    return (((sercom->mode()>>1)&0x3)==0x0);
}
int Uart::available()
{
  return rxBuffer.available();
}

int Uart::availableForWrite()
{
  return txBuffer.availableForStore();
}

int Uart::peek()
{
  return rxBuffer.peek();
}

void Uart::waitTxEnd()
{
  while( txBuffer.peek()!=-1);
}
int Uart::read()
{
 noInterrupts();// rxBuffer isn't atomic, and it could be modify by interrupt handler at same time by this function, creating a corruption
 signed  int c = rxBuffer.read_char();
interrupts();
  if (uc_pinRTS != (uint8_t)NO_RTS_PIN) {
    // if there is enough space in the RX buffer, assert RTS
    if (rxBuffer.availableForStore() < (signed int) RTS_RX_THRESHOLD) {
      *pul_outclrRTS = ul_pinMaskRTS;
    }
  }

  return c;
}

size_t Uart::write(const uint8_t data)
{
  if (sercom->isDataRegisterEmptyUART() && txBuffer.available() == 0) {
    sercom->writeDataUART(data);
  } else {
    while(txBuffer.isFull()) {
      uint8_t interruptsEnabled = ((__get_PRIMASK() & 0x1) == 0);

      if (interruptsEnabled) {
        uint32_t exceptionNumber = (SCB->ICSR & SCB_ICSR_VECTACTIVE_Msk);

        if (exceptionNumber == 0 ||
              NVIC_GetPriority((IRQn_Type)(exceptionNumber - 16)) > SERCOM_NVIC_PRIORITY) {
          // no exception or called from an ISR with lower priority,
          // wait for free buffer spot via IRQ
          continue;
        }
      }

      // interrupts are disabled or called from ISR with higher or equal priority than the SERCOM IRQ
      // manually call the UART IRQ handler when the data register is empty
      if (sercom->isDataRegisterEmptyUART()) {
      
      IrqHandler(); // process iar in case of int disable because we are inside a irq
      }
    }
    noInterrupts();// txBuffer isn't atomic, and it could be modify by interrupt handler at same time by this function, creating a corruption
    txBuffer.store_char(data);
    sercom->enableDataRegisterEmptyInterruptUART();// to be sure that interrupt event will happen after the enable
    interrupts();

  }

  return 1;
}

SercomNumberStopBit Uart::extractNbStopBit(uint16_t config)
{
  switch(config & HARDSER_STOP_BIT_MASK)
  {
    case HARDSER_STOP_BIT_1:
    default:
      return SERCOM_STOP_BIT_1;

    case HARDSER_STOP_BIT_2:
      return SERCOM_STOP_BITS_2;
  }
}

SercomUartCharSize Uart::extractCharSize(uint16_t config)
{
  switch(config & HARDSER_DATA_MASK)
  {
    case HARDSER_DATA_5:
      return UART_CHAR_SIZE_5_BITS;

    case HARDSER_DATA_6:
      return UART_CHAR_SIZE_6_BITS;

    case HARDSER_DATA_7:
      return UART_CHAR_SIZE_7_BITS;

    case HARDSER_DATA_8:
    default:
      return UART_CHAR_SIZE_8_BITS;

  }
}

SercomParityMode Uart::extractParity(uint16_t config)
{
  switch(config & HARDSER_PARITY_MASK)
  {
    case HARDSER_PARITY_NONE:
    default:
      return SERCOM_NO_PARITY;

    case HARDSER_PARITY_EVEN:
      return SERCOM_EVEN_PARITY;

    case HARDSER_PARITY_ODD:
      return SERCOM_ODD_PARITY;
  }
}

/*

#if SERIAL_INTERFACES_COUNT > 1
  Uart Serial0(SERCOM_INSTANCE_SERIAL0, PIN_SERIAL0_RX, PIN_SERIAL0_TX,  PAD_SERIAL0_RX, PAD_SERIAL0_TX);
#endif
#if SERIAL_INTERFACES_COUNT > 2
  Uart Serial1(SERCOM_INSTANCE_SERIAL1, PIN_SERIAL1_RX, PIN_SERIAL1_TX,  PAD_SERIAL1_RX, PAD_SERIAL1_TX);
#endif
#if SERIAL_INTERFACES_COUNT > 3
  Uart Serial2(SERCOM_INSTANCE_SERIAL2, PIN_SERIAL2_RX, PIN_SERIAL2_TX,  PAD_SERIAL2_RX, PAD_SERIAL2_TX);
#endif
#if SERIAL_INTERFACES_COUNT > 4
  Uart Serial3(SERCOM_INSTANCE_SERIAL3, PIN_SERIAL3_RX, PIN_SERIAL3_TX,  PAD_SERIAL3_RX, PAD_SERIAL3_TX);
#endif
#if SERIAL_INTERFACES_COUNT > 5
  Uart Serial4(SERCOM_INSTANCE_SERIAL4, PIN_SERIAL4_RX, PIN_SERIAL4_TX,  PAD_SERIAL4_RX, PAD_SERIAL4_TX);
#endif

#if SERIAL_INTERFACES_COUNT > 6
  Uart Serial5(SERCOM_INSTANCE_SERIAL5, PIN_SERIAL5_RX, PIN_SERIAL5_TX,  PAD_SERIAL5_RX, PAD_SERIAL5_TX);
#endif
*/
