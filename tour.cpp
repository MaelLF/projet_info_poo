#include "tour.hpp"
#include <iostream>

Tour::Tour(){
    name = "Tour";
}

Tour::Tour(int y, int x){
    name = "Tour";
    posy = y;
    posx = x;
}

int Tour::deplacement(int choix, int range, Playboard& pboard){
    switch (choix)
    {
    case 0 :
        for( int i=0;i<range+1;i++){
            if(!pboard.isValidCell(posy-i,posx) || !pboard.getCell(posy-i,posx).getStatus()){
                printf("deplacement pas fait");
                return 0;
            }
        }
            posx = posx;
            posy = posy-range;
            printf("deplacement en haut fait");
            return 1;

    case 2 :
        for( int i=0;i<range+1;i++){
            if(!pboard.isValidCell(posy,posx+i) || !pboard.getCell(posy,posx+i).getStatus()){
                printf("deplacement pas fait");
                return 0;
            }
        }
            posx = posx+range;
            posy = posy;
            printf("deplacement à droite fait");
            return 1;

    case 4 :
        for( int i=0;i<range+1;i++){
            if(!pboard.isValidCell(posy+i,posx) || !pboard.getCell(posy+i,posx).getStatus()){
                printf("deplacement pas fait");
                return 0;
            }
            posx = posx;
            posy = posy+range;
            printf("deplacement en bas fait");
            return 1;
        }

    case 6 :
        for( int i=0;i<range+1;i++){
            if(!pboard.isValidCell(posy, posx-i) || !pboard.getCell(posy, posx-i).getStatus()){
                printf("deplacement pas fait");
                return 0;
            }
        }
            posx = posx-range;
            posy = posy;
            printf("deplacement à gauche fait");
            return 1;
    }
    return 0;
}

