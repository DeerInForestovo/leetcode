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
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int l = 0, n = nums.size();
        for (int r = 1; r <= n; ++r) {
            if (r == n || nums[r] != nums[r - 1] + 1) {
                if (l == r - 1)
                    result.push_back(to_string(nums[l]));
                else
                    result.push_back(to_string(nums[l]) + "->" + to_string(nums[r - 1]));
                l = r;
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