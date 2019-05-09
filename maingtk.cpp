#include <iostream>
#include <gtk/gtk.h>

#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500

static void printHello (GtkWidget *widget, gpointer data) {
  using  namespace std;

  cout << "New Window BTW :)" << endl;

  GtkWidget *window;
  GtkWidget *label;

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL); 
  gtk_window_set_title (GTK_WINDOW (window), "New Window");
  gtk_window_set_default_size (GTK_WINDOW (window), WINDOW_WIDTH, WINDOW_HEIGHT);

  label = gtk_label_new("Hello AGANE BRUH <3");
  gtk_container_add(GTK_CONTAINER(window), label);
  
  gtk_widget_show_all (window);
}


static void
activate (GtkApplication* app,
          gpointer        user_data)
{
  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *button_box;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Testing");
  gtk_window_set_default_size (GTK_WINDOW (window), WINDOW_WIDTH, WINDOW_HEIGHT);

  button_box = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
  gtk_container_add(GTK_CONTAINER(window), button_box);

  button = gtk_button_new_with_label("Hello World!");

  g_signal_connect(button, "clicked", G_CALLBACK(printHello), NULL);
  //g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_destroy), window);
  gtk_container_add(GTK_CONTAINER(button_box), button);

  gtk_widget_show_all (window);
}

int
main (int    argc,
      char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}

