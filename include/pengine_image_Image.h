// pengine_image_Image.h by Paul R Jones (paujo) on 7.31.2014

#ifndef PAUJO_PENGINE_IMAGE_IMAGE_H
#define PAUJO_PENGINE_IMAGE_IMAGE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

#ifdef __cplusplus
extern "C" {
#endif

  class Image {
  private:
    std::string url;
    SDL_Texture *texture;
  public:
    Image(std::string);
    ~Image();
    const std::string &getUrl();

    bool valid();
  };


#ifdef __cplusplus
}
#endif

#endif
