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
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        result[0] = nums[0];
        for (int i = 1; i < n - 1; ++i)
            result[i] = result[i - 1] * nums[i];
        
        int suffix = 1;
        for (int i = n - 1; i > 0; --i) {
            result[i] = result[i - 1] * suffix;
            suffix *= nums[i];
        }
        result[0] = suffix;
        
        return result;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif