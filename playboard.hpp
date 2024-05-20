#ifndef PLAYBOARD_HPP
#define PLAYBOARD_HPP

#include <iostream>
#include <vector>
#include "cell.hpp"

#define NB_OBSTACLES 20
#define NB_DUEL 5

class Joueur;   
// Déclaration anticipée de la classe SFMLRenderer
class SFMLRenderer;

class Playboard {
private:
    int rows;
    int cols;
    std::vector<std::vector<Cell>> board;

public:
    Playboard(){rows = 0; cols = 0;}
    Playboard(int n, int m);

    int getRows(){return rows;};
    int getCols(){return cols;};
    void printBoard() const;
    void printBoard(Joueur joueur1, Joueur joueur2) const;
    bool isValidCell(int row, int col) const;
    void setCell(int row, int col, Cell& cell);
    Cell getCell(int row, int col) const;
    void initPlayboard();
    int getStatus(int row, int col)const;
    int isoccupied(int row, int col, Joueur joueur)const;
    void display(SFMLRenderer &renderer);
};


#include "sfml_renderer.hpp"

#endif
