//
// Created by joaquin on 21/09/18.
//

#ifndef LEAPGESTURES_WINDOW_H
#define LEAPGESTURES_WINDOW_H

#include <stdlib.h>     /* srand, rand */
//#include <gtkmm/button.h>
//#include <gtkmm/window.h>
//#include <gtkmm/box.h>
//#include <gtkmm/entry.h>
//#include <gtkmm/grid.h>
#include <gtkmm.h>
#include <vector>
#include "state.h"
using namespace std;

class ModelColumns : public Gtk::TreeModel::ColumnRecord{

public:

    ModelColumns(){ add(m_col_name); add(m_description);}

    Gtk::TreeModelColumn<Glib::ustring> m_col_name;
    Gtk::TreeModelColumn<std::string> m_description;

};

class window : public Gtk::Window
{
public:
    vector<string> data;
    ModelColumns m_Columns;
    window();
    virtual ~window();
    void initialDisplay();
    void secondDisplay(vector<string> data);
    string getSelected();
    //Signal handlers:
    bool cleanBox();
//protected:
    void on_button_clicked();
    void on_changed(vector<string> data);
    //Member widgets:
    Gtk::Box m_VBox;
    Gtk::Entry m_entry;
    Gtk::Button m_button;
    Gtk::Image m_image;
    Gtk::Grid m_grid;

//listview
    Gtk::ScrolledWindow m_ScrolledWindow;
    Gtk::TreeView m_TreeView;
    Glib::RefPtr<Gtk::ListStore> m_refTreeModel;

    Gtk::ButtonBox m_ButtonBox;
    Gtk::Button m_Button_Quit;

    string gesture;
    void setGesture(string gesture);

//palgesto
};


#endif //LEAPGESTURES_INTER_H
