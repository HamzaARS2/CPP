#include "Cure.hpp"

Cure::Cure(): AMateria("cure") {
    std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(const Cure& copy): AMateria(copy.type) {
    std::cout << "Cure copy constructor called" << std::endl;
}

Cure&    Cure::operator=(const Cure& other) {
    std::cout << "Cure assignment operator called" << std::endl;
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
    std::cout << "Cure destructor called" << std::endl;
}