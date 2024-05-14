#include "piece.hpp"

class Tour : public Piece{
    public :
        Tour(){name = "Tour";};
        Tour(int x, int y){name = "Tour"; posx=x;posy=y;};
        void print()override{std::cout << name << std::endl;};
        int deplacement(int choix, int range,Playboard& pboard)override;
};