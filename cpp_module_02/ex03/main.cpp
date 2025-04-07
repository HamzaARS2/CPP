#include "Point.hpp"
#include "Fixed.hpp"

int main() {
    // Test case 1: Point inside the triangle
    Point a(0, 0);
    Point b(5, 0);
    Point c(0, 5);
    Point inside(2, 2);  // A point inside the triangle

    std::cout << "Test 1 - Point inside triangle: " << std::endl;
    std::cout << "Expected: true" << std::endl;
    std::cout << "Result: " << bsp(a, b, c, inside) << std::endl;  // Should return true

    // Test case 2: Point on the edge of the triangle
    Point onEdge(2, 0);  // A point on the edge of the triangle

    std::cout << "\nTest 2 - Point on edge of triangle: " << std::endl;
    std::cout << "Expected: false" << std::endl;
    std::cout << "Result: " << bsp(a, b, c, onEdge) << std::endl;  // Should return false

    // Test case 3: Point at a vertex of the triangle
    Point atVertex(0, 0);  // A point at the vertex 'a'

    std::cout << "\nTest 3 - Point at vertex: " << std::endl;
    std::cout << "Expected: false" << std::endl;
    std::cout << "Result: " << bsp(a, b, c, atVertex) << std::endl;  // Should return false

    // Test case 4: Point outside the triangle
    Point outside(-1, -1);  // A point outside the triangle

    std::cout << "\nTest 4 - Point outside triangle: " << std::endl;
    std::cout << "Expected: false" << std::endl;
    std::cout << "Result: " << bsp(a, b, c, outside) << std::endl;  // Should return false

    // Test case 5: Collinear points (lying on the same line)
    Point p1(1, 1);
    Point p2(2, 2);
    Point p3(3, 3);  // Points are collinear (lie on the same line)

    std::cout << "\nTest 5 - Collinear points (not forming a valid triangle): " << std::endl;
    std::cout << "Expected: false" << std::endl;
    std::cout << "Result: " << bsp(p1, p2, p3, Point(2, 1)) << std::endl;  // Should return false

    // Test case 6: Another valid triangle with a point inside
    Point d(1, 1);
    Point e(4, 1);
    Point f(1, 4);
    Point inside2(2, 2);  // A point inside the triangle

    std::cout << "\nTest 6 - Point inside second triangle: " << std::endl;
    std::cout << "Expected: true" << std::endl;
    std::cout << "Result: " << bsp(d, e, f, inside2) << std::endl;  // Should return true

    return 0;
}
