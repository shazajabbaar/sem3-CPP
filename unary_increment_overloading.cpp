#include <iostream>
using namespace std;

class Number {
private:
    int value;

public:
    // Constructor to initialize
    Number(int v = 0) {
        value = v;
    }

    // Overload prefix ++
    Number operator++() {
        ++value;   // Increment first
        return *this;
    }

    // Overload postfix ++
    Number operator++(int) {
        Number temp = *this; // store old value
        value++;             // increment after
        return temp;         // return old value
    }

    void display() const {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Number n1(5);

    cout << "Initial value:\n";
    n1.display();

    ++n1; // calls prefix
    cout << "\nAfter prefix ++n1:\n";
    n1.display();

    n1++; // calls postfix
    cout << "\nAfter postfix n1++:\n";
    n1.display();

    return 0;
}
