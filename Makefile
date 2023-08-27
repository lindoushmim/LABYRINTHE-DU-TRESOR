SDL = -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer
SDL2 = -I/usr/include/SDL2
CPP = g++ -g -ggdb

all: bin/test bin/affichageSDL bin/affichage

bin/test: obj/main.o obj/Pos.o obj/Monstre.o obj/Piece.o obj/Joueur.o obj/Plateau.o obj/Jeu.o obj/Porte.o obj/Mur.o obj/Obstacle.o obj/Arme.o
	$(CPP) -o bin/test obj/main.o obj/Pos.o obj/Monstre.o obj/Piece.o obj/Joueur.o obj/Plateau.o obj/Jeu.o obj/Porte.o obj/Mur.o obj/Obstacle.o obj/Arme.o

bin/affichage: obj/mainTexte.o obj/Pos.o obj/Monstre.o obj/Piece.o obj/Joueur.o obj/Plateau.o obj/Jeu.o obj/winTxt.o obj/JeuModeTexte.o obj/Porte.o obj/Mur.o obj/Obstacle.o obj/Arme.o
	$(CPP) -o bin/affichage obj/mainTexte.o obj/Pos.o obj/Monstre.o obj/Piece.o obj/Joueur.o obj/Plateau.o obj/Jeu.o obj/winTxt.o obj/JeuModeTexte.o obj/Porte.o obj/Mur.o obj/Obstacle.o obj/Arme.o

bin/affichageSDL: obj/mainSDL.o obj/Pos.o obj/Monstre.o obj/Piece.o obj/Joueur.o obj/Plateau.o obj/Jeu.o obj/Image.o obj/JeuModeGraphique.o obj/Porte.o obj/Mur.o obj/Obstacle.o obj/Arme.o
	$(CPP) -o bin/affichageSDL obj/mainSDL.o obj/Pos.o obj/Monstre.o obj/Piece.o obj/Joueur.o obj/Plateau.o obj/Jeu.o obj/Image.o obj/JeuModeGraphique.o obj/Porte.o obj/Mur.o obj/Obstacle.o obj/Arme.o $(SDL)

obj/mainTexte.o: src/mainTexte.cpp
	$(CPP) -Wall -c  src/mainTexte.cpp -o obj/mainTexte.o 

obj/main.o: src/main.cpp
	$(CPP) -Wall -c  src/main.cpp -o obj/main.o 

obj/mainSDL.o: src/mainSDL.cpp 
	$(CPP) -Wall -c  src/mainSDL.cpp -o obj/mainSDL.o 

obj/JeuModeGraphique.o: src/JeuModeGraphique.cpp src/JeuModeGraphique.h
	$(CPP) -Wall -c  src/JeuModeGraphique.cpp -o obj/JeuModeGraphique.o $(SDL2)

obj/JeuModeTexte.o: src/JeuModeTexte.cpp src/JeuModeTexte.h 
	$(CPP) -Wall -c  src/JeuModeTexte.cpp -o obj/JeuModeTexte.o 

obj/Image.o: src/Image.cpp src/Image.h 
	$(CPP) -Wall -c  src/Image.cpp -o obj/Image.o $(SDL2)

obj/winTxt.o: src/winTxt.cpp src/winTxt.h 
	$(CPP) -Wall -c  src/winTxt.cpp -o obj/winTxt.o 

obj/Jeu.o: src/Jeu.cpp src/Jeu.h 
	$(CPP) -Wall -c  src/Jeu.cpp -o obj/Jeu.o 

obj/Plateau.o: src/Plateau.cpp src/Plateau.h
	$(CPP) -Wall -c  src/Plateau.cpp -o obj/Plateau.o 

obj/Piece.o: src/Piece.cpp src/Piece.h
	$(CPP) -Wall -c  src/Piece.cpp -o obj/Piece.o 

obj/Joueur.o: src/Joueur.cpp src/Joueur.h 
	$(CPP) -Wall -c  src/Joueur.cpp -o obj/Joueur.o 

obj/Monstre.o: src/Monstre.cpp src/Monstre.h 
	$(CPP) -Wall -c  src/Monstre.cpp -o obj/Monstre.o 

obj/Pos.o: src/Pos.cpp src/Pos.h 
	$(CPP) -Wall -c  src/Pos.cpp -o obj/Pos.o 

obj/Porte.o: src/Porte.cpp src/Porte.h
	$(CPP) -Wall -c  src/Porte.cpp -o obj/Porte.o

obj/Mur.o: src/Mur.cpp src/Mur.h
	$(CPP) -Wall -c  src/Mur.cpp -o obj/Mur.o

obj/Obstacle.o: src/Obstacle.cpp src/Obstacle.h
	$(CPP) -Wall -c  src/Obstacle.cpp -o obj/Obstacle.o

obj/Arme.o: src/Arme.cpp src/Arme.h
	$(CPP) -Wall -c  src/Arme.cpp -o obj/Arme.o

clean: 
	rm obj/*.o 

veryclean: 
	rm bin/* 
	
dox:
	doxygen ./doc/jeu.doxy
