// functions.h by Paul R Jones (paujo) on 8.1.2014

#ifndef PAUJO_FUNCTIONS_H
#define PAUJO_FUNCTIONS_H

#include <string>
#include <SDL2/SDL.h>

#define MIN(a, b) (a > b ? b : a)
#define MAX(a, b) (a > b ? a : b)

#ifdef __cplusplus
extern "C" {
#endif

  SDL_Texture *loadTexture(std::string);

#ifdef __cplusplus
}
#endif

#endif
