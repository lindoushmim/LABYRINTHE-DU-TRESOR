#ifndef _Porte_H_
#define _Porte_H_

#include "Pos.h"
#include <iostream>
#include <cassert>


/** 
 * @class Porte
 * @brief classe pour gerer les fonctionalités des Portes 
*/
class Porte
{

private:

    /// @brief Indique si la porte existe ou non
    bool existe;

    /// @brief Position de la porte
    Pos posPorte; 

    /// @brief Dimension de la porte 
    int tailleX,tailleY;

public:
    
    /// @brief Constructeur par défaut de la classe Porte.
    Porte();

    /// @brief Destructeur de la classe Porte.
    ~Porte();

    /// @brief Accesseur de l'attribut existe.
    /// @return la valeur booléenne de l'attribut existe.
    bool getExiste() const;

    /// @brief Accesseur de l'attribut posPorte.
    /// @return un objet de la classe Pos correspondant à la position de la porte.
    Pos getPosPorte() const;

    /// @brief Accesseur de l'attribut tailleX.
    /// @return un entier correspondant à la taille en x de la porte.
    int getTailleX() const;

    /// @brief Accesseur de l'attribut tailleY.
    /// @return un entier correspondant à la taille en y de la porte.
    int getTailleY() const;

    /// @brief Mutateur de l'attribut existe.
    /// @param e un booléen indiquant si la porte existe ou non.
    void setExiste(bool e);

    /// @brief Mutateur de l'attribut posPorte.
    /// @param p un objet de la classe Pos correspondant à la nouvelle position de la porte.
    void setPosPorte(Pos p);

    /// @brief Mutateur de l'attribut tailleX.
    /// @param x un entier correspondant à la nouvelle taille en x de la porte.
    void setTailleX(int x);

    /// @brief Mutateur de l'attribut tailleY.
    /// @param y un entier correspondant à la nouvelle taille en y de la porte.
    void setTailleY(int y);

    /// @brief fonction permettant de tester les utilités de la classe Porte
    void testRegressionPorte(); 


};      


#endif 