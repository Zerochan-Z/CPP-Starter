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

Next version: 
1. File save/load
2. Input Validation
3. Edit / Delete
*/

string getTitle (string prompt) {
    string result = prompt;
    bool upper = true;
    
    for (size_t i = 0; i < result.length(); i++) {
        if (isspace(result[i])) {
            upper = true;
        } else if (upper) {
            result[i] = toupper(result[i]);
            upper = false;
        } else {
            result[i] = tolower(result[i]);
        }
    }
    return result;
}

string getLower(string prompt) {
    string result = prompt;

    for (size_t i = 0; i < result.length(); i++) {
        result[i] = tolower(result[i]);
    }
    return result;
}

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
    void setDescription(string des) { description = des; }
    void setAmount(double a) { amount = a; }
    void setDistance(double d) { distance = d; }


    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
    string getCategory() const { return category; }
    string getSubcategory() const { return subcategory; }
    string getDescription() const { return description; }
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
        /*  1. Enter date.
            2. Enter category (Food, Transportation, Rental).
            3. While user wants to continue:
            a. Enter subcategory.
            b. Enter amount.
            c. Enter description (optional).
            d. If category is Transportation → Enter distance.
            e. Ask: "Add another expense for this date/category?"
            4. Return to main menu.
        */

        int day, month, year;
        string category, subcategory, description;
        double amount, distance;
        
        cout << "Enter current day: ";
        cin >> day;
        cout << "Enter current month: ";
        cin >> month;
        cout << "Enter current year: ";
        cin >> year;
        cout << "Category: Food, Rental, Transportation, Others \n";
        cout << "Enter your category: ";
        cin >> category;
        bool repeat = true;
        char cont;
        
        do {
            distance = 0;
            cout << "Enter subcategory: ";
            cin >> subcategory;
            cout << "Enter amount: ";
            cin >> amount;
            cout << "Enter description: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, description);
            if (getLower(category) == "transportation") {
                cout << "Enter distance: ";
                cin >> distance;
            }
            
            Expense* e = new Expense(day, month, year, category, subcategory, description, amount, distance);
            exp.push_back(e);

            do {
                cout << "Continue? (Y/N): ";
                cin >> cont;

                if (toupper(cont) == 'Y') {
                    repeat = true;
                } else if (toupper(cont) == 'N') {
                    repeat = false;
                } else {
                    cout << "Invalid input.\n";
                }
            } while (toupper(cont) != 'Y' && toupper(cont) != 'N');
           
        } while (repeat);

    }

    void viewExpenseHistory() {
        if (exp.empty()) {
            cout << "Nothing to view.\n"; 
            return;
        }

        cout << left << setw(15) << "Date"
             << setw(20) << "Subcategory"
             << setw(8) << "Amount"
             << setw(15) << "Description"
             << setw(8) << "Distance" << endl;
        string last = "";

        for (size_t i = 0; i < exp.size(); i++) {
            if (last != getLower(exp[i]->getCategory())) {
                cout << string(25, '-') << exp[i]->getCategory() << string(25, '-') << endl;
            }
            cout << left << setw(15) << getDateStr(exp[i]->getDay(), exp[i]->getMonth(), exp[i]->getYear())
                << setw(20) << exp[i]->getSubcategory()
                << setw(8) << exp[i]->getAmount()
                 << setw(15) << exp[i]->getDescription();
            if (getLower(exp[i]->getCategory()) == "transportation") {
            cout << left << setw(8) << exp[i]->getDistance() << endl;
            } cout << endl;
            last = getLower(exp[i]->getCategory());
        }

    }

    void displayReport(const Budget& bud) {
        if (exp.empty()) {
            cout << "No info to form report.\n";
            return;
        }

        double sum = 0;
        double food = 0;
        double transport = 0;
        double rental = 0; 
        double others = 0;
        double budget = bud.getHousehold() + bud.getSalary();

        for (size_t i = 0; i <exp.size(); i++) {
            sum += exp[i]->getAmount();

            if (getLower(exp[i]->getCategory()) == "food") {
                food += exp[i]->getAmount();
            } else if (getLower(exp[i]->getCategory()) == "transportation") {
                transport += exp[i]->getAmount();
            } else if (getLower(exp[i]->getCategory()) == "rental") {
                rental += exp[i]->getAmount();
            } else if (getLower(exp[i]->getCategory()) == "others") {
                others += exp[i]->getAmount();
            } else cout << exp[i]->getCategory() << " is not categorised.\n"; 
        }

        cout << "\n" << string(20, '-') << " Report " << string(20, '-') << endl;
        cout << left << setw(20) << "Budget"
             << setw(20) << "Total Expenses"
             << setw(10) << "CashFlow" << endl;

        cout << left << setw(20) << "RM " << budget
             << setw(20) << "RM " << sum
             << setw(10) << "RM " << budget - sum << endl;

        char choice;
        cout << "Do you want to know about category breakdown? " << endl;
        cout << "Choice (Y/N): ";
        cin >> choice;

        while (true) {
            if (toupper(choice) == 'Y') {
                cout << left << setw(30) << "Food: " << "RM " << food << endl; 
                cout << left << setw(30) << "Transportation: " << "RM " << transport << endl;
                cout << left << setw(30) << "Rental: " << "RM " << rental << endl;
                cout << left << setw(30) << "Others: " << "RM " << others << endl;
                break;
            } else if (toupper(choice) == 'N') {
                cout << "End of report\n";
                break;
            } else {
                cout << "Invalid input.\n";
                cout << "Please enter (Y/N): ";
                cin >> choice;
            }
        }       
    }
};

int main() {
    Budget bud;
    ExpenseTracker track;

    int choice;

    do {
        cout << "\n1. Enter budget.\n";
        cout << "2. Enter expenses\n";
        cout << "3. View expenses history.\n";
        cout << "4. View summarise report.\n";
        cout << "5. Exits.\n";
        cout << "Enter choice: ";
        cin >> choice;

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
            case 3: track.viewExpenseHistory(); break;
            case 4: track.displayReport(bud); break;
            case 5: cout << "Thanks for using this system.\n"; break;
        }
    } while (choice != 5);


}