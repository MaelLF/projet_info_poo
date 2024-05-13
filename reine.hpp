#include "piece.hpp"

class Reine: public Piece{
    public :
        Reine(){name = "Reine";};
        Reine(int x, int y){name = "Reine"; posx=x;posy=y;};
        virtual void display(){std::cout << name << std::endl;};
        int deplacement(int choix, int range,Playboard& pboard)override;

};