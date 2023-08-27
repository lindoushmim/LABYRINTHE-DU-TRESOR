#ifndef _Mur_H_
#define _Mur_H_


#include "Pos.h"
#include <iostream>
#include <cassert>

/// @brief Classe représentant un mur dans un jeu
class Mur
{

private: 

    /// @brief  position du mur
    Pos posMur;

    /// @brief dimension du mur 
    int tailleX,tailleY;

public:
    
    /// @brief constructeur par défaut de la classe Mur
    Mur();

    /// @brief accesseur pour la position du mur
    /// @return position du mur
    Pos getPosMur() const;

    /// @brief accesseur pour la largeur du mur
    /// @return largeur du mur
    int getTailleX() const;

    /// @brief accesseur pour la longueur du mur
    /// @return longueur du mur
    int getTailleY() const;

    /// @brief mutateur pour la position du mur 
    /// @param o nouvelle position du mur
    void setPosMur(Pos o);

    /// @brief mutateur pour la largeur du mur
    /// @param x nouvelle largeur du mur
    void setTailleX(int x);
    
    /// @brief mutateur pour la longueur du mur
    /// @param y nouvelle longueur du mur
    void setTailleY(int y);

    /// @brief initialise un mur avec une position et une taille donnée
    /// @param px  position x du mur
    /// @param py  position y du mur
    /// @param x taille largeur du mur
    /// @param y taille longueur du mur
    void initMur(int px, int py, int x, int y);

    /// @brief permet de tester les fonctionnalité de la classe mur 
    void testRegressionMur(); 
};

#endif