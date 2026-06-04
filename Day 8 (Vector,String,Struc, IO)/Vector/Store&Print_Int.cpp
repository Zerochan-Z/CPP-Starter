#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers;
    int input;

    cout << "Enter 10 integers: \n";
    for (int i=0; i<10;i++) {
        cin >> input;
        numbers.push_back(input);
    }

    cout << "You entered: ";
    for (int i = 0;i < numbers.size();i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}