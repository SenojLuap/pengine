// Placement_wrap.h by Paul R Jones (paujo) on 8.7.2014

#ifndef PAUJO_PLACEMENT_WRAP_H
#define PAUJO_PLACEMENT_WRAP_H

#include <boost/python.hpp>
#include "Placement.h"

#ifdef __cplusplus
extern "C" {
#endif

  using namespace boost::python;
  
  void init_Placement() {
    class_<Placement>("Placement", init<int, int, double, double, int, int, bool, bool>((arg("posX")=0, arg("posY")=0,
											arg("scale")=1.0, arg("rotation")=0.0,
											arg("rotationOriginX")=0,
											arg("rotationOriginY")=0,
											arg("flipHorizontal")=false,
											 arg("flipVerical")=false)))
      .add_property("position", make_getter(&Placement::position), make_setter(&Placement::position))
      .add_property("scale", make_getter(&Placement::scale), make_setter(&Placement::scale))
      .add_property("rotation", make_getter(&Placement::rotation), make_setter(&Placement::rotation))
      .add_property("rotationOrigin", make_getter(&Placement::rotationOrigin), make_setter(&Placement::rotationOrigin))
      .add_property("flipHorizontal", make_getter(&Placement::flipHorizontal), make_setter(&Placement::flipHorizontal))
      .add_property("flipVertical", make_getter(&Placement::flipVertical), make_setter(&Placement::flipVertical))
      ;
  }


#ifdef __cplusplus
}
#endif

#endif
