// Keyboard.cpp by Paul R Jones (paujo) on 9.11.2014

#include "Keyboard.h"

// Ctor.
Keyboard::Keyboard(Pengine *pengine) : pengine(pengine), keyState(NULL), keyStateSize(-1) {
  pendingEvents = new std::vector<KeyboardKeyEvent*>();
  listeners = new std::vector<boost::python::object>();
}

// Dtor.
Keyboard::~Keyboard() {
  for (auto event : (*pendingEvents))
    delete event;
  delete pendingEvents;
  delete listeners;
}

// Internal processing before events are parsed
void Keyboard::preProcess(Uint32 delta) {
  // Do Nothing
}

// Internal processing after events are parsed
void Keyboard::postProcess() {
  for (auto event : (*pendingEvents)) {
    for (auto listener : (*listeners)) {
      listener.attr("handleKeyboardKey")(boost::ref(event));
    }
  }
  pendingEvents->clear();
}

// Process a keyboard event.
void Keyboard::processKeyboardEvent(SDL_KeyboardEvent event) {
  if (keyState == NULL) keyState = SDL_GetKeyboardState(&keyStateSize);
  KeyboardKeyEvent *newEvent = new KeyboardKeyEvent(pengine->lastTick);
  newEvent->keyDown = (event.state == SDL_PRESSED);
  newEvent->repeat = event.repeat;
  newEvent->scanCode = event.keysym.scancode;
  pendingEvents->push_back(newEvent);
}


// Is the specified key down?
bool Keyboard::isKeyDown(KeyboardScanCode scanCode) {
  if (keyState == NULL) keyState = SDL_GetKeyboardState(&keyStateSize);
  if (scanCode < keyStateSize)
    return keyState[scanCode];
  return false;
}


// Add a listener to the listener list
void Keyboard::registerListener(boost::python::object newListener) {
  listeners->push_back(newListener);
}


// Remove a listener from the listener list
void Keyboard::deregisterListener(boost::python::object oldListener) {
  std::vector<boost::python::object>::iterator it;
  for (it = listeners->begin(); it != listeners->end(); ++it) {
    if (*it == oldListener) {
      listeners->erase(it);
      return;
    }
  }
}
