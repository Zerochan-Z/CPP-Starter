#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <limits>
#include <vector>
#include <iomanip>
using namespace std;

/* 
Student Expense Tracker 
1. Monthly budget & Income - Cash Flow 
2. Weekly expenses (food, rental, snacks, electricity & water)
3. Category, subcategory (cost + details), date, description (opt) 
*/

class Budget {
private :
    double HouseholdExpenses, partTime;

public:
    Budget(): HouseholdExpenses(0), partTime(0) {}
    Budget(double h, double p): HouseholdExpenses(h), partTime(p) {}

    double getHousehold() const { return HouseholdExpenses; }
    double getSalary() const { return partTime; }

    void setHousehold(double h) { HouseholdExpenses = h; }
    void setSalary(double p) { partTime = p; }

    double MonthlyIncome(double h, double p) const {
        return h + p;
    }

    double WeeklyIncome() {
        return MonthlyIncome() / 4;
    }
};

int main() {
    

    int choice;

    do {
        cout << "\n1. Enter enpenses.\n";
        cout << "2. View expenses history.\n";
        cout << "3. View Report.\n";
        cout << "4. Manage Budget.\n";
        cout << "5. \n";
    } while (choice != );

    switch (choice) {
        case 1: {
            cout << "Enter household expenses: ";
            double h;
            cin >> h;
            Budget->setHousehold(h);
            cout << "Enter approximate part time salary: ";
            cin >> partTime;
            break;
        }
        case 2:
        case 3: 
        case 4:
        case 5: cout << "Thanks for using this system.\n"; break;
    }
}