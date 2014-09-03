// Mouse.h by Paul R Jones (paujo) on 9.3.2014

#ifndef PAUJO_MOUSE_H
#define PAUJO_MOUSE_H

#include <list>
#include <unordered_map>

#include "Pengine.h"
#include "Point.h"
#include "SwitchState.h"

#ifdef __cplusplus
extern "C" {
#endif

  class Pengine;

  class Mouse {
  public:
    Point pos;
    unsigned trajectoryAveraging;
    std::list<Point*> *history;
    std::unordered_map <unsigned, SwitchState> *buttonMap;

    SwitchState leftButtonState();
    SwitchState rightButtonState();
    SwitchState middleButtonState();
    SwitchState buttonState(unsigned);
    
    Point *trajectory();
    void setTrajectoryFrameLength(unsigned);

    void setButtonUp(unsigned);
    void setButtonPressed(unsigned);
    void setButtonDown(unsigned);

    void setLeftButtonUp();
    void setLeftButtonPressed();
    void setLeftButtonDown();

    void setRightButtonUp();
    void setRightButtonPressed();
    void setRightButtonDown();

    void setMiddleButtonUp();
    void setMiddleButtonPressed();
    void setMiddleButtonDown();

    void processMotionEvent(SDL_MouseMotionEvent, Pengine*);
    void processButtonEvent(SDL_MouseButtonEvent, Pengine*);
    void processWheelEvent(SDL_MouseWheelEvent, Pengine*);

    Mouse();
    ~Mouse();
  };

#ifdef __cplusplus
}
#endif

#endif
