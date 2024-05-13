#include "playboard.hpp"
#include "fou.hpp"

int Fou::deplacement(int choix,int range,Playboard& pboard){
    switch (choix)
    {
    case 1 :
        for( int i=0;i<range+1;i++){
            if(!pboard.isValidCell(posx+i,posy-i) || !pboard.getCell(posx+i,posy-i).getStatus()){
                return 0;
            }
            posx = posx+range;
            posy = posy-range;
            printf("deplacement en haut a droite fait");
            return 1;
        }

    case 3 :
        for( int i=0;i<range+1;i++){
            if(!pboard.isValidCell(posx+i,posy+i) || !pboard.getCell(posx+i,posy+i).getStatus()){
                return 0;
            }
        }
            posx = posx+range;
            posy = posy+range;
            printf("deplacement en bas a droite fait");
            return 1;

    case 5 :
        for( int i=0;i<range+1;i++){
            if(!pboard.isValidCell(posx-i,posy+i) || !pboard.getCell(posx-i,posy+i).getStatus()){
                return 0;
            }
        }
            posx = posx-range;
            posy = posy+range;
            printf("deplacement en bas a gauche fait");
            return 1;
    
    case 7 :
        for( int i=0;i<range+1;i++){
            if(!pboard.isValidCell(posx-i,posy-i) || !pboard.getCell(posx-i,posy-i).getStatus()){
                printf("deplacement pas fait");
                return 0;
            }
        }
            posx = posx-range;
            posy = posy-range;
            printf("deplacement en haut a gauche fait");
            return 1;

    }
    return 0;
}