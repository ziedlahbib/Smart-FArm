
#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"
#include "functions.h"
#include"Troupeaux.h"
#include "plant.h"
#include "client.h"
int BR=1;
int V=0;
int RB;
int Niveau[2]={0,0};
int P=0;
int A;
int B;
//---------------------------------------------------------------------


void
on_HMBouttonEnregistrerOuvrier_clicked (GtkButton       *Mo,
                                        gpointer         user_data)

{GtkWidget *windowDashB;
 GtkWidget *HMWindowMeilleurOuvrier;

 windowDashB=lookup_widget(Mo,"windowDashB");

gtk_widget_destroy(windowDashB);
HMWindowMeilleurOuvrier=lookup_widget(Mo,"HMWindowMeilleurOuvrier");
HMWindowMeilleurOuvrier=create_HMWindowMeilleurOuvrier();
gtk_widget_show(HMWindowMeilleurOuvrier);
}



//----------------------------------------------------------------------


void
on_HMBouttonRetour1_clicked            (GtkButton       *r1,
                                        gpointer         user_data)
{
GtkWidget *HMWindowPresence;
 GtkWidget *HMWindowGestionOuvrier;

 HMWindowPresence=lookup_widget(r1,"HMWindowPresence");

gtk_widget_destroy(HMWindowPresence);
HMWindowGestionOuvrier=lookup_widget(r1,"HMWindowGestionOuvrier");
HMWindowGestionOuvrier=create_HMWindowGestionOuvrier();
gtk_widget_show(HMWindowGestionOuvrier);
GtkWidget *HMTreeViewOuvrier;
 HMTreeViewOuvrier=lookup_widget(HMWindowGestionOuvrier,"HMTreeViewOuvrier");
afficher(HMTreeViewOuvrier);
}

//----------------------------------------------------------------------


void
on_HMBouttonPresenceOuvrier_clicked    (GtkButton       *pr,
                                        gpointer         user_data)
{GtkWidget *HMWindowGestionOuvrier;
 GtkWidget *HMWindowPresence;

 HMWindowGestionOuvrier=lookup_widget(pr,"HMWindowGestionOuvrier");

 gtk_widget_destroy(HMWindowGestionOuvrier);
HMWindowPresence=lookup_widget(pr,"HMWindowPresence");
HMWindowPresence=create_HMWindowPresence();
gtk_widget_show(HMWindowPresence);
}

//----------------------------------------------------------------------

void
on_HMBouttonChercherOuvrier_clicked    (GtkButton       *ch,
                                        gpointer         user_data)
{
 GtkWidget *HMWindowGestionOuvrier;
 GtkWidget *HMWindowMessagederreur;

 HMWindowGestionOuvrier=lookup_widget(ch,"HMWindowGestionOuvrier");

 gtk_widget_destroy(HMWindowGestionOuvrier);
HMWindowMessagederreur=lookup_widget(ch,"HMWindowMessagederreur");
HMWindowMessagederreur=create_HMWindowMessagederreur();
gtk_widget_show(HMWindowMessagederreur);

}


//----------------------------------------------------------------------

void
on_HMBouttonModifierOuvrier_clicked    (GtkButton       *md,
                                        gpointer         user_data)
{int M;
Ouvrier o;
   GtkWidget *input1, *input2, *input3,  *input6, *input7, *input8 ;
   GtkWidget *HMWindowAjouModif;
   


	HMWindowAjouModif=lookup_widget(md,"HMWindowAjouModif");


   input1=lookup_widget(md,"HMentryNomOuvrier");
   input2=lookup_widget(md,"HMentryPrenomOuvrier");
   input3=lookup_widget(md,"HMentryIdentifiantOuvrier");
   input6=lookup_widget(md,"HMspinbuttonJour");
   input7=lookup_widget(md,"HMcomboboxentryMois");
   input8=lookup_widget(md,"HMspinbuttonAnnee");

 
strcpy(o.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
   strcpy(o.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
   strcpy(o.identifiant,gtk_entry_get_text(GTK_ENTRY(input3)));
   o.ddn.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
   strcpy(o.ddn.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input7)));
   o.ddn.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8));

if(RB==1)
strcpy(o.sexe,"Femme");
else if (RB==2)
strcpy(o.sexe,"Homme");

    M=modifier_Ouvrier( o, o.nom ,o.prenom,o.identifiant,o.sexe,o.ddn.jour,o.ddn.mois,o.ddn.annee);
  



if(M==0) 

{
GtkWidget *HMwindowEnregistrer;



HMwindowEnregistrer=create_HMwindowEnregistrer();
gtk_widget_show(HMwindowEnregistrer);
  

}
else 
{GtkWidget *Succes;
  Succes=create_Succes();
   gtk_widget_show(Succes);}
}
//---------------------------------------------------------------

void
on_HMBouttonSupprimerOuvrier_clicked   (GtkButton       *s,
                                        gpointer         user_data)
{  Ouvrier o;
   char ch1[50];
	int S;

   GtkWidget *input1;

   input1=lookup_widget(s,"HMentryIdentifiantOuvrier");
 
   
   strcpy(ch1,gtk_entry_get_text(GTK_ENTRY(input1)));
 
  S=supprimer_Ouvrier(o,ch1);
 if (S==0)

{
GtkWidget *HMwindowEnregistrer;



HMwindowEnregistrer=create_HMwindowEnregistrer();
gtk_widget_show(HMwindowEnregistrer);
  }
else
{GtkWidget *Succes;
  Succes=create_Succes();
   gtk_widget_show(Succes);}
}


//--------------------------------------------------------------





//-----------------------------------------------------------
void
on_HMBouttonAjouterOuvrier_clicked     (GtkButton       *aj,
                                        gpointer         user_data)
{GtkWidget *HMWindowGestionOuvrier;
 GtkWidget *HMWindowAjouModif;

 HMWindowGestionOuvrier=lookup_widget(aj,"HMWindowGestionOuvrier");

gtk_widget_destroy(HMWindowGestionOuvrier);
HMWindowAjouModif=lookup_widget(aj,"HMWindowAjouModif");
HMWindowAjouModif=create_HMWindowAjouModif();
gtk_widget_show(HMWindowAjouModif);
}
//--------------------------------------------------------

void
on_HMbouttonExit2_clicked              (GtkButton       *e2,
                                        gpointer         user_data)
{
 GtkWidget *HMWindowAjouModif;

 HMWindowAjouModif=lookup_widget(e2,"HMWindowAjouModif;");

gtk_widget_destroy(HMWindowAjouModif);


}


//-----------------------------------------------------------


void
on_HMBouttonRetour2_clicked            (GtkButton       *r2,
                                        gpointer         user_data)
{
GtkWidget *HMWindowAjouModif;
 GtkWidget *HMWindowGestionOuvrier;

 HMWindowAjouModif=lookup_widget(r2,"HMWindowAjouModif");

gtk_widget_destroy(HMWindowAjouModif);
HMWindowGestionOuvrier=lookup_widget(r2,"HMWindowGestionOuvrier");
HMWindowGestionOuvrier=create_HMWindowGestionOuvrier();
gtk_widget_show(HMWindowGestionOuvrier);
GtkWidget *HMTreeViewOuvrier;
 HMTreeViewOuvrier=lookup_widget(HMWindowGestionOuvrier,"HMTreeViewOuvrier");
afficher(HMTreeViewOuvrier);
}


//-----------------------------------------------------------


void
on_HMBouttonEnregistrer2_clicked       (GtkButton       *en2,
                                        gpointer         user_data)
{
Ouvrier o;
   GtkWidget *input1, *input2, *input3,  *input6, *input7, *input8 ;
   GtkWidget *HMWindowAjouModif;
	GtkWidget *Succes;


	HMWindowAjouModif=lookup_widget(en2,"HMWindowAjouModif");
        

   input1=lookup_widget(en2,"HMentryNomOuvrier");
   input2=lookup_widget(en2,"HMentryPrenomOuvrier");
   input3=lookup_widget(en2,"HMentryIdentifiantOuvrier");
   input6=lookup_widget(en2,"HMspinbuttonJour");
   input7=lookup_widget(en2,"HMcomboboxentryMois");
   input8=lookup_widget(en2,"HMspinbuttonAnnee");

   strcpy(o.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
   strcpy(o.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
   strcpy(o.identifiant,gtk_entry_get_text(GTK_ENTRY(input3)));
   o.ddn.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
   strcpy(o.ddn.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input7)));
   o.ddn.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8));

if(RB==1)
strcpy(o.sexe,"Femme");
else if (RB==2)
strcpy(o.sexe,"Homme");

   ajouter_Ouvrier(o);

  Succes=create_Succes();
   gtk_widget_show(Succes);
}


//-----------------------------------------------------------


void
on_HMBouttonOuiEnregistrer_clicked     (GtkButton       *en1,
                                        gpointer         user_data)
{

}


//-----------------------------------------------------------


void
on_HMBouttonNonEnregistrer_clicked     (GtkButton       *nn,
                                        gpointer         user_data)
{
}


//-----------------------------------------------------------


void
on_HMbuttonAfficherTV_clicked          (GtkButton       *aff,
                                        gpointer         user_data)
{

 GtkWidget *HMWindowAjouModif;
 GtkWidget *HMWindowGestionOuvrier; 
 GtkWidget *HMTreeViewOuvrier;
 
  HMWindowAjouModif=lookup_widget(aff,"HMWindowAjouModif");
  gtk_widget_destroy(HMWindowAjouModif);
  HMWindowGestionOuvrier=lookup_widget(aff,"HMWindowGestionOuvrier");
  HMWindowGestionOuvrier=create_HMWindowGestionOuvrier();
  gtk_widget_show(HMWindowGestionOuvrier);
  HMTreeViewOuvrier=lookup_widget(HMWindowGestionOuvrier,"HMTreeViewOuvrier");
  afficher(HMTreeViewOuvrier);

} 

//-----------------------------------------------------------

void
on_HMTreeViewOuvrier_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar* id;	
	gchar* nom;
	gchar *prenom;
	gchar *sexe;
	gint *jour;
	gchar *mois;
	gint *annee;
	Ouvrier O;

  GtkTreeModel *model=gtk_tree_view_get_model(treeview);
 
if(gtk_tree_model_get_iter(model, &iter, path))
{
gtk_tree_model_get(GTK_LIST_STORE(model), &iter, 0,&nom, 1,&prenom, 2,&id, 3,&sexe, 4,&jour, 5,&mois, 6, &annee, -1);
strcpy(O.nom,nom);
strcpy(O.prenom,prenom);
strcpy(O.identifiant,id);
strcpy(O.sexe,sexe);
O.ddn.jour=jour;
strcpy(O.ddn.mois,mois);
O.ddn.annee=annee;
//supprimer_Ouvrier(O);
afficher(treeview);
}

}


//-----------------------------------------------------------


void
on_HMradiobuttonFemme_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)

{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{RB=1;}
}

void
on_HMradiobuttonHomme_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{RB=2;}
}

void
on_HMcheckbuttonPresent_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

if ( gtk_toggle_button_get_active(GTK_CHECK_BUTTON (togglebutton)))
{P=1;}
else 
{P=0;}
}


//-----------------------------------------------------------

void
on_HMBouttonFind_clicked               (GtkButton       *f,
                                        gpointer         user_data)
{
  Ouvrier o;
   char ch1[50];
   char ch2[20];
   char ch3[20];
   char ch4[20];
   char ch5[20];
   int aa,jj;
   int F;
   GtkWidget *input1, *output2, *output3, *output4, *output5, *output6,*output7;





   input1=lookup_widget(f,"HMentryFindID");
   output2=lookup_widget(f,"HMentryFindNom");
   output3=lookup_widget(f,"HMentryFindPrenom");
   output4=lookup_widget(f,"HMentryFindSexe");
   output5=lookup_widget(f,"HMentryFindMois");
   output6=lookup_widget(f,"HMSPFindJJ");
   output7=lookup_widget(f,"HMSPFindAA");

   
   strcpy(ch1,gtk_entry_get_text(GTK_ENTRY(input1)));
   F=chercher(o,ch1,ch2,ch3,ch4,ch5,&jj,&aa);
 if (F==1)
   {gtk_entry_set_text(output2,ch2);
   gtk_entry_set_text(output3,ch3);  
   gtk_entry_set_text(output4,ch4);
   gtk_entry_set_text(output5,ch5);  
   gtk_spin_button_set_value(GTK_SPIN_BUTTON(output6),jj);
   gtk_spin_button_set_value(GTK_SPIN_BUTTON(output7),aa); 


   }
else
{
GtkWidget *HMwindowEnregistrer;



HMwindowEnregistrer=create_HMwindowEnregistrer();
gtk_widget_show(HMwindowEnregistrer);
  }
}
////////////////////////




//-----------------------------------------------------------


void
on_HMbuttonEnregistrerPresence_clicked (GtkButton       *ep,
                                        gpointer         user_data)
{  char jj[10];
  char mm [10];
  char aaaa[10];
  char id[10];
  char p[5];
 
   GtkWidget *input1, *input2, *input3, *input4, *input5 ;
   //GtkWidget *HMWindowAjouModif;
   //GtkWidget *HMWindowPresence;
	//HMWindowPresence=lookup_widget(ep,"HMWindowPresence");

   input1=lookup_widget(ep,"HMentryJourPresence");
   input2=lookup_widget(ep,"HMentryMoisPresence");
   input3=lookup_widget(ep,"HMentryAnneePresence");
   input4=lookup_widget(ep,"HMentryIdentifiantPresence");
   input5=lookup_widget(ep,"HMcheckbuttonPresent");

   strcpy(jj,gtk_entry_get_text(GTK_ENTRY(input1)));
   strcpy(mm,gtk_entry_get_text(GTK_ENTRY(input2)));
   strcpy(aaaa,gtk_entry_get_text(GTK_ENTRY(input3)));
   strcpy(id,gtk_entry_get_text(GTK_ENTRY(input4)));
   if (P==1)
   strcpy(p,"1");
   else
   strcpy(p,"0"); 

 Marquer_Presence(id,jj,mm,aaaa,p);
GtkWidget *Succes;
  Succes=create_Succes();
   gtk_widget_show(Succes);

}

//-----------------------------------------------------------



void
on_HMAfficherMO_clicked                (GtkButton       *BW,
                                      gpointer         user_data)
{
  

int annee,om;
int max;

GtkWidget *input1, *output2, *output3;

input1=lookup_widget(BW,"HMspinbuttonAnneeMO");
output2=lookup_widget(BW,"HMSpinButtonMOID");
output3=lookup_widget(BW,"HMspinbuttonMOnbrj");

annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input1));

