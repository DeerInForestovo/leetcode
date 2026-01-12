#include <bits/stdc++.h>

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    int countPalindromes(string s) {
        int n = s.size();
        const int MOD = 100000007;
        int ans = 0;
        int prefixPairs[10005][10][10], prefixDigits[10005][10];
        int suffixPairs[10005][10][10], suffixDigits[10005][10];
        memset(prefixPairs[0], 0, sizeof(prefixPairs[0]));
        memset(prefixDigits[0], 0, sizeof(prefixDigits[0]));
        memset(suffixPairs[n + 1], 0, sizeof(suffixPairs[n + 1]));
        memset(suffixDigits[n + 1], 0, sizeof(suffixDigits[n + 1]));
        for (int i = 1; i <= n; ++i) {
            memcpy(prefixPairs[i], prefixPairs[i - 1], sizeof(prefixPairs[i]));
            memcpy(prefixDigits[i], prefixDigits[i - 1], sizeof(prefixDigits[i]));
            int digit = s[i - 1] - '0';
            for (int d = 0; d <= 9; ++d)
                prefixPairs[i][d][digit] += prefixDigits[i - 1][d];
            ++prefixDigits[i][digit];
        }
        for (int i = n; i >= 1; --i) {
            memcpy(suffixPairs[i], suffixPairs[i + 1], sizeof(suffixPairs[i]));
            memcpy(suffixDigits[i], suffixDigits[i + 1], sizeof(suffixDigits[i]));
            int digit = s[i - 1] - '0';
            for (int d = 0; d <= 9; ++d)
                suffixPairs[i][digit][d] += suffixDigits[i + 1][d];
            ++suffixDigits[i][digit];
        }
        for (int i = 3; i <= n - 2; ++i)
            for (int d1 = 0; d1 <= 9; ++d1)
                for (int d2 = 0; d2 <= 9; ++d2)
                    ans = (ans + 1LL * prefixPairs[i - 1][d1][d2] * suffixPairs[i + 1][d2][d1]) % MOD;
        return ans;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif