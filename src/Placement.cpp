// Placement.cpp by Paul R Jones (paujo) on 8.7.2014

#include "Placement.h"

// Ctor.
Placement::Placement(int posX, int posY, double scale, double rotation, int rotationOriginX, int rotationOriginY,
		     bool flipHorizontal, bool flipVertical) {
  position.x = posX;
  position.y = posY;

  this->scale = scale;

  this->rotation = rotation;
  rotationOrigin.x = rotationOriginX;
  rotationOrigin.y = rotationOriginY;

  this->flipHorizontal = flipHorizontal;
  this->flipVertical = flipVertical;
}
