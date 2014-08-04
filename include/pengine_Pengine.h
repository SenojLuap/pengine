// pengine_Pengine.h by Paul R Jones (paujo) on 7.31.2014

#ifndef PAUJO_PENGINE_H
#define PAUJO_PENGINE_H

#include <SDL2/SDL.h>
#include "pengine_Logger.h"
#include "pengine_image_ImageRegistry.h"

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

#ifdef __cplusplus
}
#endif

#endif
