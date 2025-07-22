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
    int n, m;
    long long dfs(vector<vector<int>>& grid, vector<bool>& vis, int x, int y) {
        if (vis[x * m + y]) return 0;
        if (grid[x][y] == 0) return 0;
        vis[x * m + y] = true;
        const int dx[4] = {1, -1, 0, 0};
        const int dy[4] = {0, 0, 1, -1};
        long long ans = grid[x][y];
        for (int i = 0; i < 4; ++i) {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
            ans += dfs(grid, vis, xx, yy);
        }
        return ans;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        n = grid.size(), m = grid[0].size();
        vector<bool> vis(n * m, false);
        int ans = 0;
        for (int i = 0, cnt = 0; i < n; ++i)
            for (int j = 0; j < m; ++j, ++cnt) {
                if (vis[cnt] || grid[i][j] == 0) continue;
                if (dfs(grid, vis, i, j) % k == 0) ++ans;
            }
        return ans;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {0, 2, 1, 0, 0},
        {0, 5, 0, 0, 5},
        {0, 0, 1, 0, 0},
        {0, 1, 4, 7, 0},
        {0, 2, 0, 0, 8}
    };
    cout << sol.countIslands(grid, 5) << endl;  // Expected output depends on actual island sums
    return 0;
}
#endif