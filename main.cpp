#include <iostream>
#include <cstring>
#include "Leap.h"
#include <unistd.h>
#include "listener.h"

using namespace Leap;
using namespace std;

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
