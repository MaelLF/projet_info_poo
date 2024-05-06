#include <iostream>
#include <memory> // Pour std::unique_ptr
#ifndef cell_H
#define cell_H
// Classe abstraite Cell
class Cell {
protected:
    std::string name ="cell";
    int status = 1;
    int color = 0;

public:
    virtual ~Cell() = default; // Déstructeur virtuel
    // Méthode virtuelle pure pour afficher le type de la cellule
    virtual void display(){std::cout << name << std::endl;};
    int getstatus(){return status;};
};
#endif

