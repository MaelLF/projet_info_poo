#include "piece.hpp"
#define MAX_RANGE 3
void Piece::convertXYtoChoiceRange(int i, int j,int* choice,int* range,int rangemax){
    int droite;
    int haut;
    if(abs(j-posy)!=abs(i-posx) && i-posx!=0 && j-posy != 0){ //si pas diagonale ou ligne
        printf("mauvais deplacement \n");
        *choice = -1; *range =0; 
        return;
    } 

    if(j-posy>0){
        droite = 1;
    }
    else if(j==posy){
        droite = 0;
    }
    else{
        droite = -1;
    }

    if(i-posx>0){
        haut = -1;
    }
    else if(i==posx){
        haut = 0;
    }
    else{
        haut = 1;
    }
    printf("%d %d \n",haut,droite);
    if (haut==1){
        switch (droite)
        {
        case 1:
            *choice = 1;
            *range = posx-i;
            break;
        case -1:
            *choice = 7;
            *range = posx-i;
            break;
        case 0:
            *choice=0;
            *range = posx-i;
            break;
        }
    }
    else if(haut==-1){
        switch (droite)
        {
        case 1:
            *choice = 3;
            *range = i-posx;
            break;
        case -1:
            *choice = 5;
            *range = i-posx;
            break;
        case 0:
            *choice=4;
            *range = i-posx;
            break;
        }
    }
    else if(haut==0){
        switch (droite)
        {
        case 1:
            *choice = 2;
            *range = j-posy;
            break;
        case -1:
            *choice = 6;
            *range = posy-j;
            break;
        case 0:
            *choice=-1;
            *range = 0;
            break;
        }
    }

    if(*range>rangemax){
        *choice = -1;
        *range = 0;
    }

}

void Piece::Reculer(int range, Playboard& pboard) {
    int newY = posy;
    int i =0;
    while (i<range && pboard.getStatus(posx,posy+1)!=0 && newY < pboard.getCols()-1 && newY >= 0) {
        posy = posy+1;
        newY = posy + 1;
        i++;
    }
    return;
}