#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream outfile;
    outfile.open("students.txt");

    outfile << "Alice " << 19 << " " << 3.2 << endl;
    outfile << "Sam " << 20 << " " << 2.9 << endl;

    outfile.close();

    ifstream infile;
    infile.open("students.txt");

    while (!infile) {
        cout << "error" << endl;
        return 1;
    }

    string name;
    int age;
    double gpa;

    while (infile >> name >> age >> gpa) {
        cout << "Name: " << name << " Age: " << age << " GPA: " << gpa << endl;
    }

    infile.close();
    return 0;
}