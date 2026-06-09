#include <iostream>
#include <vector>
using namespace std;

int maximum (vector <int> &nums) {
    int max = nums[0];
    for (int i = 1; i<nums.size(); i++) {
        if (max < nums[i]) {
            max = nums[i];
        }
    }
    return max;
}

int minimum(vector <int> &nums) {
    int min = nums[0];
    for (int i = 1; i<nums.size(); i++) {
        if (min > nums[i]) {
            min = nums[i];
        }
    }
    return min;
}
int main() {
    vector <int> nums = {12, 45, 7, 89, 23};

    cout << "Numbers: "; 
    for (int i=0; i<nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() -1 ) {
            cout << ", ";
        }
    }
    cout << endl;
    
    cout << "Maximum value: " << maximum(nums) << endl;
    cout << "Minimum value: " << minimum(nums) << endl;

    return 0;
}