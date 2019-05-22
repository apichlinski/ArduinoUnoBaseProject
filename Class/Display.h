/*
  Display.h - Library for flashing Display code.
  Created by Andrzej P., May 22, 2019.
  Released into the public domain.
*/
/*!
* \file
* \brief Definicja metody klasy Display
*
* Zawiera definicję metod klasy Display.
*/
#ifndef Morse_h
#define Morse_h

#include "Arduino.h"

class Display
{
  public:
    Display(int pin);
    void dot();
    void dash();
  private:
    int _pin;
};

#endif