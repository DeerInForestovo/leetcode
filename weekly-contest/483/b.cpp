#include <bits/stdc++.h>

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>> result;
        sort(words.begin(), words.end());
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            char top_left = words[i][0];
            char top_right = words[i].back();
            for (int j = 0; j < n; ++j) {
                if (j == i) continue;
                if (top_left != words[j][0]) continue;
                char bottom_left = words[j].back();
                for (int k = 0; k < n; ++k) {
                    if (j == k || i == k) continue;
                    if (top_right != words[k][0]) continue;
                    char bottom_right = words[k].back();
                    for (int l = 0; l < n; ++l) {
                        if (l == j || l == k || l == i) continue;
                        if (bottom_left == words[l][0] && bottom_right == words[l].back())
                            result.push_back({words[i], words[j], words[k], words[l]});
                    }
                }
            }
        }
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