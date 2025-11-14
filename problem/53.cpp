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
    int maxSubArray(vector<int>& nums) {
        int ans = 0, sum = 0;
        for (int num : nums) {
            sum += num;
            ans = max(ans, sum);
            if (sum < 0)
                sum = 0;
        }
        if (ans == 0) {
            ans = nums[0];
            for (int num : nums)
                ans = max(ans, num);
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