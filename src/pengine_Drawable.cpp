// pengine_Drawable.cpp by Paul R Jones (paujo) on 8.5.2014

#include "pengine_Drawable.h"

// Ctor.
Drawable::Drawable() {
  x = 0;
  y = 0;
  scale = 1.0;
  rotation = 0;
}

 
// Invalidate the drawable. Invalid Drawable's will recieve a getImage() call on next refresh, and then be marked valid
void Drawable::invalidate() {
  valid = false;
  //if (layer != NULL) layer->invalidate();
}
