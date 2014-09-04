// MouseMotionEvent.cpp by Paul R Jones (paujo) on 9.4.2014

#include <sstream>
#include "MouseMotionEvent.h"

// Ctor.
MouseMotionEvent::MouseMotionEvent(Uint32 time) : Event(time) {
  pos.x = 0;
  pos.y = 0;
}

// Create a human-readable description of the event.
std::string MouseMotionEvent::toString() {
  std::stringstream ss;
  ss << "MouseMotionEvent at " << static_cast<int>(time) << " ticks. The new mouse position is " << pos.x << ", " << pos.y << ".";
  return ss.str();
}
