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
    int majorityElement(vector<int>& nums) {
        int maj = 0, times = 0, nsize = nums.size();
        for (int i = 0; i < nsize; ++i)
            if (times == 0) maj = nums[i], times = 1;
                else if (maj == nums[i]) ++times;
                    else --times;
        return maj;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif