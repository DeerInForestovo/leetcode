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
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0, sum = 0, minLength = INT_MAX;
        for (right = 0; right < n; ++right) {
            sum += nums[right];
            while (sum >= target) {
                minLength = min(minLength, right - left + 1);
                sum -= nums[left++];
            }
        }
        return minLength == INT_MAX ? 0 : minLength;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif