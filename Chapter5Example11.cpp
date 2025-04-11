// File Name: Chapter5Example11.cpp
// Developer/Programmer: FirstName LastName
// Date: 04/25
// Requirements: This program calculates and displays the size of a growing population day by day.

#include <iostream>
using namespace std;

// Gets a valid starting population (2 or more)
int getStartingPopulation() {
    int pop;
    while (true) {
        cout << "Enter starting population (minimum 2): ";
        cin >> pop;
        if (cin.fail() || pop < 2) {
            cout << "Invalid input. Please enter a number which is larger than or equal 2.\n";
            cin.clear();
            string dump;
            cin >> dump; // discard bad input
        }
        else {
            return pop;
        }
    }
}

// Gets a valid daily increase percentage (0 or more)
double getDailyIncrease() {
    double percent;
    while (true) {
        cout << "Enter average daily increase (as %): ";
        cin >> percent;
        if (cin.fail() || percent < 0) {
            cout << "Invalid input. Please enter a number  which is equal to or higher than 0.\n";
            cin.clear();
            string dump;
            cin >> dump; // discard bad input
        }
        else {
            return percent;
        }
    }
}

// Gets a valid number of days (1 or more)
int getDays() {
    int days;
    while (true) {
        cout << "Enter number of days (minimum 1): ";
        cin >> days;
        if (cin.fail() || days < 1) {
            cout << "Invalid input. Please enter a number equal to or higher than 1.\n";
            cin.clear();
            string dump;
            cin >> dump; // discard bad input
        }
        else {
            return days;
        }
    }
}

// Shows the population each day
void showPopulation(int start, double increase, int days) {
    double pop = start;
    cout << "\nDay\tPopulation\n";
    for (int i = 1; i <= days; i++) {
        cout << i << "\t" << pop << endl;
        pop = pop + (pop * (increase / 100));
    }
}

// Asks user if they want to run the program again
bool askToContinue() {
    char choice;
    while (true) {
        cout << "\nWould you like to run the program again? (y/n): ";
        cin >> choice;
        choice = tolower(choice);
        if (choice == 'y') return true;
        else if (choice == 'n') return false;
        else {
            cout << "Invalid input. Please enter 'y' or 'n'.\n";
            string dump;
            cin >> dump;
        }
    }
}

// Main function
int main() {
    cout << "Welcome to the Population Growth Program!\n";

    bool keepGoing = true;
    while (keepGoing) {
        int start = getStartingPopulation();
        double increase = getDailyIncrease();
        int days = getDays();

        showPopulation(start, increase, days);
        keepGoing = askToContinue();
    }

    cout << "\nThank you for using the program! Goodbye.\n";
    return 0;
}
