#include <gtk/gtk.h>

static int count = 0;
  
 static void increment (GtkWidget *widget,
             gpointer   data)
             {
				 count = count + 1;
				 g_print ("%d", count);
			 }


static void
activate (GtkApplication* app,
          gpointer        user_data)
{
  GtkWidget *window;
  
  GtkWidget *button;
  GtkWidget *button_box;

  GtkWidget *label;
  
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Counter");
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);
  
  button_box = gtk_button_box_new (GTK_ORIENTATION_VERTICAL);
  gtk_container_add (GTK_CONTAINER (window), button_box);
  printf("%d",count);
  label = gtk_label_new("Count: ");
  gtk_container_add (GTK_CONTAINER (button_box), label);


  button = gtk_button_new_with_label ("Increment");
  g_signal_connect (button, "clicked", G_CALLBACK (increment), NULL);
  gtk_container_add (GTK_CONTAINER (button_box), button);

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
