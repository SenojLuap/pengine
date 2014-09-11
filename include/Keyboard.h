// Keyboard.h by Paul R Jones (paujo) on 9.11.2014

#ifndef PAUJO_KEYBOARD_H
#define PAUJO_KEYBOARD_H

#include <SDL2/SDL.h>
#include "Pengine.h"
#include "KeyboardScanCode.h"

#ifdef __cplusplus
extern "C" {
#endif

  class Keyboard {
  public:

    Pengine *pengine;

    const Uint8 *keyState;
    int keyStateSize;
    
    Keyboard(Pengine*);
    ~Keyboard();

    void preProcess(Uint32);
    void postProcess();

    void processKeyboardEvent(SDL_KeyboardEvent);

    bool isKeyDown(KeyboardScanCode);
  };

#ifdef __cplusplus
}
#endif

#endif
