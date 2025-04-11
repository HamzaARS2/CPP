#include "Animal.hpp"


Animal::Animal() {
    std::cout << "Abstract Animal constructor called" << std::endl;
    this->type = "Default animal type";
}

Animal::Animal(const Animal& copy) {
    std::cout << "Abstract Animal constructor called" << std::endl;
    this->type = copy.type;    
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Abstract Animal copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    this->type = other.type;
    return *this;
}

String  Animal::getType() const {
    return this->type;
}

Animal::~Animal() {
    std::cout << "Abstract Animal destructor called" << std::endl;
}