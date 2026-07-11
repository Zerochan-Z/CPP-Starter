#include <iostream>
using namespace std;

void swap (int* a, int* b) {
    int temp = *a; // temp stores address of a
    *a = *b;
    *b =  temp; // goes to temp (a) adddress, gets value
}

// address is not equal to data in memory ( & x *)
// * gets value through address

int main() {
    int x = 3, y = 7;
    cout << &x << " " << &y << endl; // & address the data in memory
    swap (&x, &y); // & - address of data in memory
    cout << x << " " << y;
    return 0;
}