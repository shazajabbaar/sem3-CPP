#include <iostream>
using namespace std;

// Function overloading for area calculation

// Area of circle
double area(double radius) {
    return 3.14159 * radius * radius;
}

// Area of square
double area(int side) {
    return side * side;
}

// Area of rectangle
double area(double length, double width) {
    return length * width;
}

// Area of triangle
double area(double base, double height, char type) { // char type just to differentiate
    return 0.5 * base * height;
}

int main() {
    double radius, length, width, base, height;
    int side;

    // Circle
    cout << "Enter radius of the circle: ";
    cin >> radius;
    cout << "Area of Circle: " << area(radius) << endl;

    // Square
    cout << "Enter side of the square: ";
    cin >> side;
    cout << "Area of Square: " << area(side) << endl;

    // Rectangle
    cout << "Enter length and width of the rectangle: ";
    cin >> length >> width;
    cout << "Area of Rectangle: " << area(length, width) << endl;

    // Triangle
    cout << "Enter base and height of the triangle: ";
    cin >> base >> height;
    cout << "Area of Triangle: " << area(base, height, 't') << endl;

    return 0;
}
