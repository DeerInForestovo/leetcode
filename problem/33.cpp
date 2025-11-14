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
    int binary_search(vector<int>& nums, int target, int left, int right) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int break_point = 0;
        for (int i = 30; i >= 0; --i) {
            int step = 1 << i;
            if (break_point + step < n && nums[break_point + step] >= nums[0]) {
                break_point += step;
            }
        }
        int ans1 = binary_search(nums, target, 0, break_point);
        if (ans1 != -1) return ans1;
        return binary_search(nums, target, break_point + 1, n - 1);
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif