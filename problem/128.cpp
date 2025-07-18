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
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int max_len = 0;
        for (int num : nums) {
            if (numSet.find(num) == numSet.end() || numSet.find(num - 1) != numSet.end()) continue;
            int cur_len = 0;
            do {
                numSet.erase(num + (cur_len++));
            } while (numSet.find(num + cur_len) != numSet.end());
            max_len = max(max_len, cur_len);
        }
        return max_len;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif