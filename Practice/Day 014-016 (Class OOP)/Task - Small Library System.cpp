#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <vector>
#include <fstream>
using namespace std;

class Book {
private:
    string title, author;
    int year;
    char status;

public:
    Book() : title(""), author(""), year(0), status('A') {}
    Book(string t, string a, int y, char s) : title(t), author(a), year(y), status(s) {}

    string getTitle() { return title; }

    string getAuthor() { return author; }

    int getYear() { return year; }

    char getStatus() { return status; }

    void setTitle(string t) { title = t; }
    void setAuthor(string a) { author = a; }
    void setYear(int y) { year = y; }
    void setStatus(char s) {
        if (s == 'A' || s == 'B' || s == 'R') {
            status = s;
        }
        else cout << "Enter (A/B/R)" << endl;
    }

    void saveFile(ofstream &out) {
        out << title << endl;
        out << author << endl;
        out << year << endl;
        out << status << endl;
    }

    void loadFile(ifstream& in) {
        getline(in, title);
        getline(in, author);
        in >> year;
        in >> status;
        in.ignore();
    }

    void display() {
        cout << left << setw(22) << title
            << setw(20) << author
            << setw(8) << year
            << setw(12) << status << endl;
    }
};

class Library {
private:
    vector <Book> books;

public:

    void save() {
        ofstream out("books.txt");
        if (!out) {
            cout << "No book saved.\n";
            return;
        }
        
        for (size_t i = 0; i < books.size(); i++) {
            books[i].saveFile(out);
        }

        out.close();
    }

    void load() {
        ifstream in("books.txt");
        if (!in) {
            cout << "No book load.\n";
            return;
        }

        Book b;
        while (!(in.eof())) {
            b.loadFile(in);
            books.push_back(b);
        }

        in.close();
    }

    void addBook() {
        Book b;

        string title;
        cout << "Enter book title: ";
        cin.ignore();
        getline(cin, title);
        b.setTitle(title);

        string author;
        cout << "Enter book author: ";
        getline(cin, author);
        b.setAuthor(author);

        int year;
        cout << "Enter the year: ";
        cin >> year;
        b.setYear(year);

        char s;
        cout << "Enter status: ";
        cin >> s;
        s = toupper(s);
        b.setStatus(s);

        books.push_back(b);
        save();
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "No book to display.\n";
            return;
        }

        cout << left << setw(22) << "Title"
            << setw(20) << "Author"
            << setw(8) << "Year"
            << setw(12) << "Status" << endl;
        cout << string(65, '-') << endl;

        for (size_t i = 0; i < books.size(); i++) {
            books[i].display();
        }
    }

    void searchBook() {
        if (books.empty()) {
            cout << "No book to search.\n";
            return;
        }

        string search;
        cout << "Enter the title: ";
        cin.ignore();
        getline(cin, search);
        bool found = false;

        for (size_t i = 0; i < books.size(); i++) {
            if (books[i].getTitle().find(search) != string::npos) {
                found = true;
                cout << books[i].getTitle() << " (" << books[i].getYear() << ") - " << books[i].getAuthor() << " - " << books[i].getStatus() << endl;
            }
        }
        if (!found) {
            cout << "No certain book.\n";
        }
    }

    void countBooks() {
        int num = books.size();
        cout << "Number of books: " << num << endl;

    }
};

int main() {
    Library lib;
    lib.load();

    int choice;
    do {
        cout << "\n1. Add a book.\n";
        cout << "2. Display a book.\n";
        cout << "3. Search a book.\n";
        cout << "4. Exit.\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) lib.addBook();
        else if (choice == 2) lib.displayBooks();
        else if (choice == 3) lib.searchBook();
        else if (choice == 4) break;
        else cout << "Please enter the correct input. (1-4)\n" << endl;
    } while (choice != 4);

    return 0;
}
