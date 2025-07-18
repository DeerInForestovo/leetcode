#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    int minStable(vector<int> nums, int maxC) {
        int n = nums.size(), l = 1, r = n;

        int not_one = 0;
        for (int num : nums)
            if (num != 1) ++not_one;
        if (not_one <= maxC) return 0;

        vector<vector<int>> jump(n, vector<int>(20, 0));
        for (int i = 0; i < n; ++i)
            jump[i][0] = nums[i];
        for (int j = 1; j < 20; ++j)
            for (int i = 0; i + (1 << j) <= n; ++i)
                jump[i][j] = __gcd(jump[i][j - 1], jump[i + (1 << (j - 1))][j - 1]);
        
        vector<int> reach(n, 0);
        for (int i = 0; i < n; ++i) {
            int j = 0, k = 20, g = nums[i];
            while (i + j < n && k >= 0) {
                if (i + j + (1 << k) > n) {
                    --k;
                    continue;
                }
                int new_g = __gcd(g, jump[i + j][k]);
                if (new_g > 1) {
                    g = new_g;
                    j |= (1 << k);
                }
                --k;
            }
            reach[i] = j;
        }

        while (l < r) {
            int mid = (l + r) >> 1, remove = 0;
            for (int i = 0; i < n; ) {
                if (reach[i] > mid) {
                    ++remove; // remove i + mid
                    i = i + mid + 1;
                } else ++i;
            }
            if (remove <= maxC) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    // Input: nums = [3,5,10], maxC = 1©leetcode
    cout << sol.minStable({3, 5, 10}, 1) << endl; // Example usage
    // Input: nums = [2,6,8], maxC = 2©leetcode
    cout << sol.minStable({2, 6, 8}, 2) << endl; // Example usage
    // Input: nums = [2,4,9,6], maxC = 1©leetcode
    cout << sol.minStable({2, 4, 9, 6}, 1) << endl; // Example usage
    return 0;
}
#endif