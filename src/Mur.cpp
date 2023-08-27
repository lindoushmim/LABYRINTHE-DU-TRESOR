#include "Mur.h"

Mur::Mur()
{
    Pos p(0,0);
    posMur = p;
    tailleX = 0;
    tailleY = 0;
} 

Pos Mur::getPosMur() const
{
    return posMur;
}

int Mur::getTailleX() const
{
    return tailleX;
}

int Mur::getTailleY() const
{
    return tailleY;
}

void Mur::setPosMur(Pos o)
{
    posMur = o;
}

void Mur::setTailleX(int x)
{
    tailleX = x;
}

void Mur::setTailleY(int y)
{
    tailleY = y;
}

void Mur::initMur(int px, int py, int x, int y)
{
    Pos p(px,py);
    posMur = p;
    tailleX = x;
    tailleY = y;
}

void Mur::testRegressionMur()
{
    Mur m; 
    assert(m.getPosMur().getX()==0); 
    assert(m.getPosMur().getY()==0); 
    assert(m.getTailleX()==0); 
    assert(m.getTailleY()==0); 

    Pos pos(10,20); 
    m.setPosMur(pos);
    m.setTailleX(30); 
    m.setTailleY(40); 
    assert(m.getPosMur().getX()==10); 
    assert(m.getPosMur().getY()==20); 
    assert(m.getTailleX()==30); 
    assert(m.getTailleY()==40); 

    m.initMur(76,97,68,23); 
    assert(m.getPosMur().getX()==76); 
    assert(m.getPosMur().getY()==97); 
    assert(m.getTailleX()==68); 
    assert(m.getTailleY()==23); 
}
