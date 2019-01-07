
#include <Wire.h>

#include <SPI.h>

/*
 Test code to check that function works.
 It give also example of how to use the framework
 
*/

#include <variant.h>

/** do an alis to be able to change connector */
#define P_COMserial P_COM1
/** build a compact name */
#define MySerial P_COMserial.serial

#if !defined(LED_BUILTIN)
#define LED_BUILTIN 44
#endif

// the setup function runs once when you press reset or power the board
void setupI() {
  // initialize digital pin LED_BUILTIN as an output.
  int i=0;
 /*  for( i=0;i<52;i++)

  pinMode(i, INPUT_PULLUP);*/

 MySerial.begin(9600);
   MySerial.print("P_COM1 : init");
}



// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
 setupI();

//  setupserial();
  //setupSPI();
}

int sensorValue = 0; 
unsigned long state=0;
void loopI()
{
state=1;

  state=(unsigned long)(state<<1)+digitalRead(P_COM0.Pin.P0);
  state=(unsigned long)(state<<1)+digitalRead(P_COM0.Pin.P0);
    state=(unsigned long)(state<<1)+digitalRead(P_COM0.Pin.P0);
    state=(unsigned long)(state<<1)+digitalRead(P_COM0.Pin.P1);
    state=(unsigned long)(state<<1)+digitalRead(P_COM0.Pin.P0);
    state=(unsigned long)(state<<1)+digitalRead(P_COM0.Pin.P1);
  delay(10);  
    state=(unsigned long)(state<<1)+digitalRead(P_COM0_BIS.Pin.IO2);
    state=(unsigned long)(state<<1)+digitalRead(P_COM0_BIS.Pin.IO3);
    state=(unsigned long)(state<<1)+digitalRead(P_COM0_BIS.Pin.IO2);
    state=(unsigned long)(state<<1)+digitalRead(P_COM0_BIS.Pin.IO3);
    state=(unsigned long)(state<<1)+digitalRead(P_COM0_BIS.Pin.IO2);
    state=(unsigned long)(state<<1)+digitalRead(P_COM0_BIS.Pin.IO3);
  delay(10);  
    state=(unsigned long)(state<<1)+digitalRead(P_COM1.Pin.INT4);
    state=(unsigned long)(state<<1)+digitalRead(P_COM1.Pin.INT5);
    state=(unsigned long)(state<<1)+digitalRead(P_COM1.Pin.INT4);
    state=(unsigned long)(state<<1)+digitalRead(P_COM1.Pin.INT5);
    state=(unsigned long)(state<<1)+digitalRead(P_COM1.Pin.INT4);
    state=(unsigned long)(state<<1)+digitalRead(P_COM1.Pin.INT5);
   delay(10);  
    state=(unsigned long)(state<<1)+digitalRead(P_COM2.Pin.Tx0);
    state=(unsigned long)(state<<1)+digitalRead(P_COM2.Pin.Tx1);
    state=(unsigned long)(state<<1)+digitalRead(P_COM2.Pin.Ty0);
    state=(unsigned long)(state<<1)+digitalRead(P_COM2.Pin.Ty1);
    state=(unsigned long)(state<<1)+digitalRead(P_COM2.Pin.rsvd3);
    state=(unsigned long)(state<<1)+digitalRead(P_COM2.Pin.rsvd4);
  delay(1);
    state=(unsigned long)(state<<1)+digitalRead(P_COM3.Pin.SCL);
    state=(unsigned long)(state<<1)+digitalRead(P_COM3.Pin.SDA);
    state=(unsigned long)(state<<1)+digitalRead(P_COM3.Pin.RXD2);
    state=(unsigned long)(state<<1)+digitalRead(P_COM3.Pin.TXD2);
    state=(unsigned long)(state<<1)+digitalRead(P_COM3.Pin.rsvd2);
    state=(unsigned long)(state<<1)+digitalRead(P_COM3.Pin.GCLKIO);
  delay(1);
    state=(unsigned long)(state<<1)+digitalRead(P_COM4.Pin.RXD);
    state=(unsigned long)(state<<1)+digitalRead(P_COM4.Pin.TXD);
    state=(unsigned long)(state<<1)+digitalRead(P_COM4.Pin.CTS);
    state=(unsigned long)(state<<1)+digitalRead(P_COM4.Pin.RTS);
    state=(unsigned long)(state<<1)+digitalRead(P_COM4.Pin.rsvd0);
    state=(unsigned long)(state<<1)+digitalRead(P_COM4.Pin.rsvd1);
  delay(1);

    state=(unsigned long)(state<<1)+digitalRead(P_COM5.Pin.SCKs);
    state=(unsigned long)(state<<1)+digitalRead(P_COM5.Pin.MOSIs);
    state=(unsigned long)(state<<1)+digitalRead(P_COM5.Pin.MISOs);
    state=(unsigned long)(state<<1)+digitalRead(P_COM5.Pin.SS);
    state=(unsigned long)(state<<1)+digitalRead(P_COM5.Pin.rsvd5);
    state=(unsigned long)(state<<1)+digitalRead(P_COM5.Pin.rsvd6);

    MySerial.print("DIG=");  
    MySerial.print(((unsigned long)state)&0xffffffff,HEX);MySerial.print(((unsigned long)state)>>32,HEX);         // print the character
    sensorValue = analogRead(P_ANA0.Pin.A0);
   
     MySerial.print("PA0=");   MySerial.print((sensorValue*3.3)/1024);   MySerial.print("v \t");   
    sensorValue = analogRead(P_ANA0.Pin.A1);
     MySerial.print("PA1=");   MySerial.print((sensorValue*3.3)/1024);   MySerial.print("v \t");   
    sensorValue = analogRead(P_ANA0.Pin.A2);
     MySerial.print("PA2=");   MySerial.print((sensorValue*3.3)/1024);   MySerial.print("v \t");   
    sensorValue = analogRead(P_ANA0.Pin.A3);
     MySerial.print("PA3=");   MySerial.print((sensorValue*3.3)/1024);   MySerial.print("v \t");   
    sensorValue = analogRead(P_ANA0.Pin.A4);
     MySerial.print("PA4=");   MySerial.print((sensorValue*3.3)/1024);   MySerial.print("v \t");   
    sensorValue = analogRead(P_ANA0.Pin.A5);
     MySerial.print("PA5=");   MySerial.print((sensorValue*3.3)/1024);   MySerial.print("v \t");   
    sensorValue = analogRead(P_ANA0.Pin.A6);
     MySerial.print("PA6=");   MySerial.print((sensorValue*3.3)/1024);   MySerial.print("v \t");   
    sensorValue = analogRead(P_ANA0.Pin.A7);
     MySerial.print("PA7=");   MySerial.print((sensorValue*3.3)/1024);   MySerial.print("v \t");   

    sensorValue = analogRead(P_ANA1.Pin.A0);
     MySerial.print("PA0=");   MySerial.print((sensorValue*3.3)/1024);   MySerial.print("v \t");   
    sensorValue = analogRead(P_ANA1.Pin.A1);
     MySerial.print("PA1=");   MySerial.print((sensorValue*3.3)/1024);   MySerial.print("v \t");   
    sensorValue = analogRead(P_ANA1.Pin.A2);
     MySerial.print("PA2=");   MySerial.print((sensorValue*3.3)/1024);   MySerial.print("v \t");   
    sensorValue = analogRead(P_ANA1.Pin.A3);
     MySerial.print("PA3=");   MySerial.print((sensorValue*3.3)/1024);   MySerial.print("v \t");   
    sensorValue = analogRead(P_ANA1.Pin.A4);
     MySerial.print("PA4=");   MySerial.print((sensorValue*3.3)/1024);   MySerial.print("v \t");   
    sensorValue = analogRead(P_ANA1.Pin.A5);
     MySerial.print("PA5=");   MySerial.print((sensorValue*3.3)/1024);   MySerial.print("v \t");   
    sensorValue = analogRead(P_ANA1.Pin.A6);
     MySerial.print("PA6=");   MySerial.print((sensorValue*3.3)/1024);   MySerial.print("v \t");   
    sensorValue = analogRead(P_ANA1.Pin.A7);
     MySerial.print("PA7=");   MySerial.print((sensorValue*3.3)/1024);   MySerial.print("v \t");   
  delay(300);
MySerial.print("\n");   

}


// the loop function runs over and over again forever
void loop() {
  loopI();  
}
