#include "Jeu.h"
#include <unistd.h>


Jeu::Jeu() 
{
    pieceActuelle = 0;
    gameOverBool = false; 
}

void Jeu::setGameOverBool(bool e)
{
    gameOverBool = e;    
}

bool Jeu::getGameOverBool() const
{
    return gameOverBool; 
}

const Plateau & Jeu::getPlateau() const
{
    return pla; 
}

const Plateau & Jeu::getPlateau()
{
    return pla; 
}

Joueur & Jeu::getJoueurJeu() 
{
    return joueur;  
}

const Joueur & Jeu::getJoueurJeu() const
{
    return joueur;  
}

int Jeu::getPieceActuelle() const
{
    return pieceActuelle;
}

void Jeu::setPieceActuelle(int p)
{
    pieceActuelle = p;
}


bool Jeu::actionAutomatique(int dimensionPiece, bool monstre0, bool monstre1, bool barre)
{

    if (monstre0)
    {
        initialisationDeplacementAutoMonstre(0);
    }
    if (monstre1)
    {
        initialisationDeplacementAutoMonstre(1);
        initialisationDeplacementAutoMonstre(2);
        initialisationDeplacementAutoMonstre(3);
    }
    if (barre)
    {
        barreAuto();
    }
    
    return false;
   
}

bool Jeu::actionClavier(const char touche,int pas, int dimensionPiece)
{   
    Pos p(0,0);
    switch (touche) 
    {
        case 'z' : p.setY(- pas) ;
                   joueur.setDirectionJoueur(0);
                   break;

        case 's' : p.setY(pas) ; 
                    joueur.setDirectionJoueur(2);
                    break;

        case 'q' : p.setX(- pas) ;
                    joueur.setDirectionJoueur(3);
                    break;

        case 'd' : p.setX(pas) ;
                    joueur.setDirectionJoueur(1);
                    break;

        case 'p' : return false; break;

        case 'j' : joueur.getTabArme().back().setJoueurLancerArme(true); 
                   joueur.getTabArme().back().setDirectionArme(joueur.getDirectionJoueur()); 
                  break; 

        default : ;break;
    }

    deplacementJoueur(p,dimensionPiece); 
    return true;
}

void Jeu::deplacementJoueur(const Pos & dep, int dimensionPiece)
{
    int x = pla.getPiece(pieceActuelle).collisionsMurs(joueur.getPositionJoueur() + dep, joueur.getTailleX(), joueur.getTailleY());
    if (x == -1) // si touche pas le mur, deplacement est permis 
    {
        joueur.setPositionJoueur(joueur.getPositionJoueur() + dep);
    }
    else // sinon rapproché le joueur au mur 
    {
        joueur.setPositionJoueur(rapprochementMur(joueur.getPositionJoueur(),joueur.getTailleX(),joueur.getTailleY(),x,dep));
    }
}

void Jeu::initJeu(int x, int y, int dimensionPiece, int taillePorteX, int taillePorteY, int tailleJoueurX, int tailleJoueurY, int tailleXMonstre, int tailleYMonstre)
{
    pla.initPlateau(x,y); 
    pla.initPiece(dimensionPiece,taillePorteX,taillePorteY,tailleXMonstre,tailleYMonstre,tailleJoueurX,tailleJoueurY);
    pieceActuelle = 0;
    joueur.setTailleX(tailleJoueurX);
    joueur.setTailleY(tailleJoueurY);
    Pos p(dimensionPiece/2 - tailleJoueurX/2,dimensionPiece/2 - tailleJoueurY/2);
    joueur.setPositionJoueur(p);
    joueur.initTabArme(); 
}

void Jeu::changementDePiece(int dimensionPiece)
{
   
    if (joueur.getPositionJoueur().getX() < 0)
    {
        changeGauche();

        Pos p(pla.getPiece(pieceActuelle).getPorte(1).getPosPorte().getX() - joueur.getTailleX() - 1 ,
              pla.getPiece(pieceActuelle).getPorte(1).getPosPorte().getY() + pla.getPiece(pieceActuelle).getPorte(1).getTailleY()/2 - joueur.getTailleY()/2) ;
        joueur.setPositionJoueur(p);
    }
    if (joueur.getPositionJoueur().getX()+joueur.getTailleX() > dimensionPiece)
    {
        changeDroite();

        Pos p(pla.getPiece(pieceActuelle).getPorte(3).getPosPorte().getX() + pla.getPiece(pieceActuelle).getPorte(3).getTailleX() + 1 ,
              pla.getPiece(pieceActuelle).getPorte(3).getPosPorte().getY() + pla.getPiece(pieceActuelle).getPorte(3).getTailleY()/2 - joueur.getTailleY()/2);
        joueur.setPositionJoueur(p);
    }
    if (joueur.getPositionJoueur().getY() < 0)
    {
        changeHaut();

        Pos p(pla.getPiece(pieceActuelle).getPorte(2).getPosPorte().getX() + pla.getPiece(pieceActuelle).getPorte(2).getTailleX()/2 - joueur.getTailleX()/2,
              pla.getPiece(pieceActuelle).getPorte(2).getPosPorte().getY() - joueur.getTailleY() -1);
        joueur.setPositionJoueur(p);
    }       
    if (joueur.getPositionJoueur().getY()+joueur.getTailleY() > dimensionPiece )
    {
        changeBas();
        
        Pos p(pla.getPiece(pieceActuelle).getPorte(0).getPosPorte().getX() + pla.getPiece(pieceActuelle).getPorte(0).getTailleX()/2 - joueur.getTailleX()/2 ,
              pla.getPiece(pieceActuelle).getPorte(0).getPosPorte().getY() + pla.getPiece(pieceActuelle).getPorte(0).getTailleY() + 1);
        joueur.setPositionJoueur(p);
    }    
}

void Jeu::changeHaut()
{
    setPieceActuelle(pieceActuelle - pla.getDimx());
}

void Jeu::changeDroite()
{
    setPieceActuelle(pieceActuelle + 1);
}

void Jeu::changeBas()
{
    setPieceActuelle(pieceActuelle + pla.getDimx());
}

void Jeu::changeGauche() 
{
    setPieceActuelle(pieceActuelle - 1);
}


Pos Jeu::rapprochementMur(const Pos & p, int tailleX, int tailleY, int indiceMur, const Pos & deplacement)
{
    Pos pos(0,0); 
    if (deplacement.getX() < 0)  //GAUCHE
    {
        Pos res(pla.getPiece(pieceActuelle).getMur(indiceMur).getPosMur().getX() 
                + pla.getPiece(pieceActuelle).getMur(indiceMur).getTailleX() + 1,
                 p.getY());
        return res;
    }
    if (deplacement.getY() < 0)  //HAUT
    {
        Pos res(p.getX(), pla.getPiece(pieceActuelle).getMur(indiceMur).getPosMur().getY() + pla.getPiece(pieceActuelle).getMur(indiceMur).getTailleY() + 1);
        return res;
    }
    if (deplacement.getX() > 0)  //DROITE
    {
        Pos res(pla.getPiece(pieceActuelle).getMur(indiceMur).getPosMur().getX() - tailleX - 1, p.getY());
        return res;
    }
    if (deplacement.getY() > 0)  //BAS
    {
        Pos res(p.getX(), pla.getPiece(pieceActuelle).getMur(indiceMur).getPosMur().getY() -tailleY - 1);
        return res;
    }
    return pos; 
}

Pos Jeu::choixDéplacementAléatoire(int pas, int k)
{
    Pos res;
    int direction = rand() % 4; 

    switch(direction)
    {
        
        case 0: // déplacement à droite 
        {
            Pos dep(pas,0);  
            res = dep;                                                        
            break;
        }
        case 1: // déplacement en haut
        {
            Pos dep(0,-pas); 
            res = dep;                                                        
            break;
        }
        case 2: // déplacement à gauche
        {
            Pos dep(-pas,0);
            res = dep;
            break;
        }                                                          
        case 3: // déplacement en bas
        {
            Pos dep(0,+pas);
            res = dep;
            break;
        }
    }
    return res;
}

Pos Jeu::choixRapprochementJoueur(int pas, int k)
{
    bool droite = false;
    bool bas = false;
    int choix;
    Pos res;
    if (getJoueurJeu().getPositionJoueur().getX() < pla.getPiece(pieceActuelle).getMonstre(k).getPositionMonstre().getX())
    {   // si le monstre est à droite du joueur
        droite = true;
    }
    if (getJoueurJeu().getPositionJoueur().getY() < pla.getPiece(pieceActuelle).getMonstre(k).getPositionMonstre().getY())
    {   // si le monstre est en dessous du joueur
        bas = true;
    }

    if (bas && droite)
    {   // si le monstre est en bas à droite du joueur, on le fait aller aléatoirement en haut ou à gauche
        choix = rand()%2;
        if (choix==0)
        {
            Pos dep(0,-pas);
            res = dep;
        }
        else
        {
            Pos dep(-pas,0);
            res = dep;
        }
    }
    else 
    {
        if((!bas) && (!droite))
        {   // si le monstre est en haut à gauche du joueur, on le fait aller aléatoirement en bas ou à droite
            choix = rand()%2;
            if (choix==0)
            {
                Pos dep(0,+pas);
                res = dep;
            }
            else
            {
                Pos dep(+pas,0);
                res = dep;
            }
        }
        else
        {
            if (droite)
            {   // si le monstre est en haut à droite, on le fait aller aléatoirement en bas ou à gauche
                choix = rand()%2;
                if (choix==0)
                {
                    Pos dep(0,+pas);
                    res = dep;
                }
                else
                {
                    Pos dep(-pas,0);
                    res = dep;
                }
            }
            else
            {   // si le monstre est en bas à gauche, on le fait aller aléatoirement en haut ou à droite
                choix = rand()%2;
                if (choix==0)
                {
                    Pos dep(0,-pas);
                    res = dep;
                }
                else
                {
                    Pos dep(+pas,0);
                    res = dep;
                }
            }
        }
    }
    return res;
}

void Jeu::deplacementMonstre(const Pos  & deplacement, int k)
{
    Pos tmp;
    tmp = pla.getPiece(pieceActuelle).getMonstre(k).getPositionMonstre() + deplacement;

    int x = pla.getPiece(pieceActuelle).collisionsMurs(tmp , pla.getPiece(pieceActuelle).getMonstre(k).getTailleXMonstre() , pla.getPiece(pieceActuelle).getMonstre(k).getTailleYMonstre());
    int y = pla.getPiece(pieceActuelle).collisionsPortes(tmp , pla.getPiece(pieceActuelle).getMonstre(k).getTailleXMonstre() , pla.getPiece(pieceActuelle).getMonstre(k).getTailleYMonstre());

    if (x == -1) // si le deplacement du monstre ne le fait pas aller dans un mur, on fait ce déplacement, sinon on le rapproche au maximum au mur
    {
        
        if (y == -1)
        {
            pla.getPiece(pieceActuelle).getMonstre(k).setPositionMonstre(tmp); 
        }
    }   
    else
    {
        pla.getPiece(pieceActuelle).getMonstre(k).setPositionMonstre(rapprochementMur(pla.getPiece(pieceActuelle).getMonstre(k).getPositionMonstre(), 
                                                                                      pla.getPiece(pieceActuelle).getMonstre(k).getTailleXMonstre(), 
                                                                                      pla.getPiece(pieceActuelle).getMonstre(k).getTailleYMonstre(), 
                                                                                      x, 
                                                                                      deplacement));
    }  
}

void Jeu::initialisationDeplacementAutoMonstre(int k)
{
    if (pla.getPiece(pieceActuelle).getMonstre(k).getVieMonstre()) // seulement si en vie 
    { 
        int pas;
        if (k == 0)
        {
            pas = 20;
        }
        else
        {
            pas = 2;
        }
        
        if ((pla.getPiece(pieceActuelle).getType() == TYPE_2)&&(k==0))
        {   // ON DEPLACE ALEATOIREMENT LE MONSTRE

            Pos deplacement;
            deplacement = choixDéplacementAléatoire(pas,k);

            deplacementMonstre(deplacement,k);
        
        }
        if ((pla.getPiece(pieceActuelle).getType() == TYPE_2)&&(k==1))
        {   // ON RAPPROCHE LE MONSTRE DU JOUEUR
            
            Pos deplacement;
            deplacement = choixRapprochementJoueur(pas,k); // on défini le déplacement à faire
            deplacementMonstre(deplacement,k);
            
        }
        if ((pla.getPiece(pieceActuelle).getType() == TYPE_2)&&(k==2))
        {   // LE MONSTRE FAIT LE TOUR DE LA PIECE DANS LE SENS HORAIRE
            Pos sauvegarde = pla.getPiece(pieceActuelle).getMonstre(k).getPositionMonstre();
            Pos deplacement;
            switch(pla.getPiece(pieceActuelle).getMonstre(k).getDirectionMonstre())
            {
                case 0 : // haut
                {
                    Pos dep(0,-pas);
                    deplacement = dep;
                    break;
                }
                case 1 : // droite
                {
                    Pos dep(+pas,0);
                    deplacement = dep;
                    break;
                }
                case 2 : // bas
                {
                    Pos dep(0,+pas);
                    deplacement = dep;
                    break;
                }
                case 3 : // gauche
                {
                    Pos dep(-pas,0);
                    deplacement = dep;
                    break;
                }

            }

            deplacementMonstre(deplacement,k);

            if (pla.getPiece(pieceActuelle).getMonstre(k).getPositionMonstre() == sauvegarde) 
            {   // si la position n'a pas changé donc si le monstre etait déja collé à un mur
                
                switch(pla.getPiece(pieceActuelle).getMonstre(k).getDirectionMonstre())
                {
                    case 0 : // haut
                    {
                        Pos dep(+pas,0);
                        deplacement = dep;
                        pla.getPiece(pieceActuelle).getMonstre(k).setDirectionMonstre(1);
                        break;
                    }
                    case 1 : // droite
                    {
                        Pos dep(0,+pas);
                        deplacement = dep;
                        pla.getPiece(pieceActuelle).getMonstre(k).setDirectionMonstre(2);
                        break;
                    }
                    case 2 : // bas
                    {
                        Pos dep(-pas,0);
                        deplacement = dep;
                        pla.getPiece(pieceActuelle).getMonstre(k).setDirectionMonstre(3);
                        break;
                    }
                    case 3 : // gauche
                    {
                        Pos dep(0,-pas);
                        deplacement = dep;
                        pla.getPiece(pieceActuelle).getMonstre(k).setDirectionMonstre(0);
                        break;
                    }

                }
                deplacementMonstre(deplacement,k);
            }
                                                                    
        }
        
        if ((pla.getPiece(pieceActuelle).getType() == TYPE_2)&&(k==3))
        {   // LE MONSTRE FAIT SE DEPLACE COLLE AUX MURS 
            Pos sauvegarde = pla.getPiece(pieceActuelle).getMonstre(k).getPositionMonstre();
            Pos deplacement;
            switch(pla.getPiece(pieceActuelle).getMonstre(k).getDirectionMonstre())
            {
                case 0 : // haut
                {
                    Pos dep(0,-pas);
                    deplacement = dep;
                    break;
                }
                case 1 : // droite
                {
                    Pos dep(+pas,0);
                    deplacement = dep;
                    break;
                }
                case 2 : // bas
                {
                    Pos dep(0,+pas);
                    deplacement = dep;
                    break;
                }
                case 3 : // gauche
                {
                    Pos dep(-pas,0);
                    deplacement = dep;
                    break;
                }

            }
            
            deplacementMonstre(deplacement,k);
            
            if (pla.getPiece(pieceActuelle).getMonstre(k).getPositionMonstre() == sauvegarde) 
            {   // si la position n'a pas changé donc si le monstre etait déja collé à un mur
                switch(pla.getPiece(pieceActuelle).getMonstre(k).getDirectionMonstre())
                {
                    case 0 : // haut
                    {
                        int x = rand()%3 + 1;
                        pla.getPiece(pieceActuelle).getMonstre(k).setDirectionMonstre(x);
                        break;
                    }
                    case 1 : // droite
                    {
                        int x = rand()%3;
                        if (x >= 1)
                        {
                            x++;
                        }
                        pla.getPiece(pieceActuelle).getMonstre(k).setDirectionMonstre(x);
                        break;
                    }
                    case 2 : // bas
                    {
                        int x = rand()%3;
                        if (x == 2)
                        {
                            x++;
                        }
                        pla.getPiece(pieceActuelle).getMonstre(k).setDirectionMonstre(x);
                        break;
                    }
                    case 3 : // gauche
                    {
                        int x = rand()%3;
                        pla.getPiece(pieceActuelle).getMonstre(k).setDirectionMonstre(x);
                        break;
                    }

                }
                deplacementMonstre(deplacement,k);
            }
                                                                    
        }

    }

}


bool Jeu::contactMonstreJoueur()
{ 
    for (int k = 0; k < 4; k++)
    { 
        bool collisionX = (joueur.getPositionJoueur().getX() + joueur.getTailleX() >= pla.getPiece(pieceActuelle).getMonstre(k).getPositionMonstre().getX()) 
                            && (pla.getPiece(pieceActuelle).getMonstre(k).getPositionMonstre().getX() + pla.getPiece(pieceActuelle).getMonstre(k).getTailleXMonstre() >= joueur.getPositionJoueur().getX());

        bool collisionY = (joueur.getPositionJoueur().getY() + joueur.getTailleY() >= pla.getPiece(pieceActuelle).getMonstre(k).getPositionMonstre().getY()) 
                            && (pla.getPiece(pieceActuelle).getMonstre(k).getPositionMonstre().getY() + pla.getPiece(pieceActuelle).getMonstre(k).getTailleYMonstre() >= joueur.getPositionJoueur().getY());

        if (collisionX && collisionY)
        {
            return true; 
        }
    }
    return false; 
}


