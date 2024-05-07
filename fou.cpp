#include "playboard.hpp"
#include "fou.hpp"

int Fou::deplacement(int choix,int range,Playboard& pboard){
    switch (choix)
    {
    case 0 :
        for( int i=0;i<range+1;i++){
            if(!pboard.isValidCell(posx-i,posy-1) && !pboard.getCell(posx-i,posy-i).getStatus()){
                return 0;
            }
            posx = posx-i;
            posy = posy-i;
            return 1;
        }

    case 1 :
        for( int i=0;i<range+1;i++){
            if(!pboard.isValidCell(posx+i,posy-1) && !pboard.getCell(posx+i,posy-i).getStatus()){
                return 0;
            }
            posx = posx+i;
            posy = posy-i;
            return 1;
        }

    case 2 :
        for( int i=0;i<range+1;i++){
            if(!pboard.isValidCell(posx+i,posy+1) && !pboard.getCell(posx+i,posy+i).getStatus()){
                return 0;
            }
            posx = posx+i;
            posy = posy+i;
            return 1;
        }

    case 3 :
        for( int i=0;i<range+1;i++){
            if(!pboard.isValidCell(posx-i,posy+1) && !pboard.getCell(posx-i,posy+i).getStatus()){
                return 0;
            }
            posx = posx-i;
            posy = posy+i;
            return 1;
        }
    }
}