#include <iostream>
#include <cstring>
#include "Leap.h"
#include <unistd.h>
#include "listener.h"
#include "interface.h"
#include "state.h"
#include "gestures.h"
#include "window.h"
#include "inter.h"

using namespace Leap;
using namespace std;

int main(int argc, char** argv) {

    VisInterface * itfc = new VisInterface(1,argv);


    Leap::Controller controller;
//    VisualInterface * interface = new VisualInterface();
    BaseListener listener(itfc);
            // Have the sample listener receive events from the controller
    controller.addListener(listener);

    itfc->runInterface();


    if (argc > 1 && strcmp(argv[1], "--bg") == 0)
        controller.setPolicy(Leap::Controller::POLICY_BACKGROUND_FRAMES);

    std::cout << "Press Enter to quit..." << std::endl;
    std::cin.get();

    // Remove the sample listener when done
    controller.removeListener(listener);
    return 0;
}


