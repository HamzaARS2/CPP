#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal() {
    std::cout << "WrongAnimal constructor called" << std::endl;
    this->type = "Default WrongAnimal type";
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) {
    std::cout << "WrongAnimal constructor called" << std::endl;
    this->type = copy.type;    
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    this->type = other.type;
    return *this;
}

String  WrongAnimal::getType() const {
    return this->type;
}

void WrongAnimal::makeSound() const {
    std::cout << "Default sound" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}