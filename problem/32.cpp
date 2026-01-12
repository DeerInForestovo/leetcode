#include <bits/stdc++.h>

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), cur_left = 0, max_ans = 0;
        vector<int> last_pos(n + 2, -1);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                ++cur_left;
                if (last_pos[cur_left] == -1)
                    last_pos[cur_left] = i;
            } else {
                if (cur_left > 0) {
                    max_ans = max(max_ans, i - last_pos[cur_left] + 1);
                    last_pos[cur_left + 1] = -1;
                    --cur_left;
                } else {
                    last_pos[1] = -1;
                }
            }
        }
        return max_ans;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif