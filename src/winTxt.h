#ifndef WINTXT_H
#define WINTXT_H

//! \brief une fenÍtre texte est un tableau 2D de caractËres
class WinTXT
{
private:

    int dimx;       //!< \brief largeur
    int dimy;       //!< \brief heuteur
    char* win;      //!< \brief stocke le contenu de la fenÍtre dans un tableau 1D mais on y accede en 2D

public:

    /// @brief contructeur de la classe WinTXT
    /// @param dx largeur de la fenetre pour l'affichage en mode texte 
    /// @param dy longueur de la fenetre pour l'affichage en mode texte 
    WinTXT (int dx, int dy);

    /// @brief destructeur de la classe WinTXT
    ~WinTXT(); 

    /// @brief permet d'effacer le contenu de la fenetre en le remplissant avec un caractère donnée sinon par défaut il y a un espace
    /// @param c caractère 
    void clear (char c=' '); 
    
    /// @brief permet d'afficher un caractère donné au coordonnées spécifiées 
    /// @param x coordonnée x pour afficher le caractère 
    /// @param y coordonnée y pour afficher le caractère
    /// @param c le caractere à afficher 
    void print (int x, int y, char c); 
    
    /// @brief permet d'afficher une chaine de caractères aux coordonnées spécifiées
    /// @param x coordonné x pour afficher la chaine de caractère
    /// @param y coordone y pour afficher la chaine de caractère
    /// @param c pointeur sur tableau de caractères 
    void print (int x, int y, char* c); 
    
    /// @brief permet d'afficher le contenu de la fenetre à partir de coordonnées sinon par defaut c'est en haut à gauche 
    /// @param x coordonné x pour afficher texte
    /// @param y coordonné y pour afficher texte 
    void draw (int x=0, int y=0);
    
    /// @brief permet d'attendre que l'utilisateur appuie sur une touche 
    void pause(); 
    
    /// @brief permet de lire et de renvoyer un caractere entré par l'utilisateur
    /// @return un characeter entré par l'utilisateur 
    char getCh(); 

};


/// @brief efface le contenu de la console 
void termClear (); 

#endif
