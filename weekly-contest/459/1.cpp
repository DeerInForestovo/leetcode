#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
You are given a positive integer n. Determine whether n is divisible by the sum of the following two values:

The digit sum of n (the sum of its digits).

The digit product of n (the product of its digits).

Return true if n is divisible by this sum; otherwise, return false.©leetcode
*/

class Solution {
public:
    bool checkDivisibility(int n) {
        int a = 0, b = 1;
        int x = n;
        while (x) {
            int digit = x % 10;
            a += digit; // Digit sum
            b *= digit; // Digit product
            x /= 10;
        }
        int sum = a + b;
        if (sum == 0) return false; // Avoid division by zero
        return n % sum == 0; // Check divisibility
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    cout << sol.checkDivisibility(23) << endl; // Example test case 
    return 0;
}
#endif