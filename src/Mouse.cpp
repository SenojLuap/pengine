// Mouse.cpp by Paul R Jones (paujo) on 9.3.2014

#include <sstream>
#include "Mouse.h"
#include "functions.h"

// Ctor.
Mouse::Mouse(Pengine *pengine) : pengine(pengine) {
  pendingEvents = new std::vector<Event*>();
  listeners = new std::vector<boost::python::object>();
  _pos = NULL;
}


// Dtor.
Mouse::~Mouse() {
  delete pendingEvents;
  delete listeners;
  if (_pos != NULL)
    delete _pos;
  pengine = NULL;
}

// Add a listener to the listeners list
//void Mouse::registerListener(MouseListener *newListener) {
void Mouse::registerListener(boost::python::object newListener) {
  listeners->push_back(newListener);
}

// Remove a listener from the listeners list
//void Mouse::deregisterListener(MouseListener *oldListener) {
void Mouse::deregisterListener(boost::python::object oldListener) {
  std::vector<boost::python::object>::iterator it;
  for (it = listeners->begin(); it != listeners->end(); ++it) {
    if (*it == oldListener) {
      listeners->erase(it);
      return;
    }
  }
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
    for (auto listener : (*listeners)) {
      MouseWheelEvent *wheelEvent = dynamic_cast<MouseWheelEvent*>(event);
      if (wheelEvent != NULL) {
	listener.attr("handleMouseWheel")(boost::ref(wheelEvent));
	continue;
      }
      MouseButtonEvent *buttonEvent = dynamic_cast<MouseButtonEvent*>(event);
      if (buttonEvent != NULL) {
	listener.attr("handleMouseButton")(boost::ref(buttonEvent));
	continue;
      }
      MouseMotionEvent *motionEvent = dynamic_cast<MouseMotionEvent*>(event);
      if (motionEvent != NULL) {
	listener.attr("handleMouseMotion")(boost::ref(motionEvent));
      }
    }
  }
  pendingEvents->clear();
}
