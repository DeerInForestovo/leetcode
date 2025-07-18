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
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        int n = points.size(), arrows = 1, end = points[0][1];
        for (int i = 1; i < n; ++i) {
            if (points[i][0] > end) {
                ++arrows;
                end = points[i][1];
            } else end = min(end, points[i][1]);
        }
        return arrows;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif