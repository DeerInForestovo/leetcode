#include <bits/stdc++.h>

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        const int MAXN = 10000;
        vector<int> points(MAXN + 1, 0);
        for (auto num : nums)
            points[num] += num;
        for (int i = 2; i <= MAXN; ++i)
            points[i] = max(points[i - 1], points[i - 2] + points[i]);
        return points[MAXN];
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif