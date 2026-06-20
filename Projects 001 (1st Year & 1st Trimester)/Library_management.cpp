#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
#include <iomanip>
#include <cctype>
using namespace std;

struct Book {
    string name;
    string author;
    int year;
    char status;
};

vector <Book> book;

void save() {
    ofstream outFile("books.txt");
    if (!outFile) {
        cout << "Error: Cannot save.\n";
        return;
    }

    for (size_t i = 0; i < book.size(); i++) {
        outFile << book[i].name << endl;
        outFile << book[i].author << endl;
        outFile << book[i].year << endl;
        outFile << book[i].status << endl;
    }

    outFile.close();
    cout << book.size() << " book saved.\n";
}

void load() {
    ifstream inFile("books.txt");
    if (!inFile) {
        cout << "No student loaded.\n";
        return;
    }

    Book b;
    while (getline(inFile, b.name)) {
        getline(inFile, b.author);
        inFile >> b.year;
        inFile >> b.status;
        inFile.ignore(numeric_limits<streamsize>::max(), '\n');
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
    getline(cin, b.author);
    cout << "Enter the manufacture year: ";
    cin >> b.year;
    cout << "A - Available, B - Borrowed, R - Reserved\n";
    cout << "Enter the status of book: ";
    cin >> b.status;
    book.push_back(b);
    save();
}

void display(vector <Book>& book) {
    if (book.empty()) {
        cout << "No book's info.\n";
        return;
    }

    cout << left << setw(25) << "Name"
         << setw(20) << "Author" 
         << setw(8) << "Year"
         << setw(10) << "Status" << endl;
    cout << string(63,'-') << "\n";
    
    for (size_t i = 0; i <book.size(); i++) {
        cout << left << setw(25) << book[i].name
             << setw(20) << book[i].author
             << setw(8) << book[i].year
             << setw(10) << book[i].status << endl; 
    }

}

int Status(char status) {
     if (status == 'A') return 1;
     if (status == 'R') return 2;
     if (status == 'B') return 3;
     else return 4;
}

void del() {
    if (book.empty()) {
        cout << "No book to delete.\n";
        return;
    }
    
    string name;
    cout << "Enter the book's name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline (cin,name);
    bool found = false;

    for (size_t i = 0; i < book.size(); i++) {
        if (name == book[i].name) {
            found = true;
            book.erase(book.begin() + i);
            save();
            break;
        }
    }

    if (!found ) {
        cout << "No certain book to delete.\n";
        return;
    }
}

void edit() {
    if (book.empty()) {
        cout << "No book to edit.\n";
        return;
    }

    string name;
    cout << "Enter the book's name you want to edit: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);
    bool found = false;

    for (size_t i = 0; i <book.size(); i++) {
        if (name == book[i].name) {
            found = true;

            cout << "Current info: " << book[i].name << "  (" << book[i].year
                 << ") - " << book[i].author << " - " << book[i].status << endl;
            string newName;
            cout << "Enter the new name (Enter to keep): ";
            cin.ignore();
            getline (cin, newName);

            if (!newName.empty()) {
                book[i].name = newName;
            }

            int choice;
            cout << "\n1. Edit the manufacture year.\n";
            cout << "2. Edit the author name.\n";
            cout << "3. Edit the status of book.\n";
            cout << "Choice (1-3): ";
            cin >> choice;

            if (choice == 1) {
                int newYear;
                cout << "Enter the new manufacture year: ";
                cin >> newYear;
                book[i].year = newYear;
            } else if (choice == 2) {
                string newAuthor;
                cout << "Enter the new author: ";
                cin.ignore();
                getline(cin, newAuthor);
                book[i].author = newAuthor;
            } else if (choice == 3) {
                char newStatus;
                cout << "Enter the new status (A/R/B): ";
                cin >> newStatus;
                book[i].status = newStatus;
            } else {
                cout << "Invalid input. Please enter a number (1-3).\n";
            }  
            save();
            break;
        }
    }
    if (!found) {
        cout << "No certain book to edit.\n";
        return;
    }
}

void sortByName() {
    if (book.empty()) {
        cout << "No book to arrange.\n";
        return;
    }

    vector <Book> sorted = book;
    for (size_t i = 0; i < sorted.size() - 1; i++) {
        for (size_t j = 0; j < sorted.size() - 1 -i; j++) {
            if (book[j].name > book[j+1].name) {
                Book temp = book[j];
                book[j] = book[j+1];
                book[j+1] = temp;
            }
        }
    }
    display(sorted);
}

void sortByYear() {
    if (book.empty()) {
        cout << "No book to arrange.\n";
        return;
    }

    vector <Book> sorted = book;
    for (size_t i = 0; i < sorted.size() - 1; i++) {
        for (size_t j = 0; j < sorted.size() - 1 - i; j++) {
            if (sorted[j].year < sorted[j+1].year) {
                Book temp = sorted[j];
                sorted[j] = sorted[j+1];
                sorted[j+1] = temp;
            }
        }
    }

    display(sorted);
}

void sortByAuthor() {
    if (book.empty()) {
        cout << "No book to arrange.\n";
        return;
    }

    vector <Book> sorted = book;
    for (size_t i = 0; i < sorted.size() - 1; i++) {
        for (size_t j = 0; j < sorted.size() - 1 - i; j++) {
            if (book[j].author > book[j+1].author) {
                Book temp = sorted[j];
                sorted[j] = sorted[j+1];
                sorted[j+1] = temp;
            }
        }
    }

    display(sorted);
}

void sortByStatus() {
    if (book.empty()) {
        cout << "No book to sort.\n";
        return;
    }

    vector <Book> sorted = book;
    for (size_t i = 0; i < sorted.size() - 1; i++) {
        for (size_t j = 0; j < sorted.size() - 1 -i; j++) {
            if (Status(sorted[j].status) > Status(sorted[j+1].status)) {
                Book temp = sorted[j];
                sorted[j] = sorted[j+1];
                sorted[j+1] = temp;
            }
        }
    }
    display(sorted);
}

int main() {
    load();
    int choice;

    do {
        cout << "\n1. Add a book.\n";
        cout << "2. Display all book.\n";
        cout << "3. Delete a book.\n";
        cout << "4. Edit a book's info.\n";
        cout << "5. Sort by Name (A-Z).\n";
        cout << "6. Sort by Author (A-Z).\n";
        cout << "7. Sort by Year. (High to Low)\n";
        cout << "8. Which can borrow.\n";
        cout << "9. Exits.\n";
        cout << "Choice (1-9): ";
        cin >> choice;

        if (choice == 1) {
            add();
        } else if (choice == 2) {
            display(book);
        } else if (choice == 3) {
            del();
        } else if (choice == 4) {
            edit();
        } else if (choice == 5) {
            sortByName();
        } else if (choice == 6) {
            sortByAuthor();
        } else if (choice == 7) {
            sortByYear();
        } else if (choice == 8) {
            sortByStatus();
        } else if (choice == 9) {
            break;
        } else {
            cout << "Invalid input.";
            return 1;
        }
    } while (choice != 9);

    return 0;
}