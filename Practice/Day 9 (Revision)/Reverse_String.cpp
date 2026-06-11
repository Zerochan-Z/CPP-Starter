#include <iostream>
#include <string>
using namespace std;

string ReverseArray (string text) {
    string rev = "";
    int size = text.length();

    for (int i = size -1 ; i >=0 ; i--) {
        rev = rev + text[i];
    }
    return rev;
}

int main() {
    string reversed = {};

    cout << "Enter the sentence: ";
    getline(cin, reversed);

    cout << "Reversed: " << ReverseArray(reversed) << endl;
    
    return 0;
}

