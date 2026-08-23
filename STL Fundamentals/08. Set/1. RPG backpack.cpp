#include <set>
#include <string>
#include <iostream>

int main() {
    std::set<std::string> items;
    items.insert("Sword");
    items.insert("Potion");
    items.insert("Shield");
    items.insert("Sword");

    for (const auto &p : items) {
        std::cout << p << std::endl; 
    }

    std::cout << items.count("Potion") << std::endl;

    return 0;
}