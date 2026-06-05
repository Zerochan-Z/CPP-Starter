#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int age;
    float marks;
};

int main() {
    Student students[5];
    int highestindex = 0;

    for (int i = 0;i <5;i++) {
        cout << "\n --- Student " << i+1 << "---\n";
        cout << "Enter name: ";
        getline(cin,students[i].name);

        cout << "Enter age: ";
        cin >> students[i].age;

        cout << "Enter marks: ";
        cin >> students[i].marks;

        cin.ignore();

        if (students[i].marks > students[highestindex].marks) {
            highestindex = i;
        }
    }

    cout << "\n --- Highest Marks ---\n";
    cout << "Name: " << students[highestindex].name << endl;
    cout << "Age: " << students[highestindex].age << endl;
    cout << "Marks: " << students[highestindex].marks << endl;

    return 0;
}