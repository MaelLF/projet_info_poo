#ifndef duelcell_H
#define duelcell_H

#include "cell.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
class DuelCell : public Cell {
public:
    //Constructeur
    DuelCell(){
        name ="duel cell";
        status = 2;
        std::srand(std::time(0));
        }
    // Méthode spécifique pour déclencher un duel
    int duel() const {
        std::cout << "Duel initiated!" << std::endl;
        int res =0;
        int sto =0;
        while(res==sto){
            res = std::rand()%6 +1 ; //dé 6 faces
            sto = std::rand()%6 +1 ;
        }
        printf("%d vs %d \t",res,sto);
        if(res> sto){
            printf("j1 gagne \n");
            return 0;
        }
        printf("j2 gagne \n");
        return 1;
    }
};

#endif