#include "cell.hpp"
#include "playboard.hpp"

#include <iostream>
#include <vector>

Playboard::Playboard(int n, int m) : rows(n), cols(m) {
    // Initialiser le plateau avec des cellules vides 
    board = std::vector<std::vector<Cell>>(rows, std::vector<Cell>(cols, Cell()));
}

void Playboard::printBoard() const {
    for (const auto& row : board) {
        for (Cell cell : row) {
            std::cout << ' ';
        }
        std::cout << std::endl;
    }
}

bool Playboard::isValidCell(int row, int col) const {
    return row >= 0 && row < rows && col >= 0 && col < cols;
}

void Playboard::setCell(int row, int col, Cell& cell) {
    if (isValidCell(row, col)) {
        board[row][col] = cell;
    } else {
        std::cout << "Coordonnées invalides !" << std::endl;
    }
}

Cell Playboard::getCell(int row, int col) const {
    if (isValidCell(row, col)) {
        return board[row][col];
    } else {
        std::cout << "Coordonnées invalides !" << std::endl;
        return Cell();
    }
}
