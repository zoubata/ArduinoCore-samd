
#include <Wire.h>

#include <SPI.h>

/*
 
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
void setupINT() {
  // initialize digital pin LED_BUILTIN as an output.
  int i=0;
 /*  for( i=0;i<52;i++)

  pinMode(i, INPUT_PULLUP);*/

 MySerial.begin(9600);//9600
   MySerial.print("P_COM1 : init");
}



// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
 setupINT();

//  setupserial();
  //setupSPI();
}

int sensorValue = 0; 
unsigned long state=0;
void loopINT()
{
state=1;
MySerial.print("P_COM0");
looppin(P_COM0);
 delay(30);
 MySerial.print("P_COM0BIS");
looppin(P_COM0_BIS);
 delay(30);
 MySerial.print("P_COM1");
looppin(P_COM1);
 delay(30);
 MySerial.print("P_COM2");
looppin(P_COM2);

 delay(30);
 MySerial.print("P_COM3");
looppin(P_COM3);
 delay(30);
 MySerial.print("P_COM4");
looppin(P_COM4);
 delay(30);
 MySerial.print("P_COM5");
looppin(P_COM5);


 MySerial.print("P_ANA0");
 MySerial.print("\t\t");
  testpin(P_ANA0.Pin.INT0);
 MySerial.print("\t\t");
  testpin(P_ANA0.Pin.INT1);
 MySerial.print("\t\t");
  testpin(P_ANA0.Pin.INT2);
 MySerial.print("\t\t");
  testpin(P_ANA0.Pin.INT3);
 MySerial.print("\t\t");
  testpin(P_ANA0.Pin.INT4);
 MySerial.print("\t\t");
  testpin(P_ANA0.Pin.INT5);
 MySerial.print("\t\t");
  testpin(P_ANA0.Pin.INT6);
 MySerial.print("\t\t");
  testpin(P_ANA0.Pin.INT7);


  delay(30);
  
 MySerial.print("P_ANA1");
 MySerial.print("\t\t");
  testpin(P_ANA1.Pin.INT0);
 MySerial.print("\t\t");
  testpin(P_ANA1.Pin.INT1);
 MySerial.print("\t\t");
  testpin(P_ANA1.Pin.INT2);
 MySerial.print("\t\t");
  testpin(P_ANA1.Pin.INT3);
 MySerial.print("\t\t");
  testpin(P_ANA1.Pin.INT4);
 MySerial.print("\t\t");
  testpin(P_ANA1.Pin.INT5);
 MySerial.print("\t\t");
  testpin(P_ANA1.Pin.INT6);
 MySerial.print("\t\t");
  testpin(P_ANA1.Pin.INT7);


  delay(30);
  delay(3000);
MySerial.print("\n");   

}
/** test all pin of a port
*/
void looppin(const struct PComDescription pcom)
{

  MySerial.print("\t\t");
  testpin(pcom.Pin.INT0);
  
  MySerial.print("\t\t");
  testpin(pcom.Pin.INT1);
  
  MySerial.print("\t\t");
  testpin(pcom.Pin.INT2);
  
  MySerial.print("\t\t");
  testpin(pcom.Pin.INT3);
  
  MySerial.print("\t\t");
  testpin(pcom.Pin.INT4);
  
  MySerial.print("\t\t");
  testpin(pcom.Pin.INT5);
  
 
}
signed int intPin=0;
void handlerfunc()
{
   MySerial.print("pin ");  MySerial.print(intPin);  MySerial.print("is ok, ");
   intPin=-1;
  }
/** test interruption on pin interruptPin*/
void testpin(int interruptPin)
{
  
  intPin=interruptPin;
  
   #if defined(BOARD_ID_engi)
  
     if (5==interruptPin)
{ MySerial.print("SKIPPED\n");return;}
if (29==interruptPin)
{ MySerial.print("SKIPPED\n");return;}
/*if (14==interruptPin)//PA30
{ MySerial.print("SKIPPED\n");return;}
if (15==interruptPin)//PA31
{ MySerial.print("SKIPPED\n");return;}*/
   #else
   if (P_COMserial.Pin.TXD==interruptPin)
{ MySerial.print("SKIPPED\n");return;}
if (P_COMserial.Pin.RXD==interruptPin)
{ MySerial.print("SKIPPED\n");return;}
   #endif
   pinMode(interruptPin, INPUT_PULLUP);
   int handlerint=digitalPinToInterrupt(interruptPin);
   int r=0;
   if(handlerint!=NOT_AN_INTERRUPT)
   {
      r=attachInterrupt(handlerint, handlerfunc, CHANGE);
      pinMode(interruptPin, OUTPUT); 
      r=r<<1+digitalRead(interruptPin);
      delay(10);
      digitalWrite(interruptPin, LOW);
      r=r<<1+digitalRead(interruptPin);
      delay(10);
      digitalWrite(interruptPin, HIGH); 
      r=r<<1+digitalRead(interruptPin);
      
      
      pinMode(interruptPin, INPUT_PULLUP);
      delay(10); 
      r=r<<1+digitalRead(interruptPin);
            pinMode(interruptPin, INPUT_PULLDOWN);
      delay(10); 
      r=r<<1+digitalRead(interruptPin);
      delay(10);
      detachInterrupt(handlerint);
    if ( intPin!=-1)
    {MySerial.print("pin ");  MySerial.print(intPin);  MySerial.print("is FAIL :  ");  MySerial.print(r,HEX);}
    else { MySerial.print(r,HEX);}
    
   }
   else
   {
    MySerial.print("no interrupt available now"); 
    }
  MySerial.print("\n");
   delay(100);
}
// the loop function runs over and over again forever
void loop() {
  loopINT();  
  
}

