// Pengine.cpp by Paul R Jones (paujo) on 7.31.2014

#include <sstream>
#include "Pengine.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define pengine Pengine::getPengine()


/*************************************************
 * Constructors, Destructors, and instance control
 *************************************************/
  
// Return the singleton instance of Pengine
/*
Pengine& Pengine::getPengine() {
  static Pengine instance;
  return instance;
}
*/

// Ctor.
Pengine::Pengine() {

  log = new Logger();

  log->setDebugEnabled(true);
  log->setErrorEnabled(true);
  log->setInfoEnabled(true);

  imageRegistry = new ImageRegistry(this);

  live = false;
  screen = NULL;
  window = NULL;
  renderer = NULL;
  startup();

  lastTick = SDL_GetTicks();
}

// Dtor.
Pengine::~Pengine() {
  shutdown();
  delete log;
  delete imageRegistry;
}


/*************************************************
 * SDL
 *************************************************/


// Initialize the Pengine. NOT performed by the constructor
void Pengine::startup() {
  if (!live) {
    log->infoMsg("Starting Pengine...");
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
      std::stringstream ss;
      ss << "Failed to init SDL: " << SDL_GetError();
      log->errorMsg(ss.str());
      return;
    }
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
      std::stringstream ss;
      ss << "Failed to init SDL_image: " << SDL_GetError();
      log->errorMsg(ss.str());
      return;
    }
    live = true;
    return;
  }
  return;
}


// Releases the resources the Pengine has allocated
void Pengine::shutdown() {
  if (live) {
    log->infoMsg("Stopping Pengine...");
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    live = false;
    window = NULL;
    screen = NULL;
    renderer = NULL;
    return;
  }
  return;
}


// Create and initialize a screen with a default title
void Pengine::initScreen0(int w, int h) {
  initScreen1(w, h, "Pengine");
}


// Create and initialize the screen
void Pengine::initScreen1(int w, int h, std::string title) {
  if (!live) {
    log->errorMsg("Pengine not running!");
    return;
  }
  if (window != NULL) {
    log->errorMsg("Attempted to initialize multiple screens");
    return;
  }
  std::stringstream buf;
  buf << "Initializing screen to [" << w << " x " << h << "]";
  log->infoMsg(buf.str());

  window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			    w, h, SDL_WINDOW_SHOWN);
  if (window == NULL) {
    std::stringstream ss;
    ss << "Failed to create a window: " << SDL_GetError();
    log->errorMsg(ss.str());
    return;
  }
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (renderer == NULL) {
    std::stringstream ss;
    ss << "Failed to create a renderer: " << SDL_GetError();
    log->errorMsg(ss.str());
    return;
  }
  SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);

  screen = SDL_GetWindowSurface(window);
  if (screen == NULL) {
    log->errorMsg("Failed to get screen from window");
    return;
  }
  return;
}


// Render.
void Pengine::render() {
  if (!live) {
    log->errorMsg("Attempted to render without Pengine running");
    return;
  }
  if (screen == NULL) {
    log->errorMsg("Attempted to render without initializing the screen");
    return;
  }
  SDL_SetRenderTarget(renderer, NULL);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);
}


// Process system events and return the time since the last call to processEvents() or startup()
Uint32 Pengine::processEvents() {
  if (!live) {
    log->errorMsg("Attempted to process events before pengine was live");
    return 0;
  }
  Uint32 delta = SDL_GetTicks() - lastTick;
  lastTick += delta;
  
  SDL_Event event;
  while(SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_MOUSEMOTION:
      log->infoMsg("Mouse moved");
      break;
    default:
      std::stringstream ss;
      ss << "Unhandled event: " << event.type;
      log->debugMsg(ss.str());
      break;
    }
  }
  
  return delta;
}
