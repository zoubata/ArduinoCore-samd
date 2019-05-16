#include <Arduino.h>


#include <Wire.h>
#include <SPI.h>
#include <variant.h>

#include <bootloaders/boot.h>


#if defined(BOARD_ID_Pilo) 
//#include "C:\Temp\robot\git\intern\robot1\arduino\codePierre\sketch_mar30a\sketch_mar30a.ino"
//#include "C:\Temp\robot\git\intern\robot1\arduino\codePierre\sketch_mar30b_Pilo_Test_soft\sketch_mar30b_Pilo_Test_soft.ino"
//#include "C:\Users\M43507\Documents\Arduino\sketch_mar31a_Pilo_Ultrason\sketch_mar31a_Pilo_Ultrason.ino"
//#include "C:\Users\M43507\Documents\Arduino\sketch_mar31a_PILO_7SEG_LED.ino\sketch_mar31a_PILO_7SEG_LED.ino.ino"
//#include "C:\Temp\robot\git\intern\robot1\arduino\codePierre\sketch_apr08e_Captor_ZMOTOR3\sketch_apr08e_Captor_ZMOTOR3.ino"
//#include "C:\Temp\robot\git\intern\robot1\arduino\Pcom_ana\Pcom_ana.ino"
//#include "C:\Temp\robot\git\intern\robot1\arduino\codePierre\sketch_apr23a_PILO_7SEG_LED\sketch_apr23a_PILO_7SEG_LED.ino"
//#include "C:\Users\M43507\Documents\Arduino\libraries\Zeeprom\examples\WriteReadBytes\WriteReadBytes.ino"
//#include "C:\Users\M43507\Documents\Arduino\libraries\Zsamba\examples\BootLoaderSample\BootLoaderSample.ino"
//#include "C:\Temp\robot\git\intern\robot1\arduino\codePierre\sketch_may03_Pilo_gateway_uart_wire\sketch_may03_Pilo_gateway_uart_wire.ino"
//#include "C:\Users\M43507\Documents\Arduino\libraries\Zsamba\examples\BootLoaderSample\BootLoaderSample.ino"
//#include "C:\Temp\robot\git\intern\robot1\arduino\codeFlorine\colorview_pilo_may03\colorview_pilo_may03.ino"
//#include "C:\Temp\robot\git\intern\robot1\arduino\codePierre\sketch_Captor_may02_gateway_uart_uart\sketch_Captor_may02_gateway_uart_uart.ino"
//#include "C:\Users\M43507\Documents\Arduino\servoWithROS\servoWithROS.ino"
//#include "C:\Users\M43507\Documents\Arduino\robot\pilo\20181118_servo\20181118_servo.ino"
//#include "C:\Users\M43507\Documents\Arduino\libraries\ZMotor2\examples\Zmotor2WithRos\Zmotor2WithRos.ino"
//#include "C:\Users\M43507\Documents\Arduino\robot\pilo\20181118_motor2\20181118_motor2.ino"
//OK #include "C:\Users\M43507\Documents\Arduino\libraries\ZServoPCA9685\examples\servoWithROS\servoWithROS.ino"
//#include "C:\Users\M43507\Documents\Arduino\robot\pilo\20181118_motor2-servo\20181118_motor2-servo.ino"
//#include "C:\Users\M43507\Documents\Arduino\libraries\Adafruit-PWM-Servo-Driver-Library\examples\servo\servo.ino";
//#include "C:\Users\M43507\Documents\Arduino\libraries\ZServoPCA9685\examples\servo\servo.ino"
//#include "C:\Users\M43507\Documents\Arduino\libraries\ZMotor2\examples\Zmotor2\Zmotor2.ino"
//#include "C:\Users\M43507\Documents\Arduino\robot\pilo\20190203_motor2-servo\20190203_motor2-servo.ino"
//#include "C:\Users\M43507\Documents\Arduino\robot\pilo\20190303_motor2-servo\20190303_motor2-servo.ino"
//#include "C:\Users\M43507\Documents\Arduino\libraries\RGB-matrix-Panel\examples\plasma_32x32\plasma_32x32.ino"
//#include "C:\Users\M43507\Documents\Arduino\robot\pilo\20190317_matrix\20190317_matrix.ino"
//#include "C:\Users\M43507\Documents\Arduino\robot\pilo\20190318_matrix\20190318_matrix.ino"
//#include "C:\Users\M43507\Documents\Arduino\robot\pilo\20190320_matrix\20190320_matrix.ino"
//#include "C:\Users\M43507\Documents\Arduino\robot\pilo\20190331_motor2-servo\20190331_motor2-servo.ino";

//#include "C:\Users\M43507\Documents\Arduino\robot\pilo\20190417_motor2-servo-LCD-switch\20190417_motor2-servo-LCD-switch.ino";
//#include "C:\Users\M43507\Documents\Arduino\robot\pilo\20190512_motor2-servo-LCD\20190512_motor2-servo-LCD.ino";
#include "C:\Users\M43507\Documents\Arduino\robot\pilo\20190515_motor2-servo-LCD-switch\20190515_motor2-servo-LCD-switch.ino";


/*
USB_VID=0x16D0 
USB_PID=0x1234
USBCON
USB_MANUFACTURER="Zoubworld"
USB_PRODUCT="Pilo Rev A0"

*/
#elif defined(BOARD_ID_Captor)

