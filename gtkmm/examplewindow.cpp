#include <iostream>
#include "examplewindow.h"

ExampleWindow::ExampleWindow(std::string data)
: m_VBox(Gtk::ORIENTATION_VERTICAL),
  m_Button_Quit("Quit")
{
  set_title("Gtk::TreeView (ListStore) example");
  set_border_width(5);
  set_default_size(400, 200);

  add(m_VBox);

  //Add the TreeView, inside a ScrolledWindow, with the button underneath:
  m_ScrolledWindow.add(m_TreeView);

  //Only show the scrollbars when they are necessary:
  m_ScrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

  m_VBox.pack_start(m_ScrolledWindow);
  m_VBox.pack_start(m_ButtonBox, Gtk::PACK_SHRINK);

  m_ButtonBox.pack_start(m_Button_Quit, Gtk::PACK_SHRINK);
  m_ButtonBox.set_border_width(5);
  m_ButtonBox.set_layout(Gtk::BUTTONBOX_END);
  m_Button_Quit.signal_clicked().connect( sigc::mem_fun(*this,
              &ExampleWindow::on_button_quit) );
  signal_key_press_event().connect(sigc::mem_fun(*this, &ExampleWindow::on_key_press), false);


  //Create the Tree model:
  m_refTreeModel = Gtk::ListStore::create(m_Columns);
  m_TreeView.set_model(m_refTreeModel);

  //Fill the TreeView's model
  Gtk::TreeModel::Row row = *(m_refTreeModel->append());
  
  
//  Aqui puede ser un for para llenar mas datos
  row[m_Columns.m_col_name] = data;
  row[m_Columns.m_description] = "this is a description";
  /*
  
  // row = *(m_refTreeModel->append()); //para agregar mas
  
  */


  m_TreeView.append_column("Name", m_Columns.m_col_name);
  m_TreeView.append_column("Description", m_Columns.m_description);

  
  show_all_children();
}

ExampleWindow::~ExampleWindow()
{
}

bool ExampleWindow::on_key_press(GdkEventKey* event)
{
    std::cout << event->keyval << ' ' << event->hardware_keycode << std::endl;


    if (event->hardware_keycode == 36){//36 => enter
      examplewindow = new ExampleWindow("otro");
      examplewindow->show();
        }

    return false;
}

void ExampleWindow::on_button_quit()
{
  hide();
}
