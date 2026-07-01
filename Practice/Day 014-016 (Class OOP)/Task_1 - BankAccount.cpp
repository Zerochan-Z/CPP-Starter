#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string ownerName;
    double balance;

public:
    BankAccount(int accNum, string name, double bal) {
        accountNumber = accNum;
        ownerName = name;
        balance = bal;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: RM" << amount << endl;
        } else {
            cout << "Invalid amount.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: RM" << amount << endl;
        } else if (amount > balance) {
            cout << "Not enough balance! You have RM" << balance << endl;
        } else {
            cout << "Invalid amount.\n";
        }
    }

    void display() {
        cout << "\n--- Account Details ---\n";
        cout << "Account Number: " << accountNumber << endl;
        cout << "Owner Name: " << ownerName << endl;
        cout << "Balance: RM" << balance << endl;
        cout << "----------------------\n";
    }
};

int main() {
    BankAccount acc1(12345, "Alice", 1000);

    acc1.display();

    acc1.deposit(500);
    acc1.display();

    acc1.withdraw(200);
    acc1.display();

    acc1.withdraw(2000);

    return 0;
}