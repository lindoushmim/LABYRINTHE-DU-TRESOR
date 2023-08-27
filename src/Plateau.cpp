
#include "Plateau.h"
#include <cassert>

using namespace std;

Plateau::Plateau()
{
    dimx = 0;
    dimy = 0; 
    tabPiece = nullptr; 
    salleFin = 0; 
    
} 

Plateau::Plateau(int x, int y, int dimensionPiece)
{
    dimx = x;
    dimy = y;
    tabPiece = new Piece [dimx*dimy];
    initPiece(dimensionPiece,0,0,0,0,0,0); 
    salleFin=0; 
    
}

Plateau::Plateau(const Plateau &pla)
{
    dimx = pla.getDimx();
    dimy = pla.getDimy();
    tabPiece = pla.getTab();
}

Plateau::~Plateau()
{
    delete [] tabPiece;
}

void Plateau::initPlateau(int x, int y)
{
    dimx = x;
    dimy = y;
    tabPiece = new Piece[x*y];
}

int Plateau::getDimx() const
{
    return dimx;
}

int Plateau::getDimy() const
{
    return dimy;
}


void Plateau::setDimx(int x)
{
    dimx = x; 
}

void Plateau::setDimy(int y)
{
    dimy = y; 
}

Piece * Plateau::getTab() const
{
    return tabPiece; 
}

void Plateau::setTab(Piece * p)
{
    if (tabPiece != nullptr)
    {
        delete [] tabPiece;
    }
    tabPiece = p;
}

void Plateau::setPiece(Piece * piece, int i, int j) 
{
   
    *(tabPiece + j*dimx+i) = *piece; // besoin de déréférencer pour accéder à la case et mettre la piece à laquelle le pointeur piece pointe.
}

int Plateau::getSalleFin()
{
    return salleFin;
}

void Plateau::setSalleFin(int num)
{
    salleFin = num;
}


