#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool dp[7][30][30];
    void update(int i, int l, int r) {
        if (l >= 0 && r >= 0)
            dp[i][max(l, r)][min(l, r)] = true;
    }
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        int minAns = 1000, maxAns = -1;
        memset(dp, 0, sizeof dp);
        update(0, firstPlayer - 1, n - secondPlayer);
        for (int i = 0; n >= 2; ++i) {
            int nn = n + 1 >> 1;
            for (int l = 0; l + 2 <= n; ++l)
                for (int r = 0; l + r + 2 <= n && r <= l; ++r) {
                    if (!dp[i][l][r]) continue;
                    if (l == r) {
                        minAns = min(minAns, i + 1);
                        maxAns = max(maxAns, i + 1);
                    } else {
                        if (l >= nn) {
                            int m = n - l - r - 2;
                            for (int mm = 0; mm <= m; ++mm)
                                for (int rr = 0; rr <= r; ++rr)
                                    update(i + 1, nn - rr - mm - 2, rr);
                        } else {
                            for (int ll = 0; ll <= r; ++ll)
                                for (int lm = 0; lm <= l - r - 1; ++lm)
                                    update(i + 1, ll + lm, r - ll);
                        }
                    }
                }
            n = nn;
        }
        vector<int> ans;
        ans.push_back(minAns);
        ans.push_back(maxAns);
        return ans;
    }
};

#ifdef LEETCODE_LOCAL
#include <iostream>
int main() {
    Solution sol;
    // Add test cases here
    auto ans = sol.earliestAndLatest(18, 8, 10);
    cout << ans[0] << ' ' << ans[1];
    return 0;
}
#endif