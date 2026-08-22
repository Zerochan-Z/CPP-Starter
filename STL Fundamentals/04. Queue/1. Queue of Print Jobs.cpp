#include <iostream>
#include <string>
#include <vector>
#include <queue>

int main() {
    std::queue<std::string> printQueue;

    printQueue.push("Report.pdf");
    printQueue.push("Invoice.docs");
    printQueue.push("Photo.jpg");

    while (!printQueue.empty()) {
        std::cout << "Printing: " << printQueue.front() << std::endl;
        printQueue.pop();
    }

    return 0;
}