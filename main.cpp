#include <iostream>
#include <cstring>
#include "Leap.h"
#include <unistd.h>
#include "listener.h"
#include "interface.h"
#include "state.h"

using namespace Leap;
using namespace std;

int main(int argc, char** argv) {
    // Create a sample listener and controller
//    State * currentState;
//    currentState->setCurrentState(State::states::Begin);
    Leap::Controller controller;
    VisualInterface * interface = new VisualInterface();
    BaseListener listener(interface);
        // Have the sample listener receive events from the controller
    controller.addListener(listener);

    interface->startDisplay();
//    currentState = Begin;
    // It gains focus over other processes
    currentState = Principal;
    interface->player();
    states lastCurrent = currentState;
 //    while(true){
//        if(lastCurrent != currentState){
//            cout << "I got it\n";
//        }
//        lastCurrent = currentState;
//    }
    if (argc > 1 && strcmp(argv[1], "--bg") == 0)
        controller.setPolicy(Leap::Controller::POLICY_BACKGROUND_FRAMES);

    // Keep this process running until Enter is pressed
    std::cout << "Press Enter to quit..." << std::endl;
    std::cin.get();

    // Remove the sample listener when done
    controller.removeListener(listener);

    return 0;
}


