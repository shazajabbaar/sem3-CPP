#include <iostream>
#include <string>
#include <iomanip> // For formatting output

// --- Base Class 1 ---
class online_shopping {
protected:
    std::string item_name;
    int quantity;
    double unit_price;
    double item_cost; // To store the calculated cost

public:
    void get_item_details() {
        std::cout << "--- Enter Item Details ---" << std::endl;
        std::cout << "Enter item name: ";
        std::cin.ignore(); // Clear buffer before getline
        std::getline(std::cin, item_name);
        
        std::cout << "Enter quantity: ";
        std::cin >> quantity;
        
        std::cout << "Enter unit price (in $): ";
        std::cin >> unit_price;
        
        // Calculate the item cost immediately
        item_cost = quantity * unit_price;
    }

    // A helper function to access the calculated cost
    double get_item_cost() const {
        return item_cost;
    }
};


// --- Base Class 2 ---
class Shipping_details {
protected:
    double shipping_charge;

public:
    void get_shipping_details() {
        std::cout << "\n--- Enter Shipping Details ---" << std::endl;
        std::cout << "Enter shipping charge (in $): ";
        std::cin >> shipping_charge;
    }

    // A helper function to access the shipping charge
    double get_shipping_charge() const {
        return shipping_charge;
    }
};


// --- Derived Class (Multiple Inheritance) ---
// The Bill class publicly inherits from both online_shopping and Shipping_details
class Bill : public online_shopping, public Shipping_details {
private:
    double total_bill;

public:
    void calculate_bill() {
        // We can access the protected members (or public methods) of the base classes
        // Note: I'm using the public getter methods for clarity and good practice.
        total_bill = get_item_cost() + get_shipping_charge();
    }

    void display_bill() {
        // Set precision for currency display
        std::cout << std::fixed << std::setprecision(2);
        
        std::cout << "\n==================================" << std::endl;
        std::cout << "            FINAL BILL            " << std::endl;
        std::cout << "==================================" << std::endl;
        
        // Display details inherited from online_shopping
        std::cout << "Item Name     : " << item_name << std::endl;
        std::cout << "Quantity      : " << quantity << std::endl;
        std::cout << "Unit Price    : $" << unit_price << std::endl;
        std::cout << "----------------------------------" << std::endl;
        std::cout << "Item Total Cost : $" << get_item_cost() << std::endl;
        
        // Display details inherited from Shipping_details
        std::cout << "Shipping Charge : $" << get_shipping_charge() << std::endl;
        std::cout << "----------------------------------" << std::endl;
        
        // Display the final calculation
        std::cout << "TOTAL AMOUNT DUE: $" << total_bill << std::endl;
        std::cout << "==================================" << std::endl;
    }
};

// --- Main Function ---
int main() {
    // 1. Create an object of the derived class
    Bill final_bill;

    // 2. Call methods inherited from the first base class (online_shopping)
    final_bill.get_item_details();
    
    // 3. Call methods inherited from the second base class (Shipping_details)
    final_bill.get_shipping_details();
    
    // 4. Call the method specific to the derived class (Bill)
    final_bill.calculate_bill();

    // 5. Display the result
    final_bill.display_bill();
    
    return 0;
}
