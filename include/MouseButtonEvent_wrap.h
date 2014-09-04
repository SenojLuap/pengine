// MouseButtonEvent_wrap.h by Paul R Jones (paujo) on 9.4.2014

#ifndef PAUJO_MOUSEBUTTONEVENT_WRAP_H
#define PAUJO_MOUSEBUTTONEVENT_WRAP_H

#include <boost/python.hpp>
#include "MouseButtonEvent.h"

#ifdef __cplusplus
extern "C" {
#endif

  using namespace boost::python;

  void init_MouseButtonEvent() {
    class_<MouseButtonEvent, bases<Event>>("MouseButtonEvent", init<Uint32>())
      .add_property("button", make_getter(&MouseButtonEvent::button), make_setter(&MouseButtonEvent::button))
      .add_property("pressed", make_getter(&MouseButtonEvent::pressed), make_setter(&MouseButtonEvent::pressed))
      .def("toString", &MouseButtonEvent::toString)
      ;
  }

#ifdef __cplusplus
}
#endif

#endif
