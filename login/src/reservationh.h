#define taille 256

typedef struct reservationh
{
char id_de_voyageh[20];
char destinationh[20];
char nombre_de_personneh[20];
char prixh[20];
char date_deph[20] ; 
char date_arrh[20] ;

};
typedef struct reservationh reserveh;


void ajouter_reservationh(reserveh eh);
void supprimer_reservationh(reserveh eh,char id_de_voyageh[20]);
int rechercher_reserveh(reserveh eh,char id_de_voyageh[20]);
void afficher_reservationh(GtkWidget *liste);
void modifier_reservationh(reserveh eh,char id_de_voyageh[30]);
reserveh rechercher_reseh (char id_voyageh[taille]);
