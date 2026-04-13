#include <bits/stdc++.h>

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    long long count(long long n) {
        if (n < 10) return 0;
        std::string s = std::to_string(n);
        int len = s.length();
        const int MAX_BALANCE = 200;
        const int OFFSET = MAX_BALANCE;
        const int DP_SIZE = 2 * MAX_BALANCE + 1;
        vector<int> prefix(len + 1);
        prefix[0] = 0;
        int sign = 1;
        for (int i = 0; i < len; ++i) {
            prefix[i + 1] = prefix[i] + sign * (s[i] - '0');
            sign = -sign;
        }
        
        vector<long long> dp(DP_SIZE), dp_next(DP_SIZE);
        long long result = 0;
        for (int i = 0; i < len; ++i) {
            dp.assign(DP_SIZE, 0);
            int balance = prefix[i];
            sign = (i % 2 == 0) ? 1 : -1;
            for (int d = 0; d < (s[i] - '0'); ++d)
                dp[OFFSET + balance + sign * d] = 1;
            sign = -sign;
            for (int j = i + 1; j < len; ++j) {
                dp_next.assign(DP_SIZE, 0);
                for (int d = 0; d <= 9; ++d) {
                    for (int sum = -MAX_BALANCE; sum <= MAX_BALANCE; ++sum) {
                        int from = OFFSET + sum;
                        int to = OFFSET + sum + sign * d;
                        if (to < 0 || to >= DP_SIZE) continue;
                        dp_next[to] += dp[from];
                    }
                }
                dp.swap(dp_next);
                sign = -sign;
            }
            result += dp[OFFSET];
        }
        if (prefix[len] == 0) ++result;
        return result - 1;
    }
    long long countBalanced(long long low, long long high) {
        return count(high) - count(low - 1);
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif