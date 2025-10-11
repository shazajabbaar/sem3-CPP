#include <iostream>
using namespace std;

// Inline functions for area calculations
inline double areaCircle(double radius) {
    return 3.14159 * radius * radius;
}

inline double areaSquare(double side) {
    return side * side;
}

inline double areaRectangle(double length, double width) {
    return length * width;
}

inline double areaTriangle(double base, double height) {
    return 0.5 * base * height;
}

int main() {
    double radius, side, length, width, base, height;

    // Circle
    cout << "Enter radius of the circle: ";
    cin >> radius;
    cout << "Area of Circle: " << areaCircle(radius) << endl;

    // Square
    cout << "Enter side of the square: ";
    cin >> side;
    cout << "Area of Square: " << areaSquare(side) << endl;

    // Rectangle
    cout << "Enter length and width of the rectangle: ";
    cin >> length >> width;
    cout << "Area of Rectangle: " << areaRectangle(length, width) << endl;

    // Triangle
    cout << "Enter base and height of the triangle: ";
    cin >> base >> height;
    cout << "Area of Triangle: " << areaTriangle(base, height) << endl;

    return 0;
}
