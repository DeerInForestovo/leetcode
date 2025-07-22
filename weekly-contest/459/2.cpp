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

You are given a 2D integer array points, where points[i] = [xi, yi] represents the coordinates of the ith point on the Cartesian plane.

A horizontal trapezoid is a convex quadrilateral with at least one pair of horizontal sides (i.e. parallel to the x-axis). Two lines are parallel if and only if they have the same slope.

Return the number of unique horizontal trapezoids that can be formed by choosing any four distinct points from points.

Since the answer may be very large, return it modulo 109 + 7.©leetcode
*/

class Solution {
public:
    const int mod = 1e9 + 7;
    int countTrapezoids(vector<vector<int>>& points) {
        map<int, int> yCount;
        for (const auto& point : points) 
            ++yCount[point[1]];
        int pre = 0, tot = 0;
        for (auto& [y, count] : yCount) {
            count = (1ll * count * (count - 1) / 2) % mod;
            tot = (tot + 1ll * pre * count) % mod;
            pre = (pre + count) % mod;
        }
        return tot;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    // Input: points = [[1,0],[2,0],[3,0],[2,2],[3,2]]©leetcode
    vector<vector<int>> points = {{1, 0}, {2, 0}, {3, 0}, {2, 2}, {3, 2}};
    cout << sol.countTrapezoids(points) << endl; // Output: 3
    return 0;
}
#endif