void Plateau::initPiece(int dimensionPiece, int longueurPorte, int epaisseurPorte, int tailleXMonstre, int tailleYMonstre, int tailleJoueurX, int tailleJoueurY)  
{        
    TypePiece typeP; 
    TypePotion typePo; 
    int typeAlea;
    int typeAleaPotion; 
    int salleFinX;
    int salleFinY ;

    salleFinX = rand()%dimx;
    if (salleFinX<(dimx+1)/2)
    {
        salleFinY = rand()%((dimy)/2)+((dimy+1)/2);
    }
    else
    {
        salleFinY = rand()%dimy;
    }   

    salleFin = salleFinY*dimx + salleFinX; // On choisit aléatoirement en premier quelle sera la salle du trésor
    

    for (int i = 0; i<dimx; i++)
    {
        for (int j = 0; j<dimy; j++)
        {
            // met un type de potion aléatoirement 

            typeAleaPotion = rand() % 3; 

            switch (typeAleaPotion)
            {
                case 0: 
                    typePo = GRANDIR; 
                    break; 

                case 1: 
                    typePo = RETRECIR; 
                    break; 

                case 2: 
                    typePo = GAGNER_INVICIBILITE; 
                    break; 
            }


            // met un type de piece aléatoirement 
            if ((j*dimx+i) == salleFin)     // si l'itération actuelle concerne la salle du trésor
            {
                typeP = TYPE_3;
            }
            else
            {
                if ((j*dimx+i) == 0)
                {
                    typeP = TYPE_4;
                }
                else
                {
                    typeAlea = 1 + rand() % 2; // nb aléatoire entre 1 et 2 
                
                    switch(typeAlea)
                    {
                        case 1: 
                            typeP = TYPE_1;  
                            break; 
                        
                        case 2: 
                            typeP = TYPE_2; 
                            break; 

                        default:
                            typeP = TYPE_1;
                            break; 
                    }    
                }
            }
            tabPiece[j*dimx+i] = Piece(dimensionPiece, dimensionPiece, typeP, typePo);
            tabPiece[j*dimx+i].constructionType(4, tailleXMonstre, tailleYMonstre, epaisseurPorte,tailleJoueurX,tailleJoueurY); 
            


                         // PORTES


            if (i>0)                    //GAUCHE
            {
                tabPiece[j*dimx+i].getPorte(3).setExiste(true); 
                tabPiece[j*dimx+i].getPorte(3).setTailleX(epaisseurPorte);
                tabPiece[j*dimx+i].getPorte(3).setTailleY(longueurPorte); 
                Pos p(0, dimensionPiece/2 - tabPiece[j*dimx+i].getPorte(3).getTailleY()/2);
                tabPiece[j*dimx+i].getPorte(3).setPosPorte(p);
            }
            if (i<(dimx-1))             //DROITE
            {
                tabPiece[j*dimx+i].getPorte(1).setExiste(true);
                tabPiece[j*dimx+i].getPorte(1).setTailleX(epaisseurPorte);
                tabPiece[j*dimx+i].getPorte(1).setTailleY(longueurPorte);
                Pos p(dimensionPiece-tabPiece[j*dimx+i].getPorte(1).getTailleX(), dimensionPiece/2-tabPiece[j*dimx+i].getPorte(1).getTailleY()/2);
                tabPiece[j*dimx+i].getPorte(1).setPosPorte(p);
            }
            if (j>0)                    //HAUT
            {
                tabPiece[j*dimx+i].getPorte(0).setExiste(true);
                tabPiece[j*dimx+i].getPorte(0).setTailleX(longueurPorte);
                tabPiece[j*dimx+i].getPorte(0).setTailleY(epaisseurPorte);
                Pos p(dimensionPiece/2 - tabPiece[j*dimx+i].getPorte(0).getTailleX()/2,0);
                tabPiece[j*dimx+i].getPorte(0).setPosPorte(p);
            }
            if (j<(dimy-1))             //BAS
            {
                tabPiece[j*dimx+i].getPorte(2).setExiste(true);
                tabPiece[j*dimx+i].getPorte(2).setTailleX(longueurPorte);
                tabPiece[j*dimx+i].getPorte(2).setTailleY(epaisseurPorte);
                Pos p(dimensionPiece/2 - tabPiece[j*dimx+i].getPorte(2).getTailleX()/2 , dimensionPiece-tabPiece[j*dimx+i].getPorte(2).getTailleY());
                tabPiece[j*dimx+i].getPorte(2).setPosPorte(p);
            }



                            //MURS

            int indice = 0;
                                    // COTE GAUCHE
            if (tabPiece[j*dimx+i].getPorte(3).getExiste())     
            {
                tabPiece[j*dimx+i].getMur(indice).initMur(0,
                                                          epaisseurPorte,
                                                          epaisseurPorte,
                                                          tabPiece[j*dimx+i].getPorte(3).getPosPorte().getY() -epaisseurPorte -1
                                                          );
                indice++;
                tabPiece[j*dimx+i].getMur(indice).initMur(0,
                                                          tabPiece[j*dimx+i].getPorte(3).getPosPorte().getY() +longueurPorte + 1,
                                                          epaisseurPorte,
                                                          dimensionPiece - (tabPiece[j*dimx+i].getPorte(3).getPosPorte().getY() +longueurPorte + 1)
                                                          );
                indice++;
            }
            else
            {
                tabPiece[j*dimx+i].getMur(indice).initMur(0,    
                                                          epaisseurPorte,
                                                          epaisseurPorte,
                                                          dimensionPiece - epaisseurPorte
                                                          );
                indice++;
            }


                                    // COTE BAS
            if (tabPiece[j*dimx+i].getPorte(2).getExiste())     
            {
                tabPiece[j*dimx+i].getMur(indice).initMur(epaisseurPorte,
                                                          dimensionPiece - epaisseurPorte,
                                                          tabPiece[j*dimx+i].getPorte(2).getPosPorte().getX() -epaisseurPorte -1,
                                                          epaisseurPorte
                                                          );
                indice++;
                tabPiece[j*dimx+i].getMur(indice).initMur(tabPiece[j*dimx+i].getPorte(2).getPosPorte().getX() + longueurPorte + 1,
                                                          dimensionPiece - epaisseurPorte,
                                                          dimensionPiece - (tabPiece[j*dimx+i].getPorte(2).getPosPorte().getX() + longueurPorte + 1),
                                                          epaisseurPorte
                                                          );
                indice++;
            }
            else
            {
                tabPiece[j*dimx+i].getMur(indice).initMur(epaisseurPorte,    
                                                          dimensionPiece - epaisseurPorte,
                                                          dimensionPiece - epaisseurPorte,
                                                          epaisseurPorte
                                                          );
                indice++;
            }

                                    // COTE DROIT
            if (tabPiece[j*dimx+i].getPorte(1).getExiste())     
            {
                tabPiece[j*dimx+i].getMur(indice).initMur(dimensionPiece - epaisseurPorte,
                                                          tabPiece[j*dimx+i].getPorte(1).getPosPorte().getY() + longueurPorte + 1,
                                                          epaisseurPorte,
                                                          dimensionPiece -(tabPiece[j*dimx+i].getPorte(1).getPosPorte().getY() + longueurPorte + 1)
                                                          );
                indice++;
                tabPiece[j*dimx+i].getMur(indice).initMur(dimensionPiece - epaisseurPorte,
                                                          epaisseurPorte,
                                                          epaisseurPorte,
                                                          tabPiece[j*dimx+i].getPorte(1).getPosPorte().getY() - epaisseurPorte - 1
                                                          );
                indice++;
            }
            else
            {
                tabPiece[j*dimx+i].getMur(indice).initMur(dimensionPiece - epaisseurPorte,    
                                                          epaisseurPorte,
                                                          epaisseurPorte,
                                                          dimensionPiece - epaisseurPorte
                                                          );
                indice++;
            }
            

                                    // COTE HAUT
            if (tabPiece[j*dimx+i].getPorte(0).getExiste())     
            {
                tabPiece[j*dimx+i].getMur(indice).initMur(0,
                                                          0,
                                                          tabPiece[j*dimx+i].getPorte(0).getPosPorte().getX() - 1,
                                                          epaisseurPorte
                                                          );
                indice++;
                tabPiece[j*dimx+i].getMur(indice).initMur(tabPiece[j*dimx+i].getPorte(0).getPosPorte().getX() + longueurPorte + 1,
                                                          0,
                                                          dimensionPiece - (tabPiece[j*dimx+i].getPorte(0).getPosPorte().getX() + longueurPorte + 1),
                                                          epaisseurPorte
                                                          );
                indice++;
            }
            else
            {
                tabPiece[j*dimx+i].getMur(indice).initMur(0,    
                                                          0,
                                                          dimensionPiece,
                                                          epaisseurPorte
                                                          );
                indice++;
            }

            tabPiece[j*dimx+i].setNbMur(indice);
            /*
                    SCHEMA D'UNE PIECE AVEC SES 4 PORTES

                X  MUR7          P0           MUR6  X

                M                                   M
                U                                   U
                R                                   R
                0                                   5

                P                                   P
                3                                   1
            
                M                                   M
                U                                   U
                R                                   R
                1                                   4

                X  MUR2          P2           MUR3  X
            


                    SCHEMA DE LA PREMIERE PIECE

                X            MUR5                   X

                                                    M
                                                    U
                                                    R
                                                    4
                M
                U                                   P
                R                                   1
                0
                                                    M
                                                    U
                                                    R
                                                    3

                X  MUR1         P2            MUR2  X

                Les Murs ont une épaisseur de la meme taille qu'une porte
                Quand un coté n'a pas de porte, il y a un seul mur qui fait la taille du coté
                les murs aux emplacement des X ne sont pas necessaire 
            */
        }
    }
}



