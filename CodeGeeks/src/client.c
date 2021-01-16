#include <stdio.h>
#include <string.h>
#include "client.h"
#include <gtk/gtk.h>

enum
{
  CIN,
  NOM,
  PRENOM,
  SEXE,
  EMAIL,
  PHONE,
  COLUMNS
};

void ajouter_client(client c)
{
  FILE *f;
  f=fopen("client.txt","a+");
  if(f!=NULL)
  {
    fprintf(f,"%s %s %s %s %s %s \n",c.cin,c.nom,c.prenom,c.sexe,c.email,c.phone);
    fclose(f);
  }
}

void modifier_client(client c,char cin[],char nom[],char prenom[],char sexe[],char email[], char phone[])
{
  
  FILE *f,*g;
  f=fopen("client.txt","r");
  g=fopen("tmp.txt","w");
  if(f==NULL || g==NULL)
  {
    return;
  }
  else
  {
    while(fscanf(f,"%s %s %s %s %s %s \n",c.cin,c.nom,c.prenom,c.sexe,c.email,c.phone)!=EOF)
    {
      if(strcmp(c.cin,cin)==0)
      { 
       fprintf(g,"%s %s %s %s %s %s \n",cin,nom,prenom,sexe,email,phone);
      }
      else
      {
       fprintf(g,"%s %s %s %s %s %s \n",c.cin,c.nom,c.prenom,c.sexe,c.email,c.phone);
      }
    }
   fclose(f);
   fclose(g);
   }
   remove("client.txt");
   rename("tmp.txt","client.txt");
}

void supprimer_client(client c,char cin[])
{
    FILE *f,*g;
    f=fopen("client.txt","r");
    g=fopen("temp.txt","w");
    if(f!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s \n",c.cin,c.nom,c.prenom,c.sexe,c.email,c.phone)!=EOF)
        {
            if(strcmp(c.cin,cin)!=0)
                fprintf(g,"%s %s %s %s %s %s \n",c.cin,c.nom,c.prenom,c.sexe,c.email,c.phone);
        }
    }
    fclose(f);
    fclose(g);
    remove("client.txt");
    rename("temp.txt","client.txt");
}

int verif_client(client c, char cin[])
{
  int a=0;
  FILE *f;
  f=fopen("client.txt","r+");
  if(f==NULL)
  { 
    return;
  }
  else
  { 
    while(fscanf(f,"%s %s %s %s %s %s \n",c.cin,c.nom,c.prenom,c.sexe,c.email,c.phone)!=EOF)
    {
       if(strcmp(c.cin,cin)==0)
       {
          a=1;
       }
   }
   fclose(f);    
   }
  return a;
}

void afficher_client(GtkWidget *liste)
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
    column = gtk_tree_view_column_new_with_attributes(" cin",renderer, "text",CIN,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes(" nom",renderer, "text",NOM,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes(" prenom",renderer, "text",PRENOM,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes(" sexe",renderer, "text",SEXE,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes(" email",renderer, "text",EMAIL,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes(" phone",renderer, "text",PHONE,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);



    store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

    f=fopen("client.txt","r");
    if(f==NULL)
    {
      return;
    }
    else
    {
      f=fopen("client.txt","a+");
         while(fscanf(f,"%s %s %s %s %s %s \n",a1,a2,a3,a4,a5,a6)!=EOF)
         {
           gtk_list_store_append (store, &iter);
           gtk_list_store_set (store,&iter,CIN,a1,NOM,a2,PRENOM,a3,SEXE,a4,EMAIL,a5,PHONE,a6,-1);

         }
      fclose(f);
    gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
    g_object_unref (store);
    }
  }
    
}

void chercher_client(client c,char cin[],char nom[],char prenom[],char sexe[],char email[], char phone[])
{

  FILE *f;
  f=fopen("client.txt","r+");
  if(f==NULL)
  { 
    return;
  }
  else
  { 
    while(fscanf(f,"%s %s %s %s %s %s \n",c.cin,c.nom,c.prenom,c.sexe,c.email,c.phone)!=EOF)
    {
       if(strcmp(c.cin,cin)==0)
       {
         strcpy(nom,c.nom);
         strcpy(prenom,c.prenom);
 	 strcpy(sexe,c.sexe);
         strcpy(email,c.email);
	 strcpy(phone,c.phone);
       }
   }
   fclose(f);    
   }
    
}
