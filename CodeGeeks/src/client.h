#include <gtk/gtk.h>


typedef struct
{
    char cin[50];
    char nom[50];
    char prenom[50];
    char sexe[50];
    char email[50];
    char phone[50];
}client;
void ajouter_client(client c);
void afficher_client(GtkWidget *liste);
void chercher_client(client c,char cin[],char nom[],char prenom[],char sexe[],char email[], char phone[]);
void modifier_client(client c,char cin[],char nom[],char prenom[],char sexe[],char email[], char phone[]);
void supprimer_client(client c,char cin[]);
int verif_client(client c, char cin[]);
