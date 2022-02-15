#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

//gcc -o arguments arguments.cpp  `pkg-config gtk+-2.0 --cflags --libs`

int errorss;
char labels[50*50];
GtkWidget *entry2;
GtkWidget *entry;
char argsvv[1000];
char argsv[1000];
char *argsvvv;
static void enter_callback() 
                            
{
  const gchar *entry_text;
  
  entry_text = gtk_entry_get_text (GTK_ENTRY (entry));
  sprintf(argsvvv,"%s",entry_text);
  errorss=-1;
  system(argsvvv);
  if (errorss!=-1) gtk_entry_set_text (GTK_ENTRY (entry2),"error!!!!");
}

int main( int   argc,
          char *argv[] )
{

    GtkWidget *window;
    GtkWidget *vbox, *hbox;
    GtkWidget *button;
    GtkWidget *check;
    GdkColor color;
    gint tmp_pos;
	argsvvv=&argsvv[0];
    gtk_init (&argc, &argv);
	argsv[0]=0;
	if(argc>1){
		strcpy(argsv,argv[1]);
		strcat(argsv," ");
	}
    /* create a new window */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gdk_color_parse ("#1010FF", &color);
    gtk_widget_set_size_request (GTK_WIDGET (window), 600, 100);
    gtk_window_set_title (GTK_WINDOW (window), "run arguments");
    g_signal_connect (window, "destroy",
                      G_CALLBACK (gtk_main_quit), NULL);
    g_signal_connect_swapped (window, "delete-event",
                              G_CALLBACK (gtk_widget_destroy), 
                              window);

    vbox = gtk_vbox_new (FALSE, 0);
    gtk_container_add (GTK_CONTAINER (window), vbox);
    gtk_widget_show (vbox);

    entry = gtk_entry_new ();
    entry2 = gtk_entry_new ();
    gtk_entry_set_max_length (GTK_ENTRY (entry), 550);
    gtk_entry_set_max_length (GTK_ENTRY (entry2), 550);
    g_signal_connect (entry, "activate",
		      G_CALLBACK (enter_callback),
		      entry);
    gtk_entry_set_text (GTK_ENTRY (entry), argsv);
    gtk_entry_set_text (GTK_ENTRY (entry2), " ");
    tmp_pos = GTK_ENTRY (entry)->text_length;
    tmp_pos = GTK_ENTRY (entry2)->text_length;
    gtk_editable_insert_text (GTK_EDITABLE (entry), "", -1, &tmp_pos);
    gtk_editable_insert_text (GTK_EDITABLE (entry2), "", -1, &tmp_pos);
    gtk_editable_select_region (GTK_EDITABLE (entry),
			        0, GTK_ENTRY (entry)->text_length);
    gtk_editable_select_region (GTK_EDITABLE (entry2),
			        0, GTK_ENTRY (entry2)->text_length);
    gtk_box_pack_start (GTK_BOX (vbox), entry, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vbox), entry2, TRUE, TRUE, 0);
    gtk_widget_show (entry);
    gtk_widget_show (entry2);

    hbox = gtk_hbox_new (FALSE, 0);
    gtk_container_add (GTK_CONTAINER (vbox), hbox);
    gtk_widget_show (hbox);
   
                                 
    button = gtk_button_new_with_label ("run");
    g_signal_connect_swapped (button, "clicked",
			      G_CALLBACK (enter_callback),
			     entry);
    gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);
    gtk_widget_set_can_default (button, TRUE);
    gtk_widget_grab_default (button);
    gtk_widget_show (button);
    
    gtk_widget_show (window);
    //---------------
	gtk_widget_modify_bg ( GTK_WIDGET(window), GTK_STATE_NORMAL, &color);
	gtk_widget_modify_bg ( GTK_WIDGET(button), GTK_STATE_NORMAL, &color);
	gtk_widget_modify_bg ( GTK_WIDGET(entry), GTK_STATE_NORMAL, &color);
	gtk_widget_modify_bg ( GTK_WIDGET(entry2), GTK_STATE_NORMAL, &color);
    gtk_widget_modify_bg ( GTK_WIDGET(vbox), GTK_STATE_NORMAL, &color);
    gtk_main();

    return 0;
}
