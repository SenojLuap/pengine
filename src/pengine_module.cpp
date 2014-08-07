// pengine_module.cpp by Paul R Jones (paujo) on 7.31.2014

#include <boost/python.hpp>

#include "pengine_Pengine.h"
#include "pengine_Logger_wrap.h"
#include "pengine_Drawable_wrap.h"
#include "pengine_image_module.h"
#include "pengine_util_module.h"

using namespace boost::python;

BOOST_PYTHON_MODULE(pengine) {
  object package = scope();
  package.attr("__path__") = "pengine";

  
  initmodule_image();
  initmodule_util();

  init_logger();
  init_Drawable();

  def("startPengine", startPengine);
  def("stopPengine", stopPengine);
  def("initScreen", initScreen);
  def("initScreen", initScreen2);
  def("imageRegistry", getImageRegistry, return_value_policy<copy_const_reference>());

  def("initLayers", initLayers);
  def("setLayerSize", setLayerSize);
  def("setLayerWrap", setLayerWrap);
  def("invalidateLayer", invalidateLayer);
  def("invalidateAllLayers", invalidateAllLayers);
  def("setLayerRestrictFocus", setLayerRestrictFocus);
  def("setLayerClearColor", setLayerClearColor);
  def("setLayerFocus", setLayerFocus);
}
