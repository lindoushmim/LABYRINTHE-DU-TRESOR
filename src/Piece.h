
#ifndef _Piece_H_
#define _Piece_H_

#include "Porte.h"
#include "Obstacle.h"
#include "Mur.h"
#include "Monstre.h"
#include <iostream>
#include <string>


/// @brief Enumération des types de pièces disponibles.
enum TypePiece 
{
    TYPE_1 = 1,
    TYPE_2 = 2,
    TYPE_3 = 3,
    TYPE_4 = 4
}; 

/// @brief Enumétation des types de potion de la pièce 
enum TypePotion // pour ne pas recreer une autre structuer 
{
    GRANDIR = 1,
    RETRECIR = 2,
    GAGNER_INVICIBILITE = 3, 
};

/// @brief Structure représentant un élément
struct Element
{
    /// @brief la position x d'un élément   
    int xElement; 

    /// @brief la position y d'un élément  
    int yElement;

    /// @brief la largeur d'un élément  
    int tailleXElement;

    /// @brief la longueur d'un élément  
    int tailleYElement; 
}; 


/// @brief Classe représentant une pièce
class Piece
{

private:

    /// @brief Dimensions de la pièce
    int dimxP, dimyP; 

    /// @brief Type de la pièce 
    TypePiece type;

    /// @brief type de potion de la piece 
    TypePotion potionType; 

    /// @brief Structure représentant un objet pour la partie potion 
    struct Objet // pour la potion 
    {
        int xObjet;
        int yObjet;
        int tailleXObjet;
        int tailleYObjet; 
    }objet;

    /// @brief tableau des portes de la pièce
    Porte tabPorte[4];

    /// @brief nombre de monstres dans la pièce
    int nbMonstre; 

    /// @brief tableau des monstres de la pièce 
    Monstre tabMonstre[4]; 

    /// @brief tableau des murs de la pièce
    Mur tabMur[10];  

    /// @brief  nombre de murs dans la pièce 
    int nbMur;       

    /// @brief barre de la piece
    Obstacle barre;  

    /// @brief indique si la pièce contient une vie ou non 
    bool contientVie; 

    /// @brief objet de la structure element représentant "la vie" contenue dans la pièce 
    Element vieContient; 

    /// @brief Indique si le joueur a pris la vie contenue dans la pièce ou non
    bool aPrisVie; 

    /// @brief objet de la structure element representant une bombe contenue dans la piece 
    Element bombe; 

    /// @brief indique si la piece contient une bombe ou non 
    bool contientBombe; 

    /// @brief coordonnées et tailles du trésor
    int xTresor, yTresor, tailleXTresor, tailleYTresor;


    /// @brief objet de la structure element representant une potion contenue dans la piece
    Element potion;

    /// @brief booleen indiquand si la piece contient une postion
    bool contientPotion;  


public:

    /// @brief constructeur par defaut de la classe piece 
    Piece(); 

    /// @brief constructeur pour initialiser la piece
    /// @param dimensionXP dimension de la largeur de la piece
    /// @param dimensionYP dimension de la longueur de la piece
    /// @param P le type de la piece
    /// @param Po le type de potion
    Piece(int dimensionXP, int dimensionYP, TypePiece P, TypePotion Po); 

    /// @brief destructeur de la piece 
    ~Piece(); 

    /// @brief recuperer les info de la structure Objet pour la partie concerant l'enigme
    /// @return retourne un objet de la structure Objet 
    Objet getObjet() const; 

    /// @brief permet d initaliser les champs de la structure Objet 
    /// @param x coordonnée x
    /// @param y coordonée y
    /// @param l largeur
    /// @param h hauteur
    void setObjet(int x, int y, int l, int h); 

    /// @brief permet de recuperer un objet de la structure Element 
    /// @return un objet de la structure element 
    Element & getElement(); 

    /// @brief permet d'initialiser les champs de la structure Element
    /// @param x coordonné x 
    /// @param y coordonné y 
    /// @param l largeur
    /// @param h hauteur 
    void setElement(int x, int y, int l, int h); 

    /// @brief permet de recuperer un objet de la structure Element pour la bombe
    /// @return un objet de la structure element 
    Element & getBombe(); 

    /// @brief permet d'initialiser les champs de la structure Element pour la bombe 
    /// @param x coordonné x 
    /// @param y coordonné y 
    /// @param l largeur 
    /// @param h hauteur 
    void setBombe(int x, int y, int l, int h); 


    /// @brief permet de recuperer un objet de la structure Element pour la potion
    /// @return un objet de la structure element 
    Element & getPotion(); 

    /// @brief permet d'initialiser les champs de la structure Element pour la potion 
    /// @param x coordonné x 
    /// @param y coordonné y 
    /// @param l largeur 
    /// @param h hauteur 
    void setPotion(int x, int y, int l, int h); 

    /// @brief fonction permettant de modifier le booleen indiquant si la piece possede une bombe
    /// @param e booleen 
    void setContientBombe(bool e); 

    /// @brief recupere l info stocké dans le booleen 
    /// @return un booleen indiquant si la piece contient une bombe
    bool & getContientBombe(); 

    /// @brief fonction permettant de modifier le booleen indiquant si la piece possede une vie en plus 
    /// @param e booleen 
    void setContientVie(bool e); 

    /// @brief recupere l info stocké dans le booleen 
    /// @return un booleen indiquant si la piece contient une vie en plus 
    bool & getContientVie(); 

    /// @brief change le booleen concernant le fait que si le joueur a pris la vie 
    /// @param e booleen 
    void setAPrisVie(bool e); 

    /// @brief recupere l info concerant le fait que si le joueur a pris la vie 
    /// @return un booleen dont le membre privé aPrisVie
    bool & getAPrisVie(); 

