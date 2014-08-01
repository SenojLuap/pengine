// pengine_image_functions.h by Paul R Jones (paujo) on 8.1.2014

#ifndef PAUJO_PENGINE_IMAGE_FUNCTIONS_H
#define PAUJO_PENGINE_IMAGE_FUNCTIONS_H

#include <string>
//#include "SDL/SDL.h"
#include <SDL2/SDL.h>

#ifdef __cplusplus
extern "C" {
#endif

  SDL_Texture *loadTexture(std::string);

#ifdef __cplusplus
}
#endif

#endif
