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
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int pos = 0;
        for (int i = 30; i >= 0; --i) {
            if (pos + (1 << i) < n && nums[pos + (1 << i)] > nums[0])
                pos += (1 << i);
        }
        if (pos + 1 < n) return nums[pos + 1];
        return nums[0];
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif