#ifndef MESSAGE_H
#define MESSAGE_H
#define taille 256
#define taille_date 20
typedef struct dater
{
  int jour;
  char mois[taille_date];
  int annee;
}Date_Recla;

typedef struct reclamations
{
  char id[taille] ;
  char nom10[taille];
  char prenom10[taille];
  char objet[taille];
  char message[taille] ;
  Date_Recla d;
}recla;


void afficher_recla(GtkWidget *list) ;
recla rechercher_message (char id_message[taille]);
void supprimer_message(char id_message[taille]) ;
#endif /*NOTIFICATIONS_H*/
