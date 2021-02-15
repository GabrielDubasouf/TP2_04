// TP2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "grille.h"
#include "mode_graphique.h"
#include "neurones.h"
#include "SOURISLIB.h"
#include "winBGIm.h"


void main_grille(int pos_x, int pos_y, t_grille saisie_ecran);

int main()
{
	int pos_x;
	int pos_y;
	t_grille saisie_ecran;

	initialiser_graphique();

	afficher_texte("Ecrire un chiffre, peser [ESPACE] pour confirmer ou [ESC] pour annuler.");

	main_grille(pos_x, pos_y, saisie_ecran);

	fermer_graphique();

	//DEMANDER PROF --> afficer valeurs de la grille en format matrice, for?

}

//Premier test de main de la grille
void main_grille(int pos_x, int pos_y, t_grille saisie_ecran) {

	int valide = FALSE;
	int touche;
	int conforme;

	do {
		dessiner_rect(0, 0, 10 * NB_VARX, 10 * NB_VARY);			//DEMANDER PROF POSI INIT.

		touche = dessiner_forme();

		effacer_texte();

		if (touche == CODE_ESC) {
			afficher_texte("Appuyer une touche pour recommencer.");	//DEMANDER PROF FONVTIONNEMENT
			pause_ecran();

			valide = FALSE;
		}
		else if (touche == CODE_ESPACE) {
			recuperer_dessin(pos_x, pos_y, saisie_ecran);			//DEMANDER PROF GRILLE
			conforme = valider_grille(saisie_ecran,NB_VARY * 10,NB_VARX * 10 );
			if (conforme == ERREUR_TAILLE) {
				afficher_texte("Image trop petite.");
			}
			else if (conforme == ERREUR_POSI) {
				afficher_texte("Image pas centre");
			}
			else if (conforme == 0) {
				valide = TRUE;
			}
		}
	} while (valide == FALSE);
}