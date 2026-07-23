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

string getDateStr(int d, int m, int y) {
    string day = to_string(d);
    string month = to_string(m);
    string year = to_string(y);

    if (month.length() == 1) month = "0" + month;
    if (day.length() == 1) day = "0" + day;

    return year + "-" + month + "-" + day;
}

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
        return MonthlyIncome(HouseholdExpenses, partTime) / 4;
    }
};

class Expense {
private: 
    int day, month, year;
    string category, subcategory, description;
    double amount, distance;

public:
    Expense(): 
    day(0), month(0), year(0), category(""), subcategory(""), description(""), amount(0.00), distance(0.00) {}
    Expense(int da, int mon, int yea, string c, string s, string d, double a, double dis): 
    day(da), month(mon), year(yea), category(c), subcategory(s), description(d), amount(a), distance(dis) {}
    
    void setDay(int d) { day = d; }
    void setMonth(int m) { month = m; }
    void setYear(int y) { year = y; }
    void setCategory(string c) { category = c; }
    void setSubCategory(string s) { subcategory = s; }
    void setAmount(double a) { amount = a; }
    void setDistance(double d) { distance = d; }


    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
    string getCategory() const { return category; }
    string getSubcategory() const { return subcategory; }
    double getAmount() const { return amount; }
    double getDistance() const { return distance; }
    

    void display() const {
        cout << left << setw(20) << getDateStr(day, month, year)
             << setw(20) << category 
             << setw(20) << subcategory
             << setw(15) << amount
             << setw(10) << distance << endl;
        cout << string(65, '-') << endl; 

    }
};

class ExpenseTracker {
private:
    vector <Expense*> exp;

public:
    ExpenseTracker() {}
    ~ExpenseTracker() {
        for (size_t i = 0; i < exp.size(); i++) {
            delete exp[i];
        }
    }



    void addExpense() {
        int choice;
        
        do {
            cout << "\n1. Date\n";
            cout << "2. Category\n";
            cout << "3. Subcategory\n";
            cout << "4. Description.\n";
            cout << "5. Amount\n";
            cout << "6. Distance\n";
            cout << "7. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    int day, month, year;
                    cout << "Enter day: ";
                    cin >> day;
                    cout << "Enter month: ";
                    cin >> month;
                    cout << "Enter year: ";
                    cin >> year;
                    break;
                }
            }
            Expense* e = nullptr;
            e = new Expense(day, month)
        } while (choice != 7);

        
    }
};

int main() {
    Budget bud;
    ExpenseTracker track;

    int choice;

    do {
        cout << "\n1. Enter enpenses.\n";
        cout << "2. View expenses history.\n";
        cout << "3. View Report.\n";
        cout << "4. Manage Budget.\n";
        cout << "5. \n";

        switch (choice) {
            case 1: {
                double household, part;
                cout << "Enter household expenses: ";
                cin >> household;
                bud.setHousehold(household);
                cout << "Enter approximate part time salary: ";
                cin >> part;
                bud.setSalary(part);
                break;
            }
            case 2: track.addExpense(); break;
            case 3: 
            case 4:
                case 5: cout << "Thanks for using this system.\n"; break;
        }
    } while (choice != );


}