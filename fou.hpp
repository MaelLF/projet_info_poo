#include "piece.hpp"
class Fou : public Piece{
    public :
        Fou(){
            name = "Fou";
        };
        Fou(int x, int y){name = "Fou"; posx=x;posy=y;};
        int deplacement(int choix, int range,Playboard& pboard)override;
};