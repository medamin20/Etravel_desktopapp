#define taille 256

typedef struct reservation
{
char id_de_voyage[20];
char destination[20];
char nombre_de_personne[20];
char prix[20];
char date_dep[20] ; 
char date_arr[20] ;

}reserve;



void ajouter_reservations(reserve e);
void supprimer_reservations(reserve e,char id_de_voyage[20]);
int rechercher_reserves(reserve e,char id_de_voyage[20]);
void afficher_reservations(GtkWidget *liste);
void modifier_reservations(reserve e,char id_de_voyage[30]);
reserve rechercher_rese (char id_voyage[taille]);
