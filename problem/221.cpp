#include <bits/stdc++.h>
using namespace std;

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

// class Solution {
// public:
//     int maximalSquare(vector<vector<char>>& matrix) {
//         int n = matrix.size(), m = matrix[0].size(), ans = 0;
//         vector<int> up(m, 0);
//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < m; ++j)
//                 if (matrix[i][j] == '0') up[j] = 0;
//                     else ++up[j];
//             for (int j = 0, min_h = 1000; j < m; ++j, min_h = 1000)
//                 for (int k = j; k < m; ++k) {
//                     min_h = min(min_h, up[k]);
//                     if (!min_h) break;
//                     ans = max(ans, min(min_h, k - j + 1));
//                 }
//         }
//         return ans * ans;
//     }
// };

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            dp[i][0] = matrix[i][0] == '1';
            for (int j = 1; j < m; ++j) {
                if (matrix[i][j] == '0') {
                    dp[i][j] == 0;
                    continue;
                }
                if (!i) {
                    dp[i][j] = 1;
                    continue;
                }
                int best = min(dp[i - 1][j], dp[i][j - 1]);
                dp[i][j] = max(best, 1);
                if (best && dp[i - best][j - best])
                    dp[i][j] = best + 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                ans = max(ans, dp[i][j]);
        return ans * ans;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif