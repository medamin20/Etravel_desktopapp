#include <gtk/gtk.h>

typedef struct 
{
char nom[20];
char prenom[30];
char datenaiss[30];
char adresseemail[10];
char numtel[10];
char daterec[30];
char adresse[10];

}agent; 

void ajouter_agent(agent p);
void modifier_agent(agent p);
char est_nombre_entier (const char *s);
