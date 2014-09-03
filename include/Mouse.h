// Mouse.h by Paul R Jones (paujo) on 9.3.2014

#ifndef PAUJO_MOUSE_H
#define PAUJO_MOUSE_H

#include <list>
#include <unordered_map>

#include "Point.h"
#include "SwitchState.h"

#ifdef __cplusplus
extern "C" {
#endif

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

    Mouse();
    ~Mouse();
  };

#ifdef __cplusplus
}
#endif

#endif
