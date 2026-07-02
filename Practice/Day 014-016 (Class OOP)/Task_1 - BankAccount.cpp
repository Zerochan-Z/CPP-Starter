#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    int accountID;
    string owner;
    double balance;

public:
    BankAccount(int id, string o, double b) { 
        accountID = id;
        owner = o;
        balance = b; 
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: RM" << amount << endl;
        } else {
            cout << "Enter the correct amount.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount < balance) {
            balance -= amount;
            cout << "Withdraw: RM" << amount << endl;
        } else if (amount > balance) {
            cout << "Insufficient balance.\n";
        } else {
            cout << "Enter the correct amount.\n";
        }
    }

    void display() {
        cout << "\n ---- Account Details ---- \n";
        cout << "Account number: " << accountID << endl;
        cout << "Owner name: " << owner << endl;
        cout << "Balance: RM" << balance << endl;
        cout << string(20, '-');
    }
};

int main() {
    BankAccount a1(100100, "Mew", 200);

    a1.display();
    a1.deposit(100);
    a1.withdraw(100);
    a1.display();

    a1.withdraw(2000);
    return 0;
}