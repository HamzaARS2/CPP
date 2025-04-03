#include "Point.hpp"

Point::Point(): x(Fixed(0)), y(Fixed(0)) {
    
}

Point::Point(const Fixed fixedX, const Fixed fixedY)
    :x(fixedX), y(fixedY)  {}

Point::Point(const Point& object)
    : x(object.x), y(object.y) {}

Point&  Point::operator=(const Point other) {
    if (this == &other)
        return *this;
    return *this;
}

Fixed   Point::getX() const {
    return this->x;
}

Fixed   Point::getY() const {
    return this->y;
}



Point::~Point() {

}