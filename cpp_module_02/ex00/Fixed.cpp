#include "Fixed.hpp"

Fixed::Fixed() {
    this->rawBits = 0.0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& object) {
    this->rawBits = object.rawBits;
    std::cout << "Copy constructor called" << std::endl;
}


Fixed&  Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    this->rawBits = other.rawBits;
    return *this;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->rawBits;
}

void    Fixed::setRawBits(int raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->rawBits = raw;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}