//
// Created by joaquin on 21/09/18.
//

//TODO: Display thanos image

#include "window.h"
#include <iostream>


//HelloWorld::HelloWorld(): m_VBox(Gtk::ORIENTATION_VERTICAL), m_button("Close")
window::window(){
}

void window::initialDisplay() {
    cleanBox(); // works??
//    hide();
    this->set_border_width(10);

    // Load and display the image
    m_image.set("../thanos.gif");
    m_grid.attach(m_image,10,10,1,1);

    // Add the Quit button
    m_button->add_label("Open");
    m_button->signal_clicked().connect(sigc::mem_fun(*this,&window::on_button_clicked));

    m_grid.attach((*m_button),0,2,1,1);

    // Display the main grid in the main window
    m_grid.show_all();

    // Insert the grid in the main window
    add(m_grid);
//    m_button.hide();
}


void window::secondDisplay(vector<string> data) {
    cleanBox();
//    hide();
//    add(m_grid);
    m_VBox = Gtk::Box(Gtk::ORIENTATION_VERTICAL);
    delete(m_button);
    m_button =  new Gtk::Button("Thanos Fist");
//    m_Button_Quit = Gtk::Button("Quit");
    set_title("Gtk::List View");
    set_border_width(5);
    set_default_size(400, 200);

    add(m_VBox);


    //Add the TreeView, inside a ScrolledWindow, with the button underneath:
    m_ScrolledWindow.add(m_TreeView);

    //Only show the scrollbars when they are necessary:
    m_ScrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

    m_VBox.pack_start(m_ScrolledWindow);
    m_VBox.pack_start((*m_button), Gtk::PACK_SHRINK);
//    m_VBox.pack_start(m_ButtonBox, Gtk::PACK_SHRINK);

//    m_ButtonBox.pack_start((*m_button), Gtk::PACK_SHRINK);
//    m_ButtonBox.set_border_width(5);
//    m_ButtonBox.set_layout(Gtk::BUTTONBOX_END);
    m_button->signal_clicked().connect( sigc::mem_fun(*this,&window::on_button_clicked) );
//    signal_key_press_event().connect(sigc::mem_fun(*this, &ListView::on_key_press), false);

    //Create the Tree model:
    m_refTreeModel = Gtk::ListStore::create(m_Columns);
    m_TreeView.set_model(m_refTreeModel);

    //Fill the TreeView's model
    Gtk::TreeModel::Row row;

    for(int i = 0 ;i < data.size() ; ++i){
        row = *(m_refTreeModel->append());
        row[m_Columns.m_col_name] = data[i];
        row[m_Columns.m_description] = "";
    }


    m_TreeView.append_column("", m_Columns.m_col_name);
    m_TreeView.append_column("", m_Columns.m_description);

    show_all_children();
}

// to display another windwo
bool window::cleanBox() {
//    this->m_VBox = new GTK:
    remove();
////    hide();
//    this->m_grid.hide();
//    this->m_button.hide();
//    this->m_VBox.hide();
    this->m_VBox = Gtk::Box(Gtk::ORIENTATION_VERTICAL);
    this->m_grid = Gtk::Grid();
    this->m_ScrolledWindow = Gtk::ScrolledWindow();
    this->m_refTreeModel = Glib::RefPtr<Gtk::ListStore>();
    this->m_TreeView = Gtk::TreeView();
    this->m_button = new Gtk::Button();
    this->m_ButtonBox = Gtk::ButtonBox();
}

window::~window() {
//    hide()
}

void window::on_button_clicked() {
    if(currentState == sxhkd ) {
        data.clear();
        data.push_back("Bind Gesture with Command");
        data.push_back("Use Application");
        currentState = Principal;
        this->secondDisplay(data);
    }
    if(currentState == Binder){
        string selected = getSelected();
        cout << gesture << " is vinculated with " <<  selected << "\n";
        bindMap[sxhkd][gesture] = selected;
        data.clear();
        data.push_back("Bind Gesture with Command");
        data.push_back("Use Application");
        currentState = Principal;
        this->secondDisplay(data);
    }

    if(currentState == Free){
        data.clear();
        cout << "Clickeaste papurri\n" << gesture << "\n";
        string pretty = "Gesture detected is " + gesture;
        if(!bindMap[sxhkd].count(gesture)){
            pretty += "| Not bound yet";
        }
        else{
            pretty += "| Bound with " + bindMap[sxhkd][gesture];
        }

        if(gesture == "Double-Fist" or gesture == "Chavo"){
            pretty += " | WARNING: This bound would break Interface workflow!";
        }
        data.push_back(pretty);
        data.push_back("oneko");
        data.push_back("google-chrome-stable");
        data.push_back("emacs");
        data.push_back("bspc desktop -f prev");
        data.push_back("termite");
        data.push_back("xdotool key Super+w");
        data.push_back("ffplay -nodisp /home/joaquin/Downloads/Duki-Rockstar.mp3 -ss 4 -t 3.41");
        data.push_back("bspc node -f prev");
        this->secondDisplay(data);
        currentState = Binder;
    }
    if(currentState == Principal){
        string selected = getSelected();
        if(selected == "Bind Gesture with Command"){
            currentState = Free;
            data.clear();
            data.push_back("Waiting for Gesture");
            secondDisplay(data);
//            cleanBox();
//            this->m_button = new Gtk::Button();
//            m_button->signal_clicked().connect( sigc::mem_fun(*this,&window::on_button_clicked) );
//            show_all_children();
        }
        else if(selected == "Use Application"){
            currentState = sxhkd;
            data.clear();
            data.push_back("Waiting for Gesture");
            secondDisplay(data);
        }
//        cout << "Hace tiempo que no te veo!:" << getSelected() << "\n";
    }
    if(currentState == Begin) {
        cout << "veretera\n";
        data.clear();
        data.push_back("Bind Gesture with Command");
        data.push_back("Use Application");
        currentState = Principal;
        this->secondDisplay(data);
    }


}

string window::getSelected() {
    Glib::RefPtr<Gtk::TreeSelection> selection = m_TreeView.get_selection();
    Gtk::TreeModel::iterator selectedRow = selection->get_selected();
    Gtk::TreeModel::Row row = *selectedRow;
    Glib::ustring port = row.get_value(m_Columns.m_col_name);
    return port.data();
}

void window::setGesture(string gesture) {
    this->gesture =gesture;
}

bool window::hideBox() {
    hide();
}





//
//bool ListView::on_key_press(GdkEventKey* event){
//
//    std::cout << event->keyval << ' ' << event->hardware_keycode << std::endl;
//
//    if (event->hardware_keycode == 36){//36 => enter
//
//        this->hide();
//
//        listview2 = new ListView("otro");
//        listview2->show();
//    }
//
//    return false;
//}
//
//void ListView::on_button_quit(){
//
//    hide();
//}



