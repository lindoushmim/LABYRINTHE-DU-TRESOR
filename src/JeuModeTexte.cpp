#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "winTxt.h"

#include "JeuModeTexte.h"


bool delimitationFenetre(int x, int y, int dimensionPiece) // verifie les coordonné (x,y) si il touche les cotés de la fenetre 
{
    return ((x == 0) || (x == dimensionPiece + 4) || (y == 0) || (y == dimensionPiece + 4));
}

bool delimitationPiece(int x, int y, int dimensionPiece) // verifie si les cordonné (x,y) sont à la bordure d'une piece 
{
    bool y_cote = ((y != 1) && (y != dimensionPiece + 3));
    bool x_cote = ((x != 1) && (x != dimensionPiece + 3));

    return  ( ((x == 2) && y_cote)   ||   ((x == dimensionPiece + 2) && y_cote)   ||   ((y == 2) && x_cote) ||  ((y == dimensionPiece + 2) && x_cote) );
}

void afficheObstacle(WinTXT &win, const Jeu & j, int dimensionPiece)
{
    if (j.getPieceActuelle() == 1)
    {
        win.print(j.getPlateau().getPiece(j.getPieceActuelle()).getObstacle().getCentre().getX()+2,j.getPlateau().getPiece(j.getPieceActuelle()).getObstacle().getCentre().getY()+2,'C');
        win.print(j.getPlateau().getPiece(j.getPieceActuelle()).getObstacle().getExtremite().getX()+2,j.getPlateau().getPiece(j.getPieceActuelle()).getObstacle().getExtremite().getY()+2,'E');
        
    }
}



void affichePorte(WinTXT &win, const Jeu & j, int dimensionPiece)
{
    int num = j.getPieceActuelle();
    
    if (j.getPlateau().getPiece(num).getPorte(0).getExiste())
    {
        win.print(j.getPlateau().getPiece(num).getPorte(0).getPosPorte().getX() + 2, //on recupere la position en X de la porte 0
                  j.getPlateau().getPiece(num).getPorte(0).getPosPorte().getY() + 2, //on recupere la position en Y de la porte 0
                  ' ');
    }
    if (j.getPlateau().getPiece(num).getPorte(1).getExiste())
    {
        win.print(j.getPlateau().getPiece(num).getPorte(1).getPosPorte().getX() + 2, //on recupere la position en X de la porte 1
                  j.getPlateau().getPiece(num).getPorte(1).getPosPorte().getY() + 2, //on recupere la position en Y de la porte 1
                  ' ');
    }
    if (j.getPlateau().getPiece(num).getPorte(2).getExiste())
    {
        win.print(j.getPlateau().getPiece(num).getPorte(2).getPosPorte().getX() + 2, //on recupere la position en X de la porte 2
                  j.getPlateau().getPiece(num).getPorte(2).getPosPorte().getY() + 2, //on recupere la position en Y de la porte 2
                  ' ');
    }
    if (j.getPlateau().getPiece(num).getPorte(3).getExiste())
    {
        win.print(j.getPlateau().getPiece(num).getPorte(3).getPosPorte().getX() + 2, //on recupere la position en X de la porte 3
                  j.getPlateau().getPiece(num).getPorte(3).getPosPorte().getY() + 2, //on recupere la position en Y de la porte 3
                  ' ');
    }
}
 

void affichePiece(WinTXT &win, const Jeu & j, int dimensionPiece)
{
    for (int x = 0; x <= dimensionPiece + 4; x++)
    {
        for (int y = 0; y <= dimensionPiece + 4; y++)
        {
            if(delimitationFenetre(x,y,dimensionPiece))  // delimitation de la fenetre
            {
                win.print(x,y,'-');
            }
            else 
            {
                if (delimitationPiece(x,y,dimensionPiece)) // delimitation des murs
                {
                    win.print(x,y,'#');
                }
            }
        }
    }
    
    affichePorte(win,j,dimensionPiece);
   
}

void txtAffiche(WinTXT &win, const Jeu & j, int dimensionPiece)
{

	win.clear();

    affichePiece(win,j,dimensionPiece);
    
    win.print(j.getJoueurJeu().getPositionJoueur().getX() + 2 ,j.getJoueurJeu().getPositionJoueur().getY() + 2 ,'J');


	win.draw();
}

void txtBoucle(Jeu & j, int dimensionPiece)
{
    WinTXT win (dimensionPiece+5,dimensionPiece+5);

	bool ok = true;
    bool fin = false;
	char c=77;
    int pasTexte = 1;
    
	do {
        
	    txtAffiche(win,j,dimensionPiece);
        
        
        
        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(10000);
        #endif // WIN32
        j.changementDePiece(dimensionPiece);
		fin = j.actionAutomatique(dimensionPiece,false,false,false);              // à changer en true ??
		c = (char) win.getCh();

		ok = j.actionClavier(c,pasTexte,dimensionPiece);
	} while (ok && (!fin));
    win.clear();

    char chaine[11]= { 'F', 'I', 'N', ' ', 'D', 'U', ' ', 'J', 'E', 'U', '\0' };
    win.print(dimensionPiece/2 - 1,dimensionPiece/3 ,chaine);
    if (fin)
    {
        char chaine_f[9]= { 'V', 'I', 'C', 'T', 'O', 'I', 'R', 'E', '\0' };
        win.print(dimensionPiece/2,dimensionPiece/2 ,chaine_f);
    }
    else 
    {
        char chaine_f[8]= { 'A', 'B', 'A', 'N', 'D', 'O', 'N', '\0' };
        win.print(dimensionPiece/2,dimensionPiece/2 ,chaine_f);
    }
    
    win.draw();
    usleep(2000000);
}