//#include "C:\Temp\robot\git\intern\robot1\arduino\codePierre\sketch_Captor_mar29a\sketch_Captor_mar29a.ino"
//#include "C:\Temp\robot\git\intern\robot1\arduino\codePierre\sketch_apr30c_Captor_Test_soft\sketch_apr30c_Captor_Test_soft.ino"
//#include "C:\Temp\robot\git\intern\robot1\arduino\codePierre\sketch_apr02d_Captor_encoder\sketch_apr02d_Captor_encoder.ino"
//#include "C:\Temp\robot\git\intern\robot1\arduino\codePierre\sketch_apr02d_Captor_encoder\sketch_apr02d_Captor_encoder.ino"
//#include "C:\Temp\robot\git\intern\robot1\arduino\codePierre\sketch_apr06a_Captor_PCA9685\sketch_apr06a_Captor_PCA9685.ino"
//#include "C:\Temp\robot\git\intern\robot1\arduino\codePierre\sketch_apr07c_Captor_ZPCA9685\sketch_apr07c_Captor_ZPCA9685.ino"
//#include "C:\Temp\robot\git\intern\robot1\arduino\codePierre\sketch_apr08c_Captor_ZMCP23017\sketch_apr08c_Captor_ZMCP23017.ino"
//#include "C:\Temp\robot\git\intern\robot1\arduino\codePierre\sketch_apr08c_Captor_ZMCP23017_io\sketch_apr08c_Captor_ZMCP23017_io.ino"
//#include "C:\Temp\robot\git\intern\robot1\arduino\codePierre\sketch_apr08c_Captor_ZPCA9685_MCP23017\sketch_apr08c_Captor_ZPCA9685_MCP23017.ino"
//#include "C:\Users\M43507\Documents\Arduino\sketch_apr08c_MCP23017_io\sketch_apr08c_MCP23017_io.ino"
//#include "C:\Temp\robot\git\intern\robot1\arduino\codePierre\sketch_apr08d_Captor_ZMOTOR2\sketch_apr08d_Captor_ZMOTOR2.ino"
//#include "C:\Temp\robot\git\intern\robot1\arduino\codePierre\sketch_apr08e_Captor_ZMOTOR3\sketch_apr08e_Captor_ZMOTOR3.ino"
//#include "C:\Temp\robot\git\intern\robot1\arduino\codePierre\sketch_apr21a_Captor_full\sketch_apr21a_Captor_full.ino"
//#include "C:\Users\M43507\Documents\Arduino\libraries\Zsamba\examples\BootLoaderSample\BootLoaderSample.ino"

//#include "C:\Users\M43507\Documents\Arduino\libraries\Zeeprom\examples\WriteReadBytes\WriteReadBytes.ino"

//#include "C:\Temp\robot\git\intern\robot1\arduino\codePierre\sketch_apr10a_captor_comm_G2P_HCSR04\sketch_apr10a_captor_comm_G2P_HCSR04.ino"
//#include "C:\Temp\robot\git\intern\robot1\arduino\codePierre\sketch_apr11b_Captor_Pcom_ana\sketch_apr11b_Captor_Pcom_ana.ino"
//#include "C:\Temp\robot\git\intern\robot1\arduino\codePierre\sketch_may04a_Captor_full\sketch_may04a_Captor_full.ino"
//#include "C:\Users\M43507\Documents\Arduino\libraries\ZEncoder\examples\Encoder_example\Encoder_example.ino"
//#include "C:\Users\M43507\Documents\Arduino\libraries\ZCmdMotor\examples\ZcmdMotor_example\ZcmdMotor_example.ino"
//#include "C:\Users\M43507\Documents\Arduino\libraries\ZOpticalSensor\examples\getMeasure\getMeasure.ino"
//#include "C:\Users\M43507\Documents\Arduino\libraries\ZOpticalSensor\examples\getMeasureROS\getMeasureROS.ino"
//#include "C:\Temp\robot\git\intern\robot1\arduino\codePierre\sketch_apr08e_Captor_ZMOTOR3\sketch_apr08e_Captor_ZMOTOR3.ino"
//#include "C:\Users\M43507\Documents\Arduino\robot\captor\telecommandev1\telecommandev1.ino"
//#include "C:\Users\M43507\Documents\Arduino\robot\captor\telecommandev2\telecommandev2.ino"
//#include "C:\Users\M43507\Documents\Arduino\robot\captor\telecommandev3\telecommandev3.ino"
//#include "C:\Users\M43507\Documents\Arduino\robot\captor\telecommandev2019_03_18\telecommandev2019_03_18.ino"
//#include "C:\Users\M43507\Documents\Arduino\robot\captor\telecommandev2019_03_31\telecommandev2019_03_31.ino"
#include "C:\Users\M43507\Documents\Arduino\robot\captor\telecommandev2019_05_12\telecommandev2019_05_12.ino"


//#include "C:\Users\M43507\Documents\Arduino\robot\captor\debug_ros_0\debug_ros_0.ino"

#elif defined(BOARD_ID_Line)
#include "C:\Temp\robot\git\intern\robot1\arduino\codePierre\sketch_mar31a_UNO_7SEG_LED.ino\sketch_mar31a_UNO_7SEG_LED.ino.ino"

#else
#error not planed
#endif

