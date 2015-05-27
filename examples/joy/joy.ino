/* 
 Joystick Example
 Demonstrates Addicore joystick with push button - displays to Serial Monitor
 http://www.addicore.com/Dual-Axis-XY-Joystick-Module-with-Push-Button-p/139.htm
 
 Created by Frank Milburn, 22 May 2015
 Released into the public domain.
 
 Library contents
 ----------------
 .begin(xPin, yPin, pushPin, analogRes)  sets things up
 .readX()                                reads the X value of the joystick
 .readY()                                reads the Y value of the joystick
 .readInvertedX()                        reads an inverted X value, i.e. 0 on
                                         the X axis when joystick pushed right
 .readInvertedY()                        reads an inverted Y value, i.e. 0 on
                                         the Y axis when joystick pushed down
 .readPushButton()                       reads the push button state
 
 Pin and wiring connections
 --------------------------
 Note that the pin connections can be changed but VRX and VRY on the joystick
 must be connected to analog pins.  Connect the button (SW) to a digital pin.
 Pin connections that will work for most Texas Instruments LaunchPads, also
 connections for Arduino Uno are given below...
 
 Joystick      LaunchPads  Arduino
 --------      ----------  --------
 GND           GND         GND       
 +5V           3V3         5V
 VRX           2           A0
 VRY           6           A1
 SW            5           2
 
 Caution! Most LaunchPads are 3V3 devices!  Do not wire pins directly to 5V.
 The joystick  will work fine at 3.3V on these LaunchPads.
 
 Caution! The CC3200 LaunchPad is limited to 1.8V for analog input!  Use a
 voltage divider or other means to reduce analog voltage down to 1.8V.
 
 */

 #include "Joystick.h" 

 const int xPin = 2;               // x direction potentiometer pin (analog)
 const int yPin = 6;               // y direction potentiometer pin (analog)
 const int pushPin = 5;            // Push button pin (digital)
 const int analogRes = 4095;       // Highest analog reading for microcontroller 
                                   // (e.g. 4095 for MSP-EXP430F5529, 1023 for
                                   // MSP-EXP430G2 and Arduino Uno)

 // Instantiate the joystick
 Joystick joy(xPin, yPin, pushPin, analogRes);

 void setup()
 {
   joy.begin();
   Serial.begin(9600);
   Serial.println("Starting joystick demo...");
 }

 void loop() 
 {   
   Serial.print("X = ");     Serial.print(joy.readX());         Serial.print("   ");
   Serial.print("Inv X = "); Serial.print(joy.readInvertedX()); Serial.print("   ");
   Serial.print("Y = ");     Serial.print(joy.readY());         Serial.print("   ");
   Serial.print("Inv Y = "); Serial.print(joy.readInvertedY()); Serial.print("   ");
   Serial.print("Button = ");Serial.print(joy.readPushButton());Serial.println("");
   
   delay(200);  
 }
