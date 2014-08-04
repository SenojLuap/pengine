// pengine_module.cpp by Paul R Jones (paujo) on 7.31.2014

#include <boost/python.hpp>

#include "pengine_Pengine.h"
#include "pengine_Logger_wrap.h"
#include "pengine_image_module.h"

using namespace boost::python;

BOOST_PYTHON_MODULE(pengine) {
  object package = scope();
  package.attr("__path__") = "pengine";

  init_logger();
  
  initmodule_image();

  def("startPengine", startPengine);
  def("stopPengine", stopPengine);
  def("initScreen", initScreen);
  def("initScreen", initScreen2);
  def("imageRegistry", getImageRegistry, return_value_policy<copy_const_reference>());
  
}
