#ifndef INTERFACE_H
#define INTERFACE_H


#include "Windows.h"
#include <iostream>
#include <gtkmm.h>


class Interface
{
public:
	Interface(int argc, char *argv[]);
	~Interface();

	Wellcome* wellcome;

	ListView* listView1;
	Glib::RefPtr<Gtk::Application> app;
};

#endif


