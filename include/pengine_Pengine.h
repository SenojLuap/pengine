// pengine_Pengine.h by Paul R Jones (paujo) on 7.31.2014

#ifndef PAUJO_PENGINE_H
#define PAUJO_PENGINE_H

#include <SDL2/SDL.h>
#include <vector>
#include "pengine_Layer.h"
#include "pengine_Logger.h"
#include "pengine_image_ImageRegistry.h"
#include "pengine_util_Color.h"

#ifdef __cplusplus
extern "C" {
#endif

  class Pengine {
  public:
    static Pengine& getPengine();
    bool startup();
    bool shutdown();
    bool initScreen(int w, int h, std::string title);

    Logger log;
    bool live;
    SDL_Surface *screen;
    SDL_Window *window;
    SDL_Renderer *renderer;

    ImageRegistry imageRegistry;

    std::vector<Layer *> layers;

  private:
    Pengine();
    Pengine(Pengine const&);
    ~Pengine();
    void operator=(Pengine const&);
  };

  void startPengine();
  void stopPengine();
  bool initScreen(int, int, std::string);
  bool initScreen2(int, int);
  ImageRegistry const& getImageRegistry();


  /*********************************************
   * Layers
   *********************************************/

  void initLayers(int layerCount);
  void setLayerSize(int layer, int w, int h);
  void setLayerWrap(int layer, bool wrapHoriz, bool wrapVert);
  void invalidateLayer(int layer, bool heavy);
  void invalidateAllLayers(bool heavy);
  void setLayerRestrictFocus(int layer, bool restrictFocus);
  void setLayerClearColor(int layer, Color col);
  void setLayerFocus(int layer, int x, int y);

#ifdef __cplusplus
}
#endif

#endif
