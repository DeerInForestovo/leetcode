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

You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.

Return the maximum score you can get by erasing exactly one subarray.

An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).
*/

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int, int> lastIndex;
        int maxScore = 0, currentScore = 0, start = -1, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (lastIndex.find(nums[i]) != lastIndex.end() && lastIndex[nums[i]] >= start)
                while (start < lastIndex[nums[i]])
                    currentScore -= nums[++start];
            currentScore += nums[i];
            lastIndex[nums[i]] = i;
            maxScore = max(maxScore, currentScore);
        }
        return maxScore;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif