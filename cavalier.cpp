#include "cavalier.hpp"
#include <iostream>


int Cavalier::deplacement(int choix, Playboard& pboard) {
    int newX, newY;
    switch (choix) {
        case 0:
            // 2 haut 1 gauche : Actions à effectuer si choix est égal à 0
            newX = posx - 1 ;
            newY = posy - 2 ;
            if (!pboard.isValidCell(newX,newY) || !pboard.getCell(newX,newY).getStatus()) {
                printf("deplacement pas fait");
                return 0;   
            }
            else{
                posx = newX ;
                posy = newY ;
                std::cout << "2 haut 1 gauche" << std::endl;
                return 1 ;
            }
        case 1:
            // 2 haut 1 droite : Actions à effectuer si choix est égal à 1
            newX = posx + 1 ;
            newY = posy - 2 ;
            if (!pboard.isValidCell(newX,newY) || !pboard.getCell(newX,newY).getStatus()) {
                printf("deplacement pas fait");
                return 0;   
            }
            else{
                posx = newX ;
                posy = newY ;
                std::cout << "2 haut 1 droite" << std::endl;
                return 1 ;
            }

        case 2:
            // 2 droite 1 haut : Actions à effectuer si choix est égal à 2
            newX = posx + 2 ;
            newY = posy - 1 ;
            if (!pboard.isValidCell(newX,newY) || !pboard.getCell(newX,newY).getStatus()) {
                printf("deplacement pas fait");
                return 0;   
            }
            else{
                posx = newX ;
                posy = newY ;
                std::cout << "2 droite 1 haute" << std::endl;
                return 1 ;
            }


        case 3:
            // 2 droite 1 bas : Actions à effectuer si choix est égal à 3
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


        case 4:
            // Actions à effectuer si choix est égal à 4
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


        case 5:
            // Actions à effectuer si choix est égal à 5
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


        case 6:
            // Actions à effectuer si choix est égal à 6
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

        
        case 7:
            // Actions à effectuer si choix est égal à 7
            newX = posx - 2 ;
            newY = posy - 1 ;
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

}