Piece & Plateau::getPiece(int numero) const 
{
    return tabPiece[numero];
}

void Plateau::testRegressionPlateau()
{
    Plateau vide; 
    assert(vide.getDimx()==0); 
    assert(vide.getDimy()==0); 
    assert(vide.getSalleFin()==0); 
    assert(vide.getTab()==nullptr); 

    vide.setDimx(90); 
    vide.setDimy(88); 
    assert(vide.getDimx()==90); 
    assert(vide.getDimy()==88); 


    Plateau pla(2,2,30); 
    assert(pla.getDimx()==2); 
    assert(pla.getDimy()==2); 
    assert(pla.getSalleFin()==0); 
    assert(pla.getTab()!=nullptr); 

    // verifie les porte

    assert(pla.tabPiece[0].getPorte(0).getExiste()==0); 
    assert(pla.tabPiece[0].getPorte(1).getExiste()==1); 
    assert(pla.tabPiece[0].getPorte(2).getExiste()==1); 
    assert(pla.tabPiece[0].getPorte(3).getExiste()==0); 

    assert(pla.tabPiece[1].getPorte(0).getExiste()==0); 
    assert(pla.tabPiece[1].getPorte(1).getExiste()==0); 
    assert(pla.tabPiece[1].getPorte(2).getExiste()==1); 
    assert(pla.tabPiece[1].getPorte(3).getExiste()==1); 

    assert(pla.tabPiece[2].getPorte(0).getExiste()==1); 
    assert(pla.tabPiece[2].getPorte(1).getExiste()==1); 
    assert(pla.tabPiece[2].getPorte(2).getExiste()==0); 
    assert(pla.tabPiece[2].getPorte(3).getExiste()==0); 

    assert(pla.tabPiece[3].getPorte(0).getExiste()==1); 
    assert(pla.tabPiece[3].getPorte(1).getExiste()==0); 
    assert(pla.tabPiece[3].getPorte(2).getExiste()==0); 
    assert(pla.tabPiece[3].getPorte(3).getExiste()==1); 

}



