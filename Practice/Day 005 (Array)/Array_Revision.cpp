///
///
#include <iostream>
using namespace std;

int main() {
    int arr[5];
    int sum = 0;
    int maxValue = arr[0];

    cout << "Enter 5 numbers: ";
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    for (int i =0 ; i< 5; i++){
        sum = sum + arr[i];
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }

    cout << "Values: ";
    for (int i = 0;i < 5; i++) {
        cout << arr[i] << ' ';
    }
    
    cout << "\nSum: " << sum << "\n";
    cout << "\nMaximum value: " << maxValue << endl;

    return 0;
}