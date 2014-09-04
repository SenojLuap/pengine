// MouseWheelEvent_wrap.h by Paul R Jones (paujo) on 9.4.2014

#ifndef PAUJO_MOUSEWHEELEVENT_WRAP_H
#define PAUJO_MOUSEWHEELEVENT_WRAP_H

#include <boost/python.hpp>
#include "MouseWheelEvent.h"

#ifdef __cplusplus
extern "C" {
#endif

  using namespace boost::python;

  void init_MouseWheelEvent() {
    class_<MouseWheelEvent, bases<Event>>("MouseWheelEvent", init<Uint32>())
      .add_property("scroll", make_getter(&MouseWheelEvent::scroll), make_setter(&MouseWheelEvent::scroll))
      .def("toString", &MouseWheelEvent::toString)
      ;
  }

#ifdef __cplusplus
}
#endif  

#endif
