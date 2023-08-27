#ifndef _POS_H_
#define _POS_H_

#include <iostream>
using namespace std;


/// @brief gerer des vecteurs en 2D
class Pos
{

private:

    //! @brief représente les coordonné x et y d'un vecteur position 
    int x,y; 

public:

    //! @brief Constructeur par defaut de la classe 
    Pos();

    /**
     *  @brief Constructeur qui initialise x et y par positionX et positionY 
     * @param positionX la position x du vecteur position 
     * @param positionY la position y du vecteur position 
    */ 
    Pos(int positionX, int positionY); 

    /**
     * @brief Accesseur : récupere la composante x de pox => retourne une valeur 
     * @return la composante x 
    */
    int getX() const; 

    /**
     * @brief Accesseur : récupere la composante y de pox => retourne une valeur 
     * @return la composante y
    */
    int getY() const; 

    
    /** 
     * @brief Mutateur : modifie la composante x de la position  ( ng : donnée )
     * @param nx la nouvelle composante x
    */
    void setX(int nx); 

    /**
     * @brief Mutateur : modifie la composante y de la position  ( ng : donnée )
     * @param ny la nouvelle composante y 
    */
    void setY(int ny); 

    /**
     * @brief foncton qui calcul la distance entre l'instance de la position et une autre position passée en paramètre
     * @param pos2 la deuxième position
     * @return retourne la distance entre l'instance et pos2
    */
    int distance(const Pos & pos2) const;

    /**
     * @brief fonction qui additionne deux vecteur position 
     * @param a est une objet de la classe pos 
     * @return retourne pos ajouté à pos en paramètre 
    */
    Pos addPos(const Pos &a); 

    /**
     * @brief fonction qui soustrait deux vecteur position 
     * @param a est une objet de la classe pos 
     * @return retourne pos soustrait à pos en paramètre 
    */
   Pos sousPos(const Pos &a); 

    /**
     * @brief fonction qui multiplie deux vecteur position 
     * @param a est une objet de la classe pos 
     * @return retourne pos multiplié à pos en paramètre 
    */
    Pos multPos(const Pos &a); 

    /**
     * @brief permet l'addition de deux objet de type Pos
     * @param pos1 est un objet de type Pos (situé à droite de l'opération)
     * @return retourne le resultat de l'addition de deux objet de type Pos
    */
    Pos operator+(const Pos &pos1);

    /**
     * @brief permet la soustraction de deux objet de type Pos
     * @param pos1 est un objet de type Pos (situé à droite de l'opération)
     * @return retourne le resultat de la soustraction de deux objet de type Pos
    */
    Pos operator-(const Pos &pos1);

    /**
     * @brief permet la multiplication de deux objet de type Pos
     * @param pos1 est un objet de type Pos (situé à droite de l'opération)
     * @return retourne le resultat de la multiplication de deux objet de type Pos
    */
    Pos operator*(const Pos &pos1);

    /**
     * @brief permet la multiplication entre un objet de type Pos et un float
     * @param val est un float (situé à droite de l'opération)
     * @return retourne le resultat de la multiplication l'instance de Pos et un float
    */
    Pos operator*(float val);

    /**
     * @brief permet la multiplication entre un objet de type Pos et un double
     * @param val est un double (situé à droite de l'opération)
     * @return retourne le resultat de la multiplication l'instance de Pos et un double
    */
    Pos operator*(double val);  

    /**
     * @brief permet la multiplication entre un objet de type Pos et un int
     * @param val est un int (situé à droite de l'opération)
     * @return retourne le resultat de la multiplication l'instance de Pos et un int
    */
    Pos operator*(int val); 

    /**
     * @brief permet le test d'égalité entre deux objet de type Pos
     * @param pos1 est un objet de type Pos (situé à droite de l'opération)
     * @return retourne true si les deux objets de type pos sont égals, false sinon
    */
    bool operator==(const Pos &pos1);

    //template <typename V>
    //Pos operator*(T val);

    /// @brief surcharge de l'opérateur << pour l'affichage d'une position
    /// @param os os : le flux de sortie.
    /// @param pos1  pos1 : la position à afficher
    /// @return 
    friend ostream& operator<<(ostream &os, const Pos &pos1);

    /// @brief calcule la direction d'un vecteur représenté par une position
    /// @return un objet de la classe Pos qui est une nouvelle position normalisée.
    Pos normaliser(); //permet de calculer la direction d'un vecteur

    //! @brief fonction permettant de tester les utilités de la classe Pos 
    void testRegressionPos(); 
    
};



#endif
