#ifndef kingcell_H
#define kingcell_H

#include "cell.hpp"

class KingCell : public Cell {
public:
    //Constructeur
    KingCell(){
        name ="king cell";
        status = 4;
    }
};

#endif