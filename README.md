
---

## ✅ C++ Complete Cheat Sheet

---

## 📁 Part 1: Includes & Setup

| Code | Description |
|:---|:---|
| `#include <iostream>` | Input/output tools (`cout`, `cin`) |
| `#include <iomanip>` | Formatting tools (`setprecision`, `fixed`, `setw`) |
| `#include <sstream>` | String stream tools (`stringstream`) |
| `#include <string>` | String handling tools |
| `#include <vector>` | Dynamic array tools (`vector`) |
| `#include <cctype>` | Character check tools (`isdigit`) |
| `#include <limits>` | Input buffer tools (`ignore`) |
| `#include <cstdlib>` | Random number tools (`rand`) |
| `#include <ctime>` | Time tools (`srand`, `time`) |
| `using namespace std;` | Write `cout` instead of `std::cout` |

---

## 🔧 Part 2: Variables & Data Types

| Code | Description |
|:---|:---|
| `int x = 5;` | Integer (whole number) |
| `double y = 3.14;` | Double (decimal number) |
| `char c = 'A';` | Character (single letter) |
| `bool flag = true;` | Boolean (`true`/`false`) |
| `string name = "Alice";` | String (text) |
| `vector<int> v;` | Dynamic array (vector) of integers |
| `vector<string> names;` | Vector of strings |
| `int arr[5] = {1,2,3,4,5};` | Fixed-size array |
| `size_t i = 0;` | Non-negative large index |
| `int count = 0;` | Initialize integer counter |
| `int a, b;` | Declare multiple variables |

---

## 📥 Part 3: Input & Output

| Code | Description |
|:---|:---|
| `cout << "text";` | Print text to console |
| `cout << x;` | Print variable value |
| `cout << a << b;` | Print multiple items |
| `cout << endl;` | Print newline and flush |
| `cin >> x;` | Read user input into variable |
| `cin >> a >> b;` | Read multiple inputs |
| `getline(cin, str);` | Read an entire line (including spaces) |
| `cin.fail()` | Check if input failed |
| `cin.clear()` | Clear input error flag |
| `cin.ignore(10000, '\n')` | Discard bad input from buffer |

---

## 🎨 Part 4: Formatting Output

| Code | Description |
|:---|:---|
| `fixed` | Set decimal format (not scientific) |
| `setprecision(2)` | Set to 2 decimal places |
| `cout << fixed << setprecision(2);` | Apply decimal formatting to all following output |
| `setw(10)` | Set field width to 10 spaces |
| `left` / `right` | Left or right align output |

---

## 🔀 Part 5: Conditionals (If-Else)

| Code | Description |
|:---|:---|
| `if (condition) { }` | Execute block if true |
| `else if (condition) { }` | Check alternative condition |
| `else { }` | Execute when no condition is true |
| `condition1 \|\| condition2` | OR (true if either is true) |
| `condition1 && condition2` | AND (true if both are true) |
| `!condition` | NOT (reverses true/false) |
| `if (!isdigit(c)) { }` | True if c is NOT a digit |

---

## 🔁 Part 6: Loops

| Code | Description |
|:---|:---|
| `for (int i = 0; i < n; i++) { }` | Loop with counter |
| `for (int i = n-1; i >= 0; i--) { }` | Loop backwards |
| `for (char c : str) { }` | Range-based for loop (C++11) |
| `for (int i = 0; i < vec.size(); i++)` | Loop through all elements of a vector |
| `while (condition) { }` | Check condition first, then run |
| `do { } while (condition);` | Run first, then check condition |
| `break;` | Exit loop immediately |
| `continue;` | Skip to next iteration |

---

### Loop Operations

| Code | Description |
|:---|:---|
| `i++` | Increase by one |
| `i--` | Decrease by one |
| `i += 2` | Increase by two |
| `i < str.length()` | Loop condition for string length |
| `i < vec.size()` | Loop condition for vector size |

---

## 📦 Part 7: Arrays, Vectors & Strings

### Fixed Arrays

| Code | Description |
|:---|:---|
| `int arr[5] = {1,2,3,4,5};` | Declare and initialize fixed array |
| `arr[index]` | Access element at position |
| `arr[0] = 5;` | Assign value to array element |
| `sizeof(arr)/sizeof(arr[0])` | Get array length |

### Vectors (Dynamic Arrays)

| Code | Description |
|:---|:---|
| `vector<int> v;` | Declare an empty integer vector |
| `vector<int> v = {1,2,3};` | Declare and initialize vector |
| `v.push_back(x);` | Add element to the end |
| `v.size()` | Get number of elements |
| `v.empty()` | Check if vector is empty (returns `true`/`false`) |
| `v[i]` | Access element at position `i` |
| `v.at(i)` | Access element safely (throws error if out of bounds) |

