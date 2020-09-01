#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "voiture.h"
#define ta 100


void afficher_voiture(GtkWidget *list)
{
int nbre=0,i=0,j;
  char jourchar[ta][ta],anneechar[ta][ta],jourchar1[ta][ta],anneechar1[ta][ta],codechar[ta][ta],moischar[ta][ta],moischar1[ta][ta] ;
   char *p[ta][7]={{" "," "," "," "," "," ", " ",}};
   voiture v[ta],vo;
FILE* text ;

text=fopen("voitures.txt","r");
    if(text!=NULL)
    {
      while((fscanf(text,"%d %s %d %s %d %s %d %s %d %s %s ",&vo.code,vo.marque,&vo.date_prise.jour,vo.date_prise.mois,&(vo.date_prise.annee),vo.heure,&(vo.date_rest.jour),vo.date_rest.mois,&(vo.date_rest.annee),vo.heure1,vo.prix)!=EOF))
      {
if(strcmp(vo.date_prise.mois,"Janvier")==0)
{
strcpy (v[i].date_prise.mois,"01") ;
}
else if(strcmp(vo.date_prise.mois,"Fevrier")==0)
{
strcpy (v[i].date_prise.mois,"02") ;
}
else if(strcmp(vo.date_prise.mois,"Mars")==0)
{
strcpy (v[i].date_prise.mois,"03") ;
}
else if(strcmp(vo.date_prise.mois,"Avril")==0)
{
strcpy (v[i].date_prise.mois,"04") ;
}
else if(strcmp(vo.date_prise.mois,"May")==0)
{
strcpy (v[i].date_prise.mois,"05") ;
}
else if(strcmp(vo.date_prise.mois,"Juin")==0)
{
strcpy (v[i].date_prise.mois,"06") ;
}
else if(strcmp(vo.date_prise.mois,"Juillet")==0)
{
strcpy (v[i].date_prise.mois,"07") ;
}
else if(strcmp(vo.date_prise.mois,"Aout")==0)
{
strcpy (v[i].date_prise.mois,"08") ;
}
else if(strcmp(vo.date_prise.mois,"Septembre")==0)
{
strcpy (v[i].date_prise.mois,"09") ;
}
else if(strcmp(vo.date_prise.mois,"Octobre")==0)
{
strcpy (v[i].date_prise.mois,"10") ;
}
else if(strcmp(vo.date_prise.mois,"Novembre")==0)
{
strcpy (v[i].date_prise.mois,"11") ;
}
else if(strcmp(vo.date_prise.mois,"Decembre")==0)
{
strcpy (v[i].date_prise.mois,"12") ;
}
if(strcmp(vo.date_rest.mois,"Janvier")==0)
{
strcpy (v[i].date_rest.mois,"01") ;
}
else if(strcmp(vo.date_rest.mois,"Fevrier")==0)
{
strcpy (v[i].date_rest.mois,"02") ;
}
else if(strcmp(vo.date_rest.mois,"Mars")==0)
{
strcpy (v[i].date_rest.mois,"03") ;
}
else if(strcmp(vo.date_rest.mois,"Avril")==0)
{
strcpy (v[i].date_rest.mois,"04") ;
}
else if(strcmp(vo.date_rest.mois,"May")==0)
{
strcpy (v[i].date_rest.mois,"05") ;
}
else if(strcmp(vo.date_rest.mois,"Juin")==0)
{
strcpy (v[i].date_rest.mois,"06") ;
}
else if(strcmp(vo.date_rest.mois,"Juillet")==0)
{
strcpy (v[i].date_rest.mois,"07") ;
}
else if(strcmp(vo.date_rest.mois,"Aout")==0)
{
strcpy (v[i].date_rest.mois,"08") ;
}
else if(strcmp(vo.date_rest.mois,"Septembre")==0)
{
strcpy (v[i].date_rest.mois,"09") ;
}
else if(strcmp(vo.date_rest.mois,"Octobre")==0)
{
strcpy (v[i].date_rest.mois,"10") ;
}
else if(strcmp(vo.date_rest.mois,"Novembre")==0)
{
strcpy (v[i].date_rest.mois,"11") ;
}
else if(strcmp(vo.date_rest.mois,"Decembre")==0)
{
strcpy (v[i].date_rest.mois,"12") ;
}
        v[i].code=vo.code ;
	strcpy(v[i].marque,vo.marque);
        v[i].date_prise.jour=vo.date_prise.jour;
        v[i].date_prise.annee=vo.date_prise.annee;
        strcpy(v[i].heure,vo.heure);
        v[i].date_rest.jour=vo.date_rest.jour;
        v[i].date_rest.annee=vo.date_rest.annee;
        strcpy(v[i].heure1,vo.heure1);
	strcpy(v[i].prix,vo.prix);
        i++;
      }
      nbre=i;
      fclose(text);
    }
	gtk_clist_clear(GTK_CLIST(list));
    for(i=0;i<nbre;i++)
    {
        snprintf(jourchar[i],20,"%d",v[i].date_prise.jour);
	
        snprintf(anneechar[i],20,"%d",v[i].date_prise.annee);
        
        snprintf(jourchar1[i],20,"%d",v[i].date_rest.jour);

        snprintf(anneechar1[i],20,"%d",v[i].date_rest.annee);

        snprintf(codechar[i],20,"%d",v[i].code);

    }
    for(i=0;i<nbre;i++)
    {
      strcat(jourchar[i]," / ");
      strcat(jourchar[i],v[i].date_prise.mois);
      strcat(jourchar[i]," / ");
      strcat(jourchar[i],anneechar[i]);
     
      strcat(jourchar1[i]," / ");
      strcat(jourchar1[i],v[i].date_rest.mois);
      strcat(jourchar1[i]," / ");
      strcat(jourchar1[i],anneechar1[i]);
    }
    for(j=0;j<nbre;j++)
    {
      gtk_clist_append(GTK_CLIST(list),p[j]);
    }
    gtk_clist_set_row_height(GTK_CLIST(list),30);

      for(i=0;i<nbre;i++){
        gtk_clist_set_text(GTK_CLIST(list),i,0,codechar[i]);
      }
      for(i=0;i<nbre;i++){
        gtk_clist_set_text(GTK_CLIST(list),i,1,v[i].marque);
      }
      for(i=0;i<nbre;i++){
        gtk_clist_set_text(GTK_CLIST(list),i,2,jourchar[i]);
      }
      for(i=0;i<nbre;i++){
        gtk_clist_set_text(GTK_CLIST(list),i,3,v[i].heure);
      }
	for(i=0;i<nbre;i++){
	gtk_clist_set_text(GTK_CLIST(list),i,4,jourchar1[i]);
      }
	for(i=0;i<nbre;i++){
	gtk_clist_set_text(GTK_CLIST(list),i,5,v[i].heure1);
      }
for(i=0;i<nbre;i++){
	gtk_clist_set_text(GTK_CLIST(list),i,6,v[i].prix);
      }
}

void ajouter_voiture (voiture v)
{
FILE* f;
voiture vo;
int id=900 ;
f=fopen("voitures.txt","r");
vo.code=v.code;
strcpy(vo.marque,v.marque);
vo.date_prise.jour=v.date_prise.jour;
strcpy(vo.date_prise.mois,v.date_prise.mois);
vo.date_prise.annee=v.date_prise.annee;
strcpy(vo.heure,v.heure);
vo.date_rest.jour=v.date_rest.jour;
strcpy(vo.date_rest.mois,v.date_rest.mois);
vo.date_rest.annee=v.date_rest.annee;
strcpy(vo.heure1,v.heure1);
strcpy(vo.prix,v.prix);

while (fscanf(f,"%d %s %d %s %d %s %d %s %d %s %s\n ",&v.code,v.marque,&v.date_prise.jour,v.date_prise.mois,&v.date_prise.annee,v.heure,&v.date_rest.jour,v.date_rest.mois,&v.date_rest.annee,v.heure1,v.prix)!=EOF)
{
id=v.code;
}
fclose(f);
f=fopen("voitures.txt","a+");
if(f!=NULL)
{
fprintf(f,"%d %s %d %s %d %s %d %s %d %s %s\n ",id+1,vo.marque,vo.date_prise.jour,vo.date_prise.mois,vo.date_prise.annee,vo.heure,vo.date_rest.jour,vo.date_rest.mois,vo.date_rest.annee,vo.heure1,vo.prix);
fclose(f);
}
}

int verifier_code_voiture(voiture v,int code)
{
FILE*f;
int k=0;
f=fopen("voitures.txt","r+");
if(f!=NULL){
while(fscanf(f,"%d %s %d %s %d %s %d %s %d %s %s ",&v.code,v.marque,&v.date_prise.jour,v.date_prise.mois,&v.date_prise.annee,v.heure,&v.date_rest.jour,v.date_rest.mois,&v.date_rest.annee,v.heure1,v.prix)!=EOF)
{
if(v.code==code){
k++;
break;
}

}
}fclose(f);
return k ;
}

void supprimer_voiture(voiture v,int code)
{
FILE*f;
FILE*g;
f=fopen("voitures.txt","r+");
g=fopen("tmp.txt","w+");
if(g!=NULL){
while(fscanf(f,"%d %s %d %s %d %s %d %s %d %s %s ",&v.code,v.marque,&v.date_prise.jour,v.date_prise.mois,&v.date_prise.annee,v.heure,&v.date_rest.jour,v.date_rest.mois,&v.date_rest.annee,v.heure1,v.prix)!=EOF)
{
if(v.code!=code){
fprintf(g,"%d %s %d %s %d %s %d %s %d %s %s ",v.code,v.marque,v.date_prise.jour,v.date_prise.mois,v.date_prise.annee,v.heure,v.date_rest.jour,v.date_rest.mois,v.date_rest.annee,v.heure1,v.prix);

}
}
}fclose(f);
fclose(g);
remove("voitures.txt");
rename("tmp.txt","voitures.txt");
}
void modifier_voiture(voiture v,int code)
{

supprimer_voiture(v,code);
ajouter_voiture(v);

}

void set_marque (GtkWidget *input , char ch1[])
{
if(strcmp(ch1,"BMW3Series")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(input),0);
}
else if (strcmp(ch1,"AudiQ5")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(input),1);
}
else if (strcmp(ch1,"RenautMeganeEstate")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(input),2);
}
else if (strcmp(ch1,"Peugeot208")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(input),3);
}
else if (strcmp(ch1,"CitroenC3")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(input),4);
}
else if (strcmp(ch1,"OpelAstra")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(input),5);
}
else if (strcmp(ch1,"FordFocus")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(input),6);
}
else if (strcmp(ch1,"VolkswagenGolf")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(input),7);
}
}

void set_mois (GtkWidget *input , char ch1[])
{
if(strcmp(ch1,"Janvier")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(input),0);
}
else if (strcmp(ch1,"Fevrier")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(input),1);
}
else if (strcmp(ch1,"Mars")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(input),2);
}
else if (strcmp(ch1,"Avril")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(input),3);
}
else if (strcmp(ch1,"May")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(input),4);
}
else if (strcmp(ch1,"Juin")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(input),5);
}
else if (strcmp(ch1,"Juillet")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(input),6);
}
else if (strcmp(ch1,"Aout")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(input),7);
}
else if (strcmp(ch1,"Septembre")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(input),8);
}
else if (strcmp(ch1,"Octobre")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(input),9);
}
else if (strcmp(ch1,"Novembre")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(input),10);
}
else if (strcmp(ch1,"Decembre")==0)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(input),11);
}
}





