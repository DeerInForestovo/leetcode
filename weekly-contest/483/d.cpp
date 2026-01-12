#include <bits/stdc++.h>

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    long long minMergeCost(vector<vector<int>>& lists) {
        const int MAXN = 12;
        int n = lists.size();
        int stats = 1 << n;
        int median[1 << MAXN];
        int length[1 << MAXN];
        long long dp[1 << MAXN];
        memset(dp, 127, sizeof(dp));
        for (int i = 1; i < stats; ++i) {
            vector<int> merged;
            for (int j = 0; j < n; ++j)
                if (i & (1 << j))
                    merged.insert(merged.end(), lists[j].begin(), lists[j].end());
            sort(merged.begin(), merged.end());
            length[i] = merged.size();
            median[i] = merged[(merged.size() - 1) / 2];
        }
        for (int i = 0; i < n; ++i)
            dp[1 << i] = 0;
        for (int i = 3; i < stats; ++i) {
            for (int j = 1; j < i; ++j) {
                if ((i & j) == j) {  // j \in i
                    int k = i ^ j;
                    dp[i] = min(dp[i], dp[j] + dp[k] + length[i] + abs(median[j] - median[k]));  // length[i] = length[j] + length[k]
                }
            }
        }
        return dp[stats - 1];
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif