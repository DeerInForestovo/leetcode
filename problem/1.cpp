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
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int sum = sorted_nums[left] + sorted_nums[right];
            if (sum == target)
                for (int i = 0; i < nums.size(); ++i)
                    if (nums[i] == sorted_nums[left])
                        for (int j = 0; j < nums.size(); ++j)
                            if (i != j && nums[j] == sorted_nums[right])
                                return {i, j};
            if (sum < target) ++left;
                else --right;
        }
        return {};
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif