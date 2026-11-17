
#include <iostream>
#include <string>
using namespace std;

bool isLeapYear(int year);
int daysInMonth(int month, int year);
int dayOfWeek(int month, int day, int year);

int main() {
    string input;
    int month, day, year;

    string days[] = {
        "Saturday", "Sunday", "Monday", "Tuesday",
        "Wednesday", "Thursday", "Friday"
    };

    string months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    cout << "Enter a date or Q to quit: ";
    cin >> input;

    while (input != "Q" && input != "q") {
        month = stoi(input);
        cin >> day >> year;

        int weekday = dayOfWeek(month, day, year);

        cout << days[weekday] << ", "
            << months[month - 1] << " "
            << day << ", " << year << endl;

        cout << "Enter a date or Q to quit: ";
        cin >> input;
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

int dayOfWeek(int month, int day, int year) {
    int m = month;
    int Y = year;

    if (m == 1 || m == 2) {
        m = m + 12;
        Y = Y - 1;
    }

    int K = Y % 100;
    int J = Y / 100;

    int h = (day + (13 * (m + 1)) / 5 + K
        + K / 4 + J / 4 + 5 * J) % 7;

    return h;
}
