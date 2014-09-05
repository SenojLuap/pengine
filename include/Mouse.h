// Mouse.h by Paul R Jones (paujo) on 9.3.2014

#ifndef PAUJO_MOUSE_H
#define PAUJO_MOUSE_H

#include <list>
#include <unordered_map>

#include "Pengine.h"
#include "Point.h"
#include "SwitchState.h"
#include "Event.h"
#include "MouseButtonEvent.h"
#include "MouseMotionEvent.h"
#include "MouseWheelEvent.h"

#ifdef __cplusplus
extern "C" {
#endif

  class Pengine;

  enum class MouseButton : Uint8 {
    LEFT = SDL_BUTTON_LEFT,
      RIGHT = SDL_BUTTON_RIGHT,
      MIDDLE = SDL_BUTTON_MIDDLE,
      X1 = SDL_BUTTON_X1,
      X2 = SDL_BUTTON_X2
  };

  class Mouse {
  public:
    Point *_pos;
    Uint32 buttonState;

    std::vector<Event*> *pendingEvents;

    Pengine *pengine;

    void preProcess(Uint32);
    void postProcess();

    bool isLeftButtonDown();
    bool isRightButtonDown();
    bool isMiddleButtonDown();
    bool isButtonDown0(Uint8);
    bool isButtonDown1(MouseButton);

    void pollMouseState();
    
    void processMotionEvent(SDL_MouseMotionEvent);
    void processButtonEvent(SDL_MouseButtonEvent);
    void processWheelEvent(SDL_MouseWheelEvent);

    Mouse(Pengine*);
    ~Mouse();
  };

#ifdef __cplusplus
}
#endif

#endif
