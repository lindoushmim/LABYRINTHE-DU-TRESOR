#include "Porte.h"

Porte::Porte()
{
    existe = false; 
    Pos p;
    posPorte = p;
    tailleX = 0;
    tailleY = 0;
}

Porte::~Porte()
{

}

bool Porte::getExiste() const
{
    return existe;
}

Pos Porte::getPosPorte() const
{
    return posPorte;
}

int Porte::getTailleX() const
{
    return tailleX;
}

int Porte::getTailleY() const
{
    return tailleY;
}

void Porte::setExiste(bool e)
{
    existe = e;
}

void Porte::setPosPorte(Pos p)
{
    posPorte = p;
}

void Porte::setTailleX(int x)
{
    tailleX = x;
}

void Porte::setTailleY(int y)
{
    tailleY = y;
}

void Porte::testRegressionPorte()
{
    Porte p; 
    assert(p.getPosPorte().getX()==0); 
    assert(p.getPosPorte().getY()==0); 
    assert(p.getTailleX()==0); 
    assert(p.getTailleY()==0); 
    assert(p.getExiste()==false); 

    Pos pos(10,10); 
    p.setExiste(true); 
    p.setPosPorte(pos); 
    p.setTailleX(20); 
    p.setTailleY(30); 
    assert(pos.getX()==10); 
    assert(pos.getY()==10); 
    assert(p.getPosPorte().getX()==10); 
    assert(p.getPosPorte().getY()==10); 
    assert(p.getTailleX()==20); 
    assert(p.getTailleY()==30); 
    assert(p.getExiste()==true); 
}
