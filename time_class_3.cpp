#include <iostream>
using namespace std;

class Time {
private:
    int hours, minutes, seconds;

public:
    void inputTime() {
        cout << "Enter hours, minutes and seconds: ";
        cin >> hours >> minutes >> seconds;
    }

    void displayTime() const {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }

    friend Time addTime(const Time &t1, const Time &t2);
};

Time addTime(const Time &t1, const Time &t2) {
    Time temp;
    temp.seconds = t1.seconds + t2.seconds;
    temp.minutes = t1.minutes + t2.minutes + temp.seconds / 60;
    temp.seconds %= 60;
    temp.hours = t1.hours + t2.hours + temp.minutes / 60;
    temp.minutes %= 60;
    return temp;
}

int main() {
    Time t1, t2, t3;

    cout << "Enter first time:\n";
    t1.inputTime();

    cout << "Enter second time:\n";
    t2.inputTime();

    t3 = addTime(t1, t2);

    cout << "\nSum of times: ";
    t3.displayTime();

    return 0;
}
