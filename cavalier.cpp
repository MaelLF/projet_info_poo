#include "cavalier.hpp"
#include <iostream>
#include <random>

Cavalier::Cavalier() {
    name = "Cavalier";
}

Cavalier::Cavalier(int y, int x) {
    name = "Cavalier";
    posy = y;
    posx = x;

}

int Cavalier::deplacement(int choix, Playboard& pboard) {
    int newX, newY;
    switch (choix) {
        case 0:
            // 2 haut 1 gauche : Actions à effectuer si choix est égal à 0
            int newX = posx - 1 ;
            int newY = posy - 2 ;
            if (!pboard.isValidCell(newY,newX) || !pboard.getCell(newY,newX).getStatus()) {
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
            int newX = posx + 1 ;
            int newY = posy - 2 ;
            if (!pboard.isValidCell(newY,newX) || !pboard.getCell(newY,newX).getStatus()) {
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
            int newX = posx + 2 ;
            int newY = posy - 1 ;
            if (!pboard.isValidCell(newY,newX) || !pboard.getCell(newY,newX).getStatus()) {
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
            int newX = posx + 2 ;
            int newY = posy + 1 ;
            if (!pboard.isValidCell(newY,newX) || !pboard.getCell(newY,newX).getStatus()) {
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
            int newX = posx + 1 ;
            int newY = posy + 2 ;
             if (!pboard.isValidCell(newY,newX) || !pboard.getCell(newY,newX).getStatus()) {
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
            int newX = posx - 1 ;
            int newY = posy + 2 ;
            if (!pboard.isValidCell(newY,newX) || !pboard.getCell(newY,newX).getStatus()) {
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
            int newX = posx - 2 ;
            int newY = posy + 1 ;
            if (!pboard.isValidCell(newY,newX) || !pboard.getCell(newY,newX).getStatus()) {
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
            int newX = posx - 2 ;
            int newY = posy - 1 ;
               if (!pboard.isValidCell(newY,newX) || !pboard.getCell(newY,newX).getStatus()) {
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

int Cavalier::deplacement(int choix, int range, Playboard& pboard)
{
    this->deplacement(choix,pboard);
}

int Cavalier::pouvoir (int pouvoir,int choix,int range, Playboard& pboard){
    // Initialisation d'un générateur de nombres aléatoires avec une graine
    std::random_device rd;
    std::mt19937 gen(rd()); // Mersenne Twister 19937 generator

    // Définir une distribution pour spécifier la plage de nombres
    std::uniform_int_distribution<> distribution(1, 6); // Nombres aléatoires entre 1 et 10 inclus

    // Générer un nombre aléatoire
    int random_number = distribution(gen);

    // Afficher le nombre aléatoire généré
    std::cout << "Nombre aléatoire : " << random_number << std::endl;

    return 0;
    switch (pouvoir)
    {
    case 0 :
        if (random_number !=1) //Si le dés est différent de 1
        {
            this->deplacement(choix, pboard);
            std::cout << " le Cavalier avance !" << std::endl;
        }

        return 1 ;
    
    case 1 :
        if (random_number ==2,4,6) // si le dés est pair 
        {
            this->deplacement(choix, pboard);
            std::cout << " le Cavalier avance !" << std::endl;
        }
        return 1;

    case 2 :
        if (random_number ==6) // si le dés est égal à 6 
        {
            this->deplacement(choix, pboard);
            std::cout << " le Cavalier avance !" << std::endl;
        }
        return 1;
    
    default:
        break;
    }

}
