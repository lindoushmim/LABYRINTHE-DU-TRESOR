#include "Piece.h"
#include <cassert>
#include <iostream>
#include <assert.h>  

using namespace std;  


Piece::Piece()
{
    dimxP = 0; 
    dimyP = 0; 
    nbMonstre = 0; 
    objet.xObjet = 0; 
    objet.yObjet = 0; 
    objet.tailleXObjet = 0; 
    objet.tailleYObjet = 0; 
    contientVie = false; 
    vieContient.xElement = 0; 
    vieContient.yElement = 0; 
    vieContient.tailleXElement = 0; 
    vieContient.tailleYElement = 0; 
    aPrisVie = false; 
    contientBombe = false; 
    bombe.xElement = 0; 
    bombe.yElement = 0; 
    bombe.tailleXElement = 0; 
    bombe.tailleYElement = 0; 
    xTresor = 0; 
    yTresor = 0; 
    tailleXTresor = 0; 
    tailleYTresor = 0; 
    potion.xElement = 0; 
    potion.yElement = 0; 
    potion.tailleXElement = 0; 
    potion.tailleYElement = 0; 
    contientPotion = false; 

}

Piece::Piece(int dimensionXP, int dimensionYP, TypePiece P, TypePotion Po)
{
    dimxP = dimensionXP; 
    dimyP = dimensionYP; 
    type = P;  
    potionType = Po; 
    
    objet.xObjet = 0; 
    objet.yObjet = 0; 
    objet.tailleXObjet = 0; 
    objet.tailleYObjet = 0; 

    contientVie = false; 
    vieContient.xElement = 0; 
    vieContient.yElement = 0; 
    vieContient.tailleXElement = 0; 
    vieContient.tailleYElement = 0; 
    aPrisVie = false; 

    contientBombe = false; 
    bombe.xElement = 0; 
    bombe.yElement = 0; 
    bombe.tailleXElement = 0; 
    bombe.tailleYElement = 0; 

    potion.xElement = 0; 
    potion.yElement = 0; 
    potion.tailleXElement = 0; 
    potion.tailleYElement = 0; 
    contientPotion = false; 
}

Piece::~Piece()
{
    ;
}

Piece::Objet Piece::getObjet() const
{
    return objet;
}

void Piece::setObjet(int x, int y, int l, int h)
{
    objet.xObjet = x; 
    objet.yObjet = y; 
    objet.tailleXObjet = l; 
    objet.tailleYObjet = h; 
}

Element & Piece::getElement()  
{
    return vieContient;
}

void Piece::setElement(int x, int y, int l, int h)
{
    vieContient.xElement = x; 
    vieContient.yElement = y; 
    vieContient.tailleXElement = l; 
    vieContient.tailleYElement = h; 
}

Element &Piece::getBombe() 
{
    return bombe; 
}

void Piece::setBombe(int x, int y, int l, int h)
{
    bombe.xElement = x; 
    bombe.yElement = y; 
    bombe.tailleXElement = l; 
    bombe.tailleYElement = h; 
}

Element &Piece::getPotion()
{
    return potion; 
}

void Piece::setPotion(int x, int y, int l, int h)
{
    potion.xElement = x; 
    potion.yElement = y; 
    potion.tailleXElement = l; 
    potion.tailleYElement = h; 
}

void Piece::setContientBombe(bool e)
{
    contientBombe = e; 
}

bool &Piece::getContientBombe()
{
    return contientBombe; 
}

void Piece::setContientVie(bool e)
{
    contientVie = e; 
}

bool & Piece::getContientVie() 
{
    return contientVie;
}

void Piece::setAPrisVie(bool e)
{
    aPrisVie = e; 
}

bool &Piece::getAPrisVie()
{
    return aPrisVie; 
}

void Piece::setContientPotion(bool e)
{
    contientPotion = e; 
}

bool &Piece::getContientPotion()
{
    return contientPotion; 
}

int Piece::getDimXP() const
{
    return dimxP;
}

int Piece::getDimYP() const 
{
    return dimyP;
}

int Piece::getNbMonstre() const
{
    return nbMonstre;
}

void Piece::setNbMonstre(int nb)
{
    nbMonstre = nb; 
}

TypePiece Piece::getType() const 
{
    return type;
}

TypePotion Piece::getTypePotion() const
{
    return potionType;
}

Porte& Piece::getPorte(int num) 
{
    return tabPorte[num];
}

Porte Piece::getPorte(int num) const
{
    return tabPorte[num];
}

Mur& Piece::getMur(int indice)
{
    return tabMur[indice];
}

int Piece::getNbMur() const
{
    return nbMur;
}

void Piece::setNbMur(int nb)
{
    nbMur = nb;
}

