#include "AMateria.hpp"

AMateria::AMateria(String const& type):
    type(type) {}

String const& AMateria::getType() const {
    return this->type;
}

void    AMateria::use(ICharacter& target) {
    std::cout << target.getName() << std::endl;  
}

AMateria::~AMateria() {
}