// Image.cpp by Paul R Jones (paujo) on 7.31.2014

#include "Pengine.h"
#include "Image.h"
#include "functions.h"
#include "Rect.h"

/*************************************************
 * Constructors and Destructors
 *************************************************/


// Ctor
Image::Image(Pengine *pengine, std::string imageUrl) {
  url = imageUrl;
  texture = loadTexture(pengine, imageUrl);
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
void Image::render(Pengine &pengine, Placement pl) {
  pengine.log->debugMsg("Start render()");
  Rect srcRect;
  //srcRect.x = pl.position.x;
  //srcRect.y = pl.position.y;

  srcRect.w = size().x;
  srcRect.h = size().y;
  Rect destRect = srcRect;
  destRect.x = pl.position.x;
  destRect.y = pl.position.y;
  destRect.w = (int) ((destRect.w * pl.scale) + .5);
  destRect.h = (int) ((destRect.h * pl.scale) + .5);
  SDL_RendererFlip flip = SDL_FLIP_NONE;
  //if (pl.flipVertical) flip = (SDL_RendererFlip)(flip | SDL_FLIP_VERTICAL);
  //if (pl.flipHorizontal) flip = (SDL_RendererFlip)(flip | SDL_FLIP_HORIZONTAL);
  pengine.log->debugMsg("Before render");
  SDL_RenderCopyEx(pengine.renderer, texture, &srcRect, &destRect, pl.rotation, &pl.rotationOrigin, flip);
  pengine.log->debugMsg("After render");
}
