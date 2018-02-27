/* GTK3 Application That Makes A File
 * 
 * 
 * */

#include <gtk/gtk.h>
#include <fcntl.h>
#include <stdlib.h>

struct data {
    GtkWidget *entry;
};

void button_cb(GtkButton *button, struct data *mydata)
	{
		
		//GSList *radio_list = mydata->radio_list; 
		GtkWidget *entry;
		entry = mydata->entry;
		
		const gchar *entry_text;
		entry_text = gtk_entry_get_text (GTK_ENTRY (entry));
		
		g_print("%s",entry_text);
		
		int idx = 0;
   
		char* extension;
		
		if (idx == 0) 
			extension=".html";
		else if (idx == 1)
			extension=".css";
		else if (idx == 2)
			extension=".js";
		else 
			extension=".txt";
			
		g_print("%s", extension);
	

			
		/* GtkEntry *entry = (GtkEntry *) data;
		 const gchar *entry_text;
		 entry_text = gtk_entry_get_text (GTK_ENTRY (entry));
		 g_print ("Entry contents: %s\n", entry_text);
		 int filedesc = open(entry_text, O_WRONLY | O_APPEND | O_CREAT, S_IWUSR | S_IRUSR);
		 if(filedesc < 0)
			return;
			
		 write(filedesc,"\n", 1);
		 */
	}


static void
activate (GtkApplication* app,
          gpointer        user_data)
{
	struct data mydata;
    GtkWidget *window, *button, *button_box, *entry, *box, *radio1, *radio2, *radio3;
  
	box = gtk_box_new (GTK_ORIENTATION_VERTICAL, 2);
	gtk_box_set_homogeneous (GTK_BOX (box), TRUE);
  
	radio1 = gtk_radio_button_new_with_label (NULL, "HTML");
	
	radio2 = gtk_radio_button_new_with_label_from_widget (GTK_RADIO_BUTTON (radio1),
                                                         "CSS");
                                                         
	radio3 = gtk_radio_button_new_with_label_from_widget (GTK_RADIO_BUTTON (radio1),"JS");
  
	window = gtk_application_window_new (app);
	gtk_window_set_title (GTK_WINDOW (window), "FileMaker");
	gtk_window_set_default_size (GTK_WINDOW (window), 400, 200);
  
	button_box = gtk_button_box_new (GTK_ORIENTATION_VERTICAL);
	gtk_container_add (GTK_CONTAINER (window), button_box);

	entry = gtk_entry_new ();
	gtk_container_add (GTK_CONTAINER (button_box), entry);

	gtk_box_pack_start (GTK_BOX (box), radio1, TRUE, TRUE, 0);
	gtk_box_pack_start (GTK_BOX (box), radio2, TRUE, TRUE, 0);
	gtk_box_pack_start (GTK_BOX (box), radio3, TRUE, TRUE, 0);

	gtk_container_add (GTK_CONTAINER (button_box), box);

	mydata.entry = entry;
	//const gchar *entry_text;
//	entry_text = gtk_entry_get_text (GTK_ENTRY (entry));
//	mydata.radio_list = gtk_radio_button_get_group ((GtkRadioButton *)radio1);
//	mydata.entry = (gchar*)entry_text;
    
	button = gtk_button_new_with_label ("Make File");
	g_signal_connect (button, "clicked", (GCallback) button_cb, &mydata);
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
