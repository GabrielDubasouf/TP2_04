/*********************************************************************/
/* Fichier   : NEURONES.H  (fichier donné aux élèves)             	 */
/*															   		 */
/* Ce module implante des fonctions de gestion du réseau de neurones */
/* et implémente l'algorithme du perceptron (initialiser un neurone) */
/*********************************************************************/
#if (!defined(T_NEURONE))
#define T_NEURONE 0

#include "liste_donnees.h"

/***************************
   LES CONSTANTES
***************************/
#define  EPSILON     0.0000001    //marge d'erreur minimale
#define  BETA        0.1          //la constante d'apprentissage (doit être entre [0, 0.25])
#define  OUTPUT_MIN -2.0          //seuil minimal pour accepter le résultat d'un neurone
#define  ECART_MAX   6.0          //valeur maximale absolue d'un poids-neurone
#define  INTENS_MAX   16          //l'intensité maximale de l'affichage d'un neurone en gris

/* nom du fichier binaire utilisé pour sauvgarder/récupérer l'état des neurones */
#define  FICH_BIN   "sauvegarde_reseau.bin"

/***************************
   LES TYPES STRUCTURÉS
***************************/

/* type-struct pour un seul neurone */
typedef struct {
    double poids[NB_VARY * NB_VARX];    //tableau statique des poids pour faciliter la sauvegarde
    double bias;                        //le "biais" du neurone  
    double nb_inputs;                   //le nombre de données reçues (= NB_VARY * NB_VARX)
    double output;                      //la valeur de sortie du neurone après le calcul
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
/* Fonction qui crée et retourne un réseau de "nb_neurones", chacun ayant "nb_inputs" entrées. */
/* Paramètres (2) :                                                                            */
/*         - nb_neurones : le nombre de neurones dans le réseau neuronal.                      */
/*         - nb_inputs : le nombres de données reçues par chaque neurone.                      */
/* Retour : le nouveau réseau ainsi crée et initialisé (t_reseau_neuro).                       */
t_reseau_neuro creer_reseau(int nb_neurones, int nb_inputs);

//DESTRUCTEUR
/* Permet de libérer la mémoire de chaque neurone ainsi que la liste de neurones de "ptr_res". */
/* Paramètre (1) : le réseau à détruire reçu par référence (t_reseau_neuro *).                 */
void detruire_reseau(t_reseau_neuro* ptr_res);

/* Implémente l'algorithme du perceptron pour qualibrer les poids et le biais du neurone #no   */
/* à partir des données contenues dans la liste "input".                                       */
/* Paramètres (3) :                                                                            */
/*         - no : le numéro (position) du neurone reçu.                                        */
/*         - data : pointeur sur la liste de toutes les données à utiliser.                    */
/*         - neuro : pointeur sur le neurone à qualibrer.                                      */
/* Retour : le nombre d'itération necéssaires pour atteindre l'équilibre des poids (int).      */
int  perceptron(int no, const t_liste_data* input, t_neurone* neuro);

/* Fonction qui effectue l'étape d'apprentissage d'un réseau avec les données "input_dat".     */
/* Paramètres (2) :                                                                            */
/*         - neuros : pointeur sur la liste de neurones à éduquer.                             */
/*         - data : pointeur sur la liste de toutes les données à utiliser.                    */
void apprentissage_reseau(t_reseau_neuro* neuros, const t_liste_data* input_dat);

/* ACCESSEUR : permet d'obtenir la valeur du ".bias* du neurone "neuro".                       */
/* Parametre (1) :                                                                             */
/*         - neuro : pointeur sur le neurone.                                                  */
double get_bias(const t_neurone* neuro);

/* Permet d'afficher graphiquement tous les poids des neurones avec des teintes de gris.       */
/* Parametre (1) :                                                                             */
/*         - neuros : pointeur sur la liste de neurones.                                       */
void afficher_neurones(const t_reseau_neuro* neuros);

/* Fonction qui effectue un test de la donnée "input1" avec le réseau de neurones pour obtenir */
/* le neurone "gagnant" ainsi que sa valeur de sortie maximale.                                */
/* Parametres (3) :                                                                            */
/*         - neuros : pointeur sur la liste de neurones.                                       */
/*         - input1 : pointeur sur la donnée à tester.                                         */
/*         - maxout (sortie) : permet d'obtenir la valeur de sortie du neurone maximal.        */
/* Retour : le numéro (position) du neurone gagnant (int).                                     */
int  executer_test(t_reseau_neuro* neuros, const t_data* input1, int * maxout);

/* Fonction permettant de sauvegarder l'état des neurones du réseau de neurones reçu dans le   */
/* fichier binaire "sauvegarde_reseau.bin".                                                    */
/* Parametres :                                                                                */
/*         - liste_neuros : pointeur sur la liste de neurones.                                 */
void sauvegarder_neurones(const t_reseau_neuro* liste_neuro);

/* Fonction permettant de récupérer l'état des "nb_neurones" du réseau de neurones à partir du */
/* fichier binaire "sauvegarde_reseau.bin".                                                    */
/* Parametres :                                                                                */
/*         - liste_neuros : pointeur sur la liste de neurones.                                 */
/*         - nb_neurones  : le nombre de neurones à récupérer du fichier binaire.              */
/* Retour : 1 si le fichier binaire a pu être ouvert et lu, 0 sinon (fichier nonexistant).     */
int  recuperer_neurones(t_reseau_neuro* liste_neuro, int nb_neurones);

#endif