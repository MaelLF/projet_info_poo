#ifndef duelcell_H
#define duelcell_H

#include "cell.hpp"

class DuelCell : public Cell {
public:
    //Constructeur
    DuelCell(){
        name ="duel cell";
        status = 2;
        }
    // Méthode spécifique pour déclencher un duel
    int duel() const {
        std::cout << "Duel initiated!" << std::endl;
        int res =1;
        int sto =0;
        while(res==sto){
            res = rand()%6 +1 ; //dé 6 faces
            sto = rand()%6 +1 ;
        }
        if(res> sto){
            printf("j1 gagne \n");
            return 0;
        }
        printf("j2 gagne \n");
        return 1;
    }
};

#endif