#ifndef _JEUMODEGRAPHIQUE_H_ 
#define _JEUMODEGRAPHIQUE_H_ 

#include "Image.h"
#include "Jeu.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h> 
#include <SDL2/SDL_mixer.h>  

/**

    @class SDLSimple
    @brief Classe gérant l'affichage du jeu avec SDL.
            La classe SDLSimple permet d'afficher le jeu de manière graphique à l'aide de la bibliothèque SDL.
            Elle utilise plusieurs images pour représenter les différents éléments du jeu.
            Elle gère également le son et l'affichage du texte.
*/

class SDLSimple 
{

private :

	/// @brief reference vers le jeu à afficher 
	Jeu & jeu;

    /// @brief Fenêtre SDL dans laquelle le jeu est affiché
    SDL_Window * window;

    /// @brief Rendu SDL pour dessiner les images
    SDL_Renderer * renderer;

    // sert à afficher du texte 
    /// @brief Police de caractères pour le texte 
    TTF_Font * font;

    /// @brief pour le texte 
    Image font_im;

    /// @brief couleur du texte 
    SDL_Color font_color;
    
    // pour le son

    /// @brief Indique si le son est activé
    bool withSound;

    /// @brief Tableau des sons
    Mix_Chunk *sounds[7];

    /** Images pour représenter le joueur */
    Image imJoueurDroite; 
    Image imJoueurGauche; 
    Image imJoueurHaut; 
    Image imJoueurBas; 
    Image * imJoueurActuel; 

    /** Images pour représenter l'épée */
    Image imEpeeHaut; 
    Image imEpeeBas; 
    Image imEpeeDroite; 
    Image imEpeeGauche; 
    Image imEpee; 

    /** Image pour représenter l'arme */
    Image imArmeDroite; 
    Image imArmeGauche; 
    Image imArmeHaut; 
    Image imArmeBas; 

    /** Images pour représenter les pièces */
    Image imPiece1;
    Image imPiece2;
    Image imPiece3;
    Image imPieceDef;
    Image imMonstre; 

    /** Images pour représenter le trésor */
    Image imTresorfermer; 
    Image imTresorOuvert; 
    Image imTresorDecouvert; 

    /** Images pour représenter les autres entités du jeu */
    Image imCoeur; 
    Image imBombe; 
    Image imBombeAllumer; 
    Image imPotion; 


public : 

    /// @brief Constructeur de la classe SDLSimple
    /// @param j Référence vers le jeu à afficher
    SDLSimple (Jeu & j);

    /// @brief Destructeur de la classe SDLSimple
    ~SDLSimple ();

    // pour la partie affichage 

    /// @brief Affiche le personnage du joueur
    void afficherPerso(); 

    /// @brief Affiche la porte
    void affichePorte(); 

    /// @brief Affiche la barre de vie, de bombe, de potion et l'arme
    void afficherVieEtBombeEtPotionEtArme(); 

    /// @brief Affiche les pièces
    /// @param dim dimension de la fenetre
    void affichePiece(int dim); 

    /// @brief Affiche l'écran de jeu gagné
    /// @param dim dimension de la fenetre
    void afficherGagner(int dim); 

    /// @brief Affiche le menu
    /// @param dim dimension de la fenetre
    void afficherMenu(int dim); 

    /// @brief Dessine le menu
    /// @param choix Le choix de l'utilisateur
    /// @param dim dimension de la fenetre
    void dessinerMenu(int choix, int dim); 

    /// @brief Affiche l'introduction
    void afficherDebut(int dim);

    /// @brief Affiche le nombre de vie et d'arme restantes
    void afficherVie(); 

    /// @brief regroupe toutes les choses à afficher 
    /// @param dim dimension de la fenetre
    void sdlAff (int dim);

    /// @brief gere le son du jeu 
    void son();

    // pour traiter les actions du jeu 

    /// @brief fait l'écran de fin si le jeu est perdu
    /// @param dim dimension de la fenetre
    void gameOvera(int dim); 

    /// @brief Met à jour l'affichage en fonction de l'état du jeu
    /// @param dimension dimension de la grille du jeu
    /// @param gestionInvincible gere l'invincibilité du jeu 
    /// @param monstre0 gere le premier monstre 
    /// @param monstre1 gere les autre monste 
    /// @param barreAuto gere la barre qui tourne 
    void update(int dimension, bool gestionInvincible, bool monstre0, bool monstre1, bool barreAuto); 

    /// @brief Lance la boucle principale de SDL pour afficher la fenêtre du jeu.
    /// @param dim dimension de la fenetre
    /// @return true si le jeu est terminer, faux si le joueur appuie sur echap
    bool sdlBoucle (int dim);

};


#endif