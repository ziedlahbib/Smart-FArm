
#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Troupeaux.h"
#include<gtk/gtk.h>
GtkListStore *adstore;
GtkTreeViewColumn *adcolumn;
GtkCellRenderer *cellad;
FILE *troupeaux;
enum
{
	EType,
	EIdentifiant,
	ESexe,
	Ejj,
	Emm,
	Eaaaa,
	COLUMNS,
};

////////////////////////////////////////
void ajouter_troupeaux(Troupeaux t)
{
FILE *f;
f=fopen("troupeaux.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %s %s %d %d %s \n",t.Type,t.Identifiant,t.Sexe,t.ddn.jj,t.ddn.mm,t.ddn.aaaa);
fclose(f);
}
}
////////////////////////////
void afficher_troupeaux(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char Type[100];
	char Identifiant [100];
	char Sexe [100];
	int jj;
	int mm;
	char aaaa[100];	
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);
	if ( store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Type",renderer,"text",EType,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Identifiant",renderer,"text",EIdentifiant,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Sexe",renderer,"text",ESexe,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jours de naissance",renderer,"text",Ejj,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mois de naissance",renderer,"text",Emm,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("annee de naissance",renderer,"text",Eaaaa,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	
	}
	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING);
	
	f=fopen("troupeaux.txt","r");
	if(f==NULL)
	{
	
		return;
	}
	else
	f=fopen("troupeaux.txt","a+");
	while(fscanf(f,"%s %s %s %d %d %s \n",Type,Identifiant,Sexe,&jj,&mm,aaaa)!=EOF)
	{ 
	gtk_list_store_append (store,&iter);
	gtk_list_store_set (store, &iter, EType, Type, EIdentifiant, Identifiant, ESexe, Sexe, Ejj, jj, Emm, mm, Eaaaa, aaaa,-1);
	}
	fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
	g_object_unref (store);
	
}
////////////////////////////////////////
void supprimer_troupeaux(Troupeaux t)
{
Troupeaux t2;
FILE *f,*g;
f=fopen("troupeaux.txt","r");
g=fopen("troupeaux2.txt","w");
if (f==NULL || g==NULL)
return;
else
{
	while(fscanf(f,"%s %s %s %s %s %s",t2.Type,t2.Identifiant,t2.Sexe,&t2.ddn.jj,&t2.ddn.mm,t2.ddn.aaaa)!=EOF)
	{
		if (strcmp(t.Identifiant,t2.Identifiant)!=0 || strcmp(t.Type,t2.Type)!=0 || strcmp(t.Sexe,t2.Sexe)!=0 || 
			t.ddn.jj!=t2.ddn.jj || t.ddn.mm!=t2.ddn.mm || strcmp(t.ddn.aaaa,t2.ddn.aaaa)!=0)
		fprintf(g,"%s %s %s %d %d %s \n",t2.Type,t2.Identifiant,t2.Sexe,t2.ddn.jj,t2.ddn.mm,t2.ddn.aaaa);
	}
	fclose(f);
	fclose(g);
remove("troupeaux.txt");
rename("troupeaux2.txt","troupeaux.txt");
}
}

////////////////////
void charger(char *troupeaux,Troupeaux tab[],int *n)
{
        troupeaux=fopen(troupeaux,"r");
        if(troupeaux!=NULL)
            	{
                   while( fscanf(troupeaux,"%s %s %s %d %d %s \n",tab[*n].Type,tab[*n].Identifiant,tab[*n].Sexe,&tab[*n].ddn.jj,&tab[*n].ddn.mm,tab[*n].ddn.aaaa)!=EOF)
			     { *n=*n+1;
				}



        fclose(troupeaux);
            }
}
///////////////////////////////////
void enregistrer(char *troupeaux,Troupeaux tab[],int *n)
{
    int i;

        troupeaux=fopen(troupeaux,"w+");
        if(troupeaux!=NULL)
            {
                for(i=0;i<*n;i++)
                {
                    fprintf(troupeaux,"%s %s %s %d %d %s \n",tab[i].Type,tab[i].Identifiant,tab[i].Sexe,tab[i].ddn.jj,tab[i].ddn.mm,tab[i].ddn.aaaa);
                }
        fclose(troupeaux);
            }
}

////////////////////////////////////
Troupeaux chercher(Troupeaux tab[],int n,char IDC[])
{
    Troupeaux t;	
    int i;
    for (i=0;i<n;i++)
    {
        if (strcmp(tab[i].Identifiant,IDC)==0)
		{
		strcpy(t.Type,tab[i].Type);
		strcpy(t.Sexe,tab[i].Sexe);
		t.ddn.jj=tab[i].ddn.jj;
		t.ddn.mm=tab[i].ddn.mm;
		strcpy(t.ddn.aaaa,tab[i].ddn.aaaa);		
			
		}
	}	
return t;

    }
////////////////////////////
void supprimer(Troupeaux tab[],int *n,char IDS[])
{
    int i,j;

    for(i=0;i<*n;i++)
    {
       if(strcmp(IDS,tab[i].Identifiant)==0)
       {
           for(j=i;j<*n;j++)
           {
               tab[j]=tab[j+1];
           }
       }
      
    }

    *n=*n-1;

}
//////////////////////////////////////////////
void modifier_Troupeaux(Troupeaux tab[],int n,char IDM[],Troupeaux t)
{
    int i;

        
    for (i=0;i<n;i++)
    {
        if (strcmp(tab[i].Identifiant,IDM)==0)

            {
            
            strcpy(tab[i].Type,t.Type);
            strcpy(tab[i].Sexe,t.Sexe);
            tab[i].ddn.jj=t.ddn.jj;
            tab[i].ddn.mm=t.ddn.mm;
            strcpy(tab[i].ddn.aaaa,t.ddn.aaaa);
            }



    }





}
/////////////////////////////////////////
int rechercher_troupeaux_par_type(GtkWidget* liste,char*l,char*type,int *n){
GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	int s=0;
	char Type[100];
	char Identifiant [100];
	char Sexe [100];
	int jj;
	int mm;
	char aaaa[100];	
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);
	if ( store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Type",renderer,"text",EType,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Identifiant",renderer,"text",EIdentifiant,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Sexe",renderer,"text",ESexe,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jours de naissance",renderer,"text",Ejj,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mois de naissance",renderer,"text",Emm,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("annee de naissance",renderer,"text",Eaaaa,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	
	}
	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING);
	
	f=fopen("troupeaux.txt","r");
	if(f==NULL)
	{
	
		return;
	}
	else
	f=fopen("troupeaux.txt","a+");
	while(fscanf(f,"%s %s %s %d %d %s \n",Type,Identifiant,Sexe,&jj,&mm,aaaa)!=EOF)
	{ if (strcmp(Type,type)==0){
	gtk_list_store_append (store,&iter);
	gtk_list_store_set (store, &iter, EType, Type, EIdentifiant, Identifiant, ESexe, Sexe, Ejj, jj, Emm, mm, Eaaaa, aaaa,-1);
	s++;	
	}
	(*n)++;
	}
	fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
	g_object_unref (store);


 	








return s;



}












