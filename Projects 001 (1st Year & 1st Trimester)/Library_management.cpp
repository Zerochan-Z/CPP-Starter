
/* Book Title
Author
Year
Status (Borrowed/Available)
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
using namespace std;

struct Book {
    string name;
    string author;
    int year;
    string status;
};

vector <Book> book;

void save() {
    ofstream outFile("books.txt");
    if (!outFile) {
        cout << "No certain files. Creating...\n";
        return;
    }

    for (size_t i = 0; i < book.size(); i++) {
        outFile << book[i].name << endl;
        outFile << book[i].author << endl;
        outFile << book[i].year << endl;
        outFile << book[i].status << endl;
    }

    outFile.close();
}

void load() {
    ifstream inFile("books.txt");
    if (!inFile) {
        cout << "No student loaded.\n";
        return;
    }

    Book b;
    while (getline(inFile, b.name)) {
        inFile >> b.author;
        inFile >> b.year;
        inFile >> b.status;
        inFile.ignore(numeric_limits<streamsize>::max(); '\n');
        book.push_back(b);
    }

    inFile.close();
    cout << book.size() << " book(s) loaded.\n";
}

void add() {
    Book b;

    cout << "Enter the book's name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, b.name);
    cout << "Enter the author: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, b.author);
    cout << "Enter the manufacture year: ";
    cin >> b.year;
    cout << "Enter the status of the book: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline (cin, b.status);    
    book.push_back(b);
    save();
}

void display() {
    if (book.empty()) {
        cout << "No book's info.\n";
        return;
    }

    for (size_t i = 0; i < book.size(); i++) {
        cout << book.name << 
    }
}