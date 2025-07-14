#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        if (n == 0) return 0;
        int m = dungeon[0].size();
        if (m == 0) return 0;

        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[n - 1][m - 1] = max(1, 1 - dungeon[n - 1][m - 1]);

        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (i == n - 1 && j == m - 1) continue;
                dp[i][j] = 1 << 30;
                if (i < n - 1) dp[i][j] = min(dp[i][j], dp[i + 1][j] - dungeon[i][j]);
                if (j < m - 1) dp[i][j] = min(dp[i][j], dp[i][j + 1] - dungeon[i][j]);
                if (dp[i][j] <= 0) dp[i][j] = 1;
            }
        }

        return dp[0][0];
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif