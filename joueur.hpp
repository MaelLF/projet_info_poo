#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <iostream>
#include <memory> // Pour std::shared_ptr
#include "piece.hpp"
#include "pion.hpp"
#include "cavalier.hpp"
#include "reine.hpp"
#include "fou.hpp"
#include "tour.hpp"

class Joueur {
public:
    Joueur(){ name ="default"; point = 0;}
    Joueur(const std::string& nom, std::shared_ptr<Piece> piece) : name(nom), my_piece(piece) {}

    std::string name;
    std::shared_ptr<Piece> my_piece;
    int point;
    void print() const {
        if (my_piece) {
            std::cout << "Joueur : " << name << " Piece : " << my_piece->getname() 
                      << " Position actuelle: x:" << my_piece->posx << " y:" << my_piece->posy << std::endl;
        } else {
            std::cout << "Joueur : " << name << " Aucune pièce assignée" << std::endl;
        }
    }
    void changerpiece(int piecename) {
        std::shared_ptr<Piece> new_piece;

        switch (piecename) {
            case 1:
                new_piece = std::make_shared<Pion>(my_piece->posx, my_piece->posy);
                printf("piece changé pour un pion \n");
                break;
            
            case 2:
                new_piece = std::make_shared<Cavalier>(my_piece->posx, my_piece->posy);
                printf("piece changé pour un Cavalier \n");
                break;

            case 3:
                new_piece = std::make_shared<Tour>(my_piece->posx, my_piece->posy);
                printf("piece changé pour une Tour \n");
                break;

            case 4:
                new_piece = std::make_shared<Fou>(my_piece->posx, my_piece->posy);
                printf("piece changé pour un Fou \n");
                break;

            case 5:
                if (this->point>=3){
                new_piece = std::make_shared<Reine>(my_piece->posx, my_piece->posy);
                this->point = this->point-3; 
                break;
                }
                printf("Vous n'avez pas les points pour faire cette action \n");
                break;
            
            default :
                break;
        }

        if (new_piece) {
            my_piece = new_piece;
        }
    }

};
#endif
