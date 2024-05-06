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

int Cavalier::deplacement(int choix, Playboard& board) {
    switch (choix) {
        case 1:
            // 2 haut 1 gauche : Actions à effectuer si choix est égal à 1
            int newX = posx - 1 ;
            int newY = posy - 2 ;
            if (isValidMove(newX, newY)) {
                posx = newX ;
                posy = newY ;
            }
            std::cout << "2 haut 1 gauche" << std::endl;
            break;

        case 2:
            // 2 haut 1 droite : Actions à effectuer si choix est égal à 2
            int newX = posx + 1 ;
            int newY = posy - 2 ;
            if (isValidMove(newX, newY)) {
                posx = newX ;
                posy = newY ;
            }
            std::cout << "2 haut 1 droite" << std::endl;
            break;

        case 3:
            // 2 droite 1 haut : Actions à effectuer si choix est égal à 3
            int newX = posx + 2 ;
            int newY = posy - 1 ;
            if (isValidMove(newX, newY)) {
                posx = newX ;
                posy = newY ;
            }
            std::cout << "2 droite 1 haut" << std::endl;
            break;

        case 4:
            // Actions à effectuer si choix est égal à 3

            std::cout << "2 droite 1 bas" << std::endl;
            break;
        
        case 5:
            // Actions à effectuer si choix est égal à 3
            std::cout << "2 bas 1 droite" << std::endl;
            break;
        
        case 6:
            // Actions à effectuer si choix est égal à 3
            std::cout << "2 bas 1 gauche" << std::endl;
            break;

        case 7:
            // Actions à effectuer si choix est égal à 3
            std::cout << "2 gauche 1 bas " << std::endl;
            break;
        
        case 8:
            // Actions à effectuer si choix est égal à 3
            std::cout << "2 gauche 1 haut " << std::endl;
            break;

        default:
            // Actions à effectuer si choix n'est égal à aucune des valeurs précédentes
            std::cout << "Choix par défaut" << std::endl;
    }

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
