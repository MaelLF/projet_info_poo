#include "reine.hpp"
#include <iostream>

Reine::Reine(){
    name = "Reine";
}

Reine::Reine(int x, int y){
    name = "Reine";
    posx = x;
    posy = y;
}

int Reine ::deplacement(int choix, int range,Playboard& pboard){
    switch (choix)
    {
    case 0 :
        for( int i=0;i<range+1;i++){
            if(!pboard.isValidCell(posx,posy-i) && !pboard.getCell(posx,posy-i).getStatus()){
                printf("deplacement pas fait");
                return 0;
            }
        }
            posx = posx;
            posy = posy-range;
            printf("deplacement en haut fait");
            return 1;

    case 1 :
        for( int i=0;i<range+1;i++){
            if(!pboard.isValidCell(posx+i,posy-i) && !pboard.getCell(posx+i,posy-i).getStatus()){
                printf("deplacement pas fait");
                return 0;
            }
            posx = posx+range;
            posy = posy-range;
            printf("deplacement en haut à droite fait");
            return 1;
        }

    case 2 :
        for( int i=0;i<range+1;i++){
            if(!pboard.isValidCell(posx+i,posy) && !pboard.getCell(posx+i,posy).getStatus()){
                printf("deplacement pas fait");
                return 0;
            }
        }
            posx = posx+range;
            posy = posy;
            printf("deplacement à droite fait");
            return 1;
    
    case 3 :
        for( int i=0;i<range+1;i++){
            if(!pboard.isValidCell(posx+i,posy+i) && !pboard.getCell(posx+i,posy+i).getStatus()){
                printf("deplacement pas fait");
                return 0;
            }
        }
            posx = posx+range;
            posy = posy+range;
            printf("deplacement en bas à droite fait");
            return 1;

    case 4 :
        for( int i=0;i<range+1;i++){
            if(!pboard.isValidCell(posx,posy+i) && !pboard.getCell(posx,posy+i).getStatus()){
                printf("deplacement pas fait");
                return 0;
            }
            posx = posx;
            posy = posy+range;
            printf("deplacement en bas fait");
            return 1;
        }

    case 5 :
        for( int i=0;i<range+1;i++){
            if(!pboard.isValidCell(posx-i,posy+i) && !pboard.getCell(posx-i,posy+i).getStatus()){
                printf("deplacement pas fait");
                return 0;
            }
        }
            posx = posx-range;
            posy = posy+range;
            printf("deplacement en bas à gauche fait");
            return 1;

    case 6 :
        for( int i=0;i<range+1;i++){
            if(!pboard.isValidCell(posx-i,posy) && !pboard.getCell(posx-i,posy).getStatus()){
                printf("deplacement pas fait");
                return 0;
            }
        }
            posx = posx-range;
            posy = posy;
            printf("deplacement à gauche fait");
            return 1;

    case 7 :
        for( int i=0;i<range+1;i++){
            if(!pboard.isValidCell(posx-i,posy-i) && !pboard.getCell(posx-i,posy-i).getStatus()){
                printf("deplacement pas fait");
                return 0;
            }
        }
            posx = posx-range;
            posy = posy-range;
            printf("deplacement en haut à gauche fait");
            return 1;
        }
    return 0;
}