bool Jeu::contactBarreJoueur()
{
    if(pla.getPiece(pieceActuelle).getType() == TYPE_1)
    {

        int hauteurPiece = pla.getPiece(pieceActuelle).getDimYP();
        Pos barreCentre = pla.getPiece(pieceActuelle).getObstacle().getCentre();
        Pos barreExtremite = pla.getPiece(pieceActuelle).getObstacle().getExtremite();

        int xJoueur = joueur.getPositionJoueur().getX();
        int yJoueur = joueur.getPositionJoueur().getY();


        // le point 0,0 est en haut à gauche, on fait ces changement pour faire les calculs comme si le point etait en bas à gauche (ça demande moins de réfléxion)
        barreCentre.setY(hauteurPiece - barreCentre.getY());
        barreExtremite.setY(hauteurPiece - barreExtremite.getY());
        yJoueur = hauteurPiece - yJoueur;

        bool possibleX;
        bool possibleY;

        bool x_y_audessus;
        bool xTaille_y_audessus;
        bool x_yTaille_audessus;
        bool xTaille_yTaille_audessus;

        float m;
        float p;



        // gere le cas où la barre est verticale
        if ((barreCentre.getX() - barreExtremite.getX()) == 0)
        {
            if ((xJoueur < barreCentre.getX())&&((xJoueur + joueur.getTailleX()) > barreCentre.getX()))
            {
                if(barreCentre.getY() > barreExtremite.getY())
                {
                    return (((yJoueur < barreCentre.getY()) && (yJoueur > barreExtremite.getY()))  ||  (((yJoueur - joueur.getTailleY()) < barreCentre.getY()) && ((yJoueur - joueur.getTailleY()) > barreExtremite.getY())));
                }
                else
                {
                    return (((yJoueur > barreCentre.getY()) && (yJoueur < barreExtremite.getY()))  ||  (((yJoueur - joueur.getTailleY()) > barreCentre.getY()) && ((yJoueur - joueur.getTailleY()) < barreExtremite.getY())));
                }
            }
            else
            {
                return false;
            }
        }

        if (barreExtremite.getX() < barreCentre.getX())
        {   // partie gauche
            m = (float(barreCentre.getY() - barreExtremite.getY())/float(barreCentre.getX() - barreExtremite.getX()));
            p = (barreCentre.getY() - (m * barreCentre.getX()));

            // si une partie du joueur est entre la position x du centre et de l'extremité de la barre 
            possibleX = ( ((xJoueur < barreCentre.getX())&&(xJoueur > barreExtremite.getX()))
                      || (((xJoueur + joueur.getTailleX()) < barreCentre.getX())&&((xJoueur + joueur.getTailleX()) > barreExtremite.getX())));
                      
        }
        else
        {   // partie droite
            m = (float(barreExtremite.getY() - barreCentre.getY())/float(barreExtremite.getX() - barreCentre.getX()));
            p = (barreExtremite.getY() - (m * barreExtremite.getX()));

            // si le joueur est entre la position x du centre et de l'extremité de la barre 
            possibleX = ( ((xJoueur < barreExtremite.getX())&&(xJoueur > barreCentre.getX()))
                      || (((xJoueur + joueur.getTailleX()) < barreExtremite.getX())&&((xJoueur + joueur.getTailleX()) > barreCentre.getX())));
        }

        if (barreExtremite.getY() > barreCentre.getY())
        {   //partie supérieur

            // si le joueur est entre la position y du centre et de l'extremité de la barre 
            possibleY = ( ((yJoueur < barreExtremite.getY())&&(yJoueur > barreCentre.getY()))
                      || (((yJoueur - joueur.getTailleY()) < barreExtremite.getY())&&((yJoueur - joueur.getTailleY()) > barreCentre.getY())));
        }
        else
        {   //partie inférieur

            // si le joueur est entre la position y du centre et de l'extremité de la barre 
            possibleY = ( ((yJoueur < barreCentre.getY())&&(yJoueur > barreExtremite.getY()))
                      || (((yJoueur - joueur.getTailleY()) < barreCentre.getY())&&((yJoueur - joueur.getTailleY()) > barreExtremite.getY())));
        }
        
        if ((!possibleX)||(!possibleY))
        {
            return false;
        }

        

        // si le point supérieur gauche du joueur est au dessus de la barre
        x_y_audessus = ((xJoueur*m + p) < yJoueur);

        // si le point supérieur droit du joueur est au dessus de la barre
        xTaille_y_audessus = (((xJoueur + joueur.getTailleX())*m + p) < yJoueur);

        // si le point inférieur gauche du joueur est au dessus de la barre
        x_yTaille_audessus = ((xJoueur*m + p) < (yJoueur - joueur.getTailleY()));
        
        // si le point inférieur droit du joueur est au dessus de la barre
        xTaille_yTaille_audessus = (((xJoueur + joueur.getTailleX())*m + p) < (yJoueur - joueur.getTailleY()));



        // si on a un point au dessus de la barre et un point en dessous       
        if ((x_y_audessus && !(x_yTaille_audessus || xTaille_y_audessus || xTaille_yTaille_audessus)))
        {
            return true;
        }
        if ((x_yTaille_audessus && !(x_y_audessus && xTaille_y_audessus && xTaille_yTaille_audessus)))
        {
            return true;
        }
        if ((xTaille_y_audessus && !(x_y_audessus && x_yTaille_audessus && xTaille_yTaille_audessus)))
        {
            return true;
        }
        if ((xTaille_yTaille_audessus && !(x_y_audessus && xTaille_y_audessus && x_yTaille_audessus)))
        {
            return true;
        }

        

        // si l'extremité est dans le joueur
        if ((barreExtremite.getX() > xJoueur)&&(barreExtremite.getX() < (xJoueur + joueur.getTailleX()))&&(barreExtremite.getY() < yJoueur)&&(barreExtremite.getY() > (yJoueur - joueur.getTailleY())))
        {
            return true;
        }

        // si le centre est dans le joueur
        if ((barreCentre.getX() > xJoueur)&&(barreCentre.getX() < (xJoueur + joueur.getTailleX()))&&(barreCentre.getY() < yJoueur)&&(barreCentre.getY() > (yJoueur - joueur.getTailleY())))
        {
            return true;
        }
        
    }
    
    
    return false;
}

void Jeu::barreAuto()
{
    if (pla.getPiece(pieceActuelle).getType() == TYPE_1)
    {
        pla.getPiece(pieceActuelle).getObstacle().rotation(1); 
    }
}


void Jeu::gestionVie()
{
    
    if (contactBarreJoueur() && !(joueur.estInvincible()))
    {
        joueur.pointDeVie--; 
        joueur.invincibilite += 2;
    }
    if (contactMonstreJoueur() && !(joueur.estInvincible()))
    {
        joueur.pointDeVie--; 
        joueur.invincibilite += 2;
    }
    if (pla.getPiece(pieceActuelle).getContientVie() && contactVieJoueur() && !(pla.getPiece(pieceActuelle).getAPrisVie()))
    {
        joueur.pointDeVie++; 
        pla.getPiece(pieceActuelle).setAPrisVie(true); 
        pla.getPiece(pieceActuelle).setContientVie(false); 
    }
    if (contactBombeJoueur() && !(joueur.estInvincible()))
    {
        joueur.pointDeVie = joueur.pointDeVie - 2; 
        joueur.invincibilite += 2;
    }
 
}

void Jeu::gestionInvincibilite(bool longtemps)
{
    if (longtemps && (joueur.invincibilite > 0))
    {
        joueur.invincibilite-- ;
    }
}

bool Jeu::gameOver() // si plus de vie perdu 
{
    return (joueur.pointDeVie <= 0); 
}

int Jeu::arretJeu() 
{
   if (gameOver())
   {
      return 1;
   }
   if (jeuGagner())
   {
      return 2;
   }
   return -1;
}

bool Jeu::jeuGagner() // si le joueur a trouvé le trésor 
{

    if (contactTresorJoueur())
    {
        return true ; 
    }

    return false; 
}

bool Jeu::contactTresorJoueur()
{
    if ((pieceActuelle != pla.getSalleFin()))
    {
        return false;
    }
    bool collisionX = (joueur.getPositionJoueur().getX() + joueur.getTailleX() >= pla.getPiece(pieceActuelle).getXTresor()) 
                        && (pla.getPiece(pieceActuelle).getXTresor() + pla.getPiece(pieceActuelle).getTailleXTresor() >= joueur.getPositionJoueur().getX());
                                                                                                
    bool collisionY = (joueur.getPositionJoueur().getY() + joueur.getTailleY() >= pla.getPiece(pieceActuelle).getYTresor()) 
                        && (pla.getPiece(pieceActuelle).getYTresor() + pla.getPiece(pieceActuelle).getTailleYtresor() >= joueur.getPositionJoueur().getY());

    return (collisionX && collisionY); 
}


bool Jeu::contactVieJoueur()
{
    if (pla.getPiece(pieceActuelle).getContientVie())
    {
        bool collisionX = (joueur.getPositionJoueur().getX() + joueur.getTailleX() >= pla.getPiece(pieceActuelle).getElement().xElement) 
                            && (pla.getPiece(pieceActuelle).getElement().xElement + pla.getPiece(pieceActuelle).getElement().tailleXElement >= joueur.getPositionJoueur().getX());

        bool collisionY = (joueur.getPositionJoueur().getY() + joueur.getTailleY() >= pla.getPiece(pieceActuelle).getElement().yElement) 
                        && (pla.getPiece(pieceActuelle).getElement().yElement + pla.getPiece(pieceActuelle).getElement().tailleYElement >= joueur.getPositionJoueur().getY());

        if (collisionX && collisionY)
        {
            return true; 
        }
        return false;
    }
    return false;
}

bool Jeu::contactBombeJoueur()
{
    if (pla.getPiece(pieceActuelle).getContientBombe())
    {
        bool collisionX = (joueur.getPositionJoueur().getX() + joueur.getTailleX() >= pla.getPiece(pieceActuelle).getBombe().xElement) 
                            && (pla.getPiece(pieceActuelle).getBombe().xElement + pla.getPiece(pieceActuelle).getBombe().tailleXElement >= joueur.getPositionJoueur().getX());

        bool collisionY = (joueur.getPositionJoueur().getY() + joueur.getTailleY() >= pla.getPiece(pieceActuelle).getBombe().yElement) 
                        && (pla.getPiece(pieceActuelle).getBombe().yElement + pla.getPiece(pieceActuelle).getBombe().tailleYElement >= joueur.getPositionJoueur().getY());

        if (collisionX && collisionY)
        {
            return true; 
        }
        return false;
    }
    return false;
}


bool Jeu::contactMonstreEntite(int k, Pos p, int tailleX, int tailleY)
{

    bool collisionX = (p.getX() + tailleX >= pla.getPiece(pieceActuelle).getMonstre(k).getPositionMonstre().getX()) 
                            && (pla.getPiece(pieceActuelle).getMonstre(k).getPositionMonstre().getX() + pla.getPiece(pieceActuelle).getMonstre(k).getTailleXMonstre() >= p.getX());

    bool collisionY = (p.getY() + tailleY >= pla.getPiece(pieceActuelle).getMonstre(k).getPositionMonstre().getY()) 
                            && (pla.getPiece(pieceActuelle).getMonstre(k).getPositionMonstre().getY() + pla.getPiece(pieceActuelle).getMonstre(k).getTailleYMonstre() >= p.getY());

    if (collisionX && collisionY)
    {
        return true; 
    }
    
    return false; 
}


bool Jeu::contactPotionJoueur()
{
    if (pla.getPiece(pieceActuelle).getContientPotion())
    {
        bool collisionX = (joueur.getPositionJoueur().getX() + joueur.getTailleX() >= pla.getPiece(pieceActuelle).getPotion().xElement) 
                            && (pla.getPiece(pieceActuelle).getPotion().xElement + pla.getPiece(pieceActuelle).getPotion().tailleXElement >= joueur.getPositionJoueur().getX());

        bool collisionY = (joueur.getPositionJoueur().getY() + joueur.getTailleY() >= pla.getPiece(pieceActuelle).getPotion().yElement) 
                        && (pla.getPiece(pieceActuelle).getPotion().yElement + pla.getPiece(pieceActuelle).getPotion().tailleYElement >= joueur.getPositionJoueur().getY());

        if (collisionX && collisionY)
        {
            return true; 
        }
        return false;
    }
    return false;
}

void Jeu::joueurBuPotion()
{
    if (contactPotionJoueur())
    {   
        
        pla.getPiece(pieceActuelle).setContientPotion(false); 

        switch(pla.getPiece(pieceActuelle).getTypePotion())
        {
            case GRANDIR:
            {
                int x = 0;
                while (!pla.getPiece(pieceActuelle).getPorte(x).getExiste())
                {   // tant qu'on ne tombe pas sur une porte qui existe
                    x++;
                }

                if (((joueur.getTailleX()*2) <= (0.95*pla.getPiece(pieceActuelle).getPorte(x).getTailleX()))&&((joueur.getTailleY()*2) <= (0.95*pla.getPiece(pieceActuelle).getPorte(x).getTailleX())))
                {
                    joueur.setTailleX(joueur.getTailleX()*2); 
                    joueur.setTailleY(joueur.getTailleY()*2); 
                }
                
                break; 
            }
            case RETRECIR:
            {
                joueur.setTailleX(joueur.getTailleX()/2); 
                joueur.setTailleY(joueur.getTailleY()/2); 
                break; 
            }
            case GAGNER_INVICIBILITE:
            {
                joueur.invincibilite += 4;
                break; 
            }
        }
    }
}

