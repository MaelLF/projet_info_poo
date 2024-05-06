#include "cell.hpp"

class DuelCell : public Cell {
public:
    std::string name ="duel cell";
    // Méthode spécifique pour déclencher un duel
    void duel() const {
        std::cout << "Duel initiated!" << std::endl;
        //mettre la classe duel à l'intérieur
    }
};