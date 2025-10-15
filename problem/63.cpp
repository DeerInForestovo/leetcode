#include <bits/stdc++.h>
using namespace std;

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        if (obstacleGrid[0][0] == 1) return 0;
        dp[0][0] = 1;
        for (int i = 1; i < n; ++i)
            dp[i][0] = (obstacleGrid[i][0] == 1 ? 0 : dp[i - 1][0]);
        for (int j = 1; j < m; ++j)
            dp[0][j] = (obstacleGrid[0][j] == 1 ? 0 : dp[0][j - 1]);
        for (int i = 1; i < n; ++i)
            for (int j = 1; j < m; ++j)
                dp[i][j] = (obstacleGrid[i][j] == 1 ? 0 : dp[i - 1][j] + dp[i][j - 1]);
        return dp[n - 1][m - 1];
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif