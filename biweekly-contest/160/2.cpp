#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>> waitCost) {
        const long long inf = 1ll << 60;
        vector<vector<long long>> dp(m, vector<long long>(n, inf));
        dp[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Move right
                if (j + 1 < n)
                    dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + waitCost[i][j + 1] + (i + 1) * (j + 2));
                // Move down
                if (i + 1 < m)
                    dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + waitCost[i + 1][j] + (i + 2) * (j + 1));
            }
        }
        return dp[m - 1][n - 1] - waitCost[m - 1][n - 1];
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    // m = 2, n = 2, waitCost = [[3,5],[2,4]]©leetcode
    cout << sol.minCost(2, 2, {{3, 5}, {2, 4}}) << endl; // Example usage
    // m = 2, n = 3, waitCost = [[6,1,4],[3,2,5]]©leetcode
    cout << sol.minCost(2, 3, {{6, 1, 4}, {3, 2, 5}}) << endl; // Example usage
    return 0;
}
#endif