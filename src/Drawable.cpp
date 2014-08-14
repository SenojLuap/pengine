// Drawable.cpp by Paul R Jones (paujo) on 8.5.2014

#include "Drawable.h"

// Ctor.
Drawable::Drawable() {
}

 
// Invalidate the drawable. Invalid Drawable's will recieve a getImage() call on next refresh, and then be marked valid
void Drawable::invalidate() {
  valid = false;
  //if (layer != NULL) layer->invalidate();
}
