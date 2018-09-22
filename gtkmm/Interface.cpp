#include "Interface.h"
#include <gtkmm.h>

Interface::Interface(int argc, char *argv[]){

	app = Gtk::Application::create(argc,argv,"org.gtkmm.example");

	wellcome = new Wellcome();
	listView1 = new ListView("Luis");

	app->run(*wellcome);
	
	app = Gtk::Application::create(argc,argv,"org.gtkmm.example");

	app->run(*listView1);





}


Interface::~Interface(){

}