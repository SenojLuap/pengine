// pengine_image_Image.cpp by Paul R Jones (paujo) on 7.31.2014

#include "SDL/SDL.h"
#include "pengine_image_Image.h"

/*************************************************
 * Constructors and Destructors
 *************************************************/

// Ctor
Image::Image(std::string imageUrl) {
  url = imageUrl;
  surface = NULL;
}

// Dtor
Image::~Image() {
  if (surface != NULL) {
    SDL_FreeSurface(surface);
    surface = NULL;
  }
}

/*************************************************
 * Getters/Setters
 *************************************************/

// Get the url the image was initialized to
const std::string &Image::getUrl() {
  return url;
}
