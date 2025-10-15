#include <bits/stdc++.h>
using namespace std;

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    vector<int> dp;
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n + 1);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 2; i <= n; ++i)
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
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