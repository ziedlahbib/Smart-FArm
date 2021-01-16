#include <stdio.h>
#include <string.h>
#include "functions.h"
#include <gtk/gtk.h>

enum
{
  ID,
  NOM,
  TYPE,
  MARQUE,
  VALMAX,
  VALMIN,
  COLUMNS
};
enum
{
  IDENTIFIANT,
  COL
};

void ajouter_capt(capteur c)
{
  FILE *f;
  f=fopen("capteur.txt","a+");
  if(f!=NULL)
  {
    fprintf(f,"%s %s %s %s %s %s \n",c.identifiant,c.nom,c.type,c.marque,c.max,c.min);
    fclose(f);
  }
}


void afficher_capt(GtkWidget *liste)
{
  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;
  
  char a1[50];
  char a2[50];
  char a3[50];
  char a4[50];
  char a5[50];
  char a6[50];


  FILE *f;

  store=gtk_tree_view_get_model(liste);
  if (store==NULL)
  {
    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes(" id",renderer, "text",ID,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes(" nom",renderer, "text",NOM,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes(" type",renderer, "text",TYPE,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes(" marque",renderer, "text",MARQUE,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes(" valeur maximale",renderer, "text",VALMAX,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes(" valeur minimale",renderer, "text",VALMIN,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);



    store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

    f=fopen("capteur.txt","r");
    if(f==NULL)
    {
      return;
    }
    else
    {
      f=fopen("capteur.txt","a+");
         while(fscanf(f,"%s %s %s %s %s %s \n",a1,a2,a3,a4,a5,a6)!=EOF)
         {
           gtk_list_store_append (store, &iter);
           gtk_list_store_set (store,&iter,ID,a1,NOM,a2,TYPE,a3,MARQUE,a4,VALMAX,a5,VALMIN,a6,-1);

         }
      fclose(f);
    gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
    g_object_unref (store);
    }
  }
    
}

void modifier_capt(capteur c,char id[],char nom[],char type[], char marque[], char vmax[] , char vmin[])
{
  
  FILE *f,*g;
  f=fopen("capteur.txt","r");
  g=fopen("tmp.txt","w");
  if(f==NULL || g==NULL)
  {
    return;
  }
  else
  {
    while(fscanf(f,"%s %s %s %s %s %s \n",c.identifiant,c.nom,c.type,c.marque,c.max,c.min)!=EOF)
    {
      if(strcmp(c.identifiant,id)==0)
      { 
       fprintf(g,"%s %s %s %s %s %s \n",id,nom,type,marque,vmax,vmin);
      }
      else
      {
       fprintf(g,"%s %s %s %s %s %s \n",c.identifiant,c.nom,c.type,c.marque,c.max,c.min);
      }
    }
   fclose(f);
   fclose(g);
   }
   remove("capteur.txt");
   rename("tmp.txt","capteur.txt");
}



void supprimer_capt(capteur c,char id[])
{
    FILE *f,*g;
    f=fopen("capteur.txt","r");
    g=fopen("temp.txt","w");
    if(f!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s \n",c.identifiant,c.nom,c.type,c.marque,c.max,c.min)!=EOF)
        {
            if(strcmp(c.identifiant,id)!=0)
                fprintf(g,"%s %s %s %s %s %s \n",c.identifiant,c.nom,c.type,c.marque,c.max,c.min);
        }
    }
    fclose(f);
    fclose(g);
    remove("capteur.txt");
    rename("temp.txt","capteur.txt");
}

void chercher_capt(capteur c,char id[],char nom[],char type[], char marque[], char vmax[] , char vmin[] )
{

  FILE *f;
  f=fopen("capteur.txt","r+");
  if(f==NULL)
  { 
    return;
  }
  else
  { 
    while(fscanf(f,"%s %s %s %s %s %s \n",c.identifiant,c.nom,c.type,c.marque,c.max,c.min)!=EOF)
    {
       if(strcmp(c.identifiant,id)==0)
       {
         strcpy(nom,c.nom);
         strcpy(type,c.type);
 	 strcpy(marque,c.marque);
         strcpy(vmax,c.max);
         strcpy(vmin,c.min);  
       }
   }
   fclose(f);    
   }
    
}

int verif_capt(capteur c , char id[])
{
  int a=0;
  FILE *f;
  f=fopen("capteur.txt","r+");
  if(f==NULL)
  { 
    return;
  }
  else
  { 
    while(fscanf(f,"%s %s %s %s %s %s \n",c.identifiant,c.nom,c.type,c.marque,c.max,c.min)!=EOF)
    {
       if(strcmp(c.identifiant,id)==0)
       {
          a=1;
       }
   }
   fclose(f);    
   }
  return a;
}
void afficher_defect(GtkWidget *liste)
{
  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;
  
  char a1[50];
  FILE *f;

  store=gtk_tree_view_get_model(liste);
  if (store==NULL)
  {
    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes(" identifiant",renderer, "text",ID,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    store=gtk_list_store_new (COL, G_TYPE_STRING);

    f=fopen("defect.txt","r");
    if(f==NULL)
    {
      return;
    }
    else
    {
      f=fopen("defect.txt","a+");
         while(fscanf(f,"%s \n",a1)!=EOF)
         {
           gtk_list_store_append (store, &iter);
           gtk_list_store_set (store,&iter,IDENTIFIANT,a1,-1);

         }
      fclose(f);
    gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
    g_object_unref (store);
    }
  }
    
}
 





