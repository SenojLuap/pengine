// pengine_util_Placement.h by Paul R Jones (paujo) on 8.7.2014

#ifndef PAUJO_PENGINE_UTIL_PLACEMENT_H
#define PAUJO_PENGINE_UTIL_PLACEMENT_H

#include "pengine_util_Point.h"

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
