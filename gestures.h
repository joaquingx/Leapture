//
// Created by joaquin on 30/08/18.
//

#ifndef LEAPGESTURES_GESTURES_H
#define LEAPGESTURES_GESTURES_H

#include <Leap.h>

class OwnGestures{
private:
    bool flag=false;
    void checkFist(Leap::Frame frame);
    bool getExtendedFingers(Leap::FingerList fl);
    void checkLiftUp(Leap::Frame frame);
    void checkPredefinedGestures(Leap::Frame frame, Leap::Controller controller);
    void checkKeyTap(Leap::Gesture gesture);


public:
    void checkGestures(Leap::Frame frame, Leap::Controller controller);
};

#endif //LEAPGESTURES_GESTURES_H
