// pengine_image_module.h by Paul R Jones on 7.31.2014

#ifndef PAUJO_PENGINE_IMAGE_MODULE_H
#define PAUJO_PENGINE_IMAGE_MODULE_H

#include <boost/python.hpp>
#include "pengine_image_Image_wrap.h"
#include "pengine_image_ImageRegistry_wrap.h"

#ifdef __cplusplus
extern "C" {
#endif

  using namespace boost::python;

  void initmodule_image() {
    object imageModule(handle<>(borrowed(PyImport_AddModule("pengine.image"))));
    scope().attr("image") = imageModule;
    scope imageScope = imageModule;

    init_image();
    init_ImageRegistry();
  }

#ifdef __cplusplus
}
#endif

#endif
