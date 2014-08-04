// pengine_image_ImageRegistry.cpp by Paul R Jones (paujo) on 8.4.2014

#include "pengine_image_ImageRegistry.h"

// Ctor.
ImageRegistry::ImageRegistry() {
  // Nothing to do?
}


// Dtor.
ImageRegistry::~ImageRegistry() {
  for ( auto it = map.begin(); it != map.end(); ++it) {
    Image *img = it->second;
    if (img->valid()) delete img;
  }
  map.clear();
}


// Get an element from the map.
Image *ImageRegistry::get(std::string key) {
  return map[key];
}


// Put a new element in the list.
void ImageRegistry::put(std::string key, Image *value) {
  map[key] = value;
}


// Does the map contain the key?
bool ImageRegistry::contains(std::string key) {
  return (map[key] != NULL);
}


// Register a new image in the registry.
void ImageRegistry::registerImage1(std::string url, std::string key, bool overrideIfExisting) {
  if (contains(key)) {
    if (!overrideIfExisting) return;
    delete map[key];
  }
  map[key] = new Image(url);
}


// Register a new image in the registry.
void ImageRegistry::registerImage0(std::string url, std::string key) {
  registerImage1(url, key, false);
}
