// pengine_Pengine.cpp by Paul R Jones (paujo) on 7.31.2014

#include <sstream>
#include "pengine_Pengine.h"
//#include "SDL/SDL.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define pengine Pengine::getPengine()


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
  window = NULL;
  renderer = NULL;
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
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
      log.errorMsg("Failed to init SDL_image");
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
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    live = false;
    window = NULL;
    screen = NULL;
    renderer = NULL;
    return true;
  }
  return false;
}

// Create and initialize the screen
bool Pengine::initScreen(int w, int h, std::string title) {
  std::stringstream buf;
  buf << "Initializing screen to [" << w << " x " << h << "]";
  log.infoMsg(buf.str());

  window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			    w, h, SDL_WINDOW_SHOWN);
  if (window == NULL) {
    log.errorMsg("Failed to create a window");
    return false;
  }
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (renderer == NULL) {
    log.errorMsg("Failed to create a renderer");
    return false;
  }
  //SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

  screen = SDL_GetWindowSurface(window);
  if (screen == NULL) {
    log.errorMsg("Failed to get screen from window");
    return false;
  }
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
