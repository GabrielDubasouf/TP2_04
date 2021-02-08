/********************************************************************/
/* Par       : Eric Thé       								        */
/* Fichier   : SOURISLIB.H  (fichier donné aux élèves)           	*/
/*															   		*/
/* Ce module implante des fonctions de gestion de souris de base.   */
/* Utilise des commandes de la librairie standard <winuser.h>.		*/
/********************************************************************/
#include "winbgim.h"  //contient les fonctions de souris

/* Toutes les positions-écrans utilisées ici sont absolues, donc on */
/* ne tiens pas compte de l'existence d'un "viewport" d'affichage : */
/*  = avec (0, 0) au coin sup. gauche de l'écran  */

/* Permet de positionner la souris a la position-écran (x, y). */
void  positionne_souris(int x, int y);

/* Permet d'obtenir la position absolue* actuelle (x, y) de la souris. */
void  obtient_souris(int *x, int *y);

/* Permet d'obtenir la coordonnée absolue* "x" de la position actuelle */ 
int  sourisX(void);

/* Permet d'obtenir la coordonnée absolue* "y" de la position actuelle */
int  sourisY(void);

/* Permet de désactiver un des boutons-souris */
void eteindre_bouton(int code_bouton);

/* Permet de savoir si le bouton de gauche de la souris à été pesé */
int  bouton_pese(void);

/* Permet de savoir si le bouton de gauche à été cliqué deux fois */
int  double_clic_pese(void);

/* Permet de savoir si le bouton de gauche de la souris à été relaché */
int  bouton_releve(void);

/* Permet de savoir si le bouton de gauche de la souris à été relaché */
int  souris_bouge(void);

/* Cette fonction va attendre que le bouton gauche soit pesé */
void attend_bouton_pese(void);

/* Cette fonction va attendre que le bouton gauche soit relevé */
void attend_bouton_releve(void);

/* Fonction qui test si la position actuelle de la souris est dans 
   les limites données par (x1, y1) (x2, y2) */
int test_region_souris(int x1, int y1, int x2, int y2);

//-------------------------------------------------------------------
//-------------------------------------------------------------------












