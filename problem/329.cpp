#include <bits/stdc++.h>

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0)
            return 0;
        int m = matrix[0].size();
        if (m == 0)
            return 0;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        vector<pair<int, pair<int, int>>> cells;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cells.push_back({matrix[i][j], {i, j}});
        sort(cells.begin(), cells.end());
        const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int result = 1;
        for (auto& cell : cells) {
            int val = cell.first;
            int x = cell.second.first;
            int y = cell.second.second;
            int max_len = 1;
            for (int d = 0; d < 4; ++d) {
                int nx = x + dirs[d][0];
                int ny = y + dirs[d][1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;
                if (matrix[nx][ny] < val)
                    max_len = max(max_len, mat[nx][ny] + 1);
            }
            mat[x][y] = max_len;
            result = max(result, max_len);
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