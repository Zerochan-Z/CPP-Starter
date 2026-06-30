#include <iostream>
#include <string>
using namespace std;

class Person {
private: 
    string name;
    int age;

public: 
    Person (string n, int a) { name = n; age = a; }
    // constructor

    void introduce() {
        cout << "Hi, I'm " << name << ". I'm " << age << " years old." << endl;
    }

    int celebrateBirthday() {
        age ++;
        cout << "Happy birthday! Now " << age << " years old !!!!" << endl;
    }
};

int main() {
    // Person p1 = object
    Person p1("Alice", 10); // constructor running according to assign data
    p1.introduce(); //call the method on object
    p1.celebrateBirthday();
    return 0;
}