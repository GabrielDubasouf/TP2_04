/*******************************************************************************
  MODE_GRAPHIQUE.H             (INF147: TP2, HIV 2021, Auteur: E.Th�)
	Module d'affichage pour les neurones et pour saisir une image.
	Nec�ssite l'ajout de la librairie "winBGIm.h".
*******************************************************************************/

#if (!defined(OBSTACLE))
#include "sourislib.h"

//les deux codes ASCII nec�ssaires
#define CODE_ESPACE  32
#define CODE_ESC     27

/***************************
   LES FONCTIONS
***************************/

/*******************************************************************************
// initialiser_graphique
// *****************************************************************************
// Cette fonction permet d'ouvrir le mode graphique.
*******************************************************************************/
void  initialiser_graphique(void);


/*******************************************************************************
// fermer_graphique
// *****************************************************************************
// Cette fonction permet de fermer le mode graphique.
*******************************************************************************/
void  fermer_graphique(void);


/*******************************************************************************
// effacer_ecran
// *****************************************************************************
// Cette fonction permet d'effacer la fenetre graphique.
*******************************************************************************/
void  effacer_ecran(void);


/*******************************************************************************
// pause_ecran
// *****************************************************************************
// Cette fonction permet d'effectuer une pause-�cran en mode graphique.
*******************************************************************************/
void  pause_ecran(void);


/*******************************************************************************
// delai_ecran
// *****************************************************************************
// Cette fonction permet d'effectuer un d�lai de temps en mode graphique.
// PARAMETRES (1) : 
//	     - le temps de d�lai d�sir� en millisecondes (entiers)
*******************************************************************************/
void  delai_ecran(int msec);


/*******************************************************************************
// obtenir_pixel
// *****************************************************************************
// Cette fonction permet d'obtenir la couleur du pixel � une position donn�e.
// PARAMETRES (2) : 
//	     - pos. du pixel en x et en y (2 entiers)
// RETOUR :
//       - la couleur du pixel (entier)
*******************************************************************************/
int  obtenir_pixel(int px, int py);


/*******************************************************************************
// afficher_texte, effacer_texte
// *****************************************************************************
// 2 fonctions permettant d'afficher et d'effacer du texte au centre de l'�cran.
// PARAMETRES (1) : 
//       - contenu du texte (string)
*******************************************************************************/
void  afficher_texte(const char *text);
void  effacer_texte(void);

/*******************************************************************************
// dessiner_cercle
// *****************************************************************************
// Cette fonction permet de dessiner un cercle plein (de couleur NOIR).
// PARAMETRES (2) : 
//	     - pos. du centre en x et en y (2 entiers)
*******************************************************************************/
void  dessiner_cercle(int px, int py);

/*******************************************************************************
// dessiner_rect
// *****************************************************************************
// Cette fonction permet de dessiner un rectangle plein (de couleur BLANC).
// PARAMETRES (4) : 
//	     - pos. du coin sup. gauche en x et en y (2 entiers)
//       - pos. du coin inf. droite en x et en y (2 entiers)
*******************************************************************************/
void  dessiner_rect(int x1, int y1, int x2, int y2);

/*******************************************************************************
// dessiner_forme
// *****************************************************************************
// Cette fonction permet de dessiner une forme � l'�cran avec la souris.
// On confirme le dessin avec la touche [ESPACE] et
// on peut ANNULER le dessin avec la touche [ESC].
// PARAMETRES (aucun)
// RETOUR :
//      - le caract�re utilis� pour terminer le dessin (CODE_ESPACE ou CODE_ESC)
*******************************************************************************/
char dessiner_forme(void);

/*******************************************************************************
// afficher_intensite
// *****************************************************************************
// Cette fonction permet d'afficher une intensit� lumineuse entre [0..15].
// L'intensit� sera affich� avec une teinte de gris dans carr�e de 10x10 pixels.
// 0 = plus clair (blanc), 15 = plus fonc�e (noir)
// PARAMETRES (3):
//       - la valeur de l'intensit� et la position (px, py) du carr�e de pixels.
*******************************************************************************/
void afficher_intensite(int, int px, int py);

#endif