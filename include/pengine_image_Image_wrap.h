// pengine_image_Image_wrap.h by Paul R Jones (paujo) on 7.31.2014

#ifndef PAUJO_PENGINE_IMAGE_IMAGE_WRAP_H
#define PAUJO_PENGINE_IMAGE_IMAGE_WRAP_H

#include <boost/python.hpp>
#include "pengine_image_Image.h"

#ifdef __cplusplus
extern "C" {
#endif

  void init_image() {
    boost::python::class_<Image>("Image", init<std::string>());
  }


#ifdef __cplusplus
}
#endif

#endif
