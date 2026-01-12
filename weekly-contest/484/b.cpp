#include <bits/stdc++.h>

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size(), result = 0;
        for (int l = 0; l < n; ++l) {
            set<int> s;
            long long sum = 0;
            for (int r = l; r < n; ++r) {
                s.insert(nums[r]);
                sum += nums[r];
                if (s.count(sum))
                    ++result;
            }
        }
        return result;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif