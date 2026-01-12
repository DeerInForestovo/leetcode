#include <bits/stdc++.h>

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        long long x = 0, y = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] != t[i]) {
                if (s[i] == '0') ++x;
                else ++y;
            }
        }
        long long f = flipCost;  // x -= 1 or y -= 1
        long long sw = swapCost;  // x -= 1, y -= 1
        long long sc = swapCost + crossCost;  // x -= 2 or y -= 2
        long long xy_dif = abs(x - y);
        long long xcost = min(f * 2, sc) * (x / 2) + (x % 2) * f;
        long long ycost = min(f * 2, sc) * (y / 2) + (y % 2) * f;
        long long x_equal_y_cost = min(f * 2, sc) * (xy_dif / 2) + (xy_dif % 2) * f;
        return min(xcost + ycost, min(x, y) * sw + x_equal_y_cost);
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif