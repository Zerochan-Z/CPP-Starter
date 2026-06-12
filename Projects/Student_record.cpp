#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

struct Students {
    string name;
    int mark;
};

void add (vector <Students> &student) {
    Students s;

    cout << "Enter student's name: ";
    cin.ignore();
    getline(cin, s.name);
    cout << "Enter student's mark: ";
    cin >> s.mark;
    student.push_back(s);
}

void search (vector <Students> &student) {
    if (student.empty()) {
        cout << "No student info. Please insert one." << endl;
        return;
    }

    string name;
    cout << "Enter the student's name: ";
    cin.ignore();
    getline(cin, name);
    bool found = false;

    for (int i = 0; i < student.size(); i++) {
        if (student[i].name == name) {
            cout << student[i].name << " - " << student[i].mark << endl;
            found = true;
        }
    }
    
    if (!found) {
        cout << "No certain student found." << endl;
    }
}

void info (vector <Students> &student) {
    if (student.empty()) {
        cout << "No student info." << endl;
        return;
    }

    for (int i = 0; i < student.size(); i++) {
        cout << i+1 << ". " << student[i].name << " - " << student[i].mark << endl;
    }
}

int getValidChoice() {
    string input;

    while (true) {
        cout << "Choice: ";
        cin >> input;

        bool isValid = true;
        for (char c : input) {
            if (!isdigit(c)) {
                isValid = false;
                break;
            }
        }
        if (isValid) {
            int choice = stoi(input);
            if (choice >= 1 && choice <=4) {
                return choice;
            } else {
                cout << "Enter 1 / 2 / 3 / 4 \n";
            }
        } else {
            cout << "Invalid input. Please enter the number.";
        }
    }
}
int main() {
    vector <Students> student;
    int choice;

    do {
        cout << "\n1. Add a student\n";
        cout << "2. Search a student with name\n";
        cout << "3. Display all students' info\n";
        cout << "4. Exit\n";
        cout << "Enter choice (1-4)\n";
        choice = getValidChoice();

        if (choice == 1) {
            add(student);
        } else if (choice == 2) {
            search(student);
        } else if (choice == 3) {
            info(student);
        } else if (choice == 4) {
            break;
        } 
    } while (choice != 4);

    return 0;
}