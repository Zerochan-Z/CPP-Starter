## ✅ C++ Cheat Sheet – All in One Table

| Code / Syntax | Brief Description (≤7 words) |
|---------------|------------------------------|
| `#include <iostream>` | Get input/output tools |
| `#include <string>` | Get string handling tools |
| `#include <cctype>` | Get character check tools |
| `#include <limits>` | Get input buffer tools |
| `int main() { }` | Program starts and ends here |
| `std::string name;` | Store text in variable `str` |
| `std::cout << "text";` | Print text to console |
| `std::cin >> var;` | Read user input into variable |
| `int count = 0;` | Initialize integer counter |
| `bool flag = true;` | Set boolean flag to true |
| `size_t i = 0;` | Non‑negative large index; int allows ± |
| `i < str.length();` | Loop condition (`.length()` like `len()`) |
| `i++;` | Increase variable by one |
| `char c;` | Holds one character |
| `if (cond) { }` | Execute block if true |
| `else if (cond) { }` | Check alternative condition |
| `else { }` | Execute when no condition true |
| `if (!isdigit(c)) { }` | True if `c` is NOT a digit |
| `std::stoi(str)` | Convert string to integer |
| `std::stof(str)` | Convert string to float |
| `std::to_string(num)` | Convert number to string |
| `std::cin.fail()` | Check if input failed |
| `std::cin.clear()` | Clear input error flag |
| `std::cin.ignore(10000, '\n')` | Discard bad input from buffer |
| `return 0;` | Exit program successfully |
| `// comment` | Single‑line comment |
| `/* comment */` | Multi‑line comment |

---

## 🧠 Quick Reference – One‑Liner

```cpp
#include <iostream>   // cout, cin
#include <string>     // string
#include <cctype>     // isdigit()
#include <limits>     // numeric_limits

int main() {
    std::string s;                     // text variable
    std::cout << "Enter: ";            // print
    std::cin >> s;                     // read input

    if (std::cin.fail()) {             // check error
        std::cin.clear();              // clear flag
        std::cin.ignore(10000, '\n');  // discard bad input
    }

    for (size_t i = 0; i < s.length(); ++i) { // loop
        char c = s[i];                 // each character
        if (!isdigit(c)) { /* not digit */ }
    }

    int x = std::stoi(s);              // string to int
    float f = std::stof(s);            // string to float
    std::string numStr = std::to_string(x); // int to string

    if (x > 0) {
        // positive
    } else if (x < 0) {
        // negative
    } else {
        // zero
    }

    return 0;  // success
}
```

> Copy this page – it’s your complete C++ starter cheat sheet.