int Piece::getXTresor() const
{
    return xTresor;
}

int Piece::getYTresor() const
{
    return yTresor;
}

int Piece::getTailleXTresor() const
{
    return tailleXTresor;
}

int Piece::getTailleYtresor() const
{
    return tailleYTresor;
}

void Piece::setXTresor(int x)
{
    xTresor = x; 
}

void Piece::setYTresor(int y)
{
    yTresor = y; 
}

void Piece::setTailleXTresor(int tailleX)
{
    tailleXTresor = tailleX; 
}

void Piece::setTailleYTresor(int tailleY)
{
    tailleYTresor = tailleY; 
}

Monstre &Piece::getMonstre(int indice) 
{
    return tabMonstre[indice]; 
}

void Piece::ajouterMonstre(Monstre &monstre) // Fonction qui ajoute un objet Monstre au tableau de monstre pour cette pièce
{
    for (int i = 0; i < 4; i++) 
    {
        tabMonstre[i] = monstre; // Ajoute le nouveau monstre à l'emplacement vide
    }
}

Obstacle& Piece::getObstacle()
{
    return barre;
}

bool Piece::estPositionValidePiece(const int x, const int y) const
{
    
    return ( (x>=0) && (x<dimxP-2) && (y>=0) && (y<dimyP-2)); 

}

bool Piece::estPositionValidePiecePos(const Pos & p) const
{
    return (estPositionValidePiece(p.getX(),p.getY())); 
}

void Piece::initVieEtBombeEtPotion(int epaisseurPorte, int tailleJoueurX, int tailleJoueurY)
{ 
    int boolvie = rand() % 2; // 1 chance sur 2 d'avoir une vie 
    if (boolvie==1) 
    {
        int x = rand() % (dimxP - 2*epaisseurPorte - epaisseurPorte) + epaisseurPorte;
        int y = rand() % (dimyP - 2*epaisseurPorte - epaisseurPorte) + epaisseurPorte;
        setContientVie(true);                       //pour la taille de l'image
        setElement(x,y,epaisseurPorte,epaisseurPorte); 
    }
    
    int boolbombe = rand() % 2; // 1 chance sur 2 d'avoir une bombe
    if (boolbombe==1) 
    {
        int x = rand() % (dimxP - 2*epaisseurPorte - epaisseurPorte) + epaisseurPorte;
        int y = rand() % (dimyP - 2*epaisseurPorte - epaisseurPorte) + epaisseurPorte;
        setContientBombe(true);                     //pour la taille de l'image
        setBombe(x,y,epaisseurPorte,epaisseurPorte); 
    }  

    // pour initilisé les champs de la potion 
    int xPotion = rand() % (dimxP - 3*epaisseurPorte - tailleJoueurX) + epaisseurPorte;
    int yPotion = rand() % (dimyP - 3*epaisseurPorte - tailleJoueurY) + epaisseurPorte;
    setContientPotion(true); 
    setPotion(xPotion,yPotion,epaisseurPorte,epaisseurPorte); 

}

void Piece::constructionType(int nb, int tailleXMonstre, int tailleYMonstre, int epaisseurPorte, int tailleJoueurX, int tailleJoueurY) 
{
    switch(type) 
    {
        case TYPE_1: // le joueur ne doit pas toucher la ou les barres qui sont en mouvement 
        {

            // initialisation des coordonnée de la barre 
            Pos centre(dimxP/2,dimyP/2);  
            barre.setCentre(centre); 

            Pos extrem(dimxP/4,dimyP/4); 
            barre.setExtremite(extrem); 

                        
            initVieEtBombeEtPotion(epaisseurPorte, tailleJoueurX, tailleJoueurY);
            
            break;

        }
        case TYPE_2: // le joueur doit sortie de la piece sans toucher les monstres
        {
            nbMonstre = nb; 
            for (int i=0; i<nb; i++)
            {
                int posX = rand() % (dimxP/2) + dimxP/4;
                int posY = rand() % (dimyP/2) + dimyP/4;
                
                tabMonstre[i].setPositionMonstre(posX,posY); 
                tabMonstre[i].setTailleXMonstre(tailleXMonstre);
                tabMonstre[i].setTailleYMonstre(tailleYMonstre);
            }

            initVieEtBombeEtPotion(epaisseurPorte, tailleJoueurX, tailleJoueurY);

            break;

        }
        case TYPE_3: // le joueur doit toucher le trésor pour finir la partie 
            
            setXTresor(dimxP/2); 
            setYTresor(dimyP/2); 
            setTailleXTresor(60); 
            setTailleYTresor(60); 

            break;
        
        case TYPE_4: // premiere salle, rien de spécial

            break;


        default:
            cout << "aucun type selectionné" << endl;
            break;
    }
}


