#ifndef emptycell_H
#define emptycell_H

#include "cell.hpp"

class EmptyCell : public Cell {
public:
    //Constructeur
    EmptyCell(){name = "Empty cell";}
};

#endif