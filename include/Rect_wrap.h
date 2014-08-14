// Rect_wrap.h by Paul R Jones (paujo) on 8.8.2014

#ifndef PAUJO_RECT_WRAP_H
#define PAUJO_RECT_WRAP_H

#include <boost/python.hpp>
#include "Rect.h"

#ifdef __cplusplus
extern "C" {
#endif

  using namespace boost::python;

  void init_Rect() {
    class_<Rect>("Rect")
      .add_property("x", make_getter(&Rect::x), make_setter(&Rect::x))
      .add_property("y", make_getter(&Rect::y), make_setter(&Rect::y))
      .add_property("w", make_getter(&Rect::w), make_setter(&Rect::w))
      .add_property("h", make_getter(&Rect::h), make_setter(&Rect::h))
      ;
  }

#ifdef __cplusplus
}
#endif

#endif
