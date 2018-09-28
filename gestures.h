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
#include "inter.h"

using namespace std;


void readFile(const char * config_file);

class OwnGestures{
private:
    // e.g. bindMap[Begin]["Fist"] = "oneko" means that with fist, in begin state we'll exec an oneko
    int64_t minTimeStamp = 0;
    VisInterface *interface;
    bool checkFist(Leap::Frame frame);
    bool checkDoubleFist(Leap::Frame frame);
    bool checkLeftLiftUp(Leap::Frame frame);
    bool checkModoDiablo(Leap::Frame frame);
    bool getExtendedFingers(Leap::FingerList fl, int num);
    bool checkLiftUp(Leap::Frame frame);
    int checkPredefinedGestures(Leap::Frame frame, Leap::Controller controller);
    bool checkKeyTap(Leap::Gesture gesture);
    void manageAccordingState(string gesture);
    string getChavoCommand();
    void grabCommand(const char *gesture);
public:
    OwnGestures(VisInterface *& interface);
    void checkGestures(Leap::Frame frame, Leap::Controller controller);
};

#endif //LEAPGESTURES_GESTURES_H
