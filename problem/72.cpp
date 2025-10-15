#include <bits/stdc++.h>
using namespace std;

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        // for i from 1 to n,
        // dp[j] means the distance between word1[0..i-1] and word2[0..j-1]
        vector<int> dp(m + 1);
        for (int j = 0; j <= m; ++j) dp[j] = j;  // distance between "" and word2[0..j-1]
        for (int i = 1; i <= n; ++i) {
            int prev = dp[0];  // dp[i-1][j-1]
            dp[0] = i;  // distance between word1[0..i-1] and ""
            for (int j = 1; j <= m; ++j) {
                int temp = dp[j];  // dp[i-1][j]
                if (word1[i - 1] == word2[j - 1]) dp[j] = min(prev, min(dp[j], dp[j - 1]) + 1);  // min(dp[i-1][j-1], dp[i-1][j] + 1, dp[i][j-1] + 1)
                    else dp[j] = min(prev, min(dp[j], dp[j - 1])) + 1;  // min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1
                prev = temp;
            }
        }
        return dp[m];
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif