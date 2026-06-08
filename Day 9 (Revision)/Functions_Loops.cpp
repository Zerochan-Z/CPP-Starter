#include <iostream>
#include <iomanip>
using namespace std;

double Average(int input[]) {
    int sum = 0;
    for (int i = 0; i < 3;i++) {
        sum = sum+ input[i];
    }
    return sum/3.0;
}

int main() {
    int input[3];

    cout << "Enter 3 test scores: ";
    
    for (int i=0; i<3;i++) {
        cin >> input[i];
    }
    
    for (int i=0; i < 3; i++) {
        cout << "Data " << i+1 << ": " << input[i] << "\n";
    }
    cout << fixed << setprecision(2);
    cout << "Average: " << Average(input) << "\n";
    return 0;
}