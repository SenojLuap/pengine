// MouseWheelEvent.cpp by Paul R Jones (paujo) on 9.4.2014

#include "MouseWheelEvent.h"

// Ctor.
MouseWheelEvent::MouseWheelEvent(Uint32 time) : Event(time) {
  scroll.x = scroll.y = 0;
}

// Return a human-readable description of the event.
std::string MouseWheelEvent::toString() {
  std::stringstream ss;
  ss << "MouseWheelEvent at " << time << " ticks. VScroll: " << scroll.y << ". HScroll: " << scroll.x;
  return ss.str();
}
