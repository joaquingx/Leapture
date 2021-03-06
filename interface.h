#ifndef LEAPGESTURES_INTERFACE_H
#define LEAPGESTURES_INTERFACE_H

#include <gtk/gtk.h>
#include <string>
using namespace std;

class VisualInterface{
    enum {

        LIST_ITEM = 0,
        N_COLUMNS
    };
    void init_list(GtkWidget *list);
    void add_to_list(GtkWidget *list, const gchar *str);
    static void on_changed(GtkWidget *widget, gpointer label);
    static bool key_event(GtkWidget *widget, GdkEventKey *event, gpointer label);

  public:
    void player();
    void startDisplay();
    void createGesture(const gchar *gestureDetected);
};

#endif //LEAPGESTURES_INTERFACE_H
