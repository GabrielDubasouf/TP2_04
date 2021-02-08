/********************************************************************/
/* Fichier   : GRILLE.H  (fichier donn� aux �l�ves)             	*/
/*															   		*/
/* Ce module implante des fonctions de gestion d'une grille 15x10.  */
/* Cette grille permet de saisir des donn�es sous forme de matrice. */
/********************************************************************/
#if (!defined(T_GRILLE))
#define T_GRILLE 0

#include"mode_graphique.h"

#define NB_VARX       10       //taille-X de la grille-input
#define NB_VARY       15       //taille-Y de la grille-input
#define TAILLE_CASE   10       //taille carr�e d'une case-grille � l'�cran en pixels
#define POURCENT_PIX  0.2      //pourcentage minimal de pixels noirs dans une case-grille

/* Les deux codes d'erreur pour la validation de la saisie */
#define ERREUR_TAILLE -1
#define ERREUR_POSI   -2

/* Les bornes utilis�es pour la validation de la saisie */
#define MARGE_MAX      3       //nombre de rang�es vides MAXIMAL en haut et en bas de la grille
#define NB_MIN_VALEURS 2       //nombre minimal de valeurs (=1) d'un cot� ou l'autre du centre

/* le type-tableau pour une grille de 15x10 donn�es (entiers) */
typedef int t_grille[NB_VARY][NB_VARX];     

/***************************
   LES FONCTIONS
***************************/

/* ACCESSEUR : permet d'obtenir la valeur de la case [y][x] de la "grille".                  */
int get_val_grille(t_grille grille, int y, int x);   

/* Fonction qui r�cup�re les NB_VARY x NB_VARX valeurs de la grille � partir de l'�cran.     */
/* Param�tres (3) :                                                                          */
/*          - pos_x, pos_y: la position-�cran de la saisie (en pixels).                      */
/*          - data: le tableau NB_VARY x NB_VARX d'entiers pour recevoir les valeurs (0/1).  */
void recuperer_dessin(int pos_x, int pos_y, t_grille data);

/* Fonction qui valide si l'image saisie est valide. L'image saisie dans la grille ne doit   */
/* pas �tre trop petite: plus que MARGE_MAX lignes vides (=0) en haut ou en bas de la grille */
/*       OU non-centr�e: moins de NB_MIN_VALEURS (=1) du cot� gauche ou droite de la grille  */
/* Retour : soit le code ERREUR_TAILLE ou ERREUR_POSI si la grille est non-valide, 0 sinon.  */
int valider_grille(t_grille grille, int dimy, int dimx);

#endif

