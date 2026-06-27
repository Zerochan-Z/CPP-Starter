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
    cin.ignore();
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

void displayBook(vector <Books>& list) {
    if (list.empty()) {
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
    getline(cin, name);
    bool found = false;

    for (size_t i = 0; i < book.size(); i++) {
        if (toLower(book[i].title).find(name) != string::npos) {
            found = true;
            char c;
            cout << "Confirm to delete? (Y/N): ";
            cin >> c;
            if (toupper(c) == 'Y') {
                book.erase(book.begin() + i);
                saveFile();
            } else if (toupper(c) == 'N') {
                break;
            } else {
                cout << "Plese enter Y- Yes / No - N" << endl;
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
    cout << "Enter the title: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);
    bool found = false;

    for (size_t i = 0; i < book.size(); i++) {
        if (book[i].title.find(toLower(name)) != string ::npos) {
            found = true;

            cout << "\n1. Edit book title.\n";
            cout << "2. Edit manufacture year.\n";
            cout << "3. Edit author.\n";
            cout << "4. Edit status.\n";
            int choice;
            cout << "Choice: ";
            cin >> choice;

            if (choice == 1) {
                string newName;
                cout << "Enter new title: ";
                getline(cin, newName);
                book[i].title = newName;
            } else if (choice == 2) {
                int newYear;
                cout << "Enter new year: ";
                cin >> newYear;
                book[i].year = newYear;
            } else if (choice == 3) {
                string newAuthor;
                cout << "Enter new author: ";
                getline(cin, newAuthor);
                book[i].author = newAuthor;
            } else if (choice == 4) {
                char s;
                cout << "A - Available, B - Borrowed, R - Reserved\n";
                cout << "Enter new status (A/B/R): ";
                cin >> s;
                book[i].status = s;
            } else cout << "Enter an integer as choice.\n";
            saveFile();
            break;
        }
        if (!found) {
            cout << "No certain book.\n";
            return;
        }
    }

}

void searchBook() {
    if (book.empty()) {
        cout << "No book to search.\n";
        return;
    }

    cout << "\n1. Search by title.\n";
    cout << "2. Search by author.\n";
    cout << "3. Search by year.\n";
    cout << "4. Search by status.\n";
    cout << "Choice: ";
    int choice;
    cin >> choice;

    bool found = false;

    if (choice == 1) {
        string name;
        cout << "Enter the title: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, name);

        for (size_t i = 0; i < book.size(); i++) {
            if (book[i].title.find(toLower(name)) != string ::npos) {
                found = true;
            }
        }
    } else if (choice == 2) {
        string aut;
        cout << "Enter the author: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, aut);

        for (size_t i = 0; i < book.size(); i++) {
            if (book[i].author.find(toLower(aut)) != string::npos) {
                found = true;
            }
        }
    } else if (choice == 3) {
        int y;
        cout << "Enter the year: ";
        cin >> y;

        for (size_t i = 0; i < book.size(); i++) {
            if (book[i].year == y) {
                found = true;
            }
        }
    } else if (choice == 4) {
        char c;
        cout << "Enter the status: ";
        cin >> c;

        for (size_t i = 0 ; i < book.size(); i++) {
            if (book[i].status == c) {
                found = true;
            } 
        }
    } 
    
    for (size_t i = 0 ; i < book.size(); i++) {
        if (found) {
            cout << toTitle(book[i].title) << " (" << book[i].year << ") - " << book[i].author << " - " << book[i].status;
        } else cout << "Book not found.\n";
    }
}

void SortByTitle() {
    if (book.empty()) {
        cout << "No book to sort.\n";
        return;
    }

    vector <Books> sorted = book;
    for (size_t i = 0 ; i < sorted.size() - 1; i++) {
        for (size_t k = 0; k < sorted.size() - 1 - i; k++) {
            if (sorted[k].title > sorted[k+1].title) {
                Books temp = sorted[k];
                sorted[k] = sorted[k+1];
                sorted[k+1] = temp;
            }
        }
    }
    displayBook(sorted);
}

void SortByAuthor() {
    if (book.empty()) {
        cout << "No book to sort.\n";
        return;
    }

    vector <Books> sorted = book;
    for (size_t i = 0; i < sorted.size() -1 ; i++) {
        for (size_t k = 0; k < sorted.size() - 1 - i; k++) {
            if (sorted[k].author > sorted[k+1].author) {
                Books temp = sorted[k];
                sorted[k] = sorted[k+1];
                sorted[k+1] = temp;
            }            
        }
    }
    displayBook(sorted);
}

void SortByYear() {
    if (book.empty()) {
        cout << "No book to sort.\n";
        return;
    }

    vector <Books> sorted = book;
    for (size_t i = 0; i < sorted.size() - 1; i++) {
        for (size_t k = 0; k < sorted.size() - 1 - i;k++) {
            if (sorted[k].year < sorted[k+1].year) {
                Books temp = sorted[k];
                sorted[k] = sorted[k+1];
                sorted[k+1] = temp;
            }
        }
    }
    displayBook(sorted);
}

void SortByStatus() {
    if (book.empty()) {
        cout << "No book to sort.\n";
        return;
    }

    vector <Books> sorted = book;
    for (size_t i = 0; i < sorted.size() - 1; i++) {
        for (size_t k = 0; k < sorted.size() - 1 - i;k++) {
            if (StatusPirority(sorted[k].status) > StatusPirority(sorted[k+1].status)) {
                Books temp = sorted[k];
                sorted[k] = sorted[k+1];
                sorted[k+1] = temp;
            }
        }
    }
    displayBook(sorted);
}

int main() {
    loadFile();
    int choice;

    do {
        cout << "\n1. Add a book.\n";
        cout << "2. Display every book.\n";
        cout << "3. Delete a book.\n";
        cout << "4. Edit a book info.\n";
        cout << "5. Search a book.\n";
        cout << "6. Sort by Title (A - Z).\n";
        cout << "7. Sort by Author. (A - Z).\n";
        cout << "8. Sort by Year. (High to Low).\n";
        cout << "9. Sort by Status (A - R).\n";
        cout << "10. Exits.\n";
        cout << "Choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer.\n";
            continue;
        }
        if (choice == 1) addBook();
        else if (choice == 2) displayBook(book);
        else if (choice == 3) deleteBook();
        else if (choice == 4) editBook();
        else if (choice == 5) searchBook();
        else if (choice == 6) SortByTitle();
        else if (choice == 7) SortByAuthor();
        else if (choice == 8) SortByYear();
        else if (choice == 9) SortByStatus();
        else if (choice == 10) break;
        else cout << "Enter (1-10) as your choice.\n";
    } while (choice != 10);
    
    return 0;
}