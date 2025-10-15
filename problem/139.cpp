#include <bits/stdc++.h>
using namespace std;

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    vector<bool> dp;
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        dp.resize(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i)
            for (const string& word : wordDict) {
                int len = word.size();
                if (i < len || !dp[i - len]) continue;
                if (i >= len && s.substr(i - len, len) == word)
                    dp[i] = true;
                if (dp[i]) break;
            }
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