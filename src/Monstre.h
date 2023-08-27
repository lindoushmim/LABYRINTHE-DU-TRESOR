#ifndef _Monstre_H_
#define _Monstre_H_
#include "Pos.h"
//#include "Piece.h"


/** 
 * @class Monstre
 * @brief classe pour gerer les monstres du jeu
*/ 

class Monstre
{

private: 

    //! @brief représente la position d'un monstre
    Pos posMonstre;  

    /// @brief vitesse d'un monstre 
    Pos vitesseMonstre; 

    /// @brief largeur d'un monstre 
    int tailleXMonstre; 

    /// @brief longueur d'un monstre
    int tailleYMonstre; 
 
    /// @brief direction d'un monstre 
    int direction; 

    bool vieMonstre; 

public:
    /// @brief Constructeur par defaut de la classe
    Monstre(); 

    /**
     * @brief constructeur qui initialise la position avec px,py  et la vitesse avec vx,vy
     * @param px donnee x de posMonstre
     * @param py donnee y de posMonstre
     * @param vx donnee x de vitesseMonstre
     * @param vy donnee y de vitesseMonstre
     * @param l largueur d'un monstre
     * @param h longueur d'un monstre
    */
    Monstre(int px, int py, int vx, int vy,  int l, int h);

    /// @brief Acesseur pour savoir si le monstre est en vie ou pas 
    /// @return l'état de vie du monstre
    bool getVieMonstre() const; 

    /// @brief Mutateur pour changer l'état de vie du monstre
    /// @param e nouvelle état de vie du monstre 
    void setVieMonstre(bool e); 

    /// @brief accesseur pour la posiiton du monstre
    /// @return position du monstre 
    int getDirectionMonstre() const; 

    /// @brief mutatateur pour la direction du monstre 
    /// @param dir nouvelle direction du monstre
    void setDirectionMonstre(int dir); 

    /**
    * @brief accesseur : recupere la donnee membre posMonstre
    * @return la donnee membre posMonstre
    */
    Pos getPositionMonstre() const; 

    /// @brief mutateur pour la position du monstre
    /// @param x nouvelle coordonnée x pour monstre
    /// @param y nouvelle coordonnée y pour monstre 
    void setPositionMonstre(int x, int y); 

    /// @brief mutateur pour la position du monstre
    /// @param p nouvelle position du monstre 
    void setPositionMonstre(Pos p); 

    /**
    * @brief accesseur : recupere la donnee membre vitesseMonstre
    * @return la donnee membre vitesseMonstre
    */
    Pos getVitesseMonstre() const; 

    /// @brief accesseur pour la largeur du monstre 
    /// @return largeur du monstre 
    int getTailleXMonstre() const;

    /// @brief accesseur pour la longueur du monstre 
    /// @return longueur du monstre
    int getTailleYMonstre() const;

    /// @brief mutateur pour la largeur du monstre
    /// @param x nouvelle coordonnée x du monstre 
    void setTailleXMonstre(int x);

    /// @brief mutateur pour la longueur du monstre 
    /// @param y nouvelle coordonné y du monstre 
    void setTailleYMonstre(int y);

    /**
    * @brief test regression pour les fonctionnalités de la classe monstre 
    */
    void testRegressionMonstre(); 

};



#endif 
