// pengine.h by Paul R Jones (paujo) on 7.31.2014

#ifndef PAUJO_PENGINE_H
#define PAUJO_PENGINE_H

#include "SDL/SDL.h"
#include "logger.h"

#ifdef __cplusplus
extern "C" {
#endif

  class Pengine {
  public:
    static Pengine& getPengine();
    bool startup();
    bool shutdown();
    bool initScreen(int w, int h, std::string title);
  private:
    Pengine();
    Pengine(Pengine const&);
    ~Pengine();
    void operator=(Pengine const&);

    Logger log;
    bool live;
    SDL_Surface *screen;
  };

  void startPengine();
  void stopPengine();
  bool initScreen(int, int, std::string);
  bool initScreen2(int, int);

#ifdef __cplusplus
}
#endif

#endif
