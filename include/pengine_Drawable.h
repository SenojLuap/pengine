// pengine_Drawable.h by Paul R Jones (paujo) on 8.5.2014

#ifndef PAUJO_PENGINE_DRAWABLE_H
#define PAUJO_PENGINE_DRAWABLE_H

#include "pengine_image_Image.h"

#ifdef __cplusplus
extern "C" {
#endif

  class Drawable {
  public:
    // Python exposed:
    int x;
    int y;
    double scale;
    int rotation;

    Drawable();
    
    virtual Image *getImage() = 0;
    void invalidate();

    // Hidden from Python:
    bool valid;
    // Layer *layer; 
    
  };
  
#ifdef __cplusplus
}
#endif


#endif
