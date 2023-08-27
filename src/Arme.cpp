#include "Arme.h"


Arme::Arme()
{
    Pos p; 
    positionArme = p; 
    vitesseArme = p; 
    forceArme = p; 
    tailleXArme = 0; 
    tailleYArme = 0; 
    masseArme = 0; 
    joueurALancerArme = false; 
    directionArme = 0; 
}

Arme::Arme(Pos p, Pos v, Pos f, int m, int x, int y, bool e)
{
    positionArme = p; 
    vitesseArme = v; 
    forceArme = f; 
    tailleXArme = x; 
    tailleYArme = y; 
    masseArme = m; 
    joueurALancerArme = e; 
    directionArme = 0; 
}

Pos Arme::getPositionArme() const
{
    return positionArme;
}

void Arme::setPositionArme(Pos p)
{
    positionArme = p; 
}

Pos Arme::getVitesseArme() const
{
    return vitesseArme;
}

void Arme::setVitesseArme(Pos v)
{
    vitesseArme = v; 
}

Pos Arme::getForceArme() const
{
    return forceArme;
}

void Arme::setForceArme(Pos f)
{
    forceArme = f; 
}

int Arme::getTailleXArme() const
{
    return tailleXArme;
}

void Arme::setTailleXArme(int x)
{
    tailleXArme = x; 
}

int Arme::getTailleYArme() const
{
    return tailleYArme;
}

void Arme::setTailleYArme(int y)
{
    tailleYArme = y; 
}

bool Arme::getJoueurLancerArme() const
{
    return joueurALancerArme;
}

void Arme::setJoueurLancerArme(bool e)
{
    joueurALancerArme = e; 
}

int Arme::getDirectionArme() const
{
    return directionArme;
}

void Arme::setDirectionArme(int dir)
{
    directionArme = dir; 
}

int Arme::getMasseArme() const
{
    return masseArme;
}

void Arme::setMasseArme(int m)
{
    masseArme = m; 
}

void Arme::addForce(const Pos & F)
{
    forceArme = forceArme + F; 
}

void Arme::mvtArme()
{
    Pos vec(0,-masseArme*G); 

    addForce(vec); 

    if (masseArme > 0) // pour ne plus avoir l'erreur floating point exception
    {
        vitesseArme = vitesseArme + forceArme * (dt*(1/masseArme));
    }

    positionArme = positionArme + vitesseArme * dt;
}

bool Arme::collisionArmeMurs(int dimension, int tailleXmurs, int tailleYmurs) const
{
    return false;
}

bool Arme::collisionArmeEntite(const Pos & p, int tailleX, int tailleY) const 
{
    bool collisionX = (positionArme.getX() + tailleXArme >= p.getX()) && (p.getX() + tailleX >= positionArme.getX()); 

    bool collisionY = (positionArme.getY() + tailleXArme >= p.getY()) && (p.getY() + tailleY >= positionArme.getY()); 

    if (collisionX && collisionY)
    {
        return true; 
    }

    return false; 
}

void Arme::lancerDirectionArme(int direction) // faire le mvt en fonction de la direction du joueur mais à faire en dernier 
{
    //joueurALancerArme = true;

    Pos droite(1,0); 
    Pos gauche(-1,0); 
    Pos haut(0,-1); 
    Pos bas(0,1); 

    switch(direction) 
    {
        case 0: // tirer en haut  
            vitesseArme = haut;
            break;

        case 1: // tirer à droite 
            vitesseArme = droite;
            break;

        case 2: // tirer en bas  
            vitesseArme = bas;
            break;

        case 3: // tirer à gauche  
            vitesseArme = gauche;
            break;

        default:
            break;
    }

    /*
        // Ajouter une force latérale pour dévier la trajectoire
        Pos lateral(2, 1);
        forceArme = forceArme + lateral;

        // Ajouter une rotation pour simuler une courbe
        int angle = 30; // angle de rotation en degrés
        int radians = angle * (3 / 180); // conversion en radians
        int cosAngle = cos(radians);
        int sinAngle = sin(radians);
        int newX = (cosAngle * vitesseArme.getX()) - (sinAngle * vitesseArme.getY());
        int newY = (sinAngle * vitesseArme.getX()) + (cosAngle * vitesseArme.getY());
        vitesseArme.setX(newX);
        vitesseArme.setY(newY);
*/ 
}


void Arme::testRegressionArme()
{
    Arme arme; 
    assert(arme.getPositionArme().getX()==0);
    assert(arme.getPositionArme().getY()==0); 
    assert(arme.getVitesseArme().getX()==0); 
    assert(arme.getVitesseArme().getY()==0); 
    assert(arme.getForceArme().getX()==0); 
    assert(arme.getForceArme().getY()==0); 
    assert(arme.getTailleXArme()==0); 
    assert(arme.getTailleYArme()==0); 
    assert(arme.getDirectionArme()==0); 
    assert(arme.getJoueurLancerArme()==false); 
    assert(arme.getMasseArme()==0); 

    Pos p(12,67); 
    assert(p.getX()==12); 
    assert(p.getY()==67);

    arme.setPositionArme(p); 
    arme.setVitesseArme(p); 
    arme.setForceArme(p); 
    arme.setDirectionArme(1); 
    arme.setTailleXArme(20); 
    arme.setTailleYArme(30); 
    arme.setJoueurLancerArme(true);  
    arme.setMasseArme(40);
    assert(arme.getPositionArme().getX()==12);
    assert(arme.getPositionArme().getY()==67); 
    assert(arme.getVitesseArme().getX()==12); 
    assert(arme.getVitesseArme().getY()==67); 
    assert(arme.getForceArme().getX()==12); 
    assert(arme.getForceArme().getY()==67); 
    assert(arme.getTailleXArme()==20); 
    assert(arme.getTailleYArme()==30); 
    assert(arme.getDirectionArme()==1); 
    assert(arme.getJoueurLancerArme()==true); 
    assert(arme.getMasseArme()==40); 

    Arme arme2(p,p,p,10,20,30,true); 
    assert(arme2.getPositionArme().getX()==12);
    assert(arme2.getPositionArme().getY()==67); 
    assert(arme2.getVitesseArme().getX()==12); 
    assert(arme2.getVitesseArme().getY()==67); 
    assert(arme2.getForceArme().getX()==12); 
    assert(arme2.getForceArme().getY()==67); 
    assert(arme2.getTailleXArme()==20); 
    assert(arme2.getTailleYArme()==30); 
    assert(arme2.getDirectionArme()==0); 
    assert(arme2.getJoueurLancerArme()==true); 
    assert(arme2.getMasseArme()==10); 

    arme2.mvtArme(); 
}
