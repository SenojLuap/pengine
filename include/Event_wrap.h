// Event_wrap.h by Paul R Jones (paujo) on 9.4.2014

#ifndef PAUJO_EVENT_WRAP_H
#define PAUJO_EVENT_WRAP_H

#include <boost/python.hpp>
#include "Event.h"

#ifdef __cplusplus
extern "C" {
#endif

  using namespace boost::python;

  void init_Event() {
    class_<Event>("Event", init<Uint32>())
      .add_property("time", make_getter(&Event::time), make_setter(&Event::time))
      .def("toString", &Event::toString)
      ;
  }

#ifdef __cplusplus
}
#endif

#endif
