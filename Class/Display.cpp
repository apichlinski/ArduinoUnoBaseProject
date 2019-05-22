/*
  Display.cpp - Library for flashing Display code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/

#include "Arduino.h"
#include "Display.h"

/*!
* Wyznacza pole powierzchni danego kwadratu
* i zwraca jego wartość.
*
* \return Zwraca pole powierzchni kwadratu. Jest ono wyrażone
* w jednostkach niemianowanych.
*/
Display::Display(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
}

/*!
* Wyznacza pole powierzchni danego kwadratu
* i zwraca jego wartość.
*
* \return Zwraca pole powierzchni kwadratu. Jest ono wyrażone
* w jednostkach niemianowanych.
*/
void Display::dot()
{
  digitalWrite(_pin, HIGH);
  delay(250);
  digitalWrite(_pin, LOW);
  delay(250);  
}

/*!
* Wyznacza pole powierzchni danego kwadratu
* i zwraca jego wartość.
*
* \return Zwraca pole powierzchni kwadratu. Jest ono wyrażone
* w jednostkach niemianowanych.
*/
void Display::dash()
{
  digitalWrite(_pin, HIGH);
  delay(1000);
  digitalWrite(_pin, LOW);
  delay(250);
}