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
            cout << "Invalid input.\n";
        } else title = t;
    }

    void setAuthor(string a) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Invalid input.\n";
        } else author = a;
    }

    void setYear (int y) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Invalid input.\n";
        } else year = y;
    }

    void setStatus (char s) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Invalid input.\n"
        } else if ( s == 'A' || s == 'B' || s == 'R' || s == ' ') status = s;
        else cout << "A - Available, B - Borrowed, R - Reserved.\n";
    }

    void display() {
        cout << left << setw(25) << toTitle(title)
             << setw(20) << toTitle(author)
             << setw(8) << year
             << setw(12) << StatusStr(status) << endl;
    }

    void saveFile(ofstream &outFile) {
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
            cout << "No book  saved.\n";
            return;
        }

        for (size_t i = 0; i < book.size(); i++) book[i].saveFile(outFile);

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
        cout << book.size() << " book loaded.\n";
    }

    void addBook() {
        Book b;
        string title, author;
        int year;
        char status;

        cout << "Enter book title: ";
        cin.ignore();
        getline(cin, title);
        b.setName(title);
        cout << "Enter book author: ";
        getline(cin, author);
        b.setAuthor(author);
        cout << "Enter year: ";
        cin >> year;
        b.setYear(year);
        cout << "Enter status: ";
        cin >> status;
        b.setStatus(status);

        book.push_back(b);
        saveFile();

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

            statusTotal();
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
                if (toLower(book[i].title) == lowerName) {
                    found = true;
                    cout << "Confirm to delete? (Y/N): ";
                    char c;
                    cin >> c;
                    if (c == 'Y') {
                        book.erase(book.begin() + i);
                        saveFile();
                        cout << "Book deleted.\n";
                    } else cout << "Deletion cancelled.\n";
                    break;
                }
            }
            if (!found) {
                cout << "Book not found.\n";
            }
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

        for (size_t i = 0; i < book.size(); i++) {
            if (toLower(book[i].getName()).find(toLower(name)) != string ::npos ) {
                found = true;

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
                    book[i].setName(newName);
                } else if (choice == 2) {
                    string newAuthor;
                    cout << "Enter new author: ";
                    getline(cin, newAuthor);
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

    void searchBook() const{
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

        bool found = false;

        if (choice == 1) {
            string title;
            cout << "Enter title: ";
            cin.ignore();
            getline(cin, title);

            for (size_t i = 0; i < book.size(); i ++) {
                if (toLower(book[i].getName()).find(toLower(title)) != string ::npos) {
                    found = true;
                    cout << book[i].getName() << " (" << book[i].getYear() << ") - " << book[i].getAuthor() << " - " << book[i].getStatus() << endl;
                }
            }
        }
    }
}