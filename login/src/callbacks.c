#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif


#include <gtk/gtk.h>

#include <stdlib.h>
#include <stdio.h>

#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"

#include "reclamation.h"
#include "reservation.h"

#include "ajouter.h"
#include "afficher.h"
#include "clientfid.h"
#include "twilio.h"
#include "fonction.h"
#include "voiture.h"
#include "msg.h"

#include "addclient.h"
#include "addvol.h"

#include "reservations.h"

#include "reservationh.h"
#define Q 100
#define QA 100


void
on_button1h_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
reserveh eh;
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input6;
GtkWidget *window1h;
GtkWidget *window2;
GtkWidget *window3;
GtkWidget *treeview1;

window1h=lookup_widget(objet,"window1h");
input1=lookup_widget(objet,"entry1h");
input2=lookup_widget(objet,"entry2h");
input3=lookup_widget(objet,"entry3h");
input4=lookup_widget(objet,"entry4h");
input5=lookup_widget(objet,"entry5h");
input6=lookup_widget(objet,"entry6h");
strcpy(eh.id_de_voyageh,gtk_entry_get_text(GTK_ENTRY (input1)));
strcpy(eh.destinationh,gtk_entry_get_text(GTK_ENTRY (input2)));
strcpy(eh.date_deph,gtk_entry_get_text(GTK_ENTRY (input3)));
strcpy(eh.date_arrh,gtk_entry_get_text(GTK_ENTRY (input4)));
strcpy(eh.nombre_de_personneh,gtk_entry_get_text(GTK_ENTRY (input5)));
strcpy(eh.prixh,gtk_entry_get_text(GTK_ENTRY (input6)));
ajouter_reservationh(eh);

      GtkWidget *ajouth;
      ajouth=create_ajouth();
      gtk_widget_show(ajouth);
gtk_entry_set_text(GTK_ENTRY(input1),"");
gtk_entry_set_text(GTK_ENTRY(input2),"");
gtk_entry_set_text(GTK_ENTRY(input3),"");
gtk_entry_set_text(GTK_ENTRY(input4),"");
gtk_entry_set_text(GTK_ENTRY(input5),"");
gtk_entry_set_text(GTK_ENTRY(input6),"");
			
}


void
on_button3h_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *list;
  list=lookup_widget(objet,"clist2");
  int nbre=0,i=0,j;
  char *p[QA][6]={{" "," "," "," "," "," "}};
  reserveh Res[QA],R;
  FILE *text;
  text=fopen("reservationh.txt","r");
    if(text!=NULL)
    {
      while((fscanf(text,"%s %s %s %s %s %s  ",R.id_de_voyageh,R.destinationh,R.date_deph,R.date_arrh,R.nombre_de_personneh,R.prixh)!=EOF))
      {
        strcpy(Res[i].id_de_voyageh,R.id_de_voyageh);
        strcpy(Res[i].destinationh,R.destinationh);
	strcpy(Res[i].date_deph,R.date_deph);
	strcpy(Res[i].date_arrh,R.date_arrh);
        strcpy(Res[i].nombre_de_personneh,R.nombre_de_personneh);
	strcpy(Res[i].prixh,R.prixh);
        
        
        i++;
      }
      nbre=i;
      fclose(text);
    }
	gtk_clist_clear(GTK_CLIST(list));

for(j=0;j<nbre;j++)
    {
      gtk_clist_append(GTK_CLIST(list),p[j]);
    }
    
    
    gtk_clist_set_row_height(GTK_CLIST(list),30);
      
	for(i=0;i<nbre;i++){
        gtk_clist_set_text(GTK_CLIST(list),i,0,Res[i].id_de_voyageh);
      }
	for(i=0;i<nbre;i++){
        gtk_clist_set_text(GTK_CLIST(list),i,1,Res[i].destinationh);
      }
	for(i=0;i<nbre;i++){
        gtk_clist_set_text(GTK_CLIST(list),i,2,Res[i].date_deph);
      }
	for(i=0;i<nbre;i++){
        gtk_clist_set_text(GTK_CLIST(list),i,3,Res[i].date_arrh);
      }
	for(i=0;i<nbre;i++){
        gtk_clist_set_text(GTK_CLIST(list),i,4,Res[i].nombre_de_personneh);
      }
	for(i=0;i<nbre;i++){
        gtk_clist_set_text(GTK_CLIST(list),i,5,Res[i].prixh);
      }
	
}


void
on_button4h_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input1, *input2, *input3, *input4, *input5, *output ;
GtkWidget *inputid_de_voyage ;
reserveh eh;
char id_de_voyageh[30];
FILE *f;
input1=lookup_widget(objet,"entry8h");
input2=lookup_widget(objet,"entry9h");
input3=lookup_widget(objet,"entry10h");
input4=lookup_widget(objet,"entry11h");
input5=lookup_widget(objet,"entry12h");


inputid_de_voyage=lookup_widget(objet,"entry7h");
output=lookup_widget(objet,"label29h");
strcpy(id_de_voyageh,gtk_entry_get_text(GTK_ENTRY(inputid_de_voyage)));

if(strcmp(id_de_voyageh,"")==0){
gtk_label_set_text(GTK_LABEL(output),"entrer un code svp !!!");
}
else{
f=fopen("reservationh.txt","r");
if(f!=NULL){
while(fscanf(f,"%s %s %s %s %s %s ",eh.id_de_voyageh,eh.destinationh,eh.date_deph,eh.date_arrh,eh.nombre_de_personneh,eh.prixh)!=EOF){
if(strcmp(eh.id_de_voyageh,id_de_voyageh)==0){ 
gtk_entry_set_text(GTK_ENTRY(input1),eh.destinationh);
gtk_entry_set_text(GTK_ENTRY(input2),eh.date_deph);
gtk_entry_set_text(GTK_ENTRY(input3),eh.date_arrh);
gtk_entry_set_text(GTK_ENTRY(input4),eh.nombre_de_personneh);
gtk_entry_set_text(GTK_ENTRY(input5),eh.prixh);

gtk_label_set_text(GTK_LABEL(output),"");
}	
}
fclose(f);
}
}
}


void
on_button5h_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input6;
reserveh eh;
char matriculeh[30];

input1=lookup_widget(objet,"entry8h");
input2=lookup_widget(objet,"entry9h");
input3=lookup_widget(objet,"entry10h");
input4=lookup_widget(objet,"entry11h");
input5=lookup_widget(objet,"entry12h");
input6=lookup_widget(objet,"entry7h");

strcpy(eh.destinationh,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(eh.date_deph,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(eh.date_arrh,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(eh.nombre_de_personneh,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(eh.prixh,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(eh.id_de_voyageh,gtk_entry_get_text(GTK_ENTRY(input6)));

strcpy(matriculeh,gtk_entry_get_text(GTK_ENTRY(input6)));

modifier_reservationh(eh,matriculeh);
//supprimer_reservation(e,matricule);
//ajouter_reservation(e);
GtkWidget *modifierh;
      modifierh=create_modifierh();
      gtk_widget_show(modifierh);


gtk_entry_set_text(GTK_ENTRY(input1),"");
gtk_entry_set_text(GTK_ENTRY(input2),"");
gtk_entry_set_text(GTK_ENTRY(input3),"");
gtk_entry_set_text(GTK_ENTRY(input4),"");
gtk_entry_set_text(GTK_ENTRY(input5),"");
gtk_entry_set_text(GTK_ENTRY(input6),"");

}


void
on_button6h_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input1,*output;
char codeh[30];
reserveh eh;
reserveh nh;

input1=lookup_widget(objet,"entry13h");
output=lookup_widget(objet,"label32h");


strcpy(codeh,gtk_entry_get_text(GTK_ENTRY(input1)));
nh=rechercher_reseh(codeh);
if(strcmp(codeh,"")==0){
gtk_label_set_text(GTK_LABEL(output),"entrer un code svp !!");
}
else{
if(strcmp(nh.id_de_voyageh,codeh)==0){
supprimer_reservationh(eh,codeh);
gtk_entry_set_text(GTK_ENTRY(input1),"");
gtk_label_set_text(GTK_LABEL(output),"");

GtkWidget *supprimerh;
      supprimerh=create_supprimerh();
      gtk_widget_show(supprimerh);
}
else{
gtk_label_set_text(GTK_LABEL(output),"Hebergement inexistante");
}
}

}



void
on_button2h_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajouth;
ajouth=lookup_widget(objet,"ajouth");
gtk_widget_hide(ajouth);
}


void
on_button7h_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *supprimerh;
supprimerh=lookup_widget(objet,"supprimerh");
gtk_widget_hide(supprimerh);
}


void
on_button8h_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *modifierh;
modifierh=lookup_widget(objet,"modifierh");
gtk_widget_hide(modifierh);
}

char usernam[50];
int verifier(char username [], char password [])
{
FILE*f;
int r;
int a=0;
char user[20],pass[20];
f=fopen("Users.txt","r");
if(f!=NULL){
while(fscanf(f,"%s %s %d\n",user,pass,&r)!=EOF){
if((strcmp(username,user)==0) && (strcmp(password,pass)==0))
{a=r;}

}}
fclose(f);
return (a) ;
}
void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
memset (usernam, 0, sizeof (usernam));
        GtkWidget *input1,*input2, *output;
	GtkWidget *window1, *window4,*Espaceagent,*accueil;
        GtkWidget *image9;
        GtkWidget *image10;
	int role=0;
	int a=0;
	char username[20], password[20];

	output=lookup_widget(button,"label0");
	window1=lookup_widget(button,"window1");
	input1 = lookup_widget(button, "entry1");
	input2 = lookup_widget(button, "entry2");

	strcpy(username, gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(password, gtk_entry_get_text(GTK_ENTRY(input2)));
	role=verifier(username,password);
		if(role == 0)
		{
		gtk_label_set_text(GTK_LABEL(output),"mot de passe ou nom d'utilisateur incorrect");
		gtk_entry_set_text(GTK_ENTRY(input1),"");
		gtk_entry_set_text(GTK_ENTRY(input2),"");
		}
		else if (role == 1)
		{
		gtk_widget_hide(window1);
		window1 = create_window4();
		gtk_widget_show (window1);
		}
		else if (role == 2)
		{
		gtk_widget_hide(window1);
		window1= create_Espaceagent();
		gtk_widget_show (window1);
		}
		else if (role == 3)
		{
   
		gtk_widget_hide(window1);
		window1= create_accueil();
		gtk_widget_show (window1);
                image9=lookup_widget(window1,"image9");
                gtk_image_set_from_file(GTK_IMAGE(image9),"/home/insaf/Pictures/m.jpg");
                image10=lookup_widget(window1,"image10");
                gtk_image_set_from_file(GTK_IMAGE(image10),"/home/insaf/Pictures/n.jpg");
		}

		
}
		


void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1, *window3;

window1=lookup_widget(button,"window1");

gtk_widget_destroy(window1);
window3 = create_window3();
gtk_widget_show(window3);

}


void
on_button5_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_main_quit();

}


void
on_button4_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *window1, *window2;

window1=lookup_widget(button,"window1");

gtk_widget_destroy(window1);
window2 = create_window2();
gtk_widget_show(window2);

}


void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
GtkWidget *entry2;
entry2= lookup_widget(GTK_WIDGET(togglebutton),"entry2");
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
gtk_entry_set_visibility(GTK_ENTRY (entry2), TRUE);
else
gtk_entry_set_visibility (GTK_ENTRY (entry2), FALSE);

}


void
on_button6_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1, *window2;

window2=lookup_widget(button,"window2");

gtk_widget_destroy(window2);
window1 = create_window1();
gtk_widget_show(window1);

}


void
on_button7_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button8_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1, *window3;

window3=lookup_widget(button,"window3");

gtk_widget_destroy(window3);
window1 = create_window1();
gtk_widget_show(window1);

}


void
on_button9_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window4, *window5;

window4=lookup_widget(button,"window4");

gtk_widget_destroy(window4);
window5 = create_window5();
gtk_widget_show(window5);
}


void
on_button10_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window4, *window6;

window4=lookup_widget(button,"window6");

gtk_widget_destroy(window6);
window6 = create_window6();
gtk_widget_show(window6);
}


void
on_button11_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window4, *window7;

window4=lookup_widget(button,"window4");

gtk_widget_destroy(window4);
window7 = create_window7();
gtk_widget_show(window7);
}


void
on_button12_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1, *window4;

window4=lookup_widget(button,"window4");

gtk_widget_destroy(window4);
window1 = create_window1();
gtk_widget_show(window1);

}


void
on_button14_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window4, *window5;

window5=lookup_widget(button,"window5");

gtk_widget_destroy(window5);
window4 = create_window4();
gtk_widget_show(window4);


}


void
on_button18_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window4, *window6;

window6=lookup_widget(button,"window6");

gtk_widget_destroy(window6);
window4 = create_window4();
gtk_widget_show(window4);
}


void
on_button20_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window4, *window7;

window7=lookup_widget(button,"window7");

gtk_widget_destroy(window7);
window4 = create_window4();
gtk_widget_show(window4);
}


void
on_button13_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

reservation r;

GtkWidget *output,*input1,*input2,*input3, *input4,*input5;
GtkWidget *window5;

window5=lookup_widget(objet,"window5");

output=lookup_widget(objet,"label00");
input1=lookup_widget(objet,"comboboxentry1");
input2=lookup_widget(objet,"entry12");
input3=lookup_widget(objet,"entry16");
input4=lookup_widget(objet,"entry13");
input5=lookup_widget(objet,"entry17");

strcpy(r.des,gtk_combo_box_get_active_text(GTK_ENTRY(input1)));
strcpy(r.dep,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(r.he,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(r.arr,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(r.hee,gtk_entry_get_text(GTK_ENTRY(input5)));

gtk_label_set_text(GTK_LABEL(output),"Ajout validé :) ");
	gtk_entry_set_text(GTK_ENTRY(input1),"");
	gtk_entry_set_text(GTK_ENTRY(input2),"");
	gtk_entry_set_text(GTK_ENTRY(input3),"");
	gtk_entry_set_text(GTK_ENTRY(input4),"");
	gtk_entry_set_text(GTK_ENTRY(input5),"");
ajouter_reservation(r);




}


void
on_button17_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
Reclamation r;

GtkWidget *output,*input1,*input2;

output=lookup_widget(button,"label100");
input1=lookup_widget(button,"entry88");
input2=lookup_widget(button,"entry99");

strcpy(r.cin,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(r.description,gtk_entry_get_text(GTK_ENTRY(input2)));

gtk_label_set_text(GTK_LABEL(output),"Reclamation envoyé avec succée :) ");
	gtk_entry_set_text(GTK_ENTRY(input1),"");
	gtk_entry_set_text(GTK_ENTRY(input2),"");

ajouter_reclamation(r);
}


void
on_button21_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window5;
GtkWidget *treeview1;

window5=lookup_widget(objet,"window5");


gtk_widget_destroy(window5);

gtk_widget_show(window5);
treeview1=lookup_widget(window5,"treeview1");
afficher_reservation(treeview1);
}

//project7

void
on_retour1acc_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *gestionagents, *accueil;
GtkWidget *image9;
GtkWidget *image10;
gestionagents=lookup_widget(button,"gestionagents");
gtk_widget_destroy(gestionagents);
accueil=create_accueil();
gtk_widget_show(accueil);
image9=lookup_widget(accueil,"image9");
gtk_image_set_from_file(GTK_IMAGE(image9),"/home/insaf/Pictures/m.jpg");
image10=lookup_widget(accueil,"image10");
gtk_image_set_from_file(GTK_IMAGE(image10),"/home/insaf/Pictures/n.jpg");
}


void
on_ajouterag_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
agent p;
GtkWidget *input1, *input2, *input3,*input4,*input5,*input6,*input7;
GtkWidget *output1,*output2,*output3,*output4,*output5,*output6,*output7,*output;
GtkWidget *gestionagents;
GtkWidget *msgaj;
const char *s1;
GtkWidget *treeviewag;
gestionagents=lookup_widget(button,"gestionagents");
input1=lookup_widget(button,"entry1");
input2=lookup_widget(button,"entry2");
input3=lookup_widget(button,"entry3");
input4=lookup_widget(button,"entry4");
input5=lookup_widget(button,"entry5");
input6=lookup_widget(button,"entry6");
input7=lookup_widget(button,"entry7");
output1=lookup_widget(button,"labelerr1");
output2=lookup_widget(button,"labelerr2");
output3=lookup_widget(button,"labelerr3");
output4=lookup_widget(button,"labelerr4");
output5=lookup_widget(button,"labelerr5");
output6=lookup_widget(button,"labelerr6");
output7=lookup_widget(button,"labelerr7");
output=lookup_widget(button,"labelerr5");
s1 = gtk_entry_get_text (GTK_ENTRY(input5)) ;
if (!est_nombre_entier(s1)) {
  gtk_label_set_text(GTK_LABEL(output), "Pas des nombres") ;
  }


else if(strcmp(gtk_entry_get_text(GTK_ENTRY(input1)),"")==0){
gtk_label_set_text(GTK_LABEL(output1),"entrer un nom svp ");}
else if (strcmp(gtk_entry_get_text(GTK_ENTRY(input2)),"")==0){
gtk_label_set_text(GTK_LABEL(output2),"entrer un prénom svp ");}
else if (strcmp(gtk_entry_get_text(GTK_ENTRY(input3)),"")==0){
gtk_label_set_text(GTK_LABEL(output3),"entrer une date svp ");}
else if (strcmp(gtk_entry_get_text(GTK_ENTRY(input4)),"")==0 ){
gtk_label_set_text(GTK_LABEL(output4),"entrer une adresse email svp ");}
else if(strcmp(gtk_entry_get_text(GTK_ENTRY(input5)),"")==0){
gtk_label_set_text(GTK_LABEL(output5),"entrer un numéro svp ");}
else if(strcmp(gtk_entry_get_text(GTK_ENTRY(input6)),"")==0){
gtk_label_set_text(GTK_LABEL(output6),"entrer une date svp ");}
else if(strcmp(gtk_entry_get_text(GTK_ENTRY(input7)),"")==0){
gtk_label_set_text(GTK_LABEL(output7),"entrer une adresse svp ");}
else{
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.datenaiss,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(p.adresseemail,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(p.numtel,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(p.daterec,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(p.adresse,gtk_entry_get_text(GTK_ENTRY(input7)));
ajouter_agent(p);

msgaj=create_msgaj();
gtk_widget_show(msgaj);
treeviewag=lookup_widget(gestionagents,"treeviewag");

afficher_agent(treeviewag);
gtk_label_set_text(GTK_LABEL(output1),"");
gtk_label_set_text(GTK_LABEL(output2),"");
gtk_label_set_text(GTK_LABEL(output3),"");
gtk_label_set_text(GTK_LABEL(output4),"");
gtk_label_set_text(GTK_LABEL(output5),"");
gtk_label_set_text(GTK_LABEL(output6),"");
gtk_label_set_text(GTK_LABEL(output7),"");
gtk_entry_set_text(GTK_ENTRY(input1),"");
gtk_entry_set_text(GTK_ENTRY(input2),"");
gtk_entry_set_text(GTK_ENTRY(input3),"");
gtk_entry_set_text(GTK_ENTRY(input4),"");
gtk_entry_set_text(GTK_ENTRY(input5),"");
gtk_entry_set_text(GTK_ENTRY(input6),"");
gtk_entry_set_text(GTK_ENTRY(input7),"");
}
}

void
on_treeviewag_row_activated             (GtkTreeView     *treeviewag,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
gchar *NOM;
gchar *PRENOM;
gchar *DATENAISS;
gchar *ADRESSEEMAIL;
gchar *NUMTEL;
gchar *DATEREC;
gchar *ADRESSE;
GtkWidget *gestionagents;
GtkWidget *modifiersupprimer;
GtkTreeIter iter;
GtkWidget *nom;
GtkWidget *prenom;
GtkWidget *datenaiss;
GtkWidget *adresseemail;
GtkWidget *numtel;
GtkWidget *daterec;
GtkWidget *adresse;
GtkWidget *image6;
GtkWidget *image7;
GtkWidget *image8;
gestionagents=lookup_widget(treeviewag,"gestionagents");
gtk_widget_hide(gestionagents);
GtkTreeModel *model = gtk_tree_view_get_model(treeviewag);
if(gtk_tree_model_get_iter(model,&iter,path))
{gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&NOM,1,&PRENOM,2,&DATENAISS,3,&ADRESSEEMAIL,4,&NUMTEL,5,&DATEREC,6,&ADRESSE,-1);}
modifiersupprimer= create_modifiersupprimer();
nom=lookup_widget(modifiersupprimer,"nom");
prenom=lookup_widget(modifiersupprimer,"prenom");
datenaiss=lookup_widget(modifiersupprimer,"datenaiss");
adresseemail=lookup_widget(modifiersupprimer,"adresseemail");
numtel=lookup_widget(modifiersupprimer,"numtel");
daterec=lookup_widget(modifiersupprimer,"daterec");
adresse=lookup_widget(modifiersupprimer,"adresse");

    gtk_entry_set_text(GTK_ENTRY(nom),NOM);
    gtk_entry_set_text(GTK_ENTRY(prenom),PRENOM);
    gtk_entry_set_text(GTK_ENTRY(datenaiss),DATENAISS);	
    gtk_entry_set_text(GTK_ENTRY(adresseemail),ADRESSEEMAIL); 
    gtk_entry_set_text(GTK_ENTRY(numtel),NUMTEL); 
    gtk_entry_set_text(GTK_ENTRY(daterec),DATEREC);
    gtk_entry_set_text(GTK_ENTRY(adresse),ADRESSE);
 gtk_widget_show (modifiersupprimer);
image6=lookup_widget(modifiersupprimer,"image6");
gtk_image_set_from_file(GTK_IMAGE(image6),"/home/insaf/Pictures/m.jpg");
image7=lookup_widget(modifiersupprimer,"image7");
gtk_image_set_from_file(GTK_IMAGE(image7),"/home/insaf/Pictures/n.jpg");
image8=lookup_widget(modifiersupprimer,"image8");
gtk_image_set_from_file(GTK_IMAGE(image8),"/home/insaf/Pictures/téléchargement.jpg");
}


void
on_gestionagents_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *gestionagents;
GtkWidget *accueil;
GtkWidget *treeviewag;
GtkWidget *image3;
GtkWidget *image4;
GtkWidget *image1;
GtkWidget *image2;
GtkWidget *image5;

accueil=lookup_widget(button,"accueil");

gtk_widget_destroy(accueil);
gestionagents=lookup_widget(button,"gestionagents");

gestionagents=create_gestionagents();
gtk_widget_show(gestionagents);
image1=lookup_widget(gestionagents,"image1");
gtk_image_set_from_file(GTK_IMAGE(image1),"/home/insaf/Pictures/m.jpg");
image3=lookup_widget(gestionagents,"image3");
gtk_image_set_from_file(GTK_IMAGE(image3),"/home/insaf/Pictures/m.jpg");
image2=lookup_widget(gestionagents,"image2");
gtk_image_set_from_file(GTK_IMAGE(image2),"/home/insaf/Pictures/n.jpg");
image4=lookup_widget(gestionagents,"image4");
gtk_image_set_from_file(GTK_IMAGE(image4),"/home/insaf/Pictures/n.jpg");
image5=lookup_widget(gestionagents,"image5");
gtk_image_set_from_file(GTK_IMAGE(image5),"/home/insaf/Pictures/téléchargement.jpg");
treeviewag=lookup_widget(gestionagents,"treeviewag");

afficher_agent(treeviewag);
}


void
on_reclamations_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *accueil;
GtkWidget *reclamations;
GtkWidget *image11;
GtkWidget *image12;
accueil=lookup_widget(button,"accueil");
gtk_widget_hide(accueil);
reclamations= create_reclamations ();
gtk_widget_show (reclamations);
image11=lookup_widget(reclamations,"image11");
gtk_image_set_from_file(GTK_IMAGE(image11),"/home/insaf/Pictures/m.jpg");
image12=lookup_widget(reclamations,"image12");
gtk_image_set_from_file(GTK_IMAGE(image12),"/home/insaf/Pictures/n.jpg");
}


void
on_gestion_fidelites_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *accueil;
GtkWidget *gestionfidelites;
GtkWidget *image13;
GtkWidget *image14;
GtkWidget *image15;
GtkWidget *treeviewcf;
accueil=lookup_widget(button,"accueil");
gtk_widget_destroy(accueil);
gestionfidelites=lookup_widget(button,"gestionfidelites");
gestionfidelites= create_gestionfidelites ();
gtk_widget_show (gestionfidelites);
image13=lookup_widget(gestionfidelites,"image13");
gtk_image_set_from_file(GTK_IMAGE(image13),"/home/insaf/Pictures/m.jpg");
image14=lookup_widget(gestionfidelites,"image14");
gtk_image_set_from_file(GTK_IMAGE(image14),"/home/insaf/Pictures/n.jpg");
image15=lookup_widget(gestionfidelites,"image15");
gtk_image_set_from_file(GTK_IMAGE(image15),"/home/insaf/Pictures/fidele.jpg");
treeviewcf=lookup_widget(gestionfidelites,"treeviewcf");

afficher_clientfid(treeviewcf);
}


void
on_modifierag_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
char id [30];
 agent p;
const char *s1;
GtkWidget *input8, *input9, *input10,*input11,*input12,*input13,*input14,*input;
GtkWidget *output8, *output9, *output10,*output11,*output12,*output13,*output14,*output;
GtkWidget *modifiersupprimer;
GtkWidget *msgmod;
FILE*f;
FILE*f2;
modifiersupprimer=lookup_widget(button,"modifiersupprimer");
input=lookup_widget(button,"nom");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input)));
f=fopen("agent.txt","r");
f2=fopen("agent1.txt","a");
    if(f!=NULL)
 {
while(fscanf(f,"%s %s %s %s %s %s %s \n",p.nom,p.prenom,p.datenaiss,p.adresseemail,p.numtel,p.daterec,p.adresse)!=EOF)
     {
 if (strcmp(p.nom,id)!=0) 
  {
fprintf(f2,"%s %s %s %s %s %s %s \n",p.nom,p.prenom,p.datenaiss,p.adresseemail,p.numtel,p.daterec,p.adresse);
     }
 }
 fclose(f);
 fclose(f2);
}
remove("agent.txt");
rename("agent1.txt","agent.txt");

input8=lookup_widget(button,"nom");
input9=lookup_widget(button,"prenom");
input10=lookup_widget(button,"datenaiss");
input11=lookup_widget(button,"adresseemail");
input12=lookup_widget(button,"numtel");
input13=lookup_widget(button,"daterec");
input14=lookup_widget(button,"adresse");

output8=lookup_widget(button,"labelerr8");
output9=lookup_widget(button,"labelerr9");
output10=lookup_widget(button,"labelerr10");
output11=lookup_widget(button,"labelerr11");
output12=lookup_widget(button,"labelerr12");
output13=lookup_widget(button,"labelerr13");
output14=lookup_widget(button,"labelerr14");
output=lookup_widget(button,"labelerr12");
s1 = gtk_entry_get_text (GTK_ENTRY(input12)) ;
if (!est_nombre_entier(s1)) {
  gtk_label_set_text(GTK_LABEL(output), "Pas des nombres") ;
  }
else if(strcmp(gtk_entry_get_text(GTK_ENTRY(input8)),"")==0){
gtk_label_set_text(GTK_LABEL(output8),"entrer un nom svp ");}
else if (strcmp(gtk_entry_get_text(GTK_ENTRY(input9)),"")==0){
gtk_label_set_text(GTK_LABEL(output9),"entrer un prénom svp ");}
else if (strcmp(gtk_entry_get_text(GTK_ENTRY(input10)),"")==0){
gtk_label_set_text(GTK_LABEL(output10),"entrer une date svp ");}
else if (strcmp(gtk_entry_get_text(GTK_ENTRY(input11)),"")==0 ){
gtk_label_set_text(GTK_LABEL(output11),"entrer une adresse email svp ");}
else if(strcmp(gtk_entry_get_text(GTK_ENTRY(input12)),"")==0){
gtk_label_set_text(GTK_LABEL(output12),"entrer un numéro svp ");}
else if(strcmp(gtk_entry_get_text(GTK_ENTRY(input13)),"")==0){
gtk_label_set_text(GTK_LABEL(output13),"entrer une date svp ");}
else if(strcmp(gtk_entry_get_text(GTK_ENTRY(input14)),"")==0){
gtk_label_set_text(GTK_LABEL(output14),"entrer une adresse svp ");}
else{
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input8)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(input9)));
strcpy(p.datenaiss,gtk_entry_get_text(GTK_ENTRY(input10)));
strcpy(p.adresseemail,gtk_entry_get_text(GTK_ENTRY(input11)));
strcpy(p.numtel,gtk_entry_get_text(GTK_ENTRY(input12)));
strcpy(p.daterec,gtk_entry_get_text(GTK_ENTRY(input13)));
strcpy(p.adresse,gtk_entry_get_text(GTK_ENTRY(input14)));

modifier_agent(p);

msgmod=create_msgmod();
gtk_widget_show(msgmod);
gtk_label_set_text(GTK_LABEL(output8),"");
gtk_label_set_text(GTK_LABEL(output9),"");
gtk_label_set_text(GTK_LABEL(output10),"");
gtk_label_set_text(GTK_LABEL(output11),"");
gtk_label_set_text(GTK_LABEL(output12),"");
gtk_label_set_text(GTK_LABEL(output13),"");
gtk_label_set_text(GTK_LABEL(output14),"");
gtk_entry_set_text(GTK_ENTRY(input8),"");
gtk_entry_set_text(GTK_ENTRY(input9),"");
gtk_entry_set_text(GTK_ENTRY(input10),"");
gtk_entry_set_text(GTK_ENTRY(input11),"");
gtk_entry_set_text(GTK_ENTRY(input12),"");
gtk_entry_set_text(GTK_ENTRY(input13),"");
gtk_entry_set_text(GTK_ENTRY(input14),"");
}

}


void
on_supprimerag_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
char id [30];
agent p;
GtkWidget *modifiersupprimer;
GtkWidget *msgsupp;
GtkWidget *input;
FILE*f;
FILE*f3;
modifiersupprimer=lookup_widget(button,"modifiersupprimer");
input=lookup_widget(button,"nom");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input)));
f=fopen("agent.txt","r");
f3=fopen("agent2.txt","a");
 while(fscanf(f,"%s %s %s %s %s %s %s \n",p.nom,p.prenom,p.datenaiss,p.adresseemail,p.numtel,p.daterec,p.adresse)!=EOF)
     {
if (strcmp(p.nom,id)!=0) 
    {
    fprintf(f3,"%s %s %s %s %s %s %s \n",p.nom,p.prenom,p.datenaiss,p.adresseemail,p.numtel,p.daterec,p.adresse);
     }
 }
 fclose(f);
 fclose(f3);
remove("agent.txt");
rename("agent2.txt","agent.txt");

msgsupp=create_msgsupp();
gtk_widget_show(msgsupp);
}


void
on_retour2acc_clicked                     (GtkWidget      *button,
                                        gpointer         user_data)
{
GtkWidget *gestionagents, *modifiersupprimer, *treeviewag;
GtkWidget *image3;
GtkWidget *image4;
GtkWidget *image1;
GtkWidget *image2;
GtkWidget *image5;
modifiersupprimer=lookup_widget(button,"modifiersupprimer");
gtk_widget_destroy(modifiersupprimer);
gestionagents=create_gestionagents();
gtk_widget_show(gestionagents);
image1=lookup_widget(gestionagents,"image1");
gtk_image_set_from_file(GTK_IMAGE(image1),"/home/insaf/Pictures/m.jpg");
image3=lookup_widget(gestionagents,"image3");
gtk_image_set_from_file(GTK_IMAGE(image3),"/home/insaf/Pictures/m.jpg");
image2=lookup_widget(gestionagents,"image2");
gtk_image_set_from_file(GTK_IMAGE(image2),"/home/insaf/Pictures/n.jpg");
image4=lookup_widget(gestionagents,"image4");
gtk_image_set_from_file(GTK_IMAGE(image4),"/home/insaf/Pictures/n.jpg");
image5=lookup_widget(gestionagents,"image5");
gtk_image_set_from_file(GTK_IMAGE(image5),"/home/insaf/Pictures/téléchargement.jpg");
treeviewag=lookup_widget(gestionagents,"treeviewag");

afficher_agent(treeviewag);
}



void
on_retour3acc_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *reclamations, *accueil;
GtkWidget *image9;
GtkWidget *image10;
reclamations=lookup_widget(button,"reclamations");
gtk_widget_destroy(reclamations);
accueil=create_accueil();
gtk_widget_show(accueil);
image9=lookup_widget(accueil,"image9");
gtk_image_set_from_file(GTK_IMAGE(image9),"/home/insaf/Pictures/m.jpg");
image10=lookup_widget(accueil,"image10");
gtk_image_set_from_file(GTK_IMAGE(image10),"/home/insaf/Pictures/n.jpg");
}




void
on_treeviewcf_row_activated             (GtkTreeView     *treeviewcf,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
gchar *NOM;
gchar *PRENOM;
gchar *DATENAISS;
gchar *ADRESSEEMAIL;
gchar *NUMTEL;
gchar *CODE;
GtkWidget *gestionfidelites;
GtkTreeIter iter;
GtkWidget *nom;
GtkWidget *prenom;
GtkWidget *datenaiss;
GtkWidget *adresseemail;
GtkWidget *numtel;
GtkWidget *code;

gestionfidelites=lookup_widget(treeviewcf,"gestionfidelites");
gtk_widget_show (gestionfidelites);
GtkTreeModel *model = gtk_tree_view_get_model(treeviewcf);
if(gtk_tree_model_get_iter(model,&iter,path))
{gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&NOM,1,&PRENOM,2,&DATENAISS,3,&ADRESSEEMAIL,4,&NUMTEL,5,&CODE,-1);}
nom=lookup_widget(gestionfidelites,"nomcl");
prenom=lookup_widget(gestionfidelites,"prenomcl");
datenaiss=lookup_widget(gestionfidelites,"datenaisscl");
adresseemail=lookup_widget(gestionfidelites,"adresseemailcl");
numtel=lookup_widget(gestionfidelites,"numtelcl");
code=lookup_widget(gestionfidelites,"codecl");

    gtk_entry_set_text(GTK_ENTRY(nom),NOM);
    gtk_entry_set_text(GTK_ENTRY(prenom),PRENOM);
    gtk_entry_set_text(GTK_ENTRY(datenaiss),DATENAISS);	
    gtk_entry_set_text(GTK_ENTRY(adresseemail),ADRESSEEMAIL); 
    gtk_entry_set_text(GTK_ENTRY(numtel),NUMTEL); 
    gtk_entry_set_text(GTK_ENTRY(code),CODE);
 

}




void
on_chercherag_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
char id [30];
agent p;
GtkWidget *gestionagents;
GtkWidget *input;
GtkWidget *treeviewag;
FILE*f;
FILE*f2;


gestionagents=lookup_widget(button,"gestionagents");
input=lookup_widget(button,"entrychercher");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input)));
f=fopen("agent.txt","r");

 if(f!=NULL)
 {
  while(fscanf(f,"%s %s %s %s %s %s %s \n",p.nom,p.prenom,p.datenaiss,p.adresseemail,p.numtel,p.daterec,p.adresse)!=EOF)
     {
       f2=fopen("chercher.txt","a+");
       if  (f2!=NULL)
   {  
     
     if ((strcmp(p.nom,id)==0) || (strcmp(p.prenom,id)==0))
     { 
     fprintf(f2,"%s %s %s %s %s %s %s \n",p.nom,p.prenom,p.datenaiss,p.adresseemail,p.numtel,p.daterec,p.adresse);
     }
   
     treeviewag=lookup_widget(gestionagents,"treeviewag");
     chercher_agent(treeviewag);
    
        fclose(f2);
    }

 }
 fclose(f);
}
remove("chercher.txt");
}







void
on_envoyercode_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *input,*output;
input=lookup_widget(button,"numtelcl");
output=lookup_widget(button,"codecl");
bool verbose = false;
        char *account_sid = "AC5e9c90ade3de7ee31371ad4db70a8cc7";
        char *auth_token = "20f734f8da7c5e7c99b394313d53e01c";
        char *message =gtk_entry_get_text(GTK_ENTRY(output));
        char *from_number = "+12405415821";
        char *to_number =gtk_entry_get_text(GTK_ENTRY(input));
        char *picture_url = NULL;
        opterr = 0;

        

        if (twilio_send_message(account_sid,
                                auth_token,
                                message,
                                from_number,
                                to_number,
                                picture_url,
                                verbose
        ) == true) {
            return 0;
        } else {
            return -1;
        }
}


void
on_retour4acc_clicked                  (GtkWidget      *button,
                                        gpointer         user_data)
{
GtkWidget *gestionfidelites, *accueil;
GtkWidget *image9;
GtkWidget *image10;
gestionfidelites=lookup_widget(button,"gestionfidelites");
gtk_widget_destroy(gestionfidelites);
accueil=create_accueil();
gtk_widget_show(accueil);
image9=lookup_widget(accueil,"image9");
gtk_image_set_from_file(GTK_IMAGE(image9),"/home/insaf/Pictures/m.jpg");
image10=lookup_widget(accueil,"image10");
gtk_image_set_from_file(GTK_IMAGE(image10),"/home/insaf/Pictures/n.jpg");
}

//project6

void
on_ajouterdh_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajoutdh,*dhafer1 ;
fenetre_ajoutdh=create_fenetre_ajoutdh();
gtk_widget_show(fenetre_ajoutdh);
dhafer1=lookup_widget(objet,"dhafer1");
gtk_widget_hide(dhafer1);
}


void
on_modifierdh_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_modifierdh,*dhafer1 ;
fenetre_modifierdh=create_fenetre_modifierdh();
gtk_widget_show(fenetre_modifierdh);
dhafer1=lookup_widget(objet,"dhafer1");
gtk_widget_hide(dhafer1);
}


void
on_supprimerdh_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_supprimerdh,*dhafer1 ;
fenetre_supprimerdh=create_fenetre_supprimerdh();
gtk_widget_show(fenetre_supprimerdh);
dhafer1=lookup_widget(objet,"dhafer1");
gtk_widget_hide(dhafer1);
}


void
on_validerdh_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input1,*input2,*input3,*input4,*output,*output1,*output2,*output3,*output4 ;
GtkWidget *ajoutdh;
facture f;
int i=0 ;
ajoutdh=create_ajoutdh();
input1=lookup_widget(objet,"entrynomdh");
input2=lookup_widget(objet,"entryprenomdh");
input3=lookup_widget(objet,"entrycartedh");
input4=lookup_widget(objet,"entrymontantdh");
output=lookup_widget(objet,"labelmsgdhe") ;

strcpy(f.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(f.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(f.carte,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(f.montant,gtk_entry_get_text(GTK_ENTRY(input4)));

if(strcmp(f.nom,"")==0||strcmp(f.prenom,"")==0||strcmp(f.carte,"")==0||strcmp(f.montant,"")==0){
gtk_label_set_text(GTK_LABEL(output),"veuillez remplir toutes les cases");
}
else{
ajouter_facture(f);
gtk_entry_set_text(GTK_ENTRY(input1),"");
gtk_entry_set_text(GTK_ENTRY(input2),"");
gtk_entry_set_text(GTK_ENTRY(input3),"");
gtk_entry_set_text(GTK_ENTRY(input4),"");
gtk_label_set_text(GTK_LABEL(output),"");
gtk_widget_show(ajoutdh);
}
}


void
on_effacerdh_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input1,*input2,*input3,*input4,*output;
GtkWidget *fenetre_ajoutdh;

input1=lookup_widget(objet,"entrynomdh");
input2=lookup_widget(objet,"entryprenomdh");
input3=lookup_widget(objet,"entrycartedh");
input4=lookup_widget(objet,"entrymontantdh");
output=lookup_widget(objet,"labelmsgdhe");
gtk_entry_set_text(GTK_ENTRY(input1),"");
gtk_entry_set_text(GTK_ENTRY(input2),"");
gtk_entry_set_text(GTK_ENTRY(input3),"");
gtk_entry_set_text(GTK_ENTRY(input4),"");
gtk_label_set_text(GTK_LABEL(output),"");
}


void
on_retourdh_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajoutdh,*dhafer1,*treeviewdh1 ;
dhafer1=create_dhafer1();
gtk_widget_show(dhafer1);
fenetre_ajoutdh=lookup_widget(objet,"fenetre_ajoutdh");
gtk_widget_hide(fenetre_ajoutdh);
treeviewdh1=lookup_widget(dhafer1,"treeviewdh1");
afficher_facture (treeviewdh1) ;
}

void
on_chercherdh_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input1,*output,*input2,*input3,*input4;
GtkWidget *inputcode;
facture f;
int code;
char code1[30];
FILE *g;

input1=lookup_widget(objet,"entrynomdh1");
input2=lookup_widget(objet,"entryprenomdh1");
input3=lookup_widget(objet,"entrycartedh1");
input4=lookup_widget(objet,"entrymontantdh1");

inputcode=lookup_widget(objet,"entrycodedh");
output=lookup_widget(objet,"labelmsgdh2");
code=atof(gtk_entry_get_text(GTK_ENTRY(inputcode)));
strcpy(code1,gtk_entry_get_text(GTK_ENTRY(inputcode)));
if (strcmp(code1,"")==0){
gtk_label_set_text(GTK_LABEL(output),"entrer un code");
}
else {
if(verifier_code(f,code)==0){
gtk_label_set_text(GTK_LABEL(output),"Ce code nexiste pas");
gtk_entry_set_text(GTK_ENTRY(input1),"");
gtk_entry_set_text(GTK_ENTRY(input2),"");
gtk_entry_set_text(GTK_ENTRY(input3),"");
gtk_entry_set_text(GTK_ENTRY(input4),"");
gtk_entry_set_text(GTK_ENTRY(inputcode),"");
}
else{
g=fopen("factures.txt","r");
if(g!=NULL){
while(fscanf(g,"%d %s %s %s %s ",&f.code,f.nom,f.prenom,f.carte,f.montant)!=EOF){
if(f.code==code){ 
gtk_entry_set_text(GTK_ENTRY(input1),f.nom);
gtk_entry_set_text(GTK_ENTRY(input2),f.prenom);
gtk_entry_set_text(GTK_ENTRY(input3),f.carte);
gtk_entry_set_text(GTK_ENTRY(input4),f.montant);
gtk_label_set_text(GTK_LABEL(output),"");
	
}
}
}fclose(g);
}
}
}
void
on_validerdh1_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input1,*output,*input2,*input3,*input4;
GtkWidget *inputcode,*modifierdh;
facture f;
int code ;
char code1[30];

input1=lookup_widget(objet,"entrynomdh1");
input2=lookup_widget(objet,"entryprenomdh1");
input3=lookup_widget(objet,"entrycartedh1");
input4=lookup_widget(objet,"entrymontantdh1");
inputcode=lookup_widget(objet,"entrycodedh");
output=lookup_widget(objet,"labelmsgdhj");
modifierdh=create_modifierdh();

strcpy(f.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(f.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(f.carte,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(f.montant,gtk_entry_get_text(GTK_ENTRY(input4)));

code = atof(gtk_entry_get_text(GTK_ENTRY(inputcode)));
strcpy(code1,gtk_entry_get_text(GTK_ENTRY(inputcode)));

if(strcmp(f.nom,"")==0||strcmp(f.prenom,"")==0||strcmp(f.carte,"")==0||strcmp(f.montant,"")==0){
gtk_label_set_text(GTK_LABEL(output),"veuillez remplir toutes les cases");
}
else{
modifier_facture(f,code);
gtk_widget_show(modifierdh);
gtk_label_set_text(GTK_LABEL(output),"");
gtk_entry_set_text(GTK_ENTRY(inputcode),"");
gtk_entry_set_text(GTK_ENTRY(input1),"");
gtk_entry_set_text(GTK_ENTRY(input2),"");
gtk_entry_set_text(GTK_ENTRY(input3),"");
gtk_entry_set_text(GTK_ENTRY(input4),"");
}
}



void
on_effacerdh1_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input1,*input2,*input3,*input4,*output;
GtkWidget *input5;

input1=lookup_widget(objet,"entrynomdh1");
input2=lookup_widget(objet,"entryprenomdh1");
input3=lookup_widget(objet,"entrycartedh1");
input4=lookup_widget(objet,"entrymontantdh1");
input5=lookup_widget(objet,"entrycodedh");
output=lookup_widget(objet,"labelmsgdh2");
gtk_entry_set_text(GTK_ENTRY(input1),"");
gtk_entry_set_text(GTK_ENTRY(input2),"");
gtk_entry_set_text(GTK_ENTRY(input3),"");
gtk_entry_set_text(GTK_ENTRY(input4),"");
gtk_label_set_text(GTK_LABEL(output),"");
gtk_entry_set_text(GTK_ENTRY(input5),"");
}


void
on_retourdh1_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_modifierdh,*dhafer1,*treeviewdh1 ;
dhafer1=create_dhafer1();
gtk_widget_show(dhafer1);
fenetre_modifierdh=lookup_widget(objet,"fenetre_modifierdh");
gtk_widget_hide(fenetre_modifierdh);
treeviewdh1=lookup_widget(dhafer1,"treeviewdh1");
afficher_facture (treeviewdh1) ;
}

void
on_okdh1_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajoutdh ;
ajoutdh=lookup_widget(objet,"ajoutdh");
gtk_widget_hide(ajoutdh);
}


void
on_okdh2_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *modifierdh ;
modifierdh=lookup_widget(objet,"modifierdh");
gtk_widget_hide(modifierdh);
}


void
on_validerdh2_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *output;  
  GtkWidget *input1;
  GtkWidget *supprimerdh;
int code ;
  char code1[30];
 facture f;
  output=lookup_widget(objet,"labelmsgdh4");
  input1=lookup_widget(objet,"entrycodedh1");
	supprimerdh=create_supprimerdh(); 

  code=atof(gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(code1,gtk_entry_get_text(GTK_ENTRY(input1)));
  
	if(strcmp(code1,"")==0){
	gtk_label_set_text(GTK_LABEL(output),"entrer un code SVP");
	}
	else{
	if(verifier_code(f,code)==0){
gtk_label_set_text(GTK_LABEL(output),"Ce code nexiste pas");
gtk_entry_set_text(GTK_ENTRY(input1),"");
}
else{
supprimer_facture(f,code);
gtk_entry_set_text(GTK_ENTRY(input1),""); 
	gtk_label_set_text(GTK_LABEL(output),"");
  gtk_widget_show(supprimerdh);
}
}
}

void
on_retourdh2_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_supprimerdh,*dhafer1,*treeviewdh1 ;
dhafer1=create_dhafer1();
gtk_widget_show(dhafer1);
fenetre_supprimerdh=lookup_widget(objet,"fenetre_supprimerdh");
gtk_widget_hide(fenetre_supprimerdh);
treeviewdh1=lookup_widget(dhafer1,"treeviewdh1");
afficher_facture (treeviewdh1) ;
}


void
on_okdh3_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *supprimerdh ;
supprimerdh=lookup_widget(objet,"supprimerdh");
gtk_widget_hide(supprimerdh);
}


void
on_deconnectdh2_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *dhafer1;
GtkWidget *window1;

dhafer1=lookup_widget(objet,"dhafer1");

gtk_widget_destroy(dhafer1);
window1=lookup_widget(objet,"window1");
window1=create_window1();

gtk_widget_show(window1);
}


void
on_homedh1_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Espaceagent,*dhafer1 ;
Espaceagent=create_Espaceagent();
gtk_widget_show(Espaceagent);
dhafer1=lookup_widget(objet,"dhafer1");
gtk_widget_hide(dhafer1);
}

void
on_homedh2_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)


{
GtkWidget *Espaceagent,*dhafer2 ;
Espaceagent=create_Espaceagent();
gtk_widget_show(Espaceagent);
dhafer2=lookup_widget(objet,"dhafer2");
gtk_widget_hide(dhafer2);
}
void
on_modifierdh1_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)


{
GtkWidget *fenetre_modifierdh1,*dhafer2 ;
fenetre_modifierdh1=create_fenetre_modifierdh1();
gtk_widget_show(fenetre_modifierdh1);
dhafer2=lookup_widget(objet,"dhafer2");
gtk_widget_hide(dhafer2);
}
void
on_supprimerdh1_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)

{
GtkWidget *fenetre_supprimerdh1,*dhafer2 ;
fenetre_supprimerdh1=create_fenetre_supprimerdh1();
gtk_widget_show(fenetre_supprimerdh1);
dhafer2=lookup_widget(objet,"dhafer2");
gtk_widget_hide(dhafer2);
}

void
on_ajouterdh1_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajoutdh1,*dhafer2 ;
fenetre_ajoutdh1=create_fenetre_ajoutdh1();
gtk_widget_show(fenetre_ajoutdh1);
dhafer2=lookup_widget(objet,"dhafer2");
gtk_widget_hide(dhafer2);
}


void
on_retourdh3_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajoutdh1,*dhafer2,*clistdh1 ;
dhafer2=create_dhafer2();
gtk_widget_show(dhafer2);
fenetre_ajoutdh1=lookup_widget(objet,"fenetre_ajoutdh1");
gtk_widget_hide(fenetre_ajoutdh1);
clistdh1=lookup_widget(dhafer2,"clistdh1");
afficher_voiture(clistdh1);
}


void
on_effacerdh2_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*input8,*input9,*input10,*output;

input1=lookup_widget(objet,"comboboxdh1");
input2=lookup_widget(objet,"spinbuttondh2");
input3=lookup_widget(objet,"comboboxdh3");
input4=lookup_widget(objet,"spinbuttondh4");
input5=lookup_widget(objet,"entrydh5");
input6=lookup_widget(objet,"spinbuttondh6");
input7=lookup_widget(objet,"comboboxdh7");
input8=lookup_widget(objet,"spinbuttondh8");
input9=lookup_widget(objet,"entrydh9");
input10=lookup_widget(objet,"entrydh10");
output=lookup_widget(objet,"labeldh11");
gtk_combo_box_set_active(GTK_COMBO_BOX(input1),0);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input2),1);
gtk_combo_box_set_active(GTK_COMBO_BOX(input3),0);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input4),2020);
gtk_entry_set_text(GTK_ENTRY(input5),"");
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input6),1);
gtk_combo_box_set_active(GTK_COMBO_BOX(input7),0);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input8),2020);
gtk_entry_set_text(GTK_ENTRY(input9),"");
gtk_entry_set_text(GTK_ENTRY(input10),"");
gtk_label_set_text(GTK_LABEL(output),"");
}


void
on_validerdh3_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*input8,*input9,*input10,*output;
GtkWidget *ajoutdh1;
voiture v;
ajoutdh1=create_ajoutdh1();
input1=lookup_widget(objet,"comboboxdh1");
input2=lookup_widget(objet,"spinbuttondh2");
input3=lookup_widget(objet,"comboboxdh3");
input4=lookup_widget(objet,"spinbuttondh4");
input5=lookup_widget(objet,"entrydh5");
input6=lookup_widget(objet,"spinbuttondh6");
input7=lookup_widget(objet,"comboboxdh7");
input8=lookup_widget(objet,"spinbuttondh8");
input9=lookup_widget(objet,"entrydh9");
input10=lookup_widget(objet,"entrydh10");
output=lookup_widget(objet,"labelmsgdhm");

strcpy(v.heure,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(v.heure1,gtk_entry_get_text(GTK_ENTRY(input9)));
strcpy(v.prix,gtk_entry_get_text(GTK_ENTRY(input10)));
v.date_prise.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input2));
v.date_prise.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
v.date_rest.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
v.date_rest.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8));
strcpy(v.marque,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
strcpy(v.date_prise.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)));
strcpy(v.date_rest.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input7)));
if(strcmp(v.heure,"")==0){
gtk_label_set_text(GTK_LABEL(output),"veuillez remplir toutes les cases");
gtk_combo_box_set_active(GTK_COMBO_BOX(input1),0);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input2),1);
gtk_combo_box_set_active(GTK_COMBO_BOX(input3),0);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input4),2020);
gtk_entry_set_text(GTK_ENTRY(input5),"");
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input6),1);
gtk_combo_box_set_active(GTK_COMBO_BOX(input7),0);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input8),2020);
gtk_entry_set_text(GTK_ENTRY(input9),"");
gtk_entry_set_text(GTK_ENTRY(input10),"");
}
else
{
ajouter_voiture(v);
gtk_combo_box_set_active(GTK_COMBO_BOX(input1),0);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input2),1);
gtk_combo_box_set_active(GTK_COMBO_BOX(input3),0);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input4),2020);
gtk_entry_set_text(GTK_ENTRY(input5),"");
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input6),1);
gtk_combo_box_set_active(GTK_COMBO_BOX(input7),0);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input8),2020);
gtk_entry_set_text(GTK_ENTRY(input9),"");
gtk_entry_set_text(GTK_ENTRY(input10),"");
gtk_label_set_text(GTK_LABEL(output),"");
gtk_widget_show(ajoutdh1);
}
}
void
on_ok4_clicked                         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajoutdh1 ;
ajoutdh1=lookup_widget(objet,"ajoutdh1");
gtk_widget_hide(ajoutdh1);
}


void
on_chercherdh1_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*input8,*input9,*input10,*output;
GtkWidget *inputcode;
char  mois1[15] , mois2[15] , marque1[20] ;
voiture v;
int code;
gint x;
char code1[30];
FILE *f;

input1=lookup_widget(objet,"comboboxmarquedh1");
input2=lookup_widget(objet,"spinbuttonjour_prise1");
input3=lookup_widget(objet,"comboboxmois_prise1");
input4=lookup_widget(objet,"spinbuttonannee_prise1");
input5=lookup_widget(objet,"entryheuredh1");
input6=lookup_widget(objet,"spinbuttonjour_rest1");
input7=lookup_widget(objet,"comboboxmois_rest1");
input8=lookup_widget(objet,"spinbuttonannee_rest1");
input9=lookup_widget(objet,"entryheure1dh1");
input10=lookup_widget(objet,"entryprixvoituredh1");

inputcode=lookup_widget(objet,"entrycodedh2");
output=lookup_widget(objet,"labelmsgdh6");
code=atof(gtk_entry_get_text(GTK_ENTRY(inputcode)));
strcpy(code1,gtk_entry_get_text(GTK_ENTRY(inputcode)));
if (strcmp(code1,"")==0){
gtk_label_set_text(GTK_LABEL(output),"entrer un code");
}
else {
if(verifier_code_voiture(v,code)==0){
gtk_label_set_text(GTK_LABEL(output),"Ce code n'existe pas");
gtk_combo_box_set_active(GTK_COMBO_BOX(input1),0);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input2),1);
gtk_combo_box_set_active(GTK_COMBO_BOX(input3),0);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input4),2020);
gtk_entry_set_text(GTK_ENTRY(input5),"");
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input6),1);
gtk_combo_box_set_active(GTK_COMBO_BOX(input7),0);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input8),2020);
gtk_entry_set_text(GTK_ENTRY(input9),"");
gtk_entry_set_text(GTK_ENTRY(input10),"");
gtk_entry_set_text(GTK_ENTRY(inputcode),"");
}
else{
f=fopen("voitures.txt","r");
if(f!=NULL){
while(fscanf(f,"%d %s %d %s %d %s %d %s %d %s %s ",&v.code,v.marque,&v.date_prise.jour,v.date_prise.mois,&v.date_prise.annee,v.heure,&v.date_rest.jour,v.date_rest.mois,&v.date_rest.annee,v.heure1,v.prix)!=EOF)
{
if(v.code==code){ 
set_marque (input1 , v.marque) ;
set_mois (input3 , v.date_prise.mois) ;
set_mois (input7 , v.date_rest.mois) ;
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input2),v.date_prise.jour);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input4),v.date_prise.annee);
gtk_entry_set_text(GTK_ENTRY(input5),v.heure);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input6),v.date_rest.jour);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input8),v.date_rest.annee);
gtk_entry_set_text(GTK_ENTRY(input9),v.heure1);
gtk_entry_set_text(GTK_ENTRY(input10),v.prix);
gtk_label_set_text(GTK_LABEL(output),"");


}
}
}fclose(f);
}
}
}



void
on_Validerdh4_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*input8,*input9,*input10,*output;
GtkWidget  *input11,  *modifierdh1 ;
voiture v;
int code ;
char code1[30];

input1=lookup_widget(objet,"comboboxmarquedh1");
input2=lookup_widget(objet,"spinbuttonjour_prise1");
input3=lookup_widget(objet,"comboboxmois_prise1");
input4=lookup_widget(objet,"spinbuttonannee_prise1");
input5=lookup_widget(objet,"entryheuredh1");
input6=lookup_widget(objet,"spinbuttonjour_rest1");
input7=lookup_widget(objet,"comboboxmois_rest1");
input8=lookup_widget(objet,"spinbuttonannee_rest1");
input9=lookup_widget(objet,"entryheure1dh1");
input10=lookup_widget(objet,"entryprixvoituredh1");
input11=lookup_widget(objet,"entrycodedh2");
output=lookup_widget(objet,"labelmsgdhk");
modifierdh1=create_modifierdh1();

strcpy(v.heure,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(v.heure1,gtk_entry_get_text(GTK_ENTRY(input9)));
strcpy(v.prix,gtk_entry_get_text(GTK_ENTRY(input10)));
v.date_prise.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input2));
v.date_prise.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
v.date_rest.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
v.date_rest.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8));
strcpy(v.marque,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
strcpy(v.date_prise.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)));
strcpy(v.date_rest.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input7)));
code = atof(gtk_entry_get_text(GTK_ENTRY(input11)));
strcpy(code1,gtk_entry_get_text(GTK_ENTRY(input11)));

if(strcmp(v.heure,"")==0||strcmp(v.heure1,"")==0||strcmp(v.prix,"")==0){
gtk_label_set_text(GTK_LABEL(output),"veuillez remplir toutes les cases");
}
else
{
modifier_voiture(v,code);
gtk_widget_show(modifierdh1);
gtk_combo_box_set_active(GTK_COMBO_BOX(input1),0);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input2),1);
gtk_combo_box_set_active(GTK_COMBO_BOX(input3),0);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input4),2020);
gtk_entry_set_text(GTK_ENTRY(input5),"");
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input6),1);
gtk_combo_box_set_active(GTK_COMBO_BOX(input7),0);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input8),2020);
gtk_entry_set_text(GTK_ENTRY(input9),"");
gtk_entry_set_text(GTK_ENTRY(input10),"");
gtk_label_set_text(GTK_LABEL(output),"");

}
}

void
on_effacerdh3_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*input8,*input9,*input10,*output;
GtkWidget *input11 ;

input1=lookup_widget(objet,"comboboxmarquedh1");
input2=lookup_widget(objet,"spinbuttonjour_prise1");
input3=lookup_widget(objet,"comboboxmois_prise1");
input4=lookup_widget(objet,"spinbuttonannee_prise1");
input5=lookup_widget(objet,"entryheuredh1");
input6=lookup_widget(objet,"spinbuttonjour_rest1");
input7=lookup_widget(objet,"comboboxmois_rest1");
input8=lookup_widget(objet,"spinbuttonannee_rest1");
input9=lookup_widget(objet,"entryheure1dh1");
input10=lookup_widget(objet,"entryprixvoituredh1");
input11=lookup_widget(objet,"entrycodedh2");
output=lookup_widget(objet,"labelmsgdh6");
gtk_combo_box_set_active(GTK_COMBO_BOX(input1),0);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input2),1);
gtk_combo_box_set_active(GTK_COMBO_BOX(input3),0);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input4),2020);
gtk_entry_set_text(GTK_ENTRY(input5),"");
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input6),1);
gtk_combo_box_set_active(GTK_COMBO_BOX(input7),0);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input8),2020);
gtk_entry_set_text(GTK_ENTRY(input9),"");
gtk_entry_set_text(GTK_ENTRY(input10),"");
gtk_entry_set_text(GTK_ENTRY(input11),"");
gtk_label_set_text(GTK_LABEL(output),"");
}


void
on_retourdh4_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_modifierdh1,*dhafer2,*clistdh1 ;
dhafer2=create_dhafer2();
gtk_widget_show(dhafer2);
fenetre_modifierdh1=lookup_widget(objet,"fenetre_modifierdh1");
gtk_widget_hide(fenetre_modifierdh1);
clistdh1=lookup_widget(dhafer2,"clistdh1");
afficher_voiture(clistdh1);
}


void
on_OK5_clicked                         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *modifierdh1 ;
modifierdh1=lookup_widget(objet,"modifierdh1");
gtk_widget_hide(modifierdh1);
}

void
on_validerdh5_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *output;  
  GtkWidget *input1;
  GtkWidget *supprimerdh1;
int code ;
  char code1[30];
 voiture v;
  output=lookup_widget(objet,"labelmsgdh8");
  input1=lookup_widget(objet,"entrycodedh3");
	supprimerdh1=create_supprimerdh1(); 

  code=atof(gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(code1,gtk_entry_get_text(GTK_ENTRY(input1)));
  
	if(strcmp(code1,"")==0){
	gtk_label_set_text(GTK_LABEL(output),"entrer un code SVP");
	}
	else{
	if(verifier_code_voiture(v,code)==0){
gtk_label_set_text(GTK_LABEL(output),"Ce code nexiste pas");
gtk_entry_set_text(GTK_ENTRY(input1),"");
}
else{
supprimer_voiture(v,code);
gtk_entry_set_text(GTK_ENTRY(input1),""); 
	gtk_label_set_text(GTK_LABEL(output),"");
  gtk_widget_show(supprimerdh1);
}
}
}



void
on_retourdh5_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_supprimerdh1,*dhafer2,*clistdh1 ;
dhafer2=create_dhafer2();
gtk_widget_show(dhafer2);
fenetre_supprimerdh1=lookup_widget(objet,"fenetre_supprimerdh1");
gtk_widget_hide(fenetre_supprimerdh1);
clistdh1=lookup_widget(dhafer2,"clistdh1");
afficher_voiture(clistdh1);
}


void
on_OK6_clicked                         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *supprimerdh1 ;
supprimerdh1=lookup_widget(objet,"supprimerdh1");
gtk_widget_hide(supprimerdh1);
}


void
on_homedh3_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Espaceagent,*dhafer3 ;
Espaceagent=create_Espaceagent();
gtk_widget_show(Espaceagent);
dhafer3=lookup_widget(objet,"dhafer3");
gtk_widget_hide(dhafer3);
}


void
on_supprimerdh2_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *dhafer3,*fenetre_supprimerdh2 ;
fenetre_supprimerdh2=create_fenetre_supprimerdh2();
gtk_widget_show(fenetre_supprimerdh2);
dhafer3=lookup_widget(objet,"dhafer3");
gtk_widget_hide(dhafer3);
}


void
on_lirerecladh_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *dhafer3,*lirerecladh ;
lirerecladh=create_lirerecladh();
gtk_widget_show(lirerecladh);
dhafer3=lookup_widget(objet,"dhafer3");
gtk_widget_hide(dhafer3);
}


void
on_validerdh6_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
char id_message[taille];
GtkWidget *input,*output;
GtkWidget *supprimerdh2;
recla N;
int i=0 ;
output=lookup_widget(objet,"labelmsgdh9");
input=lookup_widget(objet,"entrycodedh4");
strcpy(id_message,gtk_entry_get_text(GTK_ENTRY(input)));
N=rechercher_message(id_message);
if (strcmp(N.id,"inexistant")!=0)
{
supprimer_message(id_message);
      supprimerdh2=create_supprimerdh2();
      gtk_widget_show(supprimerdh2);
}
else
{
if (strcmp(id_message,"")==0)
{gtk_label_set_text(GTK_LABEL(output),"entrer un code SVP");}
else
{gtk_label_set_text(GTK_LABEL(output),"Ce code n'existe pas");
gtk_entry_set_text (GTK_ENTRY(input),"");
}
}
}

void
on_retourdh6_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_supprimerdh2,*dhafer3,*clistdh2 ;
dhafer3=create_dhafer3();
gtk_widget_show(dhafer3);
fenetre_supprimerdh2=lookup_widget(objet,"fenetre_supprimerdh2");
gtk_widget_hide(fenetre_supprimerdh2);
clistdh2=lookup_widget(dhafer3,"clistdh2");
afficher_recla(clistdh2);
}


void
on_okdh7_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *supprimerdh2 ;
supprimerdh2=lookup_widget(objet,"supprimerdh2");
gtk_widget_hide(supprimerdh2);
}


void
on_chercherdh2_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*input8,*output ;
   recla N;
  char id_message[taille];
  input1=lookup_widget (objet,"entryididdh");
  output=lookup_widget (objet,"labelmsgdhz");
  strcpy(id_message,gtk_entry_get_text (GTK_ENTRY(input1)));
  N=rechercher_message(id_message);

  GtkTextBuffer *buffer=0;
  GtkTextIter start, end;
  input2=lookup_widget (objet,"entrynomdh10");
  input3=lookup_widget (objet,"entryprenomdh10");
  input4=lookup_widget (objet,"textviewdh1");
  input5=lookup_widget(objet,"entryobjetdh10");
  input6=lookup_widget(objet,"spinbuttonjourdh10");
  input7=lookup_widget(objet,"comboboxmoisdh10");
  input8=lookup_widget(objet,"spinbuttonanneedh10");

  buffer=gtk_text_view_get_buffer(GTK_TEXT_VIEW(input4));
  gtk_text_buffer_get_start_iter (buffer,&start);
  gtk_text_buffer_get_end_iter (buffer,&end);
  if(strcmp(N.id,"inexistant")!=0){
  
  gtk_entry_set_text (GTK_ENTRY(input2),N.nom10);
  gtk_entry_set_text (GTK_ENTRY(input3),N.prenom10);
  gtk_entry_set_text (GTK_ENTRY(input5),N.objet);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(input6),N.d.jour);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(input8),N.d.annee);
  gtk_text_buffer_delete (buffer,&start,&end);
  gtk_text_buffer_get_end_iter(buffer,&end);
   gtk_text_buffer_set_text(buffer,N.message,strlen(N.message));
   set_mois (input7 , N.d.mois) ;
   {gtk_label_set_text(GTK_LABEL(output),"");
 }
}
else if (strcmp(id_message,"")==0)
{gtk_label_set_text(GTK_LABEL(output),"entrer un code SVP");}
else
{gtk_label_set_text(GTK_LABEL(output),"Ce code n'existe pas");
gtk_entry_set_text (GTK_ENTRY(input1),"");
  gtk_entry_set_text (GTK_ENTRY(input2),"");
  gtk_entry_set_text (GTK_ENTRY(input3),"");
  gtk_entry_set_text (GTK_ENTRY(input5),"");
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(input6),1);
  gtk_combo_box_set_active(GTK_COMBO_BOX(input7),0);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(input8),2020);
  gtk_text_buffer_delete (buffer,&start,&end);
   gtk_text_buffer_set_text(buffer,"",strlen(N.message));
}
}


void
on_retourdh7_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *lirerecladh,*dhafer3,*clistdh2 ;
dhafer3=create_dhafer3();
gtk_widget_show(dhafer3);
lirerecladh=lookup_widget(objet,"lirerecladh");
gtk_widget_hide(lirerecladh);
clistdh2=lookup_widget(dhafer3,"clistdh2");
afficher_recla(clistdh2);
}

//amin
void
on_Gestionclients_clicked              (GtkWidget       *objet,  gpointer         user_data)
{
GtkWidget *Espaceagent;
GtkWidget *ajouterclient;

Espaceagent=lookup_widget(objet,"Espaceagent");

gtk_widget_destroy(Espaceagent);
ajouterclient=lookup_widget(objet,"ajouterclient");
ajouterclient=create_ajouterclient();

gtk_widget_show(ajouterclient);
}


void
on_Gestionvols_clicked                 (GtkWidget       *objet,   gpointer         user_data)
{
GtkWidget *Espaceagent;
GtkWidget *Gestionvol,*treeview21;

Espaceagent=lookup_widget(objet,"Espaceagent");

gtk_widget_destroy(Espaceagent);
Gestionvol=lookup_widget(objet,"Gestionvol");
Gestionvol=create_Gestionvol();

gtk_widget_show(Gestionvol);
treeview21=lookup_widget(Gestionvol,"treeview21");

afficher_vol(treeview21);
}





void
on_modifier_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void
on_supprimera_clicked                  (GtkWidget       *objet,   gpointer         user_data)
{
GtkWidget *Gestionclient;
GtkWidget *supclient;
Gestionclient=lookup_widget(objet,"Gestionclient");

gtk_widget_destroy(Gestionclient);
supclient=lookup_widget(objet,"supclient");
supclient=create_supclient();

gtk_widget_show(supclient);
}





void
on_Retoura1_clicked                    (GtkWidget       *objet,   gpointer         user_data)
{
GtkWidget *Gestionclient;
GtkWidget *Espaceagent;
Gestionclient=lookup_widget(objet,"Gestionclient");

gtk_widget_destroy(Gestionclient);
Espaceagent=lookup_widget(objet,"Espaceagent");
Espaceagent=create_Espaceagent();

gtk_widget_show(Espaceagent);
}



void
on_listc_clicked                       (GtkWidget       *objet,  gpointer         user_data)
{
GtkWidget *ajouterclient;
GtkWidget *listesclienttree;
GtkWidget *treeview01;

ajouterclient=lookup_widget(objet,"ajouterclient");

gtk_widget_destroy(ajouterclient);
listesclienttree=lookup_widget(objet,"listesclienttree");
listesclienttree=create_listesclienttree();

gtk_widget_show(listesclienttree);

treeview01=lookup_widget(listesclienttree,"treeview01");

afficher_personne(treeview01);

}



void
on_valider01_clicked                   (GtkWidget       *objet,     gpointer         user_data)
{
personne p;
GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*output,*output2;
GtkWidget *ajouterclient;
GtkWidget *listesclienttree,*treeview01;
int e=0;
ajouterclient=lookup_widget(objet,"ajouterclient");
output=lookup_widget(objet,"msg_cin");
output2=lookup_widget(objet,"msg_out");
input1=lookup_widget(objet,"Cin01");
input2=lookup_widget(objet,"Nom01");
input3=lookup_widget(objet,"Prenom01");
input4=lookup_widget(objet,"Adressmail01");
input5=lookup_widget(objet,"Login01");
input6=lookup_widget(objet,"Passworld01");
input7=lookup_widget(objet,"Telephone01");
if (strlen(gtk_entry_get_text(GTK_ENTRY(input1)))!=8 || !vermaj(gtk_entry_get_text(GTK_ENTRY(input1))))		//controle de saisie CIN
{gtk_label_set_text(GTK_LABEL(output),"numero de cin errone");
e=1;}
else {strcpy(p.Cin01,gtk_entry_get_text(GTK_ENTRY(input1)));
gtk_widget_hide(output);}
strcpy(p.Nom01,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.Prenom01,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(p.Adressmail01,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(p.Login01,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(p.Passworld01,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(p.Telephone01,gtk_entry_get_text(GTK_ENTRY(input7)));
if (e==1)
gtk_label_set_text(GTK_LABEL(output2),"Utilisateur non cree"); //MSG erreur
else{
ajouter_personne(p);
gtk_label_set_text(GTK_LABEL(output2),"Utilisateur cree");}
}









void
on_Retoura2_clicked                    (GtkWidget       *objet,     gpointer         user_data)
{
GtkWidget *ajouterclient;
GtkWidget *Espaceagent;

ajouterclient=lookup_widget(objet,"ajouterclient");

gtk_widget_destroy(ajouterclient);
Espaceagent=lookup_widget(objet,"Espaceagent");
Espaceagent=create_Espaceagent();

gtk_widget_show(Espaceagent);
}


void
on_Retour03_clicked                    (GtkWidget       *objet,   gpointer         user_data)
{
GtkWidget *listesclienttree;
GtkWidget *ajouterclient;
listesclienttree=lookup_widget(objet,"listesclienttree");

gtk_widget_destroy(listesclienttree);
ajouterclient=lookup_widget(objet,"ajouterclient");
ajouterclient=create_ajouterclient();

gtk_widget_show(ajouterclient);
}


void
on_modifiervol_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{

}





void
on_ajoutervol_clicked                  (GtkWidget       *objet,  gpointer         user_data)
{
GtkWidget *Gestionvol;
GtkWidget *ajoutervol;

Gestionvol=lookup_widget(objet,"Gestionvol");

gtk_widget_destroy(Gestionvol);
ajoutervol=lookup_widget(objet,"ajoutervol");
ajoutervol=create_ajoutervol();

gtk_widget_show(ajoutervol);
}

/*
void
on_Retour05_clicked                    (GtkButton       *objet, gpointer         user_data)
{
GtkWidget *ajoutervol;
GtkWidget *Gestionvol;

ajoutervol=lookup_widget(objet,"ajoutervol");

gtk_widget_destroy(ajoutervol);
Gestionvol=lookup_widget(objet,"Gestionvol");
Gestionvol=create_Gestionvol();

gtk_widget_show(Gestionvol);
}
*/

void
on_ajouter02_clicked                   (GtkWidget       *objet, gpointer         user_data)
{
vol v;
GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7;
GtkWidget *ajoutervol;
GtkWidget *Gestionvol,*treeview21;

ajoutervol=lookup_widget(objet,"ajoutervol");

input1=lookup_widget(objet,"code01");
input2=lookup_widget(objet,"date01");
input3=lookup_widget(objet,"heure01");
input4=lookup_widget(objet,"depart01");
input5=lookup_widget(objet,"arrivee01");
input6=lookup_widget(objet,"prix01");
input7=lookup_widget(objet,"placedis01");

strcpy(v.code01,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(v.date01,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(v.heure01,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(v.depart01,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(v.arrivee01,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(v.prix01,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(v.placedis01,gtk_entry_get_text(GTK_ENTRY(input7)));

ajouter_vol(v);
treeview21=lookup_widget(objet,"treeview21");
gtk_widget_destroy(ajoutervol);
Gestionvol=lookup_widget(objet,"Gestionvol");
Gestionvol=create_Gestionvol();
gtk_widget_show(Gestionvol);
treeview21=lookup_widget(Gestionvol,"treeview21");

afficher_vol(treeview21);
}


void
on_Retour04_clicked                    (GtkWidget       *objet,    gpointer         user_data)
{
GtkWidget *Gestionvol;
GtkWidget *Espaceagent;

Gestionvol=lookup_widget(objet,"Gestionvol");

gtk_widget_destroy(Gestionvol);
Espaceagent=lookup_widget(objet,"Espaceagent");
Espaceagent=create_Espaceagent();

gtk_widget_show(Espaceagent);
}


void
on_demandec_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void
on_Retour06_clicked                    (GtkWidget       *objet,   gpointer         user_data)
{
GtkWidget *listesvoltree;
GtkWidget *ajoutervol;

listesvoltree=lookup_widget(objet,"listesvoltree");

gtk_widget_destroy(listesvoltree);
ajoutervol=lookup_widget(objet,"ajoutervol");
ajoutervol=create_ajoutervol();

gtk_widget_show(ajoutervol);
}


void
on_deleteclient_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void
on_retour07_clicked                    (GtkWidget       *objet,  gpointer         user_data)
{
GtkWidget *supclient;
GtkWidget *ajouterclient;

supclient=lookup_widget(objet,"supclient");

gtk_widget_destroy(supclient);
ajouterclient=lookup_widget(objet,"ajouterclient");
ajouterclient=create_ajouterclient();

gtk_widget_show(ajouterclient);
}


void
on_suppvol_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void
on_retour08_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void
on_Ges_reserv_clicked                  (GtkWidget       *objet,   gpointer         user_data)
{
GtkWidget *Espaceagent;
GtkWidget *Reservation_ag;

Espaceagent=lookup_widget(objet,"Espaceagent");

gtk_widget_destroy(Espaceagent);
Reservation_ag=lookup_widget(objet,"reservation_ag");
Reservation_ag=create_Reservation_ag();

gtk_widget_show(Reservation_ag);
}


void
on_retour11_clicked                    (GtkWidget       *objet,  gpointer         user_data)
{
GtkWidget *win_reservation;
GtkWidget *Espaceagent;

win_reservation=lookup_widget(objet,"win_reservation");

gtk_widget_destroy(win_reservation);
Espaceagent=lookup_widget(objet,"Espaceagent");
Espaceagent=create_Espaceagent();

gtk_widget_show(Espaceagent);
}


void
on_rech_client_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void
on_modifier_client_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void
on_conxagent_clicked                   (GtkWidget       *objet,  gpointer         user_data)
{
FILE*f;
GtkWidget *input1,*input2,*output,*log_agent,*Espaceagent;
char username[20],password[20],user[20],pass[20];
int trouve=0;
int role ;
input1=lookup_widget(objet,"entry1log");
input2=lookup_widget(objet,"entry2mp");
output=lookup_widget(objet,"label69msg");
strcpy(username,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(password,gtk_entry_get_text(GTK_ENTRY(input2)));

f=fopen("log.txt","r");
if(f!=NULL){
while(fscanf(f,"%s %s %d",user,pass,&role)!=EOF){
if(strcmp(username,user)==0 && strcmp(password,pass)==0){
trouve++;

if(trouve!=0){

 if (role==2){
Espaceagent=create_Espaceagent();
gtk_widget_show(Espaceagent);
log_agent=lookup_widget(objet,"log_agent");
gtk_widget_hide(log_agent);
}

}
}
}
}fclose(f);

if(trouve==0){
gtk_label_set_text(GTK_LABEL(output),"nom d'utilisateur ou mot de passe incorrect !!!!");
gtk_entry_set_text(GTK_ENTRY(input2),"");
}
}



void
on_deconect_clicked                    (GtkWidget       *objet,  gpointer         user_data)
{
GtkWidget *Espaceagent;
GtkWidget *window1;

Espaceagent=lookup_widget(objet,"Espaceagent");

gtk_widget_destroy(Espaceagent);
window1=lookup_widget(objet,"window1");
window1=create_window1();

gtk_widget_show(window1);
}


void
on_find_vol_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
/*
 char code01 [30];
vol v ;
GtkWidget *Gestionvol;
GtkWidget *input;
GtkWidget *treeview21;
FILE*f;
FILE*f2;


Gestionvol=lookup_widget(objet,"Gestionvol");
input=lookup_widget(objet,"findvol");
strcpy(code01,gtk_entry_get_text(GTK_ENTRY(input)));
f=fopen("vol.txt","r");

 if(f!=NULL)
 {
  while(fscanf(f,"%s %s %s %s %s %s %s \n",v.code01,v.date01,v.heure01,v.depart01,v.arrivee01,v.prix01,v.placedis01)!=EOF)
     {
       f2=fopen("chercher.txt","a+");
       if  (f2!=NULL)
   {  
     
     if ((strcmp(v.code01,vol)==0) )
     { 
     fprintf(f2,"%s %s %s %s %s %s %s \n",v.code01,v.date01,v.heure01,v.depart01,v.arrivee01,v.prix01,v.placedis01);
     }
   
     treeview21=lookup_widget(Gestionvol,"treeview21");
     chercher_vol(treeview21);
    
        fclose(f2);
    }

 }
 fclose(f);
}
remove("chercher.txt");
*/
}




void
on_treeview01_row_activated            (GtkTreeView     *treeview, GtkTreePath     *path,  GtkTreeViewColumn *column,
                                        gpointer         user_data)

{

gchar *cin;
gchar *Num;
gchar *Pr;
gchar *Adress;
gchar *login;
gchar *pass;
gchar *tel;
GtkWidget *window1;
GtkWidget *window2;
GtkTreeIter iter;
GtkWidget *output1;
GtkWidget *output2;
GtkWidget *output3;
GtkWidget *output4;
GtkWidget *output5;
GtkWidget *output6;
GtkWidget *output7;


	window1=lookup_widget(treeview,"listesclienttree");
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	if(gtk_tree_model_get_iter(model,&iter,path))
	{
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&cin,1,&Num,2,&Pr,3,&Adress,4,&login,5,&pass,6,&tel,-1);}
	window2 = create_modif_cli();
	gtk_widget_hide (window1);
	gtk_widget_show (window2);

	output1=lookup_widget(window2,"entry0modif");
	output2=lookup_widget(window2,"entry1modif");
	output3=lookup_widget(window2,"entry2modif");
	output4=lookup_widget(window2,"entry3modif");
	output5=lookup_widget(window2,"entry4modif");
	output6=lookup_widget(window2,"entry5modif");
	output7=lookup_widget(window2,"entry6modif");

	gtk_entry_set_text(GTK_ENTRY(output1),cin);	
	gtk_entry_set_text(GTK_ENTRY(output2),Num);
	gtk_entry_set_text(GTK_ENTRY(output3),Pr);
	gtk_entry_set_text(GTK_ENTRY(output4),Adress);
	gtk_entry_set_text(GTK_ENTRY(output5),login);
	gtk_entry_set_text(GTK_ENTRY(output6),pass);
	gtk_entry_set_text(GTK_ENTRY(output7),tel);

}


void
on_sup_client_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2;

	window1=lookup_widget(objet,"modif_cli");
	gtk_widget_hide(window1);
	window2 = create_oui_supp();
	gtk_widget_show (window2);
	
GtkWidget *input2,*input3,*input4,*input5,*input6,*input7,*input8;
char Cin01[20];
char Nom01[20];
char Prenom01[10];
char Adreemail01[20];
char Login01[20];
char passworld01[10];
char Telephone01[10];
char CIN[20];
char NOM[20];
char PRENOM[20];
char ADRESS[20];
char LOGIN[20];
char PASSWORD[20];
char TELEPHONE[20];
char d[20];
char a[20];
char b[20];
char c[20];
char e[20];
char s[20];
char t[20];
FILE* f;
FILE* f1;

	input2 = lookup_widget(objet, "entry0modif");
	input3 = lookup_widget(objet, "entry1modif");
	input4 = lookup_widget(objet, "entry2modif");
	input5 = lookup_widget(objet, "entry3modif");
	input6 = lookup_widget(objet, "entry4modif");
	input7 = lookup_widget(objet, "entry5modif");
	input8 = lookup_widget(objet, "entry6modif");

	strcpy(Cin01, gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(Nom01, gtk_entry_get_text(GTK_ENTRY(input3)));
	strcpy(Prenom01, gtk_entry_get_text(GTK_ENTRY(input4)));
	strcpy(Adreemail01, gtk_entry_get_text(GTK_ENTRY(input5)));
	strcpy(Login01, gtk_entry_get_text(GTK_ENTRY(input6)));
	strcpy(passworld01, gtk_entry_get_text(GTK_ENTRY(input7)));
	strcpy(Telephone01, gtk_entry_get_text(GTK_ENTRY(input8)));

	f=fopen("client.txt","r");
	f1=fopen("clientx.txt","w+");
	while(fscanf(f,"%s %s %s %s %s %s %s\n",CIN,NOM,PRENOM,ADRESS,LOGIN,PASSWORD,TELEPHONE)!=EOF)
	{
		if ((strcmp(Cin01,CIN)!=0))
		
		fprintf(f1,"%s %s %s %s %s %s %s\n",CIN,NOM,PRENOM,ADRESS,LOGIN,PASSWORD,TELEPHONE);
		
	}
	fclose(f);
	fclose(f1);
	f1=fopen("clientx.txt","r");
	f=fopen("client.txt","w+");
	while(fscanf(f1,"%s %s %s %s %s %s %s\n",a,b,c,d,e,s,t)!=EOF)
	{
		fprintf(f,"%s %s %s %s %s %s %s\n",a,b,c,d,e,s,t);	
		
	}
	fclose(f);
	fclose(f1);
}




void
on_modif_client_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1, *window2;

	window1=lookup_widget(objet,"modif_cli");
	gtk_widget_hide(window1);
	window2 = create_clientmodifi();
	gtk_widget_show(window2);
GtkWidget *input2,*input3,*input4,*input5,*input6,*input7,*input8;
char Cin01[20];
char Nom01[20];
char Prenom01[10];
char Adreemail01[20];
char Login01[20];
char passworld01[10];
char Telephone01[10];
char CIN[20];
char NOM[20];
char PRENOM[20];
char ADRESS[20];
char LOGIN[20];
char PASSWORD[20];
char TELEPHONE[20];
char d[20];
char a[20];
char b[20];
char c[20];
char e[20];
char s[20];
char t[20];
FILE* f;
FILE* f1;

	input2 = lookup_widget(objet, "entry0modif");
	input3 = lookup_widget(objet, "entry1modif");
	input4 = lookup_widget(objet, "entry2modif");
	input5 = lookup_widget(objet, "entry3modif");
	input6 = lookup_widget(objet, "entry4modif");
	input7 = lookup_widget(objet, "entry5modif");
	input8 = lookup_widget(objet, "entry6modif");

	strcpy(Cin01, gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(Nom01, gtk_entry_get_text(GTK_ENTRY(input3)));
	strcpy(Prenom01, gtk_entry_get_text(GTK_ENTRY(input4)));
	strcpy(Adreemail01, gtk_entry_get_text(GTK_ENTRY(input5)));
	strcpy(Login01, gtk_entry_get_text(GTK_ENTRY(input6)));
	strcpy(passworld01, gtk_entry_get_text(GTK_ENTRY(input7)));
	strcpy(Telephone01, gtk_entry_get_text(GTK_ENTRY(input8)));

	f=fopen("client.txt","r");
	f1=fopen("clientx.txt","w+");
	while(fscanf(f,"%s %s %s %s %s %s %s\n",CIN,NOM,PRENOM,ADRESS,LOGIN,PASSWORD,TELEPHONE)!=EOF)
	{
		if ((strcmp(Cin01,CIN)!=0))
		
		fprintf(f1,"%s %s %s %s %s %s %s\n",CIN,NOM,PRENOM,ADRESS,LOGIN,PASSWORD,TELEPHONE);
		
	}
	fclose(f);
	fclose(f1);
	f1=fopen("clientx.txt","r");
	f=fopen("client.txt","w+");
	while(fscanf(f1,"%s %s %s %s %s %s %s\n",a,b,c,d,e,s,t)!=EOF)
	{
		fprintf(f,"%s %s %s %s %s %s %s\n",a,b,c,d,e,s,t);	
		
	}
	fclose(f);
	fclose(f1);
	f=fopen("client.txt","a+");
	fprintf(f,"%s %s %s %s %s %s %s\n",Cin01,Nom01,Prenom01,Adreemail01,Login01,passworld01,Telephone01);
	fclose(f);
}




void
on_retour10_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void
on_oui1_clicked                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *output,*input1;


	output=lookup_widget(objet,"succ_sup");
	input1=lookup_widget(objet,"succ_sup");

	gtk_label_set_text(GTK_LABEL(input1),"");
	gtk_label_set_text(GTK_LABEL(output),"Agent supprimé!!!!!! ");
}


void
on_non1_clicked                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *oui_supp;
GtkWidget *listesclienttree;
GtkWidget *treeview01;

	oui_supp=lookup_widget(objet,"oui_supp");
	
	gtk_widget_destroy(oui_supp);
	listesclienttree=create_listesclienttree();
	gtk_widget_show(listesclienttree);
	treeview01=lookup_widget(listesclienttree,"treeview01");

afficher_personne(treeview01);
}


void
on_retour20_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *clientmodifi;
GtkWidget *listesclienttree;
GtkWidget *treeview01;

	clientmodifi=lookup_widget(objet,"clientmodifi");
	
	gtk_widget_destroy(clientmodifi);
	listesclienttree=create_listesclienttree();
	gtk_widget_show(listesclienttree);
	treeview01=lookup_widget(listesclienttree,"treeview01");

afficher_personne(treeview01);
}


void
on_treeview21_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
gchar *code;
gchar *date;
gchar *hr;
gchar *de;
gchar *ar;
gchar *px;
gchar *pd;
GtkWidget *window1;
GtkWidget *window2;
GtkTreeIter iter;
GtkWidget *output1;
GtkWidget *output2;
GtkWidget *output3;
GtkWidget *output4;
GtkWidget *output5;
GtkWidget *output6;
GtkWidget *output7;


	window1=lookup_widget(treeview,"Gestionvol");
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	if(gtk_tree_model_get_iter(model,&iter,path))
	{
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&code,1,&date,2,&hr,3,&de,4,&ar,5,&px,6,&pd,-1);}
	window2 = create_modifvol();
	gtk_widget_hide (window1);
	gtk_widget_show (window2);

	output1=lookup_widget(window2,"entry1s");
	output2=lookup_widget(window2,"entry2s");
	output3=lookup_widget(window2,"entry3s");
	output4=lookup_widget(window2,"entry4s");
	output5=lookup_widget(window2,"entry5s");
	output6=lookup_widget(window2,"entry6s");
	output7=lookup_widget(window2,"entry7s");

	gtk_entry_set_text(GTK_ENTRY(output1),code);	
	gtk_entry_set_text(GTK_ENTRY(output2),date);
	gtk_entry_set_text(GTK_ENTRY(output3),hr);
	gtk_entry_set_text(GTK_ENTRY(output4),de);
	gtk_entry_set_text(GTK_ENTRY(output5),ar);
	gtk_entry_set_text(GTK_ENTRY(output6),px);
	gtk_entry_set_text(GTK_ENTRY(output7),pd);
}


void
on_delll_vol_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2;

	window1=lookup_widget(objet,"modifvol");
	gtk_widget_hide(window1);
	window2 = create_vol_sup();
	gtk_widget_show (window2);
	
GtkWidget *input2,*input3,*input4,*input5,*input6,*input7,*input8;
char code01[30];
char date01 [30];
char heure01 [30];
char depart01 [30];
char arrivee01 [30];
char prix01[30];
char placedis01 [30];
char CODE[20];
char DATE[20];
char HEURE[20];
char DEPART[20];
char ARRIVEE[20];
char PRIX[20];
char PLACE[20];
char d[20];
char a[20];
char b[20];
char c[20];
char e[20];
char s[20];
char t[20];
FILE* f;
FILE* f1;

	input2 = lookup_widget(objet, "entry1s");
	input3 = lookup_widget(objet, "entry2s");
	input4 = lookup_widget(objet, "entry3s");
	input5 = lookup_widget(objet, "entry4s");
	input6 = lookup_widget(objet, "entry5s");
	input7 = lookup_widget(objet, "entry6s");
	input8 = lookup_widget(objet, "entry7s");

	strcpy(code01, gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(date01, gtk_entry_get_text(GTK_ENTRY(input3)));
	strcpy(heure01, gtk_entry_get_text(GTK_ENTRY(input4)));
	strcpy(depart01, gtk_entry_get_text(GTK_ENTRY(input5)));
	strcpy(arrivee01, gtk_entry_get_text(GTK_ENTRY(input6)));
	strcpy(prix01, gtk_entry_get_text(GTK_ENTRY(input7)));
	strcpy(placedis01, gtk_entry_get_text(GTK_ENTRY(input8)));

	f=fopen("vol.txt","r");
	f1=fopen("volx.txt","w+");
	while(fscanf(f,"%s %s %s %s %s %s %s\n",CODE,DATE,HEURE,DEPART,ARRIVEE,PRIX,PLACE)!=EOF)
	{
		if ((strcmp(code01,CODE)!=0))
		
		fprintf(f1,"%s %s %s %s %s %s %s\n",CODE,DATE,HEURE,DEPART,ARRIVEE,PRIX,PLACE);
		
	}
	fclose(f);
	fclose(f1);
	f1=fopen("volx.txt","r");
	f=fopen("vol.txt","w+");
	while(fscanf(f1,"%s %s %s %s %s %s %s\n",a,b,c,d,e,s,t)!=EOF)
	{
		fprintf(f,"%s %s %s %s %s %s %s\n",a,b,c,d,e,s,t);	
		
	}
	fclose(f);
	fclose(f1);
}


void
on_modiff_vol_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1, *window2;

	window1=lookup_widget(objet,"modifvol");
	gtk_widget_hide(window1);
	window2 = create_vol_mod();
	gtk_widget_show(window2);
GtkWidget *input2,*input3,*input4,*input5,*input6,*input7,*input8;
char code01[30];
char date01 [30];
char heure01 [30];
char depart01 [30];
char arrivee01 [30];
char prix01[30];
char placedis01 [30];
char CODE[20];
char DATE[20];
char HEURE[20];
char DEPART[20];
char ARRIVEE[20];
char PRIX[20];
char PLACE[20];
char d[20];
char a[20];
char b[20];
char c[20];
char e[20];
char s[20];
char t[20];
FILE* f;
FILE* f1;

	input2 = lookup_widget(objet, "entry1s");
	input3 = lookup_widget(objet, "entry2s");
	input4 = lookup_widget(objet, "entry3s");
	input5 = lookup_widget(objet, "entry4s");
	input6 = lookup_widget(objet, "entry5s");
	input7 = lookup_widget(objet, "entry6s");
	input8 = lookup_widget(objet, "entry7s");

	strcpy(code01, gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(date01, gtk_entry_get_text(GTK_ENTRY(input3)));
	strcpy(heure01, gtk_entry_get_text(GTK_ENTRY(input4)));
	strcpy(depart01, gtk_entry_get_text(GTK_ENTRY(input5)));
	strcpy(arrivee01, gtk_entry_get_text(GTK_ENTRY(input6)));
	strcpy(prix01, gtk_entry_get_text(GTK_ENTRY(input7)));
	strcpy(placedis01, gtk_entry_get_text(GTK_ENTRY(input8)));

	f=fopen("vol.txt","r");
	f1=fopen("volx.txt","w+");
	while(fscanf(f,"%s %s %s %s %s %s %s\n",CODE,DATE,HEURE,DEPART,ARRIVEE,PRIX,PLACE)!=EOF)
	{
		if ((strcmp(code01,CODE)!=0))
		
		fprintf(f1,"%s %s %s %s %s %s %s\n",CODE,DATE,HEURE,DEPART,ARRIVEE,PRIX,PLACE);
		
		
	}
	fclose(f);
	fclose(f1);
	f1=fopen("volx.txt","r");
	f=fopen("vol.txt","w+");
	while(fscanf(f1,"%s %s %s %s %s %s %s\n",a,b,c,d,e,s,t)!=EOF)
	{
		fprintf(f,"%s %s %s %s %s %s %s\n",a,b,c,d,e,s,t);	
		
	}
	fclose(f);
	fclose(f1);
	f=fopen("vol.txt","a+");
	fprintf(f,"%s %s %s %s %s %s %s\n",code01,date01,heure01,depart01,arrivee01,prix01,placedis01);
	fclose(f);
}


void
on_retour30_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *modifvol;
GtkWidget *Gestionvol;
GtkWidget *treeview21;

	modifvol=lookup_widget(objet,"modifvol");
	
	gtk_widget_destroy(modifvol);
	Gestionvol=create_Gestionvol();
	gtk_widget_show(Gestionvol);
	treeview21=lookup_widget(Gestionvol,"treeview21");

afficher_vol(treeview21);
}


void
on_retour31_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *vol_sup;
GtkWidget *Gestionvol;
GtkWidget *treeview21;

	vol_sup=lookup_widget(objet,"vol_sup");
	
	gtk_widget_destroy(vol_sup);
	Gestionvol=create_Gestionvol();
	gtk_widget_show(Gestionvol);
	treeview21=lookup_widget(Gestionvol,"treeview21");

afficher_vol(treeview21);
}


void
on_retour32_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *vol_mod;
GtkWidget *Gestionvol;
GtkWidget *treeview21;

	vol_mod=lookup_widget(objet,"vol_mod");
	
	gtk_widget_destroy(vol_mod);
	Gestionvol=create_Gestionvol();
	gtk_widget_show(Gestionvol);
	treeview21=lookup_widget(Gestionvol,"treeview21");

afficher_vol(treeview21);
}


void
on_retour34_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Reservation_ag;
GtkWidget *Espaceagent;

Reservation_ag=lookup_widget(objet,"Reservation_ag");

gtk_widget_destroy(Reservation_ag);
Espaceagent=lookup_widget(objet,"Espaceagent");
Espaceagent=create_Espaceagent();

gtk_widget_show(Espaceagent);
}


void
on_ges_ex_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Espaceagent;
GtkWidget *window1voy;

Espaceagent=lookup_widget(objet,"Espaceagent");

gtk_widget_destroy(Espaceagent);
window1voy=lookup_widget(objet,"window1voy");
window1voy=create_window1voy();

gtk_widget_show(window1voy);
}


void
on_ges_heberg_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Espaceagent;
GtkWidget *window1h;

Espaceagent=lookup_widget(objet,"Espaceagent");

gtk_widget_destroy(Espaceagent);
window1h=lookup_widget(objet,"window1h");
window1h=create_window1h();

gtk_widget_show(window1h);
}

//voyage
void
on_button1voy_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
reserve e;
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input6;
GtkWidget *window1voy;
GtkWidget *window2;
GtkWidget *window3;
GtkWidget *treeview1;

window1voy=lookup_widget(button,"window1voy");
input1=lookup_widget(button,"entry1voy");
input2=lookup_widget(button,"entry2voy");
input3=lookup_widget(button,"entry3voy");
input4=lookup_widget(button,"entry4voy");
input5=lookup_widget(button,"entry5voy");
input6=lookup_widget(button,"entry6voy");
strcpy(e.id_de_voyage,gtk_entry_get_text(GTK_ENTRY (input1)));
strcpy(e.destination,gtk_entry_get_text(GTK_ENTRY (input2)));
strcpy(e.date_dep,gtk_entry_get_text(GTK_ENTRY (input3)));
strcpy(e.date_arr,gtk_entry_get_text(GTK_ENTRY (input4)));
strcpy(e.nombre_de_personne,gtk_entry_get_text(GTK_ENTRY (input5)));
strcpy(e.prix,gtk_entry_get_text(GTK_ENTRY (input6)));
ajouter_reservations(e);

      GtkWidget *ajoutvoy;
      ajoutvoy=create_ajoutvoy();
      gtk_widget_show(ajoutvoy);
gtk_entry_set_text(GTK_ENTRY(input1),"");
gtk_entry_set_text(GTK_ENTRY(input2),"");
gtk_entry_set_text(GTK_ENTRY(input3),"");
gtk_entry_set_text(GTK_ENTRY(input4),"");
gtk_entry_set_text(GTK_ENTRY(input5),"");
gtk_entry_set_text(GTK_ENTRY(input6),"");
			
		


}


void
on_button3voy_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *list;
  list=lookup_widget(button,"clist1");
  int nbre=0,i=0,j;
  char *p[QA][6]={{" "," "," "," "," "," "}};
  reserve Res[QA],R;
  FILE *text;
  text=fopen("reservations.txt","r");
    if(text!=NULL)
    {
      while((fscanf(text,"%s %s %s %s %s %s  ",R.id_de_voyage,R.destination,R.date_dep,R.date_arr,R.nombre_de_personne,R.prix)!=EOF))
      {
        strcpy(Res[i].id_de_voyage,R.id_de_voyage);
        strcpy(Res[i].destination,R.destination);
	strcpy(Res[i].date_dep,R.date_dep);
	strcpy(Res[i].date_arr,R.date_arr);
        strcpy(Res[i].nombre_de_personne,R.nombre_de_personne);
	strcpy(Res[i].prix,R.prix);
        
        
        i++;
      }
      nbre=i;
      fclose(text);
    }
	gtk_clist_clear(GTK_CLIST(list));

for(j=0;j<nbre;j++)
    {
      gtk_clist_append(GTK_CLIST(list),p[j]);
    }
    
    
    gtk_clist_set_row_height(GTK_CLIST(list),30);
      
	for(i=0;i<nbre;i++){
        gtk_clist_set_text(GTK_CLIST(list),i,0,Res[i].id_de_voyage);
      }
	for(i=0;i<nbre;i++){
        gtk_clist_set_text(GTK_CLIST(list),i,1,Res[i].destination);
      }
	for(i=0;i<nbre;i++){
        gtk_clist_set_text(GTK_CLIST(list),i,2,Res[i].date_dep);
      }
	for(i=0;i<nbre;i++){
        gtk_clist_set_text(GTK_CLIST(list),i,3,Res[i].date_arr);
      }
	for(i=0;i<nbre;i++){
        gtk_clist_set_text(GTK_CLIST(list),i,4,Res[i].nombre_de_personne);
      }
	for(i=0;i<nbre;i++){
        gtk_clist_set_text(GTK_CLIST(list),i,5,Res[i].prix);
      }
	
      
}


void
on_button4voy_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *input1, *input2, *input3, *input4, *input5, *output ;
GtkWidget *inputid_de_voyage ;
reserve e;
char id_de_voyage[30];
FILE *f;
input1=lookup_widget(button,"entry8voy");
input2=lookup_widget(button,"entry9voy");
input3=lookup_widget(button,"entry10voy");
input4=lookup_widget(button,"entry11voy");
input5=lookup_widget(button,"entry12voy");


inputid_de_voyage=lookup_widget(button,"entry7voy");
output=lookup_widget(button,"label29");
strcpy(id_de_voyage,gtk_entry_get_text(GTK_ENTRY(inputid_de_voyage)));

if(strcmp(id_de_voyage,"")==0){
gtk_label_set_text(GTK_LABEL(output),"entrer un code svp !!!");
}
else{
f=fopen("reservations.txt","r");
if(f!=NULL){
while(fscanf(f,"%s %s %s %s %s %s ",e.id_de_voyage,e.destination,e.date_dep,e.date_arr,e.nombre_de_personne,e.prix)!=EOF){
if(strcmp(e.id_de_voyage,id_de_voyage)==0){ 
gtk_entry_set_text(GTK_ENTRY(input1),e.destination);
gtk_entry_set_text(GTK_ENTRY(input2),e.date_dep);
gtk_entry_set_text(GTK_ENTRY(input3),e.date_arr);
gtk_entry_set_text(GTK_ENTRY(input4),e.nombre_de_personne);
gtk_entry_set_text(GTK_ENTRY(input5),e.prix);

gtk_label_set_text(GTK_LABEL(output),"");
}	
}
fclose(f);
}
}
}


void
on_button5voy_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input6;
reserve e;
char matricule[30];

input1=lookup_widget(button,"entry8voy");
input2=lookup_widget(button,"entry9voy");
input3=lookup_widget(button,"entry10voy");
input4=lookup_widget(button,"entry11voy");
input5=lookup_widget(button,"entry12voy");
input6=lookup_widget(button,"entry7voy");

strcpy(e.destination,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(e.date_dep,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(e.date_arr,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(e.nombre_de_personne,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(e.prix,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(e.id_de_voyage,gtk_entry_get_text(GTK_ENTRY(input6)));

strcpy(matricule,gtk_entry_get_text(GTK_ENTRY(input6)));

modifier_reservations(e,matricule);
//supprimer_reservation(e,matricule);
//ajouter_reservation(e);
GtkWidget *modifiervoy;
      modifiervoy=create_modifiervoy();
      gtk_widget_show(modifiervoy);


gtk_entry_set_text(GTK_ENTRY(input1),"");
gtk_entry_set_text(GTK_ENTRY(input2),"");
gtk_entry_set_text(GTK_ENTRY(input3),"");
gtk_entry_set_text(GTK_ENTRY(input4),"");
gtk_entry_set_text(GTK_ENTRY(input5),"");
gtk_entry_set_text(GTK_ENTRY(input6),"");


}


void
on_button6voy_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *input1,*output;
char code[30];
reserve e;
reserve n;

input1=lookup_widget(button,"entry13voy");
output=lookup_widget(button,"label32");


strcpy(code,gtk_entry_get_text(GTK_ENTRY(input1)));
n=rechercher_rese(code);
if(strcmp(code,"")==0){
gtk_label_set_text(GTK_LABEL(output),"entrer un code svp !!");
}
else{
if(strcmp(n.id_de_voyage,code)==0){
supprimer_reservations(e,code);
gtk_entry_set_text(GTK_ENTRY(input1),"");
gtk_label_set_text(GTK_LABEL(output),"");

GtkWidget *supprimervoy;
      supprimervoy=create_supprimervoy();
      gtk_widget_show(supprimervoy);
}
else{
gtk_label_set_text(GTK_LABEL(output),"voyage inexistante");
}
}

}


void
on_button2voy_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajoutvoy;
ajoutvoy=lookup_widget(button,"ajoutvoy");
gtk_widget_hide(ajoutvoy);
}


void
on_button7voy_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *supprimervoy;
supprimervoy=lookup_widget(button,"supprimervoy");
gtk_widget_hide(supprimervoy);
}


void
on_button8voy_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *modifiervoy;
modifiervoy=lookup_widget(button,"modifiervoy");
gtk_widget_hide(modifiervoy);

}

//hebergement




void
on_button158_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *accueil;
GtkWidget *window1;
accueil=lookup_widget(objet,"accueil");

gtk_widget_destroy(accueil);
window1=lookup_widget(objet,"window1");
window1=create_window1();

gtk_widget_show(window1);
}


void
on_gestionvoituresdh_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *dhafer2,*Espaceagent,*clistdh1 ;
dhafer2=create_dhafer2();
gtk_widget_show(dhafer2);
Espaceagent=lookup_widget(objet,"Espaceagent");
gtk_widget_hide(Espaceagent);
clistdh1=lookup_widget(dhafer2,"clistdh1");
afficher_voiture(clistdh1);
}


void
on_gestionfacturesdh_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Espaceagent;
GtkWidget *dhafer1;
GtkWidget *treeviewdh1;

dhafer1=lookup_widget(objet,"dhafer1");
Espaceagent=lookup_widget(objet,"Espaceagent");
dhafer1=create_dhafer1();
gtk_widget_show(dhafer1);
gtk_widget_hide(Espaceagent);

treeviewdh1=lookup_widget(dhafer1,"treeviewdh1");
afficher_facture (treeviewdh1) ;

}


void
on_gestionreclamationsdh_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *dhafer3,*Espaceagent,*clistdh2 ;
dhafer3=create_dhafer3();
gtk_widget_show(dhafer3);
Espaceagent=lookup_widget(objet,"Espaceagent");
gtk_widget_hide(Espaceagent);
clistdh2=lookup_widget(dhafer3,"clistdh2");
afficher_recla(clistdh2);
}


void
on_deconnectdh3_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *dhafer2;
GtkWidget *window1;

dhafer2=lookup_widget(objet,"dhafer2");

gtk_widget_destroy(dhafer2);
window1=lookup_widget(objet,"window1");
window1=create_window1();

gtk_widget_show(window1);
}


void
on_deconnectdh4_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *dhafer3;
GtkWidget *window1;

dhafer3=lookup_widget(objet,"dhafer3");

gtk_widget_destroy(dhafer3);
window1=lookup_widget(objet,"window1");
window1=create_window1();

gtk_widget_show(window1);
}


void
on_decofromvoy_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *window1voy;

window1voy=lookup_widget(objet,"window1voy");

gtk_widget_destroy(window1voy);
window1=lookup_widget(objet,"window1");
window1=create_window1();

gtk_widget_show(window1);
}


void
on_homefromvoy_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Espaceagent;
GtkWidget *window1voy;

window1voy=lookup_widget(objet,"window1voy");

gtk_widget_destroy(window1voy);
Espaceagent=lookup_widget(objet,"Espaceagent");
Espaceagent=create_Espaceagent();

gtk_widget_show(Espaceagent);
}


void
on_homefromh_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Espaceagent;
GtkWidget *window1h;

window1h=lookup_widget(objet,"window1h");

gtk_widget_destroy(window1h);
Espaceagent=lookup_widget(objet,"Espaceagent");
Espaceagent=create_Espaceagent();

gtk_widget_show(Espaceagent);
}


void
on_decofromh_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *window1h;

window1h=lookup_widget(objet,"window1h");

gtk_widget_destroy(window1h);
window1=lookup_widget(objet,"window1");
window1=create_window1();

gtk_widget_show(window1);
}

