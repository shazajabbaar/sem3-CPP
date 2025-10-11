#include <iostream>
using namespace std;

class TelephoneBill {
private:
    string name;
    string address;
    string telNo;
    int numOfCalls;

public:
    // Member function to input details
    void input() {
        cout << "Enter Name: ";
        cin.ignore(); // to ignore any leftover newline
        getline(cin, name);
        cout << "Enter Address: ";
        getline(cin, address);
        cout << "Enter Telephone Number: ";
        cin >> telNo;
        cout << "Enter Number of Calls: ";
        cin >> numOfCalls;
    }

    // Friend function declaration
    friend void calculateAmount(TelephoneBill t);
};

// Friend function definition
void calculateAmount(TelephoneBill t) {
    const int chargePerCall = 2; // Rs. 2 per call
    int amount = t.numOfCalls * chargePerCall;

    cout << "\n--- Telephone Bill ---\n";
    cout << "Name: " << t.name << endl;
    cout << "Address: " << t.address << endl;
    cout << "Telephone Number: " << t.telNo << endl;
    cout << "Number of Calls: " << t.numOfCalls << endl;
    cout << "Amount to be Paid: Rs. " << amount << endl;
}

int main() {
    TelephoneBill customer;
    customer.input();
    calculateAmount(customer); // friend function calculates bill
    return 0;
}
