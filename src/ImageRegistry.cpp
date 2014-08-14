// ImageRegistry.cpp by Paul R Jones (paujo) on 8.4.2014

#include <sstream>
#include <iostream>
#include "Pengine.h"
#include "ImageRegistry.h"

#define pengine Pengine::getPengine()

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
  if (contains(key))
    return map[key];
  return NULL;
}


// Put a new element in the list.
void ImageRegistry::put(std::string key, Image *value) {
  map[key] = value;
}


// Does the map contain the key?
bool ImageRegistry::contains(std::string key) {
  return map.find(key) != map.end();
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


// Dump the contents of the map
void ImageRegistry::dump() {
  Pengine::getPengine().log.debugMsg(" -- dump():");
  std::stringstream s;
  s << "this: " << this << " size: " << map.size();
  
  Pengine::getPengine().log.debugMsg(s.str());
  for (auto& x: map) {
    std::stringstream ss;
    ss << "key: " << x.first << " value: " << x.second;
    Pengine::getPengine().log.debugMsg(ss.str());
  }
}
