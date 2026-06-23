#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
#include <iomanip>
#include <cctype>
using namespace std;

// next: OOP

struct Book {
    string name;
    string author;
    int year;
    char status;
};

vector<Book> book;

void saveFile() {
    ofstream outFile("books.txt");
    if (!outFile) {
        cout << "Error: Cannot save.\n";
        return;
    }

    for (size_t i = 0; i < book.size(); i++) {
        outFile << book[i].name << endl;
        outFile << book[i].author << endl;
        outFile << book[i].year << endl;
        outFile << book[i].status << endl;
    }

    outFile.close();
    cout << book.size() << " book(s) saved.\n";
}

void loadFile() {
    ifstream inFile("books.txt");
    if (!inFile) {
        cout << "No existing data file found.\n";
        return;
    }

    Book b;
    while (getline(inFile, b.name)) {
        getline(inFile, b.author);
        inFile >> b.year;
        inFile >> b.status;
        inFile.ignore(numeric_limits<streamsize>::max(), '\n');
        book.push_back(b);
    }

    inFile.close();
    cout << book.size() << " book(s) loaded.\n";
}

string toTitle(const string& str) {
    string result = str;
    bool newWord = true;

    for (size_t i = 0; i < result.length(); i++) {
        if (isspace(result[i])) {
            newWord = true;
        } else if (newWord) {
            result[i] = toupper(result[i]);
            newWord = false;
        } else {
            result[i] = tolower(result[i]);
        }
    }
    return result;
}

string toLower(const string& str) {
    string result = str;
    for (size_t i = 0; i < result.length(); i++) {
        result[i] = tolower(result[i]);
    }
    return result;
}

string statusToString(char status) {
    if (status == 'A') return "Available";
    if (status == 'B') return "Borrowed";
    if (status == 'R') return "Reserved";
    return "Unknown";
}

int getStatusPriority(char status) {
    if (status == 'A') return 1;
    if (status == 'B') return 2;
    if (status == 'R') return 3;
    return 4;
}

void addBook() {
    Book b;

    cout << "Enter book name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, b.name);

    cout << "Enter author: ";
    getline(cin, b.author);

    cout << "Enter year: ";
    cin >> b.year;

    cout << "A - Available, B - Borrowed, R - Reserved\n";
    cout << "Enter status: ";
    cin >> b.status;
    b.status = toupper(b.status);

    book.push_back(b);
    saveFile();
    cout << "Book added.\n";
}

void statusTotal() {
    if (book.empty()) {
        cout << "No books.\n";
        return;
    }

    int available = 0, borrowed = 0, reserved = 0;
    for (size_t i = 0; i < book.size(); i++) {
        if (book[i].status == 'A') available++;
        else if (book[i].status == 'B') borrowed++;
        else if (book[i].status == 'R') reserved++;
    }

    cout << "\n--- Status Summary ---\n";
    cout << "Available: " << available << endl;
    cout << "Borrowed: " << borrowed << endl;
    cout << "Reserved: " << reserved << endl;
}

void displayBook(const vector<Book>& list) {
    if (list.empty()) {
        cout << "No books to display.\n";
        return;
    }

    cout << left << setw(25) << "Name"
         << setw(20) << "Author"
         << setw(8) << "Year"
         << setw(12) << "Status" << endl;
    cout << string(65, '-') << endl;

    for (size_t i = 0; i < list.size(); i++) {
        cout << left << setw(25) << toTitle(list[i].name)
             << setw(20) << toTitle(list[i].author)
             << setw(8) << list[i].year
             << setw(12) << statusToString(list[i].status) << endl;
    }

    statusTotal();
}

void deleteBook() {
    if (book.empty()) {
        cout << "No books to delete.\n";
        return;
    }

    string name;
    cout << "Enter book name to delete: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);

    string lowerName = toLower(name);
    bool found = false;

    for (size_t i = 0; i < book.size(); i++) {
        if (toLower(book[i].name).find(lowerName) != string::npos) {
            found = true;
            cout << "Delete this book? (Y/N): " << book[i].name << endl;
            char confirm;
            cin >> confirm;

            if (toupper(confirm) == 'Y') {
                book.erase(book.begin() + i);
                saveFile();
                cout << "Book deleted.\n";
            } else {
                cout << "Deletion cancelled.\n";
            }
            break;
        }
    }

    if (!found) {
        cout << "Book not found.\n";
    }
}

void editBook() {
    if (book.empty()) {
        cout << "No books to edit.\n";
        return;
    }

    string name;
    cout << "Enter book name to edit: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);

    string lowerName = toLower(name);
    bool found = false;

    for (size_t i = 0; i < book.size(); i++) {
        if (toLower(book[i].name).find(lowerName) != string::npos) {
            found = true;

            cout << "\nCurrent: " << book[i].name << " - " << book[i].author
                 << " (" << book[i].year << ") - " << statusToString(book[i].status) << endl;

            cout << "1. Edit title\n";
            cout << "2. Edit author\n";
            cout << "3. Edit year\n";
            cout << "4. Edit status\n";
            cout << "Choice: ";
            int choice;
            cin >> choice;

            if (choice == 1) {
                string newName;
                cout << "Enter new name: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, newName);
                book[i].name = newName;
            } else if (choice == 2) {
                string newAuthor;
                cout << "Enter new author: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, newAuthor);
                book[i].author = newAuthor;
            } else if (choice == 3) {
                int newYear;
                cout << "Enter new year: ";
                cin >> newYear;
                book[i].year = newYear;
            } else if (choice == 4) {
                char newStatus;
                cout << "Enter new status (A/B/R): ";
                cin >> newStatus;
                book[i].status = toupper(newStatus);
            } else {
                cout << "Invalid choice.\n";
            }

            saveFile();
            cout << "Book updated.\n";
            break;
        }
    }

    if (!found) {
        cout << "Book not found.\n";
    }
}

