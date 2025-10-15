#include <bits/stdc++.h>
using namespace std;

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        long long NEG_INF = -(1ll << 50);
        vector<vector<long long>> max_profit(2, vector<long long>(k + 1, NEG_INF));
        max_profit[0][0] = 0;
        for (auto price: prices) {
            vector<vector<long long>> prev_max_profit = max_profit;
            for (int j = 0; j <= k; ++j) {
                if (j) max_profit[0][j] = max({max_profit[0][j], prev_max_profit[1][j - 1] + price});
                max_profit[1][j] = max({max_profit[1][j], prev_max_profit[0][j] - price});
            }
        }
        long long maxans = NEG_INF;
        for (auto ans: max_profit[0])
            maxans = max(maxans, ans);
        return maxans;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif