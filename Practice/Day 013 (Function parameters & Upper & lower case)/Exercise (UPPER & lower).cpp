#include <iostream>
#include <cctype>
#include <limits>
#include <string>
using namespace std;

string toTitle(const string &str) {
    string result = str;
    bool newWord = true;

    for (size_t i = 0; i < result.length(); i++) {
        if (isspace(result[i])) {
            newWord = true;
        } else if (newWord) {
            result[i] = toupper(result[i]);
            newWord = false;
        } else {
            result[i] = tolower(result[i]);
        }
    }
    return result;
}

string toLower(const string &str) {
    string result = str;
    for (size_t i = 0; i < result.length(); i++) {
        result[i] = tolower(result[i]);
    }

    return result;
}

int main() {
    string input;
    cout << "Enter something: ";
    getline (cin, input);
    cout << "Uppercase: " << toTitle(input) << endl;
    cout << "Lowercase: " << toLower(input) << endl;

    return 0;
}