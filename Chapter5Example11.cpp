// File Name: Chapter5Ex11.cpp
// Developer/Programmer: FirstName LastName
// Date: 04/25
// Requirements: This program calculates and displays the size of a growing population day by day, with full input validation and repeatability.

#include <iostream>
#include <iomanip>

using namespace std;

// This module gets and validates user input
void getInput(double& startPop, double& dailyIncrease, int& days) {
    do {
        cout << "Enter starting population (minimum 2): ";
        cin >> startPop;
        if (startPop < 2)
            cout << "Error: Starting population must be at least 2.\n";
    } while (startPop < 2);

    do {
        cout << "Enter average daily increase (%): ";
        cin >> dailyIncrease;
        if (dailyIncrease < 0)
            cout << "Error: Daily increase cannot be negative.\n";
    } while (dailyIncrease < 0);

    do {
        cout << "Enter number of days to multiply (minimum 1): ";
        cin >> days;
        if (days < 1)
            cout << "Error: Number of days must be at least 1.\n";
    } while (days < 1);
}

// This module calculates and displays population for each day
void displayPopulation(double startPop, double dailyIncrease, int days) {
    double population = startPop;
    cout << fixed << setprecision(2);
    cout << "\nDay\tPopulation\n";
    for (int day = 1; day <= days; day++) {
        cout << day << "\t" << population << endl;
        population += (population * (dailyIncrease / 100));
    }
}

// Main module
int main() {
    double startPop, dailyIncrease;
    int days;
    char repeat;

    do {
        getInput(startPop, dailyIncrease, days);
        displayPopulation(startPop, dailyIncrease, days);

        cout << "\nWould you like to run the program again? (Y/N): ";
        cin >> repeat;
        cout << endl;
    } while (repeat == 'Y' || repeat == 'y');

    cout << "Program ended.\n";
    return 0;
}
