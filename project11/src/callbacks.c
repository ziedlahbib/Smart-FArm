#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include"Troupeaux.h"
int BR=1;
int V=0;

void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_CHECK_BUTTON (togglebutton)))
{V=1;}
}


void
on_radiobutton1Male_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{BR=1;}
}


void
on_radiobutton2Femelle_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{BR=2;}
}


void
on_ZLbuttonchercher_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
int Choix ;
GtkWidget *output1;
GtkWidget *input2;
GtkWidget *output5;
GtkWidget *output6;
GtkWidget *output7;
GtkWidget *male;
GtkWidget *femelle;
Troupeaux t;
Troupeaux tab[200];
int n=0;
int i;
int x=0;
FILE *troupeaux;
char IDC[100];
   output1=lookup_widget(objet_graphique,"ZLcombobox1Type");
   input2=lookup_widget(objet_graphique,"ZLentry1Identifiant");
   output5=lookup_widget(objet_graphique,"ZLspinbutton1JJ");
   output6=lookup_widget(objet_graphique,"ZLspinbutton2MM");
   output7=lookup_widget(objet_graphique,"ZLentry2Annee");
   male=lookup_widget(objet_graphique,"ZLradiobutton1Male");
   femelle=lookup_widget(objet_graphique,"ZLradiobutton2Femelle");
strcpy(IDC,gtk_entry_get_text(GTK_ENTRY(input2)));
charger("troupeaux.txt",tab,&n);
for(i=0;i<n;i++){
if(strcmp(tab[i].Identifiant,IDC)==0)
x=1;}
if (x==1){
t=chercher(tab,n,IDC);	
	if(strcmp(t.Sexe,"male")==0){
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(male),TRUE);}
	else if(strcmp(t.Sexe,"femelle")==0){
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(femelle),TRUE);}
	if(strcmp(t.Type,"veau")==0)
	{
	Choix=0;
	}
	else if(strcmp(t.Type,"agneau")==0)
	{
	Choix=1;
	}
	else if(strcmp(t.Type,"poulain")==0)
	{
	Choix=2;
	}
	else if(strcmp(t.Type,"poussins")==0)
	{
	Choix=3;
	}
	else if(strcmp(t.Type,"chevreau")==0)
	{
	Choix=4;
	}
	gtk_combo_box_set_active(GTK_COMBO_BOX(output1),Choix);
	
   	gtk_spin_button_set_value(GTK_SPIN_BUTTON(output5),t.ddn.jj);
   	gtk_spin_button_set_value(GTK_SPIN_BUTTON(output6),t.ddn.mm);
	gtk_entry_set_text(GTK_ENTRY(output7),t.ddn.aaaa);}else{GtkWidget *dialog5;
	dialog5=create_dialog5() ;
	gtk_widget_show(dialog5) ;}
	
	
		
	
	
	
}


void
on_ZLbutton1Aj_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
Troupeaux t;
   	GtkWidget *input1;
	GtkWidget *input2;
	GtkWidget *pRadio1;
	GtkWidget *pRadio2;
	GtkWidget *input5;
	GtkWidget *input6;
	GtkWidget *input7;
	GtkWidget *windowAffichage;
	
	


   input1=lookup_widget(objet_graphique,"ZLcombobox1Type");
   input2=lookup_widget(objet_graphique,"ZLentry1Identifiant");
   input5=lookup_widget(objet_graphique,"ZLspinbutton1JJ");
   input6=lookup_widget(objet_graphique,"ZLspinbutton2MM");
   input7=lookup_widget(objet_graphique,"ZLentry2Annee");

   strcpy(t.Type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
   strcpy(t.Identifiant,gtk_entry_get_text(GTK_ENTRY(input2)));
   t.ddn.jj=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
   t.ddn.mm=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
   strcpy(t.ddn.aaaa,gtk_entry_get_text(GTK_ENTRY(input7)));
   if(BR==1)
	strcpy(t.Sexe,"male");
   else if (BR==2)
	strcpy(t.Sexe,"femelle");
	if(V==1){
   ajouter_troupeaux(t);
	GtkWidget *dialog2;
	dialog2=create_dialog2() ;
	gtk_widget_show(dialog2) ;}
	else 
	{
	GtkWidget *dialog1;
	dialog1=create_dialog1() ;
	gtk_widget_show(dialog1) ;
	}

}


void
on_ZLbutton2Mo_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
Troupeaux t;
   	GtkWidget *input1;
	GtkWidget *input2;
	GtkWidget *input5;
	GtkWidget *input6;
	GtkWidget *input7;
	GtkWidget *windowAffichage;
	Troupeaux tab[200];
	int n=0;
	FILE *troupeaux;
	char IDM[100];
   input1=lookup_widget(objet_graphique,"ZLcombobox1Type");
   input2=lookup_widget(objet_graphique,"ZLentry1Identifiant");
   input5=lookup_widget(objet_graphique,"ZLspinbutton1JJ");
   input6=lookup_widget(objet_graphique,"ZLspinbutton2MM");
   input7=lookup_widget(objet_graphique,"ZLentry2Annee");
   strcpy(IDM,gtk_entry_get_text(GTK_ENTRY(input2)));
   strcpy(t.Identifiant,IDM);
   strcpy(t.Type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
   t.ddn.jj=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
   t.ddn.mm=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
   strcpy(t.ddn.aaaa,gtk_entry_get_text(GTK_ENTRY(input7)));
   if(BR==1)
	strcpy(t.Sexe,"male");
   else if (BR==2)
	strcpy(t.Sexe,"femelle");
	if(V==1)
	{
	charger("troupeaux.txt",tab,&n);
	modifier_Troupeaux(tab,n,IDM,t);
	enregistrer("troupeaux.txt",tab,&n);
	}
	else 
	{
	GtkWidget *dialog1;
	dialog1=create_dialog1() ;
	gtk_widget_show(dialog1) ;
	}
	GtkWidget *dialog3;
	dialog3=create_dialog3() ;
	gtk_widget_show(dialog3) ;
}


void
on_ZLbutton3Su_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input1;
	GtkWidget *input2;
	GtkWidget *input5;
	GtkWidget *input6;
	GtkWidget *input7;

Troupeaux tab[200];
int n=0;
FILE *troupeaux;
char IDS[100];
   input1=lookup_widget(objet_graphique,"ZLcombobox1Type");
   input2=lookup_widget(objet_graphique,"ZLentry1Identifiant");
   input5=lookup_widget(objet_graphique,"ZLspinbutton1JJ");
   input6=lookup_widget(objet_graphique,"ZLspinbutton2MM");
   input7=lookup_widget(objet_graphique,"ZLentry2Annee");
strcpy(IDS,gtk_entry_get_text(GTK_ENTRY(input2)));
charger("troupeaux.txt",tab,&n);
supprimer(tab,&n,IDS);
enregistrer("troupeaux.txt",tab,&n);
GtkWidget *dialog4;
	dialog4=create_dialog4() ;
	gtk_widget_show(dialog4) ;
}


void
on_ZLbutton4Aff_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowAMSTroupeaux;
GtkWidget *windowAffichage;
GtkWidget *treeview1;

windowAMSTroupeaux=lookup_widget(objet,"windowAMSTroupeaux");

gtk_widget_destroy(windowAMSTroupeaux);
windowAffichage=lookup_widget(objet,"windowAffichage");
windowAffichage=create_windowAffichage();
gtk_widget_show(windowAffichage);
treeview1=lookup_widget(windowAffichage,"treeview1");
afficher_troupeaux(treeview1);
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* Identifiant;
	gchar* Type;
	gchar* Sexe;
	gint* jj;
	gint* mm;
	gchar* aaaa;
	Troupeaux tab[200];
	int n=0;
	FILE *troupeaux;
	char IDS[100];
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model,&iter,path))
	{
		gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&Type,1,&Identifiant,2,&Sexe,3,&jj,4,&mm,5,&aaaa,-1);

		strcpy(IDS,Identifiant);
		charger("troupeaux.txt",tab,&n);
		supprimer(tab,&n,IDS);
		enregistrer("troupeaux.txt",tab,&n);
		afficher_troupeaux(treeview);
	}
}


