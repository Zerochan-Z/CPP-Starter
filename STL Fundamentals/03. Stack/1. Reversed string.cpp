#include <iostream>
#include <string>
#include <stack>

std::string ReversedStr(const std::string &s) {
    std::stack <char> stack;

    for (int i = 0; i < s.length();i++) {
        stack.push(s[i]);
    }

    std::string result;
    while (!stack.empty()) {
        result.push_back(stack.top());
        // result += stack.top();
        stack.pop();
    }

    return result;
}

int main() {
    std::string rev = ReversedStr("Hello");
    std::cout << rev << std::endl;

    return 0;
}