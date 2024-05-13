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
    plateau.initPlayboard();

    // Création d'un joueur avec une pièce (Fou) enveloppée dans std::shared_ptr
    std::shared_ptr<Piece> fouPtr = std::make_shared<Fou>(2, 2); // Crée un Fou avec une position (2, 2)
    Joueur joueur1("mathieu", fouPtr); // Déplace le Fou dans un std::shared_ptr et le passe au Joueur
    std::shared_ptr<Piece> piPtr = std::make_shared<Pion>(0,0);
    Joueur joueur2("victor", piPtr);
    
    joueur1.display(); // Affiche les détails du joueur et de sa pièce
    // Ajouter des joueurs au vecteur
    printf("est ce que 2 ,2 est occupée %d \n",plateau.isoccupied(2,2,joueur1));
    plateau.printBoard(joueur1,joueur2);
    // Déplacement de la pièce du joueur
    if (joueur1.my_piece) {
        joueur1.my_piece->deplacement(0, 1, plateau); // Appel de la méthode deplacement() sur la pièce du joueur
        joueur1.display(); // Affiche les détails mis à jour du joueur et de sa pièce
        plateau.printBoard(joueur1,joueur2);
        std::shared_ptr<Piece> pionPtr = std::make_shared<Pion>(fouPtr->posx,fouPtr->posy);
        joueur1.my_piece = pionPtr;

        joueur1.my_piece->deplacement(0,0,plateau);
        joueur1.display();
        plateau.printBoard(joueur1,joueur2);

        std::shared_ptr<Piece> cavalierPtr = std::make_shared<Cavalier>(joueur1.my_piece->posx,joueur1.my_piece->posy);
        joueur1.my_piece = cavalierPtr;

        
        joueur1.my_piece->deplacement(3,0,plateau);
        joueur1.display();
        plateau.printBoard(joueur1,joueur2); // Affiche l'état du plateau après le déplacement
    }
/*
    Playboard plateau(8,20);
    plateau.initPlayboard();
    plateau.printBoard();
    */
    return 0;
}

