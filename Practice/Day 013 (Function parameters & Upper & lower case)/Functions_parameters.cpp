#include <iostream>
#include <string>
using namespace std;

void greet(string name) {
    cout << "Hello, " << name << endl;
}

int add(int a, int b) {
    int result = 0;
    result = a + b;

    return result;
}

int main() {
    string name;
    int a;
    int b;
    cout << "Enter the person's name: ";
    getline(cin ,name);
    greet(name);

    cout << "Enter integer of a: ";
    cin >> a;
    cout << "Enter integer of b: ";
    cin >> b;
    cout << "Total: " << add(a, b) << endl;

    return 0;
}