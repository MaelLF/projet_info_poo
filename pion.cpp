#include "pion.hpp"

int Pion::deplacement(Playboard& pboard){
    if(!pboard.isValidCell(posx,posy-1) && !pboard.getCell(posx,posy-1).getstatus()){
        return 0;
    }
    posy = posy+1;
    return 1;
}