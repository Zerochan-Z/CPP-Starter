#include <iostream>
using namespace std;

int main() {
    int score = 100;
    int* ptr = &score;
    cout << score << endl;
    *ptr = 200;
    cout << score << endl;

    return 0;
}