#include <gtk/gtk.h>

typedef struct
{

int code; 
char nom[20];
char prenom[30];
char carte[30];
char montant[10];

}facture;

void ajouter_facture(facture f);
void afficher_facture(GtkWidget *liste);
int verifier_code(facture f,int code);
void modifier_facture(facture f,int code);
void supprimer_facture(facture f,int code);
