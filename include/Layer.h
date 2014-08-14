// Layer.h by Paul R Jones (paujo) 8.6.2014

#ifndef PAUJO_LAYER_H
#define PAUJO_LAYER_H

#include <vector>
#include <SDL2/SDL.h>
#include "Drawable.h"
#include "Color.h"

#ifdef __cplusplus
extern "C" {
#endif

  class Drawable;

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
    void render();

    void registerDrawable(Drawable *);

    std::vector<Drawable*> entities;
    SDL_Texture *texture;

    Layer();
    ~Layer();
  };

#ifdef __cplusplus
}
#endif

#endif
