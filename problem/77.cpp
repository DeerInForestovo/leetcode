#include <bits/stdc++.h>
using namespace std;

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        dfs(result, current, n, k, 1);
        return result;
    }
    void dfs(vector<vector<int>>& result, vector<int>& current, int n, int k, int start) {
        if (current.size() == k) {
            result.push_back(current);
            return;
        }

        for (int i = start; i <= n; ++i) {
            current.push_back(i);
            dfs(result, current, n, k, i + 1);
            current.pop_back();
        }
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif