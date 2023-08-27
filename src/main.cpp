
#include "Jeu.h"
#include <iostream> 

using namespace std; 

int main (int argc, char** argv)
{

    Pos p; 
    p.testRegressionPos(); 

    Porte porte; 
    porte.testRegressionPorte(); 

    Mur mur; 
    mur.testRegressionMur(); 

    Monstre monstre; 
    monstre.testRegressionMonstre();

    Obstacle obstacle; 
    obstacle.testRegressionObstacle(); 

    Joueur joueur; 
    joueur.testRegressionJoueur(); 

    Arme arme; 
    arme.testRegressionArme(); 

    Plateau plateau; 
    plateau.testRegressionPlateau(); 



    Jeu jeu; 
    jeu.initJeu(12,12,200,12,34,43,23,43,43); 



    
    return 0; 
}