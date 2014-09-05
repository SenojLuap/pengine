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
    enum_<MouseButton>("MouseButton")
      .value("Left", MouseButton::LEFT)
      .value("Right", MouseButton::RIGHT)
      .value("Middle", MouseButton::MIDDLE)
      .value("X1", MouseButton::X1)
      .value("X2", MouseButton::X2)
      ;

    class_<Mouse>("Mouse", no_init)
      .def("isLeftButtonDown", &Mouse::isLeftButtonDown)
      .def("isRightButtonDown", &Mouse::isRightButtonDown)
      .def("isMiddleButtonDown", &Mouse::isMiddleButtonDown)
      .def("isButtonDown", &Mouse::isButtonDown0)
      .def("isButtonDown", &Mouse::isButtonDown1)
      ;
  }

#ifdef __cplusplus
}
#endif

#endif
