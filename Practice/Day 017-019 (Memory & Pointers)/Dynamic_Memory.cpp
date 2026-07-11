#include <iostream>
using namespace std;

int main() {
    int* arr = new int[3];
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    cout << arr[3] << endl;
    
    delete[] arr;
    return 0;
}