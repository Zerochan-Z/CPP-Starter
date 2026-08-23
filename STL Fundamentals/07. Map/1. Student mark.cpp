#include <map>
#include <string>
#include <iostream>

int main() {
    std::map<std::string, int> students;
    students.insert({"Charlie", 85});
    students.insert({"Alice", 92});
    students.insert({"Bob", 78});

    for (const auto &p : students) {
        std::cout << p.first << " - " << p.second << std::endl;
    }

    auto it = students.find("Amy");
    if (it != students.end()) {
        std::cout << it->second << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }
    
    std::cout << students.size();
    return 0;
}