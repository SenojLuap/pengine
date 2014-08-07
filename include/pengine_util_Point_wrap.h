// pengine_util_Point_wrap.h by Paul R Jones (paujo) on 8.7.2014

#ifndef PAUJO_PENGINE_UTIL_POINT_WRAP_H
#define PAUJO_PENGINE_UTIL_POINT_WRAP_H

#include <boost/python.hpp>
#include "pengine_util_Point.h"

#ifdef __cplusplus
extern "C" {
#endif

  using namespace boost::python;

  void init_Point() {
    class_<Point>("Point")
      .add_property("x", make_getter(&Point::x), make_setter(&Point::x))
      .add_property("y", make_getter(&Point::y), make_setter(&Point::y))
      ;
  }


#ifdef __cplusplus
}
#endif

#endif