int Piece::collisionsMurs(Pos p, int tailleX, int tailleY)
{
    bool valide = true;
    int i = 0;
    int px = p.getX();
    int py = p.getY();
    do
    {
        if  (((px <= (tabMur[i].getPosMur().getX() + tabMur[i].getTailleX())) && (px >= tabMur[i].getPosMur().getX()))
            && 
            ((py <= (tabMur[i].getPosMur().getY() + tabMur[i].getTailleY()))) && (py >= tabMur[i].getPosMur().getY()))

        {
            valide = false;
        }

        if  ((( (px+tailleX) <= (tabMur[i].getPosMur().getX() + tabMur[i].getTailleX())) && ((px+tailleX) >= tabMur[i].getPosMur().getX()))
            && 
            (((py+tailleY) <= (tabMur[i].getPosMur().getY() + tabMur[i].getTailleY()))) && ((py+tailleY) >= tabMur[i].getPosMur().getY()))
        
        {
            valide = false;
        }

        if  ((( (px+tailleX) <= (tabMur[i].getPosMur().getX() + tabMur[i].getTailleX())) && ((px+tailleX) >= tabMur[i].getPosMur().getX()))
            && 
            (((py) <= (tabMur[i].getPosMur().getY() + tabMur[i].getTailleY()))) && ((py) >= tabMur[i].getPosMur().getY()))
        
        {
            valide = false;
        }

        if  ((( (px) <= (tabMur[i].getPosMur().getX() + tabMur[i].getTailleX())) && ((px) >= tabMur[i].getPosMur().getX()))
            && 
            (((py+tailleY) <= (tabMur[i].getPosMur().getY() + tabMur[i].getTailleY()))) && ((py+tailleY) >= tabMur[i].getPosMur().getY()))
        
        {
            valide = false;
        }

        i++;
    }
    while ((valide)&&(i <= nbMur));

    if (valide)
    {
        return -1;
    }
    return i-1;
}

int Piece::collisionsPortes(Pos p, int tailleX, int tailleY)  
{
    bool valide = true;
    int i = 0;
    int px = p.getX();
    int py = p.getY();

    do
    {
        if  (((px <= (tabPorte[i].getPosPorte().getX() + tabPorte[i].getTailleX())) && (px >= tabPorte[i].getPosPorte().getX()))
            && 
            ((py <= (tabPorte[i].getPosPorte().getY() + tabPorte[i].getTailleY()))) && (py >= tabPorte[i].getPosPorte().getY()))

        {
            valide = false;
        }

        if  ((( (px+tailleX) <= (tabPorte[i].getPosPorte().getX() + tabPorte[i].getTailleX())) && ((px+tailleX) >= tabPorte[i].getPosPorte().getX()))
            && 
            (((py+tailleY) <= (tabPorte[i].getPosPorte().getY() + tabPorte[i].getTailleY()))) && ((py+tailleY) >= tabPorte[i].getPosPorte().getY()))
        
        {
            valide = false;
        }

        if  ((( (px+tailleX) <= (tabPorte[i].getPosPorte().getX() + tabPorte[i].getTailleX())) && ((px+tailleX) >= tabPorte[i].getPosPorte().getX()))
            && 
            (((py) <= (tabPorte[i].getPosPorte().getY() + tabPorte[i].getTailleY()))) && ((py) >= tabPorte[i].getPosPorte().getY()))
        
        {
            valide = false;
        }

        if  ((( (px) <= (tabPorte[i].getPosPorte().getX() + tabPorte[i].getTailleX())) && ((px) >= tabPorte[i].getPosPorte().getX()))
            && 
            (((py+tailleY) <= (tabPorte[i].getPosPorte().getY() + tabPorte[i].getTailleY()))) && ((py+tailleY) >= tabPorte[i].getPosPorte().getY()))
        
        {
            valide = false;
        }

        i++;
    }
    while ((valide)&&(i <= 3));

    if (valide)
    {
        return -1;
    }
    return i-1;

}

void Piece::supprimerUnMonstre(int indice)
{
    if (indice < 0 || indice >= 4)
    {
        cout << "indice du tableau de monstre pas valide " << endl;
        return;
    }

    tabMonstre[indice].setVieMonstre(false); 

    for (int i = indice; i < 3; i++) 
    {
        tabMonstre[i] = tabMonstre[i+1];
    }

    tabMonstre[3] = Monstre(); // cree un monstre par defaut 

}

void Piece::testRegressionPiece()
{
    cout<<endl; 
    cout<<"     test de regression de piece"<<endl; 

    Piece piece(10,200,TYPE_1, GRANDIR); 

    assert(piece.getDimXP()==10); 
    assert(piece.getDimYP()==200); 
    assert(piece.getType()==1); 

}


