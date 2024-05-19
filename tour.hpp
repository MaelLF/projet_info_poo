#include "piece.hpp"
#ifndef Tour_H
#define Tour_H
class Tour : public Piece{
    public :
        Tour(){name = "Tour";};
        Tour(int x, int y){name = "Tour";posx=x;posy=y;};
        int deplacement(int choix, int range,Playboard& pboard)override;
        void display(SFMLRenderer &renderer, int j) override;
};
#endif