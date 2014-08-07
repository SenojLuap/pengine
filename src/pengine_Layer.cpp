// pengine_Layer.cpp by Paul R Jones (paujo) on 8.6.2014

#include "pengine_Layer.h"

#include "pengine_Pengine.h"
#include "pengine_util_functions.h"

#define pengine Pengine::getPengine()

// Ctor.
Layer::Layer() {
  w = pengine.screen->w;
  h = pengine.screen->h;
  focusX = (int)(ceil((double)w / 2.0));
  focusY = (int)(ceil((double)h / 2.0));
  wrapHorizontal = wrapVertical = false;
  restrictFocus = true;
  clearColor = Color(0, 0, 0, 0xFF);
  valid = false;
  texture = SDL_CreateTexture(pengine.renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, pengine.screen->w,
			      pengine.screen->h);
}


//Dtor.
Layer::~Layer() {
  SDL_DestroyTexture(texture);
  texture = NULL;
}


// Set the camera focus
void Layer::focus(int x, int y) {
  if (restrictFocus) {
    int xMargin = (int)ceil((double)(pengine.screen->w) / 2.0);
    int yMargin = (int)ceil((double)(pengine.screen->h) / 2.0);
    x = MIN(MAX(x, xMargin), w - xMargin);
    y = MIN(MAX(y, yMargin), h - yMargin);
  }
  focusX = x;
  focusY = y;
}


// Set the size of the layer
void Layer::setSize(int w, int h) {
  if (texture != NULL) {
    SDL_DestroyTexture(texture);
    texture = NULL;
  }
  texture = SDL_CreateTexture(pengine.renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, w, h);
}

// Invalidate the layer
void Layer::invalidate() {
  valid = false;
}


// Invalidate the layer and its drawables
void Layer::invalidateAll() {
  invalidate();
  for (int i = 0; i < entities.size(); i++) {
    entities[i]->invalidate();
  }
}


// Register a Drawable with the layer
void Layer::registerDrawable(Drawable *draw) {
  entities.push_back(draw);
  draw->layer = this;
}
