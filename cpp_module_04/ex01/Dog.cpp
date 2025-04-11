#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Dog constructor called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
}

Dog::Dog(const Dog& copy): Animal(copy) {
    std::cout << "Dog constructor called" << std::endl;
    this->type = copy.type;
    this->brain = new Brain(*copy.brain);
}

Dog&    Dog::operator=(const Dog& other) {
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    this->type = other.type;
    *this->brain = *other.brain;
    return *this;
}

void    Dog::makeSound() const {
    std::cout << "Bark!" << std::endl;
}

Brain&  Dog::getBrain() const {
    return *this->brain;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete brain;
}