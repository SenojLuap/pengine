// KeyboardKeyEvent_wrap.h by Paul R Jones (paujo) on 9.15.2014

#ifndef PAUJO_KEYBOARDKEYEVENT_WRAP_H
#define PAUJO_KEYBOARDKEYEVENT_WRAP_H

#include <boost/python.hpp>
#include "KeyboardKeyEvent.h"

#ifdef __cplusplus
extern "C" {
#endif

  using namespace boost::python;

  void init_KeyboardKeyEvent() {
    class_<KeyboardKeyEvent, bases<Event>>("KeyboardKeyEvent", init<Uint32>())
      .add_property("keyDown", make_getter(&KeyboardKeyEvent::keyDown), make_setter(&KeyboardKeyEvent::keyDown))
      .add_property("repeat", make_getter(&KeyboardKeyEvent::repeat), make_setter(&KeyboardKeyEvent::repeat))
      .add_property("scanCode", make_getter(&KeyboardKeyEvent::scanCode), make_setter(&KeyboardKeyEvent::scanCode))
      .def("toString", &KeyboardKeyEvent::toString)
      ;
  }

#ifdef __cplusplus
}
#endif

#endif
