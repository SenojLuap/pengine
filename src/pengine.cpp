// pengine.cpp by Paul R Jones (paujo) on 7.31.2014

#include "pengine.h"
#include "SDL/SDL.h"


#ifdef DEBUG
#include <iostream>
#endif

#define pengine Pengine::getPengine()

// Return the singleton instance of Pengine
Pengine& Pengine::getPengine() {
  static Pengine instance;
  return instance;
}

// Initialize the Pengine. NOT performed by the constructor
bool Pengine::startup() {
#ifdef DEBUG
  std::cout << "Starting Pengine...\n";
#endif
  return false;
}

// Releases the resources the Pengine has allocated
bool Pengine::shutdown() {
#ifdef DEBUG
  std::cout << "shutdown\n";
#endif
  return false;
}
int testVal = 0;

// Calls Pengine.startup()
void startEngine() {
#ifdef DEBUG
  std::cout << "startup package\n";
#endif
  pengine.startup();
}

// Calls Pengine.shutdown()
void stopEngine() {
#ifdef DEBUG
  std::cout << "shutdown package\n";
#endif
  pengine.shutdown();
}
