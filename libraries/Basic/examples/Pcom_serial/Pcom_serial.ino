
#include <Wire.h>

#include <SPI.h>

/*
 Test code to check that function works.
 It give also example of how to use the framework
 
*/

#include <variant.h>


#if !defined(LED_BUILTIN)
#define LED_BUILTIN 44
#endif
#define Myseriel P_COM1.serial2
// all serial validated exepted
// PCOM_BIS and ann serial2.

void setupserial() {
  // initialize both serial ports:
  P_COM0.serial.begin(9600);
  P_COM2.serial.begin(9600);
  P_COM3.serial.begin(9600);
  P_COM4.serial.begin(9600);
  P_COM5.serial.begin(9600);
  P_COM1.serial.begin(9600);
  Myseriel.begin(9600);
 
  Myseriel.println("Setup Serial finished");
  
}

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.

  setupserial();
  //setupSPI();
}


void loopserial() {
  // read from port 1, send to port 0:
  if (P_COM0.serial.available()) {
    
    int inByte = P_COM0.serial.read();
     Myseriel.print("P_COM0 : ");
     Myseriel.write(inByte);
     Myseriel.print("\n");
    /*P_COM0.serial.write(inByte);
    Myseriel.write(inByte);
    P_COM2.serial.write(inByte);
    P_COM3.serial.write(inByte);
    P_COM4.serial.write(inByte);
    P_COM5.serial.write(inByte);*/    
  }
  if (P_COM1.serial.available()) {
    
    int inByte = P_COM1.serial.read();
     Myseriel.print("P_COM1 : ");
     Myseriel.write(inByte);
     Myseriel.print("\n");
    /*P_COM0.serial.write(inByte);
    Myseriel.write(inByte);
    P_COM2.serial.write(inByte);
    P_COM3.serial.write(inByte);
    P_COM4.serial.write(inByte);
    P_COM5.serial.write(inByte);*/    
  }
  if (P_COM2.serial.available()) {
    
    int inByte = P_COM2.serial.read();
     Myseriel.print("P_COM2 : ");
     Myseriel.write(inByte);
     Myseriel.print("\n");
    /*P_COM0.serial.write(inByte);
    Myseriel.write(inByte);
    P_COM2.serial.write(inByte);
    P_COM3.serial.write(inByte);
    P_COM4.serial.write(inByte);
    P_COM5.serial.write(inByte);*/    
  }
  if (P_COM3.serial.available()) {
    
    int inByte = P_COM3.serial.read();
     Myseriel.print("P_COM3 : ");
     Myseriel.write(inByte);
     Myseriel.print("\n");
    /*P_COM0.serial.write(inByte);
    Myseriel.write(inByte);
    P_COM2.serial.write(inByte);
    P_COM3.serial.write(inByte);
    P_COM4.serial.write(inByte);
    P_COM5.serial.write(inByte);*/    
  }
  if (P_COM4.serial.available()) {
    
    int inByte = P_COM4.serial.read();
     Myseriel.print("P_COM4 : ");
     Myseriel.write(inByte);
     Myseriel.print("\n");
    /*P_COM0.serial.write(inByte);
    Myseriel.write(inByte);
    P_COM2.serial.write(inByte);
    P_COM3.serial.write(inByte);
    P_COM4.serial.write(inByte);
    P_COM5.serial.write(inByte);*/    
  }
  if (P_COM5.serial.available()) {
    
    int inByte = P_COM5.serial.read();
     Myseriel.print("P_COM5 : ");
     Myseriel.write(inByte);
     Myseriel.print("\n");
    /*P_COM0.serial.write(inByte);
    Myseriel.write(inByte);
    P_COM2.serial.write(inByte);
    P_COM3.serial.write(inByte);
    P_COM4.serial.write(inByte);
    P_COM5.serial.write(inByte);*/    
  }
    delay(100);
    P_COM0.serial.print("loop serial0\n");
    P_COM1.serial.print("loop serial1\n");
    Myseriel.print("loop serial1\n");
    P_COM2.serial.print("loop serial2\n");
    P_COM3.serial.print("loop serial3\n");
    P_COM4.serial.print("loop serial4\n");
    P_COM5.serial.print("loop serial5\n");
}


// the loop function runs over and over again forever
void loop() {
  loopserial() ;
 
  
}
