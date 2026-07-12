#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <cctype>
#include <iomanip>
using namespace std;

string toTitle(string str) {
    string result = str;
    bool upper = true;

    for (size_t i =0; i < result.length(); i++) {
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

string toLower(string str) {
    string result = str;
    for (size_t i =0; i < result.length(); i++) {
        result[i] = tolower(result[i]);
    }
    return result;
}

string StatusStr(char status) {
    if (status == 'A') return "Available";
    if (status == 'B') return "Borrowed";
    if (status == 'R') return "Reserved";
    return "Missing";
}

int StatusInt(char status) {
    if (status == 'A') return 1;
    if (status == 'B') return 2;
    if (status == 'R') return 3;
    return 4;
}

class Book {
private:
    string title, author;
    int year;
    char status;

public:
    Book(): title(""), author(""), year(0), status('A') {} // default (needed when empty list/vector)
    Book (string t, string a, int y, char s): title(t), author(a), year(y), status(toupper(s)) {} // assigning values for each variable

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getYear() const { return year; }
    char getStatus() const { return status; }

    void setTitle(string t) { title = t; }
    void setAuthor(string a) { author = a; }
    void setYear(int y) { year = y; }
    void setStatus(char s) { status = toupper(s); }

    void display() const {
        cout << left << setw(20) << toTitle(title)
             << setw(15) << toTitle(author)
             << setw(8) << year
             << setw(12) << StatusStr(status) << endl;
    }

    void saveFile (ofstream& outFile) {
        outFile << title << " | " << author << " | " << year << " | " << status << endl;
    }

    void loadFile(ifstream& inFile) {
        string line;
        getline(inFile, line);

        if (line.find('|') == string::npos) return; // exits if nothing found

        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1); // search '|' start from -> pos1 + 1
        size_t pos3 = line.find('|', pos2 + 1);

        title = line.substr(0, pos1);
        author = line.substr(pos1 + 1, pos2 - pos1 - 1 ); // start from pos1 + 1, take (pos2 - pos1 -1) characters
        year = stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
        status = line[pos3 + 1];

    }
};

class User {
private:
    string name;
    int UserID, borrowLimit;
    vector <Book*> borrowedBooks;

public:
    User(): name(""), UserID(000000), borrowLimit(0) {}
    User(string n, int id, int b): name(n), UserID(id), borrowLimit(b) {}

    int getID() const { return UserID; }
    bool Limit() {
        if (borrowedBooks.size() <= borrowLimit) return true;
        cout << "Limits reached! \n";
        return false;
    }

    bool borrowBook(Book* book) {
        if (Limit()) {
            if (book->getStatus() == 'A') {
                borrowedBooks.push_back(book);
                return true;
            } else {
                cout << "Book not available.\n";
                return false;
            }
        } else return false;
        
    }

    void returnBook(Book* book) {
        if (borrowedBooks.empty()) {
            cout << "No book to return.\n";
            return;
        }

        for (size_t i = 0; i < borrowedBooks.size(); i++) {
            if (borrowedBooks[i] == book) {
                borrowedBooks.erase(borrowedBooks.begin() + i);
                book->setStatus('A');
                cout << "Book returned.\n";
                return;
            }
        }
        cout << "Book not found.\n";
    }
};

class Student : public User {
public:
    Student(string name, int id) : User(name, id, 3) {}
};

class Staff : public User {
public: 
    Staff(string name, int id) : User(name, id, 5) {}
};

class Library {
private:
    vector <Book> books;
    vector <User*> users;
    string filename;

public:
    Library() { filename = "books.txt"; }

    void saveFile() {
        ofstream outFile(filename);
        if (!outFile) {
            cout << "Cannot save.\n";
            return;
        }

        for (size_t i = 0; i < books.size(); i++) {
            books[i].saveFile(outFile);
        }

        outFile.close();
        cout << books.size() << " book(s) saved.\n";
    }

    void loadFile() {
        ifstream inFile(filename);
        if (!inFile) {
            cout << "No book loaded\n";
            return;
        }

        books.clear(); // clear memory storage only not txt file
        Book b;

        while (!inFile.eof()) {
            b.loadFile(inFile);
            if (inFile.eof()) break;
            books.push_back(b);
        }

        inFile.close();
        cout << books.size() << " book(s) loaded.\n";
    }

    bool borrowBook(int userID, string title) {
        User* user = nullptr; // keep user as null in memory (User)

        for (size_t i = 0; i < users.size(); i++) {
            if (users[i]->getID() == userID) {
                user = users[i];
                break; //search id
            }
        }

        if (user == nullptr) {
            cout << "User not found.\n";
            return false; // when user not found
        }

        Book* book = nullptr; // same login as search user
        for (size_t i = 0; i < books.size(); i++) {
            if (toLower(books[i].getTitle()) == toLower(title)) {
                book = &books[i]; // book = address of certain book
                break;
            }
        }

        if (book == nullptr) {
            cout << "Book not found";
            return false;
        }

        return user->borrowBook(book); // call borrowbook from user class
    }

    void addBook() {
        string title, author;
        int year;
        char status;

        cout << "\n ---- Add a new book ----\n";
        
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter author: ";
        getline(cin, author);
        cout << "Enter year: ";
        cin >> year;
        cout << "Enter status (A/B/R): ";
        cin >> status;

        Book b(title, author, year, status);
        books.push_back(b);
        saveFile();
    }

        void displayList(vector <Book> &list) {
        if (list.empty()) {
            cout << "No book to display.\n";
            return;
        }

        cout << left << setw(20) << "Title"
             << setw(15) << "Author"
             << setw(8) << "Year"
             << setw(12) << "Status" << endl;
        cout << string(55, '-') << endl;

        for (size_t i = 0; i < list.size(); i++) {
            list[i].display();
        }
    }

    void displayBooks() {
        displayList(books);
    }


    void deleteBook() {
        if (books.empty()) {
            cout << "No book to delete.\n";
            return;
        }

        string name;
        cout << "Enter book title: ";
        getline(cin, name);
        name = toLower(name);
        bool found = false;

        for (size_t i = 0; i < books.size(); i++) {
            if (toLower(books[i].getTitle()).find(name) != string::npos) {
                found = true;
                char confirm;
                cout << "Delete [" << books[i].getTitle() << "] ? (Y/N)";
                cin >> confirm;

                if (toupper(confirm) == 'Y') {
                    books.erase(books.begin() + i);
                    saveFile();
                } else if (toupper(confirm) == 'N') {
                    cout << "Deletion cancelled.\n";
                } else {
                    cout << "Enter Y - Yes or N - No.\n";
                }
                break;
            }
        }
        if (!found) {
            cout << "Book not found.\n";
        }
    }

    void editBook() {
        if (books.empty()) {
            cout << "No books.\n";
            return;
        }

        string name;
        cout << "Enter book title: ";
        getline(cin, name);

        bool found = false;

        for (size_t i = 0; i < books.size(); i++) {
            if (toLower(books[i].getTitle()).find(toLower(name)) != string::npos) {
                found = true;

                cout << "\nCurrent: " << toTitle(books[i].getTitle())
                     << " (" << books[i].getYear() << ") - "
                     << toTitle(books[i].getAuthor()) << " ["
                     << StatusStr(books[i].getStatus()) << "]\n";

                cout << "1. Edit title\n";
                cout << "2. Edit author\n";
                cout << "3. Edit year\n";
                cout << "4. Edit status\n";
                cout << "Choice: ";
                int choice;
                cin >> choice;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (choice == 1) {
                    string newTitle;
                    cout << "Enter new title: ";
                    getline(cin, newTitle);
                    books[i].setTitle(newTitle);
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
        if (books.empty()) {
            cout << "No books.\n";
            return;
        }

        cout << "\n1. Search by title.\n";
        cout << "2. Search by author.\n";
        cout << "3. Search by year.\n";
        cout << "4. Search by status.\n";
        cout << "Choice: ";
        int choice;
        cin >> choice;

        vector<Book> results;
        bool found = false;

        if (choice == 1) {
            string search;
            cout << "Enter title keyword: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, search);
            search = toLower(search);

            for (size_t i = 0; i < books.size(); i++) {
                if (toLower(books[i].getTitle()).find(search) != string ::npos) {
                    found = true;
                    results.push_back(books[i]);
                }
            }
        } else if (choice == 2) {
            string search;
            cout << "Enter author keyword: ";
            getline(cin, search);
            search = toLower(search);

            for (size_t i = 0; i < books.size(); i++) {
                if (toLower(books[i].getAuthor()).find(search) != string::npos) {
                    found = true;
                    results.push_back(books[i]);
                }
            }
        } else if (choice == 3) {
            int search;
            cout << "Enter year: ";
            cin >> search;

            for (size_t i = 0; i < books.size(); i++) {
                if (books[i].getYear() == search) {
                    found = true;
                    results.push_back(books[i]);
                }
            }
        } else if (choice == 4) {
            char search;
            cout << "Enter status (A/B/R): ";
            cin >> search;
            search = toupper(search);

            for (size_t i = 0; i < books.size(); i++) {
                if (books[i].getStatus() == search) {
                    found = true;
                    results.push_back(books[i]);
                }
            }
        } else {
            cout << "Invalid choice.\n";
            return;
        }

        if (!found) {
            cout << "No books found.\n";
        } else {
            cout << "\nFound " << results.size() << " result(s):\n";
            displayList(results);
        }
    }

    void sortByName() {
        if (books.empty()) {
            cout << "No books.\n";
            return;
        }

        vector<Book> sorted = books;

        for (size_t i = 0; i < sorted.size() - 1; i++) {
            for (size_t j = 0; j < sorted.size() - 1 - i; j++) {
                if (toLower(sorted[j].getTitle()) > toLower(sorted[j + 1].getTitle())) {
                    Book temp = sorted[j];
                    sorted[j] = sorted[j + 1];
                    sorted[j + 1] = temp;
                }
            }
        }

        cout << "\n--- Sorted by Title (A-Z) ---\n";
        displayList(sorted);
    }

    void sortByAuthor() {
        if (books.empty()) {
            cout << "No books.\n";
            return;
        }

        vector<Book> sorted = books;

        for (size_t i = 0; i < sorted.size() - 1; i++) {
            for (size_t j = 0; j < sorted.size() - 1 - i; j++) {
                if (toLower(sorted[j].getAuthor()) > toLower(sorted[j + 1].getAuthor())) {
                    Book temp = sorted[j];
                    sorted[j] = sorted[j + 1];
                    sorted[j + 1] = temp;
                }
            }
        }

        cout << "\n--- Sorted by Author (A-Z) ---\n";
        displayList(sorted);
    }

    void sortByYear() {
        if (books.empty()) {
            cout << "No books.\n";
            return;
        }

        vector<Book> sorted = books;

        for (size_t i = 0; i < sorted.size() - 1; i++) {
            for (size_t j = 0; j < sorted.size() - 1 - i; j++) {
                if (sorted[j].getYear() < sorted[j + 1].getYear()) {
                    Book temp = sorted[j];
                    sorted[j] = sorted[j + 1];
                    sorted[j + 1] = temp;
                }
            }
        }

        cout << "\n--- Sorted by Year (Newest First) ---\n";
        displayList(sorted);
    }

    void sortByStatus() {
        if (books.empty()) {
            cout << "No books.\n";
            return;
        }

        vector<Book> sorted = books;

        for (size_t i = 0; i < sorted.size() - 1; i++) {
            for (size_t j = 0; j < sorted.size() - 1 - i; j++) {
                if (StatusInt(sorted[j].getStatus()) > StatusInt(sorted[j + 1].getStatus())) {
                    Book temp = sorted[j];
                    sorted[j] = sorted[j + 1];
                    sorted[j + 1] = temp;
                }
            }
        }

        cout << "\n--- Sorted by Status (Available first) ---\n";
        displayList(sorted);
    }
};

int main() {
    Library lib;
    lib.loadFile();

    int choice;

    do {
        cout << "\n1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Delete Book\n";
        cout << "4. Edit Book\n";
        cout << "5. Search Book\n";
        cout << "6. Sort by Title\n";
        cout << "7. Sort by Author\n";
        cout << "8. Sort by Year\n";
        cout << "9. Sort by Status\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore(10000, '\n');

        switch (choice) { // runs according to choice
            case 1: lib.addBook(); break; // runs addBook() and then BREAK for next input
            case 2: lib.displayBooks(); break;
            case 3: lib.deleteBook(); break;
            case 4: lib.editBook(); break;
            case 5: lib.searchBook(); break;
            case 6: lib.sortByName(); break;
            case 7: lib.sortByAuthor(); break;
            case 8: lib.sortByYear(); break;
            case 9: lib.sortByStatus(); break;
            case 0: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice.\n";
        } // break is a must or else it runs every cases
    } while (choice != 0);

    return 0;
    
}


