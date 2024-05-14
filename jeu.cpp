
#include "jeu.hpp"

void Jeu::tour(int nb_joueur){
    Joueur joueur;
    if (nb_joueur == 1){
        joueur = joueur1;
    }
    else{
        joueur = joueur2;
    }
    int dep = 0;
    while(!dep){
    joueur.my_piece->print();
    int choix;
    std::cout << "Saisir choix : ";
    std::cin >> choix;

    int range;
    std::cout << "Saisir range : ";
    std::cin >> range;
    dep = joueur.my_piece->deplacement(choix,range,playboard);
    }
}