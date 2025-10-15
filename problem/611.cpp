#include <bits/stdc++.h>
using namespace std;

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        vector<int> cnt(1001), sum(1001);
        for (int x: nums) ++cnt[x];
        sum[1] = cnt[1];
        for (int i = 2; i <= 1000; ++i) sum[i] = sum[i - 1] + cnt[i];
        int n = nums.size(), ans = 0;
        // case 1: a == b == c
        for (int i = 1; i <= 1000; ++i)
            if (cnt[i] >= 3) ans += cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
        // case 2: a == b != c
        for (int i = 2; i <= 1000; ++i)
            if (cnt[i] >= 2)
                ans += cnt[i] * (cnt[i] - 1) / 2 * (sum[min(1000, 2 * i - 1)] - cnt[i]);
        // case 3: a < b < c
        for (int i = 1; i < 999; ++i)
            if (cnt[i] >= 1)
                for (int j = i + 1; j < 1000; ++j)
                    if (cnt[j] >= 1)
                        ans += cnt[i] * cnt[j] * (sum[min(1000, i + j - 1)] - sum[j]);
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