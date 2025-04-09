#include "Animal.hpp"


Animal::Animal() {
    std::cout << "Animal constructor called" << std::endl;
    this->type = "Default animal type";
}

Animal::Animal(const Animal& copy) {
    std::cout << "Animal constructor called" << std::endl;
    this->type = copy.type;    
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    this->type = other.type;
    return *this;
}

String  Animal::getType() const {
    return this->type;
}

void Animal::makeSound() const {
    std::cout << "Default sound" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}