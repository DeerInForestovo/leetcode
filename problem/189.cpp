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
    void rotate(vector<int>& nums, int k) {
        int nsize = nums.size();
        reverse(nums.begin(), nums.begin() + nsize - k);
        reverse(nums.begin() + nsize - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif