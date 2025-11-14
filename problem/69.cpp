#include <bits/stdc++.h>
using namespace std;

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    int mySqrt(int x) {
        // newton's method
        if (x == 0) return 0;
        long r = x;
        while (r * r > x)
            r = (r + x / r) / 2;
        return r;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif