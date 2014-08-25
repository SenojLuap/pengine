// Image.h by Paul R Jones (paujo) on 7.31.2014

#ifndef PAUJO_IMAGE_H
#define PAUJO_IMAGE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "Point.h"
#include "Placement.h"
#include "Pengine.h"

#ifdef __cplusplus
extern "C" {
#endif
  class Pengine;

  class Image {
  private:
    std::string url;
    SDL_Texture *texture;
  public:
    Image(Pengine *, std::string);
    ~Image();
    const std::string &getUrl();

    Point size();

    bool valid();
    void render(Pengine &, Placement);
  };


#ifdef __cplusplus
}
#endif

#endif
