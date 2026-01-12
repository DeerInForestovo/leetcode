#include <bits/stdc++.h>

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        long long sum = 0;
        int n = nums.size(), r = 0, ans = n + 1;
        map<int, int> freq;
        for (int l = 0; l < n; ++l) {
            while (r < n && sum < k) {
                freq[nums[r]]++;
                if (freq[nums[r]] == 1) sum += nums[r];
                ++r;
            }
            if (sum >= k) ans = min(ans, r - l);
            if (freq[nums[l]] == 1) sum -= nums[l];
            freq[nums[l]]--;
        }
        return ans == n + 1 ? -1 : ans;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif