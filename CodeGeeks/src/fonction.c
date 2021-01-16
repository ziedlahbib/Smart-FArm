#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"


enum
{
   IDENTIFIANT,
   NOM,
   PRENOM,
   SEXE,
   JOUR,
   MOIS,
   ANNEE,
   COLUMNS
};

// fonction ..................................................................................



//Ajouter
void ajouter_Ouvrier(Ouvrier O)
{
FILE *f;
f=fopen("Ouvrier.txt","a");
if(f!=NULL)
  {
  
fprintf(f,"%s %s %s %s %d %s %d \n",O.nom,O.prenom,O.identifiant,O.sexe,O.ddn.jour,O.ddn.mois,O.ddn.annee);
fclose(f);}


}

//Supprimer
int supprimer_Ouvrier( Ouvrier o,char id[] )
{

int S=0;

FILE *f;
FILE *f1 ;
f=fopen("Ouvrier.txt","r") ;
f1=fopen("tmp.txt","w");
if (f== NULL || f1==NULL)
{
return; 
}
else
    {while (fscanf(f,"%s %s %s %s %d %s %d \n" ,o.nom,o.prenom,o.identifiant,o.sexe,&o.ddn.jour,o.ddn.mois,&o.ddn.annee)!=EOF)
    {
    if ((strcmp(id,o.identifiant) != 0) ) 
        {
            fprintf(f1,"%s %s %s %s %d %s %d \n",o.nom,o.prenom,o.identifiant,o.sexe,o.ddn.jour,o.ddn.mois,o.ddn.annee);
        }
    else S=1;
}
    fclose(f1);
    fclose(f);
    remove("Ouvrier.txt");
    rename("tmp.txt","Ouvrier.txt");
 }   
return S;}

//////////////////cherhcher

int chercher(Ouvrier o,char id[],char nom[], char prenom[],char sexe[],char mois[],int *jour, int *annee)
{ int T=0;

  FILE *f;
  f=fopen("Ouvrier.txt","r+");
  if(f==NULL)
  { 
    return;
  }
  else
  { 
    while(fscanf(f,"%s %s %s %s %d %s %d \n",o.nom,o.prenom,o.identifiant,o.sexe,&o.ddn.jour,o.ddn.mois,&o.ddn.annee )!=EOF)
    {
       if(strcmp(o.identifiant,id)==0)
       { 
         strcpy(nom,o.nom);
         strcpy(prenom,o.prenom);
         strcpy(sexe,o.sexe);
         strcpy(mois,o.ddn.mois);
	 *annee=o.ddn.annee;
	 *jour=o.ddn.jour;

	
 	T=1;	
         
       }
   }
   fclose(f);    
   }
   
return T;}


//Afficher

void afficher(GtkWidget *liste)
{
  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;
  
  char a1[50];
  char a2[50];
  char a3[50];
  char a4[50];
  int a5;
  char a6[50];
  int a7;
  store=NULL;
 
  FILE *f;

  store=gtk_tree_view_get_model(liste);
  if (store==NULL)
  {
    
    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes(" Nom",renderer, "text",NOM,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes(" Prenom",renderer, "text",PRENOM,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes(" ID",renderer, "text",IDENTIFIANT,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
    
    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes(" Sexe",renderer, "text",SEXE,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes(" jour",renderer, "text",JOUR,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes(" mois",renderer, "text",MOIS,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes(" annee",renderer, "text" ,ANNEE,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);



   

    store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING   , G_TYPE_INT, G_TYPE_STRING, G_TYPE_INT);

    f=fopen("Ouvrier.txt","r");
    if(f==NULL)
    {
      return;
    }
    else
    {
      f=fopen("Ouvrier.txt","a+");
         while(fscanf(f,"%s %s %s %s %d %s %d \n",a1,a2,a3,a4,&a5,a6,&a7)!=EOF)
         {
           gtk_list_store_append (store, &iter);
           gtk_list_store_set (store,&iter,NOM,a1,PRENOM,a2,IDENTIFIANT,a3,SEXE,a4,JOUR,a5,MOIS,a6,ANNEE,a7, -1);

         }
      fclose(f);
    gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
    g_object_unref (store);
    }
  }
    
}


//Marquer presence
void Marquer_Presence ( char identifiant [],char jj[],char mm[],char aaaa[],char p [])
{

FILE *f ;
f=fopen("Presence.txt","a");
if (f!= NULL)


 fprintf (f,"%s %s %s %s %s \n",identifiant,jj,mm,aaaa,p );

 fclose(f);
}
//modifier

int modifier_Ouvrier(Ouvrier o,char nom[],char prenom[],char id [],char sexe [],int  jj, char mm[],int aaaa)
{
 int M=0;
  FILE *f,*g;
  f=fopen("Ouvrier.txt","r");
  g=fopen("tmp.txt","w");
  if(f==NULL || g==NULL)
  {
    return;
  }
  else
  {
    while(fscanf(f,"%s %s %s %s %d %s %d \n",o.nom,o.prenom,o.identifiant,o.sexe,&o.ddn.jour,o.ddn.mois,&o.ddn.annee )!=EOF)
    {
      if(strcmp(o.identifiant,id)==0)
      { M=1; 
       fprintf(g,"%s %s %s %s %d %s %d \n",nom,prenom,id,sexe,jj,mm,aaaa);
      }
      else
      {
       fprintf(g,"%s %s %s %s %d %s %d \n",o.nom,o.prenom,o.identifiant,o.sexe,o.ddn.jour,o.ddn.mois,o.ddn.annee);
     }
    }
   fclose(f);
   fclose(g);
  }
   remove("Ouvrier.txt");
   rename("tmp.txt","Ouvrier.txt");
 return M;}





//meilleurOuvrier
int Meilleur_Ouvrier(int annee,int * max)
{
      FILE *f ;
    int id,p,ja,ma,aa,om;
int T[20000]={0};
int V[20000]={0};
int P[10];
int i,n=0,s;
char ch[20];
f=fopen("absenteisme.txt","r");
if (f!= NULL)


   {while (fscanf(f,"%d %d %d %d %d \n",&id,&ja,&ma,&aa,&p)!=EOF)

 {if (aa==annee)
     
  T[n]=id;
   V[n]=p;
   n++;
    }
   
 
   fclose(f);}
    int j=1;
while (j<10)

{i=0;
 s=0;
    while (i<n)
   { if (T[i]==j && V[i]==1)
     s++;
     i++;
   }
    P[j-1]=s;
    j++;

}


(*max)=P[0];

for (i=1;i<9;i++)
{

if (P[i]>(*max))
    {
        (*max)=P[i];
         om=i;
    }
}
return om+1;}






/*int Meilleur_Ouvrier_id(int annee)
{
      FILE *f ;
    int id,p,ja,ma,aa,om,max;
int T[20000]={0};
int V[20000]={0};
int P[10];
int i,n=0,s;
char ch[20];
f=fopen("absenteisme.txt","r");
if (f!= NULL)


   {while (fscanf(f,"%d %d %d %d %d \n",&id,&ja,&ma,&aa,&p)!=EOF)

 {if (aa==annee)
     
  T[n]=id;
  V[n]=p;
   n++;
    }
   
 
   fclose(f);}
    int j=1;
while (j<10)

{i=0;
 s=0;
    while (i<n)
   { if (T[i]==j && V[i]==1)
     s++;
     i++;
   }
    P[j-1]=s;
    j++;

}

om=1;
max=P[0];

for (i=1;i<9;i++)
{

if (P[i]>max)
    {
         om=i+1;
    }
}
return om;}




int Meilleur_Ouvrier_max(int annee)
{
      FILE *f ;
    int id,p,ja,ma,aa,max;
int T[20000]={0};
int V[20000]={0};
int P[10];
int i,n=0,s;
char ch[20];
f=fopen("absenteisme.txt","r");
if (f!= NULL)


   {while (fscanf(f,"%d %d %d %d %d \n",&id,&ja,&ma,&aa,&p)!=EOF)

 {if (aa==annee)
     
   T[n]=id;
   V[n]=p;
   n++;
    }
   
 
   fclose(f);}
    int j=1;
while (j<10)

{i=0;
 s=0;
    while (i<n)
   { if (T[i]==j && V[i]==1)
     s++;
     i++;
   }
    P[j-1]=s;
    j++;

}


max=P[0];

for (i=1;i<9;i++)
{

if (P[i]>max)
    {
       max=P[i];
    }
}
return max;}

*/

