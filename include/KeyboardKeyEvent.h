// KeyboardKeyEvent.h by Paul R Jones (paujo) on 9.15.2013

#ifndef PAUJO_KEYBOARDKEYEVENT_H
#define PAUJO_KEYBOARDKEYEVENT_H

#include <SDL2/SDL.h>
#include <string>
#include "KeyboardScanCode.h"
#include "Event.h"

#ifdef __cplusplus
extern "C" {
#endif

  struct KeyboardKeyEvent : public Event {
    bool keyDown;
    bool repeat;
    KeyboardScanCode scanCode;

    virtual std::string toString();

    KeyboardKeyEvent(Uint32);
  };

#ifdef __cplusplus
}
#endif

#endif
