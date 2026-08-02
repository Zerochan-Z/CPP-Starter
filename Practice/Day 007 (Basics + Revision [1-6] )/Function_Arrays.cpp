/*
Functions & Arrays
Task 2.1: Find maximum in array
Task 2.2: Reverse Array
Task 2.3: Count Occurrences
Task 2.4: Array Sum with Function
*/

#include <iostream>
using namespace std;

int findMax(int arr[], int size) {
    int value = arr[0];
    for (int i = 1; i < size; i++){
        if (arr[i] > value) {
            value = arr[i];
        }
    }
    return value;
}

void reverseArray(int arr[],int size) {
    for (int i= 0; i < size / 2; i++) {
        int rev = arr[i];
        arr[i] = arr[size - 1-i];
        arr[size-1+i] = rev;
    }
}

int countOccurrences(int arr[], int size,int target) {
    int count = 0;
    for (int i = 0; i < size;i++) {
        if (target == arr[i]) {
            count ++;
        }
    }
    return count;
}

int sumArray(int arr[], int size) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        result = arr[i] + result;
    }
    return result;
}

int main() {
    int arr[] = {2,5,2,8,2,3,9,4};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "The maximum value of data is " << findMax(arr, size) << ".\n";
    cout << "Reverse Array: ";
    reverseArray(arr,size);
    for (int i = 0;i <size;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "The target number of occurrences is " << countOccurrences(arr, 6,2) << ".\n";
    cout << "Sum of array: " << sumArray(arr,size) << endl;

    return 0;
}