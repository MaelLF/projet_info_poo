#include "piece.hpp"

#ifndef Reine_H
#define Reine_H
class Reine: public Piece{
    public :
        Reine(){name = "Reine";};
        Reine(int x, int y){name = "Reine"; posy=y;posx=x;};
        int deplacement(int choix, int range,Playboard& pboard)override;

};

#endif