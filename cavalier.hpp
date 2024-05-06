#include "piece.hpp"

class Cavalier : public Piece{
    public :
        Cavalier(){name = "Cavalier";};
        Cavalier(int x, int y){name = "Cavalier"; posx=x;posy=y;};
};