// Keyboard_wrap.h by Paul R Jones (paujo) on 9.11.2014

#ifndef PAUJO_KEYBOARD_WRAP_H
#define PAUJO_KEYBOARD_WRAP_H

#include <boost/python.hpp>
#include "Keyboard.h"

#ifdef __cplusplus
extern "C" {
#endif

  using namespace boost::python;

  void init_Keyboard() {
    class_<Keyboard>("Keyboard", no_init)
      .def("isKeyDown", &Keyboard::isKeyDown)
      ;
  }

#ifdef __cplusplus
}
#endif

#endif
