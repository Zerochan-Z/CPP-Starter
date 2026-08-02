#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
using namespace std;

double average(vector <int> &integers) {
    double sum = 0;
    for (int i = 0; i < integers.size(); i++) {
        sum = sum + integers[i];
    }
    if (integers.empty()) return 0.0;

    return sum/ integers.size();
}
int main() {
    vector <int> integers = {}; // vector <int> integers; -> both building dic
    string input;

    cout << "Enter the integers (put space for seperate numbers): ";
    getline(cin,input);
    
    stringstream ss(input);
    double number;
    while (ss >> number) { // extract ss to number -> (true) until none (false)
        integers.push_back(number);
    }


    cout << fixed << setprecision(2);
    cout << "Average: " << average(integers) << endl;

    return 0;
}