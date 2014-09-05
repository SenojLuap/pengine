// EventListener.h by Paul R Jones on 9.5.2014

#ifndef PAUJO_EVENTLISTENER_H
#define PAUJO_EVENTLISTENER_H

#include "Event.h"

#ifdef __cplusplus
extern "C" {
#endif

  class EventListener {
  public:
    virtual void handleEvent(Event *) = 0;
  };

#ifdef __cplusplus
}
#endif

#endif
