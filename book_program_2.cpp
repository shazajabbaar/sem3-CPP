#include <iostream>
using namespace std;

class Book {
private:
    int BookID;
    string BookName;
    float BookPrice;

    // Private function to calculate total cost
    float total_cost(int n) {
        return BookPrice * n;
    }

public:
    // Function to input book details
    void inputData() {
        cout << "Enter Book ID: ";
        cin >> BookID;
        cout << "Enter Book Name: ";
        cin.ignore();
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

    // Function to input number of copies and display total cost
    void purchaseBook() {
        int copies;
        cout << "Enter number of copies to purchase: ";
        cin >> copies;
        cout << "Total Cost = Rs. " << total_cost(copies) << endl;
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

    cout << "\n--- Purchase Details ---";
    cout << "\nFor Book 1:\n";
    b1.purchaseBook();

    cout << "\nFor Book 2:\n";
    b2.purchaseBook();

    cout << "\nFor Book 3:\n";
    b3.purchaseBook();

    return 0;
}
