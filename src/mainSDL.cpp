
#include "JeuModeGraphique.h"
#include <iostream> 

using namespace std; 

int main (int argc, char** argv)
{
    srand(time(nullptr));
    Jeu jeu;
	int dimension = 700;
	jeu.initJeu(3,3,dimension,150,35,50,70,40,70);

    SDLSimple sj(jeu);

    sj.afficherMenu(dimension);  

    return 0;  
}