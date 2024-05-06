#include "cavalier.hpp"
#include <iostream>

Cavalier::Cavalier() {
    name = "Cavalier";
}

Cavalier::Cavalier(int x, int y) {
    name = "Cavalier";
    posx = x;
    posy = y;
}

int Cavalier::deplacement(int newX, int newY, Playboard& board) {
    // Vérifier si le déplacement est valide pour un Cavalier
    if (isValidMove(newX, newY)) {
        // Déplacer le Cavalier
        posx = newX;
        posy = newY;
        // Mettre à jour la position sur le plateau
        board.setCell(newX, newY, 'C'); // 'C' pour Cavalier par exemple
    } else {
        std::cout << "Déplacement invalide pour un Cavalier !" << std::endl;
    }
}

bool Cavalier::isValidMove(int newX, int newY) const {
    int dx = abs(newX - posx);
    int dy = abs(newY - posy);
    // Vérifier si le déplacement correspond à l'un des 8 mouvements possibles pour un Cavalier
    return (dx == 1 && dy == 2) || (dx == 2 && dy == 1);
}
