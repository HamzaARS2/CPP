#include "Cure.hpp"

Cure::Cure(): AMateria("cure") {
}

Cure::Cure(const Cure& copy): AMateria(copy.type) {
}

Cure&    Cure::operator=(const Cure& other) {
    if (this == &other)
        return *this;
    
    return *this;
}

Cure*    Cure::clone() const {
    return new Cure(*this);
}

void    Cure::use(ICharacter& target) {
    std::cout << "* heals " + target.getName() + "’s wounds *" <<std::endl;
}

Cure::~Cure() {
}