    /// @brief change le booleen concernant le fait que la piece contient une potion
    /// @param e booleen 
    void setContientPotion(bool e); 

    /// @brief recupere l info concerant le fait que si la piece contient une potion 
    /// @return un booleen dont le membre privé aPrisVie
    bool & getContientPotion(); 

    /// @brief recupere la largeur de la piece 
    /// @return un entier dont dimX
    int getDimXP() const; 

    /// @brief recupere la longueur dimY
    /// @return un entier dont dimY
    int getDimYP() const; 

    /// @brief recupere le nombre de monstre 
    /// @return un entier dont NbMonstre
    int getNbMonstre() const; 

    /// @brief modifie la donnée membre du nombre de monstre 
    /// @param nb un entier 
    void setNbMonstre(int nb); 

    /// @brief recupere le type de la piece
    /// @return un type 
    TypePiece getType() const; 

    /// @brief recupere le type de la potion
    /// @return un type 
    TypePotion getTypePotion() const; 

    /// @brief recupere une porte selon son indice 
    /// @param num entier 
    /// @return un objet de la classe Porte
    Porte& getPorte(int num);
    
    /// @brief recupere une porte selon son indice 
    /// @param num entier 
    /// @return un objet de la classe Porte
    Porte getPorte(int num) const;

    /// @brief recupere un mur selon son indice
    /// @param indice entier 
    /// @return un objet de la classe Mur
    Mur& getMur(int indice);

    /// @brief recupere le nombre de murs 
    /// @return un entier 
    int getNbMur() const;

    /// @brief change le nombre de murs 
    /// @param nb un entier
    void setNbMur(int nb);

    /// @brief renvoie la coordonnée X du trésor
    /// @return un entier 
    int getXTresor() const; 

    /// @brief renvoie la coordonnée Y du trésor
    /// @return un entier 
    int getYTresor() const; 

    /// @brief renvoie la taille X du trésor
    /// @return un entier 
    int getTailleXTresor() const; 

    /// @brief renvoie la taille Y du trésor
    /// @return un entier
    int getTailleYtresor() const; 

    /// @brief modifie la coordonnée x du trésor
    /// @param x la coordonnée x du trésor
    void setXTresor(int x); 

    /// @brief modifie la coordonnée y du trésor
    /// @param y la coordonnée y du trésor
    void setYTresor(int y); 

    /// @brief modifie la taille x du trésor
    /// @param tailleX la taille x du trésor
    void setTailleXTresor(int tailleX); 

    /// @brief modifie la taille y du trésor
    /// @param tailleY la taille y du trésor
    void setTailleYTresor(int tailleY);
    
    /// @brief recupere un monstre contenu dans le tableau de monstre selon l'indice 
    /// @param indice entier
    /// @return un objet de la classe Monstre 
    Monstre& getMonstre(int indice); 

    /// @brief permet d'ajouter un monstre à la piece 
    /// @param monstre objet de la classe Monstre 
    void ajouterMonstre(Monstre& monstre); 

    /// @brief permet de recupere la barre dans une piece  // normalement à supp
    /// @return un objet de la classe Obstacle 
    Obstacle& getObstacle();

    /// @brief verifie si la position d'un point est dans les dimension de la piece
    /// @param x entier coordonnée x du point à verifier 
    /// @param y entier coordonnée y du point à vérifier
    /// @return un boolen 
    bool estPositionValidePiece(const int x, const int y) const; 

    /// @brief verifie si la position d'un point est dans la dimension de la piece 
    /// @param p objet de la classe Pos 
    /// @return un booleen 
    bool estPositionValidePiecePos(const Pos & p) const ;

    /// @brief fonction intermédiaire qui met des vie supplémentaire et des bombes dans une piece
    /// @param epaisseurPorte l'epaisseur d'une porte
    /// @param tailleJoueurX la taille en X du joueur
    /// @param tailleJoueurY la taille en Y du joueur
    void initVieEtBombeEtPotion(int epaisseurPorte, int tailleJoueurX, int tailleJoueurY);

    /// @brief initialise les données de la piece conformement à son type 
    /// @param nb le nombre de monstre d'une piece
    /// @param tailleXMonstre la taille en X d'un monstre
    /// @param tailleYMonstre la taille en Y d'un monstre
    /// @param epaisseurPorte l'epaisseur d'une porte
    /// @param tailleJoueurX la taille en X du joueur
    /// @param tailleJoueurY la taille en Y du joueur
    void constructionType(int nb, int tailleXMonstre, int tailleYMonstre, int epaisseurPorte, int tailleJoueurX, int tailleJoueurY); 

    /// @brief verifie si une entité est dans un mur
    /// @param p la position de l'entité à vérifier
    /// @param tailleX la taille en X de l'entité
    /// @param tailleY la taille en Y de l'entité
    /// @return -1 si l'entité n'est pas dans un mur, l'indice du mur dans lequel est l'entité sinon
    int collisionsMurs(Pos p, int tailleX, int tailleY);

    /// @brief verifie si une entité est dans une porte
    /// @param p la position de l'entité à vérifier
    /// @param tailleX la taille en X de l'entité
    /// @param tailleY la taille en Y de l'entité
    /// @return -1 si l'entité n'est pas dans une porte, l'indice de la porte dans lequel est l'entité sinon
    int collisionsPortes(Pos p, int tailleX, int tailleY) ;

    /// @brief supprimer un monstre une fois qu'il a été tué 
    /// @param indice l'indice du monstre dans le tableau 
    void supprimerUnMonstre(int indice); 

    /// @brief test de regression de la classe Piece 
    void testRegressionPiece(); 

};

#endif 
