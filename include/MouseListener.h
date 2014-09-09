// MouseListener.h by Paul R Jones (paujo) on 9.9.2014

#ifndef PAUJO_MOUSELISTENER_H
#define PAUJO_MOUSELISTENER_H

#include "MouseButtonEvent.h"
#include "MouseMotionEvent.h"
#include "MouseWheelEvent.h"

#ifdef __cplusplus
extern "C" {
#endif

  class MouseListener {
  public:
    virtual void mouseButtonClicked(MouseButtonEvent *) = 0;
    virtual void mouseMoved(MouseMotionEvent *) = 0;
    virtual void mouseWheelMoved(MouseWheelEvent *) = 0;
  };

#ifdef __cplusplus
}
#endif

#endif
