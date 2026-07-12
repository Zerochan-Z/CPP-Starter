#include <iostream>
using namespace std;

int main() {
    int* arr = new int[3];
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    
    for (size_t i = 0; i < 3; i++) {
        cout << arr[i] << endl;
    }
    
    delete[] arr;
    return 0;
}