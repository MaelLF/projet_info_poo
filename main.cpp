#include "cell.hpp"
#include "cavalier.hpp"
#include "reine.hpp"
#include "pion.hpp"
#include "fou.hpp"
#include "tour.hpp"
#include "joueur.hpp"
#include "emptycell.hpp"
#include "obstaclecell.hpp"
#include "duelcell.hpp"
#include "playboard.hpp"
#include <iostream>
#include <memory> // Pour std::shared_ptr

int main() {
    // Création des objets nécessaires
    Cell cellule;
    Piece piece;
    Fou fou(2, 2); // Crée un Fou avec une position (2, 2)
    Playboard plateau(5, 10);

    // Création d'un joueur avec une pièce (Fou) enveloppée dans std::shared_ptr
    std::shared_ptr<Piece> fouPtr = std::make_shared<Fou>(2, 2); // Crée un Fou avec une position (2, 2)
    Joueur joueur1("mathieu", fouPtr); // Déplace le Fou dans un std::shared_ptr et le passe au Joueur
    joueur1.display(); // Affiche les détails du joueur et de sa pièce

    // Déplacement de la pièce du joueur
    if (joueur1.my_piece) {
        joueur1.my_piece->deplacement(0, 1, plateau); // Appel de la méthode deplacement() sur la pièce du joueur
        joueur1.display(); // Affiche les détails mis à jour du joueur et de sa pièce
        plateau.printBoard(); // Affiche l'état du plateau après le déplacement
    }

    Playboard plateau(8,20);
    plateau.initPlayboard();
    plateau.printBoard();
    
    return 0;
}

