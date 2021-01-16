#include <stdio.h>
#include <string.h>
#include "plant.h"
#include <gtk/gtk.h>

enum
{
  ID,
  DATE,
  DUREE,
  PLANTE,
  TYPE,
  COLUMNS
};

void ajouter_plant(zoro z)
{
  FILE *f;
  f=fopen("plant.txt","a+");
  if(f!=NULL)
  {
    fprintf(f,"%s %d-%d-%d %s %s %s \n",z.id,z.jour,z.mois,z.annee,z.duree,z.plante,z.type);
    fclose(f);
  }
}

void modifier_plant(sanji s,char id[],char date[], char duree[], char plante[],char type[])
{
  
  FILE *f,*g;
  f=fopen("plant.txt","r");
  g=fopen("tmp.txt","w");
  if(f==NULL || g==NULL)
  {
    return;
  }
  else
  {
    while(fscanf(f,"%s %s %s %s %s \n",s.id,s.date,s.duree,s.plante,s.type)!=EOF)
    {
      if(strcmp(s.id,id)==0)
      { 
       fprintf(g,"%s %s %s %s %s \n",id,date,duree,plante,type);
      }
      else
      {
       fprintf(g,"%s %s %s %s %s \n",s.id,s.date,s.duree,s.plante,s.type);
      }
    }
   fclose(f);
   fclose(g);
   }
   remove("plant.txt");
   rename("tmp.txt","plant.txt");
}

void supprimer_plant(sanji s,char id[])
{
    FILE *f,*g;
    f=fopen("plant.txt","r");
    g=fopen("temp.txt","w");
    if(f!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s \n",s.id,s.date,s.duree,s.plante,s.type)!=EOF)
        {
            if(strcmp(s.id,id)!=0)
                fprintf(g,"%s %s %s %s %s \n",s.id,s.date,s.duree,s.plante,s.type);
        }
    }
    fclose(f);
    fclose(g);
    remove("plant.txt");
    rename("temp.txt","plant.txt");
}

int verif_plant(sanji s, char id[])
{
  int a=0;
  FILE *f;
  f=fopen("plant.txt","r+");
  if(f==NULL)
  { 
    return;
  }
  else
  { 
    while(fscanf(f,"%s %s %s %s %s \n",s.id,s.date,s.duree,s.plante,s.type)!=EOF)
    {
       if(strcmp(s.id,id)==0)
       {
          a=1;
       }
   }
   fclose(f);    
   }
  return a;
}

void afficher_plant(GtkWidget *liste)
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


  FILE *f;

  store=gtk_tree_view_get_model(liste);
  if (store==NULL)
  {
    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes(" id",renderer, "text",ID,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes(" date",renderer, "text",DATE,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes(" duree",renderer, "text",DUREE,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes(" plante",renderer, "text",PLANTE,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes(" type",renderer, "text",TYPE,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);



    store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

    f=fopen("plant.txt","r");
    if(f==NULL)
    {
      return;
    }
    else
    {
      f=fopen("plant.txt","a+");
         while(fscanf(f,"%s %s %s %s %s \n",a1,a2,a3,a4,a5)!=EOF)
         {
           gtk_list_store_append (store, &iter);
           gtk_list_store_set (store,&iter,ID,a1,DATE,a2,DUREE,a3,PLANTE,a4,TYPE,a5,-1);

         }
      fclose(f);
    gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
    g_object_unref (store);
    }
  }
    
}

void chercher_plant(sanji s,char id[],char date[],char duree[], char plante[], char type[] )
{

  FILE *f;
  f=fopen("plant.txt","r+");
  if(f==NULL)
  { 
    return;
  }
  else
  { 
    while(fscanf(f,"%s %s %s %s %s \n",s.id,s.date,s.duree,s.plante,s.type)!=EOF)
    {
       if(strcmp(s.id,id)==0)
       {
         strcpy(date,s.date);
         strcpy(duree,s.duree);
 	 strcpy(plante,s.plante);
         strcpy(type,s.type);
       }
   }
   fclose(f);    
   }
    
}
