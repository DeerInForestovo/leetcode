#include <bits/stdc++.h>
using namespace std;

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        long long NEG_INF = -(1ll << 50);
        long long max_profit[2][3] = {
            {0ll, NEG_INF, NEG_INF},
            {NEG_INF, NEG_INF, NEG_INF}
        };  // max profit if I have i stocks and have done j transactions
        for (int price : prices) {
            long long new_max_profit[3][3];
            memcpy(new_max_profit, max_profit, sizeof(max_profit));
            for (int i = 0; i <= 1; ++i)
                for (int j = 0; j <= 2; ++j) {
                    new_max_profit[i][j] = max(new_max_profit[i][j], max_profit[i][j]);
                    if (!i)
                        new_max_profit[1][j] = max(new_max_profit[1][j], max_profit[0][j] - price);
                    if (i && j <= 1)
                        new_max_profit[0][j + 1] = max(new_max_profit[0][j + 1], max_profit[1][j] + price);
                }
            memcpy(max_profit, new_max_profit, sizeof(max_profit));
        }
        return max({max_profit[0][0], max_profit[0][1], max_profit[0][2]});
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif