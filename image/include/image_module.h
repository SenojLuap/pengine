// image_module.h by Paul R Jones on 7.31.2014

#ifndef PAUJO_IMAGE_MODULE_H
#define PAUJO_IMAGE_MODULE_J

#include <boost/python.h>
#include "image_wrap.h"

#ifdef __cplusplus
extern "C" {
#endif

  using namespace boost::python;

  void initmodule_image() {
    object imageModule(handle<>(borrowed(PyImport_AddModule("pengine.image"))));
    scope().attr("image") = imageModule;
    scope imageScope = imageModule;

    init_image();
  }

#ifdef __cplusplus
}
#endif

#endif
