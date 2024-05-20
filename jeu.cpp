#include "jeu.hpp"
#include "duelcell.hpp"
void Jeu::tour(sf::Vector2i posCell){
    Joueur *joueur;
    Joueur *adverse;
    if (tourJ1){
        joueur = &joueur1;
        adverse = &joueur2;
    }
    else if(tourJ2){
        joueur = &joueur2;
        adverse = &joueur1;
    }
    int dep = 0;
    //int choice;
    //int range;
    
    joueur->my_piece->print();
    std::cout << "Click sur la case (" << posCell.x << ", " << posCell.y << ")" << std::endl;
    int dice_roll = std::rand() % 6 + 1;
    dep = joueur->my_piece->pouvoir(dice_roll,posCell.x,posCell.y,*(adverse->my_piece),playboard);

    //joueur->my_piece->convertXYtoChoiceRange(posCell.x,posCell.y, &choice, &range,3);
    //printf("choix%d range%d \n",choice,range);
    //dep = joueur->my_piece->deplacement(choice,range,playboard);
    
    printf("Fin de déplacement \n");
    if(dep && playboard.getStatus(joueur->my_piece->posx,joueur->my_piece->posy)==2){
        printf("Duel \n");
        DuelCell cel;
        int res = cel.duel();
        recompense(res);
    }
    
    if(dep && adverse->my_piece->posx == joueur->my_piece->posx && adverse->my_piece->posy == joueur->my_piece->posy){
        adverse->my_piece->Reculer(1,playboard); // ne déclenche pas les cases duels
    }

    //Condition de fin du jeu
    if(playboard.getStatus(joueur->my_piece->posx,joueur->my_piece->posy)==4){
        endGame = true;
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