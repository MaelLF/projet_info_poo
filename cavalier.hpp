#include "piece.hpp"
#ifndef CAVALIER_HPP
#define CAVALIER_HPP

#include "playboard.hpp" // Assurez-vous d'inclure le fichier Playboard pour pouvoir utiliser la classe Playboard

class Cavalier : public Piece {
public:
    Cavalier() { name = "Cavalier"; }
    Cavalier(int x, int y) { name = "Cavalier"; posx = x; posy = y; }   

    // Méthode pour déplacer le Cavalier
    int deplacement(int choix, Playboard& board)override;
    int deplacement(int choix, int range, Playboard& pboard)override;

    int pouvoir (int choix, Playboard& board);
    void convertXYtoChoiceRange(int i, int j,int* choice,int* range)override;
    void display(SFMLRenderer &renderer, int j) override;
    int pouvoir(Piece& piece_adverse, Playboard& pboard)override;

};

#endif // CAVALIER_HPP
