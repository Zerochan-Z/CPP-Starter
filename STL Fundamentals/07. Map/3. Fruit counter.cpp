#include <map>
#include <string>
#include <iostream>
#include <sstream>

int main() {
    std::map<std::string, int> fruits;
    std::string sentence = "apple banana apple";
    std::istringstream ins(sentence);
    std::string word;

    while (ins >> word) {
        fruits[word]++; 
    }

    for (const auto &m : fruits) {
        std::cout << m.first << " - " << m.second << std::endl;
    }
    return 0;
}