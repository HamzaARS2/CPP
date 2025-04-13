#include "Ice.hpp"

Ice::Ice(): AMateria("ice") {
}

Ice::Ice(const Ice& copy): AMateria(copy.type){
}

Ice&    Ice::operator=(const Ice& other) {
    if (this == &other)
        return *this;
    
    return *this;
}

Ice*    Ice::clone() const {
    return new Ice(*this);
}

void    Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " + target.getName() + " *" <<std::endl;
}

Ice::~Ice() {
}