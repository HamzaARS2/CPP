#include "Fixed.hpp"

const int Fixed::fraction = 8;

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->rawBits = 0.0;
}

Fixed::Fixed(const Fixed& object) {
    std::cout << "Copy constructor called" << std::endl;
    this->rawBits = object.rawBits;
}

Fixed::Fixed(const int i) {
    std::cout << "Int constructor called" << std::endl;
    int scale = 1 << fraction;
    this->rawBits = i * scale;
}

Fixed::Fixed(const float f) {
    std::cout << "Float constructor called" << std::endl;
    int scale = 1 << fraction;
    this->rawBits = roundf(f * scale);
}


Fixed&  Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    this->rawBits = other.rawBits;
    return *this;
}

std::ostream& operator<<(std::ostream &out, const Fixed& object) {
    out << object.toFloat();
    return out;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->rawBits;
}

void    Fixed::setRawBits(int raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->rawBits = raw;
}

float   Fixed::toFloat() const {
    int scale = 1 << Fixed::fraction;
    float number = this->rawBits / (float)scale;                
    return number;
}

int     Fixed::toInt() const {
    int number = this->rawBits >> Fixed::fraction;
    return number;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}