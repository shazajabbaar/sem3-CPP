#include <iostream>
#include <string>
#include <iomanip>

// --- Virtual Base Class: Student ---
class Student {
private: // Changed to private for better encapsulation
    std::string Name;
    int Rollno;
    std::string Course;

public:
    // Added a constructor for potential direct initialization (optional but good)
    Student(std::string n = "", int r = 0, std::string c = "") 
        : Name(n), Rollno(r), Course(c) {}

    void get_student_details() {
        std::cout << "--- Enter Student Details ---" << std::endl;
        std::cout << "Enter Name: ";
        // Use std::cin.ignore() only if necessary, or better, flush the buffer
        // Note: The previous call to std::cin >> Rollno should leave a newline, 
        // but since it's the first input, ignore is usually fine, but let's 
        // be explicit with basic cin first.
        std::cin.ignore(100, '\n'); // Clear buffer before reading name with spaces
        std::getline(std::cin, Name);
        std::cout << "Enter Roll No: ";
        std::cin >> Rollno;
        std::cout << "Enter Course: ";
        std::cin >> Course;
    }

    void display_student_details() const {
        std::cout << "Name    : " << Name << std::endl;
        std::cout << "Roll No : " << Rollno << std::endl;
        std::cout << "Course  : " << Course << std::endl;
    }
};


// --- Intermediate Derived Class 1: Test ---
class Test : virtual public Student {
protected:
    int marks[3];
    int total_test_marks;

public:
    // Intermediate constructors should explicitly call the Student constructor 
    // IF Student had mandatory parameters, but since it's virtual, only 
    // the most derived class (Result) will actually call it. We keep 
    // the default call for clarity.
    Test() : Student(), total_test_marks(0) {}

    void get_marks() {
        std::cout << "\n--- Enter Marks (Max 100 each) ---" << std::endl;
        total_test_marks = 0; // Reset just in case
        for (int i = 0; i < 3; ++i) {
            std::cout << "Enter marks for Subject " << i + 1 << ": ";
            std::cin >> marks[i];
            total_test_marks += marks[i];
        }
    }

    void display_marks() const {
        std::cout << "Marks (Sub 1, 2, 3) : " << marks[0] << ", " << marks[1] << ", " << marks[2] << std::endl;
    }

    int get_total_test_marks() const { return total_test_marks; }
};


// --- Intermediate Derived Class 2: GraceMarks ---
class GraceMarks : virtual public Student {
protected:
    int BonusMark;

public:
    GraceMarks() : Student(), BonusMark(0) {}

    void get_bonus_mark() {
        std::cout << "\n--- Enter Bonus Marks ---" << std::endl;
        std::cout << "Enter Bonus Mark: ";
        std::cin >> BonusMark;
    }

    int get_bonus_mark_value() const { return BonusMark; }
};


// --- Final Derived Class: Result ---
// The most derived class, responsible for calling the Virtual Base Class constructor.
class Result : public Test, public GraceMarks {
private:
    int Total_marks;

public:
    // IMPORTANT: Even though Student is virtual, we explicitly call its constructor
    // here. The compiler uses this call ONLY from the most derived class.
    Result() : Student(), Test(), GraceMarks(), Total_marks(0) {}

    void calculate_total_marks() {
        // Total = Test Marks + Bonus Mark
        Total_marks = get_total_test_marks() + get_bonus_mark_value();
    }

    void display_result() {
        std::cout << "\n==================================" << std::endl;
        std::cout << "           STUDENT RESULT         " << std::endl;
        std::cout << "==================================" << std::endl;
        
        // This accesses the SINGLE shared Student object:
        display_student_details(); 
        
        std::cout << "----------------------------------" << std::endl;
        
        // Data members from other classes:
        display_marks();
        std::cout << "Bonus Mark      : " << get_bonus_mark_value() << std::endl;
        
        std::cout << "----------------------------------" << std::endl;
        std::cout << "Total Marks     : " << Total_marks << std::endl;
        std::cout << "==================================" << std::endl;
    }
};

// --- Main Function ---
int main() {
    Result student_result;

    // 1. Get data for all base classes
    student_result.get_student_details(); // Populates the shared Student data
    student_result.get_marks();           // Populates Test data
    student_result.get_bonus_mark();      // Populates GraceMarks data

    // 2. Calculate the final result
    student_result.calculate_total_marks();

    // 3. Display all details
    student_result.display_result();

    return 0;
}
