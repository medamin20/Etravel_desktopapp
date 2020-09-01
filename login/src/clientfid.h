#include <gtk/gtk.h>

typedef struct 
{
char nom[20];
char prenom[30];
char datenaiss[30];
char adresseemail[10];
char numtel[10];
char code[10];

}clientfid; 
void afficher_clientfid(GtkWidget *liste);
