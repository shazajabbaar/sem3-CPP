#include <iostream>
using namespace std;

class Book {
private:
    int BookID;
    string BookName;
    float BookPrice;

public:
    // Function to input book details
    void inputData() {
        cout << "Enter Book ID: ";
        cin >> BookID;
        cout << "Enter Book Name: ";
        cin.ignore(); // To clear buffer
        getline(cin, BookName);
        cout << "Enter Book Price: ";
        cin >> BookPrice;
    }

    // Function to display book details
    void displayData() {
        cout << "\nBook ID: " << BookID;
        cout << "\nBook Name: " << BookName;
        cout << "\nBook Price: " << BookPrice << endl;
    }
};

int main() {
    Book b1, b2, b3;

    cout << "Enter details for Book 1:\n";
    b1.inputData();

    cout << "\nEnter details for Book 2:\n";
    b2.inputData();

    cout << "\nEnter details for Book 3:\n";
    b3.inputData();

    cout << "\n--- Displaying Book Details ---";
    b1.displayData();
    b2.displayData();
    b3.displayData();

    return 0;
}
