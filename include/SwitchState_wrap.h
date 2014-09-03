// SwitchState_wrap.h by Paul R Jones (paujo) on 9.3.2014

#ifndef PAUJO_SWITCHSTATE_WRAP_H
#define PAUJO_SWITCHSTATE_WRAP_H

#include <boost/python.hpp>
#include "SwitchState.h"

#ifdef __cplusplus
extern "C" {
#endif

  using namespace boost::python;

  void init_SwitchState() {
    enum_<SwitchState>("SwitchState")
      .value("up", SwitchState::UP)
      .value("pressed", SwitchState::PRESSED)
      .value("down", SwitchState::DOWN)
      ;
  }

#ifdef __cplusplus
}
#endif

#endif
