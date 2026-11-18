
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Function prototypes
bool isLeapYear(int year);
int daysInMonth(int month, int year);
int dayOfWeek(int month, int day, int year);

int main() {
    string input;
    int month, year, day;
     
    string months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    string weekdays[] = {
        "Saturday", "Sunday", "Monday", "Tuesday",
        "Wednesday", "Thursday", "Friday"
    };

    cout << "Enter a month and year or Q to quit: ";
    cin >> input;

    while (input != "Q" && input != "q") {
        month = stoi(input);
        cin >> year;

        // Step 1: Check leap year
        if (isLeapYear(year)) {
            cout << year << " is a leap year." << endl;
        }
        else {
            cout << year << " is not a leap year." << endl;
        }

        // Step 2: Find days in the month
        int totalDays = daysInMonth(month, year);

        cout << months[month - 1] << " " << year
            << " has " << totalDays << " days." << endl;

        // Step 3: Find the day of the week
        int firstDay = dayOfWeek(month, day, year);

        //cout << months[month - 1] << " 1, " << year
        //   << " is a " << weekdays[firstDay] << "." << endl;

        // Step 4: Print the calendar
        cout << endl;
        cout << "       " << months[month - 1]
            << " " << year << endl;

        cout << "Su Mo Tu We Th Fr Sa" << endl;

        // Create an array for the calendar
        int calendarDays[6][7] = {};

        // Find the starting weekday
        int startDay = (firstDay + 6) % 7;

        // Put each date in the correct position
        for (int day = 1; day <= totalDays; day++) {
            int position = day - 1 + startDay;

            int row = position / 7;
            int column = position % 7;

            calendarDays[row][column] = day;
        }

        // Print the calendar
        int numberOfWeeks = (totalDays + startDay + 6) / 7;

        for (int i = 0; i < numberOfWeeks; i++) {
            for (int j = 0; j < 7; j++) {
                if (calendarDays[i][j] == 0) {
                    cout << setw(3) << " ";
                }
                else {
                    cout << setw(3) << calendarDays[i][j];
                }
            }

            cout << endl;
        
        }

        cout << endl;

        cout << "Enter a month and year or Q to quit: ";
        cin >> input;
    }

    return 0;
}

// Step 1: Determine if a year is a leap year
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

// Step 2: Determine the number of days in a month
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

// Step 3: Determine the day of the week
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
