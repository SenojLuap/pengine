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
    virtual void handleMouseButton(MouseButtonEvent *);
    virtual void handleMouseMotion(MouseMotionEvent *);
    virtual void handleMouseWheel(MouseWheelEvent *);
  };

#ifdef __cplusplus
}
#endif

#endif
