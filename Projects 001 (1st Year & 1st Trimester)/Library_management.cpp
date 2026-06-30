#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <cctype>
#include <iomanip>
using namespace std;

string toTitle (string &str) {
    string result = str;
    bool upper = true;

    for (size_t i = 0; i < result.length(); i++) {
        if (isspace(result[i])) {
            upper = true;
        } else if (upper) {
            result[i] = toupper(result[i]);
            upper = false;
        } else result[i] = tolower(result[i]);
    }
    return result;
}

string toLower(string &str) {
    string result = str;
    
    for (size_t i = 0; i < result.length(); i++) {
        result[i] = tolower(result[i]);
    }
    return result;
}

string StatusStr(char status) {
    if (status == 'A') return "Available";
    if (status == 'B') return "Borrowed";
    if (status == 'R') return "Reserved";
    else return "Missing";
}

int StatusInt (char status) {
    if (status == 'A') return 1;
    if (status == 'B') return 2;
    if (status == 'R') return 3;
    else return 4;
}

int main() {
    // FIll in the blank

    int choice;

    do {
        cout << "\n1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Delete Book\n";
        cout << "4. Edit Book\n";
        cout << "5. Search Book\n";
        cout << "6. Sort by Name (A-Z)\n";
        cout << "7. Sort by Author (A-Z)\n";
        cout << "8. Sort by Year (Newest first)\n";
        cout << "9. Sort by Status\n";
        cout << "10. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) lib.addBook();
        else if (choice == 2) lib.displayBook();
        else if (choice == 3) lib.deleteBook();
        else if (choice == 4) lib.editBook();
        else if (choice == 5) lib.searchBook();
        else if (choice == 6) lib.sortByName();
        else if (choice == 7) lib.sortByAuthor();
        else if (choice == 8) lib.sortByYear();
        else if (choice == 9) lib.sortByStatus();
        else if (choice == 10) break;
        else cout << "Invalid choice.\n";

    } while (choice != 10);

    return 0;
}