om=Meilleur_Ouvrier(annee,&max);
 

  gtk_spin_button_set_value(GTK_SPIN_BUTTON(output2),om);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(output3),max); 
///////////


 
}


//-----------------------------------------------------------

void
on_HMButtonReturnFromFind_clicked      (GtkButton       *RF,
                                        gpointer         user_data)

{
GtkWidget *HMWindowMessagederreur;
 GtkWidget *HMWindowGestionOuvrier;

 HMWindowMessagederreur=lookup_widget(RF,"HMWindowMessagederreur");

gtk_widget_destroy(HMWindowMessagederreur);
HMWindowGestionOuvrier=lookup_widget(RF,"HMWindowGestionOuvrier");
HMWindowGestionOuvrier=create_HMWindowGestionOuvrier();
gtk_widget_show(HMWindowGestionOuvrier);
GtkWidget *HMTreeViewOuvrier;
 HMTreeViewOuvrier=lookup_widget(HMWindowGestionOuvrier,"HMTreeViewOuvrier");
afficher(HMTreeViewOuvrier);
}



//-----------------------------------------------------------


void
on_HMButtonReturnFromMO_clicked        (GtkButton       *RMO,
                                        gpointer         user_data)

{
GtkWidget *HMWindowMeilleurOuvrier;
GtkWidget *windowDashB;

 HMWindowMeilleurOuvrier=lookup_widget(RMO,"HMWindowMeilleurOuvrier");

gtk_widget_destroy(HMWindowMeilleurOuvrier);
windowDashB=lookup_widget(RMO,"windowDashB");
windowDashB=create_windowDashB();
gtk_widget_show(windowDashB);

}



void
on_AcceuilBouttonDashboard_clicked     (GtkButton       *ov,
                                        gpointer         user_data)
{GtkWidget *windowDashB;
 GtkWidget *Acceuil;
 

 Acceuil=lookup_widget(ov,"Acceuil");
 gtk_widget_destroy(Acceuil);

 windowDashB=lookup_widget(ov,"Acceuil");


windowDashB=lookup_widget(ov,"windowDashB");
windowDashB=create_windowDashB();
gtk_widget_show(windowDashB);

}


void
on_AcceuilBouttonTroupeaux_clicked     (GtkWidget       *objet,
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
treeview1=lookup_widget(windowAffichage,"ZLtreeview1");
afficher_troupeaux(treeview1);
}


void
on_AcceuilBouttonEquipement_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_AcceuilBouttonCapteurs_clicked      (GtkButton       *ob,
                                        gpointer         user_data)
{
   GtkWidget *Capteurs, *Acceuil;
   GtkWidget *mdztreeviewcapteur;

   Acceuil=lookup_widget(ob,"Acceuil");
   gtk_widget_destroy(Acceuil);
   Capteurs=create_Capteurs();
   gtk_widget_show(Capteurs);
   mdztreeviewcapteur=lookup_widget(Capteurs,"mdztreeviewcapteur");
   afficher_capt(mdztreeviewcapteur);
}


void
on_AcceuilBouttonOuvrier_clicked       (GtkButton       *ov,
                                        gpointer         user_data)
{GtkWidget *HMWindowGestionOuvrier;
 GtkWidget *Acceuil;
 GtkWidget *HMTreeViewOuvrier;

 HMWindowGestionOuvrier=lookup_widget(ov,"Acceuil");

gtk_widget_destroy(Acceuil);
HMWindowGestionOuvrier=lookup_widget(ov,"HMWindowGestionOuvrier");
HMWindowGestionOuvrier=create_HMWindowGestionOuvrier();
gtk_widget_show(HMWindowGestionOuvrier);
 HMTreeViewOuvrier=lookup_widget(HMWindowGestionOuvrier,"HMTreeViewOuvrier");
afficher(HMTreeViewOuvrier);
}



//===========================================================================================

void
on_mdzbuttonajouter_clicked            (GtkButton       *objet,
                                        gpointer         user_data)
{
   GtkWidget *Capteurs, *Ajout;

   Capteurs=lookup_widget(objet,"Capteurs");
   gtk_widget_destroy(Capteurs);
   Ajout=create_Ajout();
   gtk_widget_show(Ajout);
}


void
on_mdzbuttonmodifier_clicked           (GtkButton       *objet,
                                        gpointer         user_data)
{
   GtkWidget *Capteurs, *Modification;

   Capteurs=lookup_widget(objet,"Capteurs");
   gtk_widget_destroy(Capteurs);
   Modification=create_Modification();
   gtk_widget_show(Modification);
}


void
on_mdzbuttontester_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{
   GtkWidget *Capteurs, *Tester;

   Capteurs=lookup_widget(objet,"Capteurs");
   gtk_widget_destroy(Capteurs);
   Tester=create_Tester();
   gtk_widget_show(Tester);
}


void
on_mdzbuttonsupprimer_clicked          (GtkButton       *objet,
                                        gpointer         user_data)
{
   GtkWidget *Capteurs, *Suppression;

   Capteurs=lookup_widget(objet,"Capteurs");
   gtk_widget_destroy(Capteurs);
   Suppression=create_Suppression();
   gtk_widget_show(Suppression);
}


void
on_mdzbuttonretourajout_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{
   GtkWidget *Capteurs,*Ajout;
   GtkWidget *mdztreeviewcapteur;

   Ajout=lookup_widget(objet,"Ajout");
   gtk_widget_destroy(Ajout);
   Capteurs=create_Capteurs();
   gtk_widget_show(Capteurs);
   mdztreeviewcapteur=lookup_widget(Capteurs,"mdztreeviewcapteur");
   afficher_capt(mdztreeviewcapteur);
}


void
on_mdzbuttonretourmodif_clicked        (GtkButton       *objet,
                                        gpointer         user_data)
{
   GtkWidget *Capteurs,*Modification;
   GtkWidget *mdztreeviewcapteur;

   Modification=lookup_widget(objet,"Modification");
   gtk_widget_destroy(Modification);
   Capteurs=create_Capteurs();
   gtk_widget_show(Capteurs);
   mdztreeviewcapteur=lookup_widget(Capteurs,"mdztreeviewcapteur");
   afficher_capt(mdztreeviewcapteur);
}


void
on_mdzbuttonretourtest_clicked         (GtkButton       *objet,
                                        gpointer         user_data)
{
   GtkWidget *Capteurs,*Tester;
   GtkWidget *mdztreeviewcapteur;

   Tester=lookup_widget(objet,"Tester");
   gtk_widget_destroy(Tester);
   Capteurs=create_Capteurs();
   gtk_widget_show(Capteurs);
   mdztreeviewcapteur=lookup_widget(Capteurs,"mdztreeviewcapteur");
   afficher_capt(mdztreeviewcapteur);
}


void
on_mdzbuttonretoursupp_clicked         (GtkButton       *objet,
                                        gpointer         user_data)
{
   GtkWidget *Capteurs,*Suppression;
   GtkWidget *mdztreeviewcapteur;

   Suppression=lookup_widget(objet,"Suppression");
   gtk_widget_destroy(Suppression);
   Capteurs=create_Capteurs();
   gtk_widget_show(Capteurs);
   mdztreeviewcapteur=lookup_widget(Capteurs,"mdztreeviewcapteur");
   afficher_capt(mdztreeviewcapteur);
}


