#include "piece.hpp"
class Joueur{
    public :
        Joueur(std::string nom, Piece piece){ name =nom; my_piece = piece;};
        std::string name;
        Piece my_piece;
        void display(){std::cout << "Joueur : " << name << " Piece : " << my_piece.getname() << " Position actuelle: " << " x:" << my_piece.posx << " y:"<< my_piece.posy<< std::endl;}
        void changepiece(Piece piece){my_piece = piece;}
};