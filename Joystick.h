/*
  Joystick.h - Library for two axis joystick and push button
  Created by Frank Milburn, 22 May 2015
  Released into the public domain.
*/

#if defined(ENERGIA)
  #include "Energia.h"
#else
  #include "Arduino.h"
#endif

#ifndef Joystick_h
#define Joystick_h

class Joystick {
  protected:
    int _xPin;
    int _yPin;
    int _pushPin;
    int _analogRes;
    
  public:
    Joystick(int xPin, int yPin, int pushPin, int analogRes);
    void begin();
    int readX();
    int readY();
    int readInvertedX();
    int readInvertedY();
    int readPushButton();
};
#endif   // Joystick.h
