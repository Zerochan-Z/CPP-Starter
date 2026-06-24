#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>
using namespace std;

struct Books {
    string title;
    int year;
    string author;
    char status;
};

vector<Books> book;

void saveFile() {
    ofstream outFile("books.txt");
    if (!outFile) {
        cout << "No books found.\n";
        return;
    }

    for (size_t i = 0; i < book.size(); i++) {
        outFile << book[i].title << endl;
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
        cout << "No books loaded.\n";
        return;
    }

    Books b;
    while (getline(inFile, b.title)) {
        getline(inFile, b.author);
        inFile >> b.year;
        inFile >> b.status;
        inFile.ignore();
        book.push_back(b);
    }

    inFile.close();
    cout << book.size() << " book(s) loaded.\n";
}

string toTitle(string &str) {
    string result = str;

    bool lower = false;
    for (size_t i = 0; i < result.length(); i++) {
        if (isspace(result[i])) {
            lower = true;
        } else if (lower) {
            result[i] = toupper(result[i]);
            lower = false;
        } else {
            result[i] = tolower(result[i]);
        }
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

string statusToString(char status) {
        if (status == 'A') return "Available";
        if (status == 'B') return "Borrowed";
        if (status == 'R') return "Reserved";
        else return "Missing";
} 

int StatusPirority(char status) {
    if (status == 'A') return 1;
    if (status == 'B') return 2;
    if (status == 'R') return 3;
    else return 4;
}

void addBook() {
    Books b;

    cout << "Enter the title: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, b.title);
    b.title = toLower(b.title);
    cout << "Enter the author: ";
    getline(cin, b.author);
    b.author = toLower(b.author);
    cout << "Enter the year: ";
    cin >> b.year;
    cout << "Enter the status: ";
    cin >> b.status;
    book.push_back(b);
    saveFile();
}

void BookStatus () {
    if (book.empty()) {
        cout << "No status displayed.\n";
        return;
    }

    int a = 0, b = 0, r = 0, m = 0;
    for (size_t i = 0; i < book.size(); i++) {
        if (book[i].status == 'A') a++;
        if (book[i].status == 'B') b++;
        if (book[i].status == 'R') r++;
        if (book[i].status == ' ') m++;
    }

    cout << "\n ---- Book Status Summary ----- \n";
    cout << "Available: " << a << endl;
    cout << "Borrowed: " << b << endl;
    cout << "Reserved: " << r << endl;
    cout << "Missing: " << m << endl;
}

void displayBook() {
    if (book.empty()) {
        cout << "No book displayed.\n";
        return;
    }

    cout << left << setw(30) << "Title" 
         << setw(20) << "Author"
         << setw(10) << "Year"
         << setw(5) << "Status" << endl;
    cout << string(65, '-') << endl;

    for (size_t i = 0; i < book.size(); i++) {
        cout << left << setw(30) << toTitle(book[i].title)
             << setw(20) << toTitle(book[i].author)
             << setw(10) << book[i].year
             << setw(5) << statusToString(book[i].status) << endl;
    }

    BookStatus();
}

void deleteBook() {
    if (book.empty()) {
        cout << "No book to delete.\n";
        return;
    }

    string name;
    cout << "Enter the book's title: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    bool found = false;

    for (size_t i = 0; i < book.size(); i++) {
        if (toLower(book[i].title).find(name) != string::npos) {
            found = true;
            char c;
            cout << "Confirm to delete? (Y/N): ";
            cin >> c;
            if (toTitle(c) == 'Y') {
                book.erase(book.begin() + i);
                saveFile();
            } else if (toTitle(c) == 'N') {
                break;
            } else {
                cout << "Plese enter Y- Yes / No - N" << endl;
            }
        }
    }
}
