
#include <Wire.h>

#include <SPI.h>

/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO 
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino model, check
  the Technical Specs of your board  at https://www.arduino.cc/en/Main/Products
  
  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
  
  modified 2 Sep 2016
  by Arturo Guadalupi
  
  modified 8 Sep 2016
  by Colby Newman
*/

#include <variant.h>


#if !defined(LED_BUILTIN)
#define LED_BUILTIN 44
#endif

void setupserial() {
  // initialize both serial ports:
  P_COM0.serial.begin(9600);
  P_COM1.serial.begin(9600);
  P_COM2.serial.begin(9600);
  P_COM3.serial.begin(9600);
  P_COM4.serial.begin(9600);
  P_COM5.serial.begin(9600);
  P_COM1.serial.println("Setup Serial finished");
}
void setupI2C()
{
  P_COM3.wire.begin(4);                // join i2c bus with address #4
  P_COM3.wire.onReceive(receiveEvent); // register event
}
// the setup function runs once when you press reset or power the board
void setupIO() {
  // initialize digital pin LED_BUILTIN as an output.
  int i=0;
   for( i=0;i<52;i++)

  pinMode(i, OUTPUT);


}


void setupSPI() {
  // set the slaveSelectPin as an output:
  pinMode (P_COM2.Pin.CS0, OUTPUT);
  // initialize SPI:
  P_COM0.spi.begin();
  P_COM2.spi.begin();
  P_COM3.spi.begin();
  P_COM4.spi.begin();
  P_COM5.spi.begin();
  P_COM1.serial.begin(9600);
  
  
}

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
 setupIO();

//  setupserial();
  //setupSPI();
}



void loopserial() {
  // read from port 1, send to port 0:
  if (P_COM0.serial.available()) {
    
    int inByte = P_COM0.serial.read();
     P_COM1.serial.print("P_COM0 : ");
     P_COM1.serial.write(inByte);
     P_COM1.serial.print("\n");
    /*P_COM0.serial.write(inByte);
    P_COM1.serial.write(inByte);
    P_COM2.serial.write(inByte);
    P_COM3.serial.write(inByte);
    P_COM4.serial.write(inByte);
    P_COM5.serial.write(inByte);*/    
  }
  if (P_COM1.serial.available()) {
    
    int inByte = P_COM1.serial.read();
     P_COM1.serial.print("P_COM1 : ");
     P_COM1.serial.write(inByte);
     P_COM1.serial.print("\n");
    /*P_COM0.serial.write(inByte);
    P_COM1.serial.write(inByte);
    P_COM2.serial.write(inByte);
    P_COM3.serial.write(inByte);
    P_COM4.serial.write(inByte);
    P_COM5.serial.write(inByte);*/    
  }
  if (P_COM2.serial.available()) {
    
    int inByte = P_COM2.serial.read();
     P_COM1.serial.print("P_COM2 : ");
     P_COM1.serial.write(inByte);
     P_COM1.serial.print("\n");
    /*P_COM0.serial.write(inByte);
    P_COM1.serial.write(inByte);
    P_COM2.serial.write(inByte);
    P_COM3.serial.write(inByte);
    P_COM4.serial.write(inByte);
    P_COM5.serial.write(inByte);*/    
  }
  if (P_COM3.serial.available()) {
    
    int inByte = P_COM3.serial.read();
     P_COM1.serial.print("P_COM3 : ");
     P_COM1.serial.write(inByte);
     P_COM1.serial.print("\n");
    /*P_COM0.serial.write(inByte);
    P_COM1.serial.write(inByte);
    P_COM2.serial.write(inByte);
    P_COM3.serial.write(inByte);
    P_COM4.serial.write(inByte);
    P_COM5.serial.write(inByte);*/    
  }
  if (P_COM4.serial.available()) {
    
    int inByte = P_COM4.serial.read();
     P_COM1.serial.print("P_COM4 : ");
     P_COM1.serial.write(inByte);
     P_COM1.serial.print("\n");
    /*P_COM0.serial.write(inByte);
    P_COM1.serial.write(inByte);
    P_COM2.serial.write(inByte);
    P_COM3.serial.write(inByte);
    P_COM4.serial.write(inByte);
    P_COM5.serial.write(inByte);*/    
  }
  if (P_COM5.serial.available()) {
    
    int inByte = P_COM5.serial.read();
     P_COM1.serial.print("P_COM5 : ");
     P_COM1.serial.write(inByte);
     P_COM1.serial.print("\n");
    /*P_COM0.serial.write(inByte);
    P_COM1.serial.write(inByte);
    P_COM2.serial.write(inByte);
    P_COM3.serial.write(inByte);
    P_COM4.serial.write(inByte);
    P_COM5.serial.write(inByte);*/    
  }
    delay(100);
    P_COM0.serial.print("loop serial0\n");
    P_COM1.serial.print("loop serial1\n");
    P_COM2.serial.print("loop serial2\n");
    P_COM3.serial.print("loop serial3\n");
    P_COM4.serial.print("loop serial4\n");
    P_COM5.serial.print("loop serial5\n");
}

