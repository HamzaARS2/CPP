#include "Point.hpp"


Fixed calculateArea(Point a, Point b, Point c) {
    Fixed yDiffA = b.getY() - c.getY();
    Fixed yDiffB = c.getY() - a.getY();
    Fixed yDiffC = a.getY() - b.getY();

    Fixed area = Fixed(0.5f) * ((a.getX() * yDiffA) + (b.getX() * yDiffB) + (c.getX() * yDiffC));

    return area < Fixed(0) ? area * Fixed(-1) : area;
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
    Fixed triangleArea = calculateArea(a, b, c);
    Fixed pab = calculateArea(point, a, b);
    Fixed pac = calculateArea(point, a, c);
    Fixed pbc = calculateArea(point, b, c);
    if (pab == Fixed(0) || pac  == Fixed(0) || pbc == Fixed(0))
        return false;
    return triangleArea == (pab + pac + pbc);
}