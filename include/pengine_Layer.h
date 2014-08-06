// pengine_layer.h by Paul R Jones (paujo) 8.6.2014

#ifndef PAUJO_PENGINE_LAYER_H
#define PAUJO_PENGINE_LAYER_H

#include <vector>
#include <SDL2/SDL.h>
#include "pengine_Drawable.h"

#ifdef __cplusplus
extern "C" {
#endif

  class Layer {
  public:
    // Python visible.
    int w;
    int h;
    int focusX;
    int focusY;
    bool wrapHorizontal;
    bool wrapVertical;

    void focus(int x, int y);
    void invalidate();
    void invalidateAll();

    // Python hidden.
    std::vector<Drawable*> entities;
    SDL_Texture *texture;
  };

#ifdef __cplusplus
}
#endif

#endif
