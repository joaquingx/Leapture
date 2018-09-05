//
// Created by joaquin on 30/08/18.
//

#include "listener.h"
#include "gestures.h"
//#include "state.h"

const std::string fingerNames[] = {"Thumb", "Index", "Middle", "Ring", "Pinky"};
const std::string boneNames[] = {"Metacarpal", "Proximal", "Middle", "Distal"};





// *****************************Pedefined Shit*************************************
// This method MUST exist!!!!(Constructor)
void BaseListener::onInit(const Leap::Controller& controller) {
    std::cout << "Initialization" << std::endl;
}

void BaseListener::onConnect(const Leap::Controller& controller) {
    std::cout << "Hardware and Software Connected!!!" << std::endl;
    controller.enableGesture(Leap::Gesture::TYPE_KEY_TAP);
    controller.enableGesture(Leap::Gesture::TYPE_SCREEN_TAP);
    controller.enableGesture(Leap::Gesture::TYPE_SWIPE);
}

void BaseListener::onDisconnect(const Leap::Controller& controller) {
    // Note: not dispatched when running in a debugger.
    std::cout << "Disconnected" << std::endl;
}

void BaseListener::onExit(const Leap::Controller& controller) {
    std::cout << "Exited" << std::endl;
}

void BaseListener::onFocusGained(const Leap::Controller& ) {
    std::cout << "Focus Gained" << std::endl;
}

void BaseListener::onFocusLost(const Leap::Controller& controller) {
    std::cout << "Focus Lost" << std::endl;
}

void BaseListener::onDeviceChange(const Leap::Controller& controller) {
    std::cout << "Device Changed" << std::endl;
    const Leap::DeviceList devices = controller.devices();

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
// *****************************Pedefined Shit*************************************



void BaseListener::onFrame(const Leap::Controller& controller) {
    OwnGestures Og;
    const Leap::Frame frame = controller.frame();
    Og.checkGestures(frame, controller);
}