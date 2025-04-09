#include "WrongCat.hpp"

WrongCat::WrongCat() {
    std::cout << "WrongCat constructor called" << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& copy): WrongAnimal(copy) {
    std::cout << "WrongCat constructor called" << std::endl;
    this->type = copy.type;
}

WrongCat&    WrongCat::operator=(const WrongCat& other) {
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    this->type = other.type;
    return *this;
}

void    WrongCat::makeSound() const {
    std::cout << "Moew!" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}