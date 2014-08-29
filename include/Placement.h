// Placement.h by Paul R Jones (paujo) on 8.7.2014

#ifndef PAUJO_PLACEMENT_H
#define PAUJO_PLACEMENT_H

#include "Point.h"

#ifdef __cplusplus
extern "C" {
#endif

  struct Placement {
    Point position;
    double scale;
    double rotation;
    Point rotationOrigin;

    bool flipHorizontal;
    bool flipVertical;

    Placement(int posX = 0, int posY = 0, double scale = 1.0, double rotation = 0.0, int rotationOriginX = 0,
	      int rotationOriginY = 0, bool flipHorizontal = false, bool flipVertical = false);
  };


#ifdef __cplusplus
}
#endif

#endif
