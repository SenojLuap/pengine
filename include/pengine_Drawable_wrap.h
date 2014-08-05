// pengine_Drawable_wrap.h by Paul R Jones (paujo) on 8.5.2014

#ifndef PAUJO_PENGINE_DRAWABLE_WRAP_H
#define PAUJO_PENGINE_DRAWABLE_WRAP_H

#include <boost/python.hpp>
#include "pengine_Drawable.h"

#ifdef __cplusplus
extern "C" {
#endif

  using namespace boost::python;

  struct DrawableWrap : Drawable, wrapper<Drawable> {
    Image *getImage() {
      return this->get_override("getImage")();
    }
  };
 
  void init_Drawable() {
    class_<DrawableWrap, boost::noncopyable>("Drawable")
      .def("getImage", pure_virtual(&Drawable::getImage), return_value_policy<reference_existing_object>())
      .def("invalidate", &Drawable::invalidate)
      .add_property("x", make_getter(&Drawable::x), make_setter(&Drawable::x))
      .add_property("y", make_getter(&Drawable::y), make_setter(&Drawable::y))
      .add_property("scale", make_getter(&Drawable::scale), make_setter(&Drawable::scale))
      .add_property("rotation", make_getter(&Drawable::rotation), make_setter(&Drawable::rotation))
      ;
  }
  
#ifdef __cplusplus
}
#endif

#endif
