#include <iostream>
#include <memory> // Pour std::unique_ptr
#ifndef cell_H
#define cell_H
// Classe abstraite Cell
class Cell {
public:
    virtual ~Cell() = default; // Déstructeur virtuel
    std::string name ="cell";
    // Méthode virtuelle pure pour afficher le type de la cellule
    virtual void display(){std::cout << name << std::endl;};
};
#endif

