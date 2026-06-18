
---

## ✅ C++ Complete Cheat Sheet

---

## 📁 Part 1: Includes & Setup

| Code | Description |
|:---|:---|
| `#include <iostream>` | Input/output tools (`cout`, `cin`) |
| `#include <iomanip>` | Formatting tools (`setprecision`, `fixed`, `setw`) |
| `#include <sstream>` | String stream tools (`stringstream`) |
| `#include <fstream>` | File stream tools (`ifstream`, `ofstream`) |
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

## 🏗️ Part 3: Structs (Custom Data Types)

| Code | Description |
|:---|:---|
| `struct Student { string name; int mark; };` | Define a custom type with multiple fields |
| `Student s1;` | Create a struct variable |
| `s1.name = "Ali";` | Set a field using dot notation |
| `cout << s1.name << s1.mark;` | Access fields for output |
| `Student s2 = {"Bob", 85};` | Initialize struct at declaration |
| `vector<Student> students;` | Create a vector of structs |
| `students.push_back(s1);` | Add a struct to a vector |
| `students[i].name` | Access a field of a struct inside a vector |
| *(Remember the semicolon after `}`)* | `struct Student { ... };` ← don't forget |

---

## 📥 Part 4: Input & Output

| Code | Description |
|:---|:---|
| `cout << "text";` | Print text to console |
| `cout << x;` | Print variable value |
| `cout << a << b;` | Print multiple items |
| `cout << endl;` | Print newline and flush |
| `cin >> x;` | Read user input into variable |
| `cin >> a >> b;` | Read multiple inputs |
| `getline(cin, str);` | Read an entire line (including spaces) |
| `cin.ignore();` | Discard leftover newline after `cin >>` before `getline` |
| `cin.fail()` | Check if input failed |
| `cin.clear()` | Clear input error flag |

---

## 🎨 Part 5: Formatting Output

| Code | Description |
|:---|:---|
| `fixed` | Set decimal format (not scientific) |
| `setprecision(2)` | Set to 2 decimal places |
| `cout << fixed << setprecision(2);` | Apply decimal formatting to all following output |
| `setw(10)` | Set field width to 10 spaces |
| `left` / `right` | Left or right align output |

---

## 📄 Part 6: File I/O (Reading & Writing Files)

| Code | Description |
|:---|:---|
| `#include <fstream>` | Required header for file streams |
| `ofstream outFile("data.txt");` | Open a file for writing (creates or overwrites) |
| `ifstream inFile("data.txt");` | Open a file for reading |
| `outFile << s.name << "," << s.mark << endl;` | Write data to file (CSV format) |
| `while (getline(inFile, line)) { }` | Read file line by line |
| `if (inFile.is_open()) { }` | Check if the file was opened successfully |
| `outFile.close();` | Close the output file (good practice) |
| `inFile.close();` | Close the input file (good practice) |

### Parsing Data from a File

| Code | Description |
|:---|:---|
| `stringstream ss(line);` | Create a stream from a line of text |
| `getline(ss, name, ',');` | Extract a field until the comma |
| `getline(ss, markStr, ',');` | Extract the next field |
| `int mark = stoi(markStr);` | Convert string to integer |

---

## 🔀 Part 7: Conditionals (If-Else)

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

## 🔁 Part 8: Loops

| Code | Description |
|:---|:---|
| `for (int i = 0; i < n; i++) { }` | Loop with counter |
| `for (int i = n-1; i >= 0; i--) { }` | Loop backwards |
| `for (char c : str) { }` | Range-based for loop (C++11) |
| `for (int i = 0; i < vec.size(); i++)` | Loop through all elements of a vector |
| `for (Student s : students) { }` | Range-based loop for a vector of structs |
| `while (condition) { }` | Check condition first, then run |
| `while (getline(inFile, line)) { }` | Read a file until the end |
| `do { } while (condition);` | Run first, then check condition |
| `break;` | Exit loop immediately |
| `continue;` | Skip to next iteration |

### Loop Operations

| Code | Description |
|:---|:---|
| `i++` | Increase by one |
| `i--` | Decrease by one |
| `i += 2` | Increase by two |
| `i < str.length()` | Loop condition for string length |
| `i < vec.size()` | Loop condition for vector size |

---

## 📦 Part 9: Arrays, Vectors & Strings

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

## 🧩 Part 10: String Parsing with `stringstream`

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

## ⚙️ Part 11: Functions

| Code | Description |
|:---|:---|
| `void name() { }` | Function returns nothing |
| `int name() { return x; }` | Function returns integer |
| `double name() { return x; }` | Function returns double |
| `string name() { return str; }` | Function returns string |
| `bool name() { return true/false; }` | Function returns boolean |
| `char name() { return c; }` | Function returns character |
| `void name(int& a) { }` | Pass by reference (`&` modifies original) |
| `void addStudent(vector<Student>& v) { }` | Function that modifies the original vector |
| `void displayStudents(const vector<Student>& v) { }` | Function that only reads the vector |
| `void saveToFile(const vector<Student>& v) { }` | Write vector data to a file |
| `void loadFromFile(vector<Student>& v) { }` | Read file data into a vector |
| `int name(int arr[], int size)` | Function with array parameter |

### Function Types Summary

| Return Type | Return Needed | Call in `main()` |
|:---|:---|:---|
| `void` | ❌ No | `functionName(data);` |
| `int` | ✅ Yes | `cout << functionName(data);` |
| `string` | ✅ Yes | `cout << functionName(data);` |
| `bool` | ✅ Yes | `cout << functionName(data);` |
| `double` | ✅ Yes | `cout << functionName(data);` |
| `char` | ✅ Yes | `cout << functionName(data);` |

---

## 🧩 Part 12: Common Program Patterns

### Guard Clause Pattern

| Pattern | Description | Example |
|:---|:---|:---|
| **Guard Clause** | Handle edge case first, then write normal logic. | `if (vec.empty()) return;` |

### Menu-Driven Program Pattern

| Step | Code |
|:---|:---|
| 1. Display menu | `cout << "1. Add\n2. Display\n3. Save\n4. Exit\n";` |
| 2. Get user choice | `int choice; cin >> choice;` |
| 3. Act on choice | `if (choice == 1) addStudent(students);` |
| 4. Loop until exit | `while (choice != 4) { }` |

### Search Pattern

| Step | Code |
|:---|:---|
| 1. Get search term | `string name; getline(cin, name);` |
| 2. Loop through vector | `for (Student s : students)` |
| 3. Compare and return/print | `if (s.name == name) { cout << s.mark; }` |

---

## 🎲 Part 13: Random Numbers

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

## 🔄 Part 14: Type Conversions

| Code | Description |
|:---|:---|
| `stoi(str)` | Convert string to integer |
| `stof(str)` | Convert string to float |
| `stod(str)` | Convert string to double |
| `to_string(num)` | Convert number to string |
| `(int)doubleValue` | C-style cast (double to int) |
| `static_cast<int>(doubleValue)` | C++ style cast |

---

## 📝 Part 15: Comments

| Code | Description |
|:---|:---|
| `// single line comment` | Comment until end of line |
| `/* multi-line comment */` | Comment across multiple lines |

---

## ✅ One Sentence Summary

C++ requires `#include` statements, semicolons `;`, curly braces `{}`, explicit data types, and function return types; Python uses indentation and dynamic typing – **your cheat sheet now covers structs, file I/O, parsing data from files, menu-driven programs, the search pattern, and common function signatures for student management systems.** 💪
