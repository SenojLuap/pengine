// ImageRegistry.cpp by Paul R Jones (paujo) on 8.4.2014

#include <sstream>
#include <iostream>
#include <limits>
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
Image *ImageRegistry::get(unsigned index) {
  if (contains(index))
    return map[index];
  return NULL;
}


// Put a new element in the list.
void ImageRegistry::put(unsigned index, Image *value) {
  map[index] = value;
}


// Does the map contain the key?
bool ImageRegistry::contains(unsigned index) {
  return (map.count(index) == 1);
}


// Does the map contain the key?
bool ImageRegistry::containsFile(std::string fileUrl) {
  return (loaded.count(fileUrl) == 1);
}


// Return the first available handle. 0 is reserved to represent NULL, or no-image
unsigned ImageRegistry::firstAvailable() {
  unsigned max = std::numeric_limits<unsigned>::max();
  for (unsigned i = 1; i < max; i++)
    if (!contains(i))
      return i;
  return max;
}


// Register a new image in the registry.
unsigned ImageRegistry::registerImage1(std::string fileUrl, bool overrideIfExisting) {
  unsigned newIndex;
  if (containsFile(fileUrl)) {
    newIndex = loaded[fileUrl];
    if (!overrideIfExisting) return newIndex;
    delete map[newIndex];
  } else {
    newIndex = firstAvailable();
    loaded[fileUrl] = newIndex;
  }
  map[newIndex] = new Image(fileUrl);
  return newIndex;
}


// Register a new image in the registry.
unsigned ImageRegistry::registerImage0(std::string fileUrl) {
  return registerImage1(fileUrl, false);
}


// Dump the contents of the map
void ImageRegistry::dump() {
  Pengine::getPengine().log.debugMsg(" -- dump():");
  std::stringstream s;
  s << "this: " << this << " size: " << map.size();
  Pengine::getPengine().log.debugMsg(s.str());
  s.str("");

  for (auto& x: map) {
    std::stringstream ss;
    ss << "key: " << x.first << " value: " << x.second;
    Pengine::getPengine().log.debugMsg(ss.str());
  }

  for (auto& x: loaded) {
    s << "url: " << x.first << " key: " << x.second;
    Pengine::getPengine().log.debugMsg(s.str());
    s.str("");
  }
}
