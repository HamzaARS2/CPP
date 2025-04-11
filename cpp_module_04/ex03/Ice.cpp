#include "Ice.hpp"

Ice::Ice(): AMateria("ice") {
    std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(const Ice& copy): AMateria(copy.type){
    std::cout << "Ice copy constructor called" << std::endl;
}

Ice&    Ice::operator=(const Ice& other) {
    std::cout << "Ice assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    
    return *this;
}

Ice*    Ice::clone() const {
    return new Ice(*this);
}

void    AMateria::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " + target.getName() + " *" <<std::endl;
}

Ice::~Ice() {
    std::cout << "Ice destructor called" << std::endl;
}