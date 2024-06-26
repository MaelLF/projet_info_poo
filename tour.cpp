#include "tour.hpp"
#include <iostream>


int Tour::deplacement(int choix, int range, Playboard& pboard){
    switch (choix)
    {
    case 0 :
        for( int i=0;i<range+1;i++){
            if(!pboard.isValidCell(posx-i,posy) || !pboard.getCell(posx-i,posy).getStatus()){
                printf("deplacement pas fait");
                return 0;
            }
        }
            posx = posx-range;
            posy = posy;
            printf("deplacement en haut fait");
            return 1;

    case 2 :
        for( int i=0;i<range+1;i++){
            if(!pboard.isValidCell(posx,posy+i) || !pboard.getCell(posx,posy+i).getStatus()){
                printf("deplacement pas fait");
                return 0;
            }
        }
            posx = posx;
            posy = posy+range;
            printf("deplacement à droite fait");
            return 1;

    case 4 :
        for( int i=0;i<range+1;i++){
            if(!pboard.isValidCell(posx+i,posy) || !pboard.getCell(posx+i,posy).getStatus()){
                printf("deplacement pas fait");
                return 0;
            }
        }
            posx = posx+range;
            posy = posy;
            printf("deplacement en bas fait");
            return 1;
        

    case 6 :
        for( int i=0;i<range+1;i++){
            if(!pboard.isValidCell(posx,posy-i) || !pboard.getCell(posx,posy-i).getStatus()){
                printf("deplacement pas fait");
                return 0;
            }
        }
            posx = posx;
            posy = posy-range;
            printf("deplacement à gauche fait");
            return 1;
    }
    return 0;
}

void Tour::display(SFMLRenderer &renderer, int j){
    renderer.drawTour(*this, j);
}


int Tour::pouvoir(int dice_roll,int i, int j,Piece& piece_adverse, Playboard& pboard) {
    // Lancer d'un dé pour déterminer le pouvoir utilisé
    int choice;
    int range;
    //FONCTION MATTHIEU RÉCUP I et J
    // Pouvoir 1 : Avancer d'une case et faire reculer le joueur adverse d'une case 
    if (dice_roll == 1 || dice_roll == 3 || dice_roll == 5) {
        printf("Vous etes tombé sur %d, vous avancez 1 fois avec un range de 3 \n",dice_roll);
        this->convertXYtoChoiceRange (i,j,&choice,&range,3);
        if (this->deplacement(choice, range, pboard)) {
            return 1;  // Succès du pouvoir 1
        }
    }
    // Pouvoir 2 : Avancer d'une case et faire reculer le joueur adverse de 3 cases (tomber sur un nombre pair)
    else if (dice_roll == 2 || dice_roll == 4) {
        printf("Vous etes tombé sur %d, vous avancez 1 fois avec un range de 4 \n",dice_roll);
        this->convertXYtoChoiceRange (i,j,&choice,&range,4);
        if (this->deplacement(choice,range, pboard)) {
            return 2; // Succès du pouvoir 2
        }
    }
    // Pouvoir 3 : Avancer d'une case et faire reculer le joueur adverse de 5 cases (tomber sur 6)
    else if (dice_roll == 6) {
        printf("Vous etes tombé sur %d, vous avancez 1 fois avec un range de 5 \n",dice_roll);
        this->convertXYtoChoiceRange (i,j,&choice,&range,5);
        if (this->deplacement(choice,range, pboard)) {
            return 3; // Succès du pouvoir 3
        }
    }
    return 0; // Aucun pouvoir n'a été activé
}