#include "piece.hpp"
#ifndef pion_H
#define pion_H
class Pion : public Piece{
    public :
        Pion(){ name = "Pion";};
        Pion(int x, int y){name = "Pion"; posx=x;posy=y;};
        virtual void display(){std::cout << name << std::endl;};
        int deplacement(Playboard& pboard)override;
        int deplacement(int choix, int range ,Playboard& pboard)override;
};
#endif