void searchBook() {
    if (book.empty()) {
        cout << "No books to search.\n";
        return;
    }

    int choice;
    cout << "1. Search by title\n";
    cout << "2. Search by author\n";
    cout << "3. Search by year\n";
    cout << "4. Search by status\n";
    cout << "Choice: ";
    cin >> choice;
    bool found = false;

    if (choice == 1) {
        string title;
        cout << "Enter title keyword: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, title);
        string lowerTitle = toLower(title);

        for (size_t i = 0; i < book.size(); i++) {
            if (toLower(book[i].name).find(lowerTitle) != string::npos) {
                cout << "Found: " << book[i].name << " - " << book[i].author << endl;
                found = true;
            }
        }
        if (!found) cout << "No books found.\n";

    } else if (choice == 2) {
        string author;
        cout << "Enter author keyword: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, author);
        string lowerAuthor = toLower(author);

        for (size_t i = 0; i < book.size(); i++) {
            if (toLower(book[i].author).find(lowerAuthor) != string::npos) {
                cout << "Found: " << book[i].author << " - " << book[i].name << endl;
                found = true;
            }
        }
        if (!found) cout << "No authors found.\n";

    } else if (choice == 3) {
        int year;
        cout << "Enter the year: ";
        cin >> year;
        for (size_t i = 0; i < book.size(); i++) {
            if (book[i].year == year) {
                cout << "Found: " << book[i].name << " (" << book[i].year << ") " << endl;
                found = true;
            }
        }
    } else if (choice == 4) {
        char status;
        cout << "Enter status (A/B/R): ";
        cin >> status;
        for (size_t i = 0 ; i < book.size() ; i++) {
            if (book[i].status == status) {
                cout << "Found: " << book[i].name << " - " << book[i].status << endl;
                found = true;
            }
        }
    }
    if (!found) {
        cout << "No certain book.\n";
    }
}

void sortByName() {
    if (book.empty()) {
        cout << "No books to sort.\n";
        return;
    }

    vector<Book> sorted = book;
    for (size_t i = 0; i < sorted.size() - 1; i++) {
        for (size_t j = 0; j < sorted.size() - 1 - i; j++) {
            if (toLower(sorted[j].name) > toLower(sorted[j + 1].name)) {
                swap(sorted[j], sorted[j + 1]);
            }
        }
    }

    cout << "\n--- Sorted by Name (A-Z) ---\n";
    displayBook(sorted);
}

void sortByAuthor() {
    if (book.empty()) {
        cout << "No books to sort.\n";
        return;
    }

    vector<Book> sorted = book;
    for (size_t i = 0; i < sorted.size() - 1; i++) {
        for (size_t j = 0; j < sorted.size() - 1 - i; j++) {
            if (toLower(sorted[j].author) > toLower(sorted[j + 1].author)) {
                swap(sorted[j], sorted[j + 1]);
            }
        }
    }

    cout << "\n--- Sorted by Author (A-Z) ---\n";
    displayBook(sorted);
}

void sortByYear() {
    if (book.empty()) {
        cout << "No books to sort.\n";
        return;
    }

    vector<Book> sorted = book;
    for (size_t i = 0; i < sorted.size() - 1; i++) {
        for (size_t j = 0; j < sorted.size() - 1 - i; j++) {
            if (sorted[j].year > sorted[j + 1].year) {
                swap(sorted[j], sorted[j + 1]);
            }
        }
    }

    cout << "\n--- Sorted by Year (Newest first) ---\n";
    displayBook(sorted);
}

void sortByStatus() {
    if (book.empty()) {
        cout << "No books to sort.\n";
        return;
    }

    vector<Book> sorted = book;
    for (size_t i = 0; i < sorted.size() - 1; i++) {
        for (size_t j = 0; j < sorted.size() - 1 - i; j++) {
            if (getStatusPriority(sorted[j].status) > getStatusPriority(sorted[j + 1].status)) {
                swap(sorted[j], sorted[j + 1]);
            }
        }
    }

    cout << "\n--- Sorted by Status (Available first) ---\n";
    displayBook(sorted);
}

int main() {
    loadFile();

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

        if (choice == 1) addBook();
        else if (choice == 2) displayBook(book);
        else if (choice == 3) deleteBook();
        else if (choice == 4) editBook();
        else if (choice == 5) searchBook();
        else if (choice == 6) sortByName();
        else if (choice == 7) sortByAuthor();
        else if (choice == 8) sortByYear();
        else if (choice == 9) sortByStatus();
        else if (choice == 10) break;
        else cout << "Invalid choice.\n";

    } while (choice != 10);

    return 0;
}