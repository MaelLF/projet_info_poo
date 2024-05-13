#include "piece.hpp"

class Tour : public Piece{
    public :
        Tour(){name = "Tour";};
        Tour(int y, int x){name = "Tour"; posy=y;posx=x;};
        virtual void display(){std::cout << name << std::endl;};
        int deplacement(int choix, int range,Playboard& pboard)override;
};