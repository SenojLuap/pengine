// pengine_image_ImageRegistry.h by Paul R Jones (paujo) on 8.4.2014

#ifndef PAUJO_PENGINE_IMAGE_IMAGEREGISTRY_H
#define PAUJO_PENGINE_IMAGE_IMAGEREGISTRY_H

#include <unordered_map>
#include <string>
#include "pengine_image_Image.h"

#ifdef __cplusplus
extern "C" {
#endif

  class ImageRegistry {
  public:
    ImageRegistry();
    ~ImageRegistry();

    std::unordered_map <std::string, Image*> map;
    
    Image *get(std::string key);
    void put(std::string, Image*);
    bool contains(std::string key);

    void dump();
    
    void registerImage1(std::string url, std::string fileUrl, bool overrideIfExisting);
    void registerImage0(std::string url, std::string fileUrl);
  };

#ifdef __cplusplus
}
#endif

#endif
