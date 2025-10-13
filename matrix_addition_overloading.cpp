#include <iostream>
using namespace std;

class Matrix {
private:
    int a[3][3]; // 3x3 matrix

public:
    // Function to input matrix elements
    void input() {
        cout << "Enter 3x3 matrix elements:\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> a[i][j];
            }
        }
    }

    // Overload + operator to add two matrices
    Matrix operator+(const Matrix &m) {
        Matrix temp;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                temp.a[i][j] = a[i][j] + m.a[i][j];
            }
        }
        return temp;
    }

    // Function to display the matrix
    void display() const {
        cout << "Matrix:\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << a[i][j] << "\t";
            }
            cout << endl;
        }
    }
};

int main() {
    Matrix m1, m2, m3;

    cout << "Enter elements of first matrix:\n";
    m1.input();

    cout << "\nEnter elements of second matrix:\n";
    m2.input();

    // Using overloaded + operator
    m3 = m1 + m2;

    cout << "\nResultant Matrix after addition:\n";
    m3.display();

    return 0;
}
