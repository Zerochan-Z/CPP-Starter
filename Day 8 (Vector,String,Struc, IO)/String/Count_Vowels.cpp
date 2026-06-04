#include <iostream>
#include <string>
using namespace std;

int main() {
    string sentence;
    int vowelCount = 0;

    cout << "Enter a sentence: ";
    getline(cin,sentence); // put whole line (including space) to sentence

    for (int i=0; i < sentence.length(); i++) {
        char ch = tolower(sentence[i]); // tolower() = .lower() Change to lowercase letter
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            vowelCount++;
        }
    }

    cout << "Number of vowels: " << vowelCount << endl;

    return 0;
}