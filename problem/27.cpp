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
    int removeElement(vector<int>& nums, int val) {
        int lmove = 0, nsize = nums.size();
        for (int i = 0; i < nsize; ++i)
            if (nums[i] == val) ++lmove;
                else nums[i - lmove] = nums[i];
                cout << lmove << endl;
        return nsize - lmove;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int k = 2;
    sol.removeElement(nums, k);
    for (auto i: nums) cout << i << ' ';
    return 0;
}
#endif