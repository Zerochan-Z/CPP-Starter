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
    ifstream inFile("students.txt");
    Student s;

    if (!inFile) {
        cout << "Error: cannot open file\n";
        return 1;
    }

    cout << "\n--- Students Records ---\n";
    while (inFile >> s.name >> s.age >> s.marks) {
        cout << "Name: " << s.name << endl;
        cout << "Age: " << s.age << endl;
        cout << "Marks: " << s.marks  << endl;
        cout << "-------------------------\n";
    }

    inFile.close();
    return 0;
}