#include <bits/stdc++.h>
using namespace std;

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), t = s3.size();
        if (n + m != t) return false;
        vector<bool> dp(n + 1, true);
        // for l from 1 to t,
        // dp[i] means whether it is possible to use the first i characters of s1 and l-i characters of s2 to form the first l characters of s3
        for (int l = 1; l <= t; ++l) {
            for (int i = min(l, n); i >= 0; --i) {
                dp[i] = (i > 0 && s1[i - 1] == s3[l - 1] && dp[i - 1]) || (l - i > 0 && l - i - 1 < m && s2[l - i - 1] == s3[l - 1] && dp[i]);
            }
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