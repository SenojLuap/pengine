// Image_wrap.h by Paul R Jones (paujo) on 7.31.2014

#ifndef PAUJO_IMAGE_WRAP_H
#define PAUJO_IMAGE_WRAP_H

#include <boost/python.hpp>
#include "Image.h"

#ifdef __cplusplus
extern "C" {
#endif

  using namespace boost::python;

  void init_Image() {
    class_<Image>("Image", no_init)
      .add_property("url", make_function(&Image::getUrl, return_value_policy<copy_const_reference>()))
      .add_property("size", &Image::size)
      .def("valid", &Image::valid);
  }


#ifdef __cplusplus
}
#endif

#endif
