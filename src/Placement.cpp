// Placement.cpp by Paul R Jones (paujo) on 8.7.2014

#include "Placement.h"

// Ctor.
Placement::Placement() {
  position.x = 0;
  position.y = 0;

  scale = 1.0;

  rotation = 0.0;
  rotationOrigin.x = 0;
  rotationOrigin.y = 0;

  flipHorizontal = false;
  flipVertical = false;
}
