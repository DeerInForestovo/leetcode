#include <bits/stdc++.h>

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    bool check(const vector<int>& nums, int k, int m, int target) {
        vector<int> cost;
        for (auto num : nums) {
            int t = target;
            int c = 0;
            for (int i = 30; i >= 0; --i) {
                int bit = 1 << i;
                bool target_has_bit = (target & bit) != 0;
                bool num_has_bit = (num & bit) != 0;
                if (target_has_bit && !num_has_bit) {
                    c = t - num;
                    break;
                }
                t = (t | bit) ^ bit;
                num = (num | bit) ^ bit;
            }
            cost.push_back(c);
        }
        long long total = 0;
        sort(cost.begin(), cost.end());
        for (int i = 0; i < m; ++i)
            total += cost[i];
        return total <= k;
    }
    int maximumAND(vector<int>& nums, int k, int m) {
        int ans = 0;
        for (int i = 30; i >= 0; --i) {
            if (check(nums, k, m, ans | (1 << i)))
                ans |= (1 << i);
        }
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