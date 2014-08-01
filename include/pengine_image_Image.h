// pengine_image_Image.h by Paul R Jones (paujo) on 7.31.2014

#ifndef PAUJO_PENGINE_IMAGE_IMAGE_H
#define PAUJO_PENGINE_IMAGE_IMAGE_H

#include <string>

#ifdef __cplusplus
extern "C" {
#endif

  class Image {
  private:
    std::string url;
    SDL_Surface *surface;
  public:
    Image(std::string);
    ~Image();
  };


#ifdef __cplusplus
}
#endif

#endif