// deplace l'arme aussi 
void Jeu::deplacerEpee(char direction)  // revoir la position de l'epee, flemme mnt, surtout coté gauche et haut 
{
    int tailleX=100; 
    int tailleY=100; 

    switch (direction) 
    {
        case 'o': // haut  --
                joueur.setEpee(joueur.getPositionJoueur().getX() + joueur.getTailleX()/2 - tailleX/2, 
                            joueur.getPositionJoueur().getY() - tailleY, 
                            tailleX, tailleY);
                joueur.setBranditEpee(true); 
                break;

        case 'l': // bas
                joueur.setEpee(joueur.getPositionJoueur().getX() + joueur.getTailleX()/2 - tailleX/2, 
                            joueur.getPositionJoueur().getY() + joueur.getTailleY(), 
                            tailleX, tailleY);
                joueur.setBranditEpee(true);
                break;

        case 'k': 
                joueur.setEpee(joueur.getPositionJoueur().getX() - tailleX, 
                            joueur.getPositionJoueur().getY() - joueur.getTailleY()/4, 
                            tailleX, tailleY);
                joueur.setBranditEpee(true);
                break;

        case 'm': // droite
                joueur.setEpee(joueur.getPositionJoueur().getX() + joueur.getTailleX(),
                           joueur.getPositionJoueur().getY() - joueur.getTailleY()/4,
                           tailleX, tailleY); 
                joueur.setBranditEpee(true);
                break;

        case 'j': 
            joueur.getTabArme().back().setJoueurLancerArme(true); 

        default:
                joueur.getTabArme().back().setJoueurLancerArme(false); 
                joueur.setBranditEpee(false);
                break;
    }
}

void Jeu::mortMonstre()
{
    Pos epee(joueur.getEpee().xElement,joueur.getEpee().yElement); 

    if (pla.getPiece(pieceActuelle).getType()==TYPE_2)
    {
        for (int k = 0; k<4; k++)
        {
            if ( (contactMonstreEntite( k, epee, joueur.getEpee().tailleXElement, joueur.getEpee().tailleYElement))
                && (joueur.getBranditEpee()) )
            {
                pla.getPiece(pieceActuelle).supprimerUnMonstre(k); // met sa vie à false et le "supprime" du tableau
            }

            if ( contactMonstreEntite( k, joueur.getTabArme().back().getPositionArme(),
                                          joueur.getTabArme().back().getTailleXArme(), 
                                          joueur.getTabArme().back().getTailleYArme() ) )
            {
                
                if (joueur.getTabArme().back().getJoueurLancerArme())
                {
                    pla.getPiece(pieceActuelle).supprimerUnMonstre(k); 
                    joueur.getTabArme().back().setJoueurLancerArme(false); 
                }

            }                              
        }
    }
}

void Jeu::deplaAutoArme() // attention : gerer le cas ou l'arme sort par la porte 
{
    if(joueur.getTabArme().size() > 0)
    {
        if (joueur.getTabArme().back().getJoueurLancerArme()) // donc si appuyé sur touche j
        {
            joueur.getTabArme().back().lancerDirectionArme(joueur.getDirectionJoueur()); // change la direction en fonction de la position du joueur
            joueur.getTabArme().back().mvtArme(); 
        }
        
        // si collision de l'arme mettre le bool à faux et supprimer l'arme 

        if (( pla.getPiece(pieceActuelle).collisionsMurs(joueur.getTabArme().back().getPositionArme(), 
                                                        joueur.getTabArme().back().getTailleXArme(),
                                                        joueur.getTabArme().back().getTailleYArme()) !=-1) 
                                                        ||
            ( pla.getPiece(pieceActuelle).collisionsPortes(joueur.getTabArme().back().getPositionArme(), 
                                                        joueur.getTabArme().back().getTailleXArme(),
                                                        joueur.getTabArme().back().getTailleYArme()) !=-1) )

        {
            joueur.getTabArme().back().setJoueurLancerArme(false); 
            joueur.supprimerArme(joueur.getTabArme().size()-1); 
        }
    }
    
}
