#include "pion.hpp"
#include "duelcell.hpp"
#include <cstdlib> // Pour std::rand
#include <ctime>   // Pour std::time

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

int Pion::pouvoir(int choix, Piece& piece_adverse, Playboard& pboard) {
    // Lancer d'un dé pour déterminer le pouvoir utilisé
    int dice_roll = std::rand() % 6 + 1;

    // Pouvoir 1 : Avancer d'une case et faire reculer le joueur adverse d'une case 
    if (dice_roll == 1 || dice_roll == 3 || dice_roll == 5) {
        if (this->deplacement(choix, pboard)) {
            if (piece_adverse.posy + 1 < pboard.getCols()) {
                piece_adverse.posy += 1; // Faire reculer le joueur adverse d'une case
            }
            return 1;  // Succès du pouvoir 1
        }
    }
    // Pouvoir 2 : Avancer d'une case et faire reculer le joueur adverse de 3 cases (tomber sur un nombre pair)
    else if (dice_roll == 2 || dice_roll == 4) {
        if (this->deplacement(choix, pboard)) {
            if (piece_adverse.posy + 3 < pboard.getCols()) {
                piece_adverse.posy += 3; // Faire reculer le joueur adverse de 3 cases
            }
            return 2; // Succès du pouvoir 2
        }
    }
    // Pouvoir 3 : Avancer d'une case et faire reculer le joueur adverse de 5 cases (tomber sur 6)
    else if (dice_roll == 6) {
        if (this->deplacement(choix, pboard)) {
            if (piece_adverse.posy + 5 < pboard.getCols()) {
                piece_adverse.posy += 5; // Reculer de 5 cases
            }
            return 3; // Succès du pouvoir 3
        }
    }
    return 0; // Aucun pouvoir n'a été activé
}