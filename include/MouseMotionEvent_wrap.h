// MouseMotionEvent_wrap.h by Paul R Jones (paujo) on 9.4.2014

#ifndef PAUJO_MOUSEMOTIONEVENT_WRAP_H
#define PAUJO_MOUSEMOTIONEVENT_WRAP_H

#include <boost/python.hpp>
#include "MouseMotionEvent.h"

#ifdef __cplusplus
extern "C" {
#endif

  using namespace boost::python;

  void init_MouseMotionEvent() {
    class_<MouseMotionEvent, bases<Event>>("MouseMotionEvent", init<Uint32>())
      .add_property("pos", make_getter(&MouseMotionEvent::pos), make_setter(&MouseMotionEvent::pos))
      .def("toString", &MouseMotionEvent::toString)
      ;
  }

#ifdef __cplusplus
}
#endif

#endif
