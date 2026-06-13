#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct Students {
    string name;
    int mark;
};

vector <Students> student;

void save() {
    ofstream outFile("output\Student_record.exe");
    for (size_t i = 0; i < student.size(); i++) {
        outFile << student[i].name << endl;
        outFile << student[i].mark << endl;
    } 
    outFile.close();
}

void load() {
    ifstream inFile("output\Student_record.exe");
    if (!inFile) {
        return;
    }

    Students s;
    while(getline(inFile, s.name)) {
        inFile >> s.mark;
        inFile.ignore();
        student.push_back(s);
    }
    inFile.close();
}

void add (vector <Students> &student) {
    Students s;

    cout << "Enter student's name: ";
    cin.ignore();
    getline(cin,s.name);
    cout << "Enter student's mark: ";
    cin >> s.mark;
    student.push_back(s);
}

void search (vector <Students> &student) {
    if (student.empty()) {
        cout << "No student info." << endl;
        return;
    }

    string sname;
    cout << "Enter student's name: ";
    cin.ignore();
    getline(cin, sname);
    bool found = false;

    for (size_t i = 0; i < student.size(); i++ ) {
        if (student[i].name == sname) {
            cout << sname << " - " << student[i].mark << endl;
            found = true;
        } 
    }

    if (!found) {
        cout << "No certain student found." << endl;
    }
}

void display(vector <Students> &student) {
    if (student.empty()) {
        cout << "No student info to display." << endl;
    }
    for (size_t i = 0; i < student.size(); i++) {
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
                cout << "Please enter 1 / 2 / 3 / 4 \n";
            }
        } else {
            cout << "Invalid input. Please enter the number stated. \n";
        }
    }
}

int main() {
    load();
    int choice;

    do {
        cout << "\n1. Add a student.\n";
        cout << "2. Search a student with name.\n";
        cout << "3. Display all students info.\n";
        cout << "4. Exits.\n";
        cout << "Enter choice (1-4).\n";
        choice = getValidChoice();

        if (choice == 1) {
            add(student);
        } else if (choice == 2) {
            search(student);
        } else if (choice == 3) {
            display(student);
        } else if (choice == 4) {
            break;
        }
    } while (choice != 4);

    return 0;
}