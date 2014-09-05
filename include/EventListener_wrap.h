// EventListener_wrap.h by Paul R Jones on 9.5.2014

#ifndef PAUJO_EVENTLISTENER_WRAP_H
#define PAUJO_EVENTLISTENER_WRAP_H

#include <boost/python.hpp>
#include "EventListener.h"

#ifdef __cplusplus
extern "C" {
#endif

  using namespace boost::python;

  class EventListenerWrap : public EventListener, public wrapper<EventListener> {
    virtual void handleEvent(Event *ev) {
      this->get_override("handleEvent")(ev);
    }
  };

  void init_EventListener() {
    class_<EventListenerWrap, boost::noncopyable>("EventListener")
      .def("handleEvent", pure_virtual(&EventListener::handleEvent))
      ;
  }

#ifdef __cplusplus
}
#endif

#endif
