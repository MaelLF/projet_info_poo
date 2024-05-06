#include <iostream>
#include <memory>
#include "playboard.hpp"
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
        virtual int deplacement(int choix, int range,Playboard& board){}
        virtual int deplacement(int choix, Playboard& board){}
        virtual int deplacement(Playboard& pboard){}

};
#endif