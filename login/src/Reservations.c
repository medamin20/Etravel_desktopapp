#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>

#include "reservations.h"

enum
{    
          ID_DE_VOYAGE,
          DESTINATION,
          DATE1,
          DATE2,
          NOMBRE_DE_PERSONNE,
          PRIX,
          COLUMNS
         };
void ajouter_reservations(reserve e)
{
   FILE *f;
   f=fopen("reservations.txt","a+");
if (f!=NULL)
{
 fprintf(f,"%s %s %s %s %s %s   \n",e.id_de_voyage,e.destination,e.date_dep,e.date_arr,e.nombre_de_personne,e.prix);
fclose(f);
}
}


void afficher_reservations (GtkWidget *liste )
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
   
    GtkTreeIter  iter;
   
   GtkListStore *store;
 
char id_de_voyage[30] ;
char destination[20];
char date_dep[20];
char date_arr[20];
char nombre_de_personne[15];
char prix[10] ;
reserve e ;
   store=NULL ;
   FILE *f;
   store=gtk_tree_view_get_model(liste);
  if (store==NULL)
  {
     renderer = gtk_cell_renderer_text_new () ;
     column = gtk_tree_view_column_new_with_attributes("id_de_voyage", renderer, "text", ID_DE_VOYAGE,NULL);
     gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

renderer = gtk_cell_renderer_text_new () ;
     column = gtk_tree_view_column_new_with_attributes("destination", renderer, "text", DESTINATION,NULL);
     gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

renderer = gtk_cell_renderer_text_new () ;
     column = gtk_tree_view_column_new_with_attributes("date_dep", renderer, "text", DATE1,NULL);
     gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

 renderer = gtk_cell_renderer_text_new () ;
     column = gtk_tree_view_column_new_with_attributes("date_arr", renderer, "text", DATE2,NULL);
     gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

renderer = gtk_cell_renderer_text_new () ;
     column = gtk_tree_view_column_new_with_attributes("nombre_de_personne", renderer, "text", NOMBRE_DE_PERSONNE,NULL);
     gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

renderer = gtk_cell_renderer_text_new () ;
     column = gtk_tree_view_column_new_with_attributes("prix", renderer, "text", PRIX,NULL);
     gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;



store = gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f = fopen("reservations.txt","r");
if(f==NULL)
return;
else
{
f = fopen("reservations.txt","a+");
while(fscanf(f,"%s %s %s %s %s %s \n",id_de_voyage,destination,date_dep,date_arr,nombre_de_personne,prix)!=EOF)
{
gtk_list_store_append (store,&iter);

gtk_list_store_set (store,&iter,ID_DE_VOYAGE,id_de_voyage,DESTINATION,destination,DATE1,date_dep,DATE2,date_arr,NOMBRE_DE_PERSONNE,nombre_de_personne,PRIX,prix, -1);
}
 fclose(f);
 gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
 g_object_unref (store);
}
}
}


int rechercher_reservations(reserve e,char id_de_voyage[30])
{
FILE*f;
int t=0;

f=fopen("reservations.txt","r+");
if(f!=NULL){
while(fscanf(f,"%s %s %s %s %s %s ",e.id_de_voyage,e.destination,e.date_dep,e.date_arr,e.nombre_de_personne,e.prix)!=EOF){
if(strcmp(id_de_voyage,e.id_de_voyage)==0){
t++;
break;
}
}
}fclose(f);
return t;
}


void supprimer_reservations(reserve e,char id_de_voyage[30])
{
FILE*f;
FILE*t;

f=fopen("reservations.txt","r+");
t=fopen("tmp.txt","w+");
if(f!=NULL){
while(fscanf(f,"%s %s %s %s %s %s ",e.id_de_voyage,e.destination,e.date_dep,e.date_arr,e.nombre_de_personne,e.prix)!=EOF){
if(strcmp(id_de_voyage,e.id_de_voyage)!=0){
fprintf(t,"%s %s %s %s %s %s  \n",e.id_de_voyage,e.destination,e.date_dep,e.date_arr,e.nombre_de_personne,e.prix);
}
}
}fclose(t);
fclose(f);
remove("reservations.txt");
rename("tmp.txt","reservations.txt");
}


void modifier_reservations(reserve e,char id_de_voyage[30])
{

supprimer_reservations(e,id_de_voyage);
ajouter_reservations(e);

}

reserve rechercher_rese (char id_voyage[taille])
{
  FILE*notif;
 reserve e;
  notif=fopen("reservations.txt","r"); // searching by JUST First and Last name
  while((fscanf(notif,"%s %s %s %s %s %s  ",e.id_de_voyage,e.destination,e.date_dep,e.date_arr,e.nombre_de_personne,e.prix)!=EOF))

    {
      if((strcmp(e.id_de_voyage,id_voyage)==0)){
     return e;
   }
 }

  fclose (notif);
  strcpy(e.id_de_voyage,"inexistant");
  strcpy(e.destination,"inexistant");
  strcpy(e.date_dep,"inexistant");
  strcpy(e.date_arr,"inexistant");
  strcpy(e.nombre_de_personne,"inexistant");
  strcpy(e.prix,"inexistant");
  
  
  return e;
}