void SpiWrite(const PComDescription * pcom, int address, int value) {
  // take the SS pin low to select the chip:
  digitalWrite(pcom->Pin.CS0, LOW);
  //  send in the address and value via SPI:
  pcom->spi.transfer(address);
  pcom->spi.transfer(value);
  // take the SS pin high to de-select the chip:
  digitalWrite(pcom->Pin.CS0, HIGH);
}

/*
void digitalPotWrite(int address, int value) {
  // take the SS pin low to select the chip:
  digitalWrite(slaveSelectPin, LOW);
  //  send in the address and value via SPI:
  SPI.transfer(address);
  SPI.transfer(value);
  // take the SS pin high to de-select the chip:
  digitalWrite(slaveSelectPin, HIGH);
}*/

void loopSPI() {
  // go through the six channels of the digital pot:
  for (int channel = 0; channel < 6; channel++) {
    // change the resistance on this channel from min to max:
    for (int level = 0; level < 255; level++) {
      SpiWrite(&P_COM2,channel, level);
      delay(10);
    }
    // wait a second at the top:
    delay(100);
    // change the resistance on this channel from max to min:
    for (int level = 0; level < 255; level++) {
      SpiWrite(&(P_COM2),channel, 255 - level);
      delay(10);      
    }
  }

}
int state=LOW;
void loopIO()
{
  if (state==HIGH)
  state=LOW;
  else
  state=HIGH;
  digitalWrite(P_COM0.Pin.P0, state);
  digitalWrite(P_COM0.Pin.P1, state);
  digitalWrite(P_COM0.Pin.P0, state);
  digitalWrite(P_COM0.Pin.P1, state);
  digitalWrite(P_COM0.Pin.P0, state);
  digitalWrite(P_COM0.Pin.P1, state);
  delay(100);  
  digitalWrite(P_COM0_BIS.Pin.IO2, state);
  digitalWrite(P_COM0_BIS.Pin.IO3, state);
  digitalWrite(P_COM0_BIS.Pin.IO2, state);
  digitalWrite(P_COM0_BIS.Pin.IO3, state);
  digitalWrite(P_COM0_BIS.Pin.IO2, state);
  digitalWrite(P_COM0_BIS.Pin.IO3, state);
  delay(100);  
  digitalWrite(P_COM1.Pin.INT4, state);
  digitalWrite(P_COM1.Pin.INT5, state);
  digitalWrite(P_COM1.Pin.INT4, state);
  digitalWrite(P_COM1.Pin.INT5, state);
  digitalWrite(P_COM1.Pin.INT4, state);
  digitalWrite(P_COM1.Pin.INT5, state);
   delay(100);  
  digitalWrite(P_COM2.Pin.Tx0, state);
  digitalWrite(P_COM2.Pin.Tx1, state);
  digitalWrite(P_COM2.Pin.Ty0, state);
  digitalWrite(P_COM2.Pin.Ty1, state);
  digitalWrite(P_COM2.Pin.rsvd3, state);
  digitalWrite(P_COM2.Pin.rsvd4, state);
  delay(100);
  digitalWrite(P_COM3.Pin.SCL, state);
  digitalWrite(P_COM3.Pin.SDA, state);
  digitalWrite(P_COM3.Pin.RXD2, state);
  digitalWrite(P_COM3.Pin.TXD2, state);
  digitalWrite(P_COM3.Pin.rsvd2, state);
  digitalWrite(P_COM3.Pin.GCLKIO, state);
  delay(100);
  digitalWrite(P_COM4.Pin.RXD, state);
  digitalWrite(P_COM4.Pin.TXD, state);
  digitalWrite(P_COM4.Pin.CTS, state);
  digitalWrite(P_COM4.Pin.RTS, state);
  digitalWrite(P_COM4.Pin.rsvd0, state);
  digitalWrite(P_COM4.Pin.rsvd1, state);
  delay(100);

  
  digitalWrite(P_COM5.Pin.SCKs, state);
  digitalWrite(P_COM5.Pin.MOSIs, state);
  digitalWrite(P_COM5.Pin.MISOs, state);
  digitalWrite(P_COM5.Pin.SS, state);
  digitalWrite(P_COM5.Pin.rsvd5, state);
  digitalWrite(P_COM5.Pin.rsvd6, state);
  delay(1000);
  
}

void loopI2C()
{
  delay(100);
}
// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany)
{
  howMany=0;
  while(1 < P_COM3.wire.available()) // loop through all but the last
  {
    char c = P_COM3.wire.read(); // receive byte as a character
    P_COM1.serial.print(c);         // print the character
  }
  int x = P_COM3.wire.read();    // receive byte as an integer
  P_COM1.serial.println(x);         // print the integer
}


// the loop function runs over and over again forever
void loop() {
  //loopserial() ;
  loopIO();
 /* loopSPI();
  loopI2C();// processed on IT/Event*/
 // int i=0;
  /*
//    for( i=0;i<45;i++)
  digitalWrite(i, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);  
//    for(int i=0;i<45;i++)// wait for a second
  digitalWrite(i, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second*/
  
}
