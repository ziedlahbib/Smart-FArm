#include <gtk/gtk.h>


void
on_HMbouttonExit1_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_HMBouttonEnregistrerOuvrier_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_HMBouttonRetour1_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_HMBouttonPresenceOuvrier_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_HMBouttonChercherOuvrier_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_HMBouttonModifierOuvrier_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_HMBouttonSupprimerOuvrier_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_HMBouttonAjouterOuvrier_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_HMbouttonExit2_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_HMBouttonRetour2_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_HMBouttonEnregistrer2_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_HMBouttonOuiEnregistrer_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_HMBouttonNonEnregistrer_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_HMbuttonAfficherTV_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_HMTreeViewOuvrier_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_HMradiobuttonFemme_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_HMradiobuttonHomme_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_HMcheckbuttonPresent_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_HMBouttonFind_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_HMbuttonEnregistrerPresence_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_HMAfficherMO_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_HMButtonReturnFromFind_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_HMButtonReturnFromMO_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_AcceuilBouttonDashboard_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_AcceuilBouttonTroupeaux_clicked     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_AcceuilBouttonEquipement_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_AcceuilBouttonCapteurs_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_AcceuilBouttonOuvrier_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_AcceuilBouttonClient_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_mdzbuttonajouter_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_mdzbuttonmodifier_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_mdzbuttontester_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_mdzbuttonsupprimer_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_mdzbuttonafficher_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_mdzbuttonajout_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_mdzbuttonretourajout_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_mdzbuttonrechercher_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_mdzbuttonenregistrer_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_mdzbuttonretourmodif_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_mdzbuttontesttest_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_mdzbuttonretourtest_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_mdzbuttonsuppsupp_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_mdzbuttonretoursupp_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_mdzbuttonokay_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_mdzbuttonback_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_mdzbuttonsa_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_mdzbuttonquit_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_mdzbuttonlogin_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_ZLradiobutton1Male_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_ZLradiobutton2Femelle_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_ZLbuttonchercher_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_ZLbutton2Mo_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_ZLbutton1Aj_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_ZLbutton3Su_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_ZLbutton4Aff_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_ZLcheckbutton1_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_ZLtreeview1_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_ZLbutton5Re_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_ZLbutton1AJ_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_ZLbutton2SU_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_ZLbutton3Mo_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_ZLbutton4Chercher_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_ZLtreeview2_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_ZLbutton5chercherType_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_ZLbutton6retour_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_ZLbutton1close_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_ZLclosebutton1_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_ZLclosebutton2_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_ZLclosebutton3_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_ZLclosebutton4_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_ZLcheckbutton1_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_retourouvrier_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_retourcapt_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonpladd_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonplchange_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonpldelete_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonplajout_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonbackajout_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonplsearch_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonplsave_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonbackmodif_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonretoursupp_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonplsupp_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonplantation_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonretourplant_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobuttonasp_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttongout_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttongrav_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttoncladd_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonclchange_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttoncldelete_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonfavoris_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobuttonmale_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonfemme_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonsearchcl_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonbackmodifcl_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonsavecl_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_mdzbuttonbacksuppcl_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_mdzbuttonsuppcl_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonbackfavoris_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttoncladd_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonclchange_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttoncldelete_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonfavoris_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobuttonmale_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonfemme_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonsearchcl_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonsavecl_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonbackmodifcl_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_mdzbuttonbacksuppcl_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_mdzbuttonsuppcl_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonbackfavoris_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonclbackadd_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_AcceuilBouttonClient_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonaj_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_RetourDash_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_BTretourC_clicked                   (GtkButton       *button,
                                        gpointer         user_data);
