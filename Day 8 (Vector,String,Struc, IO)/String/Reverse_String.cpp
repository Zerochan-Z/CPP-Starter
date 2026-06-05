#include <iostream>
#include <string>
using namespace std;

int main() {
    string text;
    string reversed = "";

    cout << "Enter a string: ";
    getline(cin,text);

    for (int i = text.length() -1; i >= 0;i--) {
        reversed = reversed +text[i];
    }

    cout << "Reversed: " << reversed << endl;

    return 0;
}