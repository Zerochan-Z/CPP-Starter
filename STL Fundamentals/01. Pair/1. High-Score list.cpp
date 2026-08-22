#include <iostream>
#include <string>
#include <vector>
#include <utility>

int main() {
    std::pair<std::string, int> entry;

    entry.first = "Alice";
    entry.second = 4500;

    std::vector <std::pair<std::string, int>> List;
    // 3 ways to add 
    List.push_back(entry);
    List.push_back({"Bob", 3200});
    List.push_back(std::make_pair("Charlie", 5100));
    List.push_back(std::pair<std::string, int>("Diana", 2800));

    for (std::pair<std::string, int> pairs: List) {
        std::cout << pairs.first << " - " << pairs.second << std::endl;
    }

    return 0;
}