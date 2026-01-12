#include <bits/stdc++.h>

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    long long count(vector<long long>& prefix_sums, int left, int right, int lower, int upper) {
        if (right - left <= 1)
            return 0;
        int mid = left + (right - left) / 2;
        long long count_left = count(prefix_sums, left, mid, lower, upper);
        long long count_right = count(prefix_sums, mid, right, lower, upper);
        long long count_merge = 0;
        int j_lower = mid, j_upper = mid;
        for (int i = left; i < mid; ++i) {
            while (j_lower < right && prefix_sums[j_lower] - prefix_sums[i] < lower)
                ++j_lower;
            while (j_upper < right && prefix_sums[j_upper] - prefix_sums[i] <= upper)
                ++j_upper;
            count_merge += (j_upper - j_lower);
        }
        std::inplace_merge(prefix_sums.begin() + left, prefix_sums.begin() + mid, prefix_sums.begin() + right);
        return count_left + count_right + count_merge;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> prefix_sums;
        prefix_sums.reserve(nums.size() + 1);
        prefix_sums.push_back(0);
        for (int num : nums)
            prefix_sums.push_back(prefix_sums.back() + num);
        return count(prefix_sums, 0, prefix_sums.size(), lower, upper);
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif