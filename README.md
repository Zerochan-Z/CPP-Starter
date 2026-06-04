## ✅ Updated C++ Complete Cheat Sheet – Added Today's New Topics

---

## 📁 Part 1: Includes & Setup

| Code | Description |
|------|-------------|
| `#include <iostream>` | Get input/output tools (cout, cin) |
| `#include <iomanip>` | Get formatting tools (setprecision, fixed) |
| `#include <string>` | Get string handling tools |
| `#include <cctype>` | Get character check tools (isdigit) |
| `#include <limits>` | Get input buffer tools (ignore) |
| `#include <cstdlib>` | Get random number tools (rand) |
| `#include <ctime>` | Get time tools (srand, time) |
| `using namespace std;` | Write `cout` instead of `std::cout` |

---

## 🔧 Part 2: Variables & Data Types

| Code | Description |
|------|-------------|
| `int x = 5;` | Integer (whole number) |
| `double y = 3.14;` | Double (decimal number) |
| `char c = 'A';` | Character (single letter) |
| `bool flag = true;` | Boolean (true/false) |
| `string name = "Alice";` | String (text) |
| `int arr[5] = {1,2,3,4,5};` | Fixed-size array |
| `size_t i = 0;` | Non-negative large index; int allows ± |
| `int count = 0;` | Initialize integer counter |
| `int a, b;` | Declare multiple variables |

---

## 📥 Part 3: Input & Output

| Code | Description |
|------|-------------|
| `cout << "text";` | Print text to console |
| `cout << x;` | Print variable value |
| `cout << a << b;` | Print multiple items |
| `cout << endl;` | Print newline and flush |
| `cin >> x;` | Read user input into variable |
| `cin >> a >> b;` | Read multiple inputs |
| `cin.fail()` | Check if input failed |
| `cin.clear()` | Clear input error flag |
| `cin.ignore(10000, '\n')` | Discard bad input from buffer |

---

## 🎨 Part 4: Formatting Output

| Code | Description |
|------|-------------|
| `fixed` | Set as decimal format (not scientific) |
| `setprecision(2)` | 2 decimal places |
| `setw(10)` | Set field width to 10 spaces |
| `left` / `right` | Left or right align output |

---

## 🔀 Part 5: Conditionals (If-Else)

| Code | Description |
|------|-------------|
| `if (condition) { }` | Execute block if true |
| `else if (condition) { }` | Check alternative condition |
| `else { }` | Execute when no condition true |
| `condition1 \|\| condition2` | OR (true if either true) |
| `condition1 && condition2` | AND (true if both true) |
| `!condition` | NOT (reverses true/false) |
| `if (!isdigit(c)) { }` | True if c is NOT a digit |

---

## 🔁 Part 6: Loops

| Code | Description |
|------|-------------|
| `for (int i = 0; i < n; i++) { }` | Loop with counter |
| `for (int i = n-1; i >= 0; i--) { }` | Loop backwards |
| `for (char c : str) { }` | Range-based for loop (C++11) |
| `while (condition) { }` | Check condition first, then run |
| `do { } while (condition);` | Run first, then check condition |
| `break;` | Exit loop immediately |
| `continue;` | Skip to next iteration |

**Loop operations:**
| Code | Description |
|------|-------------|
| `i++` | Increase by one |
| `i--` | Decrease by one |
| `i += 2` | Increase by two |
| `i < str.length()` | Loop condition |

---

## 📦 Part 7: Arrays & Strings

| Code | Description |
|------|-------------|
| `arr[index]` | Access element at position |
| `arr[0] = 5;` | Assign value to array element |
| `sizeof(arr)/sizeof(arr[0])` | Get array length |
| `str.length()` | Get string length |
| `str[i]` | Access character in string |
| `str.substr(pos, len)` | Extract substring |

---

## ⚙️ Part 8: Functions

| Code | Description |
|------|-------------|
| `void name() { }` | Function returns nothing (no return needed) |
| `int name() { return x; }` | Function returns integer |
| `string name() { return str; }` | Function returns string |
| `bool name() { return true/false; }` | Function returns boolean |
| `double name() { return x; }` | Function returns double |
| `char name() { return c; }` | Function returns character |
| `void name(int& a) { }` | Pass by reference (`&` modifies original) |
| `int name(int arr[], int size)` | Function with array parameter |

**Function Types Summary:**

| Return Type | Return Needed | Call in `main()` |
|-------------|---------------|------------------|
| `void` | ❌ No | `name(data);` |
| `int` | ✅ Yes | `cout << name(data);` |
| `string` | ✅ Yes | `cout << name(data);` |
| `bool` | ✅ Yes | `cout << name(data);` |
| `double` | ✅ Yes | `cout << name(data);` |
| `char` | ✅ Yes | `cout << name(data);` |

---

## 🎲 Part 9: Random Numbers

| Code | Description |
|------|-------------|
| `#include <cstdlib>` | Required for `rand()` |
| `#include <ctime>` | Required for `time()` |
| `srand(time(0));` | Seed random number generator (once at start) |
| `rand()` | Generate random number |
| `rand() % max + min` | Random number between min and max |

**Example:**
| Code | Description |
|------|-------------|
| `rand() % 100 + 1` | Random number between 1 and 100 |
| `rand() % 50` | Random number between 0 and 49 |

---

## 🔄 Part 10: Type Conversions

| Code | Description |
|------|-------------|
| `stoi(str)` | Convert string to integer |
| `stof(str)` | Convert string to float |
| `stod(str)` | Convert string to double |
| `to_string(num)` | Convert number to string |
| `(int)doubleValue` | C-style cast (double to int) |
| `static_cast<int>(doubleValue)` | C++ style cast |

---

## 📝 Part 11: Comments

| Code | Description |
|------|-------------|
| `// single line comment` | Comment until end of line |
| `/* multi-line comment */` | Comment across multiple lines |

---

## 📊 C++ vs Python Summary Table

| Concept | C++ | Python |
|---------|-----|--------|
| **Print text** | `cout << "text";` | `print("text")` |
| **Print variable** | `cout << price;` | `print(price)` |
| **Print formatted** | `cout << fixed << setprecision(2) << price` | `print(f"{price:.2f}")` |
| **Read input** | `cin >> x;` | `x = input()` |
| **Read integer** | `int x; cin >> x;` | `x = int(input())` |
| **String variable** | `string name = "Alice";` | `name = "Alice"` |
| **Fixed array** | `int arr[3] = {1,2,3};` | `arr = [1,2,3]` |
| **Array access** | `arr[0]` | `arr[0]` |
| **If statement** | `if (x > 0) { }` | `if x > 0:` |
| **Else if** | `else if (x < 0) { }` | `elif x < 0:` |
| **Else** | `else { }` | `else:` |
| **For loop range** | `for (int i = 0; i < n; i++)` | `for i in range(n):` |
| **For-each loop** | `for (char c : str)` | `for c in str:` |
| **While loop** | `while (condition) { }` | `while condition:` |
| **Do-while** | `do { } while (condition);` | ❌ No equivalent |
| **Function (no return)** | `void name() { }` | `def name():` |
| **Function (return)** | `int name() { return x; }` | `def name(): return x` |
| **Pass by reference** | `void func(int& x) { }` | ❌ Not directly |
| **Array in function** | `void func(int arr[], int size)` | `def func(arr):` |
| **Random number** | `rand() % 100 + 1` | `random.randint(1, 100)` |
| **Single comment** | `// comment` | `# comment` |
| **Multi comment** | `/* comment */` | `""" comment """` |
| **Import library** | `#include <library>` | `import library` |
| **Main function** | `int main() { return 0; }` | `if __name__ == "__main__":` |
| **Curly braces** | Required `{ }` | Not used |
| **Semicolons** | Required `;` | Not required |
| **Indentation** | Optional (recommended) | **Required** |
| **Data types** | Must declare (`int x`) | Dynamic (`x = 5`) |
| **Boolean values** | `true` / `false` | `True` / `False` |

---

## ✅ One Sentence Summary

**C++ requires `#include` statements, semicolons `;`, curly braces `{}`, explicit data types, and function return types (`void`, `int`, `string`, `bool`, `double`, `char`); Python uses indentation and dynamic typing – today we added random numbers (`rand()`, `srand(time(0))`) and function return type rules.** 💪
