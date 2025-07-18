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
- Use ++i instead of i++ if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        short n = nums.size(), ans = 0, dp[1001];
        for (short sum = 0; sum < k; ++sum) {
            memset(dp, 0, sizeof dp);
            for (short i = 0; i < n; ++i)
                ans = max(ans,
                    dp[nums[i] % k] = max(dp[nums[i] % k],
                        (short)(dp[(sum + k - nums[i] % k) % k] + 1)
                    )
                );
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