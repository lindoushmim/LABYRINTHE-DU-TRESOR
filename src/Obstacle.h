#ifndef _OBSTACLE_H_
#define _OBSTACLE_H_

#include "Pos.h"
#include <cassert>


/** 
 * @class Obstacle
 * @brief classe pour gerer les fonctionalités des Obstacles (la barre)
*/
class Obstacle 
{

private:

    /// @brief represente un point : il s'agit d'une des extrimité pour la barre et de la position pour l'arme 
    Pos centre; 

    /// @brief represente un point : il represente une des extrimité pour la barre et de la vitesse pour l'arme 
    Pos extremite; // sert de vitesse pour les armes  

    

public:

    /// @brief constructeur par défaut de la classe Obstacle
    Obstacle(); 
    
    /// @brief constructeur de la classe Obstacle
    /// @param c position du centre de l'obstacle
    /// @param e position de l'extrémité de l'obstacle
    Obstacle (Pos c, Pos e); 

    /// @brief accesseur pour la position du centre de l'obstacle
    /// @return position du centre de l'obstacle
    const Pos & getCentre() const;

    /// @brief accesseur pour la position de l'extrémité de l'obstacle
    /// @return position de l'extrémité de l'obstacle
    const Pos & getExtremite() const;


    /// @brief mutateur pour la position du centre de l'obstacle
    /// @param c nouvelle position du centre de l'obstacle
    void setCentre(Pos c);

    /// @brief mutateur pour la position de l'extrémité de l'obstacle
    /// @param e nouvelle position de l'extrémité de l'obstacle
    void setExtremite(Pos e);

    /// @brief Initialise les champs de l'obstacle 
    /// @param c nouveau centre de l'obstacle 
    /// @param e nouveau extrimé de l'obstacle 
    void initObstacle(Pos c, Pos e);

    /// @brief fait tourner l'obstacle autour de son centre selon un angle spécifié
    /// @param angle angle l'angle de rotation 
    void rotation(int angle); 


    /// @brief fonction permettant de tester les utilités de la classe Obstacle 
    void testRegressionObstacle(); 

};



#endif