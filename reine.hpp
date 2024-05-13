#include "piece.hpp"

class Reine: public Piece{
    public :
        Reine(){name = "Reine";};
        Reine(int y, int x){name = "Reine"; posy=y;posx=x;};
        virtual void display(){std::cout << name << std::endl;};
        int deplacement(int choix, int range,Playboard& pboard)override;
};