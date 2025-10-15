#include <bits/stdc++.h>
using namespace std;

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    int ans[50];
    int climbStairs(int n) {
        ans[0] = 1;
        ans[1] = 1;
        for (int i = 2; i <= n; ++i)
            ans[i] = ans[i - 1] + ans[i - 2];
        return ans[n];
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif