#include <stdio.h>
#include <string.h>
#include "reclamation.h"
#include "callbacks.h"
#include <gtk/gtk.h>
enum
{

	CIN,
	DESCRIPTION,
	COLUMNS
};

void ajouter_reclamation(Reclamation r)
{

FILE *f;
f=fopen("Reclamation.txt","a+");
	if(f!=NULL)
	{
	fprintf(f,"%s %s \n",r.cin,r.description);
fclose(f);
	}
}

