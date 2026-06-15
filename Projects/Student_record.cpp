#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <limits>
using namespace std;

struct Student {
    string name;
    int mark;
};

vector <Student> student;

void save() {
    ofstream outFile("students.txt");

    for (size_t i = 0; i < student.size(); i++) {
        outFile << student[i].name << endl;
        outFile << student[i].mark << endl; 
    }
    
    outFile.close();
}

void load() {
    ifstream inFile("students.txt");
    
    if (!inFile) {
        cout << "No certain file.\n";
        return;
    }

    Student s;
    while (getline(inFile, s.name)) {
        inFile >> s.mark;
        inFile.ignore();
        student.push_back(s);
    }
    inFile.close();
}

void addStudent() {
    Student s;

    cout << "Enter student's name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, s.name);
    cout << "Enter student's mark: ";
    cin >> s.mark;
    student.push_back(s);
    save();
}

void display() {
    if (student.empty()) {
        cout << "No student info.\n";
        return;
    }

    for (size_t i = 0; i < student.size(); i++) {
        cout << i+1 << ". " << student[i].name << " - " << student[i].mark << endl;
    }
}

void search() {
    if (student.empty()) {
        cout << "No student to search." << endl;
        return;
    }

    string name;
    cout << "Enter the student name: ";
    cin.ignore(numeric_limits<streamsize>::max());
    getline(cin, name);

    bool found = false;
    for (size_t i = 0; i < student.size(); i++) {
        if (student[i].name == name) {
            cout << name << " - " << student[i].mark << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No certain student found." << endl;
    }
}

void del() {
    if (student.empty()) {
        cout << "No student to delete." << endl;
        return;
    }

    string name;
    Student s;
    cout << "Enter the student you want to delete: ";
    cin.ignore(numeric_limits<streamsize>::max());
    getline(cin, name);

    bool found = false;
    for (size_t i = 0; i < student.size(); i++) {
        if (student[i].name == name) {
            student.erase(student.begin() + i);
            found = true;
            save();
            break;
        }
    }
    if (!found) {
        cout << "Student " << name << " is not in the list." << endl;
    }
}

void average() {
    if (student.empty()) {
        cout << "No student data.\n";
        return;
    }

    int total = 0;
    for (size_t i= 0; i < student.size(); i++) {
        total = total + student[i].mark;
    }

    double avg = (double) total / student.size();
    cout << fixed << setprecision(2);
    cout << "Average: " << avg << endl;
}

void sortmark() {
    if (student.empty()) {
        cout << "No student to sort." << endl;
        return;
    }

    vector <Student> sorted = student;

    for (size_t i = 0; i < sorted.size() -1; i++) {
        for (size_t j = 0; j < sorted.size()- 1 -i; j++) {
            if (sorted[j].mark <  sorted[j+1].mark) {
                Student temp = sorted[j];
                sorted[j] = sorted[j+1];
                sorted[j+1] = temp;
            }
        }
    }
    cout << "\n --- Students sorted by mark (High to Low) ---\n";
    for (size_t i = 0; i < sorted.size(); i++) {
        cout << i+1 << ". " << sorted[i].name << " - " << sorted[i].mark << endl;
    }
}

void sortName() {
    if (student.empty()) {
        cout << "No student to sort." << endl;
        return;
    }

    vector <Student> sorted = student;

    for (size_t i = 0; i < sorted.size()-1; i++) {
        for (size_t j = 0; j < sorted.size()-1-i; j++) {
            if (sorted[j].name > sorted[j+1].name) {
                Student temp = sorted[j];
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

int main() {
    load();
    int choice;

    do {
        cout << "\n1. Add Student\n";
        cout << "2. Search Student\n";
        cout << "3. Display All Students\n";
        cout << "4. Delete Student\n";
        cout << "5. Average Mark\n";
        cout << "6. Sort by Name (A-Z)\n";
        cout << "7. Sort by Mark (High to Low)\n";
        cout << "8. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) addStudent();
        else if (choice == 2) display();
        else if (choice == 3) search();
        else if (choice == 4) del();
        else if (choice == 5) average();
        else if (choice == 6) sortmark();
        else if (choice == 7) sortName();
        else if (choice == 8) break;
    } while (choice != 8);

    return 0;
}