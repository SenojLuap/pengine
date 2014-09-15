// Pengine.h by Paul R Jones (paujo) on 7.31.2014

#ifndef PAUJO_PENGINE_H
#define PAUJO_PENGINE_H

#include <SDL2/SDL.h>
#include <vector>
//#include "Layer.h"
#include "Logger.h"
#include "ImageRegistry.h"
#include "Color.h"
#include "Mouse.h"
#include "Keyboard.h"

#ifdef __cplusplus
extern "C" {
#endif

  class Mouse;
  class Keyboard;

  class Pengine {
  public:
    void initScreen0(int w, int h);
    void initScreen1(int w, int h, std::string title);
    void render();
    Uint32 processEvents();
    
    Uint32 lastTick;
    Logger *log;
    bool live;
    SDL_Surface *screen;
    SDL_Window *window;
    SDL_Renderer *renderer;
    
    ImageRegistry *imageRegistry;
    Mouse *mouse;
    Keyboard *keyboard;
    
    Pengine();
    ~Pengine();
    
    void operator=(Pengine const&);

  private:
    void startup();
    void shutdown();
  };

#ifdef __cplusplus
}
#endif

#endif
