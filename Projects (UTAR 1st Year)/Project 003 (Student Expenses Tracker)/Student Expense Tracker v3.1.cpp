#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <limits>
#include <vector>
#include <iomanip>
#include <sstream>
using namespace std;

/* 
Student Expense Tracker 
1. Monthly budget & Income - Cash Flow 
2. Weekly expenses (food, rental, snacks, electricity & water)
3. Category, subcategory (cost + details), date, description (opt) 

Next version: 
1. Input Validation (Done)
2. Sort Date & catergory (Ascending)
*/

int validInt(const string& prompt, int min, int max) {
    int num;

    while (true) {
        cout << prompt;
        cin >> num;
        if (cin.fail() || num < min || num > max) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid data input.\n";
        } else {
            break;
        }
    }
    return num;
}

double validDouble(const string &prompt, double min) {
    double result;

    while (true) {
        cout << prompt;
        cin >> result;
        if (cin.fail() || result < min) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid data input.\n";
        } else {
            break;
        }
    }
    return result;
}

string validStr(const string &prompt, vector <string> options, bool allowEmpty) {
    string result;

    while (true) {
        cout << prompt;
        getline(cin, result);

        if (allowEmpty == false && result.empty()) {
            cout << "Please enter a string.\n";
            continue;
        }

        if (options.empty()) {
            return result;
        }
        for (size_t i = 0; i < options.size(); i++) {
            if (result == options[i]) {
                return result;
            } 
        }
        cout << "Error data input.\n";
        continue;
    }
}

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
    double HouseholdExpenses, salary;

