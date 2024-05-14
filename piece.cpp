#include "piece.hpp"

void Piece::convertXYtoChoiceRange(int i, int j,int* choice,int* range){
    int droite;
    int haut;
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
        case 0:
            *choice=0;
            *range = posx-i;
        
        default : 
            *choice =-1;
            *range = 0;
        }
    }
    else if(haut==-1){
        switch (droite)
        {
        case 1:
            *choice = 3;
            *range = posx-i;
            break;
        case -1:
            *choice = 5;
            *range = posx-i;
        case 0:
            *choice=4;
            *range = posx-i;
        
        default : 
            *choice =-1;
            *range = 0;
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
        case 0:
            *choice=-1;
            *range = 0;
        
        default : 
            *choice =-1;
            *range = 0;
        }
    }

}