// MouseListener_wrap.h by Paul R Jones (paujo) on 9.9.2014

#ifndef PAUJO_MOUSELISTENER_WRAP_H
#define PAUJO_MOUSELISTENER_WRAP_H

#include <boost/python.hpp>
#include "MouseListener.h"

#ifdef __cplusplus
extern "C" {
#endif

  using namespace boost::python;

  class MouseListener_wrapper : public MouseListener, public wrapper<MouseListener> {
  public:
    virtual void mouseButtonClicked(MouseButtonEvent *event) {
      this->get_override("mouseButtonClicked")(event);
    }
    virtual void mouseMoved(MouseMotionEvent *event) {
      this->get_override("mouseMoved")(event);
    }
    virtual void mouseWheelMoved(MouseWheelEvent *event) {
      this->get_override("mouseWheelMoved")(event);
    }
  };

  void init_MouseListener() {
    class_<MouseListener_wrapper, boost::noncopyable>("MouseListener")
      .def("mouseButtonClicked", pure_virtual(&MouseListener_wrapper::mouseButtonClicked))
      .def("mouseMoved", pure_virtual(&MouseListener_wrapper::mouseMoved))
      .def("mouseWheelMoved", pure_virtual(&MouseListener_wrapper::mouseWheelMoved))
      ;
  }

#ifdef __cplusplus
}
#endif

#endif
