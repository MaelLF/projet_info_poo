#ifndef playboard_HPP
#define playboard_HPP

#include "cell.hpp"
#include <iostream>
#include <vector>


class Playboard {
private:
    int rows;
    int cols;
    std::vector<std::vector<Cell>> board;

public:
    Playboard(int n, int m);

    void printBoard() const;
    bool isValidCell(int row, int col) const;
    void setCell(int row, int col, Cell& cell);
    Cell getCell(int row, int col) const;
    void initPlayboard();
};

#endif
