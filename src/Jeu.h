#ifndef _JEU_H_
#define _JEU_H_
#include <iostream>
#include <cmath> 
#include <chrono>

#include "Joueur.h"  
#include "Plateau.h"


/** 
 * @class Jeu
 * @brief La classe Jeu gère les différents éléments d'un jeu tels que le plateau, le joueur et les actions possibles.
*/ 


class Jeu
{
private:

    /// @brief Le plateau du jeu
    Plateau pla; 
     
    /// @brief L'indice de la pièce où se trouve actuellement le joueur 
    int pieceActuelle;

    /// @brief Le joueur du jeu 
    Joueur joueur;

    /// @brief Indique si le jeu est terminé 
    bool gameOverBool; 


public:

    /// @brief Constructeur par defaut 
    Jeu();

    /// @brief Mutateur de la valeur gameOverBool
    /// @param e La nouvelle valeur de gameOverBool
    void setGameOverBool(bool e); 

    /// @brief Accesseur de la valeur gameOverBool 
    /// @return La valeur de gameOverBool
    bool getGameOverBool() const; 

    /// @brief Obtient une référence constante à l'objet pla
    /// @return  Une référence constante à l'objet pla
    const Plateau & getPlateau() const; 

    /// @brief Obtient une référence constante à l'objet pla
    /// @return Une référence constante à l'objet pla
    const Plateau & getPlateau(); 

    /// @brief Obtient une référence à l'objet joueur
    /// @return Une référence à l'objet joueur
    Joueur & getJoueurJeu() ; 

    /// @brief Obtient une référence constante à l'objet joueur
    /// @return Une référence constante à l'objet joueur
    const Joueur & getJoueurJeu() const;


    /// @brief Obtient la valeur de l'entier pieceActuelle
    /// @return  La valeur de l'entier pieceActuelle
    int getPieceActuelle() const;

    /// @brief Mutateur de la valeur de l'entier pieceActuelle
    /// @param p La nouvelle valeur de l'entier pieceActuelle
    void setPieceActuelle(int p);

    /// @brief appel les fonctions qui effectue les actions automatiques
    /// @param dimensionPiece La dimension de la pièce
    /// @param monstre1 Un booléen indiquant si on doit faire effectuer l'action automatique du monstre 1
    /// @param monstre2 Un booléen indiquant si on doit faire effectuer l'action automatique des 3 autres monstres
    /// @param barre Un booléen indiquant si on doit faire effectuer l'action automatique de la barre
    /// @return booléen qui indique si l'action a été effectuer avec succès                                         A CHANGER
    bool actionAutomatique(int dimensionPiece, bool monstre1, bool monstre2, bool barre);

    /// @brief Effectue une action en fonction de la touche du clavier pressée
    /// @param touche La touche pressée sur le clavier
    /// @param pas L'avancement du joueur
    /// @param dimensionPiece La dimension de la pièce
    /// @return on renvoie false si l'utilisateur à appuyer sur la touche permettant de quitter le jeu, true sinon
    bool actionClavier(const char touche, int pas, int dimensionPiece);

    /// @brief Effectue le deplacent du joueur dans le jeu 
    /// @param dep Vecteur à laquelle le joueur se deplace 
    /// @param dimensionPiece Dimension de la piece 
    void deplacementJoueur(const Pos & dep, int dimensionPiece);
    

    /// @brief Iniitalise la classe Jeu pour pouvoir joueur 
    /// @param x Taille x du tableau de piece
    /// @param y Taille y du tableau de piece 
    /// @param dimensionPiece dimension de la piece 
    /// @param taillePorteX Largeur de la porte 
    /// @param taillePorteY Longueur de la porte 
    /// @param tailleJoueurX Largeur du joueur 
    /// @param tailleJoueurY Longueur du joueur 
    /// @param tailleXMonstre Largeur des monstres
    /// @param tailleYMonstre Longueur des monstres
    void initJeu(int x, int y, int dimensionPiece,int taillePorteX, int taillePorteY, int tailleJoueurX, int tailleJoueurY, int tailleXMonstre, int tailleYMonstre);

    /// @brief Permet de changer de piece en fonction de la porte entré par le joueur 
    /// @param dimensionPiece Dimension de la piece 
    void changementDePiece(int dimensionPiece);
    
    /// @brief Permet de recuperer la piece si le joueur est sortie par la porte du haut 
    void changeHaut(); 

    /// @brief Permet de recuperer la piece si le joueur est sortie par la porte de droite 
    void changeDroite();

    /// @brief Permet de recuperer la piece si le joueur est sortie par la porte du bas 
    void changeBas();

    /// @brief Permet de recuperer la piece si le joueur est sortie par la porte de gauche
    void changeGauche();

