#include <iostream>

int main() {
    int x = 3;

    if (x > 0) {
        std::cout << "x is positive\n";
    }else if (x < 0) {
        std::cout << "x is negative\n";
    }else {
        std::cout << "x is zero\n";
    }

    return 0;
}