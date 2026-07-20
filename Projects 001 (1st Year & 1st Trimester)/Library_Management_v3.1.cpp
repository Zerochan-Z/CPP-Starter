#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <iomanip>
#include <limits>
using namespace std;

string toTitle(string str) {
    string result = str;
    bool upper = true;

    for (size_t i = 0; i < result.length(); i++) {
        if (isspace(result[i])) {
            upper = true;
        } else if (upper) {
            result[i] = toupper(result[i]);
        } 
        result[i] = tolower(result[i]);
    }
    return result;
}

string toLower(string str) {
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
    Book() : title(""), author(""), year (0), status('A') {}
    Book (string t, string a, int y, char s): title(t), author(a), year(y), status(s) {}

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

    void saveFile(ofstream& outFile) {
        outFile << title << " | " << author << " | " << year << " | " << status << endl;
    }

    void loadFile(ifstream& inFile) {
        string line;
        getline(inFile, line);

        if (line.find("|") == string::npos) return; 

        size_t pos1 = line.find(" | ");
        size_t pos2 = line.find(" | ", pos1 + 3);
        size_t pos3 = line.find(" | ", pos2 + 3);

        title = line.substr(0, pos1);
        author = line.substr(pos1 + 3, pos2 - pos1 - 3);
        year = stoi(line.substr(pos2 + 3, pos3 - pos2 - 3));
        status = line[pos3 + 3];
    }
};

class User {
private: 
    string name;
    int UserID, borrowLimit;
    vector <Book*> borrowedBooks;

public: 
    User(): name(""), UserID(000000), borrowLimit(0) {}
    User(string n, int u, int b): name(n), UserID(u), borrowLimit(b) {}

    int getID() const { return UserID; }
    string getName() const { return name; }
    virtual string getType() const = 0;

    string getBorrowed() const {
        string titles;
        for (size_t i = 0; i < borrowedBooks.size(); i++) {
            if (i > 0) {
                titles += ", ";
                titles += borrowedBooks[i]->getTitle();
            }
        }
        return titles;
    }

    bool Limit() {
        if (borrowedBooks.size() < borrowLimit) return true;
        cout << "Limits reached! \n";
        return false;
    }

    bool borrowBook(Book* book) {
        if (Limit()) {
            if (book->getStatus() == 'A') {
                borrowedBooks.push_back(book);
                book->setStatus('B');
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
                cout << book->getTitle() << " returned.\n";
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void forceBorrow(Book* book) {
        borrowedBooks.push_back(book);
        book->setStatus('B');
    }
};

class Student : public User {
public: 
    Student(string name, int id): User(name, id, 3) {}
    
    string getType() const override { return "Student"; }
};

class Staff : public User {
public: 
    Staff(string name, int id) : User(name,id, 5) {}

    string getType() const override { return "Staff"; }
};

class Library {
private: 
    vector <Book> books;
    vector <User*> users;
    string filename;
    string userFile;

public: 
    Library() { filename = "books.txt"; userFile = "users.file"; }

    void saveUsers() {
        ofstream outFile(userFile);
        if (!outFile) {
            cout << "Cannot save.\n";
            return;
        }
        
        for (size_t i = 0; i < users.size(); i++) {
            User* u = users[i];
            outFile << u->getName() << " | "
                    << u->getID() << " | "
                    << u->getType() << " | "
                    << u->getBorrowed() << endl;
        }

        outFile.close();
        cout << users.size() << " user(s) saved.\n";
    }

    void loadUsers() {
        ifstream inFile(userFile);
        if (!inFile) {
            cout << "No user loaded.\n";
            return;
        }
        string line;
        while (getline(inFile, line)) {
            if (line.empty() || line.find('|') == string::npos) continue;

            size_t pos1 = line.find(" | ");
            size_t pos2 = line.find(" | ", pos1 + 3);
            size_t pos3 = line.find(" | ", pos2 + 3);

            string name = line.substr(0, pos1);
            int id = stoi(line.substr(pos1 + 3, pos2 - pos1 - 3));
            string type = line.substr(pos2 + 3, pos3 - pos2 - 3);
            string borrowTitles = line.substr(pos3 + 3);

            User* user = nullptr;
            if (type == "Student") {
                user = new Student(name, id);
            } else if (type == "Staff") {
                user = new Staff(name, id);
            } else continue;

            if (!borrowTitles.empty()) {
                size_t start = 0;
                
                while (start < borrowTitles.length()) {
                    size_t end = borrowTitles.find(',', start);
                    string title = borrowTitles.substr(start, end - start);

                    for (size_t i = 0; i < books.size(); i++) {
                        if (toLower(books[i].getTitle()) == toLower(title)) {
                            user->forceBorrow(&books[i]);
                            break;
                        }
                    }

                    if (end == string::npos) break;
                    start = end + 1;
                }
            }
            users.push_back(user);
        }
        inFile.close();
        cout << users.size() << " user(s) laoded.\n";
    }
}