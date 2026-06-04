#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void EvenOdd (int arr[], int size) {
    string result = "";
    for (int i = 0; i < size;i++) {
        if (arr[i] %2 == 0) {
            cout << "even " << "";
        } else {
            cout << "odd " << "";
        }
    }
}

int SumFirstN (int target) {
    int sum = 0;
    for (int i= 1; i <= target;i++) {
        sum = i + sum;
    }
    return sum;
}

int MaxArray (int arr[], int size) {
    int max = arr[0];
    for (int i= 1;i<size;i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int Occurrences (int arr[],int size, int target) {
    int count = 0;
    for (int i= 0;i< size;i++) {
        if (arr[i] == target) {
            count ++;
        }
    }
    return count;
}

int ReverseArray (int arr[],int size) {
    int rev = 0;
    for (int i = 0; i<size/2;i++){
        rev = arr[i];
        arr[i] = arr[size-1-i];
        arr[size-1-i] = rev; 
    }
    return rev;
}

int Multiplication (int target) {
    int mul = 0;
    for (int i = 1; i<= 10;i++) {
        mul = target * i;
        cout << target << " x " << i << " = " << mul << "\n";
    }
}

int ArraySum (int arr[], int size) {
    int sum = 0;
    for (int i=0;i<size; i++) {
        sum = arr[i] + sum;
    }
    return sum;
}

bool GuessNum (int test, int guess ) {
    if (test < guess) {
        cout << "Too low!" << "\n";
        return false;
    } else if (test > guess) {
        cout << "Too high! " << "\n";
        return false;
    } else {
        cout << "Congratulations! Correct !!!" << "\n";
        return true;
    }
} 

int main() {
    int arr[] = {3,2,5,8,10,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout << "The type of number are: " << "";
    EvenOdd(arr,size);
    cout << endl;
    cout << "The maximum in array is " << MaxArray(arr,size) << "\n";
    cout << "Reverse array: " << ReverseArray(arr,size);
    cout << "Array Sum: " << ArraySum << endl;

    int target = 0;
    cout << "\nEnter the N to calculate to sum of first N numbers: " << "";
    cin >> target;
    cout << "\nWhich target you're aiming to count its occurrences? " << "";
    cin >> target;
    cout << "The occurrences of target value is " << Occurrences(arr,target) << "\n";
    cout << "The sum of first N numbers: " << SumFirstN(target) << "\n";
    cout << "Enter the number to print multiplication table (1 to 10)" << "\n";
    cin >> target;
    cout << Multiplication;

    cout << "\n" << "";
    cout << "Guess a number between 1 - 30" << "\n";
    int test = 0;
    srand(time(0));
    int guess = rand() % 30 +1;
    bool isTrue = false;

    while (!isTrue) {
        cout << "Enter your guess: " << " ";
        cin >> test;

        isTrue = GuessNum(test,guess);
    }

    return 0;
}
