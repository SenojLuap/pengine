// Pengine_wrap by Paul R Jones (paujo) on 8.25.2014

#ifndef PAUJO_PENGINE_WRAP_H
#define PAUJO_PENGINE_WRAP_H

#include <boost/python.hpp>
#include "Pengine.h"

#ifdef __cplusplus
extern "C" {
#endif

  using namespace boost::python;
  
  void init_Pengine() {
    class_<Pengine>("Pengine")
      .def("initScreen", &Pengine::initScreen0)
      .def("initScreen", &Pengine::initScreen1)
      .def("render", &Pengine::render)
      .def_readonly("log", make_getter(&Pengine::log, return_internal_reference<1>()))
      .def_readonly("imageRegistry", make_getter(&Pengine::imageRegistry, return_internal_reference<1>()))
      ;
  }

#ifdef __cplusplus
}
#endif

#endif
