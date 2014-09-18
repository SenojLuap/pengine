// Pengine.h by Paul R Jones (paujo) on 7.31.2014

#ifndef PAUJO_PENGINE_H
#define PAUJO_PENGINE_H

#include <SDL2/SDL.h>
#include <vector>
#include "Logger.h"
#include "ImageRegistry.h"
#include "Color.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "RenderNode.h"

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

    RenderNode *renderTree;
    
    Pengine();
    ~Pengine();
    
    void operator=(Pengine const&);

    void addRenderJob0(int image, Placement placement, int layer = 10);
    void addRenderJob1(int image, int posX=0, int posY=0, double scale=1.0, double rotation=0.0, int rotationOriginX=0,
		       int rotationOriginY=0, bool flipHorizontal=false, bool flipVertical=false, int layer=10);

  private:
    void startup();
    void shutdown();
  };

#ifdef __cplusplus
}
#endif

#endif
