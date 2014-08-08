// pengine_image_Image.cpp by Paul R Jones (paujo) on 7.31.2014

#include "pengine_Pengine.h"
#include "pengine_image_Image.h"
#include "pengine_image_functions.h"
#include "pengine_util_Rect.h"

#define pengine Pengine::getPengine()

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


// Get the size of the image
Point Image::size() {
  Point res;
  if (valid()) {
    SDL_QueryTexture(texture, NULL, NULL, &res.x, &res.y);
  }
  return res;
}


/*************************************************
 * Misc.
 *************************************************/


// Is the image a valid image
bool Image::valid() {
  return (texture != NULL);
}


/*************************************************
 * Rendering
 *************************************************/


// Render the image
void Image::render(Placement pl) {
  pengine.log.debugMsg("Start render()");
  Rect srcRect;
  srcRect.x = pl.position.x;
  srcRect.y = pl.position.y;
  srcRect.w = size().x;
  srcRect.h = size().y;
  Rect destRect = srcRect;
  destRect.w = (int) ((destRect.w * pl.scale) + .5);
  destRect.h = (int) ((destRect.h * pl.scale) + .5);
  SDL_RendererFlip flip = SDL_FLIP_NONE;
  //if (pl.flipVertical) flip = (SDL_RendererFlip)(flip | SDL_FLIP_VERTICAL);
  //if (pl.flipHorizontal) flip = (SDL_RendererFlip)(flip | SDL_FLIP_HORIZONTAL);
  pengine.log.debugMsg("Before render");
  SDL_RenderCopyEx(Pengine::getPengine().renderer, texture, &srcRect, &destRect, pl.rotation, &pl.rotationOrigin, flip);
  pengine.log.debugMsg("After render");
}
