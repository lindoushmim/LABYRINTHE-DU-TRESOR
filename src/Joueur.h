#ifndef _Joueur_H_
#define _Joueur_H_

#include <vector>
#include "Arme.h"
#include "Piece.h"
#include <assert.h>  
#include <iostream>

using namespace std;

/** 
 * @class Joueur
 * @brief classe pour gerer les fonctionalités du joueur 
*/




class Joueur
{
private:

    /// @brief position du joueur dans le jeu 
    Pos positionJoueur;

    /// @brief taille du joueur sur l'axe des abscise (largeur)
    int tailleX;
    
    /// @brief taille du joueur sur l'axe des oordonnée (longueur)
    int tailleY;

    /// @brief liste des armes qu'à le joueur 
    vector <Arme> tabArmes; 

    /// @brief le nombre d'arme total du joueur 
    int nbArmes; 

    /// @brief indique si le joueur a brandit l'épée ou non 
    bool branditEpee; 

    /// @brief l'épée possédé par le joueur 
    Element epee; 

    /// @brief determine la direction du joueur 
    int directionJoueur; // 0 : haut, 1 : droite, 2 : bas et 3 : gauche 


public:

    /// @brief le nombre de point de vie du joueur
    int pointDeVie;   

    /// @brief le temps d'invincibilité restant au joueur (en secondes) 
    int invincibilite;

    //! @brief Constructeur par defaut de la classe Joueur
    Joueur();

    /// @brief constructeur de la classe image
    /// @param x position x du joueur 
    /// @param y position y du joueur 
    /// @param h largeur du joueur 
    /// @param l longueur du joueur 
    Joueur(int x, int y, int h, int l); 

    /// @brief Accesseur  qui recupere la position du joueur 
    /// @return la position du joueur 
    Pos getPositionJoueur() const;

    /// @brief Mutateur qui modifie la position du joueur 
    /// @param p nouvelle position du joueur 
    void setPositionJoueur(Pos p);

    /// @brief Accesseur pour la direction du joueur 
    /// @return direction du joueur 
    int getDirectionJoueur() const; 

    /// @brief Mutateur pour changer la direction du joueur
    /// @param dir nouvelle direction du joueur 
    void setDirectionJoueur(int dir); 

    /// @brief Accesseur pour recuperer l'information si le joueur a brandit ou non l'épee 
    /// @return booleen pour savoir si l'épée est brandit ou non 
    bool getBranditEpee() const; 

    /// @brief Mutateur pour changer l'information si le joueur brandit l'épée ou bien la range 
    /// @param e nouveau etat de l'épée 
    void setBranditEpee(bool e); 

    /// @brief Acesseur pour recuperer les données de la structure Element represéntant une épée 
    /// @return un objet de la structure element (representant une épée)
    Element getEpee() const; 

    /// @brief Mutateur pour changer les données de la structure de l'objet épée 
    /// @param x nouvelle position x de l'épée 
    /// @param y nouvelle position y de l'épée 
    /// @param l nouvelle largeur de l'épée 
    /// @param h nouvelle longueur de l'épée 
    void setEpee(int x, int y, int l, int h); 

    /// @brief Accesseur pour récuperer la largeur du joueur 
    /// @return la largeur du joueur 
    int getTailleX() const;

    /// @brief Accesseur pour récuperer la longueur du joueur 
    /// @return la longueur du joueur 
    int getTailleY() const;

    /// @brief Mutateur pour changer la largeur du joueur 
    /// @param x nouvelle largeur du joueur 
    void setTailleX(int x);

    /// @brief Mutateur pour changer la longueur du joueur 
    /// @param y nouvelle longueur du joueur 
    void setTailleY(int y);

    /// @brief permet de déterminer si le joueur est invincible ou non 
    /// @return si le joueur est invincible 
    bool estInvincible();

    /// @brief Accesseur pour la variable nbArme
    /// @return nombre d'armes que le joueur peut porter
    int getNbArme () const; 

    /// @brief Mutateur pour la variable nbArme
    /// @param nb nb nouveau nombre d'armes que le joueur peut porter
    void setNbArme (int nb); 

    /// @brief Accesseur pour obtenir le tableau d'armes
    /// @return référence non constante pour pouvoir récupérer l'original et non une copie et aussi pour pouvoir le modifier
    vector<Arme> & getTabArme(); // reference non constante pour pouvoir recuperer l original et non une copie et aussi pour pouvoir le modifier 

    /// @brief Mutateur pour une arme dans le tableau d'armes du joueur
    /// @param indice indice de l'arme à récupérer
    /// @return l'arme demandée en reference non constante pour pouvoir la modifier si besoin 
    Arme & getArme(int indice); // recupere une arme 

    /// @brief Modifie une arme du tableau d'armes du joueur
    /// @param indice indice de l'arme à modifier
    /// @param armeAjout nouvelle arme à ajouter à la place de l'arme précédente
    void setArme(int indice, Arme armeAjout); 

    /// @brief Initialise le tableau d'armes
    void initTabArme(); 

    /// @brief Ajoute une arme au tableau d'armes du joueur
    /// @param arme arme à ajouter
    void ajouterArme(const Arme & arme);  

    /// @brief Supprime une arme du tableau d'armes du joueur
    /// @param indice indice de l'arme à supprimer
    void supprimerArme(int indice); 

    /// @brief Méthode de test de regression pour la classe Joueur
    void testRegressionJoueur(); 

};

#endif 
