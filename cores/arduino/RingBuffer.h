
/** @file RingBuffer.h
  Copyright (c) 2014 Arduino.  All right reserved.

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
#ifdef __cplusplus
#ifndef _RING_BUFFER_
#define _RING_BUFFER_

#include <stdint.h>
#include <sam.h>
// Define constants and variables for buffering incoming serial data.  We're
// using a ring buffer (I think), in which head is the index of the location
// to which to write the next incoming character and tail is the index of the
// location from which to read.
#define SERIAL_BUFFER_SIZE 256
//#define SERIAL_BUFFER_SIZE ((HSRAM_SIZE/20)/SERCOM_INST_NUM)//5% of memory

template <int N>
class RingBufferN
{
  public:
    uint8_t _aucBuffer[N] ;
    volatile int _iHead ;
    volatile int _iTail ;

  public:
    RingBufferN( void ) ;
    void store_char( uint8_t c ) ;
	void clear();
	int read_char();
	int available();
	signed int availableForStore();
	int peek();
	bool isFull();

  private:
	int nextIndex(int index);
} ;

typedef RingBufferN<SERIAL_BUFFER_SIZE> RingBuffer;


template <int N>
RingBufferN<N>::RingBufferN( void )
{
    memset( _aucBuffer, 0, N ) ;
    clear();
}

template <int N>
void RingBufferN<N>::store_char( uint8_t c )
{
  // __disable_irq();
  int i = nextIndex(_iHead);

  // if we should be storing the received character into the location
  // just before the tail (meaning that the head would advance to the
  // current location of the tail), we're about to overflow the buffer
  // and so we don't write the character or advance the head.
  if ( i != _iTail )
  {
    
    _aucBuffer[_iHead] = c ;
    _iHead = i ;
  //   __enable_irq();
  } else
  {

  }
}

template <int N>
void RingBufferN<N>::clear()
{
 //  __disable_irq();
  _iHead = 0;
  _iTail = 0;
  // __enable_irq();
}

template <int N>
int RingBufferN<N>::read_char()
{
  if(_iTail == _iHead)
    return -1;

//   __disable_irq();
  uint8_t value = _aucBuffer[_iTail];
  _iTail = nextIndex(_iTail);
// __enable_irq();
  return value;
}

template <int N>
int RingBufferN<N>::available()
{
 //  __disable_irq();
  int delta = _iHead - _iTail;

  if(delta < 0)
    delta= N + delta;
  else
    delta= delta;
  
  // __enable_irq();
   
   return delta;
}

template <int N>
signed int RingBufferN<N>::availableForStore()
{
signed int r=0;
 if (_iHead >= _iTail)
    r= N - 1 - _iHead + _iTail;
  else
    r= _iTail - _iHead - 1;
return r;
}

template <int N>
int RingBufferN<N>::peek()
{
  if(_iTail == _iHead)
    return -1;

  return _aucBuffer[_iTail];
}

template <int N>
int RingBufferN<N>::nextIndex(int index)
{
  return (uint32_t)(index + 1) % N;
}

template <int N>
bool RingBufferN<N>::isFull()
{
  return (nextIndex(_iHead) == _iTail);
}

#endif /* _RING_BUFFER_ */

#endif /* __cplusplus */