void
on_ZLbutton5Re_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowAMSTroupeaux;
GtkWidget *windowAffichage;
windowAffichage=lookup_widget(objet,"windowAffichage");

gtk_widget_destroy(windowAffichage);
windowAMSTroupeaux=create_windowAMSTroupeaux();
gtk_widget_show(windowAMSTroupeaux);
}


void
on_ZLbutton1AJ_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowAMSTroupeaux;
windowAMSTroupeaux=create_windowAMSTroupeaux();
gtk_widget_show(windowAMSTroupeaux);
}


void
on_ZLbutton2SU_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowAMSTroupeaux;
windowAMSTroupeaux=create_windowAMSTroupeaux();
gtk_widget_show(windowAMSTroupeaux);
}


void
on_ZLbutton3Mo_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowAMSTroupeaux;
windowAMSTroupeaux=create_windowAMSTroupeaux();
gtk_widget_show(windowAMSTroupeaux);
}


void
on_ZLbutton4Chercher_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowAffnbrtroupeaux;
GtkWidget *windowAffichage;
windowAffichage=lookup_widget(objet,"windowAffichage");

gtk_widget_destroy(windowAffichage);
windowAffnbrtroupeaux=create_windowAffnbrtroupeaux();
gtk_widget_show(windowAffnbrtroupeaux);

}


void
on_ZLbutton1close_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dialog1=lookup_widget(GTK_WIDGET(button),("dialog1"));

gtk_widget_destroy(dialog1);
}


void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_ZLbutton5chercherType_clicked       (GtkWidget     *objet_graphique,
                                        gpointer         user_data)
{
char type[30];
char labelType[30];
int nb;
int n=0;
GtkWidget *windowAffnbrtroupeaux;
GtkWidget *treeview2;
GtkWidget *input1;
input1=lookup_widget(objet_graphique,"ZLentry1Type");
windowAffnbrtroupeaux=lookup_widget(objet_graphique,"windowAffnbrtroupeaux");
treeview2=lookup_widget(windowAffnbrtroupeaux,"treeview2");

strcpy(type,gtk_entry_get_text(GTK_ENTRY(input1)));





nb=rechercher_troupeaux_par_type(treeview2,"troupeaux.txt",type,&n);
sprintf(labelType,"%d",nb);
gtk_label_set_text(GTK_LABEL( lookup_widget(windowAffnbrtroupeaux,"label19") ),labelType);
sprintf(labelType,"%d",n);
gtk_label_set_text(GTK_LABEL( lookup_widget(windowAffnbrtroupeaux,"label20") ),labelType);

}


void
on_ZLbutton6retour_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowAffnbrtroupeaux;
GtkWidget *windowAffichage;
GtkWidget *treeview1;
windowAffnbrtroupeaux=lookup_widget(objet,"windowAffnbrtroupeaux");

gtk_widget_destroy(windowAffnbrtroupeaux);
windowAffichage=create_windowAffichage();
gtk_widget_show(windowAffichage);
treeview1=lookup_widget(windowAffichage,"treeview1");
afficher_troupeaux(treeview1);
}


void
on_ZLclosebutton1_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dialog2=lookup_widget(GTK_WIDGET(button),("dialog2"));

gtk_widget_destroy(dialog2);
}


void
on_ZLclosebutton2_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dialog3=lookup_widget(GTK_WIDGET(button),("dialog3"));

gtk_widget_destroy(dialog3);
}


void
on_ZLclosebutton3_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dialog4=lookup_widget(GTK_WIDGET(button),("dialog4"));

gtk_widget_destroy(dialog4);
}


void
on_ZLclosebutton4_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dialog5=lookup_widget(GTK_WIDGET(button),("dialog5"));

gtk_widget_destroy(dialog5);
}

