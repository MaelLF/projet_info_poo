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
        std::shared_ptr<Piece> piPtr = std::make_shared<Pion>(0, 0);
        std::shared_ptr<Piece> piPtr2 = std::make_shared<Pion>(0, 0);

        // Creating players with their respective pieces
        joueur1 = Joueur("J1", piPtr);
        joueur2 = Joueur("J2", piPtr2);
        longueur = lon;
        largeur = lar;
        Playboard pboard(longueur,largeur);
        playboard = pboard;
        playboard.initPlayboard();
    }

    Joueur joueur1;  // First player
    Joueur joueur2;  // Second player
    Playboard playboard;
    int longueur;    // Length
    int largeur;     // Width
};

#endif // JEU_H
