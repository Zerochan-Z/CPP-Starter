#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <limits>
#include <iomanip>
using namespace std;

string toTitle(string &str) {
    string result = str;
    bool Upper = true;

    for (size_t i = 0; i < result.length(); i++ ) {
        if (isspace(result[i])) {
            Upper = true;
        } else if (Upper) {
            result[i] = toupper(result[i]);
            Upper = false;
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

int StatusNum (char status) {
    if (status == 'A') return 1;
    if (status == 'B') return 2;
    if (status == 'R') return 3;
    else return 4;
}

class Book {
    private: 
        string title, author;
        int year;
        char status;
    
    public:

        Book() : title(""), author(""), year(0), status('A') {}
        Book (string t, string a, int y, char s) : title(t), author(a), year(y), status(s) {}

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
        void setAuthor (string a) { 
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                cout << "Invalid input.\n";
            } else author = a;
        }
        void setYear (int y) { 
            if (y > 0 && y < 2027) {
                year = y;
            } else {
                cin.clear();
                cin.ignore();
                cout << "Invalid input.\n";
            }
        }
        void setStatus (char s) {
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                cout << "Please enter an alphabet.\n A - Availble   B - Borrowed    R - Reserved\n";
            } else status = toupper(s);
        }

        void display() {
            cout << left << setw(25) << toTitle(name)
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
            ofstream outFile("books.txt");
            if (!outFile) {
                cout << "Error.\n";
                return;
            }

            for (size_t i = 0; i < book.size(); i++) {
                book[i].saveFile(outFile);
            }

            outFile.close();
        }

        void loadFile() {
            ifstream inFile("books.txt");
            if (!inFile) {
                cout << "Error.\n";
                return;
            }

            Book b;
            while (!inFile.eof()) {
                b.loadFile(inFile);
                book.push_back(b);
            }
            inFile.close();
        }

        void addBook() {
            Book b;
            string title, author;
            int year;
            char status;
        }
}