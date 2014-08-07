// pengine_layer.h by Paul R Jones (paujo) 8.6.2014

#ifndef PAUJO_PENGINE_LAYER_H
#define PAUJO_PENGINE_LAYER_H

#include <vector>
#include <SDL2/SDL.h>
#include "pengine_Drawable.h"
#include "pengine_util_Color.h"

#ifdef __cplusplus
extern "C" {
#endif

  class Layer {
  public:
    int w;
    int h;
    int focusX;
    int focusY;
    bool wrapHorizontal;
    bool wrapVertical;
    bool restrictFocus;

    Color clearColor;

    bool valid;

    void focus(int x, int y);
    void setSize(int w, int h);
    void invalidate();
    void invalidateAll();

    std::vector<Drawable*> entities;
    SDL_Texture *texture;

    Layer();
    ~Layer();
  };

#ifdef __cplusplus
}
#endif

#endif
