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
  init_SwitchState();

  init_Event();
  init_EventListener();

  init_Mouse();
  init_MouseButtonEvent();
  init_MouseMotionEvent();
  init_MouseWheelEvent();
  init_MouseListener();

  init_Logger();

  init_Pengine();

}
