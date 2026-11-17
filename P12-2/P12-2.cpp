
#include <iostream>
#include <string>
using namespace std;

// Function prototypes
bool isLeapYear(int year);
int daysInMonth(int month, int year);

int main() {

    string input;
    int month;
    int year;

    string monthNames[12] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    while (true) {

        cout << "Enter a month and year or Q to quit: ";
        cin >> input;

        if (input == "Q" || input == "q") {
            break;
        }

        month = stoi(input);
        cin >> year;

        int days = daysInMonth(month, year);

        cout << monthNames[month - 1] << " " << year
            << " has " << days << " days." << endl;

        if (isLeapYear(year)) {
            cout << year << " is a leap year." << endl;
        }
        else {
            cout << year << " is not a leap year." << endl;
        }
    }

    return 0;
}

bool isLeapYear(int year) {

    if (year % 400 == 0) {
        return true;
    }
    else if (year % 100 == 0) {
        return false;
    }
    else if (year % 4 == 0) {
        return true;
    }
    else {
        return false;
    }
}

int daysInMonth(int month, int year) {

    if (month == 2) {
        if (isLeapYear(year)) {
            return 29;
        }
        else {
            return 28;
        }
    }
    else if (month == 4 || month == 6 ||
        month == 9 || month == 11) {
        return 30;
    }
    else {
        return 31;
    }
}
