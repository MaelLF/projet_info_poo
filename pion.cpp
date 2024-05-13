#include "pion.hpp"

int Pion::deplacement(Playboard& pboard){
    if(!pboard.isValidCell(posx,posy-1) && !pboard.getCell(posx,posy-1).getStatus()){
        return 0;
    }
    posx = posx-1;
    return 1;
}

int Pion::deplacement(int choix, int range ,Playboard& pboard){
    return this->deplacement(pboard);
}