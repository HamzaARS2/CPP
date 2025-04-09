#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Dog constructor called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog& copy): Animal(copy) {
    std::cout << "Dog constructor called" << std::endl;
    this->type = copy.type;
}

Dog&    Dog::operator=(const Dog& other) {
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    this->type = other.type;
    return *this;
}

void    Dog::makeSound() const {
    std::cout << "Bark!" << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}