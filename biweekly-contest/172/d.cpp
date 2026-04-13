#include <bits/stdc++.h>

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    long long lastInteger(long long n) {
        long long ans = 1, base = 1, round = 0;
        while (n > 1) {
            if (round % 2 == 1 && n % 2 == 0)
                ans += base;
            base *= 2;
            ++round;
            n = (n + 1) / 2;
        }
        return ans;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif