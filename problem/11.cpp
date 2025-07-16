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
    int maxArea(vector<int>& height) {
        int lpoint = 0, rpoint = height.size() - 1, maxArea = 0;
        while (lpoint < rpoint) {
            int currentHeight = min(height[lpoint], height[rpoint]);
            int currentWidth = rpoint - lpoint;
            maxArea = max(maxArea, currentHeight * currentWidth);
            
            if (height[lpoint] < height[rpoint]) lpoint++;
                else rpoint--;
        }
        return maxArea;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif