#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct students {
    string name;
    int marks;
};

void addStudent (vector <students>& student ) {
    students s;
    cout << "Enter student's name: ";
    cin.ignore();
    getline(cin, s.name);
    cout << "Enter student's marks: ";
    cin >> s.marks;
    student.push_back(s);
    cout << "Student added.\n";
}

void displayStudent (vector <students>& student) {
    if (student.empty()) {
        cout << "No student info displayed!\n ";
        return;
    } 
    for (int i = 0; i < student.size(); i++) {
        cout << i+1 << ". " << student[i].name
             << " - " << student[i].marks << endl;
    }
}

int main() {
    vector <students> student;
    int choice;



    do {
        cout << "\n1. Add a student.\n";
        cout << "2. Display student info.\n";
        cout << "3. Exit.\n";
        cout << "Insert (1/2/3)\n";
        cin >> choice;

        if (choice == 1) {
            addStudent(student);
        } else if (choice == 2) {
            displayStudent(student);
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice. " << endl;
        }
    } while (choice != 3);

    return 0;
}