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
    Cell cellule;
    cellule.display();
    Piece piece;
    piece.display();
    Fou fou(1,2);
    fou.display();
    Joueur joueur1("mathieu",fou);
    joueur1.display();
}