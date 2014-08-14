// Color.cpp by Paul R Jones (paujo) on 8.6.2014

#include "Color.h"


// Ctor.
Color::Color() {
  r = 0;
  g = 0;
  b = 0;
  a = 0xFF;
}


// Ctor.
Color::Color(int red, int green, int blue, int alpha) : r(red), g(green), b(blue), a(alpha) { }
