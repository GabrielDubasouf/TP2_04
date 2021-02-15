/*******************************************************************************
  MODE_GRAPHIQUE.CPP             (INF147: TP2, HIVER 2021, Auteur: E.Th�)
	Module d'affichage pour les neurones et pour saisir une image. 
	Nec�ssite l'ajout de la librairie "winBGIm.h".
*******************************************************************************/
#include"mode_graphique.h"
#include"winBGIm.h"
#include<math.h>

/*******************************************************************************
                            CONSTANTES PRIV�ES
*******************************************************************************/
//marges pour l'affichage de texte
#define MARGEX       50   
#define POS_AFF_Y   250

//rayon pour un gros point
#define RAYON_PT     3


/*******************************************************************************
                            FONCTIONS PUBLIQUES
*******************************************************************************/

/******************************************************************************
// initialiser_graphique
// ****************************************************************************
// Cette fonction permet d'ouvrir le mode graphique.
******************************************************************************/
void initialiser_graphique(void)
{	/* request auto detection */
	int gdriver = DETECT, gmode;

	/* initializer graphics mode */
	initgraph(&gdriver, &gmode, "");
}

/******************************************************************************
// fermer_graphique
// ****************************************************************************
// Cette fonction permet de fermer le mode graphique.
// Encapsulation de la fonction � closegraph() � du module � winBGIm.h �.
******************************************************************************/
void  fermer_graphique(void)
{ closegraph(); }

/*******************************************************************************
// effacer_ecran
// *****************************************************************************
// Cette fonction permet d'effacer la fenetre graphique.
// Encapsulation de la fonction � clearviewport() � du module � winBGIm.h �.
*******************************************************************************/
void  effacer_ecran(void)
{ clearviewport(); }

/*******************************************************************************
// pause_ecran
// *****************************************************************************
// Cette fonction permet d'effectuer une pause-�cran en mode graphique.
// Encapsulation de la fonction � getch_graph() � du module � winBGIm.h �.
*******************************************************************************/
void  pause_ecran(void)
{ //l'utilisateur doit appuyer une touche pour terminer la pause-�cran
	getch_graph();
}

/*******************************************************************************
// delai_ecran
// *****************************************************************************
// Cette fonction permet d'effectuer un d�lai de temps en mode graphique.
// Encapsulation de la fonction � delay_graph() � du module � winBGIm.h �.
// PARAMETRES (1) : 
//	     - le temps de d�lai d�sir� en millisecondes (entiers)
*******************************************************************************/
void  delai_ecran(int msec)
{ delay_graph(msec); }

/*******************************************************************************
// obtenir_pixel
// *****************************************************************************
// Cette fonction permet d'obtenir la couleur du pixel � une position donn�e.
// Encapsulation de la fonction � getpixel() � du module � winBGIm.h �.
// PARAMETRES (2) : 
//	     - pos. du pixel en x et en y (2 entiers)
// RETOUR :
//      - la couleur du pixel (entier)
*******************************************************************************/
int  obtenir_pixel(int px, int py)
{ return getpixel(px, py); }

/*******************************************************************************
// afficher_texte
// *****************************************************************************
// Cette fonction permet d'afficher du texte au bas de l'�cran.
// PARAMETRES (1) : 
//       - contenu du texte (string)
*******************************************************************************/
void  afficher_texte(const char *text)
{ int px = MARGEX,			//position en x pour l'affichage
      py = POS_AFF_Y;		//position en y pour l'affichage

  //premi�rement effacer toute la r�gion d'affichage
  effacer_texte();

  //en blanc avec police et sens par d�faut, 2 fois la taille normale
  setcolor(WHITE);
  settextstyle(0, 0, 2);
  outtextxy(px, py, text);
}

/*******************************************************************************
// effacer_texte
// *****************************************************************************
// Cette fonction permet d'effacer le texte
// PARAMETRES (aucun)
*******************************************************************************/
void  effacer_texte(void)
{
	//dessiner en rectangle en NOIR pour effacer la zone des messages
	setfillstyle(SOLID_FILL, BLACK);
	bar(MARGEX - 1, POS_AFF_Y - 1, getmaxx(), POS_AFF_Y + 20);  //hauteur-texte = 20 pix.
}

/*******************************************************************************
// dessiner_cercle
// *****************************************************************************
// Cette fonction permet de dessiner un cercle plein (de couleur NOIR).
// PARAMETRES (2) : 
//	     - pos. du centre en x et en y (2 entiers)
*******************************************************************************/
void  dessiner_cercle(int px, int py)
{ //�tablir la couleur d�sir�e
  setcolor(BLACK);
  circle(px, py, RAYON_PT);    //le contour ext�rieur

  //remplir l'int�rieur
  setfillstyle(SOLID_FILL, BLACK);
  floodfill(px, py, BLACK);
}

/*******************************************************************************
// dessiner_rect
// *****************************************************************************
// Cette fonction permet de dessiner un rectangle plein (de couleur BLANC).
// PARAMETRES (4) : 
//	     - pos. du coin sup. gauche en x et en y (2 entiers)
//       - pos. du coin inf. droite en x et en y (2 entiers)
*******************************************************************************/
void  dessiner_rect(int x1, int y1, int x2, int y2)
{ //�tablir couleur de l'int�rieur
  setfillstyle(SOLID_FILL, WHITE);
  bar(x1, y1, x2, y2);
}

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
char dessiner_forme(void) {
	int pos_x, pos_y;     //la position-souris
	char ch = 0;

	/* on s'assure que le bouton-bouton souris est �teint et on attends un clic-gauche */
	eteindre_bouton(WM_LBUTTONDOWN);
	attend_bouton_pese();

	do {
		/* boucle pour dessiner des points noirs tant que le bouton-gauche est pes� */
		while (ch != CODE_ESPACE && ch != CODE_ESC && !bouton_releve()) {
			if (souris_bouge()) {
				obtient_souris(&pos_x, &pos_y);
				dessiner_cercle(pos_x, pos_y);
			}

			//IMPORTANT: petit d�lai qui permet de d�tecter les �venements-souris!
			delay_graph(1);
		
			//�teindre le double-clic si jamais cela se produit
			eteindre_bouton(WM_LBUTTONDBLCLK);    //WM_LBUTTONDBLCLK pour un double-clic
		} 

		/* boucle d'attente jusqu'au prochain clic-souris OU une touche-clavier */
		while (!bouton_pese() && !kbhit_graph())
			delay_graph(10);

		/* si on a double-cliqu� la souris, �teindre le double-clic */
		if (double_clic_pese())
			eteindre_bouton(WM_LBUTTONDBLCLK);    //WM_LBUTTONDBLCLK pour un double-clic

		/* si une touche-clavier est d�tect�e, r�cup�rer la touche ASCII */
		if (kbhit_graph()) {
			ch = getch_graph();
			/* dans le cas d'une mauvaise touche, afficher un message d'erreur */
			if (ch != CODE_ESPACE && ch != CODE_ESC)
				afficher_texte("Mauvaise touche, cliquez sur l'ecran pour continuer..");
		}
	} while (ch != CODE_ESPACE && ch != CODE_ESC);

	return ch;
}

/*******************************************************************************
// afficher_intensite
// *****************************************************************************
// Cette fonction permet d'afficher une intensit� lumineuse entre [0..15].
// L'intensit� sera affich� avec une teinte de gris dans carr�e de 10x10 pixels.
// 0 = plus clair (blanc), 15 = plus fonc�e (noir)
// PARAMETRES (3):
//       - la valeur de l'intensit� et la position (px, py) du carr�e de pixels.
*******************************************************************************/
void afficher_intensite(int intensite, int px, int py) {
	struct palettetype pal;    //la palettes des 16 teintes de gris
	int i;

	/* obtenir une copie de la palette */
	getpalette(&pal);

	/* g�n�rer les 16 teintes de gris */
	for (i = 0; i < pal.size; i++)
		setrgbpalette(pal.colors[i], i * 16, i * 16, i * 16);

	/* on affiche la teinte de gris #intensite dans un petit carr� (10x10 pixels) */
	setfillstyle(SOLID_FILL, intensite);
	bar(px, py, px+10, py+10);           //(px, py) est le coin sup-gauche du carr�
}