#include "Windows.h"

#include <iostream>


Wellcome::Wellcome(){


  this->set_border_width(10);

  // Load and display the image
  m_image.set("../thanos.gif");
  m_grid.attach(m_image,0,0,1,1);

  // Add the Quit button
  m_button.add_label("Open");
  m_button.signal_pressed().connect(sigc::mem_fun(*this,&Wellcome::on_button_clicked));
  signal_key_press_event().connect(sigc::mem_fun(*this, &Wellcome::on_key_press), false);

  m_grid.attach(m_button,0,2,1,1);

  // Display the main grid in the main window
  m_grid.show_all();

  // Insert the grid in the main window
  add(m_grid);

}

Wellcome::~Wellcome(){

}

bool Wellcome::on_key_press(GdkEventKey* event){

  hide();
  return false;
}


void Wellcome::on_button_clicked(){
  
  hide();
    // this->hold();
  // listview1 = new ListView(data);
  // listview1->show();
  // std::cout << "Hello World" << std::endl;
  // std::string data=m_entry.get_text();
    // on_changed(data);

}


// void Wellcome::on_changed(std::string data){
  
//   if(this->data!=data){

//     std::cout << "Changed" << std::endl;
//     std::cout<< data <<std::endl;
//     // this->hold();    
//     listview1 = new ListView(data);

//     listview1->show();

//   }

// }

ListView::ListView(std::string data): m_VBox(

  Gtk::ORIENTATION_VERTICAL), m_Button_Quit("Quit"){
  set_title("Gtk::List View");
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
  m_Button_Quit.signal_clicked().connect( sigc::mem_fun(*this,&ListView::on_button_quit) );
  signal_key_press_event().connect(sigc::mem_fun(*this, &ListView::on_key_press), false);

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

ListView::~ListView(){
}

bool ListView::on_key_press(GdkEventKey* event){

    std::cout << event->keyval << ' ' << event->hardware_keycode << std::endl;

    if (event->hardware_keycode == 36){//36 => enter
      
      this->hide();
      
      listview2 = new ListView("otro");
      listview2->show();
      }

    return false;
}

void ListView::on_button_quit(){

  hide();
}


