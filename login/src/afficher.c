#include <stdio.h>
#include <string.h>
#include "afficher.h"
#include <gtk/gtk.h>
  
enum 
{ 
   NOM,
   PRENOM,
   DATENAISS,
   ADRESSEEMAIL,
   NUMTEL,
   DATEREC,
   ADRESSE,
   COLUMNS
};
void afficher_agent(GtkWidget *liste)
{
 GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter iter;
 GtkListStore *store;
 char nom[20];
 char prenom[30];
 char datenaiss[30];
 char adresseemail[10];
 char numtel[10];
 char daterec[30];
 char adresse[10];
store=NULL;
 FILE *f; 
 store=gtk_tree_view_get_model(liste);
 if (store==NULL)
{

   renderer=gtk_cell_renderer_text_new();
   column= gtk_tree_view_column_new_with_attributes("nom",renderer, "text",NOM,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
 
   renderer=gtk_cell_renderer_text_new();
   column= gtk_tree_view_column_new_with_attributes(" prenom",renderer, "text",PRENOM,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
  
   renderer=gtk_cell_renderer_text_new();
   column= gtk_tree_view_column_new_with_attributes(" datenaiss",renderer, "text",DATENAISS,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
   
   renderer=gtk_cell_renderer_text_new();
   column= gtk_tree_view_column_new_with_attributes(" adresseemail",renderer, "text",ADRESSEEMAIL,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
   
   renderer=gtk_cell_renderer_text_new();
   column= gtk_tree_view_column_new_with_attributes(" numtel",renderer, "text",NUMTEL,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
  
   renderer=gtk_cell_renderer_text_new();
   column= gtk_tree_view_column_new_with_attributes(" daterec",renderer, "text",DATEREC,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

   renderer=gtk_cell_renderer_text_new();
   column= gtk_tree_view_column_new_with_attributes(" adresse",renderer, "text",ADRESSE,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
}
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("agent.txt", "r");
if(f==NULL)
{
 return;
}
else 
{ f=fopen("agent.txt", "a+");
    while(fscanf(f,"%s %s %s %s %s %s %s \n",nom,prenom,datenaiss,adresseemail,numtel,daterec,adresse)!=EOF)
     {
gtk_list_store_append (store,&iter);
gtk_list_store_set (store,&iter,NOM,nom,PRENOM,prenom,DATENAISS,datenaiss,ADRESSEEMAIL,adresseemail,NUMTEL,numtel,DATEREC,daterec,ADRESSE,adresse, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}




void chercher_agent(GtkWidget *liste)
{
 GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter iter;
 GtkListStore *store;
 char nom[20];
 char prenom[30];
 char datenaiss[30];
 char adresseemail[10];
 char numtel[10];
 char daterec[30];
 char adresse[10];
store=NULL;
 FILE *f2; 
 store=gtk_tree_view_get_model(liste);
 if (store==NULL)
{

   renderer=gtk_cell_renderer_text_new();
   column= gtk_tree_view_column_new_with_attributes("nom",renderer, "text",NOM,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
 
   renderer=gtk_cell_renderer_text_new();
   column= gtk_tree_view_column_new_with_attributes(" prenom",renderer, "text",PRENOM,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
  
   renderer=gtk_cell_renderer_text_new();
   column= gtk_tree_view_column_new_with_attributes(" datenaiss",renderer, "text",DATENAISS,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
   
   renderer=gtk_cell_renderer_text_new();
   column= gtk_tree_view_column_new_with_attributes(" adresseemail",renderer, "text",ADRESSEEMAIL,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
   
   renderer=gtk_cell_renderer_text_new();
   column= gtk_tree_view_column_new_with_attributes(" numtel",renderer, "text",NUMTEL,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
  
   renderer=gtk_cell_renderer_text_new();
   column= gtk_tree_view_column_new_with_attributes(" daterec",renderer, "text",DATEREC,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

   renderer=gtk_cell_renderer_text_new();
   column= gtk_tree_view_column_new_with_attributes(" adresse",renderer, "text",ADRESSE,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
}
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f2=fopen("chercher.txt", "r");
if(f2==NULL)
{
 return;
}
else 
{ f2=fopen("chercher.txt", "a+");
    while(fscanf(f2,"%s %s %s %s %s %s %s \n",nom,prenom,datenaiss,adresseemail,numtel,daterec,adresse)!=EOF)
     {
gtk_list_store_append (store,&iter);
gtk_list_store_set (store,&iter,NOM,nom,PRENOM,prenom,DATENAISS,datenaiss,ADRESSEEMAIL,adresseemail,NUMTEL,numtel,DATEREC,daterec,ADRESSE,adresse, -1);
}
fclose(f2);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}

