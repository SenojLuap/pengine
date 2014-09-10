// MouseListener_wrap.h by Paul R Jones (paujo) on 9.9.2014

#ifndef PAUJO_MOUSELISTENER_WRAP_H
#define PAUJO_MOUSELISTENER_WRAP_H

#include <boost/python.hpp>
#include "MouseListener.h"

#ifdef __cplusplus
extern "C" {
#endif

  using namespace boost::python;

  void init_MouseListener() {
    class_<MouseListener>("MouseListener")
      .def("handleMouseButton", &MouseListener::handleMouseButton)
      .def("handleMouseMotion", &MouseListener::handleMouseMotion)
      .def("handleMouseWheel", &MouseListener::handleMouseWheel)
      ;
  }

#ifdef __cplusplus
}
#endif

#endif