public:
    Budget(): HouseholdExpenses(0), salary(0) {}
    Budget(double h, double p): HouseholdExpenses(h), salary(p) {}

    double getHousehold() const { return HouseholdExpenses; }
    double getSalary() const { return salary; }

    void setHousehold(double h) { HouseholdExpenses = h; }
    void setSalary(double p) { salary = p; }

    double MonthlyIncome(double h, double p) const {
        return h + p;
    }

    double WeeklyIncome() {
        return MonthlyIncome(HouseholdExpenses, salary) / 4;
    }

    void saveBudget() {
        ofstream outFile("budget.txt");

        if (!outFile) {
            cout << "No saved file.\n";
            return;
        }

        outFile << HouseholdExpenses << " | " << salary << endl;

        outFile.close();
        cout << "File saved.\n";
    }

    void loadBudget() {
        ifstream inFile("budget.txt");
        
        if (!inFile) {
            cout << "No budget load.\n";
            return;
        }

        string line;
        getline(inFile, line);
        size_t pos1 = line.find(" | ");
        if (pos1 == string::npos) {
            cout << "Empty file.\n";
            return;
        }
        
        double HouseHold = stod(line.substr(0, pos1));
        double partTime = stod(line.substr(pos1 + 3));
        HouseholdExpenses = HouseHold;
        salary = partTime;
        
        inFile.close();
        cout << "Budget loaded.\n";
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

    void saveExpense() {
        ofstream outFile("expenses.txt");

        if (!outFile) {
            cout << "No expenses is saved.\n";
            return;
        }

        for (size_t i = 0; i < exp.size(); i++) {
            outFile << exp[i]->getDay() << " | " << exp[i]->getMonth() << " | " << exp[i]->getYear() << " | "
                    << exp[i]->getCategory() << " | " << exp[i]->getSubcategory() << " | "
                    << exp[i]->getAmount() << " | " << exp[i]->getDistance() 
                    << " | " << exp[i]->getDescription() << endl;
        }

        outFile.close();
        cout << exp.size() << " expense(s) saved.\n";
    }

    void loadExpenses() {
        ifstream inFile("expenses.txt");
        if (!inFile) {
            cout << "No expenses loaded.\n";
            return;
        }

        for (size_t i = 0; i < exp.size(); i++) {
            delete exp[i];
            // exp[i] is a pointer holding an address
            // delete object that located in that address
            // there's still pointer exists just nothing inside the address
        }

        exp.clear();
        // remove the address what a pointer used

        string line;

        while (getline(inFile, line)) {
            size_t pos1 = line.find(" | ");
            size_t pos2 = line.find(" | ", pos1 + 3);
            size_t pos3 = line.find(" | ", pos2 + 3);
            size_t pos4 = line.find(" | ", pos3 + 3);
            size_t pos5 = line.find(" | ", pos4 + 3);
            size_t pos6 = line.find(" | ", pos5 + 3);
            size_t pos7 = line.find(" | ", pos6 + 3);

            // Once one of the element not detected, skip
            if (pos1 == string::npos || pos2 == string::npos || pos3 == string::npos || pos4 == string::npos || pos5 == string::npos || pos6 == string::npos || pos7 == string::npos ) {
                cout << "Error detected. Skipping the line.\n";
                continue;
            }

            double distance = 0;
            int day = stoi(line.substr(0, pos1));
            int month = stoi(line.substr(pos1 + 3, pos2 - pos1 - 3));
            int year = stoi(line.substr(pos2 + 3, pos3 - pos2 - 3));
            string category = line.substr(pos3 + 3, pos4 - pos3 - 3);
            string subcategory = line.substr(pos4 + 3, pos5 - pos4 - 3);
            double amount = stod(line.substr(pos5 + 3, pos6 - pos5 - 3));
            distance = stod(line.substr(pos6 + 3, pos7 - pos6 - 3));
            string description = line.substr(pos7 + 3);

            Expense* e = new Expense(day, month, year, category, subcategory, description, amount, distance);
            exp.push_back(e);
        }

        inFile.close();
        cout << exp.size() << " expense(s) loaded.\n";

    }

    void exportCSV() {
        ofstream outFile("expenses.csv");

        if (!outFile) {
            cout << "Nothing to export.\n";
            return;
        }

        ostringstream amountOss, distanceOss;
        outFile << "Date,Category,Subcategory,Amount,Distance,Description" << endl;
        for (size_t i = 0; i < exp.size(); i++) {
            string date = getDateStr(exp[i]->getDay(), exp[i]->getMonth(), exp[i]->getYear());

            string whole;
            amountOss << fixed << setprecision(2) << exp[i]->getAmount();
            distanceOss << fixed << setprecision(2) << exp[i]->getDistance();
            if (exp[i]->getDescription().find(',') != string::npos) {
                whole = "\"" + exp[i]->getDescription() + "\"";
            } else {
                whole = exp[i]->getDescription();
            }

            outFile << date << "," << exp[i]->getCategory()
                    << "," << exp[i]->getSubcategory()
                    << "," << amountOss.str()
                    << "," << distanceOss.str()
                    << "," << whole << endl;
        }
        outFile.close();
        cout << "CSV saved.\n";
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
        
        day = validInt("Enter current day: ", 1, 31);
        month = validInt("Enter current month: ", 1, 12);
        year = validInt("Enter current year: ", 2000, 2026);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Category: Food, Rental, Transportation, Others \n";
        category = validStr("Enter category: ", {"Food","Rental","Transportation","Others"}, false);
        bool repeat = true;
        
        do {
            distance = 0.00;
            subcategory = validStr("Enter subcategory: ", {}, false);
            amount = validDouble("Enter amount (RM): ", 0.00);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            description = validStr("Enter description: ", {}, true);
            if (getLower(category) == "transportation") {
                distance = validDouble("Enter distance (km): ", 0.00);
            }
            
            Expense* e = new Expense(day, month, year, category, subcategory, description, amount, distance);
            exp.push_back(e);

            char cont;
            do {
                cout << "Continue? (Y/N): ";
                cin >> cont;

                if (toupper(cont) == 'Y') {
                    repeat = true;
                } else if (toupper(cont) == 'N') {
                    repeat = false;
                } else {
                    cout << "Invalid input.\n";
                    cout << "Please enter Y/N.\n";
                }
            } while (toupper(cont) != 'Y' && toupper(cont) != 'N');
            saveExpense();
        } while (repeat);

    }

    void viewExpenseHistory() {
        if (exp.empty()) {
            cout << "Nothing to view.\n"; 
            return;
        }

        cout << endl;
        cout << left << setw(13) << "Date"
             << setw(15) << "Subcategory"
             << setw(12) << "Amount"
             << setw(20) << "Description"
             << setw(10) << "Distance" << endl;
        string last = "";

        for (size_t i = 0; i < exp.size(); i++) {
            ostringstream oss;
            oss << fixed << setprecision(2) << exp[i]->getAmount();
            string amountStr = "RM " + oss.str();

            if (last != getLower(exp[i]->getCategory())) {
                cout << string(30, '-') << exp[i]->getCategory() << string(30, '-') << endl;
            }
            cout << fixed << setprecision(2);
            cout << left << setw(13) << getDateStr(exp[i]->getDay(), exp[i]->getMonth(), exp[i]->getYear())
                << setw(15) << exp[i]->getSubcategory()
                << setw(12) << amountStr
                << setw(20) << exp[i]->getDescription();
            if (getLower(exp[i]->getCategory()) == "transportation") {
            cout << left << setw(10) << exp[i]->getDistance() << endl;
            } cout << "\n\n";
            last = getLower(exp[i]->getCategory());
        }

        system("pause");
    }

    void displayReport(const Budget& bud) {
        if (exp.empty()) {
            cout << "No info to form report.\n";
            return;
        }

        double sum = 0;
        double food = 0, transport = 0, rental = 0, others = 0;
        double budget = bud.getHousehold() + bud.getSalary();
    
        cout << fixed << setprecision(2);

        for (size_t i = 0; i < exp.size(); i++) {
            sum += exp[i]->getAmount();
            string cat = getLower(exp[i]->getCategory());
            if (cat == "food") {
                food += exp[i]->getAmount();
            } else if (cat == "transportation") {
                transport += exp[i]->getAmount();
            } else if (cat == "rental") {
                rental += exp[i]->getAmount();
            } else if (cat == "others") {
                others += exp[i]->getAmount();
            } else {
                cout << exp[i]->getCategory() << " is not categorised.\n";
            }
        }

        cout << "\n" << string(30, '-') << " Report " << string(30, '-') << endl;
        cout << left << setw(20) << "Budget"
             << setw(20) << "Total Expenses"
             << setw(10) << "CashFlow" << endl;

        ostringstream budgetOSS, sumOSS, cashOSS;
        budgetOSS << fixed << setprecision(2) << budget;
        sumOSS << fixed << setprecision(2) << sum;
        cashOSS << fixed << setprecision(2) << (budget - sum);
    
        cout << left << setw(20) << ("RM " + budgetOSS.str())
             << setw(20) << ("RM " + sumOSS.str())
             << setw(10) << ("RM " + cashOSS.str()) << endl;
    
        char choice;
        cout << "\nDo you want to see category breakdown? (Y/N): ";
        
        cin >> choice;

        while (true) {
            if (toupper(choice) == 'Y') {
                ostringstream foodOSS, transportOSS, rentalOSS, othersOSS;
                foodOSS << fixed << setprecision(2) << food;
                transportOSS << fixed << setprecision(2) << transport;
                rentalOSS << fixed << setprecision(2) << rental;
                othersOSS << fixed << setprecision(2) << others;

                cout << left << setw(30) << "Food: " << ("RM " + foodOSS.str()) << endl;
                cout << left << setw(30) << "Transportation: " << ("RM " + transportOSS.str()) << endl;
                cout << left << setw(30) << "Rental: " << ("RM " + rentalOSS.str()) << endl;
                cout << left << setw(30) << "Others: " << ("RM " + othersOSS.str()) << endl;
                system("pause");
                break;
            } else if (toupper(choice) == 'N') {
                cout << "End of report\n";
                break;
            } else {
                cout << "Invalid input. Please enter Y or N: ";
                cin >> choice;
            }
        }
    }
};

int main() {
    Budget bud;
    bud.loadBudget();

    ExpenseTracker track;
    track.loadExpenses();

    int choice;

    do {
        cout << "\n1. Enter budget.\n";
        cout << "2. Enter expenses\n";
        cout << "3. View expenses history.\n";
        cout << "4. View summarise report.\n";
        cout << "5. Export to CSV.\n";
        cout << "6. Exits.\n";
        choice = validInt("Enter choice: ", 1, 6);

        switch (choice) {
            case 1: {
                double household, part;
                household = validDouble("Enter household expenses (RM): ", 0.00);
                bud.setHousehold(household);
                part = validDouble("Enter part-time salary (RM): ", 0.00);
                bud.setSalary(part);
                bud.saveBudget();
                break;
            }
            case 2: track.addExpense(); break;
            case 3: track.viewExpenseHistory(); break;
            case 4: track.displayReport(bud); break;
            case 5: track.exportCSV(); break;
            case 6: cout << "\nThanks for using this system.\n"; break;
        }
    } while (choice != 6);
}