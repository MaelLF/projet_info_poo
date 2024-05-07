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
    void duel() const {
        std::cout << "Duel initiated!" << std::endl;
        //mettre la classe duel à l'intérieur
    }
};

#endif