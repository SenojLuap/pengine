// Mouse.cpp by Paul R Jones (paujo) on 9.3.2014

#include <sstream>
#include "Mouse.h"
#include "functions.h"

// Ctor.
Mouse::Mouse(Pengine *pengine) : pengine(pengine) {
  pendingEvents = new std::vector<Event*>();
  _pos = NULL;
}


// Dtor.
Mouse::~Mouse() {
  delete pendingEvents;
  if (_pos != NULL)
    delete _pos;
  pengine = NULL;
}


// Poll SDL for the state of the mouse
void Mouse::pollMouseState() {
  _pos = new Point();
  buttonState = SDL_GetMouseState(&_pos->x, &_pos->y);
}

// Return the state of the specified button
bool Mouse::isButtonDown1(MouseButton btn) {
  return isButtonDown0(static_cast<Uint8>(btn));
}


// Return the state of the specified button
bool Mouse::isButtonDown0(Uint8 btn) {
  if (_pos == NULL) pollMouseState();
  if (buttonState & SDL_BUTTON(btn))
    return true;
  return false;
}

// Return the state of the left mouse button
bool Mouse::isLeftButtonDown() {
  return isButtonDown1(MouseButton::LEFT);
}


// Return the state of the right mouse button
bool Mouse::isRightButtonDown() {
  return isButtonDown1(MouseButton::RIGHT);
}


// Return the state of the middle mouse button
bool Mouse::isMiddleButtonDown() {
  return isButtonDown1(MouseButton::MIDDLE);
}


// Handle a movement of the mouse.
void Mouse::processMotionEvent(SDL_MouseMotionEvent event) {
  MouseMotionEvent *ev = new MouseMotionEvent(pengine->lastTick);
  ev->pos.x = static_cast<int>(event.x);
  ev->pos.y = static_cast<int>(event.y);
  pendingEvents->push_back(ev);
}


// Handle a mouse button event.
void Mouse::processButtonEvent(SDL_MouseButtonEvent event) {
  MouseButtonEvent *ev = new MouseButtonEvent(pengine->lastTick);
  ev->button = event.button;
  ev->pressed = (event.type == SDL_MOUSEBUTTONDOWN);
  pendingEvents->push_back(ev);
}


// Handle a mouse wheel event.
void Mouse::processWheelEvent(SDL_MouseWheelEvent event) {
  MouseWheelEvent *ev = new MouseWheelEvent(pengine->lastTick);
  ev->scroll.x = event.x;
  ev->scroll.y = event.y;
  pendingEvents->push_back(ev);
}


// Handle per-tick operations
void Mouse::preProcess(Uint32 delta) {
  if (_pos != NULL) {
    delete _pos;
    _pos = NULL;
  }
}


// Called be fore Pengine.processEvents() ends.
void Mouse::postProcess() {
  for (auto event : (*pendingEvents)) {
    // Do nothing for now.
  }
  pendingEvents->clear();
}
