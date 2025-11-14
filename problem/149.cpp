#include <bits/stdc++.h>
using namespace std;

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        int max_points = 1;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) continue;
                int count = 2;
                for (int k = 0; k < n; ++k) {
                    if (k == i || k == j) continue;
                    if ((points[i][1] - points[j][1]) * (points[k][0] - points[j][0]) ==
                        (points[i][0] - points[j][0]) * (points[k][1] - points[j][1]))
                        ++count;
                }
                max_points = max(max_points, count);
            }
        }
        return max_points;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif