#ifndef CAVALIER_HPP
#define CAVALIER_HPP

#include "piece.hpp"
#include "playboard.hpp" // Assurez-vous d'inclure le fichier Playboard pour pouvoir utiliser la classe Playboard

class Cavalier : public Piece {
public:
    Cavalier() { name = "Cavalier"; }
    Cavalier(int y, int x) { name = "Cavalier"; posy = y; posx = x; }   

    // Méthode pour déplacer le Cavalier
    int deplacement(int choix, Playboard& board);
    int deplacement(int choix, int range, Playboard& pboard);

    int pouvoir (int pouvoir, int choix,int range, Playboard& board);

};

#endif // CAVALIER_HPP
