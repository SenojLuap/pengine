// Drawable.h by Paul R Jones (paujo) on 8.5.2014

#ifndef PAUJO_DRAWABLE_H
#define PAUJO_DRAWABLE_H

#include "Image.h"
#include "Layer.h"
#include "Placement.h"

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
