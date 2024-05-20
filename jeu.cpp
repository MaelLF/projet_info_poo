#include "jeu.hpp"
#include "duelcell.hpp"
#include <cstdlib> // Pour std::rand
#include <ctime>   // Pour std::time
void Jeu::tour(sf::Vector2i posCell){
    Joueur *joueur;
    if (tourJ1){
        joueur = &joueur1;
    }
    else if(tourJ2){
        joueur = &joueur2;
    }
    int dep = 0;
    int choice;
    int range;
    
    joueur->my_piece->print();
    std::cout << "Click sur la case (" << posCell.x << ", " << posCell.y << ")" << std::endl;
    int dice_roll = std::rand() % 6 + 1;
    joueur->my_piece->pouvoir(dice_roll,posCell.x,posCell.y,&joueur2,playboard);
    //joueur->my_piece->convertXYtoChoiceRange(posCell.x,posCell.y, &choice, &range);
    //printf("choix%d range%d \n",choice,range);
    //dep = joueur->my_piece->deplacement(choice,range,playboard);
    
    printf("Fin de déplacement \n");
    if(dep && playboard.getStatus(joueur->my_piece->posx,joueur->my_piece->posy)==2){
        printf("Duel \n");
        DuelCell cel;
        int res = cel.duel();
        recompense(res);
    }
    
    //Fin du tour
    if(tourJ1 && dep){
        tourJ1 = false;
        tourJ2 = true;
        nbTours++;
        if(nbTours%3 == 0){
            std::cout << "Duel" << std::endl;
            DuelCell cel;
            int res = cel.duel();
            recompense(res);
        }
    }else if(tourJ2 && dep){
        tourJ1 = true;
        tourJ2 = false;
        nbTours++;
        if(nbTours%3 == 0){
            printf("Duel \n");
            DuelCell cel;
            int res = cel.duel();
            recompense(res);
        }
    }
}

void Jeu::recompense(int res){
    Joueur *joueur;
    if (res == 0){
        joueur = &joueur1;
    }
    else{
        joueur = &joueur2;
    }
        joueur->point ++;
        std::cout << "Saisir pièce : " << std::endl;
        joueur->choosePiece = true;
}