// pengine_Drawable.h by Paul R Jones (paujo) on 8.5.2014

#ifndef PAUJO_PENGINE_DRAWABLE_H
#define PAUJO_PENGINE_DRAWABLE_H

#include "pengine_image_Image.h"
#include "pengine_Layer.h"
#include "pengine_util_Placement.h"

#ifdef __cplusplus
extern "C" {
#endif

  class Layer;

  class Drawable {
  public:
    // Python exposed:
    Placement placement;

    Drawable();
    
    virtual Image *getImage() = 0;
    void invalidate();

    // Hidden from Python:
    bool valid;
    Layer *layer; 
    
  };
  
#ifdef __cplusplus
}
#endif


#endif
