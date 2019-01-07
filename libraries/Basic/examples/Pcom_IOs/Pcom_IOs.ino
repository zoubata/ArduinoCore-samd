
#include <Wire.h>

#include <SPI.h>
#include <bootloaders/boot.h>

/*
 Test code to check that function works.
 It give also example of how to use the framework
 
*/

#include <variant.h>


#if !defined(LED_BUILTIN)
#define LED_BUILTIN 44
#endif

// the setup function runs once when you press reset or power the board
// all GPIO validated 
void setupIO() {
  // initialize digital pin LED_BUILTIN as an output.
  int i=0;
   for( i=0;i<52;i++)

  pinMode(i, OUTPUT);


}

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
 setupIO();

//  setupserial();
  //setupSPI();
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
  digitalWrite(P_COM0.Pin.P2, state);
  digitalWrite(P_COM0.Pin.P3, state);
  digitalWrite(P_COM0.Pin.P4, state);
  digitalWrite(P_COM0.Pin.P5, state);
  delay(10);  
  digitalWrite(P_COM0_BIS.Pin.IO0, state);
  digitalWrite(P_COM0_BIS.Pin.IO1, state);
  digitalWrite(P_COM0_BIS.Pin.IO2, state);
  digitalWrite(P_COM0_BIS.Pin.IO3, state);
  digitalWrite(P_COM0_BIS.Pin.IO4, state);
  digitalWrite(P_COM0_BIS.Pin.IO5, state);
  delay(10);  
  digitalWrite(P_COM1.Pin.INT0, state);
  digitalWrite(P_COM1.Pin.INT1, state);
  digitalWrite(P_COM1.Pin.INT2, state);
  digitalWrite(P_COM1.Pin.INT3, state);
  digitalWrite(P_COM1.Pin.INT4, state);
  digitalWrite(P_COM1.Pin.INT5, state);
   delay(10);  
  digitalWrite(P_COM2.Pin.Tx0, state);
  digitalWrite(P_COM2.Pin.Tx1, state);
  digitalWrite(P_COM2.Pin.Ty0, state);
  digitalWrite(P_COM2.Pin.Ty1, state);
  digitalWrite(P_COM2.Pin.rsvd3, state);
  digitalWrite(P_COM2.Pin.rsvd4, state);
  delay(10);
  digitalWrite(P_COM3.Pin.SCL, state);
  digitalWrite(P_COM3.Pin.SDA, state);
  digitalWrite(P_COM3.Pin.RXD2, state);
  digitalWrite(P_COM3.Pin.TXD2, state);
  digitalWrite(P_COM3.Pin.rsvd2, state);
  digitalWrite(P_COM3.Pin.GCLKIO, state);
  delay(10);
  digitalWrite(P_COM4.Pin.RXD, state);
  digitalWrite(P_COM4.Pin.TXD, state);
  digitalWrite(P_COM4.Pin.CTS, state);
  digitalWrite(P_COM4.Pin.RTS, state);
  digitalWrite(P_COM4.Pin.rsvd0, state);
  digitalWrite(P_COM4.Pin.rsvd1, state);
  delay(10);

  
  digitalWrite(P_COM5.Pin.SCKs, state);
  digitalWrite(P_COM5.Pin.MOSIs, state);
  digitalWrite(P_COM5.Pin.MISOs, state);
  digitalWrite(P_COM5.Pin.SS, state);
  digitalWrite(P_COM5.Pin.rsvd5, state);
  digitalWrite(P_COM5.Pin.rsvd6, state);
  delay(10);

  
  digitalWrite(P_ANA0.Pin.A0, state);
  digitalWrite(P_ANA0.Pin.A1, state);
  digitalWrite(P_ANA0.Pin.A2, state);
  digitalWrite(P_ANA0.Pin.A3, state);
  digitalWrite(P_ANA0.Pin.A4, state);
  digitalWrite(P_ANA0.Pin.A5, state);
  digitalWrite(P_ANA0.Pin.A6, state);
  digitalWrite(P_ANA0.Pin.A7, state);
  delay(10);

  
  digitalWrite(P_ANA1.Pin.IO0, state);
  digitalWrite(P_ANA1.Pin.IO1, state);
  digitalWrite(P_ANA1.Pin.IO2, state);
  digitalWrite(P_ANA1.Pin.INT3, state);
  digitalWrite(P_ANA1.Pin.INT4, state);
  digitalWrite(P_ANA1.Pin.INT5, state);
  digitalWrite(P_ANA1.Pin.INT6, state);
  digitalWrite(P_ANA1.Pin.INT7, state);
  delay(100);
  
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
