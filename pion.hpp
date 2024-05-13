#include "piece.hpp"

class Pion : public Piece{
    public :
        Pion(){ name = "Pion";};
        Pion(int y, int x){name = "Pion";posy=y;posx=x;};
        virtual void display(){std::cout << name << std::endl;};
        int deplacement(Playboard& pboard)override{}
};