#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_set>

int main() {
    std::string sentence = "hello world hello code";
    std::istringstream iss(sentence);
    std::string word;
    
    std::vector<std::string> order;          
    std::unordered_set<std::string> seen;    
    
    while (iss >> word) {
        if (seen.count(word) == 0) {
            // .count() check the pressence of the (word)
            // return 0 if none
            seen.insert(word);
            order.push_back(word);
        } 
    }
    
    std::cout << "In unordered_set: ";
    for (const auto &w : seen) {
        std::cout << w << " ";
    }
    std::cout << std::endl;
    
    // Still after filtered by unordered_set
    std::cout << "In ordered vector: ";
    for (const std::string &w : order) {
        std::cout << w << " ";
    }
    std::cout << std::endl;

    return 0;
}