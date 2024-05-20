#include <iostream>
#include <memory>
#include "playboard.hpp"
#include "joueur.hpp"
#ifndef piece_H
#define piece_H

// Déclaration anticipée de la classe SFMLRenderer
class SFMLRenderer;

class Piece{
    public :
        Piece(){name = "Piece";};
        std::string name;
        int posx;
        int posy;
        virtual void print(){std::cout << name << std::endl;};
        virtual std::string getname(){return name;};
        virtual int deplacement(int choix, int range,Playboard& board){printf("hello");return 0;};
        virtual int deplacement(int choix, Playboard& board){return 0;};
        virtual int deplacement(Playboard& pboard){return 0;};
        virtual void convertXYtoChoiceRange(int i, int j,int* choice,int* range,int rangemax);
        virtual ~Piece() = default;
        virtual void display(SFMLRenderer &renderer, int j) = 0;
        virtual int pouvoir(int dice_roll,int i, int j, Piece& piece_adverse, Playboard& pboard) { return 0; };
        void Reculer(int range, Playboard& pboard);
};

#include "sfml_renderer.hpp"

#endif  