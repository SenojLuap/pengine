// Pengine.h by Paul R Jones (paujo) on 7.31.2014

#ifndef PAUJO_PENGINE_H
#define PAUJO_PENGINE_H

#include <SDL2/SDL.h>
#include <vector>
//#include "Layer.h"
#include "Logger.h"
#include "ImageRegistry.h"
#include "Color.h"

#ifdef __cplusplus
extern "C" {
#endif

  class Pengine {
  public:
    static Pengine& getPengine();
    void startup();
    void shutdown();
    void initScreen(int w, int h, std::string title);
    void render();

    Logger log;
    bool live;
    SDL_Surface *screen;
    SDL_Window *window;
    SDL_Renderer *renderer;

    ImageRegistry imageRegistry;

    //std::vector<Layer *> layers;

  private:
    Pengine();
    Pengine(Pengine const&);
    ~Pengine();
    void operator=(Pengine const&);
  };

  void startPengine();
  void stopPengine();
  void initScreen(int, int, std::string);
  void initScreen2(int, int);
  ImageRegistry *getImageRegistry();


  /*********************************************
   * Layers
   *********************************************/

  /*
  void initLayers(int layerCount);
  void setLayerSize(int layer, int w, int h);
  void setLayerWrap(int layer, bool wrapHoriz, bool wrapVert);
  void invalidateLayer(int layer, bool heavy);
  void invalidateAllLayers(bool heavy);
  void setLayerRestrictFocus(int layer, bool restrictFocus);
  void setLayerClearColor(int layer, Color col);
  void setLayerFocus(int layer, int x, int y);

  void registerDrawable0(Drawable *draw);
  void registerDrawable1(Drawable *draw, int layer);
  */

  /*********************************************
   * Rendering
   *********************************************/

  void render();

#ifdef __cplusplus
}
#endif

#endif
