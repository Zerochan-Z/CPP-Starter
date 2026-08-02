/*
Basic Programs (cin/cout, if/else, for/while)
Task 1.1: Even or Odd
Task 1.2: Sum of First N numbers
Task 1.3: Multiplication Table
Task 1.4: Guess the number game
*/ 

#include <iostream>
#include <string> // string format
#include <cstdlib> // usage of rand()
#include <ctime> // usage of time() / srand(time()) - seed 
using namespace std;

string OddEven(int number) { 
    string result = "";
    if (number %2 ==0) {
        result = "even.";
    } else {
        result = "odd.";
    }

    return result;
}

int SumFirstN (int number) {
    int sum = 0;
    for (int i = 1; i <= number; i++){
        sum = sum + i;
    }
    return sum;
}

void Multiplication(int number) {
    for (int i = 1; i < 11; i++) {
        int mul = number * i;
        cout << number << " x " << i << " = " << mul << "\n";
    }
}

bool Guess(int test, int target) {
    
    if (test < target) {
        cout << "Too low! " << "\n";
        return false;
    } else if (test > target) {
        cout << "Too high! " << "\n";
        return false;
    } else {
        cout << "Correct! Congratulations!!! " << "\n";
        return true;
    }
}

int main() {
    int number = 0;
    int test = 0;
    cout << "Enter a number: " << "";
    cin >> number;
    cout << "The number is " << OddEven(number) << "\n";
    cout << "The sum of first N numbers is " << SumFirstN(number) << "\n";
    cout << "Printing multiplication table..." << "\n";
    cout << "\n --- Multiplication table ---\n" << "\n";
    Multiplication(number);

    cout << "\n" << "";
    cout << "Guess a number between 1 - 30" << "\n";
    srand(time(0));
    int target = rand() % 30 + 1; 
    bool isTrue = false;

    while (!isTrue) {
        cout << "Enter your guess: " << "";
        cin >> test;

        isTrue = Guess(test,target);
    }

    return 0;
}