#include <iostream>
#include <string>
using namespace std;

int main() {
    string sentence;
    int wordCount = 1;

    cout << "Enter a sentence: ";
    getline(cin,sentence);

    for (int i = 0; i< sentence.length(); i++) {
        if (sentence[i] == ' ') {
            wordCount ++;
        }
    }
    
    cout << "Number of words: " << wordCount << endl;

    return 0;
}