#include <iostream>
using namespace std;

// Base class
class Person {
protected:
    string name;
    int age;

public:
    // Function to input person details
    void getData() {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
    }

    // Function to display person details
    void display() const {
        cout << "\nName: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Derived class from Person
class Student : public Person {
private:
    int roll_number;

public:
    // Function to input student details
    void getDetails() {
        cin.ignore(); // clear input buffer before getline
        getData(); // call base class input
        cout << "Enter roll number: ";
        cin >> roll_number;
    }

    // Function to display all details
    void showDetails() const {
        display(); // call base class display
        cout << "Roll Number: " << roll_number << endl;
    }
};

int main() {
    Student s1;

    cout << "Enter Student Details:\n";
    s1.getDetails();

    cout << "\nStudent Information:\n";
    s1.showDetails();

    return 0;
}
