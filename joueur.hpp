#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <iostream>
#include <memory> // Pour std::shared_ptr
#include "piece.hpp"

class Joueur {
public:
    Joueur(){ name ="default";}
    Joueur(const std::string& nom, std::shared_ptr<Piece> piece) : name(nom), my_piece(piece) {}

    std::string name;
    std::shared_ptr<Piece> my_piece;

    void display() const {
        if (my_piece) {
            std::cout << "Joueur : " << name << " Piece : " << my_piece->getname() 
                      << " Position actuelle: x:" << my_piece->posx << " y:" << my_piece->posy << std::endl;
        } else {
            std::cout << "Joueur : " << name << " Aucune pièce assignée" << std::endl;
        }
    }
};
#endif
