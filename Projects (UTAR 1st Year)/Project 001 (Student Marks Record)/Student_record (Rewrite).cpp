#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cctype>
#include <limits>
using namespace std;

struct Student {
    string name;
    int mark;
};

vector <Student> student;

void saveFile() {
    ofstream outFile("students.txt");
    if (!outFile) {
        cout << "No file found.\n";
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
    if(!inFile) {
        cout << "No student loaded.\n";
        return;
    }

    Student s;
    while (getline(inFile,s.name)) {
        inFile >> s.mark;
        inFile.ignore();
        student.push_back(s);
    }

    inFile.close();
    cout << student.size() << " student(s) loaded.\n";
}

string toTitle(string &str) {
    string result = str;
    bool newWord = true;

    for (size_t i = 0; i < result.length() ; i++) {
        if (isspace(result[i])) {
            newWord = true;
        } else if (newWord) {
            result[i] = toupper(result[i]);
            newWord = false;
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

void addStudent() {
    Student s;

    cout << "Enter the student's name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline (cin, s.name);
    cout << "Enter the student's mark: ";
    cin >> s.mark;
    student.push_back(s);   
    saveFile(); 
}

void displayStudent() {
    if (student.empty()) {
        cout << "No student to display.\n";
        return;
    }

    cout << left << setw(20) << "Name" 
                 << setw(10) << "Mark" << endl;
    cout << string(55,'-') << endl;

    for (size_t i = 0 ; i < student.size(); i++) {
        cout << left << setw(20) << toTitle(student[i].name)
                     << setw(10) << student[i].mark << endl;
    }
}

void deleteStudent() {
    if (student.empty()) {
        cout << "No student to delete.\n";
        return;
    }

    string name;
    cout << "Enter his/her name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);
    bool found = false;
    for (size_t i = 0; i < student.size(); i++) {
        if (toLower(name) == toLower(student[i].name)) {
            student.erase(student.begin() + i);
            found = true;
            saveFile();
        }
    }

    if (!found) {
        cout << "No such student to delete.\n";
    }
}

void editStudent() {
    if (student.empty()) {
        cout << "No student to edit.\n";
        return;
    }

    string name;
    cout << "Enter the student's name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);
    bool found = false;

    for (size_t i = 0; i <student.size(); i++) {
        if (toLower(student[i].name) == toLower(name)) {
            found = true;
            int choice;
            cout << "1. Enter new student's name: \n";
            cout << "2. Edit student's mark: \n";
            cout << "Choice: ";
            cin >> choice;
    
            if (choice == 1) {
                string newName;
                cout << "Enter his/her new name: ";
                cin.ignore();
                getline(cin, newName);
                student[i].name = newName;
            } else if (choice == 2) {
                int newMark;
                cout << "Enter his/her new mark: ";
                cin >> newMark;
                student[i].mark = newMark;
            } else {
                cout << "Enter the (1/2).\n";
                return;
            }
        }
        saveFile();
    }
}

void searchStudent() {
    if (student.empty()) {
        cout << "No student to search.\n";
        return;
    }

    string name;
    cout << "Enter the student's name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name); 
    bool found = false;
    for (size_t i = 0; i < student.size(); i++) {
        if (toLower(student[i].name) == toLower(name)) {
            found = true;
            cout << toTitle(name) << " - " << student[i].mark;
        }
    }
    if (!found) {
        cout << "No student found.\n";
        return;
    }
}
void AverageMark() {
    if (student.empty()) {
        cout << "No student's average.\n";
        return;
    }

    int total = 0;
    for (size_t i = 0; i < student.size(); i++) {
        total = student[i].mark + total;
    }

    double avg = (double)total /student.size();
    cout << fixed << setprecision(2);
    cout << "Average: " << avg << " %" << endl;
}

void PassingRate() {
    if (student.empty()) {
        cout << "No student here.\n";
        return;
    }

    int count = 0;
    for (size_t i = 0; i < student.size(); i++) {
        if (student[i].mark > 60) {
            count++;
        } 
    }

    double pass = ((double) count / student.size())*100;
    cout << fixed << setprecision(2);
    cout << "Passing Rate (%): " << pass << endl;
    if (pass > 80.00) {
        cout << "This class is average good.\n";
    }

}

void SortedName() {
    if (student.empty()) {
        cout << "No student to sort.\n";
        return;
    }

    vector <Student> sorted = student;
    for (size_t i = 0; i < sorted.size() - 1; i++) {
        for (size_t k = 0; k < sorted.size() - 1 - i; k++) {
            if (toLower(sorted[k].name) > toLower(sorted[k+1].name)) {
                Student temp = sorted[k];
                sorted[k] = sorted[k+1];
                sorted[k+1] = temp;
            }
        }
    }
    cout << "\n --- Student's Name --- \n";
    student = sorted;
    displayStudent();
}

void SortedMark() {
    if (student.empty()) {
        cout << "No student to sort.\n";
        return;
    }

    vector <Student> sorted = student;
    for (size_t i = 0; i < sorted.size() - 1; i++) {
        for (size_t k = 0; k < sorted.size() - 1 - i; k++) {
            if (sorted[k].mark < sorted[k+1].mark) {
                Student temp = sorted[k];
                sorted[k] = sorted[k+1];
                sorted[k+1] = temp;
            }
        }
    }
    cout << "\n --- Student's Mark (High to Low) --- \n";
    student = sorted;
    displayStudent();
}

int main() {
    loadFile();
    int choice;

    do {
        cout << "\n1. Add a student.\n";
        cout << "2. Display all students.\n";
        cout << "3. Search a student.\n";
        cout << "4. Delete a student.\n";
        cout << "5. Edit a student.\n";
        cout << "6. Average marks.\n";
        cout << "7. Passing rate.\n";
        cout << "8. Sorted by Name. (A-Z)\n";
        cout << "9. Sorted by Marks. (High to Low).\n";
        cout << "10. Exits.\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) addStudent();
        else if (choice == 2) displayStudent();
        else if (choice == 3) searchStudent();
        else if (choice == 4) deleteStudent();
        else if (choice == 5) editStudent();
        else if (choice == 6) AverageMark();
        else if (choice == 7) PassingRate();
        else if (choice == 8) SortedName();
        else if (choice == 9) SortedMark();
        else if (choice == 10) break;
        else cout << "Invalid choice.\n";

    } while (choice != 9);

    return 0;
}