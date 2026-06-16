#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
using namespace std;

struct Student {
    string name;
    int mark;
};

vector <Student> student;

void save() {
    ofstream outFile("students.txt");
    if (!outFile) {
        cout << "No certain file. Creating...";
        return;
    }

    for (size_t i = 0; i < student.size(); i++) {
        outFile << student[i].name << endl;
        outFile << student[i].mark << endl;
    }
    outFile.close();
}

void load() {
    ifstream inFile("students.txt");
    if (!inFile) {
        return;
    }

    Student s;
    while (getline(inFile, s.name)) {
        inFile >> s.mark;
        inFile.ignore(numeric_limits<streamsize>::max(), '\n');
        student.push_back(s);
    }
    inFile.close();
    cout << student.size() << " student(s) loaded from 'students.txt'.\n";
}

void add() {
    Student s;

    cout << "Enter the student's name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, s.name);
    cout << "Enter the student's mark: ";
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

    cout << "Enter student's name to find their marks: ";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    getline(cin,name);

    bool found = false;
    for (size_t i = 0; i < student.size(); i++) {
        if (name == student[i].name) {
            cout << name << " - " << student[i].mark;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "No certain student.\n";
        return;
    }
}

void display () {
    if (student.empty()) {
        cout << "No student to display.\n";
        return;
    }

    for (size_t i = 0; i <student.size(); i++) {
        cout << i+1 << ". " << student[i].name << " - " << student[i].mark << endl;
    }
}

void del() {
    if (student.empty()) {
        cout << "No student to delete.\n";
        return;
    }
    string name;
    
    cout << "Enter the student to delete: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);

    bool found = false;
    for (size_t i = 0; i < student.size(); i++) {
        if (name == student[i].name) {
            student.erase(student.begin() + i);
            found = true;
            save();
            break;
        }
    }
    if (!found) {
        cout << "No certain student.\n";
        return;
    }
}

void edit() {
    if (student.empty()) {
        cout << "No student to edit.\n";
        return;
    }
    string name;

    cout << "\n ---> Edit/Add student's data <--- \n";
    cout << "Enter the student's name: ";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    getline(cin, name);
    bool found = false;

    for (size_t i = 0; i < student.size(); i++) {
        if (name == student[i].name) {
            found = true;

            cout << "\nCurrent: " << student[i].name << " - " << student[i].mark << endl;
            
            cout << "Enter new name (or press Enter to continue): ";
            string newName;
            getline(cin, newName);
            if (!newName.empty()) {
                student[i].name = newName;
            }

            cout << "1. Edit student's mark.\n";
            cout << "2. Add mark with the same name.\n";
            int choice;
            cout << "Enter your choice (1 / 2): ";
            cin >> choice;

            if (choice == 1) {
                cout << "From " << student[i].mark << "changed to ";
                int newMark;
                cin >> newMark;
                student[i].mark = newMark;
            } else if (choice == 2) {
                Student newStudent;
                newStudent.name = student[i].name;
                cout << "Enter another mark for " << student[i].name << ": ";
                cin >> newStudent.mark;
                student.push_back(newStudent);
                cout << "Added " << student[i].mark << "to" << student[i].name << endl;
            } else cout << "Invalid choice. No changes made.\n";

            save();
            break;
        }
    }

    if (!found) {
        cout << "No certain student to edit/add.\n";
        return;
    }
}
void average() {
    if (student.empty()) {
        cout << "No student info to calculate.\n";
        return;
    }
    int total = 0;
    for (size_t i = 0; i < student.size(); i++) {
        total = total + student[i].mark;
    }

    double avg = (double) total / student.size();
    cout << fixed << setprecision(2);
    cout << "Average: " << avg << endl;
}

void sortMark() {
    if (student.empty()) {
        cout << "No student info.\n";
        return;
    }

    vector <Student> sorted = student;
    for (size_t i = 0; i < sorted.size()-1 ; i++) {
        for (size_t j = 0; j < sorted.size() - 1 - i; j++) {
            if (sorted[j].mark < sorted[j+1].mark) {
                Student temp = sorted[j];
                sorted [j] = sorted[j+1];
                sorted[j+1] = temp;
            }
        }
    }

    cout << " --- Student's marks (HIGH - LOW) --- \n";
    for (size_t i = 0; i < sorted.size(); i++) {
        cout << sorted[i].name << " - " << sorted[i].mark;
    }
}

void sortName() {
    if (student.empty()) {
        cout << "No student info.\n";
        return;
    }
    vector <Student> sorted = student;
    for (size_t i = 0; i < sorted.size()-1 ; i++) {
        for (size_t j = 0; j < sorted.size()-1 -i; j++) {
            if (sorted[j].name > sorted[j+1].name) {
                Student temp = sorted[j];
                sorted[j] = sorted[j+1];
                sorted[j+1] = temp;
            }
        }
    }

    cout << " --- Student sorted by Name (A-Z) ---\n";
    for (size_t i = 0; i < sorted.size(); i++) {
        cout << sorted[i].name << " - " << sorted[i].mark;
    } 
}

int main() {
    load();
    int choice;

    do {
        cout << "\n1. Add a student.\n";
        cout << "2. Search a student.\n";
        cout << "3. Display all students.\n";
        cout << "4. Delete a student.\n";
        cout << "5. Calculate marks' average.\n";
        cout << "6. Sorted Mark (High - Low).\n";
        cout << "7. Sorted Name (A - Z).\n";
        cout << "8. Exits.\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) add();
        else if (choice == 2) search();
        else if (choice == 3) display();
        else if (choice == 4) del();
        else if (choice == 5) average();
        else if (choice == 6) sortMark();
        else if (choice == 7) sortName();
        else if (choice == 8) break;
    } while (choice != 8);

    return 0;
}