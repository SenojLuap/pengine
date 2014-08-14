// Drawable_wrap.h by Paul R Jones (paujo) on 8.5.2014

#ifndef PAUJO_DRAWABLE_WRAP_H
#define PAUJO_DRAWABLE_WRAP_H

#include <boost/python.hpp>
#include "Drawable.h"

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
      .add_property("placement", make_getter(&Drawable::placement), make_setter(&Drawable::placement))
      ;
  }
  
#ifdef __cplusplus
}
#endif

#endif
