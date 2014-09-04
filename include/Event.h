// Event.h by Paul R Jones (paujo) on 9.4.2014

#ifndef PAUJO_EVENT_H
#define PAUJO_EVENT_H

#include <SDL2/SDL.h>
#include <string>

#ifdef __cplusplus
extern "C" {
#endif

  struct Event {
    Uint32 time;
    
    virtual std::string toString();

    Event(Uint32);
  };

#ifdef __cplusplus
}
#endif

#endif
