#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int nsize = nums.size(), maxReach = 0;
        for (int i = 0; i < nsize && i <= maxReach; ++i) {
            maxReach = max(maxReach, i + nums[i]);
            if (maxReach >= nsize - 1) return true;
        }
        return false;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif