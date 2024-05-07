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

int main(){
    //Case
    Cell cellule;
    cellule.display();

    //Piece
    Piece piece;
    piece.display();

    //Fou
    Fou fou(1,2);
    fou.display();

    //Joueur
    Joueur joueur1("mathieu",fou);
    joueur1.display();

    Playboard plateau(8,20);
    plateau.printBoard();
}