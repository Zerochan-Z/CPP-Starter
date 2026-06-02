#include <iostream>
using namespace std;

int SumArray(int arr[], int size){
    int total = 0;
    for (int i = 0; i<size; i++){
        total = total + arr[i];
    }
    return total;
}

int MaxArray(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i<size; i++){
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int EvenNum (int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size;i++) {
        if (arr[i] %2 == 0) {
            count ++;
        }
    }
    return count;
}

void ReverseArray (int arr[], int size) {
    for (int i =0; i< size/2; i++) {
        int reverse = arr[i];
        arr[i] = arr[size -1 -i];
        arr[size -1 -i] = reverse;
    }
}

int main() {
    int arr[5] = {2,3,4,5,6};
    int size = 5;
    cout << "Data: " << arr[] << "\n";
    cout << "Sum: " << SumArray << "\n";
    cout << "Max: " << MaxArray << "\n";
    cout << "Even number count/s: " << EvenNum << "\n";
    cout << "Reverse array: " << ReverseArray << endl;

    return 0;

}