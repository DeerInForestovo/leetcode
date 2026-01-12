#include <bits/stdc++.h>

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    vector<int> _select(vector<int>& nums, int k) {
        vector<int> result;
        result.resize(k);
        int n = nums.size(), m = 0;
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            while (m > 0 && result[m - 1] < num && m + n - i > k)
                --m;
            if (m < k)
                result[m++] = num;
        }
        return result;
    }
    bool _greater(const vector<int>& a, int i, const vector<int>& b, int j) {
        int n = a.size(), m = b.size();
        while (i < n && j < m) {
            if (a[i] != b[j])
                return a[i] > b[j];
            ++i; ++j;
        }
        return (i != n);
    }
    vector<int> _merge(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int n = nums1.size(), m = nums2.size();
        vector<int> res;
        res.reserve(n + m);
        while (i < n || j < m) {
            if (_greater(nums1, i, nums2, j))
                res.push_back(nums1[i++]);
            else
                res.push_back(nums2[j++]);
        }
        return res;
    }
    void _update(vector<int>& result, vector<int>& current) {
        if (result.size() == 0) {
            result = current;
            return;
        }
        int n = result.size();
        for (int i = 0; i < n; ++i) {
            if (result[i] < current[i]) {
                result = current;
                return;
            }
            if (result[i] > current[i]) {
                return;
            }
        }
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> max_nums;
        for (int i = 0; i <= k; ++i) {
            int j = k - i;
            if (i <= n && j <= m) {
                auto selected_nums1 = _select(nums1, i);
                auto selected_nums2 = _select(nums2, j);
                auto merged_nums = _merge(selected_nums1, selected_nums2);
                _update(max_nums, merged_nums);
            }
        }
        return max_nums;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    vector<int> nums1, nums2;
    vector<int> out;

    nums1 = {3,4,6,5}; nums2 = {9,1,2,5,8,3}; out = sol.maxNumber(nums1, nums2, 5);
    for (int x : out) cout << x;
    cout << "\n"; // expect 98653

    nums1 = {6,7}; nums2 = {6,0,4}; out = sol.maxNumber(nums1, nums2, 5);
    for (int x : out) cout << x;
    cout << "\n"; // expect 67604

    nums1 = {3,9}; nums2 = {8,9}; out = sol.maxNumber(nums1, nums2, 3);
    for (int x : out) cout << x;
    cout << "\n"; // expect 989

    return 0;
}
#endif