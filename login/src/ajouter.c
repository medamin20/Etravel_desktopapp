#include <stdio.h>
#include <string.h>
#include "ajouter.h"
#include <gtk/gtk.h>
  

 void ajouter_agent(agent p)
{
 FILE *f; 
 f=fopen("agent.txt","a+");
 if(f!=NULL)
 {
 fprintf(f,"%s %s %s %s %s %s %s \n",p.nom,p.prenom,p.datenaiss,p.adresseemail,p.numtel,p.daterec,p.adresse);
 fclose(f);
}
}
void modifier_agent(agent p)
{
 FILE *f; 
 f=fopen("agent.txt","a+");
 if(f!=NULL)
 {
 fprintf(f,"%s %s %s %s %s %s %s \n",p.nom,p.prenom,p.datenaiss,p.adresseemail,p.numtel,p.daterec,p.adresse);
 fclose(f);
}
}
char est_nombre_entier (const char *s) {
  int i ;
  char res = 1 ; /* true */

  for (i=0 ; i<strlen(s) && res ; i++)
    if (!isdigit(s[i]))
      res = 0 ; /* false */

  return res ;
}
