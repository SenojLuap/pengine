// pengine_Pengine.cpp by Paul R Jones (paujo) on 7.31.2014

#include <sstream>
#include "pengine_Pengine.h"
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
  if (!live) {
    log.errorMsg("Pengine not running!");
    return false;
  }
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
  SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);

  screen = SDL_GetWindowSurface(window);
  if (screen == NULL) {
    log.errorMsg("Failed to get screen from window");
    return false;
  }
  for (int i = 0; i < layers.size(); i++)
    delete layers[i];
  layers.clear();
  layers.push_back(new Layer());
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

// Get the image registry for the engine.
ImageRegistry *getImageRegistry() {
  return &pengine.imageRegistry;
}


/*********************************************
 * Layers
 *********************************************/


// Initialize a set of layers
void initLayers(int layerCount) {
  if (pengine.screen == NULL) {
    pengine.log.errorMsg("Attempted to initialize layers before initializing screen");
    return;
  }
  for (int i = 0; i < pengine.layers.size(); i++)
    delete pengine.layers[i];
  pengine.layers.clear();
  for (int i = 0; i < layerCount; i++) {
    Layer *newLayer = new Layer();
    pengine.layers.push_back(newLayer);
  }
}


// Set the size of a specific layer
void setLayerSize(int layer, int w, int h) {
  if (layer >= pengine.layers.size()) {
    pengine.log.errorMsg("Attempted to access out-of-bounds layer");
    return;
  }
  pengine.layers[layer]->setSize(w, h);
}


// Enable/disable layer wrapping
void setLayerWrap(int layer, bool wrapHoriz, bool wrapVert) {
  if (layer >= pengine.layers.size()) {
    pengine.log.errorMsg("Attempted to access out-of-bounds layer");
    return;
  }
  pengine.layers[layer]->wrapHorizontal = wrapHoriz;
  pengine.layers[layer]->wrapVertical = wrapVert;
}


// Invalidate a layer
void invalidateLayer(int layer, bool heavy) {
  if (layer >= pengine.layers.size()) {
    pengine.log.errorMsg("Attempted to access out-of-bounds layer");
    return;
  }
  if (heavy) pengine.layers[layer]->invalidateAll();
  else pengine.layers[layer]->invalidate();
}


// Invalidate all layers
void invalidateAllLayers(bool heavy) {
  for (int i = 0; i < pengine.layers.size(); i++)
    invalidateLayer(i, heavy);
}


// Enable/disable resctricting the camera focus of a layer
void setLayerRestrictFocus(int layer, bool restrictFocus) {
  if (layer >= pengine.layers.size()) {
    pengine.log.errorMsg("Attempted to access out-of-bounds layer");
    return;
  }
  pengine.layers[layer]->restrictFocus = restrictFocus;
}


// Set the color a layer uses to clear
void setLayerClearColor(int layer, Color col) {
  if (layer >= pengine.layers.size()) {
    pengine.log.errorMsg("Attempted to access out-of-bounds layer");
    return;
  }
  pengine.layers[layer]->clearColor = col;
}


// Set the focus point of the layer
void setLayerFocus(int layer, int x, int y) {
  if (layer >= pengine.layers.size()) {
    pengine.log.errorMsg("Attempted to access out-of-bounds layer");
    return;
  }
  pengine.layers[layer]->focus(x, y);
}


// Register a Drawable to the default layer
void registerDrawable0(Drawable *draw) {
  registerDrawable1(draw, 0);
}


// Register a Drawable to a specifiic layer
void registerDrawable1(Drawable *draw, int layer) {
  if (layer >= pengine.layers.size()) {
    pengine.log.errorMsg("Attempted to register a Drawable to an invalid layer");
    return;
  }
  pengine.layers[layer]->registerDrawable(draw);
}


/*********************************************
 * Rendering
 *********************************************/


// Render.
void render() {
  pengine.render();
}


// Render.
void Pengine::render() {
  if (!live) {
    log.errorMsg("Attempted to render without Pengine running");
    return;
  }
  if (screen == NULL) {
    log.errorMsg("Attempted to render without initializing the screen");
    return;
  }
  SDL_SetRenderTarget(renderer, NULL);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);
  
  for (int i = 0; i < layers.size(); i++) {
    layers[i]->render();
  }
}
