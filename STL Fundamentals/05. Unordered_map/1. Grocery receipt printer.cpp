#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::unordered_map<std::string, double> prices;

    prices["Apple"] = 2.50;
    prices["Banana"] = 1.20;
    prices["Orange"] = 3.00;

    prices["Banana"] = 1.50; // (Modified)

    // unordered_map_name["Name"] = values (like dict in python)
    std::cout << "Price of apple: " << prices["Apple"] << std::endl;
    std::cout << "Price of banana: " << prices["Banana"] << std::endl;
    
    // For loop:
    std::cout << std::endl;
    // pair = temp variable stores element (.first -> first element)
    for (std::pair<const std::string, double> p : prices) {
        std::cout << "Item: " << p.first << ", Price: " << p.second << std::endl;
    }
    
    // Shorter version (for loop)
    std::cout << std::endl;
    // auto: tells compiler
    // Figure out what type p should be based on what you're iterating over.
    for (auto p : prices) {
        std::cout << "Item: " << p.first << ", Price: " << p.second << std::endl;
    }

    return 0;
}