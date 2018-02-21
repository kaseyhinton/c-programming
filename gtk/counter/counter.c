/* GTK3 Application That Counts To 100
 * 
 * 
 * */

#include <gtk/gtk.h>
#include <string.h>

static int count = 0;

 static void increment (GtkWidget *widget,
             gpointer   data)
             {
				 count += 1;
				 char text[7] = "count: ";
				 char buffer[255];
				 int buffer_size;
				 
				 buffer_size = 255;
				 snprintf(buffer, buffer_size, "%i", count);

				 strcat(text, buffer);
				 
				 if (count < 10)
					text[8] = '\0';
				else if (count < 100)
					text[9] = '\0';
				else if (count == 100)
					text[10] = '\0';
				else
					return;
				 
				 GtkWidget *label = (GtkWidget *) data;
				 gtk_label_set_text (GTK_LABEL(label), text);
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

  char text[7] = "count: ";
  char buffer[8];
  snprintf(buffer, 2, "%i", count);
  strcat(text, buffer);
  text[8] = '\0';
  label = gtk_label_new(text);
  gtk_container_add (GTK_CONTAINER (button_box), label);

  button = gtk_button_new_with_label ("Increment");
  g_signal_connect (button, "clicked", G_CALLBACK (increment), label);
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
