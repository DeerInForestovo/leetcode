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
    int trap(vector<int>& height) {
        int ans = 0, n = height.size(), maxx = height[0], maxInd = 0;
        for (int i = 1; i < n; ++i)
            if (height[i] > maxx) {
                maxx = height[i];
                maxInd = i;
            }
        int leftMax = height[0];
        for (int i = 1; i < maxInd; ++i)
            if (height[i] < leftMax) ans += leftMax - height[i];
            else leftMax = height[i];
        int rightMax = height[n - 1];
        for (int i = n - 2; i > maxInd; --i)
            if (height[i] < rightMax) ans += rightMax - height[i];
                else rightMax = height[i];
        return ans;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif