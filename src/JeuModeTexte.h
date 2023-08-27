#ifndef _JEUMODETEXTE_H_ 
#define _JEUMODETEXTE_H_ 

#include "Jeu.h"

/// @brief Affichage du jeu sous forme textuelle dans une fenêtre win
/// @param win fenetre où afficher le jeu 
/// @param j jeu à afficher 
/// @param dimensionPiece dimension de la piece du jeu 
void txtAffiche(WinTXT & win, const Jeu & j, int dimensionPiece); 


/// @brief lance la boucle du jeu en mode texte 
/// @param j jeu à afficher 
/// @param dimensionPiece dimension de la piece du jeu
void txtBoucle (Jeu & j, int dimensionPiece);

#endif   