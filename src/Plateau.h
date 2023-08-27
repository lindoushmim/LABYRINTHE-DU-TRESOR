
#ifndef _PLATEAU_H_
#define _PLATEAU_H_

#include "Piece.h"
#include <iostream>
 
using namespace std;


/** 
 * @class Plateau
 * @brief classe pour gerer l'ensemble des pieces
*/ 


class Plateau 
{

private:

    //! @brief représente les dimensions de l'ensemble des pieces, on a dimx*dimy = nombre de pieces
    int dimx,dimy;

    //! @brief pointeur sur un tableau de Piece contenant dimx*dimy Pieces
    Piece * tabPiece;

    //! @brief numéro de la salle contenant le trésor
    int salleFin;


public:

    /// @brief Constructeur par defaut 
    Plateau(); 

    /// @brief Constructeur de la classe Plateau.Constructeur de la classe Plateau. 
    /// @param x Entier représentant la dimension en x 
    /// @param y Entier représentant la dimension en y 
    /// @param dimensionPiece Dimension pour une piece
    Plateau(int x, int y, int dimensionPiece);

    /// @brief Constructeur de recopie de la classe Plateau
    /// @param pla Plateau à recopier
    Plateau(const Plateau &pla);

    /// @brief destructeur de la classe 
    ~Plateau();

    /// @brief permet d'initialiser un plateau de piece de nombre x*y
    /// @param x Entier représentant la dimension en x
    /// @param y Entier représentant la dimension en y
    void initPlateau(int x, int y);

    /// @brief Accesseur de dimx 
    /// @return La dimension en x
    int getDimx() const;

    /// @brief Accesseur de dimy
    /// @return La dimension en y
    int getDimy() const;

    /// @brief Accesseur de tabPiece
    /// @return Le tableau de pièces
    Piece * getTab() const;

    /// @brief Mutateur de dimx
    /// @param x Nouvelle valeur de dimx
    void setDimx(int x); 

    /// @brief Mutateur de dimy
    /// @param y Nouvelle valeur de dimy
    void setDimy(int y); 

    /// @brief Mutateur de tabPiece
    /// @param p Nouvelle valeur de tabPiece
    void setTab(Piece * p);

    /// @brief Mutateur d'une pièce dans tabPiece
    /// @param piece Nouvelle valeur de la pièce
    /// @param i Indice en x
    /// @param j Indice en y
    void setPiece(Piece * piece, int i, int j); 

    /// @brief Accesseur de salleFin où se trouve le trésor 
    /// @return Le numéro de la salle finale
    int getSalleFin(); // rajouter le const 

    /// @brief Mutateur de salleFin où se trouve le trésor 
    /// @param num Nouvelle valeur de salleFin
    void setSalleFin(int num);

    /// @brief Initialise une pièce sur le plateau
    /// @param dimensionPiece Dimension pour la pièce
    /// @param longueurPorte Longueur de la porte
    /// @param epaisseurPorte Épaisseur de la porte
    /// @param tailleXMonstre Taille en x du monstre
    /// @param tailleYMonstre Taille en y du monstre
    /// @param tailleJoueurX Taille en x du joueur (utile pour choisir la position des potions)
    /// @param tailleJoueurY Taille en y du joueur (utile pour choisir la position des potions)
    void initPiece(int dimensionPiece,int longueurPorte, int epaisseurPorte, int tailleXMonstre, int tailleYMonstre, int tailleJoueurX, int tailleJoueurY);


    /// @brief Accesseur pour recuperer une piece du plateau selon son indice
    /// @param numero indice de la salle dans le plateau
    /// @return une piece du plateau 
    Piece & getPiece(int numero) const ;

    /// @brief test de regression de la classe Plateau s
    void testRegressionPlateau(); 

};

#endif

