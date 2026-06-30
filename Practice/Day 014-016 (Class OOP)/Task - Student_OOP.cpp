#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int id;
    double gpa;

public:
    Student(string n, int i, double g) {
        name = n;
        id = i;
        gpa = g;
    }

    double setGPA () {
        double g;
        cout << "Changing Sam GPA to cheat.\n";
        cout << "Enter new GPA: ";
        cin >> g;
        gpa = g;
        return gpa;
    }

    void display() {
        cout << name << " (" << id << ") - " << gpa << endl;
    }

    void getGPA() {
        cout << name << " (" << id << ") - " << gpa << endl;
    }
};

int main() {
    Student s1("Tee" , 20, 2.5);
    Student s2("Sam", 23, 2.3);
    s1.display();
    s2.display();
    s2.setGPA();
    s2.getGPA();

    return 0;
}