//image and button

#include <gtk/gtk.h>

static void myButtonClicked(GtkWidget *widget, gpointer   data)
{
    g_print("Button clicked: ShortCut  GTK+\n");
}

int main(int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *myImage;
    GtkWidget *myButton;
    GtkWidget *myPaned;



    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 500);

    gtk_window_set_title(GTK_WINDOW(window), "Shortcut LeapMotion");
    
    myPaned = gtk_paned_new(GTK_ORIENTATION_VERTICAL);


    myImage = gtk_image_new_from_file ("images.jpeg");//poner imagen
    

    myButton = gtk_button_new_with_label("Start");

    g_signal_connect(myButton, "clicked", 
        G_CALLBACK(myButtonClicked), NULL);

    g_signal_connect (window, "destroy", 
        G_CALLBACK(gtk_main_quit), NULL);

    gtk_paned_add1 (GTK_PANED(myPaned), myImage);
    gtk_paned_add2 (GTK_PANED(myPaned), myButton);

    gtk_container_add(GTK_CONTAINER (window), myPaned);
    gtk_widget_show_all (window);

    gtk_main();
    return(0);
}