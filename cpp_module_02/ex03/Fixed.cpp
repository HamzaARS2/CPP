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

// Comparators

bool    Fixed::operator>(const Fixed other) const {
    return this->rawBits > other.rawBits;
}

bool    Fixed::operator<(const Fixed other) const {
    return this->rawBits < other.rawBits;
}

bool    Fixed::operator>=(const Fixed other) {
    return this->rawBits >= other.rawBits;
}

bool    Fixed::operator<=(const Fixed other) {
    return this->rawBits <= other.rawBits;
}

bool    Fixed::operator==(const Fixed other) {
    return this->rawBits == other.rawBits;
}

bool    Fixed::operator!=(const Fixed other) {
    return this->rawBits != other.rawBits;
}

// Arithmetic

Fixed  Fixed::operator+(const Fixed other) {
    Fixed newFixed;
    newFixed.setRawBits(this->rawBits + other.rawBits);
    return newFixed;
}

Fixed  Fixed::operator-(const Fixed other) {
    Fixed newFixed;
    newFixed.setRawBits(this->rawBits - other.rawBits);
    return newFixed;
}

Fixed  Fixed::operator*(const Fixed other) {
    Fixed newFixed;
    int scale = 1 << fraction;
    newFixed.setRawBits((this->rawBits * other.rawBits) / scale);
    return newFixed;
}

Fixed  Fixed::operator/(const Fixed other) {
    Fixed newFixed(((float)this->rawBits / other.rawBits));
    return newFixed;
}

// Increment/Decrement 

Fixed   Fixed::operator++(int) {
    Fixed original;
    original.setRawBits(this->rawBits++);
    return original;
}
Fixed   Fixed::operator++() {
    this->rawBits++;
    return *this;
}

Fixed   Fixed::operator--(int) {
    Fixed original;
    original.setRawBits(this->rawBits--);
    return original;
}

Fixed   Fixed::operator--() {
    this->rawBits--;
    return *this;
}

// min/max methods

Fixed&   Fixed::min(Fixed& object1, Fixed& object2) {
    if (object1 > object2) 
        return object2;
    return object1;
}

const Fixed&   Fixed::min(const Fixed& object1, const Fixed& object2) {
    if (object1 > object2) 
        return object2;
    return object1;
}

Fixed&   Fixed::max(Fixed& object1, Fixed& object2) {
    if (object1 > object2) 
        return object1;
    return object2;
}

const Fixed&   Fixed::max(const Fixed& object1, const Fixed& object2) {
    if (object1 > object2) 
        return object1;
    return object2;
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