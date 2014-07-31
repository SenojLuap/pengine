// pengine.cpp by Paul R Jones (paujo) on 7.31.2014

#include <sstream>
#include "pengine.h"
#include "SDL/SDL.h"

#define pengine Pengine::getPengine()

/*************************************************
 * 
 *************************************************/


/*************************************************
 * Constructors, Destructors, and instance control
 *************************************************/
  
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
  screen = NULL;
}

// Dtor.
Pengine::~Pengine() {
  shutdown();
}


/*************************************************
 * SDL
 *************************************************/


// Initialize the Pengine. NOT performed by the constructor
bool Pengine::startup() {
  if (!live) {
    log.infoMsg("Starting Pengine...");
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
      log.errorMsg("Failed to init SDL");
      return false;
    }
    live = true;
    return true;
  }
  return false;
}

// Releases the resources the Pengine has allocated
bool Pengine::shutdown() {
  if (live) {
    log.infoMsg("Stopping Pengine...");
    SDL_Quit();
    live = false;
    screen = NULL;
    return true;
  }
  return false;
}

// Create and initialize the screen
bool Pengine::initScreen(int w, int h, std::string title) {
  std::stringstream buf;
  buf << "Initializing screen to [" << w << " x " << h << "]";
  log.infoMsg(buf.str());

  screen = SDL_SetVideoMode(w, h, 32, SDL_SWSURFACE);
  if (screen == NULL) {
    log.errorMsg("Failed to initialize screen");
    return false;
  }
  SDL_WM_SetCaption(title.c_str(), NULL);
  return true;
}


/*************************************************
 * Interface functions
 *************************************************/


// Start the Pengine
void startPengine() {
  pengine.startup();
}

// Stop the Pengine
void stopPengine() {
  pengine.shutdown();
}

// Init the screen
bool initScreen(int w, int h, std::string title) {
  pengine.initScreen(w, h, title);
}

// Init the screen
bool initScreen2(int w, int h) {
  return initScreen(w, h, "Pengine");
}
