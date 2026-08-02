#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers;
    int input;

    cout << "Enter 10 integers: \n";
    for (int i = 0;i <10; i++) {
        cin >> input;
        numbers.push_back(input);
    }

    int maxVal = numbers[0];
    int minVal = numbers[0];
    int sum = 0;

    for (int i = 0;i < numbers.size();i++) {
        if (numbers[i]> maxVal) {
            maxVal = numbers[i];
        }
        if (numbers[i] < minVal) {
            minVal = numbers[i];
        }
        sum = sum+numbers[i];
    }

    double avg = (double)sum / numbers.size();

    cout << "Max: " << maxVal << endl;
    cout << "Min: " << minVal << endl;
    cout << "Average: " << avg << endl;

    return 0;
}