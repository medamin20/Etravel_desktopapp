#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>

#include "reservationh.h"

enum
{    
          ID_DE_VOYAGEh,
          DESTINATIONh,
          DATE1h,
          DATE2h,
          NOMBRE_DE_PERSONNEh,
          PRIXh,
          COLUMNS
         };
void ajouter_reservationh(reserveh eh)
{
   FILE *f;
   f=fopen("reservationh.txt","a+");
if (f!=NULL)
{
 fprintf(f,"%s %s %s %s %s %s   \n",eh.id_de_voyageh,eh.destinationh,eh.date_deph,eh.date_arrh,eh.nombre_de_personneh,eh.prixh);
fclose(f);
}
}


void afficher_reservationh (GtkWidget *liste )
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
   
    GtkTreeIter  iter;
   
   GtkListStore *store;
 
char id_de_voyageh[30] ;
char destinationh[20];
char date_deph[20];
char date_arrh[20];
char nombre_de_personneh[15];
char prixh[10] ;
reserveh eh ;
   store=NULL ;
   FILE *f;
   store=gtk_tree_view_get_model(liste);
  if (store==NULL)
  {
     renderer = gtk_cell_renderer_text_new () ;
     column = gtk_tree_view_column_new_with_attributes("id_de_voyageh", renderer, "text", ID_DE_VOYAGEh,NULL);
     gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

renderer = gtk_cell_renderer_text_new () ;
     column = gtk_tree_view_column_new_with_attributes("destinationh", renderer, "text", DESTINATIONh,NULL);
     gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

renderer = gtk_cell_renderer_text_new () ;
     column = gtk_tree_view_column_new_with_attributes("date_deph", renderer, "text", DATE1h,NULL);
     gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

 renderer = gtk_cell_renderer_text_new () ;
     column = gtk_tree_view_column_new_with_attributes("date_arrh", renderer, "text", DATE2h,NULL);
     gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

renderer = gtk_cell_renderer_text_new () ;
     column = gtk_tree_view_column_new_with_attributes("nombre_de_personneh", renderer, "text", NOMBRE_DE_PERSONNEh,NULL);
     gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

renderer = gtk_cell_renderer_text_new () ;
     column = gtk_tree_view_column_new_with_attributes("prixh", renderer, "text", PRIXh,NULL);
     gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;



store = gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f = fopen("reservationh.txt","r");
if(f==NULL)
return;
else
{
f = fopen("reservationh.txt","a+");
while(fscanf(f,"%s %s %s %s %s %s \n",id_de_voyageh,destinationh,date_deph,date_arrh,nombre_de_personneh,prixh)!=EOF)
{
gtk_list_store_append (store,&iter);

gtk_list_store_set (store,&iter,ID_DE_VOYAGEh,id_de_voyageh,DESTINATIONh,destinationh,DATE1h,date_deph,DATE2h,date_arrh,NOMBRE_DE_PERSONNEh,nombre_de_personneh,PRIXh,prixh, -1);
}
 fclose(f);
 gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
 g_object_unref (store);
}
}
}


int rechercher_reservationh(reserveh eh,char id_de_voyageh[30])
{
FILE*f;
int t=0;

f=fopen("reservationh.txt","r+");
if(f!=NULL){
while(fscanf(f,"%s %s %s %s %s %s ",eh.id_de_voyageh,eh.destinationh,eh.date_deph,eh.date_arrh,eh.nombre_de_personneh,eh.prixh)!=EOF){
if(strcmp(id_de_voyageh,eh.id_de_voyageh)==0){
t++;
break;
}
}
}fclose(f);
return t;
}


void supprimer_reservationh(reserveh eh,char id_de_voyageh[30])
{
FILE*f;
FILE*t;

f=fopen("reservationh.txt","r+");
t=fopen("tmph.txt","w+");
if(f!=NULL){
while(fscanf(f,"%s %s %s %s %s %s ",eh.id_de_voyageh,eh.destinationh,eh.date_deph,eh.date_arrh,eh.nombre_de_personneh,eh.prixh)!=EOF){
if(strcmp(id_de_voyageh,eh.id_de_voyageh)!=0){
fprintf(t,"%s %s %s %s %s %s  \n",eh.id_de_voyageh,eh.destinationh,eh.date_deph,eh.date_arrh,eh.nombre_de_personneh,eh.prixh);
}
}
}fclose(t);
fclose(f);
remove("reservationh.txt");
rename("tmph.txt","reservationh.txt");
}


void modifier_reservationh(reserveh eh,char id_de_voyageh[30])
{

supprimer_reservationh(eh,id_de_voyageh);
ajouter_reservationh(eh);

}

reserveh rechercher_reseh (char id_voyageh[taille])
{
  FILE*notif;
 reserveh eh;
  notif=fopen("reservationh.txt","r"); // searching by JUST First and Last name
  while((fscanf(notif,"%s %s %s %s %s %s  ",eh.id_de_voyageh,eh.destinationh,eh.date_deph,eh.date_arrh,eh.nombre_de_personneh,eh.prixh)!=EOF))

    {
      if((strcmp(eh.id_de_voyageh,id_voyageh)==0)){
     return eh;
   }
 }

  fclose (notif);
  strcpy(eh.id_de_voyageh,"inexistant");
  strcpy(eh.destinationh,"inexistant");
  strcpy(eh.date_deph,"inexistant");
  strcpy(eh.date_arrh,"inexistant");
  strcpy(eh.nombre_de_personneh,"inexistant");
  strcpy(eh.prixh,"inexistant");
  
  
  return eh;
}


