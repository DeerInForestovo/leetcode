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
    int removeDuplicates(vector<int>& nums) {
        int lmove = 0, nsize = nums.size();
        for (int i = 2; i < nsize; ++i)
            if (nums[i] == nums[i - lmove - 1] && nums[i] == nums[i - lmove - 2]) ++lmove;
                else nums[i - lmove] = nums[i];
        return nsize - lmove;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif