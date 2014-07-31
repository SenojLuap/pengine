// pengine.cpp by Paul R Jones (paujo) on 7.31.2014

#include "pengine.h"
#ifdef DEBUG
#include <iostream>
#endif

// Return the singleton instance of Pengine
Pengine& Pengine::getPengine() {
  static Pengine instance;
  return instance;
}

// Initialize the Pengine. NOT performed by the constructor
bool Pengine::init() {
#ifdef DEBUG
  std::cout << "init\n";
#endif
  return false;
}

// Releases the resources the Pengine has allocated
bool Pengine::exit() {
#ifdef DEBUG
  std::cout << "exit\n";
#endif
  return false;
}