void
on_mdzbuttonajout_clicked              (GtkButton       *ob,
                                        gpointer         user_data)
{
   capteur c;
   GtkWidget *input1, *input2, *input3, *input4, *input5, *input6;
   GtkWidget *Ajout,*Succes;

   Ajout=lookup_widget(ob,"Ajout");

   input1=lookup_widget(ob,"mdzentryidcapt");
   input2=lookup_widget(ob,"mdzentrynomcapt");
   input3=lookup_widget(ob,"comboboxentrytype");
   input4=lookup_widget(ob,"comboboxentrymarque");
   input5=lookup_widget(ob,"mdzentryvalmax");
   input6=lookup_widget(ob,"mdzentryvalmin");

   strcpy(c.identifiant,gtk_entry_get_text(GTK_ENTRY(input1)));
   strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
   strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)));
   strcpy(c.marque,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input4)));
   strcpy(c.max,gtk_entry_get_text(GTK_ENTRY(input5)));
   strcpy(c.min,gtk_entry_get_text(GTK_ENTRY(input6)));

   ajouter_capt(c);
   Succes=create_Succes();
   gtk_widget_show(Succes);
   gtk_entry_set_text(input1,"");
   gtk_entry_set_text(input2,"");
   gtk_entry_set_text(input5,"");
   gtk_entry_set_text(input6,"");
   
}


void
on_mdzbuttonrechercher_clicked         (GtkButton       *ob,
                                        gpointer         user_data)
{
   capteur c;
   int t;
   int k=-1;
   int m=-1;
   char ch1[50];
   char ch2[50];
   char ch3[50];
   char ch4[50];
   char ch5[50];
   char ch6[50];
   GtkWidget *Alerte;
   GtkWidget *input1, *output2, *output3, *output4, *output5, *output6;
   input1=lookup_widget(ob,"mdzentryidr");
   output2=lookup_widget(ob,"mdzentrynomcaptr");
   output3=lookup_widget(ob,"mdzentryvalmaxr");
   output4=lookup_widget(ob,"mdzentryvalminr");
   output5=lookup_widget(ob,"comboboxentrytyper");
   output6=lookup_widget(ob,"comboboxentrymarquer");

   strcpy(ch1,gtk_entry_get_text(GTK_ENTRY(input1)));
   t=verif_capt(c,ch1);
   if (t==1)
      {
           chercher_capt(c,ch1,ch2,ch3,ch4,ch5,ch6);
           gtk_entry_set_text(output2,ch2);
           gtk_entry_set_text(output3,ch5);
           gtk_entry_set_text(output4,ch6);
	   if(strcmp(ch3,"Temperature")==0)
 		{		
 		k=0;
		}
	   else if (strcmp(ch3,"Humidite")==0)
	       {		
		k=1;
		}
	   gtk_combo_box_set_active(GTK_COMBO_BOX(output5),k);
	   if(strcmp(ch4,"Marque1")==0)
 		{		
 		m=0;
		}
	   else if (strcmp(ch4,"Marque2")==0)
	       {		
		m=1;
		}
	   else if (strcmp(ch4,"Marque3")==0)
	       {		
		m=2;
		}
	   gtk_combo_box_set_active(GTK_COMBO_BOX(output6),m);
      }
   else
     {
           gtk_entry_set_text(output2,"");
           gtk_entry_set_text(output3,"");
           gtk_entry_set_text(output4,"");
           Alerte=create_Alerte();
           gtk_widget_show(Alerte);
     }
}


void
on_mdzbuttonenregistrer_clicked        (GtkButton       *ob,
                                        gpointer         user_data)
{
   capteur c;
   char ch1[50];
   char ch2[50];
   char ch3[50];
   char ch4[50];
   char ch5[50];
   char ch6[50];
   GtkWidget *input1, *input2, *input3, *input4, *input5, *input6;
   GtkWidget *Succes;

   input1=lookup_widget(ob,"mdzentryidr");
   input2=lookup_widget(ob,"mdzentrynomcaptr");
   input3=lookup_widget(ob,"comboboxentrytyper");
   input4=lookup_widget(ob,"comboboxentrymarquer");
   input5=lookup_widget(ob,"mdzentryvalmaxr");
   input6=lookup_widget(ob,"mdzentryvalminr");

   strcpy(ch1,gtk_entry_get_text(GTK_ENTRY(input1)));
   strcpy(ch2,gtk_entry_get_text(GTK_ENTRY(input2)));
   strcpy(ch3,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)));
   strcpy(ch4,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input4)));
   strcpy(ch5,gtk_entry_get_text(GTK_ENTRY(input5)));
   strcpy(ch6,gtk_entry_get_text(GTK_ENTRY(input6)));
   modifier_capt(c,ch1,ch2,ch3,ch4,ch5,ch6);
   Succes=create_Succes();
   gtk_widget_show(Succes);
   gtk_entry_set_text(input1,"");
   gtk_entry_set_text(input2,"");
   gtk_entry_set_text(input5,"");
   gtk_entry_set_text(input6,"");
   gtk_combo_box_set_active(GTK_COMBO_BOX(input3),-1);
   gtk_combo_box_set_active(GTK_COMBO_BOX(input4),-1);
   
   
}


void
on_mdzbuttonsuppsupp_clicked           (GtkButton       *ob,
                                        gpointer         user_data)
{
   capteur c;
   int t;
   GtkWidget *input1;
   GtkWidget *Alerte,*Succes;
   char ch1[50];
   input1=lookup_widget(ob,"mdzentrysuppsupp");
   strcpy(ch1,gtk_entry_get_text(GTK_ENTRY(input1)));
   t=verif_capt(c,ch1);
   if(t==1)
     {
       supprimer_capt(c,ch1);
       Succes=create_Succes();
       gtk_widget_show(Succes);
       gtk_entry_set_text(input1,"");
       
     }
   else
     {
       Alerte=create_Alerte();
       gtk_widget_show(Alerte);
     }
}


void
on_mdzbuttonokay_clicked               (GtkButton       *ob,
                                        gpointer         user_data)
{
   GtkWidget *Alerte;
   
   Alerte=lookup_widget(ob,"Alerte");
   gtk_widget_destroy(Alerte);
}


void
on_mdzbuttontesttest_clicked           (GtkButton       *ob,
                                        gpointer         user_data)
{
   FILE *f,*g,*h;
   capteur c;
   border b;
   yoat y;
   char ch1[50];
   char ch2[50];
   int a=0,i=0;
   date d;
   GtkWidget *input1, *input2, *input3, *input4, *input5, *output6;
   GtkWidget *Alerte;

   input1=lookup_widget(ob,"mdzentryidtest");
   input2=lookup_widget(ob,"mdzspinbuttonjour");
   input3=lookup_widget(ob,"mdzspinbuttonmois");
   input4=lookup_widget(ob,"mdzspinbuttonannee");
   output6=lookup_widget(ob,"mdzentryval");
   strcpy(ch1,gtk_entry_get_text(GTK_ENTRY(input1)));
   d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input2));
   d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3));
   d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
   f=fopen("capteur.txt","r");
   g=fopen("taraji.txt","a+");
   if(f==NULL || g==NULL)
    {
      return;
    }
   else
    {
      while(fscanf(f,"%s %s %s %s %s %s \n",c.identifiant,c.nom,c.type,c.marque,c.max,c.min)!=EOF)
        {
           fprintf(g,"%s %s %s %s \n",c.identifiant,c.type,c.max,c.min);
        }
      fclose(f);
      fclose(g); 
    }
   g=fopen("taraji.txt","r");
   if(g==NULL)
    {
      return;
    }
   else
    {
      while(fscanf(g,"%s %s %s %s \n",b.id,b.type,b.max,b.min)!=EOF)
        {
           if(strcmp(ch1,b.id)==0 && strcmp("Temperature",b.type)==0)
             {
               h=fopen("temperature.txt","r");
               if(h==NULL)
               {
                return;
               }
               else
               {
                  while(fscanf(h,"%s %d %d %d %s \n",y.id,&y.jour,&y.mois,&y.annee,y.valeur)!=EOF)
                      {
                        if(strcmp(ch1,y.id)==0 && y.jour==d.jour && y.mois==d.mois && y.annee==d.annee)
                         {
                            gtk_entry_set_text(output6,y.valeur);
                         }
                      }
                  fclose(h);
               }
            
             }
           else if(strcmp(ch1,b.id)==0 && strcmp("Humidite",b.type)==0)
             {
               h=fopen("humidite.txt","r");
               if(h==NULL)
               {
                return;
               }
               else
               {
                  while(fscanf(h,"%s %d %d %d %s \n",y.id,&y.jour,&y.mois,&y.annee,y.valeur)!=EOF)
                      {
                        if(strcmp(ch1,y.id)==0 && y.jour==d.jour && y.mois==d.mois && y.annee==d.annee)
                         {
                            gtk_entry_set_text(output6,y.valeur);
                         }
                      }
                   fclose(h);
               }
              }

            }
          fclose(g);
         }
 
         remove("taraji.txt");
   f=fopen("capteur.txt","r");

   if(f==NULL )
    {
      return;
    }
   else
    {
      while(fscanf(f,"%s %s %s %s %s %s \n",c.identifiant,c.nom,c.type,c.marque,c.max,c.min)!=EOF)
        {
           if(strcmp(ch1,c.identifiant)!=0)
             {
                  i++;
             }
            a++;
        }
      fclose(f);
    }
   if(i==a)
     {
                    Alerte=create_Alerte();
                    gtk_widget_show(Alerte);
	            gtk_entry_set_text(output6,"");
     }
  
}


void
on_mdzbuttonafficher_clicked           (GtkButton       *objet,
                                        gpointer         user_data)
{

   GtkWidget *Capteurs, *Defect;
   GtkWidget *treeviewdefect;

   FILE *f,*g,*h;
   capteur c;
   int n=1;
   int id,iden,j,m,a,i;
   char type[50];
   int v;
   int t[50];

   t[0]=3;
   f=fopen("capteur.txt","r");
   g=fopen("hola.txt","w");
   if(f==NULL || g==NULL)
    {
      return;
    }
   else
    {
      while(fscanf(f,"%s %s %s %s %s %s \n",c.identifiant,c.nom,c.type,c.marque,c.max,c.min)!=EOF)
        {
           fprintf(g,"%s %s \n",c.identifiant,c.type);
        }
      fclose(f);
      fclose(g); 
    }
   g=fopen("hola.txt","r");
   if(g==NULL)
    {
      return;
    }
   else
    {
      while(fscanf(g,"%d %s \n",&id,type)!=EOF)
        {
           if(strcmp("Temperature",type)==0)
             {
               h=fopen("tempo.txt","r");
               if(h==NULL)
               {
                return;
               }
               else
               {
                  while(fscanf(h,"%d %d %d %d %d \n",&iden,&j,&m,&a,&v)!=EOF)
                      {
                        if(id==iden && (v<-5 || v>50))
                         {
                            for(i=0;i<n && t[i]!=iden;i++)
				{
				   if(i==n-1)
					{
					  t[n]=iden;
					  n++;
					}
				}
                         }
                      }
                  fclose(h);
               }
            
             }
           else if(strcmp("Humidite",type)==0)
             {
               h=fopen("hum.txt","r");
               if(h==NULL)
               {
                return;
               }
               else
               {
                  while(fscanf(h,"%d %d %d %d %d \n",&iden,&j,&m,&a,&v)!=EOF)
                      {
                        if(id==iden && (v<30 || v>100))
                         {
                             for(i=0;i<n && t[i]!=iden;i++)
				{
				   if(i==n-1)
					{
					  t[n]=iden;
					  n++;
					}
				}
                         }
                      }
                   fclose(h);
               }
              }

            }
          fclose(g);
         }

      f=fopen("defect.txt","w");
   if(f!=NULL)
  {

    for(i=0;i<n;i++)
    {
      fprintf(f,"%d \n",t[i]);
    }
    fclose(f);
  }
   Capteurs=lookup_widget(objet,"Capteurs");
   gtk_widget_destroy(Capteurs);
   Defect=create_Defect();
   gtk_widget_show(Defect);
   treeviewdefect=lookup_widget(Defect,"treeviewdefect");
   afficher_defect(treeviewdefect);
}


void
on_mdzbuttonback_clicked          (GtkButton       *objet,
                                 gpointer         user_data)
{
    GtkWidget *Capteurs, *Defect;
    GtkWidget *mdztreeviewcapteur;
    Defect=lookup_widget(objet,"Defect");
    gtk_widget_destroy(Defect);
    Capteurs=create_Capteurs();
    gtk_widget_show(Capteurs);
       mdztreeviewcapteur=lookup_widget(Capteurs,"mdztreeviewcapteur");
   afficher_capt(mdztreeviewcapteur);

}


void
on_mdzbuttonsa_clicked                 (GtkButton       *ob,
                                        gpointer         user_data)
{
   GtkWidget *Succes;
   
   Succes=lookup_widget(ob,"Succes");
   gtk_widget_destroy(Succes);
}

void
on_mdzbuttonquit_clicked               (GtkButton       *ob,
                                        gpointer         user_data)
{
   GtkWidget *Login;
   
   Login=lookup_widget(ob,"Login");
   gtk_widget_destroy(Login);
}


void
on_mdzbuttonlogin_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *un,*pwd, *Acceuil,*Login;
char user[20];
char pass[20];
int trouve;
un = lookup_widget (button, "entryusername_log");
pwd= lookup_widget (button, "entrypassword_log");
strcpy(user, gtk_entry_get_text(GTK_ENTRY(un)));
strcpy(pass, gtk_entry_get_text(GTK_ENTRY(pwd)));

trouve=verifier(user,pass);
if(trouve==1)
{
   Acceuil=create_Acceuil();
   gtk_widget_show (Acceuil);
   Login=lookup_widget(button,"Login");
   gtk_widget_destroy(Login);
}
}


void
on_ZLradiobutton1Male_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{BR=1;}
}


void
on_ZLradiobutton2Femelle_toggled       (GtkToggleButton *togglebutton,
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
t=chercher1(tab,n,IDC);	
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
	GtkWidget *dialog3;
	dialog3=create_dialog3() ;
	gtk_widget_show(dialog3) ;
	}
	else 
	{
	GtkWidget *dialog1;
	dialog1=create_dialog1() ;
	gtk_widget_show(dialog1) ;
	}
	
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
treeview1=lookup_widget(windowAffichage,"ZLtreeview1");
afficher_troupeaux(treeview1);
}


void
on_ZLcheckbutton1_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ZLtreeview1_row_activated           (GtkTreeView     *treeview,
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
GtkWidget *Acceuil;
GtkWidget *windowAffichage;
windowAffichage=lookup_widget(objet,"windowAffichage");

gtk_widget_destroy(windowAffichage);
Acceuil=create_Acceuil();
gtk_widget_show(Acceuil);
}


void
on_ZLbutton1AJ_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowAffichage;
GtkWidget *windowAMSTroupeaux;
windowAffichage=lookup_widget(objet,"windowAffichage");
gtk_widget_destroy(windowAffichage);
windowAMSTroupeaux=create_windowAMSTroupeaux();
gtk_widget_show(windowAMSTroupeaux);
}


void
on_ZLbutton2SU_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowAffichage;
GtkWidget *windowAMSTroupeaux;
windowAffichage=lookup_widget(objet,"windowAffichage");
gtk_widget_destroy(windowAffichage);
windowAMSTroupeaux=create_windowAMSTroupeaux();
gtk_widget_show(windowAMSTroupeaux);
}


void
on_ZLbutton3Mo_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowAffichage;
GtkWidget *windowAMSTroupeaux;
windowAffichage=lookup_widget(objet,"windowAffichage");
gtk_widget_destroy(windowAffichage);
windowAMSTroupeaux=create_windowAMSTroupeaux();
gtk_widget_show(windowAMSTroupeaux);
}


void
on_ZLbutton4Chercher_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowAffnbrtroupeaux;
GtkWidget *windowDashB;
windowDashB=lookup_widget(objet,"windowDashB");

gtk_widget_destroy(windowDashB);
windowAffnbrtroupeaux=create_windowAffnbrtroupeaux();
gtk_widget_show(windowAffnbrtroupeaux);
}


void
on_ZLtreeview2_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_ZLbutton5chercherType_clicked       (GtkWidget       *objet_graphique,
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
treeview2=lookup_widget(windowAffnbrtroupeaux,"ZLtreeview2");

strcpy(type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));





nb=rechercher_troupeaux_par_type(treeview2,"troupeaux.txt",type,&n);
sprintf(labelType,"%d",nb);
gtk_label_set_text(GTK_LABEL( lookup_widget(windowAffnbrtroupeaux,"ZLlabel19") ),labelType);
sprintf(labelType,"%d",n);
gtk_label_set_text(GTK_LABEL( lookup_widget(windowAffnbrtroupeaux,"ZLlabel20") ),labelType);


}


void
on_ZLbutton6retour_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowAffnbrtroupeaux;
GtkWidget *windowDashB;

windowAffnbrtroupeaux=lookup_widget(objet,"windowAffnbrtroupeaux");

gtk_widget_destroy(windowAffnbrtroupeaux);
windowDashB=create_windowDashB();
gtk_widget_show(windowDashB);

}


void
on_ZLbutton1close_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dialog1=lookup_widget(GTK_WIDGET(button),("dialog1"));

gtk_widget_destroy(dialog1);
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


void
on_ZLcheckbutton1_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_CHECK_BUTTON (togglebutton)))
{V=1;}
}


void
on_retourouvrier_clicked               (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *Acceuil;
GtkWidget *HMWindowGestionOuvrier;
HMWindowGestionOuvrier=lookup_widget(objet,"HMWindowGestionOuvrier");

gtk_widget_destroy(HMWindowGestionOuvrier);
Acceuil=create_Acceuil();
gtk_widget_show(Acceuil);
}


void
on_retourcapt_clicked                  (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *Acceuil;
GtkWidget *Capteurs;
Capteurs=lookup_widget(objet,"Capteurs");

gtk_widget_destroy(Capteurs);
Acceuil=create_Acceuil();
gtk_widget_show(Acceuil);
}


void
on_buttonpladd_clicked                 (GtkButton       *objet,
                                        gpointer         user_data)
{
   GtkWidget *Plantation, *Plajouter;

   Plantation=lookup_widget(objet,"Plantation");
   gtk_widget_destroy(Plantation);
   Plajouter=create_Plajouter();
   gtk_widget_show(Plajouter);
}


void
on_buttonplchange_clicked              (GtkButton       *objet,
                                        gpointer         user_data)
{
   GtkWidget *Plantation, *Plmodifier;

   Plantation=lookup_widget(objet,"Plantation");
   gtk_widget_destroy(Plantation);
   Plmodifier=create_Plmodifier();
   gtk_widget_show(Plmodifier);
}


void
on_buttonpldelete_clicked              (GtkButton       *objet,
                                        gpointer         user_data)
{
   GtkWidget *Plantation, *Plsupprimer;

   Plantation=lookup_widget(objet,"Plantation");
   gtk_widget_destroy(Plantation);
   Plsupprimer=create_Plsupprimer();
   gtk_widget_show(Plsupprimer);
}


void
on_buttonplajout_clicked               (GtkButton       *ob,
                                        gpointer         user_data)
{
   zoro z;
   GtkWidget *input1, *input2, *input3, *input4, *input5, *input6;
   GtkWidget *Plajouter,*Succes;

   Plajouter=lookup_widget(ob,"Plajouter");

   input1=lookup_widget(ob,"spinbuttonjour");
   input2=lookup_widget(ob,"spinbuttonmois");
   input3=lookup_widget(ob,"spinbuttonannee");
   input4=lookup_widget(ob,"entryidpl");
   input5=lookup_widget(ob,"comboboxentryduree");
   input6=lookup_widget(ob,"entryplpl");

   z.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input1));
   z.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input2));
   z.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3));
   strcpy(z.id,gtk_entry_get_text(GTK_ENTRY(input4)));
   strcpy(z.duree,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)));
   strcpy(z.plante,gtk_entry_get_text(GTK_ENTRY(input6)));
   if(A==3)
	{strcpy(z.type,"gravitaire");}
   else if (A==2)
	{strcpy(z.type,"goutte-à-goutte");}
  else if (A==1)
	{strcpy(z.type,"par-aspiration");}
  ajouter_plant(z);
   Succes=create_Succes();
   gtk_widget_show(Succes);
}


void
on_buttonbackajout_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{
   GtkWidget *Plantation, *Plajouter;
   GtkWidget *treeviewplant;

   Plajouter=lookup_widget(objet,"Plajouter");
   gtk_widget_destroy(Plajouter);
   Plantation=create_Plantation();
   gtk_widget_show(Plantation);
   treeviewplant=lookup_widget(Plantation,"treeviewplant");
   afficher_plant(treeviewplant);
}


