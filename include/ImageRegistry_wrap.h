// ImageRegistry_wrap.h by Paul R Jones (paujo) on 8.4.2014

#ifndef PAUJO_IMAGEREGISTRY_WRAP_H
#define PAUJO_IMAGEREGISTRY_WRAP_H

#include <boost/python.hpp>
#include "ImageRegistry.h"
#include "Image.h"

#ifdef __cplusplus
extern "C" {
#endif
  
  using namespace boost::python;

  void init_ImageRegistry() {
    class_<ImageRegistry>("ImageRegistry")
      .def("get", &ImageRegistry::get, return_internal_reference<1>())
      .def("contains", &ImageRegistry::contains)
      .def("registerImage", &ImageRegistry::registerImage0)
      .def("registerImage", &ImageRegistry::registerImage1);
  }

#ifdef __cplusplus
}
#endif

#endif
