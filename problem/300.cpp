#include <bits/stdc++.h>
using namespace std;

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    const int MaxM = 20000 + 10;
    const int Bias = MaxM >> 1;
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i)
            nums[i] += Bias;
        vector<int> BIT(MaxM, 0);
        auto lowbit = [](int x) { return x & -x; };
        auto update = [&](int x, int v) {
            for (; x < MaxM; x += lowbit(x))
                BIT[x] = max(BIT[x], v);
        };
        auto query = [&](int x) {
            int res = 0;
            for (; x; x -= lowbit(x))
                res = max(res, BIT[x]);
            return res;
        };
        for (int i = 0; i < n; ++i) {
            int best = query(nums[i] - 1) + 1;
            update(nums[i], best);
        }
        return query(MaxM - 1);
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif