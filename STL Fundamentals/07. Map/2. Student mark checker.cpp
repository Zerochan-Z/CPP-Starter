#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, int> student;
    student.insert({"Amy", 94});
    student.insert({"Bob", 57});
    student.insert({"Avo", 84});

    cout << "Enter the student name: ";
    string name;
    cin >> name;

    auto found = student.find(name);
    if (found != student.end()) {
        cout << found->second << endl;
    } else {
        cout << "Not found.\n";
    }

    return 0;
}