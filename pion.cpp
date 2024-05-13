#include "pion.hpp"

int Pion::deplacement(Playboard& pboard){
    if(!pboard.isValidCell(posy-1, posx) || !pboard.getCell(posy-1, posx).getStatus()){
        return 0;
    }
    posy = posy-1;
    return 1;
}

int Pion::deplacement(int choix, int range ,Playboard& pboard){
    return this->deplacement(pboard);
}