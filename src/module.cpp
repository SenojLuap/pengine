// module.cpp by Paul R Jones (paujo) on 7.31.2014

#include <boost/python.hpp>

#include "Pengine.h"
#include "wraps.h"

using namespace boost::python;

BOOST_PYTHON_MODULE(pengine) {
  init_Image();
  init_ImageRegistry();

  init_Color();
  init_Point();
  init_Rect();
  init_Placement();

  init_Logger();

  def("startPengine", startPengine);
  def("stopPengine", stopPengine);
  def("initScreen", initScreen);
  def("initScreen", initScreen2);
  def("imageRegistry", getImageRegistry, return_value_policy<reference_existing_object>());

  /*
  def("initLayers", initLayers);
  def("setLayerSize", setLayerSize);
  def("setLayerWrap", setLayerWrap);
  def("invalidateLayer", invalidateLayer);
  def("invalidateAllLayers", invalidateAllLayers);
  def("setLayerRestrictFocus", setLayerRestrictFocus);
  def("setLayerClearColor", setLayerClearColor);
  def("setLayerFocus", setLayerFocus);

  def("registerDrawable", registerDrawable0);
  def("registerDrawable", registerDrawable1);
  */
  def("render", render);
}
