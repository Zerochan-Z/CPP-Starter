#include <iostream>
using namespace std;

int main() {
    int a = 7;
    int* p1 = &a; // stores value from (&) address a to (*) put in p1
    int** p2 = &p1;
    cout << **p2;

    return 0;
}