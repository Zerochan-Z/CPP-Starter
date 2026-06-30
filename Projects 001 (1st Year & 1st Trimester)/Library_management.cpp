#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <cctype>
#include <iomanip>
using namespace std;

string toTitle (const string &str) {
    string result = str;
    bool upper = true;

    for (size_t i = 0 ; i < result.length(); i++) {
        if (isspace(result[i])) {
            upper = true;
        } else if (upper) {
            result[i] = toupper(result[i]);
            upper = false;
        } else result[i] = tolower(result[i]);
    }
    return result;
}

string toLower (const string &str) {
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

int StatusInt(char status) {
    if (status == 'A') return 1;
    if (status == 'B') return 2;
    if (status == 'R') return 3;
    else return 4;
}

class Book {
private:
    string title;
    string author;
    int year;
    char status;

public:

    Book() : title(""), author(""), year(0), status('A') {}
    Book(string t, string a, int y, char s) : title(t), author(a), year(y), status(s) {}

    string getName() { return title; }
    string getAuthor() { return author; }
    int getYear() { return year; }
    char getStatus() { return status; }

    void setName(string t) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Invalid data type.\n";
        } else title = t;
    }

    void setAuthor(string a) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Invalid data type.\n";
        } else author = a;
    }

    void setYear (int y) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Invalid data type.\n";
        } else year = y;
    }

    void setStatus (char s) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Invalid input.\n";
        } else if ( s == 'A' || s == 'B' || s == 'R' || s == ' ') status = s;
        else cout << "A - Available, B - Borrowed, R - Reserved.\n";
    }

    void display() const {
        cout << left << setw(25) << toTitle(title)
             << setw(20) << toTitle(author)
             << setw(8) << year
             << setw(12) << StatusStr(status) << endl;
    }

    void saveFile(ofstream &outFile) const {
        outFile << title << endl;
        outFile << author << endl;
        outFile << year << endl;
        outFile << status << endl;
    }

    void loadFile(ifstream &inFile) {
        getline(inFile, title);
        getline(inFile, author);
        inFile >> year;
        inFile >> status;
        inFile.ignore();
    }
};

class Library {
private: 
    vector <Book> book;

public:

    void saveFile() {
        ofstream outFile ("books.txt");
        if (!outFile) {
            cout << "No book saved.\n";
            return;
        }

        for (size_t i = 0; i < book.size(); i++) {
            book[i].saveFile(outFile);
        }

        outFile.close();
        cout << book.size() << " book(s) saved.\n";
    }

    void loadFile() {
        ifstream inFile("books.txt");
        if (!inFile) {
            cout << "No book loaded.\n";
            return;
        }

        Book b;
        while (!inFile.eof()) {
            b.loadFile(inFile);
            book.push_back(b);
        }

        inFile.close();
        cout << book.size() << " book(s) loaded.\n";
    }

    void addBook() {
        Book b;
        string title, author;
        int year;
        char status;

        cout << "Enter book title: ";
        cin.ignore();
        getline(cin, title);
        title = toTitle(title);
        b.setName(title);
        cout << "Enter book author: ";
        getline(cin, author);
        author = toTitle(author);
        b.setAuthor(author);
        cout << "Enter year: ";
        cin >> year;
        b.setYear(year);
        cout << "Enter status: ";
        cin >> status;
        status = toupper(status);
        b.setStatus(status);

        book.push_back(b);
        saveFile();

    }

    void displayBook() {
        if (book.empty()) {
            cout << "No books to display.\n";
            return;
        }
        cout << left << setw(28) << "Title"
             << setw(20) << "Author"
             << setw(8) << "Year"
             << setw(12) << "Status" << endl;
        cout << string(65, '-') << endl;

        for (size_t i = 0; i < book.size(); i++) {
            book[i].display();
        }
        StatusTotal();
    }

