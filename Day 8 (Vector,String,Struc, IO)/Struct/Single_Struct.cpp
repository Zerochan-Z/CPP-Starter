#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int age;
    float marks;
};

int main() {
    Student s1;

    cout << "Enter student name: ";
    getline(cin,s1.name);

    cout << "Enter age: ";
    cin >> s1.age;

    cout << "Enter marks: ";
    cin >> s1.marks;

    cout << "\n--- Student Record ---\n";
    cout << "Name: " << s1.name << endl;
    cout << "Age: " << s1.age << endl;
    cout << "Marks: " << s1.marks << endl;

    return 0;
}