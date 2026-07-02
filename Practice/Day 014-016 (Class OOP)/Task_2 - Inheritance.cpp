#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(): name(""), age(0) {}
    Person(string n, int a): name(n), age(a) {}

    string getName() { return name; }
    int getAge() { return age; }
    
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    
    virtual void display() {
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

    void display() override {
        cout << "\n ---- Student Details ---- \n";
        display();
        cout << "Student ID: " << studentID << endl;
        cout << "Course: " << course << endl;
    }
};

class Lecturer: public Person {
private:
    int staffID;
    string department;

public:
    Lecturer(): Person("", 0), staffID(980000), department("") {}
    Lecturer(string n, int a, int id, string dep): Person(n, a), staffID(id), department(dep) {}

    void display() override{
        cout << "\n ---- Lecturer Details ---- \n";
        Person::display();
        cout << "Staff ID: " << staffID << endl;
        cout << "Department: " << department << endl;
    }
};

int main() {
    Student s1("Mew mew", 3, 260001, "Business");
    Student s2("Ngiao", 6, 240423, "vet");
    
    s1.display();
    s2.display();

    Lecturer l1("Cutie", 40, 190312, "Green Technology");
    Lecturer l2("Old man", 83, 740284, "Chinese Architecture");
    l1.display();
    l2.display();

    return 0;
}