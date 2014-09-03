// Mouse.cpp by Paul R Jones (paujo) on 9.3.2014

#include "Mouse.h"
#include "functions.h"

#define BtnMap std::unordered_map<unsigned, SwitchState>

// Ctor.
Mouse::Mouse() {
  pos.x = pos.y = 0;
  history = new std::list<Point*>();
  buttonMap = new std::unordered_map<unsigned, SwitchState>();
}


// Dtor.
Mouse::~Mouse() {
  delete history;
  delete buttonMap;
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
  return buttonState(0);
}


// Return the state of the right mouse button
SwitchState Mouse::rightButtonState() {
  return buttonState(1);
}


// Return the state of the middle mouse button
SwitchState Mouse::middleButtonState() {
  return buttonState(2);
}

// Set the state of the button to 'up'
void Mouse::setButtonUp(unsigned button) {
  buttonMap->erase(button);
}

// Set the state of the button to 'pressed'
void Mouse::setButtonPressed(unsigned button) {
  (*buttonMap)[button] = SwitchState::PRESSED;
}

// Set the state of the button to 'down'
void Mouse::setButtonDown(unsigned button) {
  (*buttonMap)[button] = SwitchState::DOWN;
}

// Set the sate of the left button to 'up'
void Mouse::setLeftButtonUp() {
  setButtonUp(0);
}

// Set the state of the left button to 'pressed'
void Mouse::setLeftButtonPressed() {
  setButtonPressed(0);
}

// Set the state of the left button to 'down'
void Mouse::setLeftButtonDown() {
  setButtonDown(0);
}

// Set the state of the right button to 'up'
void Mouse::setRightButtonUp() {
  setButtonUp(1);
}

// Set the state of the right button to 'pressed'
void Mouse::setRightButtonPressed() {
  setButtonPressed(1);
}

// Set the state of the right button to 'down'
void Mouse::setRightButtonDown() {
  setButtonDown(1);
}

// Set the state of the middle button to 'up'
void Mouse::setMiddleButtonUp() {
  setButtonUp(2);
}

// Set the state of the middle button to 'pressed'
void Mouse::setMiddleButtonPressed() {
  setButtonPressed(2);
}

// Set the state of the middle button to 'down'
void Mouse::setMiddleButtonDown() {
  setButtonDown(2);
}