void
on_buttonplsearch_clicked              (GtkButton       *ob,
                                        gpointer         user_data)
{
   sanji s;
   int t;
   int k=-1;
   char ch1[50];
   char ch2[50];
   char ch3[50];
   char ch4[50];
   char ch5[50];
   GtkWidget *Alerte;
   GtkWidget *input1, *output2, *output3, *output4, *output5;
   input1=lookup_widget(ob,"entrymidpl");
   output2=lookup_widget(ob,"entrymdate");
   output3=lookup_widget(ob,"comboboxentrymduree");
   output4=lookup_widget(ob,"entrymplpl");
   output5=lookup_widget(ob,"entrymtype");


   strcpy(ch1,gtk_entry_get_text(GTK_ENTRY(input1)));
   t=verif_plant(s,ch1);
   if (t==1)
      {
           chercher_plant(s,ch1,ch2,ch3,ch4,ch5);
           gtk_entry_set_text(output2,ch2);
	   if(strcmp(ch3,"1semaine")==0)
 		{		
 		k=0;
		}
	   else if (strcmp(ch3,"2semaine")==0)
	       {		
		k=1;
		}
	   else if (strcmp(ch3,"3semaine")==0)
	       {		
		k=2;
		}
	   else if (strcmp(ch3,"1mois")==0)
	       {		
		k=3;
		}
	   gtk_combo_box_set_active(GTK_COMBO_BOX(output3),k);
           gtk_entry_set_text(output4,ch4);
           gtk_entry_set_text(output5,ch5);
      }
   else
     {
           gtk_entry_set_text(output2,"");
           gtk_entry_set_text(output5,"");
           gtk_entry_set_text(output4,"");
           gtk_entry_set_text(input1,"");
           Alerte=create_Alerte();
           gtk_widget_show(Alerte);
     }
}


void
on_buttonplsave_clicked                (GtkButton       *ob,
                                        gpointer         user_data)
{
   sanji s;
   char ch1[50];
   char ch2[50];
   char ch3[50];
   char ch4[50];
   char ch5[50];
   GtkWidget *input1, *input2, *input3, *input4, *input5, *input6;
   GtkWidget *Succes;

   input1=lookup_widget(ob,"entrymidpl");
   input2=lookup_widget(ob,"entrymdate");
   input3=lookup_widget(ob,"comboboxentrymduree");
   input4=lookup_widget(ob,"entrymplpl");
   input5=lookup_widget(ob,"entrymtype");

   strcpy(ch1,gtk_entry_get_text(GTK_ENTRY(input1)));
   strcpy(ch2,gtk_entry_get_text(GTK_ENTRY(input2)));
   strcpy(ch3,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)));
   strcpy(ch4,gtk_entry_get_text(GTK_ENTRY(input4)));
   strcpy(ch5,gtk_entry_get_text(GTK_ENTRY(input5)));
   modifier_plant(s,ch1,ch2,ch3,ch4,ch5);
   Succes=create_Succes();
   gtk_widget_show(Succes);
   gtk_entry_set_text(input1,"");
   gtk_entry_set_text(input2,"");
   gtk_entry_set_text(input4,"");
   gtk_entry_set_text(input5,"");
   
}


void
on_buttonbackmodif_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{
   GtkWidget *Plantation, *Plmodifier;
   GtkWidget *treeviewplant;

   Plmodifier=lookup_widget(objet,"Plmodifier");
   gtk_widget_destroy(Plmodifier);
   Plantation=create_Plantation();
   gtk_widget_show(Plantation);
   treeviewplant=lookup_widget(Plantation,"treeviewplant");
   afficher_plant(treeviewplant);
}


void
on_buttonretoursupp_clicked            (GtkButton       *objet,
                                        gpointer         user_data)
{
   GtkWidget *Plantation, *Plsupprimer;
   GtkWidget *treeviewplant;

   Plsupprimer=lookup_widget(objet,"Plsupprimer");
   gtk_widget_destroy(Plsupprimer);
   Plantation=create_Plantation();
   gtk_widget_show(Plantation);
   treeviewplant=lookup_widget(Plantation,"treeviewplant");
   afficher_plant(treeviewplant);
}


void
on_buttonplsupp_clicked                (GtkButton       *ob,
                                        gpointer         user_data)
{
   sanji s;
   int t;
   GtkWidget *input1;
   GtkWidget *Alerte,*Succes;
   char ch1[50];
   input1=lookup_widget(ob,"entryplsupp");
   strcpy(ch1,gtk_entry_get_text(GTK_ENTRY(input1)));
   t=verif_plant(s,ch1);
   if(t==1)
     {
       supprimer_plant(s,ch1);
       Succes=create_Succes();
       gtk_widget_show(Succes);
       gtk_entry_set_text(input1,"");
       
     }
   else
     {
       Alerte=create_Alerte();
       gtk_widget_show(Alerte);
     }
}


void
on_buttonplantation_clicked            (GtkButton       *ob,
                                        gpointer         user_data)
{
   GtkWidget *Plantation, *Acceuil;
   GtkWidget *treeviewplant;

   Acceuil=lookup_widget(ob,"Acceuil");
   gtk_widget_destroy(Acceuil);
   Plantation=create_Plantation();
   gtk_widget_show(Plantation);
   treeviewplant=lookup_widget(Plantation,"treeviewplant");
   afficher_plant(treeviewplant);
}


void
on_buttonretourplant_clicked           (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *Acceuil;
GtkWidget *Plantation;
Plantation=lookup_widget(objet,"Plantation");

gtk_widget_destroy(Plantation);
Acceuil=create_Acceuil();
gtk_widget_show(Acceuil);
}


void
on_radiobuttonasp_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{A=1;}
}


void
on_radiobuttongout_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{A=2;}
}


void
on_radiobuttongrav_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{A=3;}
}


void
on_buttoncladd_clicked                 (GtkButton       *objet,
                                        gpointer         user_data)
{
   GtkWidget *Client, *Clajouter;

   Client=lookup_widget(objet,"Client");
   gtk_widget_destroy(Client);
   Clajouter=create_Clajouter();
   gtk_widget_show(Clajouter);
}


void
on_buttonclchange_clicked              (GtkButton       *objet,
                                        gpointer         user_data)
{
   GtkWidget *Client, *Clmodifier;

   Client=lookup_widget(objet,"Client");
   gtk_widget_destroy(Client);
   Clmodifier=create_Clmodifier();
   gtk_widget_show(Clmodifier);
}


void
on_buttoncldelete_clicked              (GtkButton       *objet,
                                        gpointer         user_data)
{
   GtkWidget *Client, *Clsupprimer;

   Client=lookup_widget(objet,"Client");
   gtk_widget_destroy(Client);
   Clsupprimer=create_Clsupprimer();
   gtk_widget_show(Clsupprimer);
}


void
on_buttonfavoris_clicked               (GtkButton       *objet,
                                        gpointer         user_data)
{
   GtkWidget *Client, *Clfavoris;

   Client=lookup_widget(objet,"Client");
   gtk_widget_destroy(Client);
   Clfavoris=create_Clfavoris();
   gtk_widget_show(Clfavoris);
}


void
on_radiobuttonmale_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{B=1;}
}


void
on_radiobuttonfemme_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{B=2;}
}


