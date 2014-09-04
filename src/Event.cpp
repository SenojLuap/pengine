// Event.cpp by Paul R Jones (paujo) on 9.4.2014

#include <sstream>
#include "Event.h"

// Ctor.
Event::Event(Uint32 time) : time(time) { }

// Convert the event to a human-readable string.
std::string Event::toString() {
  std::stringstream ss;
  ss << "Event at " << static_cast<int>(time) << " ticks";
  return ss.str();
}
