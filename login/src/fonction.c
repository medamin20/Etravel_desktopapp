#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include "fonction.h"


enum
{

        CODE,
	NOM,
	PRENOM,
	CARTE,
	MONTANT,
	COLUMNS
};

void ajouter_facture(facture f)
{

FILE *g;
facture h;
int i=0;
g=fopen("factures.txt","r");
strcpy(h.nom,f.nom);
strcpy(h.prenom,f.prenom);
strcpy(h.carte,f.carte);
strcpy(h.montant,f.montant);
h.code=f.code;
while (fscanf(g,"%d %s %s %s %s\n",&f.code,f.nom,f.prenom,f.carte,f.montant)!=EOF)
{i=f.code;}
fclose(g);
g=fopen("factures.txt","a+");
if(g!=NULL)
{
fprintf(g,"%d %s %s %s %s\n",i+1,h.nom,h.prenom,h.carte,h.montant);
fclose(g);
}
}

void afficher_facture(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter	iter;
GtkListStore *store;

int code;
char nom[30];
char prenom[30];
char num_carte_credit[30];
char montant[10];
store=NULL;

FILE *g;

store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
        renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("code", renderer, "text",CODE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text",NOM, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("prenom", renderer, "text",PRENOM, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("num_carte_credit", renderer, "text",CARTE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("montant", renderer, "text",MONTANT, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	

store=gtk_list_store_new (COLUMNS, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING);
g=fopen("factures.txt", "r");
if(g==NULL)
{
return;
}
else
{ g = fopen("factures.txt","a+");
	while(fscanf(g,"%d %s %s %s %s\n",&code,nom,prenom,num_carte_credit,montant)!=EOF)
	{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,CODE,code,NOM, nom,PRENOM, prenom, CARTE, num_carte_credit,MONTANT, montant, -1);
	}
	fclose(g);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
	g_object_unref (store);
}
}
}


int verifier_code(facture f,int code)
{
FILE*g;
int t=0;
g=fopen("factures.txt","r+");
if(g!=NULL){
while(fscanf(g,"%d %s %s %s %s",&f.code,f.nom,f.prenom,f.carte,f.montant)!=EOF){
if(f.code==code){
t++;
break;
}
}
}fclose(g);
return t ;
}


void supprimer_facture(facture f,int code)
{
FILE*g;
FILE*t;
g=fopen("factures.txt","r+");
t=fopen("tmp.txt","w+");
if(g!=NULL){
while(fscanf(g,"%d %s %s %s %s",&f.code,f.nom,f.prenom,f.carte,f.montant)!=EOF){
if(f.code!=code){
fprintf(t,"%d %s %s %s %s \n",f.code,f.nom,f.prenom,f.carte,f.montant);

}
}
}fclose(g);
fclose(t);
remove("factures.txt");
rename("tmp.txt","factures.txt");
}


void modifier_facture(facture f,int code)
{

supprimer_facture(f,code);
ajouter_facture(f);

}


