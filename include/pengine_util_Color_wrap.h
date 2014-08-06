// pengine_util_Color_wrap.h by Paul R Jones (paujo) on 8.6.2014

#ifndef PAUJO_PENGINE_UTIL_COLOR_WRAP_H
#define PAUJO_PENGINE_UTIL_COLOR_WRAP_H

#include <boost/python.hpp>
#include "pengine_util_Color.h"

#ifdef __cplusplus
extern "C" {
#endif

  using namespace boost::python;

  void init_Color() {
    class_<Color>("Color", init<>())
      .def(init<int, int, int, int>())
      .add_property("r", make_getter(&Color::r), make_setter(&Color::r))
      .add_property("g", make_getter(&Color::g), make_setter(&Color::g))
      .add_property("b", make_getter(&Color::b), make_setter(&Color::b))
      .add_property("a", make_getter(&Color::a), make_setter(&Color::a))
      ;
  }
  

#ifdef __cplusplus
}
#endif

#endif
