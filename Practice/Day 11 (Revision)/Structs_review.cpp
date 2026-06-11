#include <iostream>
#include <string>
using namespace std;

struct student {
    string name;
    int age;
    double gpa;
};

void info(student s) {
    cout << s.name;
    cout << s.age;
    cout << s.gpa;
}

int main() {
    student s1;

    cin >> s1.name;
    cin >> s1.age;
    cin >> s1.gpa;

    info(s1);

    return 0;
}