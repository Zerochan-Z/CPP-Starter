#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

class Person {
private:
    string name;
    int age;
public:
    Person(): name(""), age(0) {}
    Person(string n, int a): name(n), age(a) {}

    string getName() { return name; }
    int getAge() { return age; }
    
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    
    void display() {
        cout << "Name: " << getName() << endl;
        cout << "Age: " << getAge() << endl;
    }
};

class Student: public Person {
private:
    int studentID;
    string course;

public: 
    Student(): Person("", 0), studentID(260000), course("") {}
    Student(string n, int a, int id, string c): Person(n,a), studentID(id), course(c) {}

    int getID() { return studentID; }
    string getCourse() { return course; }

    void setID(int id) { studentID = id; }
    void setCourse(string c) { course = c; }

    void displayStudent() {
        cout << "\n ---- Student Details ---- \n";
        display();
        cout << "Student ID: " << getID() << endl;
        cout << "Course: " << getCourse() << endl;
    }
};

class Lecturer: public Person {
private:
    int staffID;
    string department;

public:
    Lecturer(): Person("", 0), staffID(980000), department("") {}
    Lecturer(string n, int a, int id, string dep): Person(n, a), staffID(id), department(dep) {}

    int getID() { return staffID; }
    string getDep() { return department; }

    void setID(int id) { staffID = id; }
    void setDep(string dep) { department = dep; }

    void displayStaff() {
        cout << "\n ---- Lecturer Details ---- \n";
        display();
        cout << "Staff ID: " << getID() << endl;
        cout << "Department: " << getDep() << endl;
    }
};

int main() {
    Student s1("Mew mew", 3, 260001, "Business");
    Student s2("Ngiao", 6, 240423, "vet");
    
    s1.displayStudent();
    s2.displayStudent();

    Lecturer l1("Cutie", 40, 190312, "Green Technology");
    Lecturer l2("Old man", 83, 740284, "Chinese Architecture");
    l1.displayStaff();
    l2.displayStaff();

    return 0;
}