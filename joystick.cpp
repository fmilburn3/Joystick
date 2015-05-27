/*
  Joystick.cpp - Library for two axis joystick and push button
  Created by Frank Milburn, 22 May 2015
  Released into the public domain.
*/

#if defined(ENERGIA)
  #include "Energia.h"
#else
  #include "Arduino.h"
#endif

#include "Joystick.h"

// Constructor
Joystick::Joystick(int xPin, int yPin, int pushPin, int analogRes)
{
  _xPin = xPin;
  _yPin = yPin;
  _pushPin = pushPin;
  _analogRes = analogRes;
}

// Initialization
void Joystick::begin()
{
  pinMode(_pushPin, INPUT_PULLUP);
}

// Read x axis
int Joystick::readX()
{
  return analogRead(_xPin);
}

// Read y axis
int Joystick::readY()
{
  return analogRead(_yPin);
}

// Read x axis and invert
int Joystick::readInvertedX()
{
  return abs(_analogRes - analogRead(_xPin));
}

// Read y axis and invert
int Joystick::readInvertedY()
{
  return abs(_analogRes - analogRead(_yPin));
}

// Read state of push button (0 if pushed, 1 if not)
int Joystick::readPushButton()
{
  return digitalRead(_pushPin);
}
