#include "Monstre.h"
#include <cassert>
#include <iostream> 
#include <cstdlib> // pour le rand 
#include <ctime>

using namespace std; 

//const float dt = 0.1;

Monstre::Monstre()
{
    posMonstre.setX(0); 
    posMonstre.setY(0); 
    vitesseMonstre.setX(0); 
    vitesseMonstre.setY(0); 
    tailleXMonstre = 0; 
    tailleYMonstre = 0; 
    direction = 0;
    vieMonstre = true;
}

Monstre::Monstre(int px, int py, int vx, int vy, int l, int h)
{
    posMonstre.setX(px); 
    posMonstre.setY(py); 
    vitesseMonstre.setX(vx); 
    vitesseMonstre.setY(vy); 
    tailleXMonstre = l; 
    tailleYMonstre = h;  
    direction = 0;
    vieMonstre=true; 
}

bool Monstre::getVieMonstre() const
{
    return vieMonstre;
}

void Monstre::setVieMonstre(bool e)
{
    vieMonstre = e; 
}

int Monstre::getDirectionMonstre() const
{
    return direction;
}

void Monstre::setDirectionMonstre(int dir)
{
    direction = dir; 
}

Pos Monstre::getPositionMonstre() const 
{
    return posMonstre;
}

void Monstre::setPositionMonstre(int x, int y)
{
    posMonstre.setX(x); 
    posMonstre.setY(y); 
}

void Monstre::setPositionMonstre(Pos p)
{
    posMonstre = p;
}

Pos Monstre::getVitesseMonstre() const
{
    return vitesseMonstre; 
}

int Monstre::getTailleXMonstre() const
{
    return tailleXMonstre;
}

int Monstre::getTailleYMonstre() const
{
    return tailleYMonstre; 
}

void Monstre::setTailleXMonstre(int x)
{
    tailleXMonstre = x;
}

void Monstre::setTailleYMonstre(int y)
{
    tailleYMonstre = y;
}

void Monstre::testRegressionMonstre()
{ 
    Monstre monstre; 
    assert(monstre.getPositionMonstre().getX()==0); 
    assert(monstre.getPositionMonstre().getY()==0); 
    assert(monstre.getVitesseMonstre().getX()==0); 
    assert(monstre.getVitesseMonstre().getY()==0); 
    assert(monstre.getTailleXMonstre()==0); 
    assert(monstre.getTailleYMonstre()==0); 

    monstre.setPositionMonstre(87,76); 
    monstre.setTailleXMonstre(9); 
    monstre.setTailleYMonstre(76); 
    assert(monstre.getPositionMonstre().getX()==87); 
    assert(monstre.getPositionMonstre().getY()==76); ; 
    //assert(monstre.getDirectionMonstre()==20); 
    assert(monstre.getTailleXMonstre()==9); 
    assert(monstre.getTailleYMonstre()==76); 

    Monstre monstre2(20,18,29,30,48,38); 
    assert(monstre2.getPositionMonstre().getX()==20); 
    assert(monstre2.getPositionMonstre().getY()==18); 
    assert(monstre2.getVitesseMonstre().getX()==29); 
    assert(monstre2.getVitesseMonstre().getY()==30); 
    assert(monstre2.getTailleXMonstre()==48); 
    assert(monstre2.getTailleYMonstre()==38); 
}

