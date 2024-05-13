#include "cell.hpp"
#include "emptycell.hpp"
#include "duelcell.hpp"
#include "obstaclecell.hpp"
#include "playboard.hpp"
#include "joueur.hpp"
#include <iostream>
#include <vector>
#include <cstdlib> //random 
#define NB_JOUEURS 2

Playboard::Playboard(int n, int m) : rows(n), cols(m) {
    // Initialiser le plateau avec des cellules vides 
    board = std::vector<std::vector<Cell>>(rows, std::vector<Cell>(cols, Cell()));
}

void Playboard::printBoard() const {
    for (const auto& row : board) {
        for (Cell cell : row) {
            std::cout << cell.getStatus() << ' ';
        }
        std::cout << std::endl;
    }
}
void Playboard::printBoard(Joueur joueur1,Joueur joueur2) const {
    int ligne = 0; 
    int colon = 0;
    for (const auto& row : board) {
        colon = 0;
        for (Cell cell : row) {
            if (this->isoccupied(ligne, colon, joueur1) || (this->isoccupied(ligne, colon, joueur2))) {
                std::cout << '3' << ' '; // Affiche '3' si la case est occupée
            } else {
                std::cout << cell.getStatus() << ' '; 
            }
            colon++;
        }
        std::cout << std::endl;
        ligne++; //
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

void Playboard::initPlayboard(){
    srand(time(NULL));
    int i, j, r, status, nbDuel = 0, nbObstacle = 0;
    //Placement des 3 cases Duels
    while(nbDuel < 3){
        for(i=0; i < rows; i++){
            for(j=0; j < cols ; j++){
                r = std::rand() % 100;
                status = board[i][j].getStatus();
                if(status != 2){
                    if(r || nbDuel >= 3){
                        board[i][j] = EmptyCell();
                    }else{
                        board[i][j] = DuelCell();
                        nbDuel++;
                        std::cout << nbDuel << " : (i,j) = ("<< i << "," << j << ")" << std::endl;
                    }
                }
            }
        }
    }
    //Placement des 10 cases obstacles
    while(nbObstacle < 10){ 
        for(i=0; i < rows; i++){
            for(j=0; j < cols ; j++){
                r = std::rand() % 100;
                status = board[i][j].getStatus();
                if(status != 2 && status != 0){
                    if(r || nbObstacle >= 10){
                        board[i][j] = EmptyCell();
                    }else{
                        board[i][j] = ObstacleCell();
                        nbObstacle++;
                    }
                }
            }
        }
    }
}

int Playboard::isoccupied(int row,int col,Joueur joueur)const{
        if (joueur.my_piece->posx == row && joueur.my_piece->posy == col){
            return 1;
        }
    return 0;
}