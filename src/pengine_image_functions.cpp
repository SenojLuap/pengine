// pengine_image_functions.cpp by Paul R Jones (paujo) on 8.1.2014

#include "pengine_image_functions.h"
#include "SDL/SDL_image.h"

SDL_Surface *loadOptimizedImage(std::string fileUrl) {
  SDL_Surface *firstLoad = NULL;
  SDL_Surface *secondLoad = NULL;

  firstLoad = IMG_Load(fileUrl.c_str());

  if (firstLoad != NULL) {
    secondLoad = SDL_DisplayFormat(firstLoad);
    SDL_FreeSurface(firstLoad);
  }

  return secondLoad;
}
