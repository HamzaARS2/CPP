#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat constructor called" << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat& copy): Animal(copy) {
    std::cout << "Cat constructor called" << std::endl;
    this->type = copy.type;
}

Cat&    Cat::operator=(const Cat& other) {
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    this->type = other.type;
    return *this;
}

void    Cat::makeSound() const {
    std::cout << "Moew!" << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}