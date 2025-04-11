#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat constructor called" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
}

Cat::Cat(const Cat& copy): Animal(copy) {
    std::cout << "Cat constructor called" << std::endl;
    this->type = copy.type;
    this->brain = new Brain(*copy.brain);
}

Cat&    Cat::operator=(const Cat& other) {
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    this->type = other.type;
    *this->brain = *other.brain;
    return *this;
}

void    Cat::makeSound() const {
    std::cout << "Moew!" << std::endl;
}

Brain&  Cat::getBrain() const {
    return *this->brain;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    delete this->brain;
}