#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string input;
    vector <char> chars;

    cout << "Enter a word: ";
    getline(cin, input);
    
    for (int i = 0; i <input.length(); i++) {
        chars.push_back(input[i]);
    }

    int size = chars.size();
    for (int i = 0; i < size/2; i++) {
        char temp = chars[i];
        chars[i] = chars[size-1-i];
        chars[size - 1 -i] = temp;
    }
    
    cout << "Reversed: ";
    for (int i = 0; i <size; i++) {
        cout << chars[i];
    }

    cout << endl;

    return 0;
}