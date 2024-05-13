#ifndef playboard_HPP
#define playboard_HPP

#include <iostream>
#include <vector>
#include "cell.hpp"

class Joueur;   
class Playboard {
private:
    int rows;
    int cols;
    std::vector<std::vector<Cell>> board;

public:
    Playboard(int n, int m);

    void printBoard() const;
    void printBoard(Joueur joueur1, Joueur joueur2) const;
    bool isValidCell(int row, int col) const;
    void setCell(int row, int col, Cell& cell);
    Cell getCell(int row, int col) const;
    void initPlayboard();
    int isoccupied(int row, int col, Joueur joueur)const;
};

#endif
