#include "grille.h"






int valider_grille(t_grille grille, int dimy, int dimx) {

	int i, j;
	int compteur=0;
	
	
	//Regarder si le dessin est assez haut.
			for (i = 0; i < MARGE_MAX; i++) {
				for (j = 0; j < dimy; j++) {
					if (grille[i][j] == 1)
						compteur++;
				}
			}
			if (compteur == 0) {
				return ERREUR_TAILLE;
			}

			compteur = 0;

	//Regarder si dessin est assez bas.
			for (i = dimx-MARGE_MAX; i < dimx ; i++) {
				for (j = 0; j < dimy; j++) {
					if (grille[i][j] == 1)
						compteur++;
				}
			}
			if (compteur == 0) {
				return ERREUR_TAILLE;
			}

			compteur = 0;

	//Regarder si dessin est assez à gauche.
			for (i = 0; i < dimx; i++) {
				for (j = 0; j < NB_MIN_VALEURS; j++) {
					if (grille[i][j] == 1)
						compteur++;
				}
			}
			if (compteur == 0) {
				return ERREUR_POSI;
			}

			compteur = 0;

	//Regarder si dessin est assez à gauche.
			for (i = 0; i < dimx; i++) {
				for (j = dimy- NB_MIN_VALEURS ; j < dimy; j++) {
					if (grille[i][j] == 1)
						compteur++;
				}
			}
			if (compteur == 0) {
				return ERREUR_POSI;
			}
	//Si dessin est valide.
			return 0;
}

void recuperer_dessin(int pos_x, int pos_y, t_grille data) {

	int compteur_noir=0; 
	int i, j, k, l;


	//Balayer les rangées de data
	for (i = 0; i < NB_VARX; i++) {
		//Balayer les colonnes de data
		for (j = 0; j < NB_VARY; j++) {
			//Balayer les position en x du carré
			for (k = 0; k < pos_x; k++) {
				//Balayer les position en y du carré
				for (l = 0; l < pos_y; l++) {
					if (obtenir_pixel(pos_x, pos_y) == BLACK) {
						compteur_noir++;
					}
				}
			}
			//Si compteur du noir est plus grand ou égal à 20%, la case du tableau data est 1.
			if (compteur_noir / (TAILLE_CASE * TAILLE_CASE) >= POURCENT_PIX) {
				data[i][j] = 1;
			}
			else {
				data[i][j] = 0;
			}
		}
	}
}


