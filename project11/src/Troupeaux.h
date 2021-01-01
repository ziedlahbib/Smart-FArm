#include<gtk/gtk.h>
typedef struct {
int jj;
int mm;
char aaaa[100];
}Date;
typedef struct {
char Type [100];
char Identifiant [100];
char Sexe [100];
Date ddn;
}Troupeaux;
void ajouter_troupeaux(Troupeaux t);
void afficher_troupeaux(GtkWidget *liste);
void supprimer_troupeaux(Troupeaux t);
Troupeaux chercher(Troupeaux tab[],int n,char IDC[]);
void charger(char *troupeaux,Troupeaux tab[],int *n);
void enregistrer(char *troupeaux,Troupeaux tab[],int *n);
void supprimer(Troupeaux tab[],int *n,char IDS[]);
void modifier_Troupeaux(Troupeaux tab[],int n,char IDM[],Troupeaux t);
int rechercher_troupeaux_par_type(GtkWidget* treeview1,char*troupeaux,char*type,int *n);
