#include <gtk/gtk.h>
typedef struct 
{
int jour;
char mois[30];
int  annee;

}Date;
typedef struct
{   char nom[15];
char prenom[15] ;
char identifiant [20];
char sexe [10];
Date ddn;
}Ouvrier;

void ajouter_Ouvrier(Ouvrier O);
int supprimer_Ouvrier( Ouvrier o,char id[] );
void afficher(GtkWidget *liste);
int chercher(Ouvrier o,char id[],char nom[], char prenom[],char sexe[],char mois[],int *jour, int *annee);
void Marquer_Presence ( char identifiant [],char jj[],char mm[],char aaaa[],char p []);
int modifier_Ouvrier(Ouvrier o, char nom[],char prenom[],char id [],char sexe [],int jj, char mm[],int aaaa);
int Meilleur_Ouvrier(int annee,int * max);
//int Meilleur_Ouvrier_id(int annee);
//int Meilleur_Ouvrier_max(int annee);


