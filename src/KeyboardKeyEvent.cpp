// KeyboardKeyEvent.cpp by Paul R Jones (paujo) on 9.15.2014

#include <sstream>
#include "KeyboardKeyEvent.h"

// Ctor.
KeyboardKeyEvent::KeyboardKeyEvent(Uint32 time) : Event(time) { }

// Return a human-readable description of the event.
std::string KeyboardKeyEvent::toString() {
  std::stringstream ss;
  ss << Event::toString();
  ss << " Key " << static_cast<Uint32>(scanCode) << " is " << (keyDown ? "down." : "up.");
  return ss.str();
}
