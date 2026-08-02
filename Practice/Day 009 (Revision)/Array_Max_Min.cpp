#include <iostream>
using namespace std;

int Maximum (int arr[], int size) {
    int max = arr[0];
    for (int i = 0; i<size;i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}

int Minimum (int arr[], int size) {
    int min = arr[0];
    for (int i=0; i<size;i++) {
        if (min > arr[i]) {
            min = arr[i];
        }
    }
    return min;
}

int main() {
    int arr[5] = {12,45,7,89,23};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout << "Array: ";
    for (int i = 0 ; i < size ;i++) {
        cout << arr[i];

        if (i < size-1) {
            cout << ", ";
        }
    }
    cout <<  endl;

    cout << "Max: " << Maximum(arr,size) << endl;
    cout << "Min: " << Minimum(arr,size) << endl;

    return 0;

}