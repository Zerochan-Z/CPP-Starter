#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector <int> num;
    int input;

    cout << "Enter 10 integers: " << "\n";
    for (int i=0; i<10; i++) {
        cin >> input;
        num.push_back(input);
    }

    cout << "You entered: " << "";
    for (int i = 0; i < num.size();i++) {
        cout << num[i] << " ";
    }
    
    int max = num[0];
    int min = num[0];
    int sum = num[0];

    for (int i = 1; i < num.size();i++) {
        if (num[i] > max) {
            max = num[i];
        }
        if (num[i] < min) {
            min = num[i];
        }
        sum = sum + num[i];
    }

    double avg = double(sum) / num.size();

    cout << "\nMax: " << max << "\n";
    cout << "Min: " << min << "\n";
    cout << "Average: " << avg << "\n";

    return 0;
}