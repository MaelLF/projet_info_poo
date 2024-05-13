#include "piece.hpp"

class Pion : public Piece{
    public :
        Pion(){ name = "Pion";};
        Pion(int x, int y){name = "Pion"; posx=x;posy=y;};
        // virtual void display(){std::cout << name << std::endl;};
        int deplacement(Playboard& pboard)override;
};