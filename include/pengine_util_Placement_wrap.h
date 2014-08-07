// pengine_util_Placement_wrap.h by Paul R Jones (paujo) on 8.7.2014

#ifndef PAUJO_PENGINE_UTIL_PLACEMENT_WRAP_H
#define PAUJO_PENGINE_UTIL_PLACEMENT_WRAP_H

#include <boost/python.hpp>
#include "pengine_util_Placement.h"

#ifdef __cplusplus
extern "C" {
#endif

  using namespace boost::python;
  
  void init_Placement() {
    class_<Placement>("Placement")
      .add_property("position", make_getter(&Placement::position), make_setter(&Placement::position))
      .add_property("scale", make_getter(&Placement::scale), make_setter(&Placement::scale))
      .add_property("rotation", make_getter(&Placement::rotation), make_setter(&Placement::rotation))
      .add_property("rotationOrigin", make_getter(&Placement::rotationOrigin), make_setter(&Placement::rotationOrigin))
      ;
  }


#ifdef __cplusplus
}
#endif

#endif
