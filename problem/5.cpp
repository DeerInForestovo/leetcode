#include <bits/stdc++.h>
using namespace std;

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    pair<int, pair<int, int>> dp[1005][1005];  // val, <start, end>
    string longestPalindrome(string s) {
        int n = s.size();
        for (int len = 1; len <= n; ++len)
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                if (len == 1)
                    dp[i][j] = {1, {i, j}};
                else if (s[i] == s[j]) {
                    if (len == 2)
                        dp[i][j] = {2, {i, j}};
                    else if (dp[i + 1][j - 1].first == j - i - 1)
                        dp[i][j] = {dp[i + 1][j - 1].first + 2, {i, j}};
                    else
                        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                } else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        pair<int, pair<int, int>> best = {0, {0, 0}};
        for (int i = 0; i < n; ++i)
            for (int j = i; j < n; ++j)
                best = max(best, dp[i][j]);
        return s.substr(best.second.first, best.first);
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif