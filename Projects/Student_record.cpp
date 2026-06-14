#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>
using namespace std;

struct Students {
    string name;
    int mark;
};

vector <Students> student;

void save() {
    ofstream outFile("Students.txt");
    if (!outFile) {
        cout << "ERROR! No certain file.\n";
        return;
    }

    for (size_t i = 0; i < student.size(); i++) {
        outFile << student[i].name << endl;
        outFile << student[i].mark << endl;
    }

    outFile.close();
    cout << "Saved " << student.size() << " studetn(s) to file. \n";
}

void load() {
    ifstream inFile("Students.txt");
    if (!inFile) {
        cout << "ERROR no certain file!" << endl;
        return;
    }

    Students s;

    while(getline(inFile, s.name)) {
        inFile >> s.mark;
        inFile.ignore();
        student.push_back(s);
    }

    inFile.close();
    cout << "Loaded " << student.size() << " student(s).\n";
}

void add() {
    Students s;

    cout << "Enter student's name: ";
    cin.ignore();
    getline(cin, s.name);
    cout << "Enter student's mark: ";
    cin >> s.mark;
    student.push_back(s);
    save();
}

void search() {
    if (student.empty()) {
        cout << "No student to search.\n";
        return;
    }

    string name;
    cout << "Enter the student's name: ";
    cin.ignore();
    getline(cin, name);

    bool found = false;
    for (size_t i = 0; i < student.size(); i++) {
        if (student[i].name == name) {
            cout << name << " - " << student[i].mark << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No certain student." << endl;
    }
}

void display () {
    if (student.empty()) {
        cout << "No student info." << endl;
        return;
    }

    for (size_t i = 0; i < student.size(); i++) {
        cout << i+1 << ". " << student[i].name << " - " << student[i].mark << endl;
    }
}

void del() {
    if (student.empty()) {
        cout << "No student to delete.\n";
        return;
    }
    string name;
    cout << "Enter the name of student to delete: ";
    cin.ignore();
    getline(cin,name);

    bool found = false;
    for (size_t i = 0; i < student.size(); i++) {
        if (student[i].name == name) {
            student.erase(student.begin() + i);
            cout << name << "student" << " deleted.\n";
            found = true;
            save();
            break;
        }
    }

    if (!found) {
        cout << name << " student not found.\n";
    }
}

void average() {
    if (student.empty()) {
        cout << "No student's mark to calculate average.\n";
        return;
    }
    string name;
    int total = 0;
    for (size_t i = 0; i<student.size(); i++) {
        total = total + student[i].mark;
    }

    double avg = (double) total / student.size();
    cout << "Average mark: " << avg << endl;
}

void sortMark() {
    if (student.empty()) {
        cout << "No students to sort.\n";
        return;
    }

    vector <Students> sorted = student; // copy struct as new

    for (size_t i = 0; i < sorted.size() - 1; i++) {
        for (size_t j = 0 ; j < sorted.size() -i -1; j++) {
            if (sorted[j].mark < sorted[j+1].mark) {
                Students temp = sorted[j];
                sorted[j] = sorted[j+1];
                sorted[j+1] = temp;
            }
        }
    }

    cout << "\n --- Students sorted by mark (Highest to Lowest) --- \n";
    for (size_t i = 0; i < sorted.size(); i++) {
        cout << i+1 << ". " << sorted[i].name << " - " << sorted[i].mark << endl;
    }
}

void sortName () {
    if (student.empty()) {
        cout << "No students to sort.\n";
        return;
    }

    vector <Students> sorted = student;

    for (size_t i = 0; i < sorted.size() - 1; i++) {
        for (size_t j = 0; j < sorted.size() - 1 - i; j++) {
            if (sorted[j].name > sorted[j+1].name) {
                Students temp = sorted[j];
                sorted[j] = sorted[j+1];
                sorted[j+1] = temp;
            }
        }
    }

    cout << "\n --- Students sorted by name (A-Z) --- \n";
    for (size_t i = 0; i < sorted.size(); i++) {
        cout << i+1 << ". " << sorted[i].name << " - " << sorted[i].mark << endl;
    }
}
int validation() {
    string input;

    while(true) {
        cout << "Choice (1-4): ";
        cin >> input;

        bool valid = true;
        for (char c : input) {
            if (!isdigit(c)) {
                valid = false;
                break;
            }
        }

        if (valid) {
            int choice = stoi(input);
            if (choice >= 1 && choice <=8 ) {
                return choice;
            } else {
                cout << "Please enter (1-4).\n";
            }
        }
    }
}

int main() {
    load();

    int choice;

    do {
        cout << "\n1. Add a student.\n";
        cout << "2. Search student with name.\n";
        cout << "3. Display all student.\n";
        cout << "4. Delete student.\n";
        cout << "5. Calculate average.\n";
        cout << "6. Sorted by highest mark to lowest.\n";
        cout << "7. Sorted name by A-Z";
        cout << "8. Exit.\n";
        choice = validation();

        if (choice == 1) add();
        else if (choice == 2) search();
        else if (choice == 3) display();
        else if (choice == 4) del();
        else if (choice == 5) average();
        else if (choice == 6) sortMark();
        else if (choice == 7) sortName;
        else if (choice == 8) break;
    } while (choice != 4);
}