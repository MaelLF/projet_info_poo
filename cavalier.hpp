#ifndef CAVALIER_HPP
#define CAVALIER_HPP

#include "piece.hpp"
#include "playboard.hpp" // Assurez-vous d'inclure le fichier Playboard pour pouvoir utiliser la classe Playboard

class Cavalier : public Piece {
public:
    Cavalier() { name = "Cavalier"; }
    Cavalier(int x, int y) { name = "Cavalier"; posx = x; posy = y; }   

    // Méthode pour déplacer le Cavalier
    int deplacement(int choix, Playboard& board);

private:
    // Méthode pour vérifier si le déplacement est valide pour un Cavalier
    bool isValidMove(int newX, int newY) const;
};

#endif // CAVALIER_HPP
