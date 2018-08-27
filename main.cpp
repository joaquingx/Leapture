/******************************************************************************\
* Copyright (C) 2012-2014 Leap Motion, Inc. All rights reserved.               *
* Leap Motion proprietary and confidential. Not for distribution.              *
* Use subject to the terms of the Leap Motion SDK Agreement available at       *
* https://developer.leapmotion.com/sdk_agreement, or another agreement         *
* between Leap Motion and you, your company or other organization.             *
\******************************************************************************/

#include <iostream>
#include <cstring>
#include "Leap.h"
#include <unistd.h>


using namespace Leap;
using namespace std;

class BaseListener : public Leap::Listener {
public:
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

bool flag=0;
const std::string fingerNames[] = {"Thumb", "Index", "Middle", "Ring", "Pinky"};
const std::string boneNames[] = {"Metacarpal", "Proximal", "Middle", "Distal"};
const std::string stateNames[] = {"STATE_INVALID", "STATE_START", "STATE_UPDATE", "STATE_END"};

// This method MUST exist!!!!
void BaseListener::onInit(const Leap::Controller& controller) {
    std::cout << "Initialization" << std::endl;
}

void BaseListener::onConnect(const Leap::Controller& controller) {
    std::cout << "Hardware and Software Connected!!!" << std::endl;
//    controller.enableGesture(Gesture::TYPE_CIRCLE);
    controller.enableGesture(Gesture::TYPE_KEY_TAP);
    controller.enableGesture(Gesture::TYPE_SCREEN_TAP);
    controller.enableGesture(Gesture::TYPE_SWIPE);
}

void BaseListener::onDisconnect(const Leap::Controller& controller) {
    // Note: not dispatched when running in a debugger.
    std::cout << "Disconnected" << std::endl;
}

void BaseListener::onExit(const Leap::Controller& controller) {
    std::cout << "Exited" << std::endl;
}

bool getExtendedFingers(Leap::FingerList fl) {
    return (fl.extended().count() == 0);
}

//function checkFist(hand){
//    var sum = 0;
//    for(var i=0;i<hand.fingers.length;i++){
//        var finger = hand.fingers[i];
//        var meta = finger.bones[0].direction();
//        var proxi = finger.bones[1].direction();
//        var inter = finger.bones[2].direction();
//        var dMetaProxi = Leap.vec3.dot(meta,proxi);
//        var dProxiInter = Leap.vec3.dot(proxi,inter);
//        sum += dMetaProxi;
//        sum += dProxiInter
//    }
//    sum = sum/10;
//
//    if(sum<=minValue && getExtendedFingers(hand)==0){
//        return true;
//    }else{
//        return false;
//    }
//}

void checkFist(Leap::Frame frame){
    Leap::HandList hands = frame.hands();
    for(HandList::const_iterator hl = hands.begin() ; hl!= hands.end(); ++hl){
        const Hand hand = *hl;
        Leap::FingerList fl = hand.fingers();
        float sum = 0;
        float minValue = 0.7;
        const FingerList fingers = hand.fingers();
        for (FingerList::const_iterator fl = fingers.begin(); fl != fingers.end(); ++fl) {
            const Leap::Finger finger = *fl;
            Leap::Vector bonesDirs[3];
            for(int j = 0 ; j < 3 ; ++j){
                Bone::Type boneType = static_cast<Bone::Type>(j);
                Bone bone = finger.bone(boneType);
                bonesDirs[j]= bone.direction();
            }
            sum += bonesDirs[0].dot(bonesDirs[1]);
            sum += bonesDirs[1].dot(bonesDirs[2]);
        }
        sum /= 10;
        if(sum <= minValue && getExtendedFingers(fl)){
            cout << "********************************************\n";
            cout << "********************************************\n";
            cout << "********************************************\n";
            cout << "********************************************\n";
            cout << "********************************************\n";
            cout << "********************************************\n";
            cout << "********************************************\n";
            cout << "Fist Detected-------------------------------\n";
            if(!flag) {
                system("google-chrome-stable");
                flag=1;
            }
        }
    }
}


void liftGesture(const Leap::Frame frame) {
    int numberHands = frame.hands().count();
    Leap::HandList hands = frame.hands();
    Leap::Vector palmNormals[2];
    Leap::Vector palmVelocities[2];
//    cout << "Number of Hands: " << numberHands << "\n";
//    cout << "La pinche normal" <<  (*hands.begin()).palmNormal()[0] << "\n";
    int cnt = 0;
    for(HandList::const_iterator hl = hands.begin() ; hl!= hands.end(); ++hl){
        const Hand hand = *hl;
        palmNormals[cnt] = hand.palmNormal();
        palmVelocities[cnt] = hand.palmVelocity();
        ++cnt;
    }
//    cout << "Normales de la Palma\n";
//    for(int j = 0 ; j < 2 ; ++j){
//        for(int i = 0 ;i < 3 ; ++i) {
//            cout << palmNormals[j][i] << " ";
//        }
//        cout << " roll: " << palmNormals[j].roll() << " ";
//        cout << "\n";
//    }
    if ((numberHands == 2) &&
        (palmNormals[0].roll() < 0.0f) && (palmNormals[1].roll() < 0.0f) &&
        (palmVelocities[0].z > 50.0f) && (palmVelocities[1].z > 50.0f) &&
        (palmVelocities[0].z < 300.0f) && (palmVelocities[1].z < 300.0f)) {
        cout << "****************************************\n";
        cout << "****************************************\n";
        cout << "****************************************\n";
        cout << "****************************************\n";
        cout << "****************************************\n";
        cout << "****************************************\n";
        cout << "****************************************\n";
        cout << "****************************************\n";
        cout << "****************************************\n";
        cout << "Lift Gesture detected\n";
    }
}

void getGestures(const Leap::Frame frame, const Leap::Controller controller){
// Get gestures
    const GestureList gestures = frame.gestures();
    for (int g = 0; g < gestures.count(); ++g) {
        Gesture gesture = gestures[g];

        switch (gesture.type()) {
            case Gesture::TYPE_CIRCLE:
            {
                CircleGesture circle = gesture;
                std::string clockwiseness;

                if (circle.pointable().direction().angleTo(circle.normal()) <= PI/2) {
                    clockwiseness = "clockwise";
                } else {
                    clockwiseness = "counterclockwise";
                }

                // Calculate angle swept since last frame
                float sweptAngle = 0;
                if (circle.state() != Gesture::STATE_START) {
                    CircleGesture previousUpdate = CircleGesture(controller.frame(1).gesture(circle.id()));
                    sweptAngle = (circle.progress() - previousUpdate.progress()) * 2 * PI;
                }
                std::cout << std::string(2, ' ')
                          << "Circle id: " << gesture.id()
                          << ", state: " << stateNames[gesture.state()]
                          << ", progress: " << circle.progress()
                          << ", radius: " << circle.radius()
                          << ", angle " << sweptAngle * RAD_TO_DEG
                          <<  ", " << clockwiseness << std::endl;
                break;
            }
            case Gesture::TYPE_SWIPE:
            {
                SwipeGesture swipe = gesture;
                std::cout << std::string(2, ' ')
                          << "Swipe id: " << gesture.id()
                          << ", state: " << stateNames[gesture.state()]
                          << ", direction: " << swipe.direction()
                          << ", speed: " << swipe.speed() << std::endl;
                break;
            }
            case Gesture::TYPE_KEY_TAP:
            {
                KeyTapGesture tap = gesture;
                std::cout << std::string(2, ' ')
                          << "Key Tap id: " << gesture.id()
                          << ", state: " << stateNames[gesture.state()]
                          << ", position: " << tap.position()
                          << ", direction: " << tap.direction()<< std::endl;
                break;
            }
            case Gesture::TYPE_SCREEN_TAP:
            {
                ScreenTapGesture screentap = gesture;
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
        }
    }
//    if (!frame.hands().isEmpty() || !gestures.isEmpty()) {
//        std::cout << std::endl;
//    }
}

void getHands(const Leap::Frame frame){
    HandList hands = frame.hands();
    for (HandList::const_iterator hl = hands.begin(); hl != hands.end(); ++hl) {
        // Get the first hand
        const Hand hand = *hl;
        std::string handType = hand.isLeft() ? "Left hand" : "Right hand";
        std::cout << std::string(2, ' ') << handType << ", id: " << hand.id()
                  << ", palm position: " << hand.palmPosition() << std::endl;
        // Get the hand's normal vector and direction
        const Vector normal = hand.palmNormal();
        const Vector direction = hand.direction();

        // Calculate the hand's pitch, roll, and yaw angles
        std::cout << std::string(2, ' ') <<  "pitch: " << direction.pitch() * RAD_TO_DEG << " degrees, "
                  << "roll: " << normal.roll() * RAD_TO_DEG << " degrees, "
                  << "yaw: " << direction.yaw() * RAD_TO_DEG << " degrees" << std::endl;

        // Get the Arm bone
        Arm arm = hand.arm();
        std::cout << std::string(2, ' ') <<  "Arm direction: " << arm.direction()
                  << " wrist position: " << arm.wristPosition()
                  << " elbow position: " << arm.elbowPosition() << std::endl;

        // Get fingers
        const FingerList fingers = hand.fingers();
        for (FingerList::const_iterator fl = fingers.begin(); fl != fingers.end(); ++fl) {
            const Finger finger = *fl;
            std::cout << std::string(4, ' ') <<  fingerNames[finger.type()]
                      << " finger, id: " << finger.id()
                      << ", length: " << finger.length()
                      << "mm, width: " << finger.width() << std::endl;

            // Get finger bones
            for (int b = 0; b < 4; ++b) {
                Bone::Type boneType = static_cast<Bone::Type>(b);
                Bone bone = finger.bone(boneType);
                std::cout << std::string(6, ' ') <<  boneNames[boneType]
                          << " bone, start: " << bone.prevJoint()
                          << ", end: " << bone.nextJoint()
                          << ", direction: " << bone.direction() << std::endl;
            }
        }
    }
}

void BaseListener::onFrame(const Leap::Controller& controller) {
    // Get the most recent frame and report some basic information
//    delay(100);
//    usleep(2000);
    const Leap::Frame frame = controller.frame();
//    std::cout << "Frame id: " << frame.id()
//              << ", timestamp: " << frame.timestamp()
//              << ", hands: " << frame.hands().count()
//              << ", extended fingers: " << frame.fingers().extended().count()
//              << ", tools: " << frame.tools().count()
//              << ", gestures: " << frame.gestures().count() << std::endl;
//    getHands(frame);
    getGestures(frame,controller);
    liftGesture(frame);
    checkFist(frame);
}

void BaseListener::onFocusGained(const Leap::Controller& ) {
    std::cout << "Focus Gained" << std::endl;
}

void BaseListener::onFocusLost(const Leap::Controller& controller) {
    std::cout << "Focus Lost" << std::endl;
}

void BaseListener::onDeviceChange(const Leap::Controller& controller) {
    std::cout << "Device Changed" << std::endl;
    const DeviceList devices = controller.devices();

    for (int i = 0; i < devices.count(); ++i) {
        std::cout << "id: " << devices[i].toString() << std::endl;
        std::cout << "  isStreaming: " << (devices[i].isStreaming() ? "true" : "false") << std::endl;
    }
}

void BaseListener::onServiceConnect(const Leap::Controller& controller) {
    std::cout << "Service Connected" << std::endl;
}

void BaseListener::onServiceDisconnect(const Leap::Controller& controller) {
    std::cout << "Service Disconnected" << std::endl;
}

int main(int argc, char** argv) {
    // Create a sample listener and controller
    BaseListener listener;
    Leap::Controller controller;

    // Have the sample listener receive events from the controller
    controller.addListener(listener);

    if (argc > 1 && strcmp(argv[1], "--bg") == 0)
        controller.setPolicy(Leap::Controller::POLICY_BACKGROUND_FRAMES);

    // Keep this process running until Enter is pressed
    std::cout << "Press Enter to quit..." << std::endl;
    std::cin.get();

    // Remove the sample listener when done
    controller.removeListener(listener);

    return 0;
}
