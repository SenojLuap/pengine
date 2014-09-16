// Keyboard.h by Paul R Jones (paujo) on 9.11.2014

#ifndef PAUJO_KEYBOARD_H
#define PAUJO_KEYBOARD_H

#include <SDL2/SDL.h>
#include <boost/python.hpp>
#include <vector>
#include "Pengine.h"
#include "KeyboardScanCode.h"
#include "KeyboardKeyEvent.h"

#ifdef __cplusplus
extern "C" {
#endif

  class Keyboard {
  public:

    Pengine *pengine;

    const Uint8 *keyState;
    int keyStateSize;

    std::vector<KeyboardKeyEvent*> *pendingEvents;
    std::vector<boost::python::object> *listeners;
    
    Keyboard(Pengine*);
    ~Keyboard();

    void registerListener(boost::python::object);
    void deregisterListener(boost::python::object);

    void preProcess(Uint32);
    void postProcess();

    void processKeyboardEvent(SDL_KeyboardEvent);

    bool isKeyDown(KeyboardScanCode);
  };

#ifdef __cplusplus
}
#endif

#endif
