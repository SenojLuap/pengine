// MouseWheelEvent.h by Paul R Jones (paujo) on 9.4.2014

#ifndef PAUJO_MOUSEWHEELEVENT_H
#define PAUJO_MOUSEWHEELEVENT_H

#include <sstream>
#include "Event.h"
#include "Point.h"

#ifdef __cplusplus
extern "C" {
#endif

  struct MouseWheelEvent : public Event {
    Point scroll;
    
    virtual std::string toString();

    MouseWheelEvent(Uint32);
  };

#ifdef __cplusplus
}
#endif

#endif
