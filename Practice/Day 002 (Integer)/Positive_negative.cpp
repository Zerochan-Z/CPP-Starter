#include <iostream>
#include <string>
#include <cctype>

int main() {
    float x;
    std::string input;

    while (true) {
        std::cout << "Enter a number: ";
        std::cin >> input;

        bool isValid = true;
        int dotCount = 0;

        for (size_t i = 0; i < input.length(); i++){
            char c = input[i];
            if (i == 0 && c =='-') {
                continue;
            }
            if (c == '.') {
                dotCount++;
                if (dotCount > 1) {
                    isValid = false;
                    break;
                }
                continue;
            }
            if (!isdigit(c)) {
                isValid = false;
                break;
            }
        }

        if (!isValid) {
            std::cout << "Invalid input. Please enter a valid number.\n";
            continue;
        }
        
        x = std::stof(input);
        break;
    }
    
    if (x > 0) {
        std::cout << "The number is positive.\n";
    } else if (x < 0) {
        std::cout << "The number is negative.\n";
    } else {
        std::cout << "The number is zero.\n";
    }

    return 0;
}