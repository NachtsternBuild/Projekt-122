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
 *              Headerfile					 *
 *											 *
 *-------------------------------------------*
 */

#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>

#ifndef FLASHHEADER_H
#define FLASHHEADER_H

void flashrecoveryfunction();
void flashboot();
void flashvendor();
void flashvendorboot();
void flashsystem();
void flashpayload();
void flashvbmeta();

#endif