#include "piece.hpp"

class Pion : public Piece{
    public :
        Pion(){ name = "Pion";};
        Pion(int y, int x){name = "Pion"; posx=x;posy=y;};
        // virtual void display(){std::cout << name << std::endl;};
        int deplacement(Playboard& pboard)override;
        int deplacement(int choix,int range,Playboard& pboard)override;
};