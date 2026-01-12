#include <bits/stdc++.h>

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        const int MaxN = 2048;
        int n = s.size();
        int m = p.size();
        bitset<MaxN> dp, next_dp;
        // for i, dp[j] means p[0, i) matches s[0, j)
        dp.reset();
        dp[0] = 1;
        for (int i = 0; i < m; ++i) {
            next_dp.reset();
            if (p[i] == '*') {
                for (int j = 0; j <= n; ++j) {
                    if (dp[j]) {
                        for (int k = j; k <= n; ++k)
                            next_dp[k] = 1;
                        break;
                    }
                }
            } else {
                for (int j = 0; j < n; ++j) {
                    if (dp[j] && (p[i] == '?' || p[i] == s[j]))
                        next_dp[j + 1] = 1;
                }
            }
            dp = next_dp;
        }
        return dp[n];
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif