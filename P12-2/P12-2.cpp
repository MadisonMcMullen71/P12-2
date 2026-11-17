
#include <iostream>
#include <string>
using namespace std;

// Function prototype
bool isLeapYear(int year);

int main() {

    string input;
    int year;

    while (true) {

        cout << "Enter a year or Q to quit: ";
        cin >> input;

        if (input == "Q" || input == "q") {
            break;
        }

        year = stoi(input);

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
