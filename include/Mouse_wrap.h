// Mouse_wrap.h by Paul R Jones (paujo) on 9.3.2014

#ifndef PAUJO_MOUSE_WRAP_H
#define PAUJO_MOUSE_WRAP_H

#include <boost/python.hpp>
#include "Mouse.h"

#ifdef __cplusplus
extern "C" {
#endif

  using namespace boost::python;

  void init_Mouse() {
    class_<Mouse>("Mouse", no_init)
      .add_property("pos", make_getter(&Mouse::pos), make_setter(&Mouse::pos))
      .def("leftButtonState", &Mouse::leftButtonState)
      .def("rightButtonState", &Mouse::rightButtonState)
      .def("middleButtonState", &Mouse::middleButtonState)
      ;
  }

#ifdef __cplusplus
}
#endif

#endif