    /// @brief Permet de mettre la position d'une entité contre le mur si le pas qu'il veut faire est plus grand
    /// @param p Position d'un vecteur 
    /// @param tailleX Largeur du joueur 
    /// @param tailleY Longueur du joueur 
    /// @param indiceMur Inidice du mur de la piece 
    /// @param deplacement Vecteur à laquelle le joueur se deplace 
    /// @return la position de l'entité, rapprochée du mur
    Pos rapprochementMur(const Pos & p, int tailleX, int tailleY, int indiceMur, const Pos & deplacement);

    /// @brief Fonction intermédiaire qui choisit aléatoirement le déplacement d'un monstre
    /// @param pas taille du déplacement 
    /// @param k indice du monstre sur lequel on doit effectuer le déplacement
    Pos choixDéplacementAléatoire(int pas, int k);

    /// @brief Fonction intermédiaire qui permet de choisir le déplacement à faire pour rapprocher un monstre du joueur
    /// @param pas taille du déplacement 
    /// @param k indice du monstre sur lequel on doit effectuer le déplacement
    /// @return le déplacement à faire pour bouger le monstre
    Pos choixRapprochementJoueur(int pas,int k);

    /// @brief Fonction intermédiaire qui effectue le déplacement d'un monstre
    /// @param k indice du monstre sur lequel on doit effectuer le déplacement
    /// @param deplacement le déplacement à effectuer
    void deplacementMonstre(const Pos & deplacement, int k);

    /// @brief permet de faire les déplacements automatiques des monstres
    /// @param k indice du monstre sur lequel on doit effectuer le déplacement
    void initialisationDeplacementAutoMonstre( int k); 

    /// @brief Permet de déterminer si le joueur est entré en contact avec un monstre d'une piece
    /// @return booleen permattant de savoir si y'a eu contact ou non
    bool contactMonstreJoueur(); 

    /// @brief Permet de déterminer si le joueur est entré en contact avec une barre d'une piece
    /// @return booleen permattant de savoir si y'a eu contact ou non
    bool contactBarreJoueur(); 

    /// @brief Permet de faire bouger la barre
    void barreAuto();

    /// @brief Determine le score du jeu 
    void gestionVie(); 

    /// @brief Determine l'invincibilité du joueur 
    /// @param longtemps booleen indiquant si le joueur doit perdre de l'invincibilite 
    void gestionInvincibilite(bool longtemps);

    /// @brief Determine si le joueur est mort en fonciton de son nombre de vie 
    /// @return booleen permattant de savoir si fin du jeu 
    bool gameOver(); 

    /// @brief si le joeur n as plus de vie, ou bien qu'il a trouvé le tresor arreter le jeu 
    /// @return 1 si le joueur à perdu, 2 si le joueur à gagner, -1 si la partie n'est pas fini 
    int arretJeu(); 

    /// @brief Determine si le joueur a gagner (trouver le tresor avant de perdre toutes ses vies)
    /// @return booleen permattant de savoir si le jeu a été gagné 
    bool jeuGagner(); 

    /// @brief Permet de déterminer si le joueur est entré en contact avec le tresor d'une piece
    /// @return booleen permattant de savoir si y'a eu contact ou non
    bool contactTresorJoueur(); 

    /// @brief Permet de déterminer si le joueur est entré en contact avec une vie d'une piece
    /// @return booleen permattant de savoir si y'a eu contact ou non
    bool contactVieJoueur(); 

    /// @brief Permet de déterminer si le joueur est entré en contact avec une bombe d'une piece
    /// @return booleen permattant de savoir si y'a eu contact ou non
    bool contactBombeJoueur(); 

    /// @brief permet de determiner si un monstre entre en collision avec une autre entité du jeu 
    /// @param k l'indice du monstre dans le tableau de monstre 
    /// @param p la position de l'entité à vérifié avec si y'a eu collision 
    /// @param  tailleX la largeur de l'entité
    /// @param  tailleY la longueur de l'entité
    /// @return indique si y'a eu contact ou non 
    bool contactMonstreEntite(int k, Pos p, int tailleX, int tailleY); 

    /// @brief Permet de déterminer si le joueur est entré en contact avec une potion d'une piece
    /// @return booleen permattant de savoir si y'a eu contact ou non
    bool contactPotionJoueur(); 

    /// @brief permet de savoir quoi faire si le joueur a pris une potion en fonction de son type de potion 
    void joueurBuPotion(); 

    /// @brief permet de deplacer l'epee en fonction de la direction souhaitée 
    /// @param direction un caractere pour recuperer l info de la touche appuyé par le joueur 
    void deplacerEpee(char direction); 

    /// @brief mettre à jour le tableau de monstre en fonction de leur vies 
    void mortMonstre(); 

    /// @brief permet de deplacer l'arme en fonction de direction du joueur 
    void deplaAutoArme(); 

};

#endif