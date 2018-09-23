//
// Created by joaquin on 22/09/18.
//

#ifndef LEAPGESTURES_INTER_H
#define LEAPGESTURES_INTER_H

#include "window.h"
#include <iostream>
#include <gtkmm.h>


class VisInterface
{
public:
    VisInterface(int argc, char *argv[]);
    ~VisInterface();
    void runInterface();
    window * wellcome;
    Glib::RefPtr<Gtk::Application> app;
    bool setClick();
    bool setGesture(string gesture);
    size_t getDataSize();
};

#endif //LEAPGESTURES_INTER_H
