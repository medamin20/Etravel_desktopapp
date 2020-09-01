#include <stdio.h>
#include <string.h>
#include "addvol.h"
#include <gtk/gtk.h>

enum
{
	CODE,
	DATE,
	HEURE,
	DEPART,
	ARRIVEE,
	PRIX,
	PLACESDISPO,
	COLUMNS
};

void ajouter_vol(vol v)
{

 FILE *f;
 f=fopen("vol.txt","a+");
 if(f!=NULL)
 {
 fprintf(f,"%s %s %s %s %s %s %s \n",v.code01,v.date01,v.heure01,v.depart01,v.arrivee01,v.prix01,v.placedis01);
 fclose(f);
 }

}


void afficher_vol(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;


char code01[30];
char date01 [30];
char heure01 [30];
char depart01 [30];
char arrivee01 [30];
char prix01[30];
char placedis01 [30];
store =NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("code01",renderer,"text",CODE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("date01",renderer,"text",DATE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("heure01",renderer,"text",HEURE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("depart01",renderer,"text",DEPART,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("arrivee01",renderer,"text",ARRIVEE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("prix01",renderer,"text",PRIX,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("placedis01",renderer,"text",PLACESDISPO,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("vol.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	
	{ 
	f=fopen("vol.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s \n",code01,date01,heure01,depart01,arrivee01,prix01,placedis01)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,CODE,code01,DATE,date01,HEURE,heure01,DEPART,depart01,ARRIVEE,arrivee01,PRIX,prix01,PLACESDISPO,placedis01,-1);
		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
	}
}
}




void chercher_vol(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;


char code01[30];
char date01 [30];
char heure01 [30];
char depart01 [30];
char arrivee01 [30];
char prix01[30];
char placedis01 [30];
store =NULL;

FILE *f2;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("code01",renderer,"text",CODE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("date01",renderer,"text",DATE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("heure01",renderer,"text",HEURE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("depart01",renderer,"text",DEPART,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("arrivee01",renderer,"text",ARRIVEE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("prix01",renderer,"text",PRIX,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("placedis01",renderer,"text",PLACESDISPO,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f2=fopen("chercher.txt","r");

	if(f2==NULL)
	{
		return;
	}
	else
	
	{ 
	f2=fopen("chercher.txt","a+");
		while(fscanf(f2,"%s %s %s %s %s %s %s \n",code01,date01,heure01,depart01,arrivee01,prix01,placedis01)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,CODE,code01,DATE,date01,HEURE,heure01,DEPART,depart01,ARRIVEE,arrivee01,PRIX,prix01,PLACESDISPO,placedis01,-1);
		}
	   fclose(f2);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
	}
}
}
