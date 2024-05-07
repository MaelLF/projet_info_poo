#ifndef obstaclecell_H
#define obstaclecell_H

#include "cell.hpp"

class ObstacleCell : public Cell {
public:
    //Constructeur
    ObstacleCell(){
        name ="obstacle cell";
        status = 0;
    }
};

#endif