#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string name;
    int age;
    double gpa;

    ofstream outFile;
    outFile.open("students.txt");

    outFile << "Alice " << 20 << " " << 3.8 << endl;
    outFile << "Bob " << 21 << " " << 3.5 << endl;

    outFile.close();

    ifstream inFile;
    inFile.open("students.txt");

    if (!inFile) {
        cout << "Error opening file! " << endl;
        return 1;
    }

    cout << "--- Students from file ---" << endl;
    while (inFile >> name >> age >> gpa) {
        cout << "Name: " << name << ", Age: " << age << ", GPA: " << gpa << endl;
    }

    inFile.close();
}