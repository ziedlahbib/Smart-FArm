#include <gtk/gtk.h>


typedef struct
{
    char identifiant[50];
    char nom[50];
    char type[50];
    char marque[50];
    char max[50];
    char min[50];
}capteur;



void ajouter_capt(capteur c);
void afficher_capt(GtkWidget *liste);
void chercher_capt(capteur c,char id[],char nom[],char type[], char marque[], char vmax[] , char vmin[]);
void modifier_capt(capteur c,char id[],char nom[],char type[], char marque[], char vmax[] , char vmin[]);
void supprimer_capt(capteur c , char id[]);
int verif_capt(capteur c , char id[]);
void captAlarm(int t[]);
void afficher_defect(GtkWidget *liste);




typedef struct
{
   int jour;
   int mois;
   int annee;
}date;


typedef struct
{
  char id[50];
  char type[50];
  char max[50];
  char min[50];
}border;




typedef struct
{
   char id[50];
   int jour;
   int mois;
   int annee;
   char valeur[50];
}yoat;


