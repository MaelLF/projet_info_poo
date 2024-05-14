#include "tour.hpp"
#include <iostream>


int Tour::deplacement(int choix, int range, Playboard& pboard){
    switch (choix)
    {
    case 0 :
        for( int i=0;i<range+1;i++){
            if(!pboard.isValidCell(posx,posy-i) || !pboard.getCell(posx,posy-i).getStatus()){
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
            if(!pboard.isValidCell(posx+i,posy) || !pboard.getCell(posx+i,posy).getStatus()){
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
            if(!pboard.isValidCell(posx,posy+i) || !pboard.getCell(posx,posy+i).getStatus()){
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
            if(!pboard.isValidCell(posx-i,posy) || !pboard.getCell(posx-i,posy).getStatus()){
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

