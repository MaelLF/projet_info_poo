#include "pion.hpp"

int Pion::deplacement(Playboard& pboard){
    if(!pboard.isValidCell(posx-1,posy) || !pboard.getCell(posx-1,posy).getStatus()){
        printf("déplacement pas possible \n");
        return 0;
    }
    posx = posx-1;
    return 1;
}

int Pion::deplacement(int choix, int range ,Playboard& pboard){
    return this->deplacement(pboard);
}