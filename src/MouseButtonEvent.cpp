// MouseButtonEvent.cpp by Paul R Jones (paujo) 9.4.2014

#include <sstream>
#include "MouseButtonEvent.h"

// Ctor.
MouseButtonEvent::MouseButtonEvent(Uint32 time) : Event(time) {
  button = 0;
  pressed = true;
}

// Ctor.
MouseButtonEvent::MouseButtonEvent(Uint32 time, SDL_MouseButtonEvent event) : Event(time) {
  button = event.button;
  pressed = (event.type == SDL_MOUSEBUTTONDOWN);
}

// Convert the event to a human-readable string
std::string MouseButtonEvent::toString() {
  std::stringstream ss;
  ss << "MouseButtonEvent at " << static_cast<int>(time) << " ticks. Button " << static_cast<int>(button) << " is"
     << (pressed ? " down." : " up.");
  return ss.str();
}
