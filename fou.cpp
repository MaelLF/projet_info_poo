#include "playboard.hpp"
#include "fou.hpp"

int Fou::deplacement(int choix,int range,Playboard& pboard){
    switch (choix)
    {
    case 1 :
        for( int i=0;i<range+1;i++){
            if(!pboard.isValidCell(posx-i,posy+i) || !pboard.getCell(posx-i,posy+i).getStatus()){
                return 0;
            }
        }
            posx = posx-range;
            posy = posy+range;
            printf("deplacement en haut a droite fait");
            return 1;
        

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
            if(!pboard.isValidCell(posx+i,posy-i) || !pboard.getCell(posx+i,posy-i).getStatus()){
                return 0;
            }
        }
            posx = posx+range;
            posy = posy-range;
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

void Fou::display(SFMLRenderer &renderer, int j){
    renderer.drawFou(*this, j);
}


int Fou::pouvoir(int dice_roll,int i, int j, Piece& piece_adverse, Playboard& pboard) {
    // Lancer d'un dé pour déterminer le pouvoir utilisé
    int choice;
    int range;
    //FONCTION MATTHIEU RÉCUP I et J
    // Pouvoir 1 : Avancer d'une case et faire reculer le joueur adverse d'une case 
    if (dice_roll == 1 || dice_roll == 3 || dice_roll == 5) {
        printf("Vous etes tombé sur %d, vous avancez 1 fois avec un range max de 3\n",dice_roll);
        this->convertXYtoChoiceRange (i,j,&choice,&range,3);
        if (this->deplacement(choice,range, pboard)) {
            return 1;  // Succès du pouvoir 1
        }
    }
    // Pouvoir 2 : Avancer d'une case et faire reculer le joueur adverse de 3 cases (tomber sur un nombre pair)
    else if (dice_roll == 2 || dice_roll == 4) {
        printf("Vous etes tombé sur %d, vous avancez 1 fois avec un range max de 3 et faites reculer l'adversaire d'une case\n",dice_roll);
        this->convertXYtoChoiceRange (i,j,&choice,&range,3);
        if (this->deplacement(choice,range, pboard)) {
            piece_adverse.Reculer(1, pboard); // Faire reculer le joueur adverse de 3 cases
            return 2; // Succès du pouvoir 2
        }
    }
    // Pouvoir 3 : Avancer d'une case et faire reculer le joueur adverse de 5 cases (tomber sur 6)
    else if (dice_roll == 6) {
        printf("Vous etes tombé sur %d, vous avancez 1 fois avec un range max de 3\n",dice_roll);
        this->convertXYtoChoiceRange (i,j,&choice,&range,3);
        if (this->deplacement(choice,range, pboard)) {
            piece_adverse.Reculer(3, pboard); // Reculer de 5 cases
            return 3; // Succès du pouvoir 3
        }
    }
    return 0; // Aucun pouvoir n'a été activé
}