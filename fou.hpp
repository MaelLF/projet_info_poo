#include "piece.hpp"
class Fou : public Piece{
    public :
        Fou(){
            name = "Fou";
        }
        Fou(int y, int x){name = "Fou"; posy=y; posx=x;};
        int deplacement(int choix, int range,Playboard& pboard)override;
};