    void deleteBook() {
        if (book.empty()) {
            cout << "No book to delete.\n";
            return;
        }

        string name;
        cout << "Enter the title: ";
        cin.ignore();
        getline(cin, name);
        string lowerName = toLower(name);
        bool found = false;

        for (size_t i = 0; i < book.size(); i++) {
            if (toLower(book[i].getName()) == lowerName) {
                found = true;
                cout << "Confirm to delete? (Y/N): ";
                char c;
                cin >> c;
                if (toupper(c) == 'Y') {
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
            cout << "No book to edit.\n";
            return;
        }

        string name;
        cout << "Enter book title: ";
        cin.ignore();
        getline(cin, name);
        bool found = false;
        string lowerName = toLower(name);

        for (size_t i = 0; i < book.size(); i++) {
            if (toLower(book[i].getName()).find(lowerName) != string ::npos ) {
                found = true;

                cout << "\nCurrent: " << book[i].getName() << " - " << book[i].getAuthor() << " (" << book[i].getYear() << ") - " << book[i].getStatus() << endl;
                cout << "1. Edit book title.\n";
                cout << "2. Edit book author.\n";
                cout << "3. Edit book year.\n";
                cout << "4. Edit book status.\n";
                cout << "Choice: ";
                int choice;
                cin >> choice;
                cin.ignore();

                if (choice == 1) {
                    string newName;
                    cout << "Enter new name: ";
                    getline(cin, newName);
                    newName = toTitle(newName);
                    book[i].setName(newName);
                } else if (choice == 2) {
                    string newAuthor;
                    cout << "Enter new author: ";
                    getline(cin, newAuthor);
                    newAuthor = toTitle(newAuthor);
                    book[i].setAuthor(newAuthor);
                } else if (choice == 3) {
                    int newYear;
                    cout << "Enter new year: ";
                    cin >> newYear;
                    book[i].setYear(newYear);
                } else  if (choice == 4) {
                    char newStatus;
                    cout << "Enter new status: ";
                    cin >> newStatus;
                    newStatus = toupper(newStatus);
                    book[i].setStatus(newStatus);
                } else cout << "Enter the correct choice. (1-4)\n";
                saveFile();
                break;
            }
        }
        if (!found) {
            cout << "No certain book.\n";
        }
    }

    void searchBook() {
        if (book.empty()) {
            cout << "No book to search.\n";
            return;
        }

        int choice;
        cout << "\n1. Search by title.\n";
        cout << "2. Search by author.\n";
        cout << "3. Search by year.\n";
        cout << "4. Search by status.\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        bool found = false;

        if (choice == 1) {
            string title;
            cout << "Enter title: ";
            getline(cin, title);
            string lowtitle = toLower(title);

            for (size_t i = 0; i < book.size(); i ++) {
                if (toLower(book[i].getName()).find(lowtitle) != string ::npos) {
                    found = true;
                    cout << "Found: " << book[i].getName() << " (" << book[i].getYear() << ") - " << book[i].getAuthor() << " - " << book[i].getStatus() << endl;
                }
                else {
                    found = false;
                }
            }
        } else if (choice == 2) {
            string aut;
            cout << "Enter author: ";
            cin.ignore();
            getline (cin, aut);
            string lowaut = toLower(aut);

            for (size_t i = 0; i < book.size();  i++) {
                if (toLower(book[i].getAuthor()).find(aut) != string::npos) {
                    found = true;
                    cout << book[i].getName() << " (" << book[i].getYear() << ") - " << book[i].getStatus() << endl;
                } else {
                    found = false;
                }
            }
        } else if (choice == 3) {
            int y;
            cout << "Enter year: ";
            cin >> y;
            
            for (size_t i = 0; i < book.size(); i++) {
                if (book[i].getYear() == y) {
                    cout << book[i].getName() << " - " << book[i].getAuthor() << " - " << book[i].getStatus() << endl;
                    found = true;
                }
            }
        } else if (choice == 4) {
            char s;
            cout << "Enter status: ";
            cin >> s;

            for (size_t i = 0; i < book.size(); i ++) {
                if (book[i].getStatus() == s) {
                    found = true;
                    cout << book[i].getName() << " (" << book[i].getYear() << ") - " << book[i].getAuthor() << endl;
                }
            }
        } else cout << "Invalid choice.\n";
        if (!found) {
            cout << "Book not found.\n";
        }
    }

    void sortByName() {
        if (book.empty()) {
            cout << "No book to sort.\n";
            return;
        }

        vector<Book> sorted = book;
        for (size_t i = 0; i < sorted.size() -1 ; i++) {
            for (size_t k = 0; k < sorted.size() - 1 -i; k++) {
                if (sorted[k].getName() > sorted[k+1].getName()) {
                    Book temp = sorted[k];
                    sorted[k] = sorted[k+1];
                    sorted[k+1] = temp;
                }
            }
        }

        displayList(sorted);
    }

    void sortByAuthor() {
        if (book.empty()) {
            cout << "No book to sort.\n";
            return;
        }

        vector <Book> sorted = book;
        for (size_t i = 0; i < sorted.size() - 1; i++) {
            for (size_t k = 0; k < sorted.size()- 1 - i;k++) {
                if (sorted[k].getAuthor() > sorted[k+1].getAuthor()) {
                    swap(sorted[k], sorted[k+1]);
                }
            }
        }

        displayList(sorted);
    }

    void sortByYear() {
        if (book.empty()) {
            cout << "No book to sort";
            return;
        }

        vector <Book> sorted = book;

        for (size_t i = 0; i < sorted.size() - 1; i++) {
            for (size_t k = 0; k < sorted.size()- 1 -i; k++) {
                if (sorted[k].getYear() < sorted[k+1].getYear()) {
                    Book temp = sorted[k];
                    sorted[k] = sorted[k+1];
                    sorted[k+1] = temp;
                }
            }
        }
        
        displayList(sorted);
    }

    void sortByStatus() {
        if (book.empty()) {
            cout << "No book to sort.\n";
            return;
        }

        vector <Book> sorted = book;
        for (size_t i = 0; i < sorted.size() -1 ; i++) {
            for (size_t k = 0; k < sorted.size() - 1 -i; k++) {
                if (StatusInt(sorted[k].getStatus()) > StatusInt(sorted[k+1].getStatus())) {
                    Book temp = sorted[k];
                    sorted[k] = sorted[k+1];
                    sorted[k+1] = temp;
                }
            }
        }

        displayList(sorted);
    }

private:

    void StatusTotal() {
        if (book.empty()) {
            cout << "No books.\n";
            return;
        }

        int available = 0, borrowed = 0, reserved = 0, missing = 0;

        for (size_t i = 0; i < book.size(); i++) {
            if (book[i].getStatus() == 'A') available ++;
            else if (book[i].getStatus() == 'B') borrowed ++;
            else if (book[i].getStatus() == 'R') reserved ++;
            else missing ++;
        }

        cout << "Available: " << available << endl;
        cout << "Borrowed: " << borrowed << endl;
        cout << "Reserved: " << reserved << endl;
    }

    void displayList(vector <Book> &list) {
        if (list.empty()) {
            cout << "No book to display.\n";
            return;
        }

        cout << left << setw(25) << "Title"
             << setw(20) << "Author"
             << setw(8) << "Year"
             << setw(12) << "Status" << endl;
        cout << string(65, '-') << endl;

        for (size_t i = 0; i < book.size() ; i++) {
            list[i].display();
        }

        StatusTotal();
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

