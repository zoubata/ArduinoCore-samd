
#include <Wire.h>
#include <SPI.h>
#include <variant.h>
#include <bootloaders/boot.h>
/** here we just say hello, and return to boot for next update.
*/
void setup() {
  // put your setup code here, to run once:
  P_COM0.serial.begin(9600);
  P_COM2.serial.begin(9600);
  P_COM3.serial.begin(9600);
  P_COM4.serial.begin(9600);
  P_COM5.serial.begin(9600);
  P_COM1.serial2.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
delay(100);
    P_COM0.serial.print("Hello world ! ! !\n");
    P_COM1.serial2.print("Hello world ! ! !\n");
    P_COM2.serial.print("Hello world ! ! !\n");
    P_COM3.serial.print("Hello world ! ! !\n");
    P_COM4.serial.print("Hello world ! ! !\n");
    P_COM5.serial.print("Hello world ! ! !\n");
    delay(1000);//wait the flush serial on the line  before re boost
   jumpInBoot();// I finish, I return on boot for next sketch. to run me again reset.  
    
}
