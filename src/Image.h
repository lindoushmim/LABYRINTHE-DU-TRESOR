#ifndef _IMAGE_H
#define _IMAGE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h> 
//#include <SDL2/SDL_mixer.h>


//! \brief Pour gérer une image avec SDL2


class Image 
{

private:

    /// @brief surface de l'image chargée
    SDL_Surface * m_surface;

    /// @brief texture de l'image chargée
    SDL_Texture * m_texture;

    /// @brief booleen indiquant si l'image a été modifiée
    bool m_hasChanged;

public:

    /// @brief Constructeur par defaut de la classe Image
    Image () ;

    /// @brief Déstructeur de la classe Image
    ~Image();

    /// @brief charge une image à partir d'un fichier
    /// @param filename chemin du fichier pour charger l'image 
    /// @param renderer renderer sur lequel l'image est dessiné 
    void loadFromFile (const char* filename, SDL_Renderer * renderer);

    /// @brief charge une image  
    /// @param renderer renderer sur lequel l'image est dessiné 
    void loadFromCurrentSurface (SDL_Renderer * renderer);

    /// @brief dessine l'image sur un renderer 
    /// @param renderer renderer sur lequel l'image est dessiné 
    /// @param x coordonnée x de l'image 
    /// @param y coordonnée y de l'image 
    /// @param w largeur de l'image (par defaut -1 : utilise la largeur actuelle de l'image) 
    /// @param h largeur de l'image (par defaut -1 : utilise la longueur actuelle de l'image) 
    void draw (SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1); 

    /// @brief Acceseur pour obtenir le pointeur vers la texture de l'image
    /// @return pointeur vers la texture de l'image 
    SDL_Texture * getTexture() const;

    /// @brief Mutateur pour changer le pointeur de la texture de l'image 
    /// @param surf pointe vers la nouvelle texture de l'image 
    void setSurface(SDL_Surface * surf);

    /// @brief  Accesseur pour recuperer la largeur de l'image 
    /// @return la largeur de l'image 
    int getWidth() const; 

    /// @brief Accesseur pour recuperer la longueur de l'image
    /// @return la longueur de l'image 
    int getHeight() const; 

};

#endif 
