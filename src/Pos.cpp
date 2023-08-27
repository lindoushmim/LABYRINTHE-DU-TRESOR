#include "Pos.h"
#include "math.h"
#include <cassert>
#include <iostream> 

using namespace std; 

Pos::Pos()
{
    x = 0; 
    y = 0; 
}

Pos::Pos(int positionX, int positionY)
{
    x = positionX; 
    y = positionY; 
}

int Pos::getX() const 
{
    return x; 
}

int Pos::getY() const 
{
    return y; 
}

void Pos::setX(int nx) 
{
    x = nx; 
}

void Pos::setY(int ny)
{
    y=ny; 
}

int Pos::distance(const Pos & pos2) const
{
    return (int) sqrt ( (pow(x-pos2.getX(),2)) + (pow(y-pos2.getX(),2)) ); 
}

Pos Pos::addPos(const Pos &a)
{
    x = x + a.x; 
    y = y + a.y; 
    return *this; 
}

Pos Pos::sousPos(const Pos &a)
{
    x = x - a.x; 
    y = y - a.y; 
    return *this; 
}

Pos Pos::multPos(const Pos &a)
{
    x = x * a.x; 
    y = y * a.y; 
    return *this; 
}

Pos Pos::operator+(const Pos &pos1)
{
    Pos pos_res;
    pos_res.x = x + pos1.x;
    pos_res.y = y + pos1.y;
    return pos_res;
}


Pos Pos::operator-(const Pos &pos1)
{
    Pos pos_res;
    pos_res.x = x - pos1.x;
    pos_res.y = y - pos1.y;
    return pos_res;
}

Pos Pos::operator*(const Pos &pos1)
{
    Pos pos_res;
    pos_res.x = x * pos1.x;
    pos_res.y = y * pos1.y;
    return pos_res;
}

Pos Pos::operator*(float val)
{
    Pos pos_res;
    pos_res.x = x * val;
    pos_res.y = y * val;
    return pos_res;
}

Pos Pos::operator*(double val)
{
    Pos pos_res;
    pos_res.x = x * val;
    pos_res.y = y * val;
    return pos_res;
}

Pos Pos::operator*(int val)
{
    Pos pos_res;
    pos_res.x = x * val;
    pos_res.y = y * val;
    return pos_res;
}

bool Pos::operator==(const Pos &pos1)
{
    return ((x==pos1.x)&&(y==pos1.y));
}


/*
template <typename V> // argeument de type generique V 
Pos Pos::operator*(V val)
{
    Pos pos_res;
    pos_res.x = x * val;
    pos_res.y = y * val;
    return pos_res;
}
*/ 

ostream& operator<<(ostream &os, const Pos &pos1)
{
    os << "x = " << pos1.getX() << "  ;  y = " << pos1.getY() ;
    return os;
}

Pos Pos::normaliser()
{
    float norme = sqrt(x*x + y*y);

    if (norme != 0)
    {
        return Pos(x/norme, y/norme);
    }
    else
    {
        return Pos(0, 0);
    }
}

void Pos::testRegressionPos()
{
    Pos p1; 
    assert(p1.getX()==0); 
    assert(p1.getY()==0); 
    p1.setX(20); 
    p1.setY(30); 
    assert(p1.getX()==20); 
    assert(p1.getY()==30); 

    Pos p2(10,20); 
    assert(p2.getX()==10); 
    assert(p2.getY()==20); 

    Pos p = p1+p2; 
    assert(p.getX()==30);
    assert(p.getY()==50); 

    p1 = p - p2; 
    assert(p1.getX()==20); 
    assert(p1.getY()==30); 

    p = p1 * p2; 
    assert(p.getX()==200); 
    assert(p.getY()==600); 

    p = p1 * 3; 
    assert(p.getX()==60); 
    assert(p.getY()==90); 
     
}
