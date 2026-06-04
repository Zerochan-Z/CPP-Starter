#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void EvenOdd(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            cout << "even ";
        } else {
            cout << "odd ";
        }
    }
}

int SumFirstN(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum = sum + i;
    }
    return sum;
}

int MaxArray(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int Occurrences(int arr[], int size, int target) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            count++;
        }
    }
    return count;
}

void ReverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

void Multiplication(int target) {
    for (int i = 1; i <= 10; i++) {
        cout << target << " x " << i << " = " << target * i << "\n";
    }
}

int ArraySum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum = sum + arr[i];
    }
    return sum;
}

bool GuessNum(int test, int guess) {
    if (test < guess) {
        cout << "Too low!\n";
        return false;
    } else if (test > guess) {
        cout << "Too high!\n";
        return false;
    } else {
        cout << "Congratulations! Correct!!!\n";
        return true;
    }
}

int main() {
    int arr[] = {3, 2, 5, 8, 10, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "The type of numbers are: ";
    EvenOdd(arr, size);
    cout << endl;

    cout << "The maximum in array is " << MaxArray(arr, size) << endl;

    ReverseArray(arr, size);
    cout << "Reversed array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Array Sum: " << ArraySum(arr, size) << endl;

    int n;
    cout << "Enter N to calculate sum of first N numbers: ";
    cin >> n;
    cout << "Sum of first " << n << " numbers: " << SumFirstN(n) << endl;

    int targetOcc;
    cout << "Enter target value to count occurrences: ";
    cin >> targetOcc;
    cout << "Occurrences: " << Occurrences(arr, size, targetOcc) << endl;

    int mult;
    cout << "Enter number for multiplication table (1-10): ";
    cin >> mult;
    Multiplication(mult);

    cout << "\nGuess a number between 1-30\n";
    srand(time(0));
    int guess = rand() % 30 + 1;
    int test;
    bool isTrue = false;

    while (!isTrue) {
        cout << "Enter your guess: ";
        cin >> test;
        isTrue = GuessNum(test, guess);
    }

    return 0;
}