#include "cavalier.hpp"
#include <iostream>


int Cavalier::deplacement(int choix, Playboard& pboard) {
    int newX, newY;
    switch (choix) {
        case 0:
            // 2 gauche 1 haut : Actions à effectuer si choix est égal à 0
            newX = posx - 2 ;
            newY = posy - 1 ;
            if (!pboard.isValidCell(newX,newY) || !pboard.getCell(newX,newY).getStatus()) {
                printf("deplacement pas fait");
                return 0;   
            }
            else{
                posx = newX ;
                posy = newY ;
                std::cout << "2 gauche 1 haut" << std::endl;
                return 1 ;
            }
        case 1:
            // 2 gauche 1 bas : Actions à effectuer si choix est égal à 1
            newX = posx - 2 ;
            newY = posy + 1 ;
            if (!pboard.isValidCell(newX,newY) || !pboard.getCell(newX,newY).getStatus()) {
                printf("deplacement pas fait");
                return 0;   
            }
            else{
                posx = newX ;
                posy = newY ;
                std::cout << "2 gauche 1 bas" << std::endl;
                return 1 ;
            }

        case 2:
            // 2 bas 1 gauche : Actions à effectuer si choix est égal à 2
            newX = posx - 1 ;
            newY = posy + 2 ;
            if (!pboard.isValidCell(newX,newY) || !pboard.getCell(newX,newY).getStatus()) {
                printf("deplacement pas fait");
                return 0;   
            }
            else{
                posx = newX ;
                posy = newY ;
                std::cout << "2 bas 1 gauche" << std::endl;
                return 1 ;
            }


        case 3:
            // 2 bas 1 droite : Actions à effectuer si choix est égal à 3
            newX = posx + 1 ;
            newY = posy + 2 ;
            if (!pboard.isValidCell(newX,newY) || !pboard.getCell(newX,newY).getStatus()) {
                printf("deplacement pas fait");
                return 0;   
            }
            else{
                posx = newX ;
                posy = newY ;
                std::cout << "2 bas 1 droite" << std::endl;
                return 1 ;
            }


        case 4:
            // Actions à effectuer si choix est égal à 4
            newX = posx + 2 ;
            newY = posy + 1 ;
             if (!pboard.isValidCell(newX,newY) || !pboard.getCell(newX,newY).getStatus()) {
                printf("deplacement pas fait");
                return 0;   
            }
            else{
                posx = newX ;
                posy = newY ;
                std::cout << "2 droite 1 bas" << std::endl;
                return 1 ;
            }


        case 5:
            // Actions à effectuer si choix est égal à 5
            newX = posx + 2 ;
            newY = posy - 1 ;
            if (!pboard.isValidCell(newX,newY) || !pboard.getCell(newX,newY).getStatus()) {
                printf("deplacement pas fait");
                return 0;   
            }
            else{
                posx = newX ;
                posy = newY ;
                std::cout << "2 droite 1 haut" << std::endl;
                return 1 ;
            }


        case 6:
            // Actions à effectuer si choix est égal à 6
            newX = posx + 1 ;
            newY = posy - 2 ;
            if (!pboard.isValidCell(newX,newY) || !pboard.getCell(newX,newY).getStatus()) {
                printf("deplacement pas fait");
                return 0;   
            }
            else{
                posx = newX ;
                posy = newY ;
                std::cout << "2 gauche 1 bas" << std::endl;
                return 1 ;
            }

        
        case 7:
            // Actions à effectuer si choix est égal à 7
            newX = posx - 1 ;
            newY = posy - 2 ;
               if (!pboard.isValidCell(newX,newY) || !pboard.getCell(newX,newY).getStatus()) {
                printf("deplacement pas fait");
                return 0;   
            }
            else{
                posx = newX ;
                posy = newY ;
                std::cout << "2 gauche 1 haute" << std::endl;
                return 1 ;
            }


        default:
            // Actions à effectuer si choix n'est égal à aucune des valeurs précédentes
            std::cout << "Déplacement invalide pour un Cavalier !" << std::endl;
            return 0;
    }
}


int Cavalier::deplacement(int choix,int range, Playboard& pboard) {
    return this->deplacement(choix,pboard);
}

int Cavalier::pouvoir (int choix, Playboard& pboard){
    return 0;
}

void Cavalier::display(SFMLRenderer &renderer, int j){
    renderer.drawCavalier(*this, j);
}

void Cavalier::convertXYtoChoiceRange(int i, int j,int* choice,int* range){
    *range =0;
    if (this->posx-1==i && this->posy-2==j){
        *choice=0;
        return;
    }
    if (this->posx+1==i && this->posy-2==j){
        *choice=1;
        return;
    }
    if (this->posx-1==i && this->posy+2==j){
        *choice=5;
        return;
    }
    if (this->posx+1==i && this->posy+2==j){
        *choice=4;
        return;
    }
    if (this->posx-2==i && this->posy-1==j){
        *choice=7;
        return;
    }
    if (this->posx-2==i && this->posy+1==j){
        *choice=6;
        return;
    }
    if (this->posx+2==i && this->posy-1==j){
        *choice=2;
        return;
    }
    if (this->posx+2==i && this->posy+1==j){
        *choice=3;
        return;
    }
    *choice = -1;
}


int Cavalier::pouvoir(int i, int j,Piece& piece_adverse, Playboard& pboard) {
    // Lancer d'un dé pour déterminer le pouvoir utilisé
    int dice_roll = std::rand() % 6 + 1;
    int choice;
    int range;
    //FONCTION MATTHIEU RÉCUP I et J
    // Pouvoir 1 : Avancer d'une case et faire reculer le joueur adverse d'une case 
    if (dice_roll == 1 || dice_roll == 3 || dice_roll == 5) {
        this->convertXYtoChoiceRange (i,j,&choice,&range);
        if (this->deplacement(choice, pboard)) {
            return 1;  // Succès du pouvoir 1
        }
    }
    // Pouvoir 2 : Avancer d'une case et faire reculer le joueur adverse de 3 cases (tomber sur un nombre pair)
    else if (dice_roll == 2 || dice_roll == 4) {
        if (this->deplacement(choice, pboard)) {
            piece_adverse.Reculer(1, pboard); // Faire reculer le joueur adverse de 3 cases
            return 2; // Succès du pouvoir 2
        }
    }
    // Pouvoir 3 : Avancer d'une case et faire reculer le joueur adverse de 5 cases (tomber sur 6)
    else if (dice_roll == 6) {
        if (this->deplacement(choice, pboard)) {
            piece_adverse.Reculer(3, pboard); // Reculer de 5 cases
            return 3; // Succès du pouvoir 3
        }
    }
    return 0; // Aucun pouvoir n'a été activé
}