### Strings

| Code | Description |
|:---|:---|
| `str.length()` | Get string length |
| `str[i]` | Access character in string |
| `str.substr(pos, len)` | Extract substring |
| `str.empty()` | Check if string is empty |

---

## 🧩 Part 7B: String Parsing with `stringstream`

| Code | Description |
|:---|:---|
| `#include <sstream>` | Required header for `stringstream` |
| `stringstream ss(input);` | Create a stream from a string |
| `while (ss >> number) { }` | Extract integers/words one by one |

### String Parsing Pattern

| Step | Code |
|:---|:---|
| 1. Read entire line | `getline(cin, input);` |
| 2. Create stream | `stringstream ss(input);` |
| 3. Extract numbers | `while (ss >> num) { vec.push_back(num); }` |

---

## ⚙️ Part 8: Functions

| Code | Description |
|:---|:---|
| `void name() { }` | Function returns nothing |
| `int name() { return x; }` | Function returns integer |
| `double name() { return x; }` | Function returns double |
| `string name() { return str; }` | Function returns string |
| `bool name() { return true/false; }` | Function returns boolean |
| `char name() { return c; }` | Function returns character |
| `void name(int& a) { }` | Pass by reference (`&` modifies original) |
| `double name(vector<int>& v) { }` | Function takes vector by reference |
| `int name(int arr[], int size)` | Function with array parameter |

---

### Function Types Summary

| Return Type | Return Needed | Call in `main()` |
|:---|:---|:---|
| `void` | ❌ No | `name(data);` |
| `int` | ✅ Yes | `cout << name(data);` |
| `string` | ✅ Yes | `cout << name(data);` |
| `bool` | ✅ Yes | `cout << name(data);` |
| `double` | ✅ Yes | `cout << name(data);` |
| `char` | ✅ Yes | `cout << name(data);` |

---

### Guard Clause Pattern

| Pattern | Description | Example |
|:---|:---|:---|
| **Guard Clause** | Handle edge case first and `return` early. Then write normal logic below. | `if (vec.empty()) return 0.0;` |

---

## 🎲 Part 9: Random Numbers

| Code | Description |
|:---|:---|
| `#include <cstdlib>` | Required for `rand()` |
| `#include <ctime>` | Required for `time()` |
| `srand(time(0));` | Seed random number generator (once at start) |
| `rand()` | Generate random number |
| `rand() % max + min` | Random number between min and max |

### Random Number Examples

| Code | Description |
|:---|:---|
| `rand() % 100 + 1` | Random number between 1 and 100 |
| `rand() % 50` | Random number between 0 and 49 |

---

## 🔄 Part 10: Type Conversions

| Code | Description |
|:---|:---|
| `stoi(str)` | Convert string to integer |
| `stof(str)` | Convert string to float |
| `stod(str)` | Convert string to double |
| `to_string(num)` | Convert number to string |
| `(int)doubleValue` | C-style cast (double to int) |
| `static_cast<int>(doubleValue)` | C++ style cast |

---

## 📝 Part 11: Comments

| Code | Description |
|:---|:---|
| `// single line comment` | Comment until end of line |
| `/* multi-line comment */` | Comment across multiple lines |

---

## 📊 Part 12: C++ vs Python Summary

| Concept | C++ | Python |
|:---|:---|:---|
| **Print text** | `cout << "text";` | `print("text")` |
| **Print variable** | `cout << price;` | `print(price)` |
| **Print formatted** | `cout << fixed << setprecision(2) << price` | `print(f"{price:.2f}")` |
| **Read input** | `cin >> x;` | `x = input()` |
| **Read full line** | `getline(cin, str);` | `input()` |
| **Read integer** | `int x; cin >> x;` | `x = int(input())` |
| **Parse numbers from string** | `stringstream ss(str); while (ss >> n)` | `list(map(int, str.split()))` |
| **String variable** | `string name = "Alice";` | `name = "Alice"` |
| **Dynamic array** | `vector<int> v;` | `list = []` |
| **Add to dynamic array** | `v.push_back(x);` | `list.append(x)` |
| **Array size** | `v.size()` | `len(list)` |
| **Array empty check** | `v.empty()` | `not list` |
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
| **Guard clause** | `if (vec.empty()) return 0.0;` | `if not list: return 0.0` |
| **Random number** | `rand() % 100 + 1` | `random.randint(1, 100)` |
| **Format decimals** | `cout << fixed << setprecision(2) << x` | `print(f"{x:.2f}")` |
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

C++ requires `#include` statements, semicolons `;`, curly braces `{}`, explicit data types, and function return types; Python uses indentation and dynamic typing – **your cheat sheet now covers basics, strings, vectors, stringstream parsing, guard clauses, random numbers, and formatting.** 💪
