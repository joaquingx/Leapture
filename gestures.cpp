//
// Created by joaquin on 30/08/18.
//
#include "gestures.h"
#include "state.h"
#include "interface.h"
#define STATES 4
#define NITEMS 5
using namespace std;

int cnt=0,cMode=0;
string toDo;
string OwnGestures::getChavoCommand() {
    if(currentState == Principal){
        if(!(cnt%NITEMS))
        {
            if(!(cMode % 2))
                toDo = "xdotool key Down", cMode++;
            else
                toDo = "xdotool key Up", cMode++;
        }
        ++cnt;
    }
    return toDo;
}

string OwnGestures::grabCommand(const gchar *gesture) {
    VisualInterface interface;
    interface.createGesture(gesture);
}

OwnGestures::OwnGestures() {
    bindMap.resize(STATES);
    bindMap[Begin]["Fist"] = "xdotool key super+w";
    bindMap[Begin]["Chavo"] = "";
    bindMap[Principal]["Fist"] = "xdotool key Return";
    //    bindMap[Free]["Fist"] = grabCommand("Fist");
//    bindMap[Free]["Chavo"] = grabCommand("Chavo");
//    bindMap[Free]["LiftUp"] = grabCommand("LiftUp");
}

void OwnGestures::manageAccordingState(string gesture) {
    cout << "Gesture is " << gesture << "and the command is" << bindMap[currentState][gesture] << "\n";
    if(currentState == Free) {
        grabCommand(gesture.c_str());
    }
    else {
        bindMap[Principal]["Chavo"] = getChavoCommand();
        system((bindMap[currentState][gesture]).c_str());
    }
}

void OwnGestures::checkGestures(Leap::Frame frame, Leap::Controller controller) {
    bool anyoneActivated=false;
//    cout << currentState << "\n";
    cout << "frametimestamp:" << frame.timestamp() << " mintimestamp:"<< minTimeStamp << "\n";

    if(frame.timestamp() > minTimeStamp){
        if(checkFist(frame)){
            anyoneActivated=true;
            manageAccordingState("Fist");
        }
        else if(checkLiftUp(frame)){
            anyoneActivated=true;
            manageAccordingState("LiftUp");
        }
        else if(checkPredefinedGestures(frame, controller)){
            anyoneActivated=true;
            manageAccordingState("Chavo");
        }
        if(anyoneActivated){// minimium time between gestures binding
            minTimeStamp = frame.timestamp() + 400000;
        }
    }
}
bool OwnGestures::getExtendedFingers(Leap::FingerList fl) {
    return (fl.extended().count() == 0);
}

bool OwnGestures::checkFist(Leap::Frame frame) {
    Leap::HandList hands = frame.hands();
    for(Leap::HandList::const_iterator hl = hands.begin() ; hl!= hands.end(); ++hl){
        const Leap::Hand hand = *hl;
        Leap::FingerList fl = hand.fingers();
        float sum = 0;
        float minValue = 0.7;
        const Leap::FingerList fingers = hand.fingers();
        for (Leap::FingerList::const_iterator fl = fingers.begin(); fl != fingers.end(); ++fl) {
            const Leap::Finger finger = *fl;
            Leap::Vector bonesDirs[3];
            for(int j = 0 ; j < 3 ; ++j){
                Leap::Bone::Type boneType = static_cast<Leap::Bone::Type>(j);
                Leap::Bone bone = finger.bone(boneType);
                bonesDirs[j]= bone.direction();
            }
            sum += bonesDirs[0].dot(bonesDirs[1]);
            sum += bonesDirs[1].dot(bonesDirs[2]);
        }
        sum /= 10;
        if(sum <= minValue && getExtendedFingers(fl)){
            return true;
        }
    }
}

bool OwnGestures::checkLiftUp(Leap::Frame frame) {
    int numberHands = frame.hands().count();
    Leap::HandList hands = frame.hands();
    Leap::Vector palmNormals[2];
    Leap::Vector palmVelocities[2];
    int cnt = 0;
    for(Leap::HandList::const_iterator hl = hands.begin() ; hl!= hands.end(); ++hl){
        const Leap::Hand hand = *hl;
        palmNormals[cnt] = hand.palmNormal();
        palmVelocities[cnt] = hand.palmVelocity();
        ++cnt;
    }
    if ((numberHands == 2) &&
        (palmNormals[0].roll() < 0.0f) && (palmNormals[1].roll() < 0.0f) &&
        (palmVelocities[0].z > 50.0f) && (palmVelocities[1].z > 50.0f) &&
        (palmVelocities[0].z < 300.0f) && (palmVelocities[1].z < 300.0f)) {
        return true;
    }
}



bool OwnGestures::checkPredefinedGestures(Leap::Frame frame, Leap::Controller controller) {
    const std::string stateNames[] = {"STATE_INVALID", "STATE_START", "STATE_UPDATE", "STATE_END"};
    const Leap::GestureList gestures = frame.gestures();
    bool isActivated=false;
    for (int g = 0; g < gestures.count(); ++g) {
        Leap::Gesture gesture = gestures[g];

        switch (gesture.type()) {
            case Leap::Gesture::TYPE_CIRCLE:
            {
                Leap::CircleGesture circle = gesture;
                std::string clockwiseness;

                if (circle.pointable().direction().angleTo(circle.normal()) <= Leap::PI/2) {
                    clockwiseness = "clockwise";
                } else {
                    clockwiseness = "counterclockwise";
                }

                // Calculate angle swept since last frame
                float sweptAngle = 0;
                if (circle.state() != Leap::Gesture::STATE_START) {
                    Leap::CircleGesture previousUpdate = Leap::CircleGesture(controller.frame(1).gesture(circle.id()));
                    sweptAngle = (circle.progress() - previousUpdate.progress()) * 2 * Leap::PI;
                }
                std::cout << std::string(2, ' ')
                          << "Circle id: " << gesture.id()
                          << ", state: " << stateNames[gesture.state()]
                          << ", progress: " << circle.progress()
                          << ", radius: " << circle.radius()
                          << ", angle " << sweptAngle
                          <<  ", " << clockwiseness << std::endl;
                break;
            }
            case Leap::Gesture::TYPE_SWIPE:
            {
                Leap::SwipeGesture swipe = gesture;
                std::cout << std::string(2, ' ')
                          << "Swipe id: " << gesture.id()
                          << ", state: " << stateNames[gesture.state()]
                          << ", direction: " << swipe.direction()
                          << ", speed: " << swipe.speed() << std::endl;
                break;
            }
            case Leap::Gesture::TYPE_KEY_TAP:
            {
                isActivated = checkKeyTap(gesture);
                break;
            }
            case Leap::Gesture::TYPE_SCREEN_TAP:
            {
                Leap::ScreenTapGesture screentap = gesture;
                std::cout << std::string(2, ' ')
                          << "Screen Tap id: " << gesture.id()
                          << ", state: " << stateNames[gesture.state()]
                          << ", position: " << screentap.position()
                          << ", direction: " << screentap.direction()<< std::endl;
                break;
            }
            default:
                std::cout << std::string(2, ' ')  << "Unknown gesture type." << std::endl;
                break;
            case Leap::Gesture::TYPE_INVALID:break;
        }
    }
    return isActivated;
}

bool OwnGestures::checkKeyTap(Leap::Gesture gesture) {
    Leap::KeyTapGesture tap = gesture;
    std::cout << std::string(2, ' ')
              << "Key Tap id: " << gesture.id()
              << ", position: " << tap.position()
              << ", direction: " << tap.direction()<< std::endl;
    return 1;

}








