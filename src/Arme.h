#ifndef _ARME_H_
#define _ARME_H_

#include "Pos.h"
#include "math.h"
#include <assert.h> 

const int G = 10;
const int dt = 1;


/** 
 * @class Arme
 * @brief classe pour gerer les fonctionalités des armes 
*/
class Arme 
{

private:

    /// @brief represente un point : il s'agit de la position d'une arme 
    Pos positionArme; 

    /// @brief represente un point : vitesse pour l'arme 
    Pos  vitesseArme; 

    /// @brief vecteur Force 
    Pos forceArme; 

    /// @brief largeur de l'arme 
    int tailleXArme; 

    /// @brief longeueur de l'arme 
    int tailleYArme; 

    /// @brief entier masse de l'arme 
    int masseArme; 

    /// @brief booleen pour detecter quand le joueur lance l'arme 
    bool joueurALancerArme; 

    /// @brief la direction à laquelle le joueur peut lancer l'arme 
    int directionArme;  
    

public:

    /// @brief constructeur par défaut de la classe arme
    Arme(); 
    
    /// @brief constructeur de la classe arme
    /// @param p position de l'arme 
    /// @param v vitesse de l'arme 
    /// @param f vecteur Force de l'arme
    /// @param m masse du rayon 
    /// @param x taille en X de l'arme
    /// @param y taille en Y de l'arme
    /// @param e booleen pour lancer l'arme 
    Arme (Pos p, Pos v, Pos f, int m, int x, int y, bool e); 

    /// @brief Accesseur pour récuperer la position de l'arme  
    /// @return la position du joueur 
    Pos getPositionArme() const; 

    /// @brief Mutatateur pour changer la position de l'arme 
    /// @param p nouvelle position de l'arme 
    void setPositionArme(Pos p); 

    /// @brief Accesseur pour récuperer la vitesse de l'arme 
    /// @return la vitesse de l'arme 
    Pos getVitesseArme() const; 

    /// @brief Mutateur pour changer la vitesse de l'arme 
    /// @param v nouvelle vitesse de l'arme 
    void setVitesseArme(Pos v);

    /// @brief Accesseur pour récuperer la force de l'arme 
    /// @return la force de l arme 
    Pos getForceArme() const; 

    /// @brief Mutateur pour changer la foce de l'arme 
    /// @param f nouvelle force de l'arme 
    void setForceArme(Pos f); 

    /// @brief Accesseur pour récuperer la largeur de l'arme 
    /// @return la largeur de l'arme 
    int getTailleXArme() const; 

    /// @brief Mutateur pour changer la largeur de l'arme 
    /// @param x nouvelle largeur de l'arme 
    void setTailleXArme(int x); 

    /// @brief Accesseur pour récuperer la longueur de l'arme 
    /// @return la longueur de l'arme 
    int getTailleYArme () const; 

    /// @brief Mutateur pour changer la longeuer de l'arme 
    /// @param y nouvelle longueur de l'arme 
    void setTailleYArme(int y); 

    /// @brief Accesseur pour savoir si le joueur a lancé l'arme 
    /// @return le booleen si le joueur a lancé l'arme 
    bool getJoueurLancerArme() const; 

    /// @brief Mutateur pour changer la valeur du booleen pour savoir si le joueur a lancé l'arme 
    /// @param e nouvelle état de l'arme, si jeté ou non 
    void setJoueurLancerArme(bool e); 

    /// @brief Accesseur pour recupérer la direction du mouvement de l'arme 
    /// @return la direction du mouvement de l'arme 
    int getDirectionArme() const; 

    /// @brief Mutatateur pour modifier la direction de l'arme 
    /// @param dir nouvelle direction de l'arme 
    void setDirectionArme(int dir); 

    /// @brief Accesseur pour recuperer la masse de l'arme 
    /// @return la masse de l'arme 
    int getMasseArme() const; 

    /// @brief Mutateur pour modifier la masse de l'arme 
    /// @param m nouvelle masse de l'arme 
    void setMasseArme(int m); 

    /// @brief rajoute une force à la force d'une arme 
    /// @param F un vecteur force 
    void addForce(const Pos & F); 

    /// @brief permet de mettre en mouvement l'arme  
    void mvtArme(); 

    /// @brief detecte la collision entre l'arme et les cotés de la piece 
    /// @param dimension dimension de la piece 
    /// @param tailleXmurs largeur du mur
    /// @param tailleYmurs longeueur du mur
    /// @return un boolen indiquant s'il y'a collision entre les murs et l'obstacle 
    bool collisionArmeMurs(int dimension, int tailleXmurs, int tailleYmurs) const; 
 
    /// @brief permet de détecter la collision entre l'arme et une entité du jeu 
    /// @param p position de l'entité de jeu 
    /// @param tailleX largeur de l'entité du jeu 
    /// @param tailleY longeur de l'entité du jeu 
    /// @return 
    bool collisionArmeEntite(const Pos & p, int tailleX, int tailleY) const; 

    /// @brief permet de lancer l'arme dans la direction souhaité par le joueur 
    /// @param direction direction de l'arme 
    void lancerDirectionArme(int direction); 

    /// @brief fonction permettant de tester les utilités de la classe Obstacle 
    void testRegressionArme(); 

};



#endif