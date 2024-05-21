#include <iostream>
#include <memory>
#include "playboard.hpp"
#include "joueur.hpp"
#include "pion.hpp"
#ifndef JEU_H
#define JEU_H
class Jeu {
public:
    Jeu(int lon, int lar) {
        // Creating shared pointers for pieces
        std::shared_ptr<Piece> piPtr = std::make_shared<Pion>(lon/2, lar-1);
        std::shared_ptr<Piece> piPtr2 = std::make_shared<Pion>((lon/2)-1, lar-1);

        // Creating players with their respective pieces
        joueur1 = Joueur("J1", piPtr);
        joueur2 = Joueur("J2", piPtr2);
        longueur = lon;
        largeur = lar;
        tourJ1 = true;
        tourJ2 = false;
        clickButton = false;
        startGame = true;
        endGame = false;
        nbTours = 0;
        dice = 0;
        Playboard pboard(longueur,largeur);
        playboard = pboard;
        playboard.initPlayboard();
    }
    void tour(sf::Vector2i posCell);
    void recompense(int res);
    Joueur joueur1;  // First player
    Joueur joueur2;  // Second player
    Playboard playboard;
    int longueur;    // Length
    int largeur;     // Width
    bool tourJ1, tourJ2, clickButton, startGame, endGame;
    int nbTours;
    int dice;
};

#endif // JEU_H
