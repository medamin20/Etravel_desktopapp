#include <stdio.h>
#include <string.h>
#include "reservation.h"
#include "callbacks.h"
#include <gtk/gtk.h>

enum
{

	DES,
	DEP,
	HE,
	ARR,
	HEE,
	COLUMNS
};

void ajouter_reservation(reservation r)
{

FILE *f;
f=fopen("reservation.txt","a+");
	if(f!=NULL)
	{
	fprintf(f,"%s %s %s %s %s\n",r.des,r.dep,r.he,r.arr,r.hee);
fclose(f);
	}
}


void afficher_reservation(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter	iter;
GtkListStore *store;

char des[50];
char dep[50];
char he[20];
char arr[50];
char hee[20];
store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("DESCRIPTION", renderer, "text",DES, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("DATE DEPART", renderer, "text",DEP, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("HEURE ", renderer, "text",HE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("DATE ARRIVER", renderer, "text",ARR, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("HEURE ", renderer, "text",HEE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("reservation.txt", "r");
if(f==NULL)
{
return;
}
else
{ f = fopen("reservation.txt","a+");
	while(fscanf(f,"%s %s %s %s %s\n",des,dep,he,arr,hee)!=EOF)
	{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,DES, des ,DEP, dep,HE, he, ARR, arr ,HEE, hee , -1);
	}
	fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
	g_object_unref (store);
}
}
}
