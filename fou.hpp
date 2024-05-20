#include "piece.hpp"
#ifndef fou_H
#define fou_H
class Fou : public Piece{
    public :
        Fou(){
            name = "Fou";
        }
        Fou(int x, int y){name = "Fou"; posx=x;posy=y;};
        int deplacement(int choix, int range,Playboard& pboard)override;
        void display(SFMLRenderer &renderer, int j) override;
        int pouvoir(int i, int j, Piece& piece_adverse, Playboard& pboard)override;
};
#endif