#include <bits/stdc++.h>
using namespace std;

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (auto& str: strs) {
            int zero_cnt = 0, one_cnt = 0;
            for (auto& c: str)
                if (c == '0') ++zero_cnt;
                    else ++one_cnt;
            for (int i = n; i >= one_cnt; --i)
                for (int j = m; j >= zero_cnt; --j)
                    dp[i][j] = max(dp[i][j], dp[i - one_cnt][j - zero_cnt] + 1);
        }
        return dp[n][m];
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif