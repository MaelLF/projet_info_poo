#include "cell.hpp"
#include <iostream>

void Cell::display(){
    std::cout << name << std::endl;
}

int Cell::getStatus() const{
    return status;
}