void
on_buttonsearchcl_clicked              (GtkButton       *ob,
                                        gpointer         user_data)
{
   client c;
   int t;
   char ch1[50];
   char ch2[50];
   char ch3[50];
   char ch4[50];
   char ch5[50];
   char ch6[50];
   GtkWidget *Alerte;
   GtkWidget *input1, *output2, *output3, *output4, *output5, *output6;
   input1=lookup_widget(ob,"mdzentryclcinm");
   output2=lookup_widget(ob,"mdzentryclnomm");
   output3=lookup_widget(ob,"mdzentryclprenomm");
   output4=lookup_widget(ob,"mdzentryclsexem");
   output5=lookup_widget(ob,"mdzentryclemailm");
   output6=lookup_widget(ob,"mdzentryclphonem");


   strcpy(ch1,gtk_entry_get_text(GTK_ENTRY(input1)));
   t=verif_client(c,ch1);
   if (t==1)
      {
           chercher_client(c,ch1,ch2,ch3,ch4,ch5,ch6);
           gtk_entry_set_text(output2,ch2);
           gtk_entry_set_text(output3,ch3);
           gtk_entry_set_text(output4,ch4);
	   gtk_entry_set_text(output5,ch5);
           gtk_entry_set_text(output6,ch6);
      }
   else
     {
           gtk_entry_set_text(output2,"");
           gtk_entry_set_text(output5,"");
           gtk_entry_set_text(output4,"");
           gtk_entry_set_text(output6,"");
           gtk_entry_set_text(output3,"");
           gtk_entry_set_text(input1,"");
           Alerte=create_Alerte();
           gtk_widget_show(Alerte);
     }
}


void
on_buttonsavecl_clicked                (GtkButton       *ob,
                                        gpointer         user_data)
{
   client c;
   char ch1[50];
   char ch2[50];
   char ch3[50];
   char ch4[50];
   char ch5[50];
   char ch6[50];
   GtkWidget *input1, *input2, *input3, *input4, *input5, *input6;
   GtkWidget *Succes;

   input1=lookup_widget(ob,"mdzentryclcinm");
   input2=lookup_widget(ob,"mdzentryclnomm");
   input3=lookup_widget(ob,"mdzentryclprenomm");
   input4=lookup_widget(ob,"mdzentryclsexem");
   input5=lookup_widget(ob,"mdzentryclemailm");
   input6=lookup_widget(ob,"mdzentryclphonem");
   strcpy(ch1,gtk_entry_get_text(GTK_ENTRY(input1)));
   strcpy(ch2,gtk_entry_get_text(GTK_ENTRY(input2)));
   strcpy(ch3,gtk_entry_get_text(GTK_ENTRY(input3)));
   strcpy(ch4,gtk_entry_get_text(GTK_ENTRY(input4)));
   strcpy(ch5,gtk_entry_get_text(GTK_ENTRY(input5)));
   strcpy(ch6,gtk_entry_get_text(GTK_ENTRY(input2)));
   modifier_client(c,ch1,ch2,ch3,ch4,ch5,ch6);
   Succes=create_Succes();
   gtk_widget_show(Succes);
   gtk_entry_set_text(input1,"");
   gtk_entry_set_text(input2,"");
   gtk_entry_set_text(input4,"");
   gtk_entry_set_text(input5,"");
   gtk_entry_set_text(input6,"");
}


void
on_buttonbackmodifcl_clicked           (GtkButton       *objet,
                                        gpointer         user_data)
{
   GtkWidget *Client, *Clmodifier;
   GtkWidget *treeviewclient;

   Clmodifier=lookup_widget(objet,"Clmodifier");
   gtk_widget_destroy(Clmodifier);
   Client=create_Client();
   gtk_widget_show(Client);
   treeviewclient=lookup_widget(Client,"treeviewclient");
   afficher_client(treeviewclient);
}


void
on_mdzbuttonbacksuppcl_clicked         (GtkButton       *objet,
                                        gpointer         user_data)
{
   GtkWidget *Client, *Clsupprimer;
   GtkWidget *treeviewclient;

   Clsupprimer=lookup_widget(objet,"Clsupprimer");
   gtk_widget_destroy(Clsupprimer);
   Client=create_Client();
   gtk_widget_show(Client);
   treeviewclient=lookup_widget(Client,"treeviewclient");
   afficher_client(treeviewclient);
}


void
on_mdzbuttonsuppcl_clicked             (GtkButton       *ob,
                                        gpointer         user_data)
{
   client c;
   int t;
   GtkWidget *input1;
   GtkWidget *Alerte,*Succes;
   char ch1[50];
   input1=lookup_widget(ob,"mdzentrysuppcl");
   strcpy(ch1,gtk_entry_get_text(GTK_ENTRY(input1)));
   t=verif_client(c,ch1);
   if(t==1)
     {
       supprimer_client(c,ch1);
       Succes=create_Succes();
       gtk_widget_show(Succes);
       gtk_entry_set_text(input1,"");
       
     }
   else
     {
       Alerte=create_Alerte();
       gtk_widget_show(Alerte);
     }
}


void
on_buttonbackfavoris_clicked           (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *Client, *Clfavoris;

   Clfavoris=lookup_widget(objet,"Clfavoris");
   gtk_widget_destroy(Clfavoris);
   Client=create_Client();
   gtk_widget_show(Client);
}


void
on_buttonclbackadd_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{
   GtkWidget *Client, *Clajouter;
   GtkWidget *treeviewclient;

   Clajouter=lookup_widget(objet,"Clajouter");
   gtk_widget_destroy(Clajouter);
   Client=create_Client();
   gtk_widget_show(Client);
   treeviewclient=lookup_widget(Client,"treeviewclient");
   afficher_client(treeviewclient);
}


void
on_AcceuilBouttonClient_clicked        (GtkButton       *ob,
                                        gpointer         user_data)
{
   GtkWidget *Client, *Acceuil;

   Acceuil=lookup_widget(ob,"Acceuil");
   gtk_widget_destroy(Acceuil);
   Client=create_Client();
   gtk_widget_show(Client);
}


void
on_buttonaj_clicked                    (GtkButton       *ob,
                                        gpointer         user_data)
{
   client c;
   GtkWidget *input1, *input2, *input3, *input4, *input5;
   GtkWidget *Clajouter,*Succes;

   Clajouter=lookup_widget(ob,"Clajouter");

   input1=lookup_widget(ob,"mdzentryclcin");
   input2=lookup_widget(ob,"mdzentryclnom");
   input3=lookup_widget(ob,"mdzentryclprenom");
   input4=lookup_widget(ob,"mdzentryclemail");
   input5=lookup_widget(ob,"mdzentryclphone");

   strcpy(c.cin,gtk_entry_get_text(GTK_ENTRY(input1)));
   strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(input2)));  
   strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
   strcpy(c.email,gtk_entry_get_text(GTK_ENTRY(input4)));
   strcpy(c.phone,gtk_entry_get_text(GTK_ENTRY(input5)));
   if (B==1)
	{strcpy(c.sexe,"Homme");}
   else if (B==2)
	{strcpy(c.sexe,"Femme");}
   ajouter_client(c);
   Succes=create_Succes();
   gtk_widget_show(Succes);
}


void
on_RetourDash_clicked                  (GtkButton       *ov,
                                        gpointer         user_data)
{
GtkWidget *windowDashB;
 GtkWidget *Acceuil;
 
 windowDashB=lookup_widget(ov,"windowDashB");
 gtk_widget_destroy(windowDashB);
 Acceuil=lookup_widget(ov,"Acceuil");
Acceuil=lookup_widget(ov,"windowDashB");
Acceuil=create_Acceuil();
gtk_widget_show(Acceuil);

}


void
on_BTretourC_clicked                   (GtkButton       *ob,
                                        gpointer         user_data)
{
 GtkWidget *Capteurs, *Acceuil;
  

   Capteurs=lookup_widget(ob,"Capteurs");
   gtk_widget_destroy(Capteurs);
   Acceuil=create_Acceuil();
   gtk_widget_show(Acceuil);
 
}

