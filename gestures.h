//
// Created by joaquin on 30/08/18.
//

#ifndef LEAPGESTURES_GESTURES_H
#define LEAPGESTURES_GESTURES_H

#include <Leap.h>
#include <string>
#include <map>
#include <vector>
#include "state.h"
#include "interface.h"

using namespace std;

class OwnGestures{
private:
    // e.g. bindMap[Begin]["Fist"] = "oneko" means that with fist, in begin state we'll exec an oneko
    int64_t minTimeStamp = 0;
    vector< map<string,string> > bindMap;
    VisualInterface *interface;
    bool checkFist(Leap::Frame frame);
    bool getExtendedFingers(Leap::FingerList fl);
    bool checkLiftUp(Leap::Frame frame);
    bool checkPredefinedGestures(Leap::Frame frame, Leap::Controller controller);
    bool checkKeyTap(Leap::Gesture gesture);
    void manageAccordingState(string gesture);
    string getChavoCommand();
    void grabCommand(const char *gesture);
public:
    OwnGestures(VisualInterface *& interface);
    void checkGestures(Leap::Frame frame, Leap::Controller controller);
};

#endif //LEAPGESTURES_GESTURES_H
