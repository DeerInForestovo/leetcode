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
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.resize(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int coin: coins) {
            for (int i = coin; i <= amount; ++i)
                if (dp[i - coin] != INT_MAX)
                    dp[i] = min(dp[i], dp[i - coin] + 1);
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif