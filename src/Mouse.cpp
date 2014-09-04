// Mouse.cpp by Paul R Jones (paujo) on 9.3.2014

#include <sstream>
#include "Mouse.h"
#include "functions.h"

#define BtnMap std::unordered_map<unsigned, SwitchState>

// Ctor.
Mouse::Mouse(Pengine *pengine) : pengine(pengine) {
  pos.x = pos.y = 0;
  history = new std::list<Point*>();
  buttonMap = new std::unordered_map<unsigned, SwitchState>();
  pendingEvents = new std::vector<Event*>();
}


// Dtor.
Mouse::~Mouse() {
  delete history;
  delete buttonMap;
  delete pendingEvents;
  pengine = NULL;
}


// Return the trajectory; the average of the last mouse positions.
Point *Mouse::trajectory() {
  int xSum = pos.x;
  int ySum = pos.y;
  for (auto his: *history) {
    xSum += his->x;
    ySum += his->y;
  }
  Point *res = new Point();
  res->x = xSum / trajectoryAveraging;
  res->y = ySum / trajectoryAveraging;
  return res;
}

// Set the length of the trajectory history
void Mouse::setTrajectoryFrameLength(unsigned newLength) {
  trajectoryAveraging = MAX(newLength, 1);
  while (history->size() >= newLength) {
    history->pop_back();
  }
}


// Return the state of the specified button
SwitchState Mouse::buttonState(unsigned button) {
  SwitchState res = SwitchState::UP;
  BtnMap::iterator it = buttonMap->find(button);
  if (it != buttonMap->end()) {
    res = it->second;
  }
  return res;
}


// Return the state of the left mouse button
SwitchState Mouse::leftButtonState() {
  return buttonState(SDL_BUTTON_LEFT);
}


// Return the state of the right mouse button
SwitchState Mouse::rightButtonState() {
  return buttonState(SDL_BUTTON_RIGHT);
}


// Return the state of the middle mouse button
SwitchState Mouse::middleButtonState() {
  return buttonState(SDL_BUTTON_MIDDLE);
}

// Set the state of the button to 'up'
void Mouse::setButtonUp(unsigned button) {
  buttonMap->erase(button);
  MouseButtonEvent *ev = new MouseButtonEvent(pengine->lastTick);
  ev->button = button;
  ev->pressed = false;
  pendingEvents->push_back(ev);
}

// Set the state of the button to 'pressed'
void Mouse::setButtonPressed(unsigned button) {
  BtnMap::iterator it = buttonMap->find(button);
  if (it == buttonMap->end()) {
    (*buttonMap)[button] = SwitchState::PRESSED;
    MouseButtonEvent *ev = new MouseButtonEvent(pengine->lastTick);
    ev->button = button;
    ev->pressed = true;
    pendingEvents->push_back(ev);
  }
}

// Set the state of the button to 'down'
void Mouse::setButtonDown(unsigned button) {
  (*buttonMap)[button] = SwitchState::DOWN;
}

// Set the sate of the left button to 'up'
void Mouse::setLeftButtonUp() {
  setButtonUp(SDL_BUTTON_LEFT);
}

// Set the state of the left button to 'pressed'
void Mouse::setLeftButtonPressed() {
  setButtonPressed(SDL_BUTTON_LEFT);
}

// Set the state of the left button to 'down'
void Mouse::setLeftButtonDown() {
  setButtonDown(SDL_BUTTON_LEFT);
}

// Set the state of the right button to 'up'
void Mouse::setRightButtonUp() {
  setButtonUp(SDL_BUTTON_RIGHT);
}

// Set the state of the right button to 'pressed'
void Mouse::setRightButtonPressed() {
  setButtonPressed(SDL_BUTTON_RIGHT);
}

// Set the state of the right button to 'down'
void Mouse::setRightButtonDown() {
  setButtonDown(SDL_BUTTON_RIGHT);
}

// Set the state of the middle button to 'up'
void Mouse::setMiddleButtonUp() {
  setButtonUp(SDL_BUTTON_MIDDLE);
}

// Set the state of the middle button to 'pressed'
void Mouse::setMiddleButtonPressed() {
  setButtonPressed(SDL_BUTTON_MIDDLE);
}

// Set the state of the middle button to 'down'
void Mouse::setMiddleButtonDown() {
  setButtonDown(SDL_BUTTON_MIDDLE);
}


// Handle a movement of the mouse.
void Mouse::processMotionEvent(SDL_MouseMotionEvent event) {
  if (trajectoryAveraging > 1) {
    Point *p = new Point();
    *p = pos;
    history->push_front(p);
    while (history->size() >= trajectoryAveraging)
      history->pop_back();
  }
  pos.x = static_cast<int>(event.x);
  pos.y = static_cast<int>(event.y);
  MouseMotionEvent *ev = new MouseMotionEvent(pengine->lastTick);
  ev->pos = pos;
  pendingEvents->push_back(ev);
}


// Handle a mouse button event.
void Mouse::processButtonEvent(SDL_MouseButtonEvent event) {
  if (event.type == SDL_MOUSEBUTTONDOWN) {
    setButtonPressed(static_cast<int>(event.button));
  } else if (event.type == SDL_MOUSEBUTTONUP) {
    setButtonUp(static_cast<int>(event.button));
  } else if (pengine != NULL) {
    std::stringstream ss;
    ss << "Received unexpected event type: " << static_cast<int>(event.type);
    pengine->log->errorMsg(ss.str());
  }
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
  for (auto it: (*buttonMap)) {
    if (it.second == SwitchState::PRESSED) {
      (*buttonMap)[it.first] = SwitchState::DOWN;
    }
  }
}


// Called be fore Pengine.processEvents() ends.
void Mouse::postProcess() {
  for (auto event : (*pendingEvents)) {
    // Do nothing for now.
  }
  pendingEvents->clear();
}
