// functions.cpp by Paul R Jones (paujo) on 8.1.2014

#include "functions.h"
#include "Pengine.h"
#include <SDL2/SDL_image.h>
#include <sstream>

#define pengine Pengine::getPengine()

SDL_Texture *loadTexture(std::string fileUrl) {
  SDL_Texture *res = NULL;

  SDL_Surface *loadedSurface = IMG_Load(fileUrl.c_str());
  if (loadedSurface == NULL) {
    std::stringstream buf;
    buf << "Failed to load image: '" << fileUrl << "': " << SDL_GetError();
    
    pengine.log.errorMsg(buf.str());
    return NULL;
  }
  res = SDL_CreateTextureFromSurface(pengine.renderer, loadedSurface);
  if (res == NULL) {
    std::stringstream buf;
    buf << "Failed to create texture for: '" << fileUrl << "': " << SDL_GetError();
    pengine.log.errorMsg(buf.str());
  }
  SDL_FreeSurface(loadedSurface);
  return res;
}
