#include <iostream>
#include <memory>
#ifndef piece_H
#define piece_H
class Piece{
    public :
        Piece(){name = "Piece";};
        std::string name;
        int posx;
        int posy;
        virtual void display(){std::cout << name << std::endl;};
        virtual std::string getname(){return name;};
};
#endif