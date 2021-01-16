#include <gtk/gtk.h>



typedef struct
{
	int jour;
	int mois;
	int annee;
	char id[50];
	char duree[50];
	char plante[50];
	char type[50];
}zoro;
typedef struct
{
	char id[50];
	char date[50];
	char duree[50];
	char plante[50];
	char type[50];
}sanji;


void ajouter_plant(zoro z);
void afficher_plant(GtkWidget *liste);
void chercher_plant(sanji s,char id[],char date[],char duree[], char plante[], char type[]);
void modifier_plant(sanji s,char id[],char date[],char duree[], char plante[], char type[]);
void supprimer_plant(sanji s, char id[]);
int verif_plant(sanji s, char id[]);
