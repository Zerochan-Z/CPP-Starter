#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    string name;
    int age;
    float marks;
};

int main() {
    ofstream outFile ("students.txt");
    Student s;
    char choice;

    do {
        cout << "Enter student name: ";
        cin.ignore();
        getline(cin, s.name);

        cout << "Enter age: ";
        cin >> s.age;

        cout << "Enter marks: ";
        cin >> s.marks;

        outFile << s.name << endl;
        outFile << s.age << endl;
        outFile << s.marks << endl;

        cout << "Add another? (y/n): ";
        cin >> choice;
    
    } while (choice == 'y' || choice == 'Y');
    
    outFile.close();
    cout << "Data saved to students.txt\n";

    return 0;
}