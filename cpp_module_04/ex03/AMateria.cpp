#include "AMateria.hpp"

AMateria::AMateria(String const& type):
    type(type) {}

String const& AMateria::getType() const {
    return this->type;
}

AMateria::~AMateria() {
    std::cout << "AMateria destructor called" << std::endl;    
}