#include <stdio.h>
#include <string.h>
#include "clientfid.h"
#include <gtk/gtk.h>
  
enum 
{ 
   NOM,
   PRENOM,
   DATENAISS,
   ADRESSEEMAIL,
   NUMTEL,
   CODE,
   COLUMNS
};
void afficher_clientfid(GtkWidget *liste)
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
char code[10];
 store=NULL;
 FILE *f4; 
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
   column= gtk_tree_view_column_new_with_attributes(" code",renderer, "text",CODE,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

  }
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING , G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f4=fopen("clientfidele.txt", "r");
if(f4==NULL)
{
 return;
}
else 
{ f4=fopen("clientfidele.txt", "a+");
    while(fscanf(f4,"%s %s %s %s %s %s\n",nom,prenom,datenaiss,adresseemail,numtel, code)!=EOF)
     {
gtk_list_store_append (store,&iter);
gtk_list_store_set (store,&iter,NOM,nom,PRENOM,prenom,DATENAISS,datenaiss,ADRESSEEMAIL,adresseemail,NUMTEL,numtel,CODE,code, -1);
}
fclose(f4);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}

