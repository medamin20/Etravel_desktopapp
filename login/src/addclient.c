#include <stdio.h>
#include <string.h>
#include "addclient.h"
#include <gtk/gtk.h>



enum
{
	CIN,
	NOM,
	PRENOM,
	ADRESS,
	LOGIN,
	PASSWORD,
	TELEPHONE,
	COLUMNS
};

void ajouter_personne(personne p)
{

 FILE *f;
 f=fopen("client.txt","a+");
 if(f!=NULL)
 {
 fprintf(f,"%s %s %s %s %s %s %s\n",p.Cin01,p.Nom01,p.Prenom01,p.Adressmail01,p.Login01,p.Passworld01,p.Telephone01);
 fclose(f);
 }

}

void afficher_personne(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char Cin01 [30];
char Nom01 [30];
char Prenom01 [30];
char Adressmail01 [30];
char Login01 [30];
char Passworld01 [30];
char Telephone01 [30];
store =NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Cin01",renderer,"text",CIN,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Nom01",renderer,"text",NOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Prenom01",renderer,"text",PRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Adressmail01",renderer,"text",ADRESS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Login01",renderer,"text",LOGIN,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Passworld01",renderer,"text",PASSWORD,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Telephone01",renderer,"text",TELEPHONE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	
	

	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("client.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	
	{ 
	f=fopen("client.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s \n",Cin01,Nom01,Prenom01,Adressmail01,Login01,Passworld01,Telephone01)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,CIN,Cin01,NOM,Nom01,PRENOM,Prenom01,ADRESS,Adressmail01,LOGIN,Login01,PASSWORD,Passworld01,TELEPHONE,Telephone01,-1);
		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
	}
}
}

int vermaj(char text[8])
{int i,e=0;
for(i=0;i<strlen(text);i++)
if (text[i]>='9' || text[i]<='0')
e=1;
if (e==0)
return 1;
else return 0;
}

