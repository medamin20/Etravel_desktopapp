#include <gtk/gtk.h>

typedef struct
{
char Cin01 [30];
char Nom01 [30];
char Prenom01 [30];
char Adressmail01 [30];
char Login01 [30];
char Passworld01 [30];
char Telephone01[30];

}personne;


int vermaj(char text[8]);
void ajouter_personne(personne p);
void afficher_personne(GtkWidget *liste);
