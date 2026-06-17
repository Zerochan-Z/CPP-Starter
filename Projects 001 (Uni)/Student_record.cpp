#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <vector>
#include <string>
using namespace std;

struct Student {
    string name;
    int mark;
};

vector <Student> student;

void saveFile() {
    ofstream outFile("students.txt");
    if (!outFile) {
        cout << "No certain file.\n";
        return;
    }

    for (size_t i = 0; i < student.size(); i++) {
        outFile << student[i].name << endl;
        outFile << student[i].mark << endl;
    }

    outFile.close();
}

void loadFile() {
    ifstream inFile("students.txt");
    if (!inFile) {
        cout << "No student loaded.\n";
        return;
    }

    Student s;
    while (getline(inFile, s.name)) {
        inFile >> s.mark;
        inFile.ignore(numeric_limits<streamsize>::max(), '\n');
        student.push_back(s);
    }

    inFile.close();
    cout << "Loaded " << student.size() << " students.\n";
}

void addStudent() {
    Student s;

    cout << "Enter the student's name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, s.name);
    cout << "Enter the student's mark: ";
    cin >> s.mark;
    student.push_back(s);
    saveFile();
}

void displayStudent() {
    if (student.empty()) {
        cout << "No student info to display.\n";
        return;
    }
    for (size_t i = 0; i < student.size(); i++) {
        cout << i+1 << ". " << student[i].name << " - " << student[i].mark << endl;
    }
}

void searchStudent() {
    if (student.empty()) {
        cout << "No student to search.\n";
        return;
    }

    string name;
    cout << "\nEnter the student's name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline (cin, name);
    bool found = false;

    for (size_t i = 0; i < student.size(); i++) {
        if (name == student[i].name) {
            found = true;
            cout << "\n" << name << " - " << student[i].mark << endl;
            break;
        }
    }
    if (!found) {
        cout << "No certain student to search.\n";
        return;
    }
}

void deleteStudent() {
    if (student.empty()) {
        cout << "No student to delete.\n";
        return;
    }

    string name;
    cout << "Enter the student's name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,name);
    
    bool found = false;
    for (size_t i = 0; i < student.size(); i++) {
        if (student[i].name == name) {
            found = true;
            student.erase(student.begin()+ i);
            saveFile();
            cout << student[i].name << " deleted.\n";
            break;
        }
    }

    if (!found) {
        cout << "No certain student.\n";
        return;
    }
}

void editFile() {
    if (student.empty()) {
        cout << "No student to edit.\n";
        return;
    }

    string name;
    cout << "Enter the student's name to edit: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,name);
    bool found = false;

    for (size_t i = 0; i < student.size(); i++) {
        if (student[i].name == name) {
            found = true;

            string newName;
            cout << "Edit the student's name (Press enter to skip): \n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline (cin,newName);

            if (!newName.empty()) {
                student[i].name = newName;
            }

            cout << "\n1. Edit student's mark.\n";
            cout << "2. Add student's mark.\n";
            cout << "Choice (1 / 2): ";
            int choice;
            cin >> choice;

            if (choice == 1) {
                cout << student[i].mark << " changed to -> ";
                int newMark;
                cin >> newMark;
                student[i].mark = newMark;
                cout << "Mark changed.\n";
            } else if (choice == 2) {
                Student newStudent;
                newStudent.name = student[i].name;
                cout << "Enter the student's mark: ";
                cin >> newStudent.mark;
                student.push_back(newStudent);
                cout << "Succesfully added.\n";
            } else {
                cout << "Invalid input. Please enter the number.\n";
            }
        }
        saveFile();
        break;
    }

    if (!found) {
        cout << "No certain student.\n";
        return;
    }
}

void averageStudent() {
    if (student.empty()) {
        cout << "No student to calculate.\n";
        return;
    }

    int total = 0;
    for (size_t i = 0; i < student.size(); i++) {
        total = student[i].mark + total;
    }
    double avg = (double) total / student.size();
    cout << fixed << setprecision(2);
    cout << "Average: " << avg << endl;
}

void sortByMark() {
    if (student.empty()) {
        cout << "No student to sort.\n";
        return;
    }

    vector <Student> sorted = student;

    for (size_t i = 0; i < sorted.size()-1 ; i++) {
        for (size_t j = 0; j < sorted.size() - 1 - i; j++) {
            if (sorted[j].mark < sorted[j+1].mark) {
                Student temp = sorted[j];
                sorted[j] = sorted[j+1];
                sorted[j+1] = temp;
            }

        }
    }

    cout << "\n--- Arranged data from High to Low ---\n";
    for (size_t i = 0; i < student.size(); i++) {
        cout << sorted[i].name << " - " << sorted[i].mark << endl;
    }
}

void sortByName() {
    if (student.empty()) {
        cout << "No student to sort.\n";
        return;
    }

    vector <Student> sorted = student;

    for (size_t i = 0; i < sorted.size() - 1; i++) {
        for (size_t j = 0; j < sorted.size() - 1 - i; j++) {
            if (sorted[j].name > sorted[j+1].name) {
                Student temp = sorted[j];
                sorted[j] = sorted[j+1];
                sorted[j+1] = temp;
            }
        }
    }

    cout << "\n --- Sorted Students' Name (A - Z) ---\n";
    for (size_t i = 0; i < sorted.size(); i++) {
        cout << sorted[i].name << " - " << sorted[i].mark << endl;
    }
}

int main() {
    loadFile();
    int choice;

    do {
        cout << "\n1. Add a student.\n";
        cout << "2. Display all the student.\n";
        cout << "3. Search student.\n";
        cout << "4. Delete a student.\n";
        cout << "5. Edit a student.\n";
        cout << "6. Calculate average.\n";
        cout << "7. Sort the marks from (High to Low).\n";
        cout << "8. Sort the name (A - Z).\n";
        cout << "9. Exits.\n";
        cout << "Enter the choice (1-9): ";
        cin >> choice;

        if (choice == 1) addStudent();
        else if (choice == 2) displayStudent();
        else if (choice == 3) searchStudent();
        else if (choice == 4) deleteStudent();
        else if (choice == 5) editFile();
        else if (choice == 6) averageStudent();
        else if (choice == 7) sortByMark();
        else if (choice == 8) sortByName();
        else if (choice == 9) {
            cout << "\n\nThanks for using this system. \n(๑•̀ㅂ•́)و✧";
            break;
        }
        else cout << "ERROR! Please enter a number.\n";
    } while (choice != 9);
}