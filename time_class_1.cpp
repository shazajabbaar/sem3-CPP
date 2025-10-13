#include <iostream>
using namespace std;

class Time {
private:
    int hours, minutes, seconds;

public:
    void inputTime() {
        cout << "Enter hours: ";
        cin >> hours;
        cout << "Enter minutes: ";
        cin >> minutes;
        cout << "Enter seconds: ";
        cin >> seconds;
    }

    void displayTime() {
        cout << "Time: " << hours << ":" << minutes << ":" << seconds << endl;
    }
};

int main() {
    Time t;
    t.inputTime();
    t.displayTime();
    return 0;
}
