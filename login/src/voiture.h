#include <gtk/gtk.h>

typedef struct 
{
int jour ;
char mois[15] ;
int annee ;
}date ;
typedef struct
{

int code ; 
char marque[20] ;
date date_prise ;
date date_rest ;
char prix[10] ;
char heure[15] ;
char heure1[15] ;
}voiture;

void afficher_voiture(GtkWidget *list) ;
void ajouter_voiture (voiture v) ;
int verifier_code_voiture(voiture v,int code) ;
void supprimer_voiture(voiture v,int code) ;
void modifier_voiture(voiture v,int code) ;
void set_marque (GtkWidget *input , char ch1[]) ;
void set_mois (GtkWidget *input , char ch1[]) ;
