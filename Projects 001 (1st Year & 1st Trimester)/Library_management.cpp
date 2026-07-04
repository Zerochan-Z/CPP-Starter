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

class Library {
protected: 
    string title, author;
    int year;
    char status;

public:
    Library() : title(""), author(""), year(0), status('A') {}
    Library(string t, string a, int y, char s): title(t), author(a), year(y), status(s) {}

    string getTitle() { return title; }
    string getAuthor() { return author; }
    int getYear() { return year; }
    char getStatus() { return status; }

    void setTitle(string t) { title = t; }
    void setAuthor(string a) { author = a; }
    void setYear(int y) { year = y; }
    void setStatus(char s) { status = s; }

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

    virtual void display() {
        cout << left << setw(18) << toTitle(title)
             << setw(12) << toTitle(author)
             << setw(8) << getYear()
             << setw(12) << StatusStr(getStatus()) << endl;
    }
};


class Books: public Library {
private:
    vector <Books> book;

public:
    void saveFile() {
        ofstream outFile("books.txt");
        if (!outFile) {
            cout << "No book saved.\n";
            return;
        }

        for (size_t i = 0; i < book.size(); i++) {
            saveFile();
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

        Books b;

        loadFile();
        book.push_back(b);
        inFile.close();
        cout << book.size() << " book(s) loaded.\n";
    }

    void addBook() {
        string title;
        string author;
        int year;
        char status;
        Books b;

        cout << "Enter title of book: ";
        cin.ignore();
        getline(cin, title);
        setTitle(title);
        cout << "Enter author of book: ";
        getline(cin, author);
        setAuthor(author);
        cout << "Enter year of book: ";
        cin >> year;
        setYear(year);
        cout << "Available - A, Borrow - B, Reserved - R" << endl;
        cout << "Enter status of book: ";
        cin >> status;
        setStatus(status);

        saveFile();
        book.push_back(b);
    }

    void displayBook(vector <Books> &list) {
        if (!list.empty()) {
            cout << "No book to display.\n";
            return;
        }

        cout << left << setw(18) << "Title"
             << setw(12) << "Author"
             << setw(8) << "Year"
             << setw(12) << "Status" << endl;
        cout << string(55, '-') << endl;

        for (size_t i = 0; i < book.size(); i++) {
            display();
        }
    }

    void deleteBook() {
        if (!book.empty()) {
            cout << "No book to delete.\n";
            return;
        }

        string name;
        cout << "Enter the book title: ";
        cin.ignore();
        getline (cin, name);
        bool found = false;
        string Lower = toLower(name);

        for (size_t i = 0; i < book.size(); i++) {
            if (toLower(book[i].title).find(name) != string :: npos) {
                found = true;
                char confirm;
                cout << "Confirm to delete? (Y/N): ";
                cin >> confirm;

                if (toupper(confirm) == 'Y') {
                    book.erase(book.begin() + i);
                    saveFile();
                    break;
                } else if (toupper(confirm) == 'N') break;
                cout << "Please enter Y - Yes / N - No.\n";
            }   
        }
        if (!found) {
            cout << "No certain book.\n";
        }
    }

    void editBook() {
        if (book.empty()) {
            cout << "No book to edit.\n";
            return;
        }

        string name;
        cout << "Enter the title of book: ";
        cin.ignore();
        getline(cin, name);
        string lower = toLower(name);
        bool found = false;

        for (size_t i = 0; i < book.size(); i++) {
            if (toLower(book[i].title).find(name) != string::npos) {
                found = true;
                cout << "Currect: " << toTitle(book[i].title) << " (" << book[i].year << ") - "
                     << toTitle(book[i].author) << " [" << StatusStr(book[i].status) << "] \n";

                cout << "1. Edit title.\n";
                cout << "2. Edit author.\n";
                cout << "3. Edit year.\n";
                cout << "4. Edit status.\n";
                cout << "Choice: ";
                int choice;
                cin >> choice;

                if (choice == 1) {
                    string newTitle;
                    cout << "Enter new title: ";
                    getline(cin, newTitle);
                    book[i].setTitle(newTitle);
                } else if (choice == 2) {
                    string newAuthor;
                    cout << "Enter new author: ";
                    getline(cin, newAuthor);
                    book[i].setTitle(newAuthor);
                } else if (choice == 3) {
                    int newYear;
                    cout << "Enter new year: ";
                    cin >> newYear;
                    book[i].setYear(newYear);
                } else if (choice == 4) {
                    char newStatus;
                    cout << "A - Available, B - Borrowed, R - Reserved\n";
                    cout << "Enter new status in one letter: ";
                    cin >> newStatus;
                    book[i].setStatus(newStatus);
                } else cout << "Enter correct choice. (1-4)\n";
            }
        }
        if (!found) {
            cout << "No book found.\n";
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
        cout << "3."
    }
};

int main() {
    Books sys;
    sys.loadFile();

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

        if (choice == 1) sys.addBook();
        else if (choice == 2) sys.displayBook();
        else if (choice == 3) sys.deleteBook();
        else if (choice == 4) sys.editBook();
        else if (choice == 5) sys.searchBook();
        else if (choice == 6) sys.sortByName();
        else if (choice == 7) sys.sortByAuthor();
        else if (choice == 8) sys.sortByYear();
        else if (choice == 9) sys.sortByStatus();
        else if (choice == 10) break;
        else cout << "Invalid choice.\n";

    } while (choice != 10);

    return 0;
}

