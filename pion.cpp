#include "pion.hpp"

int Pion::deplacement(Playboard& pboard){
    if(!pboard.isValidCell(posx,posy-1) || !pboard.getCell(posx,posy-1).getStatus()){
        printf("déplacement pas possible \n");
        return 0;
    }
    posy = posy-1;
    return 1;
}

int Pion::deplacement(int choix, int range ,Playboard& pboard){
    return this->deplacement(pboard);
}

void Pion::convertXYtoChoiceRange(int i, int j,int* choice,int* range){
    *choice=0;
    *range= 0;
}