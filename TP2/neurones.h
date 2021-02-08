/*********************************************************************/
/* Fichier   : NEURONES.H  (fichier donn� aux �l�ves)             	 */
/*															   		 */
/* Ce module implante des fonctions de gestion du r�seau de neurones */
/* et impl�mente l'algorithme du perceptron (initialiser un neurone) */
/*********************************************************************/
#if (!defined(T_NEURONE))
#define T_NEURONE 0

#include "liste_donnees.h"

/***************************
   LES CONSTANTES
***************************/
#define  EPSILON     0.0000001    //marge d'erreur minimale
#define  BETA        0.1          //la constante d'apprentissage (doit �tre entre [0, 0.25])
#define  OUTPUT_MIN -2.0          //seuil minimal pour accepter le r�sultat d'un neurone
#define  ECART_MAX   6.0          //valeur maximale absolue d'un poids-neurone
#define  INTENS_MAX   16          //l'intensit� maximale de l'affichage d'un neurone en gris

/* nom du fichier binaire utilis� pour sauvgarder/r�cup�rer l'�tat des neurones */
#define  FICH_BIN   "sauvegarde_reseau.bin"

/***************************
   LES TYPES STRUCTUR�S
***************************/

/* type-struct pour un seul neurone */
typedef struct {
    double poids[NB_VARY * NB_VARX];    //tableau statique des poids pour faciliter la sauvegarde
    double bias;                        //le "biais" du neurone  
    double nb_inputs;                   //le nombre de donn�es re�ues (= NB_VARY * NB_VARX)
    double output;                      //la valeur de sortie du neurone apr�s le calcul
} t_neurone;

/* type-struct pour la liste de tous les neurones */
typedef struct {
    t_neurone * liste_neurones;         //la liste de neurones est dynamique
    int nb_neurones;
} t_reseau_neuro;


/***************************
   LES FONCTIONS
***************************/

//CONSTRUCTEUR
/* Fonction qui cr�e et retourne un r�seau de "nb_neurones", chacun ayant "nb_inputs" entr�es. */
/* Param�tres (2) :                                                                            */
/*         - nb_neurones : le nombre de neurones dans le r�seau neuronal.                      */
/*         - nb_inputs : le nombres de donn�es re�ues par chaque neurone.                      */
/* Retour : le nouveau r�seau ainsi cr�e et initialis� (t_reseau_neuro).                       */
t_reseau_neuro creer_reseau(int nb_neurones, int nb_inputs);

//DESTRUCTEUR
/* Permet de lib�rer la m�moire de chaque neurone ainsi que la liste de neurones de "ptr_res". */
/* Param�tre (1) : le r�seau � d�truire re�u par r�f�rence (t_reseau_neuro *).                 */
void detruire_reseau(t_reseau_neuro* ptr_res);

/* Impl�mente l'algorithme du perceptron pour qualibrer les poids et le biais du neurone #no   */
/* � partir des donn�es contenues dans la liste "input".                                       */
/* Param�tres (3) :                                                                            */
/*         - no : le num�ro (position) du neurone re�u.                                        */
/*         - data : pointeur sur la liste de toutes les donn�es � utiliser.                    */
/*         - neuro : pointeur sur le neurone � qualibrer.                                      */
/* Retour : le nombre d'it�ration nec�ssaires pour atteindre l'�quilibre des poids (int).      */
int  perceptron(int no, const t_liste_data* input, t_neurone* neuro);

/* Fonction qui effectue l'�tape d'apprentissage d'un r�seau avec les donn�es "input_dat".     */
/* Param�tres (2) :                                                                            */
/*         - neuros : pointeur sur la liste de neurones � �duquer.                             */
/*         - data : pointeur sur la liste de toutes les donn�es � utiliser.                    */
void apprentissage_reseau(t_reseau_neuro* neuros, const t_liste_data* input_dat);

/* ACCESSEUR : permet d'obtenir la valeur du ".bias* du neurone "neuro".                       */
/* Parametre (1) :                                                                             */
/*         - neuro : pointeur sur le neurone.                                                  */
double get_bias(const t_neurone* neuro);

/* Permet d'afficher graphiquement tous les poids des neurones avec des teintes de gris.       */
/* Parametre (1) :                                                                             */
/*         - neuros : pointeur sur la liste de neurones.                                       */
void afficher_neurones(const t_reseau_neuro* neuros);

/* Fonction qui effectue un test de la donn�e "input1" avec le r�seau de neurones pour obtenir */
/* le neurone "gagnant" ainsi que sa valeur de sortie maximale.                                */
/* Parametres (3) :                                                                            */
/*         - neuros : pointeur sur la liste de neurones.                                       */
/*         - input1 : pointeur sur la donn�e � tester.                                         */
/*         - maxout (sortie) : permet d'obtenir la valeur de sortie du neurone maximal.        */
/* Retour : le num�ro (position) du neurone gagnant (int).                                     */
int  executer_test(t_reseau_neuro* neuros, const t_data* input1, int * maxout);

/* Fonction permettant de sauvegarder l'�tat des neurones du r�seau de neurones re�u dans le   */
/* fichier binaire "sauvegarde_reseau.bin".                                                    */
/* Parametres :                                                                                */
/*         - liste_neuros : pointeur sur la liste de neurones.                                 */
void sauvegarder_neurones(const t_reseau_neuro* liste_neuro);

/* Fonction permettant de r�cup�rer l'�tat des "nb_neurones" du r�seau de neurones � partir du */
/* fichier binaire "sauvegarde_reseau.bin".                                                    */
/* Parametres :                                                                                */
/*         - liste_neuros : pointeur sur la liste de neurones.                                 */
/*         - nb_neurones  : le nombre de neurones � r�cup�rer du fichier binaire.              */
/* Retour : 1 si le fichier binaire a pu �tre ouvert et lu, 0 sinon (fichier nonexistant).     */
int  recuperer_neurones(t_reseau_neuro* liste_neuro, int nb_neurones);

#endif