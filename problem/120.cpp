#include <bits/stdc++.h>
using namespace std;

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; ++i)
            for (int j = 0; j <= i; ++j)
                if (j == 0)
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
                else if (j == i)
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                else
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif