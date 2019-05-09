#include <iostream>
#include <gtk/gtk.h>
#include <string>

#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500

GtkWidget *form_login;
GtkWidget *form_pswd;
GtkWidget *form_submit;

std::string login_str;
std::string pswd_str;

static void testPrint(GtkWidget *widget, gpointer data) {
	using namespace std;
	cout << "Submit Clicked!" << endl;
	cout << gtk_entry_get_text(GTK_ENTRY(form_login)) << endl;
	cout << gtk_entry_get_text(GTK_ENTRY(form_pswd)) << endl;
}

static void
activate (GtkApplication* app,
          gpointer        user_data)
{
  GtkBuilder *builder;
  GtkWidget *window;

  builder = gtk_builder_new();
  gtk_builder_add_from_file(builder, "testing.glade", NULL); 

  window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
  gtk_builder_connect_signals(builder, NULL);
  gtk_window_set_title (GTK_WINDOW (window), "Testing");

  form_login = GTK_WIDGET(gtk_builder_get_object(builder, "login_form_login"));
  form_pswd = GTK_WIDGET(gtk_builder_get_object(builder, "login_form_pswd"));
  form_submit = GTK_WIDGET(gtk_builder_get_object(builder, "login_form_submit_btn"));

  g_signal_connect(form_submit, "clicked", G_CALLBACK(testPrint), NULL);
 
  g_object_unref(builder);
  gtk_widget_show(window);
  gtk_main();
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

