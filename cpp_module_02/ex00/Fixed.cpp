#include "Fixed.hpp"

Fixed::Fixed() {
    this->fixedPoint = 0.0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& object) {
    this->fixedPoint = object.fixedPoint;
    std::cout << "Copy constructor called" << std::endl;
}


Fixed&  Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    this->fixedPoint = other.fixedPoint;
    return *this;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixedPoint;
}

void    Fixed::setRawBits(int raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->fixedPoint = raw;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}