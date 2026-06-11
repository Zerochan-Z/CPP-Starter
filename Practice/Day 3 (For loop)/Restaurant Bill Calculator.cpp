#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void displayMenu() ;
double calculateTotal(double prices[],int quantities[], int itemCount);
void applyDiscount(double& total);
void printReceipt(string items[], double prices[], int quantities[], int itemCount, double total);

int main() {
    string items[] = {"Teh Tarik", "Ice Lemon Tea", "Artisanal Syrups"};
    double prices[] = {8.90, 12.90, 21.90};
    int quantities[3] = {0,0,0};
    int choice, quantity;
    char addMore;

    cout << "=== Welcome to T&S Restaurant ===\n\n";

    do {
        displayMenu();

        cout << "Pick your choice (1-3): ";
        cin >> choice;

        if (choice < 1 || choice > 3) {
            cout << " Invalid choice! Please try again. \n";
            continue;
        }
        
        cout << "Enter quantity: ";
        cin >> quantity;

        quantities[choice -1] += quantity;
        cout << "Added " <<quantity << " x " << items[choice -1] << "\n";
        
        cout << "\n Add another? (Y/N): \n";
        cin >> addMore;

    } while (addMore == 'Y' || addMore == 'y');

    double total = calculateTotal(prices, quantities, 3);

    applyDiscount(total);

    printReceipt(items, prices, quantities, 3, total);

        return 0;
}
    
void displayMenu() {
    cout << "========== Menu ==========\n";
    cout << "1. Teh Tarik - RM8.90\n";
    cout << "2. Ice Lemon Tea - RM12.90\n";
    cout << "3. Artisanal Syrups - RM21.90\n";
    cout << "==========================\n";
}

double calculateTotal(double prices[], int quantities[], int itemCount) {
    double total = 0;
    for (int i = 0; i < itemCount; i++) {
        total = total + (prices[i] * quantities[i]);
    }
    return total;
}

void applyDiscount(double& total) {
    if (total > 30) {
        cout << "\n*** RM 5 promo voucher applied! ***\n";
        total = total -5;
    }
}

void printReceipt(string items[], double prices[], int quantities[], int itemCount, double total) {
    cout << "\n========== Receipt ==========\n";
    
    for (int i = 0; i < itemCount; i++) {
        if (quantities[i] > 0) {
            cout << quantities[i] << " x " << items[i];
            cout << " = RM " << fixed << setprecision(2) << (prices[i] * quantities[i]) << "\n";
        }
    }
    
    cout << "-----------------------------\n";
    cout << "Total: RM " << fixed << setprecision(2) << total << "\n";
    cout << "=============================\n";
    cout << "Thank you for visiting! \n";
}