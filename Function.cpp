#include <iostream>
using namespace std;

int add(int x, int y) {
    return x + y;
}

int main() {
    int result = add(5,3);
    cout << "Sum: " << result << endl;
    return 0;
}