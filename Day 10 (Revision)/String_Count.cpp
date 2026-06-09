#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int vowels(string &sentence) {
    int vow = 0;
    for (int i = 0; i < sentence.length(); i++) {
        char ch = tolower(sentence[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            vow++;
        }
    }
    return vow;
}

int consonants (string &sentence) {
    int cons = 0;
    for (int i = 0; i < sentence.length(); i++) {
        char ch = tolower(sentence[i]);
        if (isalpha(ch)) {
            if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u') {
                cons++;
            }
        } 
    }
    return cons;
}

int main() {
    string sentence;

    cout << "Enter the sentence: ";
    getline(cin, sentence);

    cout << "\nNumber of vowel/S: " << vowels(sentence) << endl;
    cout << "Number of consonant/S: " << consonants(sentence) << endl;

    return 0;
}