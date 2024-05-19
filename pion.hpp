#include "piece.hpp"
#ifndef pion_H
#define pion_H
class Pion : public Piece{
    public :
        Pion(){ name = "Pion";};
        Pion(int x, int y){name = "Pion"; posx=x;posy=y;};
        void print()override{std::cout << name << std::endl;};
        int deplacement(int choix,Playboard& pboard)override;
        int deplacement(int choix, int range ,Playboard& pboard)override;
        void convertXYtoChoiceRange(int i, int j,int* choice,int* range)override;
        void display(SFMLRenderer &renderer, int j) override;
        int pouvoir(int i, int j, Piece& piece_adverse, Playboard& pboard)override;
};
#endif