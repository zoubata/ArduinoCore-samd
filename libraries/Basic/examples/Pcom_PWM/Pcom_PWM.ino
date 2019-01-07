
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

// the setup function runs once when you press reset or power the board
void setupPWM() {
 


}

// the setup function runs once when you press reset or power the board
// code on arduino validated :  all PWM are ok
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
 setupPWM();

//  setupserial();
  //setupSPI();
}


void loopPWM()
{


   delay(10);  
   for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
    analogWrite(P_COM0.Pin.Tx0, fadeValue);
	analogWrite(P_COM0.Pin.Tx1, fadeValue);
    analogWrite(P_COM0.Pin.Ty0, fadeValue);
    analogWrite(P_COM0.Pin.Ty1, fadeValue);
	
    analogWrite(P_COM0_BIS.Pin.Tx0, fadeValue);
	analogWrite(P_COM0_BIS.Pin.Tx1, fadeValue);
    analogWrite(P_COM0_BIS.Pin.Ty0, fadeValue);
    analogWrite(P_COM0_BIS.Pin.Ty1, fadeValue);
    
	analogWrite(P_COM1.Pin.Tx0, fadeValue);
	analogWrite(P_COM1.Pin.Tx1, fadeValue);
    analogWrite(P_COM1.Pin.Ty0, fadeValue);
    analogWrite(P_COM1.Pin.Ty1, fadeValue);
    
	analogWrite(P_COM2.Pin.Tx0, fadeValue);
	analogWrite(P_COM2.Pin.Tx1, fadeValue);
    analogWrite(P_COM2.Pin.Ty0, fadeValue);
    analogWrite(P_COM2.Pin.Ty1, fadeValue);
    
	analogWrite(P_COM3.Pin.Tx0, fadeValue);
	analogWrite(P_COM3.Pin.Tx1, fadeValue);
    analogWrite(P_COM3.Pin.Ty0, fadeValue);
    analogWrite(P_COM3.Pin.Ty1, fadeValue);
    
	analogWrite(P_COM4.Pin.Tx0, fadeValue);
	analogWrite(P_COM4.Pin.Tx1, fadeValue);
    analogWrite(P_COM4.Pin.Ty0, fadeValue);
    analogWrite(P_COM4.Pin.Ty1, fadeValue);
    
	analogWrite(P_COM5.Pin.Tx0, fadeValue);
	analogWrite(P_COM5.Pin.Tx1, fadeValue);
    analogWrite(P_COM5.Pin.Ty0, fadeValue);
    analogWrite(P_COM5.Pin.Ty1, fadeValue);
      delay(10);
	
	}
 
  
}


// the loop function runs over and over again forever
void loop() {
  
  loopPWM();
}
