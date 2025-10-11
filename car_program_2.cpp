#include <iostream>
using namespace std;

class Car {
    string brand;
    string model;
    int year;

public:
    void readData() {
        cout << "Enter brand: ";
        cin >> brand;
        cout << "Enter model: ";
        cin >> model;
        cout << "Enter year: ";
        cin >> year;
    }

    void displayData() {
        cout << "\nCar Details:\n";
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};

int main() {
    Car car1, car2, car3;

    cout << "Enter details for Car 1:\n";
    car1.readData();

    cout << "\nEnter details for Car 2:\n";
    car2.readData();

    cout << "\nEnter details for Car 3:\n";
    car3.readData();

    cout << "\n--- Displaying Car Details ---";
    car1.displayData();
    car2.displayData();
    car3.displayData();

    return 0;
}
