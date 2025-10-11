#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    // Default constructor
    Rectangle() {
        length = 0;
        width = 0;
    }

    // Parameterized constructor
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    // Member function to display rectangle details
    void display() {
        cout << "Length: " << length << ", Width: " << width << endl;
    }

    // Destructor
    ~Rectangle() {
        cout << "Rectangle object destroyed." << endl;
    }
};

int main() {
    // Creating object using default constructor
    Rectangle rect1;
    cout << "Rectangle 1 (Default Constructor): ";
    rect1.display();

    // Creating object using parameterized constructor
    Rectangle rect2(10.5, 7.2);
    cout << "Rectangle 2 (Parameterized Constructor): ";
    rect2.display();

    return 0;
}
