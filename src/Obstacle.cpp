#include "Obstacle.h"
#include "math.h"

Obstacle::Obstacle()
{
    Pos p(0,0); 
    centre = p;
    extremite = p;
}

Obstacle::Obstacle(Pos c, Pos e)
{
    centre = c;
    extremite = e;
    Pos p(0,0); 
}



const Pos & Obstacle::getCentre() const
{
    return centre;
}

const Pos & Obstacle::getExtremite() const
{
    return extremite;
}



void Obstacle::setCentre(Pos c)
{
    centre = c;
}

void Obstacle::setExtremite(Pos e)
{
    extremite = e; 
}



void Obstacle::initObstacle(Pos c, Pos e)
{
    centre = c;
    extremite = e;
}

void Obstacle::rotation(int vitesse)
{
    float angle = vitesse * 2* M_PI / 360;

    float dx = extremite.getX() - centre.getX(); 
    float dy = extremite.getY() - centre.getY();
    float new_dx = dx * cos(angle) - dy * sin(angle); //nouveux x de l'extrémité après la rotation
    float new_dy = dx * sin(angle) + dy * cos(angle); 
    extremite.setX(centre.getX() + new_dx); // on remet le point x d'etrimité à sa place et lui ajoute sa nouvelle coordonnée 
    extremite.setY(centre.getY() + new_dy); 
}



void Obstacle::testRegressionObstacle()
{
    Pos p(40,80); 
    Pos p2(39,90); 
    assert(p.getX()==40); 
    assert(p.getY()==80); 
    assert(p2.getX()==39); 
    assert(p2.getY()==90); 

    Obstacle ob; 
    assert(ob.getCentre().getX()==0);
    assert(ob.getCentre().getY()==0);
    assert(ob.getExtremite().getX()==0); 
    assert(ob.getExtremite().getY()==0); 

    ob.initObstacle(p,p2); 
    assert(ob.getCentre().getX()==40);
    assert(ob.getCentre().getY()==80);
    assert(ob.getExtremite().getX()==39); 
    assert(ob.getExtremite().getY()==90); 


    Obstacle ob2(p,p); 
    assert(ob2.getCentre().getX()==40);
    assert(ob2.getCentre().getY()==80);
    assert(ob2.getExtremite().getX()==40); 

    ob2.setCentre(p2); 
    ob2.setExtremite(p2); 
    assert(ob2.getCentre().getX()==39);
    assert(ob2.getCentre().getY()==90);
    assert(ob2.getExtremite().getX()==39); 
    assert(ob2.getExtremite().getY()==90); 


    
}
