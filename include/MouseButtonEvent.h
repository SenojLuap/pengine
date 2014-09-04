// MouseButtonEvent.h by Paul R Jones (paujo) on 9.4.2014

#ifndef PAUJO_MOUSEBUTTONEVENT_H
#define PAUJO_MOUSEBUTTONEVENT_H

#include "Event.h"

#ifdef __cplusplus
extern "C" {
#endif

  struct MouseButtonEvent : public Event {
    Uint32 button;
    bool pressed;

    virtual std::string toString();
    
    MouseButtonEvent(Uint32);
    MouseButtonEvent(Uint32, SDL_MouseButtonEvent);
  };

#ifdef __cplusplus
}
#endif

#endif
