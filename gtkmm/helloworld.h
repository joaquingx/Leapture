#ifndef GTKMM_EXAMPLE_HELLOWORLD_H
#define GTKMM_EXAMPLE_HELLOWORLD_H

#include "examplewindow.h"
#include <stdlib.h>     /* srand, rand */
#include <gtkmm/button.h>
#include <gtkmm/window.h>

class HelloWorld : public Gtk::Window
{

public:
  HelloWorld();
  virtual ~HelloWorld();
  ExampleWindow* examplewindow;

protected:
  //Signal handlers:
  void on_button_clicked();


  void on_changed(std::string);

  //Member widgets:
  Gtk::Box m_VBox;
  Gtk::Entry m_entry;
  Gtk::Button m_button;

  std::string  data;
};

#endif // GTKMM_EXAMPLE_HELLOWORLD_H