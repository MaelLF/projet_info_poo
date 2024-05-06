#include "cell.hpp"

#include <iostream>
#include <vector>

class Playboard {
private:
    int rows;
    int cols;
    std::vector<std::vector<Cell>> board;

public:
    Playboard(int n, int m) : rows(n), cols(m);

    void printBoard() const;
    bool isValidCell(int row, int col) const;
    void setCell(int row, int col, char value);
    char getCell(int row, int col) const;
};