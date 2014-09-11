// Keyboard.cpp by Paul R Jones (paujo) on 9.11.2014

#include "Keyboard.h"

// Ctor.
Keyboard::Keyboard(Pengine *pengine) : pengine(pengine), keyState(NULL), keyStateSize(-1) { }

// Dtor.
Keyboard::~Keyboard() {
  // Do Nothing
}

// Internal processing before events are parsed
void Keyboard::preProcess(Uint32 delta) {
  // Do Nothing
}

// Internal processing after events are parsed
void Keyboard::postProcess() {
  // Do Nothing
}

// Process a keyboard event.
void Keyboard::processKeyboardEvent(SDL_KeyboardEvent event) {
  if (keyState == NULL) keyState = SDL_GetKeyboardState(&keyStateSize);
}


// Is the specified key down?
bool Keyboard::isKeyDown(KeyboardScanCode scanCode) {
  if (keyState == NULL) keyState = SDL_GetKeyboardState(&keyStateSize);
  if (scanCode < keyStateSize)
    return keyState[scanCode];
  return false;
}
