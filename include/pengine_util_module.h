// pengine_util_module.h by Paul R Jones (paujo) on 8.6.2014

#ifndef PAUJO_UTIL_MODULE_H
#define PAUJO_UTIL_MODULE_H

#include <boost/python.hpp>
#include "pengine_util_Color_wrap.h"
#include "pengine_util_Point_wrap.h"
#include "pengine_util_Placement_wrap.h"

#ifdef __cplusplus
extern "C" {
#endif

  using namespace boost::python;

  void initmodule_util() {
    object utilModule(handle<>(borrowed(PyImport_AddModule("pengine.util"))));
    scope().attr("util") = utilModule;
    scope utilScope = utilModule;

    init_Color();
    init_Point();
    init_Placement();
  }

#ifdef __cplusplus
}
#endif

#endif
