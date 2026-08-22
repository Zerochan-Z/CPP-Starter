#include <iostream>
#include <stack>
#include <string>
#include <vector>

bool isBalanced(const std::string &s) {
    if (s.empty()) return false;
    std::stack<char> paren;

    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] == '(' ) {
            paren.push('(');
        } else if (s[i] == '[') {
            paren.push('[');
        } else if (s[i] == '{') {
            paren.push('{');
        } else if (s[i] == ')' && paren.top() == '(') {
            paren.pop();
        } else if (s[i] == ']' && paren.top() == '[') {
            paren.pop();
        } else if (s[i] == '}' && paren.top() == '{') {
            paren.pop();
        } else {
            return false;
        }
    }

    return paren.empty();
}

int main() {
    std::vector <std::string> List = {"()", "([)]", "{[]}", "(", ""}; 

    for (size_t i = 0; i < List.size(); i++) {
        //                  condition ? value_if_true : value_if_false
        std::cout << "Result: " << (isBalanced(List[i]) ? "true" : "false") << std::endl;
    }

    return 0;
}