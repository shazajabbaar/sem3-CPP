#include <iostream>
#include <iomanip>
using namespace std;

class Time {
private:
    int hours, minutes, seconds;

public:
    void inputTime() {
        cout << "Enter time (hours minutes seconds): ";
        cin >> hours >> minutes >> seconds;
    }

    void displayTime() {
        cout << "Formatted Time: "
             << setw(2) << setfill('0') << hours << ":"
             << setw(2) << setfill('0') << minutes << ":"
             << setw(2) << setfill('0') << seconds << endl;
    }
};

int main() {
    Time t;
    t.inputTime();
    t.displayTime();
    return 0;
}
