#include "Joueur.h"


Joueur::Joueur() 
{
    positionJoueur.setX(1);  
    positionJoueur.setY(1); 
    tailleX = 0; 
    tailleY = 0; 
    pointDeVie = 3; 
    invincibilite = 0;
    nbArmes = 10;
    branditEpee = false; 
    epee.tailleXElement = 0; 
    epee.tailleYElement = 0; 
    epee.xElement = 0; 
    epee.yElement = 0; 
    directionJoueur = 0; 
}

Joueur::Joueur(int x, int y, int h, int l)
{
    positionJoueur.setX(x); 
    positionJoueur.setY(y); 
    tailleX = l; 
    tailleY = h; 
    pointDeVie = 3; 
    invincibilite = 0;
    Pos p(0,0); 
    nbArmes = 10;
    branditEpee = false; 
    epee.tailleXElement = 0; 
    epee.tailleYElement = 0; 
    epee.xElement = 0; 
    epee.yElement = 0; 
    directionJoueur = 0; 
}

Pos Joueur::getPositionJoueur() const
{
    return positionJoueur; 
}

void Joueur::setPositionJoueur(Pos p)
{
    positionJoueur = p;
}

int Joueur::getDirectionJoueur() const
{
    return directionJoueur;
}

void Joueur::setDirectionJoueur(int dir)
{
    directionJoueur = dir; 
}

bool Joueur::getBranditEpee() const
{
    return branditEpee; 
}

void Joueur::setBranditEpee(bool e)
{
    branditEpee = e; 
}

Element Joueur::getEpee() const
{
    return epee;
}

void Joueur::setEpee(int x, int y, int l, int h)
{
    epee.xElement = x; 
    epee.yElement = y; 
    epee.tailleXElement = l; 
    epee.tailleYElement = h; 
}

int Joueur::getTailleX() const
{
    return tailleX;
}

int Joueur::getTailleY() const
{
    return tailleY;
}

void Joueur::setTailleX(int x)
{
    tailleX = x;
}

void Joueur::setTailleY(int y)
{
    tailleY = y;
}

bool Joueur::estInvincible()
{
    return (invincibilite > 0);
}

int Joueur::getNbArme() const
{
    return nbArmes;
}

void Joueur::setNbArme(int nb)
{
    nbArmes = nb; 
}

vector<Arme> &Joueur::getTabArme()
{
    return tabArmes; 
}

void Joueur::initTabArme()
{
    for (int i = 0; i<nbArmes; i++)
    {
        Pos p; 
        Arme armeAjout(positionJoueur, p, p, 10, 20, 20, false); 
        tabArmes.push_back(armeAjout);
    }
}

void Joueur::setArme(int indice, Arme armeAjout)
{
    if (indice >= 0 && indice < nbArmes) 
    {
        tabArmes[indice] = armeAjout;
    }
}

Arme& Joueur::getArme(int indice) 
{
    return tabArmes.at(indice);
}

void Joueur::ajouterArme(const Arme & arme)
{
    tabArmes.push_back(arme);
}

void Joueur::supprimerArme(int indice)
{
    if (tabArmes.size() > 0) 
    {
        tabArmes.erase(tabArmes.begin() + indice);    
    }
}

void Joueur::testRegressionJoueur()
{
    Joueur joueur; 
    assert(joueur.getPositionJoueur().getX()==1); 
    assert(joueur.getPositionJoueur().getY()==1); 
    assert(joueur.getTailleX()==0); 
    assert(joueur.getTailleY()==0); 
    assert(joueur.invincibilite == 0); 
    assert(joueur.getNbArme()==10); 

    Joueur joueur2(30,49,20,48); 
    assert(joueur2.getPositionJoueur().getX()==30); 
    assert(joueur2.getPositionJoueur().getY()==49); 
    assert(joueur2.getTailleX()==48); 
    assert(joueur2.getTailleY()==20); 
    assert(joueur2.invincibilite == 0); 
    assert(joueur2.getNbArme()==10); 

    joueur2.initTabArme(); 

    for (int i=0; i<joueur2.getNbArme(); i++)
    {
        assert(joueur2.getArme(i).getPositionArme().getX() == joueur2.getPositionJoueur().getX()); 
        assert(joueur2.getArme(i).getPositionArme().getY()==joueur2.getPositionJoueur().getY()); 
        assert(joueur2.getArme(i).getVitesseArme().getX()==0); 
        assert(joueur2.getArme(i).getVitesseArme().getY()==0); 
        assert(joueur2.getArme(i).getForceArme().getX()==0); 
        assert(joueur2.getArme(i).getForceArme().getY()==0); 
        assert(joueur2.getArme(i).getTailleXArme()==20); 
        assert(joueur2.getArme(i).getTailleYArme()==20); 
        assert(joueur2.getArme(i).getDirectionArme()==0); 
        assert(joueur2.getArme(i).getMasseArme()==10); 
        assert(joueur2.getArme(i).getJoueurLancerArme()==false); 
    }

    Pos a (29,28); 
    joueur2.getArme(9).setPositionArme(a); 
}

