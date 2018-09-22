#ifndef WINDOWS_H
#define WINDOWS_H

#include <stdlib.h>     /* srand, rand */
#include <gtkmm.h>

class ListView;


class Wellcome : public Gtk::Window
{

  public:
    Wellcome();
    virtual ~Wellcome();
    ListView* listview1;

  protected:
    //Signal handlers:
    void on_button_clicked();
    void on_changed(std::string);
    bool on_key_press(GdkEventKey* event);

    //Member widgets:
    Gtk::Image m_image;
    Gtk::Grid m_grid;
    Gtk::Button m_button;

    std::string  data;

};


class ListView : public Gtk::Window{

  public:
    ListView(std::string data);
    virtual ~ListView();
    ListView* listview2;
    
  protected:
    void on_button_quit();
    bool on_key_press(GdkEventKey* event);
  //Signal handlers:


  //Tree model columns:
  class ModelColumns : public Gtk::TreeModel::ColumnRecord{

  public:

    ModelColumns(){ add(m_col_name); add(m_description);}

    Gtk::TreeModelColumn<Glib::ustring> m_col_name;
    Gtk::TreeModelColumn<std::string> m_description;

  };

  ModelColumns m_Columns;

  //Child widgets:
  Gtk::Box m_VBox;

  Gtk::ScrolledWindow m_ScrolledWindow;
  Gtk::TreeView m_TreeView;
  Glib::RefPtr<Gtk::ListStore> m_refTreeModel;

  Gtk::ButtonBox m_ButtonBox;
  Gtk::Button m_Button_Quit;

};


#endif // WINDOWS_H