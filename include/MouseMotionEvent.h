// MouseMotionEvent.h by Paul R Jones (paujo) on 9.4.2014

#ifndef PAUJO_MOUSEMOTIONEVENT_H
#define PAUJO_MOUSEMOTIONEVENT_H

#include "Event.h"
#include "Point.h"

#ifdef __cplusplus
extern "C" {
#endif

  struct MouseMotionEvent : public Event {
    Point pos;

    virtual std::string toString();

    MouseMotionEvent(Uint32);
  };

#ifdef __cplusplus
}
#endif

#endif
