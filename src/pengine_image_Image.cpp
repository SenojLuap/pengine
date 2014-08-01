// pengine_image_Image.cpp by Paul R Jones (paujo) on 7.31.2014

//#include "SDL/SDL.h"
//#include "SDL/SDL_image.h"
#include "pengine_image_Image.h"
#include "pengine_image_functions.h"

/*************************************************
 * Constructors and Destructors
 *************************************************/

// Ctor
Image::Image(std::string imageUrl) {
  url = imageUrl;
  texture = loadTexture(imageUrl);
}

// Dtor
Image::~Image() {
  if (texture != NULL) {
    SDL_DestroyTexture(texture);
    texture = NULL;
  }
}

/*************************************************
 * Getters/Setters
 *************************************************/

// Get the url the image was initialized to
const std::string &Image::getUrl() {
  return url;
}


/*************************************************
 * Misc.
 *************************************************/

// Is the image a valid image
bool Image::valid() {
  return (texture != NULL);
}
