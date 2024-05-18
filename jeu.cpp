
#include "jeu.hpp"
#include "duelcell.hpp"
void Jeu::tour(int nb_joueur){
    Joueur joueur;
    if (nb_joueur == 1){
        joueur = joueur1;
    }
    else{
        joueur = joueur2;
    }
    int dep = 0;
    int choice;
    int range;
    while(!dep){
        joueur.my_piece->print();
        int i;
        std::cout << "Saisir i : ";
        std::cin >> i;
        if(i<0){
            printf("Tour passé \n");
            break;
        };  
        int j;
        std::cout << "Saisir j : ";
        std::cin >> j;
        joueur.my_piece->convertXYtoChoiceRange(i,j, &choice, &range);
        dep = joueur.my_piece->deplacement(choice,range,playboard);
    }
        Cell celule =playboard.getCell(joueur.my_piece->posx,joueur.my_piece->posx);
        if(celule.getStatus()==2){
            DuelCell cel;
            int res = cel.duel();
            recompense(res);
        }
}

void Jeu::recompense(int res){
    Joueur joueur;
    if(res){
        joueur=joueur1;
    }
    else{
        joueur = joueur2;
    }
        joueur.point ++;
        int i;
        std::cout << "Saisir pièce : ";
        std::cin >> i;
        joueur.changerpiece(i);
}