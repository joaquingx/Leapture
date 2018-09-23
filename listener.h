//
// Created by joaquin on 30/08/18.
//

#ifndef LEAPGESTURES_LISTENER_H
#define LEAPGESTURES_LISTENER_H


#include <Leap.h>
#include "interface.h"
#include "gestures.h"
#include "inter.h"

class BaseListener : public Leap::Listener {
public:
    VisInterface * interface;
    OwnGestures * Og;
    explicit BaseListener(VisInterface *& interface);
    virtual void onInit(const Leap::Controller&);
    virtual void onConnect(const Leap::Controller&);
    virtual void onDisconnect(const Leap::Controller&);
    virtual void onExit(const Leap::Controller&);
    virtual void onFrame(const Leap::Controller&);
    virtual void onFocusGained(const Leap::Controller&);
    virtual void onFocusLost(const Leap::Controller&);
    virtual void onDeviceChange(const Leap::Controller&);
    virtual void onServiceConnect(const Leap::Controller&);
    virtual void onServiceDisconnect(const Leap::Controller&);

private:
};

#endif //LEAPGESTURES_LISTENER_H
