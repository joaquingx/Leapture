//
// Created by joaquin on 22/09/18.
//

#include "inter.h"

VisInterface::VisInterface(int argc, char **argv) {
    app = Gtk::Application::create(argc,argv,"org.gtkmm.example");
    this->wellcome = new window();
    vector<string> p; p.push_back("Punito");
    this->wellcome->secondDisplay(p);
    cout << "quefuepnana\n";
}


bool VisInterface::setClick() {
    if(wellcome->m_button != NULL)
        wellcome->m_button->clicked();
}

void VisInterface::runInterface() {
    app->run(*wellcome);
}

size_t VisInterface::getDataSize() {
    return wellcome->data.size();
}

bool VisInterface::setGesture(string gesture) {
    wellcome->setGesture(gesture);
    return true;
}

VisInterface::~VisInterface() {
//    app->main
}
