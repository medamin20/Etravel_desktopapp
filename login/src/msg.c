#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "msg.h"
#define TAILLE1 256
#define t 100

void afficher_recla(GtkWidget *list) 
{

int nbre=0,i=0,j;
 char jourchar[TAILLE1][TAILLE1], anneechar[TAILLE1][TAILLE1];
   char *p[t][5]={{" "," "," "," "," "}};
   recla SMS[TAILLE1], N;
  FILE *f;

f=fopen("msg.txt","r");
    if(f!=NULL)
    {
      while((fscanf(f,"%s %s %s %s %d %s %d ",N.id,N.nom10,N.prenom10,N.objet,&N.d.jour,N.d.mois,&N.d.annee)!=EOF) &&(fgets(N.message,100,f)!=NULL))
      {
        if(strcmp(N.d.mois,"Janvier")==0)
{
strcpy (SMS[i].d.mois,"01") ;
}
else if(strcmp(N.d.mois,"Fevrier")==0)
{
strcpy (SMS[i].d.mois,"02") ;
}
else if(strcmp(N.d.mois,"Mars")==0)
{
strcpy (SMS[i].d.mois,"03") ;
}
else if(strcmp(N.d.mois,"Avril")==0)
{
strcpy (SMS[i].d.mois,"04") ;
}
else if(strcmp(N.d.mois,"May")==0)
{
strcpy (SMS[i].d.mois,"05") ;
}
else if(strcmp(N.d.mois,"Juin")==0)
{
strcpy (SMS[i].d.mois,"06") ;
}
else if(strcmp(N.d.mois,"Juillet")==0)
{
strcpy (SMS[i].d.mois,"07") ;
}
else if(strcmp(N.d.mois,"Aout")==0)
{
strcpy (SMS[i].d.mois,"08") ;
}
else if(strcmp(N.d.mois,"Septembre")==0)
{
strcpy (SMS[i].d.mois,"09") ;
}
else if(strcmp(N.d.mois,"Octobre")==0)
{
strcpy (SMS[i].d.mois,"10") ;
}
else if(strcmp(N.d.mois,"Novembre")==0)
{
strcpy (SMS[i].d.mois,"11") ;
}
else if(strcmp(N.d.mois,"Decembre")==0)
{
strcpy (SMS[i].d.mois,"12") ;
}

        strcpy(SMS[i].id,N.id);
        strcpy(SMS[i].nom10,N.nom10);
          strcpy(SMS[i].prenom10,N.prenom10);
        strcpy(SMS[i].objet,N.objet);
        SMS[i].d.jour=N.d.jour;
        SMS[i].d.annee=N.d.annee;
        i++;
 
      }
 
      nbre=i;

    }fclose(f);
    gtk_clist_clear(GTK_CLIST(list));
    for(i=0;i<nbre;i++)
    {
      snprintf(jourchar[i],20,"%d",SMS[i].d.jour);
      snprintf(anneechar[i],20,"%d",SMS[i].d.annee);
    }
    for(i=0;i<nbre;i++)
    {
      strcat(jourchar[i],"/");
      strcat(jourchar[i],SMS[i].d.mois);
      strcat(jourchar[i],"/");
      strcat(jourchar[i],anneechar[i]);
}

for(j=0;j<nbre;j++)
    {
      gtk_clist_append(GTK_CLIST(list),p[j]);
    }
    gtk_clist_set_row_height(GTK_CLIST(list),30);
      for(i=0;i<nbre;i++){
        gtk_clist_set_text(GTK_CLIST(list),i,0,SMS[i].id);
      }
      for(i=0;i<nbre;i++){
        gtk_clist_set_text(GTK_CLIST(list),i,1,SMS[i].nom10);
      }
      for(i=0;i<nbre;i++){
        gtk_clist_set_text(GTK_CLIST(list),i,2,SMS[i].prenom10);
      }
      for(i=0;i<nbre;i++){
        gtk_clist_set_text(GTK_CLIST(list),i,3,SMS[i].objet);
      }
      for(i=0;i<nbre;i++){
        gtk_clist_set_text(GTK_CLIST(list),i,4,jourchar[i]);
      }

}


recla rechercher_message(char id_message[t])
{
  FILE* f;
  recla N;
  f=fopen("msg.txt","r");
  while((fscanf(f,"%s %s %s %s %d %s %d ",N.id,N.nom10,N.prenom10,N.objet,&N.d.jour,N.d.mois,&N.d.annee)!=EOF)&&(fgets(N.message,100,f)!=NULL))
    {
      if((strcmp(N.id,id_message)==0)){
     return N;
   }
 }

  fclose (f);
  strcpy(N.id,"inexistant");
  strcpy(N.nom10,"inexistant");
  strcpy(N.prenom10,"inexistant");
  strcpy(N.objet,"inexistant");
  strcpy(N.message,"inexistant");
  N.d.jour=1;
  strcpy(N.d.mois,"01");
  N.d.annee=2019;
  return N;
}


void supprimer_message(char id_message[taille])
{
    recla N;
    
      FILE *notif=fopen("msg.txt","r");
      FILE *nouv_notif=fopen("msg_temp.txt","w");
      if(notif!=NULL)
      {
while((fscanf(notif,"%s %s %s %s %d %s %d ",N.id,N.nom10,N.prenom10,N.objet,&N.d.jour,N.d.mois,&N.d.annee)!=EOF)&&(fgets(N.message,100,notif)!=NULL))
  {
    if(strcmp(N.id,id_message)!=0)
    {
  fprintf(nouv_notif,"%s %s %s %s %d %s %d %s",N.id,N.nom10,N.prenom10,N.objet,&N.d.jour,N.d.mois,&N.d.annee,N.message);
}
}
}
      fclose(nouv_notif);
      fclose(notif);
        remove("msg.txt");
        rename("msg_temp.txt","msg.txt");
}




