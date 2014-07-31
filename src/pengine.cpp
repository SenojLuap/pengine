// pengine.cpp by Paul R Jones (paujo) on 7.31.2014

#include "pengine.h"
#include "SDL/SDL.h"

#define pengine Pengine::getPengine()

// Return the singleton instance of Pengine
Pengine& Pengine::getPengine() {
  static Pengine instance;
  return instance;
}

// Ctor.
Pengine::Pengine() {
  log = Logger();
  log.setDebugEnabled(true);
  log.setErrorEnabled(true);
  log.setInfoEnabled(true);

  live = false;
}

// Dtor.
Pengine::~Pengine() {
  shutdown();
}

// Initialize the Pengine. NOT performed by the constructor
bool Pengine::startup() {
  if (!live) {
    log.infoMsg("Starting Pengine...");
    live = true;
    return true;
  }
  return false;
}

// Releases the resources the Pengine has allocated
bool Pengine::shutdown() {
  if (live) {
    log.infoMsg("Stopping Pengine...");
    live = false;
    return true;
  }
  return false;
}

// Start the Pengine
void startPengine() {
  pengine.startup();
}

// Stop the Pengine
void stopPengine() {
  pengine.shutdown();
}
