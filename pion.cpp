#include "pion.hpp"

int Pion::deplacement(int choix ,Playboard& pboard){
    if (choix==1){
    if(!pboard.isValidCell(posx,posy-1) || !pboard.getCell(posx,posy-1).getStatus()){
        printf("déplacement pas possible \n");
        return 0;
    }
    posy = posy-1;
    return 1;
    }
    else{
        return 0;
    }
}

int Pion::deplacement(int choix, int range ,Playboard& pboard){
    return this->deplacement(choix,pboard);
}

void Pion::convertXYtoChoiceRange(int i, int j,int* choice,int* range){
    if (this->posx==i && this->posy-1==j){
        *choice=1;
        *range= 0;
    }
    else{
        *choice=0;
        *range= 0;
    }
}

void Pion::display(SFMLRenderer &renderer, int j){
    renderer.drawPion(*this, j);
}

