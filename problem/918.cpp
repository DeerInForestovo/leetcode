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
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int total = nums[0];
        int max_ending = nums[0], max_so_far = nums[0];
        int min_ending = nums[0], min_so_far = nums[0];
        for (int i = 1; i < n; ++i) {
            int x = nums[i];
            max_ending = max(x, max_ending + x);
            max_so_far = max(max_so_far, max_ending);
            min_ending = min(x, min_ending + x);
            min_so_far = min(min_so_far, min_ending);
            total += x;
        }
        if (max_so_far < 0) return max_so_far;
        return max(max_so_far, total - min_so_far);
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif