#include <gtk/gtk.h>

typedef struct
{
char code01[30];
char date01 [30];
char heure01 [30];
char depart01 [30];
char arrivee01 [30];
char prix01[30];
char placedis01[30];

}vol;

void ajouter_vol(vol v);
void afficher_vol(GtkWidget *liste);
void chercher_vol(GtkWidget *liste);
