#include "cell.hpp"

#include <iostream>
#include <vector>

class Playboard {
private:
    int rows;
    int cols;
    std::vector<std::vector<char>> board;

public:
    Playboard(int n, int m) : rows(n), cols(m) {
        // Initialiser le plateau avec des cellules vides (' ')
        board = std::vector<std::vector<char>>(rows, std::vector<char>(cols, ' '));
    }

    void printBoard() const {
        for (const auto& row : board) {
            for (char cell : row) {
                std::cout << cell << ' ';
            }
            std::cout << std::endl;
        }
    }

    void setCell(int row, int col, char value) {
        if (isValidCell(row, col)) {
            board[row][col] = value;
        } else {
            std::cout << "Coordonnées invalides !" << std::endl;
        }
    }

    char getCell(int row, int col) const {
        if (isValidCell(row, col)) {
            return board[row][col];
        } else {
            std::cout << "Coordonnées invalides !" << std::endl;
            return ' ';
        }
    }

private:
    bool isValidCell(int row, int col) const {
        return row >= 0 && row < rows && col >= 0 && col < cols;
    }
};