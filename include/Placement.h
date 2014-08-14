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

    Placement();
  };


#ifdef __cplusplus
}
#endif

#endif
