#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
#include <iomanip>
#include <cctype>
using namespace std;

// ========== HELPER FUNCTIONS ==========
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

// ========== BOOK CLASS ==========
class Book {
private:
    string name;
    string author;
    int year;
    char status;

public:
    // Constructors
    Book() : name(""), author(""), year(0), status('A') {}
    Book(string n, string a, int y, char s) : name(n), author(a), year(y), status(s) {}

    // Getters (accessors)
    string getName() const { return name; }
    string getAuthor() const { return author; }
    int getYear() const { return year; }
    char getStatus() const { return status; }

    // Setters (mutators)
    void setName(string n) { name = n; }
    void setAuthor(string a) { author = a; }
    void setYear(int y) { year = y; }
    void setStatus(char s) { status = toupper(s); }

    // Display
    void display() const {
        cout << left << setw(25) << toTitle(name)
             << setw(20) << toTitle(author)
             << setw(8) << year
             << setw(12) << statusToString(status) << endl;
    }

    // File I/O
    void saveToFile(ofstream& outFile) const {
        outFile << name << endl;
        outFile << author << endl;
        outFile << year << endl;
        outFile << status << endl;
    }

    void loadFromFile(ifstream& inFile) {
        getline(inFile, name);
        getline(inFile, author);
        inFile >> year;
        inFile >> status;
        inFile.ignore(numeric_limits<streamsize>::max(), '\n');
    }
};

// ========== LIBRARY CLASS ==========
class Library {
private:
    vector<Book> books;

public:
    // File I/O
    void saveToFile() {
        ofstream outFile("books.txt");
        if (!outFile) {
            cout << "Error: Cannot save.\n";
            return;
        }

        for (size_t i = 0; i < books.size(); i++) {
            books[i].saveToFile(outFile);
        }

        outFile.close();
        cout << books.size() << " book(s) saved.\n";
    }

    void loadFromFile() {
        ifstream inFile("books.txt");
        if (!inFile) {
            cout << "No existing data file found.\n";
            return;
        }

        Book b;
        while (!inFile.eof()) {
            b.loadFromFile(inFile);
            books.push_back(b);
        }
        inFile.close();
        cout << books.size() << " book(s) loaded.\n";
    }

    // Add
    void addBook() {
        Book b;
        string name, author;
        int year;
        char status;

        cout << "Enter book name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, name);
        b.setName(name);

        cout << "Enter author: ";
        getline(cin, author);
        b.setAuthor(author);

        cout << "Enter year: ";
        cin >> year;
        b.setYear(year);

        cout << "A - Available, B - Borrowed, R - Reserved\n";
        cout << "Enter status: ";
        cin >> status;
        b.setStatus(status);

        books.push_back(b);
        saveToFile();
        cout << "Book added.\n";
    }

    // Display
    void displayBooks() const {
        if (books.empty()) {
            cout << "No books to display.\n";
            return;
        }

        cout << left << setw(25) << "Name"
             << setw(20) << "Author"
             << setw(8) << "Year"
             << setw(12) << "Status" << endl;
        cout << string(65, '-') << endl;

        for (size_t i = 0; i < books.size(); i++) {
            books[i].display();
        }

        statusTotal();
    }

    // Delete
    void deleteBook() {
        if (books.empty()) {
            cout << "No books to delete.\n";
            return;
        }

        string name;
        cout << "Enter book name to delete: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, name);

        string lowerName = toLower(name);
        bool found = false;

        for (size_t i = 0; i < books.size(); i++) {
            if (toLower(books[i].getName()).find(lowerName) != string::npos) {
                found = true;
                cout << "Delete this book? (Y/N): " << books[i].getName() << endl;
                char confirm;
                cin >> confirm;

                if (toupper(confirm) == 'Y') {
                    books.erase(books.begin() + i);
                    saveToFile();
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

    // Edit
    void editBook() {
        if (books.empty()) {
            cout << "No books to edit.\n";
            return;
        }

        string name;
        cout << "Enter book name to edit: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, name);

        string lowerName = toLower(name);
        bool found = false;

        for (size_t i = 0; i < books.size(); i++) {
            if (toLower(books[i].getName()).find(lowerName) != string::npos) {
                found = true;

                cout << "\nCurrent: " << books[i].getName() << " - " << books[i].getAuthor()
                     << " (" << books[i].getYear() << ") - " << statusToString(books[i].getStatus()) << endl;

                int choice;
                cout << "1. Edit title\n";
                cout << "2. Edit author\n";
                cout << "3. Edit year\n";
                cout << "4. Edit status\n";
                cout << "Choice: ";
                cin >> choice;
                cin.ignore();

                if (choice == 1) {
                    string newName;
                    cout << "Enter new name: ";
                    getline(cin, newName);
                    books[i].setName(newName);
                } else if (choice == 2) {
                    string newAuthor;
                    cout << "Enter new author: ";
                    getline(cin, newAuthor);
                    books[i].setAuthor(newAuthor);
                } else if (choice == 3) {
                    int newYear;
                    cout << "Enter new year: ";
                    cin >> newYear;
                    books[i].setYear(newYear);
                } else if (choice == 4) {
                    char newStatus;
                    cout << "Enter new status (A/B/R): ";
                    cin >> newStatus;
                    books[i].setStatus(newStatus);
                } else {
                    cout << "Invalid choice.\n";
                }

                saveToFile();
                cout << "Book updated.\n";
                break;
            }
        }

        if (!found) {
            cout << "Book not found.\n";
        }
    }

    // Search
    void searchBook() const {
        if (books.empty()) {
            cout << "No books to search.\n";
            return;
        }

        int choice;
        cout << "\n1. Search by title\n";
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

            for (size_t i = 0; i < books.size(); i++) {
                if (toLower(books[i].getName()).find(lowerTitle) != string::npos) {
                    cout << "Found: " << books[i].getName() << " - " << books[i].getAuthor() << endl;
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

            for (size_t i = 0; i < books.size(); i++) {
                if (toLower(books[i].getAuthor()).find(lowerAuthor) != string::npos) {
                    cout << "Found: " << books[i].getAuthor() << " - " << books[i].getName() << endl;
                    found = true;
                }
            }
            if (!found) cout << "No authors found.\n";

        } else if (choice == 3) {
            int year;
            cout << "Enter year: ";
            cin >> year;
            for (size_t i = 0; i < books.size(); i++) {
                if (books[i].getYear() == year) {
                    cout << "Found: " << books[i].getName() << " (" << books[i].getYear() << ")" << endl;
                    found = true;
                }
            }
            if (!found) cout << "No books found.\n";

        } else if (choice == 4) {
            char status;
            cout << "Enter status (A/B/R): ";
            cin >> status;
            for (size_t i = 0; i < books.size(); i++) {
                if (books[i].getStatus() == status) {
                    cout << "Found: " << books[i].getName() << " - " << statusToString(books[i].getStatus()) << endl;
                    found = true;
                }
            }
            if (!found) cout << "No books found.\n";

        } else {
            cout << "Invalid choice.\n";
        }
    }

    // Sort functions
    void sortByName() {
        if (books.empty()) {
            cout << "No books to sort.\n";
            return;
        }

        vector<Book> sorted = books;
        for (size_t i = 0; i < sorted.size() - 1; i++) {
            for (size_t j = 0; j < sorted.size() - 1 - i; j++) {
                if (toLower(sorted[j].getName()) > toLower(sorted[j + 1].getName())) {
                    swap(sorted[j], sorted[j + 1]);
                }
            }
        }

        cout << "\n--- Sorted by Name (A-Z) ---\n";
        displayList(sorted);
    }

    void sortByAuthor() {
        if (books.empty()) {
            cout << "No books to sort.\n";
            return;
        }

        vector<Book> sorted = books;
        for (size_t i = 0; i < sorted.size() - 1; i++) {
            for (size_t j = 0; j < sorted.size() - 1 - i; j++) {
                if (toLower(sorted[j].getAuthor()) > toLower(sorted[j + 1].getAuthor())) {
                    swap(sorted[j], sorted[j + 1]);
                }
            }
        }

        cout << "\n--- Sorted by Author (A-Z) ---\n";
        displayList(sorted);
    }

    void sortByYear() {
        if (books.empty()) {
            cout << "No books to sort.\n";
            return;
        }

        vector<Book> sorted = books;
        for (size_t i = 0; i < sorted.size() - 1; i++) {
            for (size_t j = 0; j < sorted.size() - 1 - i; j++) {
                if (sorted[j].getYear() > sorted[j + 1].getYear()) {
                    swap(sorted[j], sorted[j + 1]);
                }
            }
        }

        cout << "\n--- Sorted by Year (Newest first) ---\n";
        displayList(sorted);
    }

    void sortByStatus() {
        if (books.empty()) {
            cout << "No books to sort.\n";
            return;
        }

        vector<Book> sorted = books;
        for (size_t i = 0; i < sorted.size() - 1; i++) {
            for (size_t j = 0; j < sorted.size() - 1 - i; j++) {
                if (getStatusPriority(sorted[j].getStatus()) > getStatusPriority(sorted[j + 1].getStatus())) {
                    swap(sorted[j], sorted[j + 1]);
                }
            }
        }

        cout << "\n--- Sorted by Status (Available first) ---\n";
        displayList(sorted);
    }

private:
    // Helper methods
    void statusTotal() const {
        if (books.empty()) {
            cout << "No books.\n";
            return;
        }

        int available = 0, borrowed = 0, reserved = 0;
        for (size_t i = 0; i < books.size(); i++) {
            if (books[i].getStatus() == 'A') available++;
            else if (books[i].getStatus() == 'B') borrowed++;
            else if (books[i].getStatus() == 'R') reserved++;
        }

        cout << "\n--- Status Summary ---\n";
        cout << "Available: " << available << endl;
        cout << "Borrowed: " << borrowed << endl;
        cout << "Reserved: " << reserved << endl;
    }

    void displayList(const vector<Book>& list) const {
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
            list[i].display();
        }

        statusTotal();
    }
};

// ========== MAIN ==========
int main() {
    Library lib;
    lib.loadFromFile();

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
        else if (choice == 2) lib.displayBooks();
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
