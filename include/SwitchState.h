// SwitchState.h by Paul R Jones (paujo) on 9.3.2014

#ifndef PAUJO_SWITCHSTATE_H
#define PAUJO_SWITCHSTATE_H

#include <cstdint>

#ifdef __cplusplus
extern "C" {
#endif

  enum class SwitchState : std::uint8_t {
    UP = 0,
    PRESSED = 1,
    DOWN = 2
  };

#ifdef __cplusplus
}
#endif

#endif
