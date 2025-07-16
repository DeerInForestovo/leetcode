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
    int maximumLength(vector<int>& nums) {
        int n = nums.size(), zero = 0, one = 0, neq = 0, last = -1;
        for (int i = 0; i < n; ++i)
            if (nums[i] % 2 == 0) {
                zero++;
                if (last != 0) neq++;
                last = 0;
            } else {
                one++;
                if (last != 1) neq++;
                last = 1;
            }
        return max(max(zero, one), neq);
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif