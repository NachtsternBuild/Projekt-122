/*
 *-------------------------------------------*
 *                Projekt 122                *
 *-------------------------------------------*
 *  	Apache License, Version 2.0		     *
 *-------------------------------------------*
 *                                           *
 *  Programm um das installieren von 		 *
 *	Custom-ROM und GSIs auf Android-Geräte 	 *
 *	zu erleichtern  						 *
 *                                           *
 *-------------------------------------------*
 *      (C) Copyright 2023 Elias Mörz 		 *
 *-------------------------------------------*
 *											 *
 *              flashvbmeta					 *
 *											 *
 *-------------------------------------------*
 */
 
/* headers that used in the main programm */
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include "flashheader.h"

// function to flash vbmeta.img
void flashvbmetafunction()
{
    GtkWidget *dialog;
    char message[512];

    // Show a message that the flash is starting
    snprintf(message, sizeof(message), "Starte Flash des vbmeta.img...\n");
    showMessage(message);

    // Show the device list
    system("fastboot devices");
    
	// flash vbmeta.img
    system("fastboot flash --disable-verity --disable-verification vbmeta ~/Downloads/ROM-Install/vbmeta.img");

    // Show a message that the flash is completed
    snprintf(message, sizeof(message), "Flash beendet!\n");
    showMessage(message);
}

// button clicked callback
void buttonfvb_clicked(GtkWidget *widget, gpointer data)
{
    flashvbmetafunction();
}

// UI for flashsystem
void flashvbmeta(int argc, char *argv[])
{
    // Initialize GTK
    gtk_init(&argc, &argv);

    // Create the main window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Flash vbmeta");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 200);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Create a vertical box
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Create an entry for entering the filename
    GtkWidget *entry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(vbox), entry, FALSE, FALSE, 5);

    // Create a button
    GtkWidget *button = gtk_button_new_with_label("Flash vbmeta.img");
    g_signal_connect(button, "clicked", G_CALLBACK(buttonfvb_clicked), entry);
    gtk_box_pack_start(GTK_BOX(vbox), button, FALSE, FALSE, 5);

    // Show all the widgets
    gtk_widget_show_all(window);

    // Run the GTK main loop
    gtk_main();
}