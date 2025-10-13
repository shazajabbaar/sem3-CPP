#include <iostream>
using namespace std;

// Base class: BankAccount
class BankAccount {
protected:
    int account_number;
    double balance;

public:
    // Function to input account details
    void inputAccount() {
        cout << "Enter Account Number: ";
        cin >> account_number;
        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    // Deposit money
    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    // Withdraw money
    void withdraw(double amount) {
        if (amount > balance)
            cout << "Insufficient balance!" << endl;
        else {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        }
    }

    // Display balance
    void display() const {
        cout << "Account Number: " << account_number << endl;
        cout << "Balance: " << balance << endl;
    }
};

// Derived class: SavingsAccount
class SavingsAccount : public BankAccount {
private:
    double rate_of_interest;

public:
    void inputSavings() {
        inputAccount();
        cout << "Enter Rate of Interest (%): ";
        cin >> rate_of_interest;
    }

    void calculateInterest() {
        double interest = (balance * rate_of_interest) / 100;
        cout << "Interest Earned: " << interest << endl;
        balance += interest;
    }

    void displaySavings() {
        cout << "\n--- Savings Account Details ---\n";
        display();
        cout << "Rate of Interest: " << rate_of_interest << "%" << endl;
    }
};

// Derived class: CurrentAccount
class CurrentAccount : public BankAccount {
private:
    double minimum_balance;
    double service_charge;

public:
    void inputCurrent() {
        inputAccount();
        cout << "Enter Minimum Balance: ";
        cin >> minimum_balance;
        cout << "Enter Service Charge: ";
        cin >> service_charge;
    }

    void calculateServiceCharge() {
        if (balance < minimum_balance) {
            cout << "Balance below minimum! Service charge of " << service_charge << " applied." << endl;
            balance -= service_charge;
        } else {
            cout << "No service charge applied." << endl;
        }
    }

    void displayCurrent() {
        cout << "\n--- Current Account Details ---\n";
        display();
        cout << "Minimum Balance: " << minimum_balance << endl;
        cout << "Service Charge: " << service_charge << endl;
    }
};

int main() {
    // Savings account demo
    SavingsAccount s1;
    cout << "Enter Savings Account Details:\n";
    s1.inputSavings();
    s1.deposit(1000);
    s1.calculateInterest();
    s1.displaySavings();

    // Current account demo
    CurrentAccount c1;
    cout << "\nEnter Current Account Details:\n";
    c1.inputCurrent();
    c1.withdraw(500);
    c1.calculateServiceCharge();
    c1.displayCurrent();

    return 0;
}
