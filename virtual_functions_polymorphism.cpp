#include <iostream>
#include <cmath> 


class c_polygon {
protected:
    double dim1, dim2; // Common dimensions: base/height or length/width

public:
    
    c_polygon(double d1 = 0, double d2 = 0) : dim1(d1), dim2(d2) {}

     Function, turning c_polygon into an Abstract Class.
    
    virtual double area() const = 0;

    void get_dimensions() {
        std::cout << "Enter first dimension: ";
        std::cin >> dim1;
        std::cout << "Enter second dimension: ";
        std::cin >> dim2;
    }
    
    
    virtual ~c_polygon() {}
};

// --- Derived Class 1: Rectangle ---
class c_rectangle : public c_polygon {
public:
    c_rectangle() : c_polygon() {}

    // Override the virtual function to calculate rectangle area
    double area() const override {
        // Area = length * width (dim1 * dim2)
        return dim1 * dim2;
    }
};

// --- Derived Class 2: Triangle ---
class c_traingle : public c_polygon {
public:
    c_traingle() : c_polygon() {}

    // Override the virtual function to calculate triangle area
    double area() const override {
        // Area = 0.5 * base * height (0.5 * dim1 * dim2)
        return 0.5 * dim1 * dim2;
    }
};

// --- Main Function to Demonstrate Polymorphism ---
int main() {
    // A base class pointer can point to any derived class object
    c_polygon* shapePtr = nullptr;
    double calculatedArea = 0.0;
    int choice;

    std::cout << "---------------------------------------" << std::endl;
    std::cout << "1. Calculate Rectangle Area" << std::endl;
    std::cout << "2. Calculate Triangle Area" << std::endl;
    std::cout << "Enter your choice (1 or 2): ";
    std::cin >> choice;
    std::cout << "---------------------------------------" << std::endl;

    if (choice == 1) {
        c_rectangle rect;
        rect.get_dimensions();
        shapePtr = &rect; // Assign the rectangle object's address to the base class pointer
        
        // This call to area() is resolved at runtime (Polymorphism)
        calculatedArea = shapePtr->area();
        
    } else if (choice == 2) {
        c_traingle tri;
        tri.get_dimensions();
        shapePtr = &tri; // Assign the triangle object's address to the base class pointer
        
        // This call to area() is resolved at runtime (Polymorphism)
        calculatedArea = shapePtr->area();
        
    } else {
        std::cout << "Invalid choice." << std::endl;
        return 1;
    }
    
    // The output logic is unified, proving the effectiveness of the virtual function
    std::cout << "\nResult calculated via base class pointer:" << std::endl;
    std::cout << "The Area is: " << calculatedArea << std::endl;
    std::cout << "---------------------------------------" << std::endl;

    // Note: No need for 'delete shapePtr' since it points to a stack-allocated object.

    return 0;
}
