#include "winTxt.h"
#include "JeuModeTexte.h"

int main ( int argc, char** argv ) 
{
    termClear();
	Jeu jeu;
	int dimension = 30;
	
	jeu.initJeu(3,3,dimension,0,0,0,0,0,0);


	txtBoucle(jeu,dimension);
    termClear();
	return 0;
}
