#include <cassert>
#include <time.h>
#include <stdlib.h>

#include "JeuModeGraphique.h"

#include <iostream>
using namespace std; 


SDLSimple::SDLSimple (Jeu & j): jeu(j)
{

    
    // Initialisation de la SDL 
    if (SDL_Init(SDL_INIT_VIDEO) < 0) 
    {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    if (TTF_Init() != 0) {
        cout << "Erreur lors de l'initialisation de la SDL_ttf : " << TTF_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if( !(IMG_Init(imgFlags) & imgFlags)) 
    {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    //partie gerant le son 
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << endl;
        cout << "No sound !!!" << endl;
        //SDL_Quit();exit(1);
        withSound = false;
    }
    else withSound = true;

    // Creation de la fenetre
    window = SDL_CreateWindow("Jeu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, j.getPlateau().getPiece(0).getDimXP(), j.getPlateau().getPiece(0).getDimYP(), SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == nullptr) 
    {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; 
        SDL_Quit(); 
        exit(1);
    }
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED); 


    // IMAGES
    imPiece1.loadFromFile("data/image/piece.png",renderer);  
    imPiece2.loadFromFile("data/image/piece2.png",renderer);  
    imPiece3.loadFromFile("data/image/piece3.png",renderer);  
    imPieceDef.loadFromFile("data/image/pieceDef.png",renderer);  
    imMonstre.loadFromFile("data/image/imMonstre.png",renderer); 

    imJoueurBas.loadFromFile("data/image/joueurBas.png",renderer); 
    imJoueurHaut.loadFromFile("data/image/joueurHaut.png",renderer); 
    imJoueurDroite.loadFromFile("data/image/joueurDroite.png",renderer); 
    imJoueurGauche.loadFromFile("data/image/joueurGauche.png",renderer); 

    imEpeeHaut.loadFromFile("data/image/epeeHaut.png",renderer); 
    imEpeeBas.loadFromFile("data/image/epeeBas.png",renderer); 
    imEpeeDroite.loadFromFile("data/image/epeeDroite.png",renderer);  
    imEpeeGauche.loadFromFile("data/image/epeeGauche.png",renderer); 

    imEpee.loadFromFile("data/image/epee.png",renderer); 

    imTresorfermer.loadFromFile("data/image/imTresorFermer.png",renderer); 
    imTresorOuvert.loadFromFile("data/image/imTresorOuvert.png",renderer); 
    imTresorDecouvert.loadFromFile("data/image/imTresorTrouver.png",renderer); 

    imCoeur.loadFromFile("data/image/imCoeur.png",renderer); 
    imBombe.loadFromFile("data/image/imBombe.png",renderer); 
    imBombeAllumer.loadFromFile("data/image/imBombeAllumer.png",renderer); 
    imPotion.loadFromFile("data/image/imPotion.png",renderer); 

    imArmeDroite.loadFromFile("data/image/armeDroite.png",renderer); 
    imArmeHaut.loadFromFile("data/image/armeHaut.png",renderer); 
    imArmeGauche.loadFromFile("data/image/armeGauche.png",renderer); 
    imArmeBas.loadFromFile("data/image/armeBas.png",renderer); 

    imJoueurActuel = &imJoueurDroite; 


    // FONTS : charge une police TrueType nommée "DejaVuSansCondensed.ttf" avec une taille de 50 point
    
    font = TTF_OpenFont("data/dejavu-fonts-ttf-2.37/ttf/DejaVuSans-Bold.ttf",20);
    if (font == nullptr)
        font = TTF_OpenFont("../dejavu-fonts-ttf-2.37/ttf/DejaVuSans-Bold.ttf",20);
    if (font == nullptr) {
            cout << "Failed to load dejavu-fonts-ttf-2.37! SDL_TTF Error: " << TTF_GetError() << endl; 
            SDL_Quit(); 
            exit(1);
	}
	font_color.r = 0;font_color.g = 0;font_color.b = 0;


    //init son 
    
    if (withSound)
    {
        sounds[0] = Mix_LoadWAV("data/son/monstre.mp3");
        if (sounds[0] == nullptr) 
        {
            cout << "Failed to load monstre.mp3! SDL_mixer Error: " << Mix_GetError() << endl;
            SDL_Quit();
            exit(1);
        }

        sounds[1] = Mix_LoadWAV("data/son/bombe.mp3");
        if (sounds[1] == nullptr) 
        {
            cout << "Failed to load bombe.mp3! SDL_mixer Error: " << Mix_GetError() << endl;
            SDL_Quit();
            exit(1);
        }

        sounds[2] = Mix_LoadWAV("data/son/potion.mp3");
        if (sounds[2] == nullptr) 
        {
            cout << "Failed to load potion.mp3! SDL_mixer Error: " << Mix_GetError() << endl;
            SDL_Quit();
            exit(1);
        }

        sounds[3] = Mix_LoadWAV("data/son/vie.mp3");
        if (sounds[3] == nullptr) 
        {
            cout << "Failed to load vie.mp3! SDL_mixer Error: " << Mix_GetError() << endl;
            SDL_Quit();
            exit(1);
        }

        sounds[4] = Mix_LoadWAV("data/son/sonMenu.mp3");
        if (sounds[4] == nullptr) 
        {
            cout << "Failed to load sonMenu.mp3! SDL_mixer Error: " << Mix_GetError() << endl;
            SDL_Quit();
            exit(1);
        }

        sounds[5] = Mix_LoadWAV("data/son/epee.mp3");
        if (sounds[5] == nullptr) 
        {
            cout << "Failed to load epee.mp3! SDL_mixer Error: " << Mix_GetError() << endl;
            SDL_Quit();
            exit(1);
        }

        sounds[6] = Mix_LoadWAV("data/son/lancerArme.mp3");
        if (sounds[6] == nullptr) 
        {
            cout << "Failed to load lancerArme.mp3! SDL_mixer Error: " << Mix_GetError() << endl;
            SDL_Quit();
            exit(1);
        }

    }
    
}


SDLSimple::~SDLSimple () 
{
    if (withSound) Mix_Quit();

    for (int i = 0; i < 7; i++)
     {
        if (sounds[i] != nullptr) 
        {
            Mix_FreeChunk(sounds[i]);
            sounds[i] = nullptr;
        }
    }

    imJoueurActuel = nullptr;

    Mix_CloseAudio();
    TTF_CloseFont(font);
    TTF_Quit();
    imPiece1.~Image();
    imPiece2.~Image();
    imPiece3.~Image();
    imPieceDef.~Image();
    imMonstre.~Image();
    imJoueurBas.~Image();
    imJoueurHaut.~Image();
    imJoueurDroite.~Image();
    imJoueurGauche.~Image();
    imTresorfermer.~Image();
    imTresorOuvert.~Image();
    imTresorDecouvert.~Image();
    imCoeur.~Image();
    imBombe.~Image();
    imBombeAllumer.~Image();
    font_im.~Image();
    imPotion.~Image();
    imEpee.~Image();
    imEpeeHaut.~Image();
    imEpeeBas.~Image();
    imEpeeGauche.~Image();
    imEpeeDroite.~Image();
    imArmeDroite.~Image();
    imArmeGauche.~Image();
    imArmeHaut.~Image();
    imArmeBas.~Image();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


void SDLSimple::afficherPerso() 
{

    SDL_Texture* textureJoueur = imJoueurActuel->getTexture();
    const Uint8 transparant = 100;
    
    //met en transparant le joueur le temps qu'il est invincible 
    
    if (jeu.getJoueurJeu().estInvincible())
    {
        SDL_SetTextureAlphaMod(textureJoueur, transparant);
    }
    else
    {
        SDL_SetTextureAlphaMod(textureJoueur, 255);
    }
    
    // Dessiner la texture du joueur
    imJoueurActuel->draw(renderer, jeu.getJoueurJeu().getPositionJoueur().getX(), jeu.getJoueurJeu().getPositionJoueur().getY(),jeu.getJoueurJeu().getTailleX(),jeu.getJoueurJeu().getTailleY());

}

void SDLSimple::affichePorte() // fonctionne mais revoir les positions des portes 
{
    int num = jeu.getPieceActuelle(); 

    SDL_SetRenderDrawColor(renderer, 255, 250, 250, 255); 

    if (jeu.getPlateau().getPiece(num).getPorte(0).getExiste())  // bien dessiner porte haut
    {
        SDL_Rect rectHaut = {jeu.getPlateau().getPiece(num).getPorte(0).getPosPorte().getX(),
                             jeu.getPlateau().getPiece(num).getPorte(0).getPosPorte().getY(), 
                             jeu.getPlateau().getPiece(num).getPorte(0).getTailleX() , 
                             jeu.getPlateau().getPiece(num).getPorte(0).getTailleY()   }; 
        SDL_RenderFillRect(renderer, &rectHaut); 
    }

    if (jeu.getPlateau().getPiece(num).getPorte(1).getExiste()) // bien dessiner porte droite 
    {
        SDL_Rect rectDroit = { jeu.getPlateau().getPiece(num).getPorte(1).getPosPorte().getX(),
                               jeu.getPlateau().getPiece(num).getPorte(1).getPosPorte().getY(), 
                               jeu.getPlateau().getPiece(num).getPorte(1).getTailleX() ,
                               jeu.getPlateau().getPiece(num).getPorte(1).getTailleY() }; 
        SDL_RenderFillRect(renderer, &rectDroit);
    }

    if (jeu.getPlateau().getPiece(num).getPorte(2).getExiste()) //bien dessiner porte bas
    { 
        SDL_Rect rectBas = {  jeu.getPlateau().getPiece(num).getPorte(2).getPosPorte().getX(),
                              jeu.getPlateau().getPiece(num).getPorte(2).getPosPorte().getY(), 
                              jeu.getPlateau().getPiece(num).getPorte(2).getTailleX() ,
                              jeu.getPlateau().getPiece(num).getPorte(2).getTailleY() }; 
        SDL_RenderFillRect(renderer, &rectBas);
    }

    if (jeu.getPlateau().getPiece(num).getPorte(3).getExiste()) // bien dessiner 
    {
        SDL_Rect rectGauche = { jeu.getPlateau().getPiece(num).getPorte(3).getPosPorte().getX(),
                                jeu.getPlateau().getPiece(num).getPorte(3).getPosPorte().getY(), 
                                jeu.getPlateau().getPiece(num).getPorte(3).getTailleX() ,
                                jeu.getPlateau().getPiece(num).getPorte(3).getTailleY() }; 
        SDL_RenderFillRect(renderer, &rectGauche);
    }

    SDL_SetRenderDrawColor(renderer, 255, 100, 250, 255);
    for (int i = 0; i<jeu.getPlateau().getPiece(num).getNbMur() ; i++)
    {
        SDL_Rect rectMur = {jeu.getPlateau().getPiece(num).getMur(i).getPosMur().getX(),
                            jeu.getPlateau().getPiece(num).getMur(i).getPosMur().getY(),
                            jeu.getPlateau().getPiece(num).getMur(i).getTailleX(),
                            jeu.getPlateau().getPiece(num).getMur(i).getTailleY() };
        SDL_RenderFillRect(renderer, &rectMur);           
    }
}

void SDLSimple::afficherVieEtBombeEtPotionEtArme()
{
    // pour la vie 
    if (jeu.getPlateau().getPiece(jeu.getPieceActuelle()).getContientVie())
    {
        imCoeur.draw(renderer,jeu.getPlateau().getPiece(jeu.getPieceActuelle()).getElement().xElement,
                 jeu.getPlateau().getPiece(jeu.getPieceActuelle()).getElement().yElement,
                 jeu.getPlateau().getPiece(jeu.getPieceActuelle()).getElement().tailleXElement,
                 jeu.getPlateau().getPiece(jeu.getPieceActuelle()).getElement().tailleYElement); 
    }

    // pour la bombe 
    if (jeu.getPlateau().getPiece(jeu.getPieceActuelle()).getContientBombe())
    {
        imBombe.draw(renderer,jeu.getPlateau().getPiece(jeu.getPieceActuelle()).getBombe().xElement,
                                        jeu.getPlateau().getPiece(jeu.getPieceActuelle()).getBombe().yElement,
                                        jeu.getPlateau().getPiece(jeu.getPieceActuelle()).getBombe().tailleXElement,
                                        jeu.getPlateau().getPiece(jeu.getPieceActuelle()).getBombe().tailleYElement); 
    }

    // pour la bombe allumé
    if (jeu.contactBombeJoueur()) 
    {
        imBombeAllumer.draw(renderer,jeu.getPlateau().getPiece(jeu.getPieceActuelle()).getBombe().xElement,
                                        jeu.getPlateau().getPiece(jeu.getPieceActuelle()).getBombe().yElement,
                                        jeu.getPlateau().getPiece(jeu.getPieceActuelle()).getBombe().tailleXElement+20,
                                        jeu.getPlateau().getPiece(jeu.getPieceActuelle()).getBombe().tailleYElement+20); 
    }

    // pour la potion 
    if (jeu.getPlateau().getPiece(jeu.getPieceActuelle()).getContientPotion())
    {
        imPotion.draw(renderer,jeu.getPlateau().getPiece(jeu.getPieceActuelle()).getPotion().xElement,
                                        jeu.getPlateau().getPiece(jeu.getPieceActuelle()).getPotion().yElement,
                                        jeu.getPlateau().getPiece(jeu.getPieceActuelle()).getPotion().tailleXElement,
                                        jeu.getPlateau().getPiece(jeu.getPieceActuelle()).getPotion().tailleYElement); 
    }

    //pour l'affichage des armes     
    if (jeu.getJoueurJeu().getTabArme().size() > 0)
    {
        if (jeu.getJoueurJeu().getTabArme().back().getJoueurLancerArme())
        {
            if (jeu.getJoueurJeu().getTabArme().back().getDirectionArme()==0)
            {
                imArmeHaut.draw(renderer, jeu.getJoueurJeu().getTabArme().back().getPositionArme().getX(),
                                    jeu.getJoueurJeu().getTabArme().back().getPositionArme().getY(), 
                                    jeu.getJoueurJeu().getTabArme().back().getTailleXArme(), 
                                    jeu.getJoueurJeu().getTabArme().back().getTailleYArme()
                                    ); 
            }

            if (jeu.getJoueurJeu().getTabArme().back().getDirectionArme()==1)
            {
                imArmeDroite.draw(renderer, jeu.getJoueurJeu().getTabArme().back().getPositionArme().getX(),
                                    jeu.getJoueurJeu().getTabArme().back().getPositionArme().getY(), 
                                    jeu.getJoueurJeu().getTabArme().back().getTailleXArme(), 
                                    jeu.getJoueurJeu().getTabArme().back().getTailleYArme()
                                    ); 
            }

            if (jeu.getJoueurJeu().getTabArme().back().getDirectionArme()==2)
            {
                imArmeBas.draw(renderer, jeu.getJoueurJeu().getTabArme().back().getPositionArme().getX(),
                                    jeu.getJoueurJeu().getTabArme().back().getPositionArme().getY(), 
                                    jeu.getJoueurJeu().getTabArme().back().getTailleXArme(), 
                                    jeu.getJoueurJeu().getTabArme().back().getTailleYArme()
                                    ); 
            }

            if (jeu.getJoueurJeu().getTabArme().back().getDirectionArme()==3)
            {
                imArmeGauche.draw(renderer, jeu.getJoueurJeu().getTabArme().back().getPositionArme().getX(),
                                    jeu.getJoueurJeu().getTabArme().back().getPositionArme().getY(), 
                                    jeu.getJoueurJeu().getTabArme().back().getTailleXArme(), 
                                    jeu.getJoueurJeu().getTabArme().back().getTailleYArme()
                                    ); 
            }

        }
    }
}


void SDLSimple::affichePiece(int dim)
{
    int num = jeu.getPieceActuelle();
    

    switch(jeu.getPlateau().getPiece(num).getType())
    {
        case TYPE_1:

            imPiece1.draw(renderer,0,0,dim,dim); 

            SDL_RenderDrawLine(renderer,
                       jeu.getPlateau().getPiece(num).getObstacle().getExtremite().getX(), 
                       jeu.getPlateau().getPiece(num).getObstacle().getExtremite().getY(),
                       jeu.getPlateau().getPiece(num).getObstacle().getCentre().getX(),
                       jeu.getPlateau().getPiece(num).getObstacle().getCentre().getY());

            break;

        case TYPE_2:

            imPiece2.draw(renderer,0,0,dim,dim); 
            for (int i=0; i < 4; i++) 
            {
                if (jeu.getPlateau().getPiece(num).getMonstre(i).getVieMonstre())
                {
                    imMonstre.draw(renderer,
                               jeu.getPlateau().getPiece(num).getMonstre(i).getPositionMonstre().getX(),
                               jeu.getPlateau().getPiece(num).getMonstre(i).getPositionMonstre().getY(), 
                               jeu.getPlateau().getPiece(num).getMonstre(i).getTailleXMonstre(),
                               jeu.getPlateau().getPiece(num).getMonstre(i).getTailleYMonstre()); 

                }
            } 
            
            break;

        case TYPE_3:

            imPiece3.draw(renderer,0,0,dim,dim); 

            if (jeu.jeuGagner()) // si contact et monstre mort ====> probleme avec cette fonction 
            {
                imTresorOuvert.draw(renderer,jeu.getPlateau().getPiece(num).getXTresor(),
                                             jeu.getPlateau().getPiece(num).getYTresor(),
                                             jeu.getPlateau().getPiece(num).getTailleXTresor(),
                                             jeu.getPlateau().getPiece(num).getTailleYtresor()); 
            }
            else
            {
                imTresorfermer.draw(renderer,jeu.getPlateau().getPiece(num).getXTresor(),
                                         jeu.getPlateau().getPiece(num).getYTresor(),
                                         jeu.getPlateau().getPiece(num).getTailleXTresor(),
                                         jeu.getPlateau().getPiece(num).getTailleYtresor()); 
            }

            break;
        
        case TYPE_4:

            imPiece3.draw(renderer,0,0,dim,dim);

        default:
            break;
    }

    affichePorte(); 
    afficherVieEtBombeEtPotionEtArme(); 
}


void SDLSimple::sdlAff (int dim) 
{
	//Remplir l'écran de blanc
    SDL_SetRenderDrawColor(renderer, 230, 190, 50, 25);
    SDL_RenderClear(renderer);

    affichePiece(dim);  
    afficherPerso(); 
    afficherVie(); 
}

void SDLSimple::gameOvera(int dim)  
{
    if (jeu.gameOver())
    {   
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_Rect fond = {0,0,dim,dim};
        SDL_RenderFillRect(renderer, &fond);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            
        SDL_Color blanc = {255, 255, 255, 255};

        font_im.setSurface(TTF_RenderText_Solid(font, "DEFAITE", blanc));
        font_im.loadFromCurrentSurface(renderer);
        SDL_Rect perdu;
        perdu.x = (dim - 4*font_im.getWidth()) / 2;
        perdu.y = (dim - 2*font_im.getHeight()) / 2;
        perdu.w = 4*font_im.getWidth();
        perdu.h = 2*font_im.getHeight();
        SDL_RenderCopy(renderer, font_im.getTexture(), NULL, &perdu);

        SDL_RenderPresent(renderer);
        Uint32 finPerduF = SDL_GetTicks(),finPerduD;

        do
        {
            finPerduD = SDL_GetTicks();
        }
        while((finPerduD - finPerduF) < 2000);
    }   
}

void SDLSimple::afficherGagner(int dim)
{
    if (jeu.contactTresorJoueur())
    {   
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_Rect fond = {0,0,dim,dim};
        SDL_RenderFillRect(renderer, &fond);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            
        SDL_Color blanc = {255, 255, 255, 255};

        font_im.setSurface(TTF_RenderText_Solid(font, "VICTOIRE", blanc));
        font_im.loadFromCurrentSurface(renderer);
        SDL_Rect perdu;
        perdu.x = (dim - 4*font_im.getWidth()) / 2;
        perdu.y = (dim - 2*font_im.getHeight()) / 2;
        perdu.w = 4*font_im.getWidth();
        perdu.h = 2*font_im.getHeight();
        SDL_RenderCopy(renderer, font_im.getTexture(), NULL, &perdu);

        SDL_RenderPresent(renderer);

        Uint32 finGagnerF = SDL_GetTicks(),finGagnerD;
        
        do
        {
            finGagnerD = SDL_GetTicks();
        }
        while((finGagnerD - finGagnerF) < 2000);

    }  
}

void SDLSimple::update(int dimension, bool gestionInvincible, bool monstre0, bool monstre1, bool barreAuto)
{
    jeu.deplaAutoArme(); 
    jeu.mortMonstre(); 
    jeu.gestionVie(); 
    jeu.joueurBuPotion(); 
    jeu.changementDePiece(dimension);
    jeu.actionAutomatique(dimension,monstre0,monstre1,barreAuto); // gere le deplacement de la barre et des monstres 
    jeu.gestionInvincibilite(gestionInvincible);
}

void SDLSimple::son()
{
    if (withSound)
    {
        if (jeu.contactMonstreJoueur() || jeu.contactBarreJoueur()) 
        {
            Mix_PlayChannel(-1, sounds[0], 0);
        }

        if (jeu.contactBombeJoueur())
        {
            Mix_PlayChannel(-1, sounds[1], 0);
        }

        if (jeu.contactPotionJoueur())
        {
            Mix_PlayChannel(-1, sounds[2], 0);
        }
        
        if (jeu.contactVieJoueur()) 
        {
            Mix_PlayChannel(-1, sounds[3], 0);
        }

        if (jeu.getJoueurJeu().getBranditEpee() 
            || ((jeu.getJoueurJeu().getTabArme().size() > 0) && jeu.getJoueurJeu().getTabArme().back().getJoueurLancerArme()))
        {
            Mix_PlayChannel(-1, sounds[5], 0);
        }

    }
}

void SDLSimple::dessinerMenu(int choix, int dim)
{
            SDL_RenderClear(renderer);

            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_Rect fond = {0,0,dim,dim};
            SDL_RenderFillRect(renderer, &fond);

            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            
            
            SDL_Color blanc = {255, 255, 255, 255};


            font_im.setSurface(TTF_RenderText_Solid(font, "LABYRINTHE DU TRESOR", blanc));
            font_im.loadFromCurrentSurface(renderer);
            SDL_Rect nom;
            nom.x = (dim - 2*font_im.getWidth()) / 2;
            nom.y = (dim - 2*font_im.getHeight()) / 5;
            nom.w = 2*font_im.getWidth();
            nom.h = 2*font_im.getHeight();
            SDL_RenderCopy(renderer, font_im.getTexture(), NULL, &nom);


            font_im.setSurface(TTF_RenderText_Solid(font, "COMMENCER", blanc));
            font_im.loadFromCurrentSurface(renderer);
            SDL_Rect debut;
            debut.x = (dim - font_im.getWidth()) / 2;
            debut.y = 3*(dim - font_im.getHeight()) / 5;
            debut.w = font_im.getWidth();
            debut.h = font_im.getHeight();
            SDL_RenderCopy(renderer, font_im.getTexture(), NULL, &debut); 


            font_im.setSurface(TTF_RenderText_Solid(font, "QUITTER", blanc));
            font_im.loadFromCurrentSurface(renderer);
            SDL_Rect fin;
            fin.x = (dim - font_im.getWidth()) / 2 ; 
            fin.y = 4*(dim - font_im.getHeight()) / 5;  
            fin.w = font_im.getWidth();
            fin.h = font_im.getHeight();
            SDL_RenderCopy(renderer, font_im.getTexture(), NULL, &fin);


            font_im.setSurface(TTF_RenderText_Solid(font, ">", blanc));
            font_im.loadFromCurrentSurface(renderer);
            SDL_Rect curseur;
            curseur.w = font_im.getWidth();
            curseur.h = font_im.getHeight();
            if(choix == 0)
            {
                curseur.x = (dim - debut.w)/2 - 2*curseur.w;
                curseur.y = 3*(dim - font_im.getHeight()) / 5;
            }
            if(choix == 1)
            {
                curseur.x = (dim - fin.w)/2 - 2*curseur.w;
                curseur.y = 4*(dim - font_im.getHeight()) / 5;
            }
            
            SDL_RenderCopy(renderer, font_im.getTexture(), NULL, &curseur);

            SDL_RenderPresent(renderer);


}

void SDLSimple::afficherMenu(int dim)
{
    bool quit = false;
    SDL_Event events;
    bool jeuCommence = false;
    int choix = 0;
    bool debut = true;
    while (!quit)
    {
        while (SDL_PollEvent(&events))
        {
            if (events.type == SDL_QUIT)
            {
                quit = true;
            }
            else if (events.type == SDL_KEYDOWN)
            {
                switch (events.key.keysym.sym)
                {
                    case SDLK_RETURN :
                        ;

                    case SDLK_SPACE:
                       
                        switch(choix)
                        {
                            case 0 : jeuCommence = true; 
                                    break; // Commence la boucle de jeu
                        
                            case 1 : quit = true;

                        }
                        break;

                    case SDLK_s: ;

                    case SDLK_DOWN: 
                        if (choix != 1)
                        {
                            choix++;
                        }
                        
                        break;

                    case SDLK_z: ;

                    case SDLK_UP: 
                        if (choix != 0)
                        {
                            choix--;
                        }
                        break;

                    case SDLK_ESCAPE:
                        quit = true;
                        break; 
                }
            }
        }
    
        if (jeuCommence) // si entré dans le jeu et pas mort dans le jeu 
        {
            if (debut)
            {
                afficherDebut(dim);
                debut = false;
            }
            quit = sdlBoucle(dim);
            jeuCommence = false; // remettre à faux 
        }

        if (!jeuCommence)
        {
            dessinerMenu(choix, dim);
        }

       
    }
}

void SDLSimple::afficherDebut(int dim)
{
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_Rect fond = {0,0,dim,dim};
    SDL_RenderFillRect(renderer, &fond);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    
    
    SDL_Color blanc = {255, 255, 255, 255};

    font_im.setSurface(TTF_RenderText_Solid(font, "Dans ce jeu, vous incarnez un aventurier intrepide", blanc));
    font_im.loadFromCurrentSurface(renderer);
    SDL_Rect phrase1;
    phrase1.x = (dim - 0.6*font_im.getWidth()) / 2;
    phrase1.y = (dim - font_im.getHeight())/10 ;
    phrase1.w = 0.6*font_im.getWidth();
    phrase1.h = font_im.getHeight();
    SDL_RenderCopy(renderer, font_im.getTexture(), NULL, &phrase1);

    font_im.setSurface(TTF_RenderText_Solid(font, "qui doit explorer un vaste monde rempli de dangers et de mysteres.", blanc));
    font_im.loadFromCurrentSurface(renderer);
    SDL_Rect phrase2;
    phrase2.x = (dim - 0.6*font_im.getWidth()) / 2;
    phrase2.y = 2*(dim - font_im.getHeight())/10 ;
    phrase2.w = 0.6*font_im.getWidth();
    phrase2.h = font_im.getHeight();
    SDL_RenderCopy(renderer, font_im.getTexture(), NULL, &phrase2);

    font_im.setSurface(TTF_RenderText_Solid(font, "Chaque piece du labyrinthe offre des defis surmonter.", blanc));
    font_im.loadFromCurrentSurface(renderer);
    SDL_Rect phrase3;
    phrase3.x = (dim - 0.6*font_im.getWidth()) / 2;
    phrase3.y = 3*(dim - font_im.getHeight())/10 ;
    phrase3.w = 0.6*font_im.getWidth();
    phrase3.h = font_im.getHeight();
    SDL_RenderCopy(renderer, font_im.getTexture(), NULL, &phrase3);

    font_im.setSurface(TTF_RenderText_Solid(font, "Votre but ultime est de trouver le tresor legendaire", blanc));
    font_im.loadFromCurrentSurface(renderer);
    SDL_Rect phrase4;
    phrase4.x = (dim - 0.6*font_im.getWidth()) / 2;
    phrase4.y = 4*(dim - font_im.getHeight())/10 ;
    phrase4.w = 0.6*font_im.getWidth();
    phrase4.h = font_im.getHeight();
    SDL_RenderCopy(renderer, font_im.getTexture(), NULL, &phrase4);

    font_im.setSurface(TTF_RenderText_Solid(font, "qui se trouve quelque part dans le labyrinthe.", blanc));
    font_im.loadFromCurrentSurface(renderer);
    SDL_Rect phrase5;
    phrase5.x = (dim - 0.6*font_im.getWidth()) / 2;
    phrase5.y = 5*(dim - font_im.getHeight())/10 ;
    phrase5.w = 0.6*font_im.getWidth();
    phrase5.h = font_im.getHeight();
    SDL_RenderCopy(renderer, font_im.getTexture(), NULL, &phrase5);
     

    font_im.setSurface(TTF_RenderText_Solid(font, "Mais attention, les gardiens du tresor ne vous laisseront pas partir facilement !", blanc));
    font_im.loadFromCurrentSurface(renderer);
    SDL_Rect phrase6;
    phrase6.x = (dim - 0.6*font_im.getWidth()) / 2;
    phrase6.y = 6*(dim - font_im.getHeight())/10 ;
    phrase6.w = 0.6*font_im.getWidth();
    phrase6.h = font_im.getHeight();
    SDL_RenderCopy(renderer, font_im.getTexture(), NULL, &phrase6);

    

    font_im.setSurface(TTF_RenderText_Solid(font, "APPUYER SUR UNE TOUCHE POUR CONTINUER", blanc));
    font_im.loadFromCurrentSurface(renderer);
    SDL_Rect touche;
    touche.x = (dim - font_im.getWidth()) / 2;
    touche.y = (dim - 5*font_im.getHeight()) ;
    touche.w = font_im.getWidth();
    touche.h = font_im.getHeight();
    SDL_RenderCopy(renderer, font_im.getTexture(), NULL, &touche);


    SDL_RenderPresent(renderer);

    SDL_Event events;
    bool quit = false;

    while (!quit)
    {
        while (SDL_PollEvent(&events))
        {
            if (events.type == SDL_QUIT)
            {
                quit = true;
            }
            else 
            {
                if (events.type == SDL_KEYDOWN)
                {
                    quit = true;
                }
            }
        }
    }

}

bool SDLSimple::sdlBoucle (int dim) 
{
    SDL_Event events;
	bool quit = false;

    int pas = 15;

    bool autoMonstre0 = false, autoMonstre1 = false, autoBarre = false, gestInvincibilite = false;
    
    Uint32 tMonstre0 = SDL_GetTicks(), tMonstre1 = SDL_GetTicks(), tBarre = SDL_GetTicks(), tInvincibilite = SDL_GetTicks(), ntMonstre0, ntMonstre1, ntBarre, ntInvincibilite;
    
	// tant que ce n'est pas la fin ...
	while (!quit && !jeu.gameOver())
    {
        SDL_RenderClear(renderer); // efface l'ancien contenu  

        autoMonstre0 = false;
        autoMonstre1 = false;
        autoBarre = false;
        gestInvincibilite = false;
        ntMonstre0 = SDL_GetTicks();
        ntMonstre1 = SDL_GetTicks();
        ntBarre = SDL_GetTicks();
        ntInvincibilite = SDL_GetTicks();

        if (ntMonstre0-tMonstre0>200) {

            autoMonstre0 = true;
            tMonstre0 = ntMonstre0;
        }
        if (ntMonstre1-tMonstre1>30) {

            autoMonstre1 = true;
            tMonstre1 = ntMonstre1;
        }
        if (ntBarre-tBarre > 30)
        {

            autoBarre = true;
            tBarre = ntBarre;
        }
        if (ntInvincibilite-tInvincibilite > 1000)
        {
            gestInvincibilite = true;
            tInvincibilite = ntInvincibilite;
        }


        update(dim,gestInvincibilite,autoMonstre0,autoMonstre1,autoBarre); 


		// tant qu'il y a des évenements à traiter (cette boucle n'est pas bloquante)
		while (SDL_PollEvent(&events)) 
        {
			if (events.type == SDL_QUIT) 
            {
                quit = true;        // Si l'utilisateur a clique sur la croix de fermeture
            }

			else if (events.type == SDL_KEYDOWN)     // si touche enfonce
            {   
				switch (events.key.keysym.sym) 
                {
                    case SDLK_ESCAPE:
                        quit = true;
                        break;

                    case SDLK_z: ;

                    case SDLK_UP: 
                        jeu.actionClavier('z',pas,dim);  
                        imJoueurActuel = &imJoueurHaut;
                        break;

                    case SDLK_s: ;

                    case SDLK_DOWN: 
                        jeu.actionClavier('s',pas,dim);  
                        imJoueurActuel = &imJoueurBas;
                        break;

                    case SDLK_q: ;

                    case SDLK_LEFT: 
                        jeu.actionClavier('q',pas,dim); 
                        imJoueurActuel = &imJoueurGauche; 
                        break; 
                    
                    case SDLK_d: ;

                    case SDLK_RIGHT:     
                        jeu.actionClavier('d',pas,dim);  
                        imJoueurActuel = &imJoueurDroite;
                        break; 
  
                    case SDLK_o: 
                            jeu.deplacerEpee('o');
                            imJoueurActuel = &imEpeeHaut;
                             break; 
 
                    case SDLK_l: 
                            jeu.deplacerEpee('l'); 
                            imJoueurActuel = &imEpeeBas;
                            break; 
                     
                    case SDLK_k: 
                            jeu.deplacerEpee('k'); 
                            imJoueurActuel = &imEpeeGauche;
                            break; 

                    case SDLK_m: 
                            jeu.deplacerEpee('m'); 
                            imJoueurActuel = &imEpeeDroite;
                            break; 

                    case SDLK_j : 
                            if (jeu.getJoueurJeu().getTabArme().size() > 0)
                            {
                                jeu.actionClavier('j',pas,dim);
                                jeu.getJoueurJeu().getTabArme().back().setPositionArme(jeu.getJoueurJeu().getPositionJoueur()); // permet de mettre à jour la position du joueur 
                            }
                            
                            break; 



                    default: break;
				}
			}

            else if (events.type == SDL_KEYUP)   // Si  touche  relâché
            {
                switch (events.key.keysym.sym) 
                {
                    case SDLK_o:

                    case SDLK_l:

                    case SDLK_k:

                    case SDLK_m:
                        jeu.getJoueurJeu().setBranditEpee(false);
                        break;

                    case SDLK_z:
                        jeu.getJoueurJeu().setDirectionJoueur(0); 
                        break; 

                    case SDLK_s: 
                        jeu.getJoueurJeu().setDirectionJoueur(2); 
                        break; 

                    case SDLK_q:
                        jeu.getJoueurJeu().setDirectionJoueur(3); 
                        break; 

                    case SDLK_d:
                        jeu.getJoueurJeu().setDirectionJoueur(1); 
                        break; 

                    default:
                        break;
                }
            }

            son(); 
            
		}

		// on affiche le jeu sur le buffer caché 
		sdlAff(dim);
		// on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans la boucle)
        SDL_RenderPresent(renderer);

        if (jeu.arretJeu() == 1)
        {
            gameOvera(dim);
            return true;
        }
        if (jeu.arretJeu() == 2)
        {
            afficherGagner(dim);
            return true;
        }
	}
    return false;
}


void SDLSimple::afficherVie()
{  
    SDL_Color vert = {0, 255, 0, 255}; 

    // pour afficher le panneau 
    SDL_Color backgroundColor = { 245, 245, 220, 255 };
    SDL_Rect backgroundRect = { 35,35,180,50}; 
    SDL_SetRenderDrawColor(renderer, backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
    SDL_RenderFillRect(renderer, &backgroundRect);

    // pour afficher le nombre de coeur 
    int vie = jeu.getJoueurJeu().pointDeVie;
    imCoeur.draw(renderer,45,45,30,30); 

    font_im.setSurface(TTF_RenderText_Solid(font, std::to_string(vie).c_str(), vert));
    font_im.loadFromCurrentSurface(renderer);
    SDL_Rect textVie = { 85, 45, 30, 30 };
    SDL_RenderCopy(renderer, font_im.getTexture(), NULL, &textVie);

    // pour afficher le nombre d'arme 
    int nbArme = jeu.getJoueurJeu().getTabArme().size(); 
    imArmeBas.draw(renderer, 125, 45, 30, 30); 

    font_im.setSurface(TTF_RenderText_Solid(font, std::to_string(nbArme).c_str(), vert));
    font_im.loadFromCurrentSurface(renderer);
    SDL_Rect textNbArme = { 165, 45, 30, 30 };
    SDL_RenderCopy(renderer, font_im.getTexture(), NULL, &textNbArme);
}
