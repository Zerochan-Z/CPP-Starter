## Intermediate C++ Code – Restaurant Bill Calculator

This is equivalent to a **Python intermediate level** program (like your crypto price checker). It uses:
- Functions
- Arrays
- Loops
- Conditionals
- User input

---

## The Complete Code

```cpp
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function prototypes (declare before use)
void displayMenu();
double calculateTotal(double prices[], int quantities[], int itemCount);
void applyDiscount(double& total);
void printReceipt(string items[], double prices[], int quantities[], int itemCount, double total);

int main() {
    // Menu data
    string items[] = {"Teh Tarik", "Ice Lemon Tea", "Matcha Latte"};
    double prices[] = {3.50, 6.90, 12.90};
    int quantities[3] = {0, 0, 0};
    int choice, quantity;
    char addMore;
    
    cout << "=== Welcome to J&J Restaurant ===\n\n";
    
    // Loop for ordering
    do {
        displayMenu();
        
        cout << "Pick your choice (1-3): ";
        cin >> choice;
        
        // Validate choice
        if (choice < 1 || choice > 3) {
            cout << "Invalid choice! Please try again.\n";
            continue;
        }
        
        cout << "Enter quantity: ";
        cin >> quantity;
        
        // Add to order
        quantities[choice - 1] += quantity;
        cout << "Added " << quantity << " x " << items[choice - 1] << "\n";
        
        cout << "\nAdd another? (Y/N): ";
        cin >> addMore;
        cout << "\n";
        
    } while (addMore == 'Y' || addMore == 'y');
    
    // Calculate total
    double total = calculateTotal(prices, quantities, 3);
    
    // Apply discount if eligible
    applyDiscount(total);
    
    // Print receipt
    printReceipt(items, prices, quantities, 3, total);
    
    return 0;
}

// Function definitions

void displayMenu() {
    cout << "========== DRINK MENU ==========\n";
    cout << "1. Teh Tarik      - RM 3.50\n";
    cout << "2. Ice Lemon Tea  - RM 6.90\n";
    cout << "3. Matcha Latte   - RM 12.90\n";
    cout << "================================\n";
}

double calculateTotal(double prices[], int quantities[], int itemCount) {
    double total = 0;
    for (int i = 0; i < itemCount; i++) {
        total = total + (prices[i] * quantities[i]);
    }
    return total;
}

void applyDiscount(double& total) {
    if (total > 30) {
        cout << "\n*** RM5 promo voucher applied! ***\n";
        total = total - 5;
    }
}

void printReceipt(string items[], double prices[], int quantities[], int itemCount, double total) {
    cout << "\n========== YOUR RECEIPT ==========\n";
    
    for (int i = 0; i < itemCount; i++) {
        if (quantities[i] > 0) {
            cout << quantities[i] << " x " << items[i];
            cout << " = RM " << fixed << setprecision(2) << (prices[i] * quantities[i]) << "\n";
        }
    }
    
    cout << "--------------------------------\n";
    cout << "TOTAL: RM " << fixed << setprecision(2) << total << "\n";
    cout << "================================\n";
    cout << "Thank you for visiting!\n";
}
```

---

## Line-by-Line Breakdown

### Part 1: Includes and Setup (Lines 1-4)

```cpp
#include <iostream>   // For cin, cout (input/output)
#include <iomanip>    // For setprecision (decimal formatting)
#include <string>     // For string data type
using namespace std;  // So we don't have to write std:: every time
```

| Code | Meaning |
|------|---------|
| `#include <iostream>` | Print and input tools |
| `#include <iomanip>` | Format decimals (RM 3.50 not 3.5) |
| `#include <string>` | Use text variables |
| `using namespace std;` | Saves typing `std::` before `cout`, `cin`, `string` |

---

### Part 2: Function Prototypes (Lines 6-10)

```cpp
void displayMenu();
double calculateTotal(double prices[], int quantities[], int itemCount);
void applyDiscount(double& total);
void printReceipt(string items[], double prices[], int quantities[], int itemCount, double total);
```

| Code | Meaning |
|------|---------|
| `void` | Function returns nothing |
| `double` | Function returns a decimal number |
| `double& total` | Pass by reference (can modify original) |
| `[]` | Array (list of values) |

**Why prototypes?** C++ needs to know functions exist before you use them. Prototypes declare them early.

---

### Part 3: Main Function – Variables (Lines 12-20)

```cpp
int main() {
    string items[] = {"Teh Tarik", "Ice Lemon Tea", "Matcha Latte"};
    double prices[] = {3.50, 6.90, 12.90};
    int quantities[3] = {0, 0, 0};
    int choice, quantity;
    char addMore;
```

| Code | Meaning |
|------|---------|
| `string items[]` | Array of text (like Python list of strings) |
| `double prices[]` | Array of decimals (like Python list of floats) |
| `int quantities[3]` | Array of 3 integers (starts at 0) |
| `char addMore` | Single character variable ('Y' or 'N') |

**Python equivalent:**
```python
items = ["Teh Tarik", "Ice Lemon Tea", "Matcha Latte"]
prices = [3.50, 6.90, 12.90]
quantities = [0, 0, 0]
```

---

### Part 4: Main Function – Ordering Loop (Lines 22-48)

```cpp
do {
    displayMenu();
    
    cout << "Pick your choice (1-3): ";
    cin >> choice;
    
    if (choice < 1 || choice > 3) {
        cout << "Invalid choice! Please try again.\n";
        continue;  // Skip rest of loop, ask again
    }
    
    cout << "Enter quantity: ";
    cin >> quantity;
    
    quantities[choice - 1] += quantity;
    cout << "Added " << quantity << " x " << items[choice - 1] << "\n";
    
    cout << "\nAdd another? (Y/N): ";
    cin >> addMore;
    
} while (addMore == 'Y' || addMore == 'y');
```

| Code | Meaning |
|------|---------|
| `do { } while(condition);` | Run code at least once, then repeat while condition true |
| `cin >> choice` | Get user input (like `input()` in Python) |
| `quantities[choice - 1]` | Array index (0,1,2) for user choice (1,2,3) |
| `continue` | Skip to next loop iteration |

**Python equivalent:**
```python
while True:
    displayMenu()
    choice = int(input("Pick your choice (1-3): "))
    if choice < 1 or choice > 3:
        print("Invalid choice")
        continue
    quantity = int(input("Enter quantity: "))
    quantities[choice - 1] += quantity
    again = input("Add another? (Y/N): ")
    if again.upper() != 'Y':
        break
```

---

### Part 5: Function Definitions

#### `displayMenu()` (Lines 54-61)

```cpp
void displayMenu() {
    cout << "========== DRINK MENU ==========\n";
    cout << "1. Teh Tarik      - RM 3.50\n";
    cout << "2. Ice Lemon Tea  - RM 6.90\n";
    cout << "3. Matcha Latte   - RM 12.90\n";
    cout << "================================\n";
}
```

| Code | Meaning |
|------|---------|
| `void` | Returns nothing (just prints) |
| `\n` | Newline character (like `\n` in Python) |

---

#### `calculateTotal()` (Lines 63-70)

```cpp
double calculateTotal(double prices[], int quantities[], int itemCount) {
    double total = 0;
    for (int i = 0; i < itemCount; i++) {
        total = total + (prices[i] * quantities[i]);
    }
    return total;
}
```

| Code | Meaning |
|------|---------|
| `double` | Returns a decimal number |
| `for (int i = 0; i < itemCount; i++)` | Loop from 0 to itemCount-1 |
| `total = total + ...` | Add to running total |

**Python equivalent:**
```python
def calculateTotal(prices, quantities):
    total = 0
    for i in range(len(prices)):
        total += prices[i] * quantities[i]
    return total
```

---

#### `applyDiscount()` (Lines 72-78)

```cpp
void applyDiscount(double& total) {
    if (total > 30) {
        cout << "\n*** RM5 promo voucher applied! ***\n";
        total = total - 5;
    }
}
```

| Code | Meaning |
|------|---------|
| `double& total` | **Pass by reference** – can modify original variable |
| `if (total > 30)` | Condition (like Python `if total > 30:`) |

**Why `&` matters:** Without `&`, changes to `total` inside function wouldn't affect the original.

**Python equivalent:**
```python
def applyDiscount(total):
    if total > 30:
        print("*** RM5 promo voucher applied! ***")
        total -= 5
    return total  # Python returns instead of using reference
```

---

#### `printReceipt()` (Lines 80-96)

```cpp
void printReceipt(string items[], double prices[], int quantities[], int itemCount, double total) {
    cout << "\n========== YOUR RECEIPT ==========\n";
    
    for (int i = 0; i < itemCount; i++) {
        if (quantities[i] > 0) {
            cout << quantities[i] << " x " << items[i];
            cout << " = RM " << fixed << setprecision(2) << (prices[i] * quantities[i]) << "\n";
        }
    }
    
    cout << "--------------------------------\n";
    cout << "TOTAL: RM " << fixed << setprecision(2) << total << "\n";
    cout << "================================\n";
    cout << "Thank you for visiting!\n";
}
```

| Code | Meaning |
|------|---------|
| `fixed << setprecision(2)` | Show 2 decimal places (3.50 not 3.5) |
| `if (quantities[i] > 0)` | Only show items that were ordered |

**Python equivalent:**
```python
def printReceipt(items, prices, quantities, total):
    print("\n========== YOUR RECEIPT ==========")
    for i in range(len(items)):
        if quantities[i] > 0:
            print(f"{quantities[i]} x {items[i]} = RM {prices[i] * quantities[i]:.2f}")
    print(f"TOTAL: RM {total:.2f}")
```

---

## Key C++ Concepts vs Python

| Concept | C++ | Python |
|---------|-----|--------|
| Print | `cout << "text"` | `print("text")` |
| Input | `cin >> variable` | `variable = input()` |
| Function return type | Must declare (`int`, `double`, `void`) | Not required |
| Pass by reference | `double& total` | Not available (returns instead) |
| Array | `int arr[5]` | `arr = [0, 2, 4]` |
| Loop | `for (int i = 0; i < n; i++)` | `for i in range(n):` |
| Decimal format | `fixed << setprecision(2)` | `f"{value:.2f}"` |
| Semicolon | Required after statements | Not required |

---

## One Sentence Summary

**This C++ restaurant program uses arrays to store menu data, a do-while loop for repeated ordering, functions to calculate totals and apply discounts, and pass-by-reference to modify the original total – same logic as your Python crypto checker, but with stricter syntax.**
