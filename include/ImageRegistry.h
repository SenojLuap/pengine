// ImageRegistry.h by Paul R Jones (paujo) on 8.4.2014

#ifndef PAUJO_IMAGEREGISTRY_H
#define PAUJO_IMAGEREGISTRY_H

#include <unordered_map>
#include <string>
#include "Image.h"

#define NULL_IMAGE (unsigned)0

#ifdef __cplusplus
extern "C" {
#endif

  class ImageRegistry {
  public:
    ImageRegistry();
    ~ImageRegistry();

    std::unordered_map <unsigned, Image*> map;
    std::unordered_map <std::string, unsigned> loaded;
    
    Image *get(unsigned);
    void put(unsigned, Image*);
    bool contains(unsigned);
    bool containsFile(std::string);
    unsigned firstAvailable();

    void dump();
    
    unsigned registerImage1(std::string fileUrl, bool overrideIfExisting);
    unsigned registerImage0(std::string fileUrl);
  };

#ifdef __cplusplus
}
#endif

#endif
